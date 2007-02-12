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

#include <osg/Camera>
#include <osg/DisplaySettings>
#include <osg/Node>
#include <osg/State>
#include <osgGA/EventQueue>
#include <osgGA/GUIEventHandler>
#include <osgGA/MatrixManipulator>
#include <osgUtil/LineSegmentIntersector>
#include <osgViewer/Scene>
#include <osgViewer/View>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgViewer::EndOfDynamicDrawBlock)
	I_BaseType(osg::State::DynamicObjectRenderingCompletedCallback);
	I_Constructor1(IN, unsigned, int,
	               Properties::NON_EXPLICIT,
	               ____EndOfDynamicDrawBlock__unsigned,
	               "",
	               "");
	I_Method1(void, completed, IN, osg::State *, state,
	          Properties::VIRTUAL,
	          __void__completed__osg_State_P1,
	          "",
	          "");
	I_Method0(void, block,
	          Properties::NON_VIRTUAL,
	          __void__block,
	          "",
	          "");
	I_Method0(void, reset,
	          Properties::NON_VIRTUAL,
	          __void__reset,
	          "",
	          "");
	I_Method0(void, release,
	          Properties::NON_VIRTUAL,
	          __void__release,
	          "",
	          "");
	I_Method1(void, setNumOfBlocks, IN, unsigned int, blockCount,
	          Properties::NON_VIRTUAL,
	          __void__setNumOfBlocks__unsigned_int,
	          "",
	          "");
	I_SimpleProperty(unsigned int, NumOfBlocks, 
	                 0, 
	                 __void__setNumOfBlocks__unsigned_int);
END_REFLECTOR

