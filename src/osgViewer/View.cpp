/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2006 Robert Osfield 
 *
 * This library is open source and may be redistributed and/or modified under  
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * OpenSceneGraph Public License for more details.
*/

#include <osgViewer/View>
#include <osgViewer/GraphicsWindow>

#include <osgUtil/SceneView>
#include <osg/io_utils>

using namespace osgViewer;

View::View()
{
    // osg::notify(osg::NOTICE)<<"Constructing osgViewer::View"<<std::endl;
   setEventQueue(new osgGA::EventQueue);
}

View::~View()
{
    // osg::notify(osg::NOTICE)<<"Destructing osgViewer::View"<<std::endl;
}

void View::setSceneData(osg::Node* node)
{
    _scene = new osgViewer::Scene;
    _scene->setSceneData(node);
    
    assignSceneDataToCameras();
}

void View::setCameraManipulator(osgGA::MatrixManipulator* manipulator)
{
    _cameraManipulator = manipulator;
    if (_cameraManipulator.valid() && getSceneData())
    {
        _cameraManipulator->setNode(getSceneData());
        
        osg::ref_ptr<osgGA::GUIEventAdapter> dummyEvent = _eventQueue->createEvent();

        _cameraManipulator->home(*dummyEvent, *this);
    }
}

void View::addEventHandler(osgGA::GUIEventHandler* eventHandler)
{ 
    _eventHandlers.push_back(eventHandler);
}

void View::setUpViewAcrossAllScreens()
{
    osg::GraphicsContext::WindowingSystemInterface* wsi = osg::GraphicsContext::getWindowingSystemInterface();
    if (!wsi) 
    {
        osg::notify(osg::NOTICE)<<"View::setUpViewAcrossAllScreens() : Error, no WindowSystemInterface available, cannot create windows."<<std::endl;
        return;
    }
    

    double fovy, aspectRatio, zNear, zFar;        
    _camera->getProjectionMatrixAsPerspective(fovy, aspectRatio, zNear, zFar);

    double fovx = atan(tan(osg::DegreesToRadians(fovy*0.5)) * aspectRatio) * 2.0;

    unsigned int numScreens = wsi->getNumScreens();
    if (numScreens==1)
    {
            unsigned int width, height;
            wsi->getScreenResolution(osg::GraphicsContext::ScreenIdentifier(0), width, height);

            osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
            traits->x = 0;
            traits->y = 0;
            traits->width = width;
            traits->height = height;
#if 1
            traits->windowDecoration = false;
#else
            traits->windowDecoration = true;
#endif            
            traits->doubleBuffer = true;
            traits->sharedContext = 0;
            
            osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
            
            _camera->setGraphicsContext(gc.get());
            
            osgViewer::GraphicsWindow* gw = dynamic_cast<osgViewer::GraphicsWindow*>(gc.get());
            if (gw)
            {
                osg::notify(osg::INFO)<<"  GraphicsWindow has been created successfully."<<std::endl;
                gw->getEventQueue()->getCurrentEventState()->setWindowRectangle(0, 0, width, height );
            }
            else
            {
                osg::notify(osg::NOTICE)<<"  GraphicsWindow has not been created successfully."<<std::endl;
            }

            _camera->setViewport(new osg::Viewport(0, 0, width, height));
            
            GLenum buffer = traits->doubleBuffer ? GL_BACK : GL_FRONT;
            
            _camera->setDrawBuffer(buffer);
            _camera->setReadBuffer(buffer);

    }
    else
    {
        double rotate_x = - double(numScreens-1) * 0.5 * fovx;
            
        for(unsigned int i=0; i<numScreens; ++i, rotate_x += fovx)
        {
            unsigned int width, height;
            wsi->getScreenResolution(osg::GraphicsContext::ScreenIdentifier(i), width, height);

            osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
            traits->screenNum = i;
            traits->x = 0;
            traits->y = 0;
            traits->width = width;
            traits->height = height;
            traits->windowDecoration = false;
            traits->doubleBuffer = true;
            traits->sharedContext = 0;
            
            osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
            
            osg::ref_ptr<osg::Camera> camera = new osg::Camera;
            camera->setGraphicsContext(gc.get());
            
            osgViewer::GraphicsWindow* gw = dynamic_cast<osgViewer::GraphicsWindow*>(gc.get());
            if (gw)
            {
                osg::notify(osg::INFO)<<"  GraphicsWindow has been created successfully."<<gw<<std::endl;
                
                gw->getEventQueue()->getCurrentEventState()->setWindowRectangle(0, 0, width, height );
            }
            else
            {
                osg::notify(osg::NOTICE)<<"  GraphicsWindow has not been created successfully."<<std::endl;
            }
            
            camera->setViewport(new osg::Viewport(0, 0, width, height));
            
            GLenum buffer = traits->doubleBuffer ? GL_BACK : GL_FRONT;
            camera->setDrawBuffer(buffer);
            camera->setReadBuffer(buffer);

            addSlave(camera.get(), osg::Matrixd(), osg::Matrixd::rotate( rotate_x, 0.0, 1.0, 0.0));
            
        }
    }
    
    setUpRenderingSupport();
    assignSceneDataToCameras();
}

