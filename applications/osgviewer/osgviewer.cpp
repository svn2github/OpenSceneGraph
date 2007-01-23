/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2006 Robert Osfield 
 *
 * This application is open source and may be redistributed and/or modified   
 * freely and without restriction, both in commericial and non commericial applications,
 * as long as this copyright notice is maintained.
 * 
 * This application is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <osgDB/ReadFile>
#include <osgUtil/Optimizer>
#include <osg/CoordinateSystemNode>

#include <osg/Switch>
#include <osgText/Text>

#include <osgViewer/Viewer>

#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>

#include <iostream>

class ThreadingHandler : public osgGA::GUIEventHandler 
{
public: 

    ThreadingHandler() {}
        
    bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
    {
        osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
        if (!viewer) return false;
    
        switch(ea.getEventType())
        {
            case(osgGA::GUIEventAdapter::KEYUP):
            {
                if (ea.getKey()=='m')
                {
                    switch(viewer->getThreadingModel())
                    {
                        case(osgViewer::Viewer::SingleThreaded):
                            viewer->setThreadingModel(osgViewer::Viewer::ThreadPerContext);
                            osg::notify(osg::NOTICE)<<"Threading model 'ThreadPerContext' selected."<<std::endl;
                            break;
                        case(osgViewer::Viewer::ThreadPerContext):
                            viewer->setThreadingModel(osgViewer::Viewer::ThreadPerCamera);
                            osg::notify(osg::NOTICE)<<"Threading model 'ThreadPerCamera' selected."<<std::endl;
                            break;
                        case(osgViewer::Viewer::ThreadPerCamera):
                            viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);
                            osg::notify(osg::NOTICE)<<"Threading model 'SingleTheaded' selected."<<std::endl;
                            break;
                    }
                    return true;
                }
                if (ea.getKey()=='e')
                {
                    switch(viewer->getEndBarrierPosition())
                    {
                        case(osgViewer::Viewer::BeforeSwapBuffers):
                            viewer->setEndBarrierPosition(osgViewer::Viewer::AfterSwapBuffers);
                            osg::notify(osg::NOTICE)<<"Threading model 'AfterSwapBuffers' selected."<<std::endl;
                            break;
                        case(osgViewer::Viewer::AfterSwapBuffers):
                            viewer->setEndBarrierPosition(osgViewer::Viewer::BeforeSwapBuffers);
                            osg::notify(osg::NOTICE)<<"Threading model 'BeforeSwapBuffers' selected."<<std::endl;
                            break;
                    }
                    return true;
                }
            }
            default: break;
        }
        
        return false;
    }
    
    bool _done;
};

class StatsHandler : public osgGA::GUIEventHandler 
{
public: 

    StatsHandler():
        _statsType(NO_STATS),
        _frameRateChildNum(0),
        _viewerChildNum(0),
        _sceneChildNum(0),
        _numBlocks(8),
        _blockMultiplier(10000.0) {}

    enum StatsType
    {
        NO_STATS = 0,
        FRAME_RATE = 1,
        VIEWER_STATS = 2,
        SCENE_STATS = 3,
        LAST = 4
    };
        
    bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
    {
        osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
        if (!viewer) return false;
    
        switch(ea.getEventType())
        {
            case(osgGA::GUIEventAdapter::KEYDOWN):
            {
                if (ea.getKey()=='s')
                {
                    if (viewer->getStats())
                    {
                        if (!_camera.valid())
                        {
                            setUpHUDCamera(viewer);
                            setUpScene(viewer);
                        }

                        ++_statsType;
                        
                        if (_statsType==LAST) _statsType = NO_STATS;
                        
                        switch(_statsType)
                        {
                            case(NO_STATS):
                            {
                                _camera->setNodeMask(0x0); 
                                _switch->setAllChildrenOff();
                                break;
                            }
                            case(FRAME_RATE):
                            {
                                _camera->setNodeMask(0xffffffff);
                                _switch->setValue(_frameRateChildNum, true);
                                break;
                            }
                            case(VIEWER_STATS):
                            {
                                _camera->setNodeMask(0xffffffff);
                                _switch->setValue(_viewerChildNum, true);
                                break;
                            }
                            case(SCENE_STATS):
                            {
                                _switch->setValue(_sceneChildNum, true);
                                _camera->setNodeMask(0xffffffff);
                                break;
                            }
                            default:
                                break;
                        }

                        
                    }
                    return true;
                }
                if (ea.getKey()=='S')
                {
                    if (viewer->getStats())
                    {
                        osg::notify(osg::NOTICE)<<std::endl<<"Stats report:"<<std::endl;
                        typedef std::vector<osg::Stats*> StatsList;
                        StatsList statsList;
                        statsList.push_back(viewer->getStats());
                        
                        osgViewer::Viewer::Contexts contexts;
                        viewer->getContexts(contexts);
                        for(osgViewer::Viewer::Contexts::iterator gcitr = contexts.begin();
                            gcitr != contexts.end();
                            ++gcitr)
                        {
                            osg::GraphicsContext::Cameras& cameras = (*gcitr)->getCameras();
                            for(osg::GraphicsContext::Cameras::iterator itr = cameras.begin();
                                itr != cameras.end();
                                ++itr)
                            {
                                if ((*itr)->getStats())
                                {
                                    statsList.push_back((*itr)->getStats());
                                }
                            }
                        }
                        
                        for(int i = viewer->getStats()->getEarliestFrameNumber(); i<= viewer->getStats()->getLatestFrameNumber()-1; ++i)
                        {
                            for(StatsList::iterator itr = statsList.begin();
                                itr != statsList.end();
                                ++itr)
                            {
                                if (itr==statsList.begin()) (*itr)->report(osg::notify(osg::NOTICE), i);
                                else (*itr)->report(osg::notify(osg::NOTICE), i, "    ");
                            }
                            osg::notify(osg::NOTICE)<<std::endl;
                        }
                        
                    }
                    return true;
                }
            }
            default: break;
        }
        
        return false;
        
    }

    void setUpHUDCamera(osgViewer::Viewer* viewer)
    {
        osgViewer::Viewer::Windows windows;
        viewer->getWindows(windows);
        
        if (windows.empty()) return;
        
        osgViewer::GraphicsWindow* window = windows.front();
        
        _camera = new osg::Camera;
        _camera->setGraphicsContext(window);
        _camera->setViewport(0, 0, window->getTraits()->width, window->getTraits()->height);
        
        _camera->setProjectionMatrix(osg::Matrix::ortho2D(0,1280,0,1024));
        _camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
        _camera->setViewMatrix(osg::Matrix::identity());

        // only clear the depth buffer
        _camera->setClearMask(0);
        
        viewer->setUpRenderingSupport();
    }
    
    struct TextDrawCallback : public virtual osg::Drawable::DrawCallback
    {
        TextDrawCallback(osg::Stats* stats, const std::string& name, int frameDelta, double multiplier = 1.0):
            _stats(stats),
            _attributeName(name),
            _frameDelta(frameDelta),
            _multiplier(multiplier) {}
    
        /** do customized draw code.*/
        virtual void drawImplementation(osg::RenderInfo& renderInfo,const osg::Drawable* drawable) const
        {
            osgText::Text* text = (osgText::Text*)drawable;
            
            int frameNumber = renderInfo.getState()->getFrameStamp()->getFrameNumber();
            
            double value;
            if (_stats->getAttribute( frameNumber+_frameDelta, _attributeName, value))
            {
                sprintf(_tmpText,"%4.2f",value * _multiplier);
                text->setText(_tmpText);
            }
            else
            {
                text->setText("");
            }
                        
            text->drawImplementation(renderInfo);
        }

        osg::Stats*     _stats;
        std::string     _attributeName;
        int             _frameDelta;
        double          _multiplier;
        mutable char    _tmpText[128];
    };

