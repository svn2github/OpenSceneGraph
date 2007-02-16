// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/.svn/text-base/Node.svn-base>
#include <osg/Camera>
#include <osgDB/.svn/text-base/DatabasePager.svn-base>
#include <osgGA/GUIEventHandler>
#include <osgGA/MatrixManipulator>
#include <osgUtil/SceneView>
#include <osgViewer/.svn/text-base/SimpleViewer.svn-base>
#include <osgViewer/SimpleViewer>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::list< osg::ref_ptr< osgGA::GUIEventHandler > >, osgViewer::SimpleViewer::EventHandlers);

BEGIN_OBJECT_REFLECTOR(osgViewer::SimpleViewer)
	I_VirtualBaseType(osgViewer::GraphicsWindow);
	I_VirtualBaseType(osgViewer::GraphicsWindow);
	I_Constructor0(____SimpleViewer,
	               "",
	               "");
	I_Method1(void, setSceneData, IN, osg::Node *, node,
	          Properties::NON_VIRTUAL,
	          __void__setSceneData__osg_Node_P1,
	          "",
	          "");
	I_Method0(osg::Node *, getSceneData,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__getSceneData,
	          "",
	          "");
	I_Method0(const osg::Node *, getSceneData,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Node_P1__getSceneData,
	          "",
	          "");
	I_Method1(void, setDatabasePager, IN, osgDB::DatabasePager *, dp,
	          Properties::NON_VIRTUAL,
	          __void__setDatabasePager__osgDB_DatabasePager_P1,
	          "",
	          "");
	I_Method0(osgDB::DatabasePager *, getDatabasePager,
	          Properties::NON_VIRTUAL,
	          __osgDB_DatabasePager_P1__getDatabasePager,
	          "",
	          "");
	I_Method0(const osgDB::DatabasePager *, getDatabasePager,
	          Properties::NON_VIRTUAL,
	          __C5_osgDB_DatabasePager_P1__getDatabasePager,
	          "",
	          "");
	I_Method0(osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method0(const osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method1(void, setCameraManipulator, IN, osgGA::MatrixManipulator *, manipulator,
	          Properties::NON_VIRTUAL,
	          __void__setCameraManipulator__osgGA_MatrixManipulator_P1,
	          "",
	          "");
	I_Method0(osgGA::MatrixManipulator *, getCameraManipulator,
	          Properties::NON_VIRTUAL,
	          __osgGA_MatrixManipulator_P1__getCameraManipulator,
	          "",
	          "");
	I_Method0(const osgGA::MatrixManipulator *, getCameraManipulator,
	          Properties::NON_VIRTUAL,
	          __C5_osgGA_MatrixManipulator_P1__getCameraManipulator,
	          "",
	          "");
	I_Method1(void, addEventHandler, IN, osgGA::GUIEventHandler *, eventHandler,
	          Properties::NON_VIRTUAL,
	          __void__addEventHandler__osgGA_GUIEventHandler_P1,
	          "",
	          "");
	I_Method0(osgViewer::SimpleViewer::EventHandlers &, getEventHandlers,
	          Properties::NON_VIRTUAL,
	          __EventHandlers_R1__getEventHandlers,
	          "",
	          "");
	I_Method0(const osgViewer::SimpleViewer::EventHandlers &, getEventHandlers,
	          Properties::NON_VIRTUAL,
	          __C5_EventHandlers_R1__getEventHandlers,
	          "",
	          "");
	I_MethodWithDefaults1(void, frame, IN, double, simulationTime, USE_REFERENCE_TIME,
	                      Properties::VIRTUAL,
	                      __void__frame__double,
	                      "Render a complete new frame. ",
	                      "Calls frameAdvance(), frameEventTraversal(), frameUpateTraversal(), frameCullTraversal() and frameDrawTraversal(). Note, no internal makeCurrent() is issued before, or swap buffers called after frame(), these operations are the responsibility of the calling code. ");
	I_MethodWithDefaults1(void, advance, IN, double, simulationTime, USE_REFERENCE_TIME,
	                      Properties::VIRTUAL,
	                      __void__advance__double,
	                      "",
	                      "");
	I_Method0(void, eventTraversal,
	          Properties::VIRTUAL,
	          __void__eventTraversal,
	          "",
	          "");
	I_Method0(void, updateTraversal,
	          Properties::VIRTUAL,
	          __void__updateTraversal,
	          "",
	          "");
	I_Method0(void, renderingTraversal,
	          Properties::VIRTUAL,
	          __void__renderingTraversal,
	          "",
	          "");
	I_Method0(void, releaseAllGLObjects,
	          Properties::VIRTUAL,
	          __void__releaseAllGLObjects,
	          "Release all OpenGL objects associated with this viewer's scenegraph. ",
	          "Note, does not deleted the actual OpenGL objects, it just releases them to the pending GL object delete lists which will need flushing once a valid graphics context is obtained. ");
	I_Method0(void, cleanup,
	          Properties::VIRTUAL,
	          __void__cleanup,
	          "Clean up all OpenGL objects associated with this viewer's scenegraph. ",
	          "Note, must only be called from the graphics context associated with this viewer. ");
	I_Method0(osgUtil::SceneView *, getSceneView,
	          Properties::NON_VIRTUAL,
	          __osgUtil_SceneView_P1__getSceneView,
	          "",
	          "");
	I_Method0(const osgUtil::SceneView *, getSceneView,
	          Properties::NON_VIRTUAL,
	          __C5_osgUtil_SceneView_P1__getSceneView,
	          "",
	          "");
	I_Method0(void, init,
	          Properties::NON_VIRTUAL,
	          __void__init,
	          "",
	          "");
	I_Constructor0(____SimpleViewer,
	               "",
	               "");
	I_Method1(void, setSceneData, IN, osg::Node *, node,
	          Properties::NON_VIRTUAL,
	          __void__setSceneData__osg_Node_P1,
	          "",
	          "");
	I_Method0(osg::Node *, getSceneData,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__getSceneData,
	          "",
	          "");
	I_Method0(const osg::Node *, getSceneData,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Node_P1__getSceneData,
	          "",
	          "");
	I_Method1(void, setDatabasePager, IN, osgDB::DatabasePager *, dp,
	          Properties::NON_VIRTUAL,
	          __void__setDatabasePager__osgDB_DatabasePager_P1,
	          "",
	          "");
	I_Method0(osgDB::DatabasePager *, getDatabasePager,
	          Properties::NON_VIRTUAL,
	          __osgDB_DatabasePager_P1__getDatabasePager,
	          "",
	          "");
	I_Method0(const osgDB::DatabasePager *, getDatabasePager,
	          Properties::NON_VIRTUAL,
	          __C5_osgDB_DatabasePager_P1__getDatabasePager,
	          "",
	          "");
	I_Method0(osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method0(const osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method1(void, setCameraManipulator, IN, osgGA::MatrixManipulator *, manipulator,
	          Properties::NON_VIRTUAL,
	          __void__setCameraManipulator__osgGA_MatrixManipulator_P1,
	          "",
	          "");
	I_Method0(osgGA::MatrixManipulator *, getCameraManipulator,
	          Properties::NON_VIRTUAL,
	          __osgGA_MatrixManipulator_P1__getCameraManipulator,
	          "",
	          "");
	I_Method0(const osgGA::MatrixManipulator *, getCameraManipulator,
	          Properties::NON_VIRTUAL,
	          __C5_osgGA_MatrixManipulator_P1__getCameraManipulator,
	          "",
	          "");
	I_Method1(void, addEventHandler, IN, osgGA::GUIEventHandler *, eventHandler,
	          Properties::NON_VIRTUAL,
	          __void__addEventHandler__osgGA_GUIEventHandler_P1,
	          "",
	          "");
	I_Method0(osgViewer::SimpleViewer::EventHandlers &, getEventHandlers,
	          Properties::NON_VIRTUAL,
	          __EventHandlers_R1__getEventHandlers,
	          "",
	          "");
	I_Method0(const osgViewer::SimpleViewer::EventHandlers &, getEventHandlers,
	          Properties::NON_VIRTUAL,
	          __C5_EventHandlers_R1__getEventHandlers,
	          "",
	          "");
	I_MethodWithDefaults1(void, frame, IN, double, simulationTime, USE_REFERENCE_TIME,
	                      Properties::VIRTUAL,
	                      __void__frame__double,
	                      "Render a complete new frame. ",
	                      "Calls frameAdvance(), frameEventTraversal(), frameUpateTraversal(), frameCullTraversal() and frameDrawTraversal(). Note, no internal makeCurrent() is issued before, or swap buffers called after frame(), these operations are the responsibility of the calling code. ");
	I_MethodWithDefaults1(void, advance, IN, double, simulationTime, USE_REFERENCE_TIME,
	                      Properties::VIRTUAL,
	                      __void__advance__double,
	                      "",
	                      "");
	I_Method0(void, eventTraversal,
	          Properties::VIRTUAL,
	          __void__eventTraversal,
	          "",
	          "");
	I_Method0(void, updateTraversal,
	          Properties::VIRTUAL,
	          __void__updateTraversal,
	          "",
	          "");
	I_Method0(void, renderingTraversal,
	          Properties::VIRTUAL,
	          __void__renderingTraversal,
	          "",
	          "");
	I_Method0(void, releaseAllGLObjects,
	          Properties::VIRTUAL,
	          __void__releaseAllGLObjects,
	          "Release all OpenGL objects associated with this viewer's scenegraph. ",
	          "Note, does not deleted the actual OpenGL objects, it just releases them to the pending GL object delete lists which will need flushing once a valid graphics context is obtained. ");
	I_Method0(void, cleanup,
	          Properties::VIRTUAL,
	          __void__cleanup,
	          "Clean up all OpenGL objects associated with this viewer's scenegraph. ",
	          "Note, must only be called from the graphics context associated with this viewer. ");
	I_Method0(osgUtil::SceneView *, getSceneView,
	          Properties::NON_VIRTUAL,
	          __osgUtil_SceneView_P1__getSceneView,
	          "",
	          "");
	I_Method0(const osgUtil::SceneView *, getSceneView,
	          Properties::NON_VIRTUAL,
	          __C5_osgUtil_SceneView_P1__getSceneView,
	          "",
	          "");
	I_Method0(void, init,
	          Properties::NON_VIRTUAL,
	          __void__init,
	          "",
	          "");
	I_SimpleProperty(osg::Camera *, Camera, 
	                 __osg_Camera_P1__getCamera, 
	                 0);
	I_SimpleProperty(osgGA::MatrixManipulator *, CameraManipulator, 
	                 __osgGA_MatrixManipulator_P1__getCameraManipulator, 
	                 __void__setCameraManipulator__osgGA_MatrixManipulator_P1);
	I_SimpleProperty(osgDB::DatabasePager *, DatabasePager, 
	                 __osgDB_DatabasePager_P1__getDatabasePager, 
	                 __void__setDatabasePager__osgDB_DatabasePager_P1);
	I_SimpleProperty(osgViewer::SimpleViewer::EventHandlers &, EventHandlers, 
	                 __EventHandlers_R1__getEventHandlers, 
	                 0);
	I_SimpleProperty(osg::Node *, SceneData, 
	                 __osg_Node_P1__getSceneData, 
	                 __void__setSceneData__osg_Node_P1);
	I_SimpleProperty(osgUtil::SceneView *, SceneView, 
	                 __osgUtil_SceneView_P1__getSceneView, 
	                 0);
END_REFLECTOR

TYPE_NAME_ALIAS(std::list< osg::ref_ptr< osgGA::GUIEventHandler > >, osgViewer::SimpleViewer::EventHandlers);

BEGIN_OBJECT_REFLECTOR(osgViewer::SimpleViewer)
	I_VirtualBaseType(osgViewer::GraphicsWindow);
	I_VirtualBaseType(osgViewer::GraphicsWindow);
	I_Constructor0(____SimpleViewer,
	               "",
	               "");
	I_Method1(void, setSceneData, IN, osg::Node *, node,
	          Properties::NON_VIRTUAL,
	          __void__setSceneData__osg_Node_P1,
	          "",
	          "");
	I_Method0(osg::Node *, getSceneData,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__getSceneData,
	          "",
	          "");
	I_Method0(const osg::Node *, getSceneData,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Node_P1__getSceneData,
	          "",
	          "");
	I_Method1(void, setDatabasePager, IN, osgDB::DatabasePager *, dp,
	          Properties::NON_VIRTUAL,
	          __void__setDatabasePager__osgDB_DatabasePager_P1,
	          "",
	          "");
	I_Method0(osgDB::DatabasePager *, getDatabasePager,
	          Properties::NON_VIRTUAL,
	          __osgDB_DatabasePager_P1__getDatabasePager,
	          "",
	          "");
	I_Method0(const osgDB::DatabasePager *, getDatabasePager,
	          Properties::NON_VIRTUAL,
	          __C5_osgDB_DatabasePager_P1__getDatabasePager,
	          "",
	          "");
	I_Method0(osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method0(const osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method1(void, setCameraManipulator, IN, osgGA::MatrixManipulator *, manipulator,
	          Properties::NON_VIRTUAL,
	          __void__setCameraManipulator__osgGA_MatrixManipulator_P1,
	          "",
	          "");
	I_Method0(osgGA::MatrixManipulator *, getCameraManipulator,
	          Properties::NON_VIRTUAL,
	          __osgGA_MatrixManipulator_P1__getCameraManipulator,
	          "",
	          "");
	I_Method0(const osgGA::MatrixManipulator *, getCameraManipulator,
	          Properties::NON_VIRTUAL,
	          __C5_osgGA_MatrixManipulator_P1__getCameraManipulator,
	          "",
	          "");
	I_Method1(void, addEventHandler, IN, osgGA::GUIEventHandler *, eventHandler,
	          Properties::NON_VIRTUAL,
	          __void__addEventHandler__osgGA_GUIEventHandler_P1,
	          "",
	          "");
	I_Method0(osgViewer::SimpleViewer::EventHandlers &, getEventHandlers,
	          Properties::NON_VIRTUAL,
	          __EventHandlers_R1__getEventHandlers,
	          "",
	          "");
	I_Method0(const osgViewer::SimpleViewer::EventHandlers &, getEventHandlers,
	          Properties::NON_VIRTUAL,
	          __C5_EventHandlers_R1__getEventHandlers,
	          "",
	          "");
	I_MethodWithDefaults1(void, frame, IN, double, simulationTime, USE_REFERENCE_TIME,
	                      Properties::VIRTUAL,
	                      __void__frame__double,
	                      "Render a complete new frame. ",
	                      "Calls frameAdvance(), frameEventTraversal(), frameUpateTraversal(), frameCullTraversal() and frameDrawTraversal(). Note, no internal makeCurrent() is issued before, or swap buffers called after frame(), these operations are the responsibility of the calling code. ");
	I_MethodWithDefaults1(void, advance, IN, double, simulationTime, USE_REFERENCE_TIME,
	                      Properties::VIRTUAL,
	                      __void__advance__double,
	                      "",
	                      "");
	I_Method0(void, eventTraversal,
	          Properties::VIRTUAL,
	          __void__eventTraversal,
	          "",
	          "");
	I_Method0(void, updateTraversal,
	          Properties::VIRTUAL,
	          __void__updateTraversal,
	          "",
	          "");
	I_Method0(void, renderingTraversal,
	          Properties::VIRTUAL,
	          __void__renderingTraversal,
	          "",
	          "");
	I_Method0(void, releaseAllGLObjects,
	          Properties::VIRTUAL,
	          __void__releaseAllGLObjects,
	          "Release all OpenGL objects associated with this viewer's scenegraph. ",
	          "Note, does not deleted the actual OpenGL objects, it just releases them to the pending GL object delete lists which will need flushing once a valid graphics context is obtained. ");
	I_Method0(void, cleanup,
	          Properties::VIRTUAL,
	          __void__cleanup,
	          "Clean up all OpenGL objects associated with this viewer's scenegraph. ",
	          "Note, must only be called from the graphics context associated with this viewer. ");
	I_Method0(osgUtil::SceneView *, getSceneView,
	          Properties::NON_VIRTUAL,
	          __osgUtil_SceneView_P1__getSceneView,
	          "",
	          "");
	I_Method0(const osgUtil::SceneView *, getSceneView,
	          Properties::NON_VIRTUAL,
	          __C5_osgUtil_SceneView_P1__getSceneView,
	          "",
	          "");
	I_Method0(void, init,
	          Properties::NON_VIRTUAL,
	          __void__init,
	          "",
	          "");
	I_Constructor0(____SimpleViewer,
	               "",
	               "");
	I_Method1(void, setSceneData, IN, osg::Node *, node,
	          Properties::NON_VIRTUAL,
	          __void__setSceneData__osg_Node_P1,
	          "",
	          "");
	I_Method0(osg::Node *, getSceneData,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__getSceneData,
	          "",
	          "");
	I_Method0(const osg::Node *, getSceneData,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Node_P1__getSceneData,
	          "",
	          "");
	I_Method1(void, setDatabasePager, IN, osgDB::DatabasePager *, dp,
	          Properties::NON_VIRTUAL,
	          __void__setDatabasePager__osgDB_DatabasePager_P1,
	          "",
	          "");
	I_Method0(osgDB::DatabasePager *, getDatabasePager,
	          Properties::NON_VIRTUAL,
	          __osgDB_DatabasePager_P1__getDatabasePager,
	          "",
	          "");
	I_Method0(const osgDB::DatabasePager *, getDatabasePager,
	          Properties::NON_VIRTUAL,
	          __C5_osgDB_DatabasePager_P1__getDatabasePager,
	          "",
	          "");
	I_Method0(osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method0(const osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Camera_P1__getCamera,
	          "",
	          "");
	I_Method1(void, setCameraManipulator, IN, osgGA::MatrixManipulator *, manipulator,
	          Properties::NON_VIRTUAL,
	          __void__setCameraManipulator__osgGA_MatrixManipulator_P1,
	          "",
	          "");
	I_Method0(osgGA::MatrixManipulator *, getCameraManipulator,
	          Properties::NON_VIRTUAL,
	          __osgGA_MatrixManipulator_P1__getCameraManipulator,
	          "",
	          "");
	I_Method0(const osgGA::MatrixManipulator *, getCameraManipulator,
	          Properties::NON_VIRTUAL,
	          __C5_osgGA_MatrixManipulator_P1__getCameraManipulator,
	          "",
	          "");
	I_Method1(void, addEventHandler, IN, osgGA::GUIEventHandler *, eventHandler,
	          Properties::NON_VIRTUAL,
	          __void__addEventHandler__osgGA_GUIEventHandler_P1,
	          "",
	          "");
	I_Method0(osgViewer::SimpleViewer::EventHandlers &, getEventHandlers,
	          Properties::NON_VIRTUAL,
	          __EventHandlers_R1__getEventHandlers,
	          "",
	          "");
	I_Method0(const osgViewer::SimpleViewer::EventHandlers &, getEventHandlers,
	          Properties::NON_VIRTUAL,
	          __C5_EventHandlers_R1__getEventHandlers,
	          "",
	          "");
	I_MethodWithDefaults1(void, frame, IN, double, simulationTime, USE_REFERENCE_TIME,
	                      Properties::VIRTUAL,
	                      __void__frame__double,
	                      "Render a complete new frame. ",
	                      "Calls frameAdvance(), frameEventTraversal(), frameUpateTraversal(), frameCullTraversal() and frameDrawTraversal(). Note, no internal makeCurrent() is issued before, or swap buffers called after frame(), these operations are the responsibility of the calling code. ");
	I_MethodWithDefaults1(void, advance, IN, double, simulationTime, USE_REFERENCE_TIME,
	                      Properties::VIRTUAL,
	                      __void__advance__double,
	                      "",
	                      "");
	I_Method0(void, eventTraversal,
	          Properties::VIRTUAL,
	          __void__eventTraversal,
	          "",
	          "");
	I_Method0(void, updateTraversal,
	          Properties::VIRTUAL,
	          __void__updateTraversal,
	          "",
	          "");
	I_Method0(void, renderingTraversal,
	          Properties::VIRTUAL,
	          __void__renderingTraversal,
	          "",
	          "");
	I_Method0(void, releaseAllGLObjects,
	          Properties::VIRTUAL,
	          __void__releaseAllGLObjects,
	          "Release all OpenGL objects associated with this viewer's scenegraph. ",
	          "Note, does not deleted the actual OpenGL objects, it just releases them to the pending GL object delete lists which will need flushing once a valid graphics context is obtained. ");
	I_Method0(void, cleanup,
	          Properties::VIRTUAL,
	          __void__cleanup,
	          "Clean up all OpenGL objects associated with this viewer's scenegraph. ",
	          "Note, must only be called from the graphics context associated with this viewer. ");
	I_Method0(osgUtil::SceneView *, getSceneView,
	          Properties::NON_VIRTUAL,
	          __osgUtil_SceneView_P1__getSceneView,
	          "",
	          "");
	I_Method0(const osgUtil::SceneView *, getSceneView,
	          Properties::NON_VIRTUAL,
	          __C5_osgUtil_SceneView_P1__getSceneView,
	          "",
	          "");
	I_Method0(void, init,
	          Properties::NON_VIRTUAL,
	          __void__init,
	          "",
	          "");
	I_SimpleProperty(osg::Camera *, Camera, 
	                 __osg_Camera_P1__getCamera, 
	                 0);
	I_SimpleProperty(osgGA::MatrixManipulator *, CameraManipulator, 
	                 __osgGA_MatrixManipulator_P1__getCameraManipulator, 
	                 __void__setCameraManipulator__osgGA_MatrixManipulator_P1);
	I_SimpleProperty(osgDB::DatabasePager *, DatabasePager, 
	                 __osgDB_DatabasePager_P1__getDatabasePager, 
	                 __void__setDatabasePager__osgDB_DatabasePager_P1);
	I_SimpleProperty(osgViewer::SimpleViewer::EventHandlers &, EventHandlers, 
	                 __EventHandlers_R1__getEventHandlers, 
	                 0);
	I_SimpleProperty(osg::Node *, SceneData, 
	                 __osg_Node_P1__getSceneData, 
	                 __void__setSceneData__osg_Node_P1);
	I_SimpleProperty(osgUtil::SceneView *, SceneView, 
	                 __osgUtil_SceneView_P1__getSceneView, 
	                 0);
END_REFLECTOR