// Draw operation, that does a draw on the scene graph.
struct RenderingOperation : public osg::GraphicsOperation
{
    RenderingOperation(osgUtil::SceneView* sceneView, osgDB::DatabasePager* databasePager):
        osg::GraphicsOperation("Render",true),
        _sceneView(sceneView),
        _databasePager(databasePager)
    {
        _sceneView->getCullVisitor()->setDatabaseRequestHandler(_databasePager.get());
    }
    
    virtual void operator () (osg::GraphicsContext*)
    {
        if (!_sceneView) return;
    

        // osg::notify(osg::NOTICE)<<"RenderingOperation"<<std::endl;
        
        _sceneView->cull();
        _sceneView->draw();

        if (_databasePager.valid())
        {
            double availableTime = 0.004; // 4 ms
            _databasePager->compileGLObjects(*(_sceneView->getState()), availableTime);
            _sceneView->flushDeletedGLObjects(availableTime);
        }
    }
    
    osg::observer_ptr<osgUtil::SceneView>    _sceneView;
    osg::observer_ptr<osgDB::DatabasePager>  _databasePager;
};

void View::setUpRenderingSupport()
{
    osg::FrameStamp* frameStamp = _scene->getFrameStamp();

    // what should we do with the old sceneViews?
    _cameraSceneViewMap.clear();

    if (_camera.valid() && _camera->getGraphicsContext())
    {
        osgUtil::SceneView* sceneView = new osgUtil::SceneView;
        _cameraSceneViewMap[_camera] = sceneView;

        sceneView->setDefaults();
        sceneView->setCamera(_camera.get());
        sceneView->setState(_camera->getGraphicsContext()->getState());
        sceneView->setSceneData(getSceneData());
        sceneView->setFrameStamp(frameStamp);

        _camera->getGraphicsContext()->add(new RenderingOperation(sceneView, _scene->getDatabasePager()));        
    }
    
    for(unsigned i=0; i<getNumSlaves(); ++i)
    {
        Slave& slave = getSlave(i);
        if (slave._camera.valid() && slave._camera->getGraphicsContext())
        {
            osgUtil::SceneView* sceneView = new osgUtil::SceneView;
            _cameraSceneViewMap[slave._camera] = sceneView;

            sceneView->setDefaults();
            sceneView->setCamera(slave._camera.get());
            sceneView->setState(slave._camera->getGraphicsContext()->getState());
            sceneView->setSceneData(getSceneData());
            sceneView->setFrameStamp(frameStamp);

            slave._camera->getGraphicsContext()->add(new RenderingOperation(sceneView, _scene->getDatabasePager()));
        }
    }
}