    struct BlockDrawCallback : public virtual osg::Drawable::DrawCallback
    {
        BlockDrawCallback(StatsHandler* statsHandler, float xPos, osg::Stats* viewerStats, osg::Stats* stats, const std::string& beginName, const std::string& endName, int frameDelta, int numFrames):
            _statsHandler(statsHandler), 
            _xPos(xPos),
            _viewerStats(viewerStats),
            _stats(stats),
            _beginName(beginName),
            _endName(endName),
            _frameDelta(frameDelta),
            _numFrames(numFrames) {}
    
        /** do customized draw code.*/
        virtual void drawImplementation(osg::RenderInfo& renderInfo,const osg::Drawable* drawable) const
        {
            osg::Geometry* geom = (osg::Geometry*)drawable;
            osg::Vec3Array* vertices = (osg::Vec3Array*)geom->getVertexArray();
            
            int frameNumber = renderInfo.getState()->getFrameStamp()->getFrameNumber();            
            
            int startFrame = frameNumber + _frameDelta - _numFrames + 1;
            int endFrame = frameNumber + _frameDelta;
            double referenceTime;
            if (!_viewerStats->getAttribute( startFrame, "Reference time", referenceTime))
            {
                return;
            }

            unsigned int vi = 0;
            double beginValue, endValue;
            for(int i = startFrame; i <= endFrame; ++i)
            {            
                if (_stats->getAttribute( i, _beginName, beginValue) &&
                    _stats->getAttribute( i, _endName, endValue) )
                {
                    (*vertices)[vi++].x() = _xPos + (beginValue - referenceTime) * _statsHandler->_blockMultiplier;
                    (*vertices)[vi++].x() = _xPos + (beginValue - referenceTime) * _statsHandler->_blockMultiplier;
                    (*vertices)[vi++].x() = _xPos + (endValue - referenceTime) * _statsHandler->_blockMultiplier;
                    (*vertices)[vi++].x() = _xPos + (endValue - referenceTime) * _statsHandler->_blockMultiplier;
                }
            }
                                    
            drawable->drawImplementation(renderInfo);
        }

        StatsHandler*   _statsHandler;
        float           _xPos;
        osg::Stats*     _viewerStats;
        osg::Stats*     _stats;
        std::string     _beginName;
        std::string     _endName;
        int             _frameDelta;
        int             _numFrames;
    };
    