TYPE_NAME_ALIAS(std::list< osg::ref_ptr< osgGA::GUIEventHandler > >, osgViewer::View::EventHandlers);

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgViewer::View)
	I_BaseType(osg::View);
	I_BaseType(osgGA::GUIActionAdapter);
	I_Constructor0(____View,
	               "",
	               "");
	I_Method0(osgViewer::Scene *, getScene,
	          Properties::NON_VIRTUAL,
	          __Scene_P1__getScene,
	          "",
	          "");
	I_Method0(const osgViewer::Scene *, getScene,
	          Properties::NON_VIRTUAL,
	          __C5_Scene_P1__getScene,
	          "",
	          "");
	I_Method1(void, setSceneData, IN, osg::Node *, node,
	          Properties::VIRTUAL,
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
	I_Method1(void, setEventQueue, IN, osgGA::EventQueue *, eventQueue,
	          Properties::NON_VIRTUAL,
	          __void__setEventQueue__osgGA_EventQueue_P1,
	          "",
	          "");
	I_Method0(osgGA::EventQueue *, getEventQueue,
	          Properties::NON_VIRTUAL,
	          __osgGA_EventQueue_P1__getEventQueue,
	          "",
	          "");
	I_Method0(const osgGA::EventQueue *, getEventQueue,
	          Properties::NON_VIRTUAL,
	          __C5_osgGA_EventQueue_P1__getEventQueue,
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
	I_Method0(osgViewer::View::EventHandlers &, getEventHandlers,
	          Properties::NON_VIRTUAL,
	          __EventHandlers_R1__getEventHandlers,
	          "",
	          "");
	I_Method0(const osgViewer::View::EventHandlers &, getEventHandlers,
	          Properties::NON_VIRTUAL,
	          __C5_EventHandlers_R1__getEventHandlers,
	          "",
	          "");
	I_Method1(void, setDisplaySettings, IN, osg::DisplaySettings *, ds,
	          Properties::NON_VIRTUAL,
	          __void__setDisplaySettings__osg_DisplaySettings_P1,
	          "Set the DsplaySettings object associated with this view. ",
	          "");
	I_Method0(osg::DisplaySettings *, getDisplaySettings,
	          Properties::NON_VIRTUAL,
	          __osg_DisplaySettings_P1__getDisplaySettings,
	          "Set the DsplaySettings object associated with this view. ",
	          "");
	I_Method0(const osg::DisplaySettings *, getDisplaySettings,
	          Properties::NON_VIRTUAL,
	          __C5_osg_DisplaySettings_P1__getDisplaySettings,
	          "Set the DsplaySettings object associated with this view. ",
	          "");
	I_Method0(void, setUpViewAcrossAllScreens,
	          Properties::NON_VIRTUAL,
	          __void__setUpViewAcrossAllScreens,
	          "Convinience method for creating slave Cameras and associated GraphicsWindows across all screens. ",
	          "");
	I_MethodWithDefaults1(void, setUpViewOnSingleScreen, IN, unsigned int, screenNum, 0,
	                      Properties::NON_VIRTUAL,
	                      __void__setUpViewOnSingleScreen__unsigned_int,
	                      "Convinience method for a single Camara associated with a single full screen GraphicsWindow. ",
	                      "");
	I_Method1(bool, containsCamera, IN, const osg::Camera *, camera,
	          Properties::NON_VIRTUAL,
	          __bool__containsCamera__C5_osg_Camera_P1,
	          "Return true if this view contains a specified camera. ",
	          "");
	I_Method4(const osg::Camera *, getCameraContainingPosition, IN, float, x, IN, float, y, IN, float &, local_x, IN, float &, local_y,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Camera_P1__getCameraContainingPosition__float__float__float_R1__float_R1,
	          "Get the camera which contains the pointer position x,y specified master cameras window/eye coords. ",
	          "Also passes back the local window coords for the graphics context associated with the camera passed back. ");
	I_MethodWithDefaults4(bool, computeIntersections, IN, float, x, , IN, float, y, , IN, osgUtil::LineSegmentIntersector::Intersections &, intersections, , IN, osg::Node::NodeMask, traversalMask, 0xffffffff,
	                      Properties::NON_VIRTUAL,
	                      __bool__computeIntersections__float__float__osgUtil_LineSegmentIntersector_Intersections_R1__osg_Node_NodeMask,
	                      "Compute intersections between a ray through the specified master cameras window/eye coords and a specified node. ",
	                      "Note, when a master cameras has slaves and no viewport itself its coordinate frame will be in clip space i.e. -1,-1 to 1,1, while if its has a viewport the coordintates will be relative to its viewport dimensions. Mouse events handled by the view will automatically be attached into the master camera window/clip coords so can be passed directly on to the computeIntersections method. ");
	I_MethodWithDefaults5(bool, computeIntersections, IN, float, x, , IN, float, y, , IN, osg::NodePath &, nodePath, , IN, osgUtil::LineSegmentIntersector::Intersections &, intersections, , IN, osg::Node::NodeMask, traversalMask, 0xffffffff,
	                      Properties::NON_VIRTUAL,
	                      __bool__computeIntersections__float__float__osg_NodePath_R1__osgUtil_LineSegmentIntersector_Intersections_R1__osg_Node_NodeMask,
	                      "Compute intersections between a ray through the specified master cameras window/eye coords and a specified nodePath's subgraph. ",
	                      "");
	I_Method0(void, requestRedraw,
	          Properties::VIRTUAL,
	          __void__requestRedraw,
	          "requestRedraw() requests a single redraw. ",
	          "");
	I_MethodWithDefaults1(void, requestContinuousUpdate, IN, bool, needed, true,
	                      Properties::VIRTUAL,
	                      __void__requestContinuousUpdate__bool,
	                      "requestContinousUpdate(bool) is for en/disabling a throw or idle callback to be requested by a GUIEventHandler (typically a MatrixManipulator, though other GUIEventHandler's may also provide functionality). ",
	                      "GUI toolkits can respond to this immediately by registering an idle/timed callback, or can delay setting the callback and update at their own leisure.");
	I_Method2(void, requestWarpPointer, IN, float, x, IN, float, y,
	          Properties::VIRTUAL,
	          __void__requestWarpPointer__float__float,
	          "requestWarpPointer(int,int) is requesting a repositioning of the mouse pointer to a specified x,y location on the window. ",
	          "This is used by some camera manipulators to initialise the mouse pointer when mouse position relative to a controls neutral mouse position is required, i.e when mimicking a aircrafts joystick.");
	I_Method0(void, assignSceneDataToCameras,
	          Properties::NON_VIRTUAL,
	          __void__assignSceneDataToCameras,
	          "",
	          "");
	I_Method0(void, init,
	          Properties::NON_VIRTUAL,
	          __void__init,
	          "",
	          "");
	I_SimpleProperty(osgGA::MatrixManipulator *, CameraManipulator, 
	                 __osgGA_MatrixManipulator_P1__getCameraManipulator, 
	                 __void__setCameraManipulator__osgGA_MatrixManipulator_P1);
	I_SimpleProperty(osg::DisplaySettings *, DisplaySettings, 
	                 __osg_DisplaySettings_P1__getDisplaySettings, 
	                 __void__setDisplaySettings__osg_DisplaySettings_P1);
	I_SimpleProperty(osgViewer::View::EventHandlers &, EventHandlers, 
	                 __EventHandlers_R1__getEventHandlers, 
	                 0);
	I_SimpleProperty(osgGA::EventQueue *, EventQueue, 
	                 __osgGA_EventQueue_P1__getEventQueue, 
	                 __void__setEventQueue__osgGA_EventQueue_P1);
	I_SimpleProperty(osgViewer::Scene *, Scene, 
	                 __Scene_P1__getScene, 
	                 0);
	I_SimpleProperty(osg::Node *, SceneData, 
	                 __osg_Node_P1__getSceneData, 
	                 __void__setSceneData__osg_Node_P1);
	I_SimpleProperty(unsigned int, UpViewOnSingleScreen, 
	                 0, 
	                 __void__setUpViewOnSingleScreen__unsigned_int);
END_REFLECTOR