void View::assignSceneDataToCameras()
{
    osg::Node* sceneData = _scene.valid() ? _scene->getSceneData() : 0;
    
    if (_cameraManipulator.valid())
    {
        _cameraManipulator->setNode(sceneData);
        
        osg::ref_ptr<osgGA::GUIEventAdapter> dummyEvent = _eventQueue->createEvent();

        _cameraManipulator->home(*dummyEvent, *this);
    }

    if (_camera.valid())
    {
        _camera->removeChildren(0,_camera->getNumChildren());
        if (sceneData) _camera->addChild(sceneData);
    }

    for(unsigned i=0; i<getNumSlaves(); ++i)
    {
        Slave& slave = getSlave(i);
        if (slave._camera.valid())
        {
            slave._camera->removeChildren(0,slave._camera->getNumChildren());
            if (sceneData) slave._camera->addChild(sceneData);
        }
    }    
}

void View::requestRedraw()
{
}

void View::requestContinuousUpdate(bool)
{
}

void View::requestWarpPointer(float x,float y)
{
    osgGA::GUIEventAdapter* eventState = getEventQueue()->getCurrentEventState(); 
    bool view_invert_y = eventState->getMouseYOrientation()==osgGA::GUIEventAdapter::Y_INCREASING_DOWNWARDS;
    
    osgViewer::GraphicsWindow* gw = dynamic_cast<osgViewer::GraphicsWindow*>(_camera->getGraphicsContext());
    if (gw)
    {
        bool gw_invert_y = gw->getEventQueue()->getCurrentEventState()->getMouseYOrientation()==osgGA::GUIEventAdapter::Y_INCREASING_DOWNWARDS;

        x = x * float(gw->getTraits()->width) / (eventState->getXmax()-eventState->getXmin());
        y = y * float(gw->getTraits()->height) / (eventState->getYmax()-eventState->getYmin());

        if (view_invert_y != gw_invert_y) y = gw->getTraits()->height - y;
        
        gw->requestWarpPointer(x, y);
        
        return;
    }

    osg::Matrix masterCameraVPW = getCamera()->getViewMatrix() * getCamera()->getProjectionMatrix();
    
    x = (x - eventState->getXmin()) * 2.0 / (eventState->getXmax()-eventState->getXmin()) - 1.0;
    y = (y - eventState->getYmin())* 2.0 / (eventState->getYmax()-eventState->getYmin()) - 1.0;

    if (view_invert_y) y = - y;
    
    for(unsigned i=0; i<getNumSlaves(); ++i)
    {
        Slave& slave = getSlave(i);
        if (slave._camera.valid())
        {
            osg::Camera* camera = slave._camera.get();
            osg::Viewport* viewport = camera ? camera->getViewport() : 0;

            osg::Matrix localCameraVPW = camera->getViewMatrix() * camera->getProjectionMatrix();
            if (viewport) localCameraVPW *= viewport->computeWindowMatrix();

            osg::Matrix matrix( osg::Matrix::inverse(masterCameraVPW) * localCameraVPW );

            osg::Vec3d new_coord = osg::Vec3d(x,y,0.0) * matrix;

            if (viewport && 
                new_coord.x() >= viewport->x() && new_coord.y() >= viewport->y() &&
                new_coord.x() <= (viewport->x()+viewport->width()) && new_coord.y() <= (viewport->y()+viewport->height()) )
            {
                gw = dynamic_cast<osgViewer::GraphicsWindow*>(camera->getGraphicsContext());
                if (gw)
                {
                    x = new_coord.x();
                    y = new_coord.y();

                    bool gw_invert_y = gw->getEventQueue()->getCurrentEventState()->getMouseYOrientation()==osgGA::GUIEventAdapter::Y_INCREASING_DOWNWARDS;
                    
                    if (gw_invert_y) y = gw->getTraits()->height - y;

                    gw->requestWarpPointer(x, y);

                    return;
                }
            }


        }
    }    



}