    osg::Geometry* createGeometry(const osg::Vec3& pos, float height, const osg::Vec4& colour, unsigned int numBlocks)
    {
        osg::Geometry* geometry = new osg::Geometry;

        geometry->setUseDisplayList(false);
        
        osg::Vec3Array* vertices = new osg::Vec3Array;
        geometry->setVertexArray(vertices);
        vertices->reserve(numBlocks*4);
        
        for(unsigned int i=0; i<numBlocks; ++i)
        {
            vertices->push_back(pos+osg::Vec3(i*20, height, 0.0));
            vertices->push_back(pos+osg::Vec3(i*20, 0.0, 0.0));
            vertices->push_back(pos+osg::Vec3(i*20+10.0, 0.0, 0.0));
            vertices->push_back(pos+osg::Vec3(i*20+10.0, height, 0.0));
        }
        
        osg::Vec4Array* colours = new osg::Vec4Array;
        colours->push_back(colour);
        geometry->setColorArray(colours);
        geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
        
        geometry->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, numBlocks*4));
        
        return geometry;       
    }


    struct FrameMarkerDrawCallback : public virtual osg::Drawable::DrawCallback
    {
        FrameMarkerDrawCallback(StatsHandler* statsHandler, float xPos, osg::Stats* viewerStats, int frameDelta, int numFrames):
            _statsHandler(statsHandler), 
            _xPos(xPos),
            _viewerStats(viewerStats),
            _frameDelta(frameDelta),
            _numFrames(numFrames) {}
    
        /** do customized draw code.*/
        virtual void drawImplementation(osg::RenderInfo& renderInfo,const osg::Drawable* drawable) const
        {
            osg::Geometry* geom = (osg::Geometry*)drawable;
            osg::Vec3Array* vertices = (osg::Vec3Array*)geom->getVertexArray();
            
            int frameNumber = renderInfo.getState()->getFrameStamp()->getFrameNumber();            
            
            int startFrame = frameNumber + _frameDelta - _numFrames + 1;
            int endFrame = frameNumber + _frameDelta;
            double referenceTime;
            if (!_viewerStats->getAttribute( startFrame, "Reference time", referenceTime))
            {
                return;
            }

            unsigned int vi = 0;
            double currentReferenceTime;
            for(int i = startFrame; i <= endFrame; ++i)
            {            
                if (_viewerStats->getAttribute( i, "Reference time", currentReferenceTime))
                {
                    (*vertices)[vi++].x() = _xPos + (currentReferenceTime - referenceTime) * _statsHandler->_blockMultiplier;
                    (*vertices)[vi++].x() = _xPos + (currentReferenceTime - referenceTime) * _statsHandler->_blockMultiplier;
                }
            }
                                    
            drawable->drawImplementation(renderInfo);
        }

        StatsHandler*   _statsHandler;
        float           _xPos;
        osg::Stats*     _viewerStats;
        std::string     _endName;
        int             _frameDelta;
        int             _numFrames;
    };
    

    osg::Geometry* createFrameMarkers(const osg::Vec3& pos, float height, const osg::Vec4& colour, unsigned int numBlocks)
    {
        osg::Geometry* geometry = new osg::Geometry;

        geometry->setUseDisplayList(false);
        
        osg::Vec3Array* vertices = new osg::Vec3Array;
        geometry->setVertexArray(vertices);
        vertices->reserve(numBlocks*2);
        
        for(unsigned int i=0; i<numBlocks; ++i)
        {
            vertices->push_back(pos+osg::Vec3(double(i)*_blockMultiplier*0.01, height, 0.0));
            vertices->push_back(pos+osg::Vec3(double(i)*_blockMultiplier*0.01, 0.0, 0.0));
        }
        
        osg::Vec4Array* colours = new osg::Vec4Array;
        colours->push_back(colour);
        geometry->setColorArray(colours);
        geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
        
        geometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES, 0, numBlocks*2));
        
        return geometry;       
    }

    osg::Geometry* createTick(const osg::Vec3& pos, float height, const osg::Vec4& colour, unsigned int numTicks)
    {
        osg::Geometry* geometry = new osg::Geometry;

        geometry->setUseDisplayList(false);
        
        osg::Vec3Array* vertices = new osg::Vec3Array;
        geometry->setVertexArray(vertices);
        vertices->reserve(numTicks*2);
        
        for(unsigned int i=0; i<numTicks; ++i)
        {
            float tickHeight = (i%10) ? height : height * 2.0;
            vertices->push_back(pos+osg::Vec3(double(i)*_blockMultiplier*0.001, tickHeight , 0.0));
            vertices->push_back(pos+osg::Vec3(double(i)*_blockMultiplier*0.001, 0.0, 0.0));
        }
        
        osg::Vec4Array* colours = new osg::Vec4Array;
        colours->push_back(colour);
        geometry->setColorArray(colours);
        geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
        
        geometry->addPrimitiveSet(new osg::DrawArrays(GL_LINES, 0, numTicks*2));
        
        return geometry;       
    }

    void setUpScene(osgViewer::Viewer* viewer)
    {
        _switch = new osg::Switch;

        _camera->addChild(_switch.get());

        osg::StateSet* stateset = _switch->getOrCreateStateSet();
        stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
        stateset->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);

        std::string font("fonts/arial.ttf");


        // collect all the relevant camers
        typedef std::vector<osg::Camera*> Cameras;
        Cameras cameras;
        if (viewer->getCamera()->getStats()) 
        {
            cameras.push_back(viewer->getCamera());            
        }
        for(unsigned int si=0; si<viewer->getNumSlaves(); ++si)
        {
            if (viewer->getSlave(si)._camera->getStats()) 
            {
                cameras.push_back(viewer->getSlave(si)._camera.get());
            }
        }

        // check for querry time support
        unsigned int numCamrasWithTimerQuerySupport = 0;
        for(Cameras::iterator citr = cameras.begin();
            citr != cameras.end();
            ++citr)
        {
            unsigned int contextID = (*citr)->getGraphicsContext()->getState()->getContextID();
            const osg::Drawable::Extensions* extensions = osg::Drawable::getExtensions(contextID, false);
            if (extensions && extensions->isTimerQuerySupported())
            {
                ++numCamrasWithTimerQuerySupport;
            }
        }

        bool aquireGPUStats = numCamrasWithTimerQuerySupport==cameras.size();

        float leftPos = 10.0f;
        float startBlocks = aquireGPUStats ? 250.0f : 150.0f;
        float characterSize = 20.0f;

        osg::Vec3 pos(leftPos,1000.0f,0.0f);

        osg::Vec4 colorFR(1.0f,1.0f,1.0f,1.0f);
        osg::Vec4 colorUpdate( 0.0f,1.0f,0.0f,1.0f);


        // frame rate stats
        {
            osg::Geode* geode = new osg::Geode();
            _frameRateChildNum = _switch->getNumChildren();
            _switch->addChild(geode, false);

            osg::ref_ptr<osgText::Text> frameRateLabel = new osgText::Text;
            geode->addDrawable( frameRateLabel.get() );

            frameRateLabel->setColor(colorFR);
            frameRateLabel->setFont(font);
            frameRateLabel->setCharacterSize(characterSize);
            frameRateLabel->setPosition(pos);
            frameRateLabel->setText("Frame Rate: ");

            pos.x() = frameRateLabel->getBound().xMax();

            osg::ref_ptr<osgText::Text> frameRateValue = new osgText::Text;
            geode->addDrawable( frameRateValue.get() );

            frameRateValue->setColor(colorFR);
            frameRateValue->setFont(font);
            frameRateValue->setCharacterSize(characterSize);
            frameRateValue->setPosition(pos);
            frameRateValue->setText("0.0");

            frameRateValue->setDrawCallback(new TextDrawCallback(viewer->getStats(),"Frame rate",-1));

            pos.y() -= characterSize*1.5f;
            
        }
        

        // viewer stats
        {
            osg::Group* group = new osg::Group;
            _viewerChildNum = _switch->getNumChildren();
            _switch->addChild(group, false);

            osg::Geode* geode = new osg::Geode();
            group->addChild(geode);

            float topOfViewerStats = pos.y() + characterSize * 1.5;

            {
                pos.x() = leftPos;

                osg::ref_ptr<osgText::Text> eventLabel = new osgText::Text;
                geode->addDrawable( eventLabel.get() );

                eventLabel->setColor(colorUpdate);
                eventLabel->setFont(font);
                eventLabel->setCharacterSize(characterSize);
                eventLabel->setPosition(pos);
                eventLabel->setText("Event: ");

                pos.x() = eventLabel->getBound().xMax();

                osg::ref_ptr<osgText::Text> eventValue = new osgText::Text;
                geode->addDrawable( eventValue.get() );

                eventValue->setColor(colorUpdate);
                eventValue->setFont(font);
                eventValue->setCharacterSize(characterSize);
                eventValue->setPosition(pos);
                eventValue->setText("0.0");

                eventValue->setDrawCallback(new TextDrawCallback(viewer->getStats(),"Event traversal time taken",-1, 1000.0));
                
                pos.x() = startBlocks;
                osg::Geometry* geometry = createGeometry(pos, characterSize *0.8, colorUpdate, _numBlocks);
                geometry->setDrawCallback(new BlockDrawCallback(this, startBlocks, viewer->getStats(), viewer->getStats(), "Event traversal begin time", "Event traversal end time", -1, _numBlocks));
                geode->addDrawable(geometry);

                pos.y() -= characterSize*1.5f;
            }
            
            {
                pos.x() = leftPos;

                osg::ref_ptr<osgText::Text> updateLabel = new osgText::Text;
                geode->addDrawable( updateLabel.get() );

                updateLabel->setColor(colorUpdate);
                updateLabel->setFont(font);
                updateLabel->setCharacterSize(characterSize);
                updateLabel->setPosition(pos);
                updateLabel->setText("Update: ");

                pos.x() = updateLabel->getBound().xMax();

                osg::ref_ptr<osgText::Text> updateValue = new osgText::Text;
                geode->addDrawable( updateValue.get() );

                updateValue->setColor(colorUpdate);
                updateValue->setFont(font);
                updateValue->setCharacterSize(characterSize);
                updateValue->setPosition(pos);
                updateValue->setText("0.0");

                updateValue->setDrawCallback(new TextDrawCallback(viewer->getStats(),"Update traversal time taken",-1, 1000.0));

                pos.x() = startBlocks;
                osg::Geometry* geometry = createGeometry(pos, characterSize *0.8, colorUpdate, _numBlocks);
                geometry->setDrawCallback(new BlockDrawCallback(this, startBlocks, viewer->getStats(), viewer->getStats(), "Update traversal begin time", "Update traversal end time", -1, _numBlocks));
                geode->addDrawable(geometry);

                pos.y() -= characterSize*1.5f;
            }
            
            pos.x() = leftPos;

            
            // add camera stats
            for(Cameras::iterator citr = cameras.begin();
                citr != cameras.end();
                ++citr)
            {
                group->addChild(createCameraStats(font, pos, startBlocks, aquireGPUStats, characterSize, viewer->getStats(), *citr));
            }


            // add frame ticks
            {
                osg::Geode* geode = new osg::Geode;
                group->addChild(geode);
                
                osg::Vec4 colourTicks(1.0f,1.0f,1.0f, 0.5f);
                
                pos.x() = startBlocks;
                pos.y() += characterSize*0.5;
                float height = topOfViewerStats - pos.y();

                osg::Geometry* ticks = createTick(pos, 5.0f, colourTicks, 100);
                geode->addDrawable(ticks);
                
                osg::Geometry* frameMarkers = createFrameMarkers(pos, height, colourTicks, _numBlocks + 1);
                frameMarkers->setDrawCallback(new FrameMarkerDrawCallback(this, startBlocks, viewer->getStats(), 0, _numBlocks + 1));
                geode->addDrawable(frameMarkers);
            }

        }

        // scene stats
        {
            pos.x() = leftPos;

            osg::Geode* geode = new osg::Geode();

            {
                osgText::Text* text = new  osgText::Text;
                geode->addDrawable( text );

                text->setFont(font);
                text->setCharacterSize(characterSize);
                text->setPosition(pos);
                text->setText("Scene Stats to do...");

                pos.y() -= characterSize*1.5f;
            }    

            _sceneChildNum = _switch->getNumChildren();
            _switch->addChild(geode, false);
        }
    }

    osg::Node* createCameraStats(const std::string& font, osg::Vec3& pos, float startBlocks, bool aquireGPUStats, float characterSize, osg::Stats* viewerStats, osg::Camera* camera)
    {
        osg::Stats* stats = camera->getStats();
        if (!stats) return 0;

        osg::Group* group = new osg::Group;

        osg::Geode* geode = new osg::Geode();
        group->addChild(geode);

        float leftPos = pos.x();

        osg::Vec4 colorCull( 0.0f,1.0f,1.0f,1.0f);
        osg::Vec4 colorDraw( 1.0f,1.0f,0.0f,1.0f);
        osg::Vec4 colorGPU( 1.0f,0.5f,0.0f,1.0f);

        {
            pos.x() = leftPos;

            osg::ref_ptr<osgText::Text> cullLabel = new osgText::Text;
            geode->addDrawable( cullLabel.get() );

            cullLabel->setColor(colorCull);
            cullLabel->setFont(font);
            cullLabel->setCharacterSize(characterSize);
            cullLabel->setPosition(pos);
            cullLabel->setText("Cull: ");

            pos.x() = cullLabel->getBound().xMax();

            osg::ref_ptr<osgText::Text> cullValue = new osgText::Text;
            geode->addDrawable( cullValue.get() );

            cullValue->setColor(colorCull);
            cullValue->setFont(font);
            cullValue->setCharacterSize(characterSize);
            cullValue->setPosition(pos);
            cullValue->setText("0.0");

            cullValue->setDrawCallback(new TextDrawCallback(stats,"Cull traversal time taken",-1, 1000.0));

            pos.x() = startBlocks;
            osg::Geometry* geometry = createGeometry(pos, characterSize *0.8, colorCull, _numBlocks);
            geometry->setDrawCallback(new BlockDrawCallback(this, startBlocks, viewerStats, stats, "Cull traversal begin time", "Cull traversal end time", -1, _numBlocks));
            geode->addDrawable(geometry);

            pos.y() -= characterSize*1.5f;
        }

        {
            pos.x() = leftPos;

            osg::ref_ptr<osgText::Text> drawLabel = new osgText::Text;
            geode->addDrawable( drawLabel.get() );

            drawLabel->setColor(colorDraw);
            drawLabel->setFont(font);
            drawLabel->setCharacterSize(characterSize);
            drawLabel->setPosition(pos);
            drawLabel->setText("Draw: ");

            pos.x() = drawLabel->getBound().xMax();

            osg::ref_ptr<osgText::Text> drawValue = new osgText::Text;
            geode->addDrawable( drawValue.get() );

            drawValue->setColor(colorDraw);
            drawValue->setFont(font);
            drawValue->setCharacterSize(characterSize);
            drawValue->setPosition(pos);
            drawValue->setText("0.0");

            drawValue->setDrawCallback(new TextDrawCallback(stats,"Draw traversal time taken",-1, 1000.0));


            pos.x() = startBlocks;
            osg::Geometry* geometry = createGeometry(pos, characterSize *0.8, colorDraw, _numBlocks);
            geometry->setDrawCallback(new BlockDrawCallback(this, startBlocks, viewerStats, stats, "Draw traversal begin time", "Draw traversal end time", -1, _numBlocks));
            geode->addDrawable(geometry);

            pos.y() -= characterSize*1.5f;
        }

        if (aquireGPUStats)
        {
            pos.x() = leftPos;

            osg::ref_ptr<osgText::Text> gpuLabel = new osgText::Text;
            geode->addDrawable( gpuLabel.get() );

            gpuLabel->setColor(colorGPU);
            gpuLabel->setFont(font);
            gpuLabel->setCharacterSize(characterSize);
            gpuLabel->setPosition(pos);
            gpuLabel->setText("GPU: ");

            pos.x() = gpuLabel->getBound().xMax();

            osg::ref_ptr<osgText::Text> gpuValue = new osgText::Text;
            geode->addDrawable( gpuValue.get() );

            gpuValue->setColor(colorGPU);
            gpuValue->setFont(font);
            gpuValue->setCharacterSize(characterSize);
            gpuValue->setPosition(pos);
            gpuValue->setText("0.0");

            gpuValue->setDrawCallback(new TextDrawCallback(stats,"GPU draw time taken",-1, 1000.0));

            pos.x() = startBlocks;
            osg::Geometry* geometry = createGeometry(pos, characterSize *0.8, colorGPU, _numBlocks);
            geometry->setDrawCallback(new BlockDrawCallback(this, startBlocks, viewerStats, stats, "GPU draw begin time", "GPU draw end time", -1, _numBlocks));
            geode->addDrawable(geometry);

            pos.y() -= characterSize*1.5f;
        }


        pos.x() = leftPos;

        return group;
    }

    int                             _statsType;
    osg::ref_ptr<osg::Camera>       _camera;
    osg::ref_ptr<osg::Switch>       _switch;
    
    unsigned int                    _frameRateChildNum;
    unsigned int                    _viewerChildNum;
    unsigned int                    _sceneChildNum;
    unsigned int                    _numBlocks;
    double                          _blockMultiplier;
    
};

int main(int argc, char** argv)
{
    // use an ArgumentParser object to manage the program arguments.
    osg::ArgumentParser arguments(&argc,argv);

    arguments.getApplicationUsage()->setApplicationName(arguments.getApplicationName());
    arguments.getApplicationUsage()->setDescription(arguments.getApplicationName()+" is the standard OpenSceneGraph example which loads and visualises 3d models.");
    arguments.getApplicationUsage()->setCommandLineUsage(arguments.getApplicationName()+" [options] filename ...");
    arguments.getApplicationUsage()->addCommandLineOption("--image <filename>","Load an image and render it on a quad");
    arguments.getApplicationUsage()->addCommandLineOption("--dem <filename>","Load an image/DEM and render it on a HeightField");
    arguments.getApplicationUsage()->addCommandLineOption("-h or --help","Display command line parameters");
    arguments.getApplicationUsage()->addCommandLineOption("--help-env","Display environmental variables available");
    arguments.getApplicationUsage()->addCommandLineOption("--help-keys","Display keyboard & mouse bindings available");
    arguments.getApplicationUsage()->addCommandLineOption("--help-all","Display all command line, env vars and keyboard & mouse bindings.");

    // if user request help write it out to cout.
    bool helpAll = arguments.read("--help-all");
    unsigned int helpType = ((helpAll || arguments.read("-h") || arguments.read("--help"))? osg::ApplicationUsage::COMMAND_LINE_OPTION : 0 ) |
                            ((helpAll ||  arguments.read("--help-env"))? osg::ApplicationUsage::ENVIRONMENTAL_VARIABLE : 0 ) |
                            ((helpAll ||  arguments.read("--help-keys"))? osg::ApplicationUsage::KEYBOARD_MOUSE_BINDING : 0 );
    if (helpType)
    {
        arguments.getApplicationUsage()->write(std::cout, helpType);
        return 1;
    }

    // report any errors if they have occurred when parsing the program arguments.
    if (arguments.errors())
    {
        arguments.writeErrorMessages(std::cout);
        return 1;
    }
    
    if (arguments.argc()<=1)
    {
        arguments.getApplicationUsage()->write(std::cout,osg::ApplicationUsage::COMMAND_LINE_OPTION);
        return 1;
    }

    osgViewer::Viewer viewer;
    
    // set up the camera manipulators.
    {
        osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> keyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;

        keyswitchManipulator->addMatrixManipulator( '1', "Trackball", new osgGA::TrackballManipulator() );
        keyswitchManipulator->addMatrixManipulator( '2', "Flight", new osgGA::FlightManipulator() );
        keyswitchManipulator->addMatrixManipulator( '3', "Drive", new osgGA::DriveManipulator() );
        keyswitchManipulator->addMatrixManipulator( '4', "Terrain", new osgGA::TerrainManipulator() );

        std::string pathfile;
        char keyForAnimationPath = '5';
        while (arguments.read("-p",pathfile))
        {
            osgGA::AnimationPathManipulator* apm = new osgGA::AnimationPathManipulator(pathfile);
            if (apm || !apm->valid()) 
            {
                unsigned int num = keyswitchManipulator->getNumMatrixManipulators();
                keyswitchManipulator->addMatrixManipulator( keyForAnimationPath, "Path", apm );
                keyswitchManipulator->selectMatrixManipulator(num);
                ++keyForAnimationPath;
            }
        }

        viewer.setCameraManipulator( keyswitchManipulator.get() );
    }

    // add the state manipulator
    {
        osg::ref_ptr<osgGA::StateSetManipulator> statesetManipulator = new osgGA::StateSetManipulator;
        statesetManipulator->setStateSet(viewer.getCamera()->getOrCreateStateSet());

        viewer.addEventHandler( statesetManipulator.get() );
    }
    
    // add the thread model handler
    viewer.addEventHandler(new ThreadingHandler);

    // add the stats handler
    viewer.addEventHandler(new StatsHandler);

    // load the data
    osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFiles(arguments);
    if (!loadedModel) 
    {
        std::cout << arguments.getApplicationName() <<": No data loaded" << std::endl;
        return 1;
    }

    // any option left unread are converted into errors to write out later.
    arguments.reportRemainingOptionsAsUnrecognized();

    // report any errors if they have occurred when parsing the program arguments.
    if (arguments.errors())
    {
        arguments.writeErrorMessages(std::cout);
        return 1;
    }


    // optimize the scene graph, remove redundant nodes and state etc.
    osgUtil::Optimizer optimizer;
    optimizer.optimize(loadedModel.get());

    viewer.setSceneData( loadedModel.get() );

    return viewer.run();
}
