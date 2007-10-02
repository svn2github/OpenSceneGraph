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

#include <osg/ApplicationUsage>
#include <osg/ArgumentParser>
#include <osg/Camera>
#include <osg/CopyOp>
#include <osg/FrameStamp>
#include <osg/Object>
#include <osg/Timer>
#include <osgGA/EventQueue>
#include <osgViewer/CompositeViewer>
#include <osgViewer/View>
#include <osgViewer/ViewerBase>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgViewer::CompositeViewer)
	I_DeclaringFile("osgViewer/CompositeViewer");
	I_BaseType(osgViewer::ViewerBase);
	I_VirtualBaseType(osg::Object);
	I_Constructor0(____CompositeViewer,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgViewer::CompositeViewer &, x, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____CompositeViewer__C5_CompositeViewer_R1__C5_osg_CopyOp_R1,
	                           "",
	                           "");
	I_Constructor1(IN, osg::ArgumentParser &, arguments,
	               Properties::NON_EXPLICIT,
	               ____CompositeViewer__osg_ArgumentParser_R1,
	               "",
	               "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, readConfiguration, IN, const std::string &, filename,
	          Properties::VIRTUAL,
	          __bool__readConfiguration__C5_std_string_R1,
	          "read the viewer configuration from a configuration file. ",
	          "");
	I_Method1(void, addView, IN, osgViewer::View *, view,
	          Properties::NON_VIRTUAL,
	          __void__addView__osgViewer_View_P1,
	          "",
	          "");
	I_Method1(void, removeView, IN, osgViewer::View *, view,
	          Properties::NON_VIRTUAL,
	          __void__removeView__osgViewer_View_P1,
	          "",
	          "");
	I_Method1(osgViewer::View *, getView, IN, unsigned, i,
	          Properties::NON_VIRTUAL,
	          __osgViewer_View_P1__getView__unsigned,
	          "",
	          "");
	I_Method1(const osgViewer::View *, getView, IN, unsigned, i,
	          Properties::NON_VIRTUAL,
	          __C5_osgViewer_View_P1__getView__unsigned,
	          "",
	          "");
	I_Method0(unsigned int, getNumViews,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumViews,
	          "",
	          "");
	I_Method0(bool, isRealized,
	          Properties::VIRTUAL,
	          __bool__isRealized,
	          "Get whether at least of one of this viewers windows are realized. ",
	          "");
	I_Method0(void, realize,
	          Properties::VIRTUAL,
	          __void__realize,
	          "set up windows and associated threads. ",
	          "");
	I_Method1(void, setStartTick, IN, osg::Timer_t, tick,
	          Properties::VIRTUAL,
	          __void__setStartTick__osg_Timer_t,
	          "",
	          "");
	I_MethodWithDefaults1(void, setReferenceTime, IN, double, time, 0.0,
	                      Properties::NON_VIRTUAL,
	                      __void__setReferenceTime__double,
	                      "",
	                      "");
	I_Method0(osg::FrameStamp *, getFrameStamp,
	          Properties::NON_VIRTUAL,
	          __osg_FrameStamp_P1__getFrameStamp,
	          "",
	          "");
	I_Method0(const osg::FrameStamp *, getFrameStamp,
	          Properties::NON_VIRTUAL,
	          __C5_osg_FrameStamp_P1__getFrameStamp,
	          "",
	          "");
	I_Method0(double, elapsedTime,
	          Properties::VIRTUAL,
	          __double__elapsedTime,
	          "",
	          "");
	I_Method0(osg::FrameStamp *, getViewerFrameStamp,
	          Properties::VIRTUAL,
	          __osg_FrameStamp_P1__getViewerFrameStamp,
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
	I_Method0(int, run,
	          Properties::VIRTUAL,
	          __int__run,
	          "Execute a main frame loop. ",
	          "Equivialant to while (!viewer.done()) viewer.frame(); Also calls realize() if the viewer is not already realized, and installs trackball manipulator if one is not already assigned. ");
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
	I_Method1(void, setCameraWithFocus, IN, osg::Camera *, camera,
	          Properties::NON_VIRTUAL,
	          __void__setCameraWithFocus__osg_Camera_P1,
	          "",
	          "");
	I_Method0(osg::Camera *, getCameraWithFocus,
	          Properties::NON_VIRTUAL,
	          __osg_Camera_P1__getCameraWithFocus,
	          "",
	          "");
	I_Method0(const osg::Camera *, getCameraWithFocus,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Camera_P1__getCameraWithFocus,
	          "",
	          "");
	I_Method0(osgViewer::View *, getViewWithFocus,
	          Properties::NON_VIRTUAL,
	          __osgViewer_View_P1__getViewWithFocus,
	          "",
	          "");
	I_Method0(const osgViewer::View *, getViewWithFocus,
	          Properties::NON_VIRTUAL,
	          __C5_osgViewer_View_P1__getViewWithFocus,
	          "",
	          "");
	I_MethodWithDefaults2(void, getCameras, IN, osgViewer::ViewerBase::Cameras &, cameras, , IN, bool, onlyActive, true,
	                      Properties::VIRTUAL,
	                      __void__getCameras__Cameras_R1__bool,
	                      "",
	                      "");
	I_MethodWithDefaults2(void, getContexts, IN, osgViewer::ViewerBase::Contexts &, contexts, , IN, bool, onlyValid, true,
	                      Properties::VIRTUAL,
	                      __void__getContexts__Contexts_R1__bool,
	                      "",
	                      "");
	I_MethodWithDefaults2(void, getWindows, IN, osgViewer::ViewerBase::Windows &, windows, , IN, bool, onlyValid, true,
	                      Properties::VIRTUAL,
	                      __void__getWindows__Windows_R1__bool,
	                      "",
	                      "");
	I_MethodWithDefaults2(void, getAllThreads, IN, osgViewer::ViewerBase::Threads &, threads, , IN, bool, onlyActive, true,
	                      Properties::VIRTUAL,
	                      __void__getAllThreads__Threads_R1__bool,
	                      "",
	                      "");
	I_MethodWithDefaults2(void, getOperationThreads, IN, osgViewer::ViewerBase::OperationThreads &, threads, , IN, bool, onlyActive, true,
	                      Properties::VIRTUAL,
	                      __void__getOperationThreads__OperationThreads_R1__bool,
	                      "",
	                      "");
	I_MethodWithDefaults2(void, getScenes, IN, osgViewer::ViewerBase::Scenes &, scenes, , IN, bool, onlyValid, true,
	                      Properties::VIRTUAL,
	                      __void__getScenes__Scenes_R1__bool,
	                      "",
	                      "");
	I_MethodWithDefaults2(void, getViews, IN, osgViewer::ViewerBase::Views &, views, , IN, bool, onlyValid, true,
	                      Properties::VIRTUAL,
	                      __void__getViews__Views_R1__bool,
	                      "",
	                      "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this viewer. ",
	          "");
	I_ProtectedMethod0(void, constructorInit,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__constructorInit,
	                   "",
	                   "");
	I_ProtectedMethod0(void, viewerInit,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__viewerInit,
	                   "",
	                   "");
	I_SimpleProperty(osg::Camera *, CameraWithFocus, 
	                 __osg_Camera_P1__getCameraWithFocus, 
	                 __void__setCameraWithFocus__osg_Camera_P1);
	I_SimpleProperty(osgGA::EventQueue *, EventQueue, 
	                 __osgGA_EventQueue_P1__getEventQueue, 
	                 __void__setEventQueue__osgGA_EventQueue_P1);
	I_SimpleProperty(osg::FrameStamp *, FrameStamp, 
	                 __osg_FrameStamp_P1__getFrameStamp, 
	                 0);
	I_SimpleProperty(double, ReferenceTime, 
	                 0, 
	                 __void__setReferenceTime__double);
	I_SimpleProperty(osg::Timer_t, StartTick, 
	                 0, 
	                 __void__setStartTick__osg_Timer_t);
	I_ArrayProperty(osgViewer::View *, View, 
	                __osgViewer_View_P1__getView__unsigned, 
	                0, 
	                __unsigned_int__getNumViews, 
	                __void__addView__osgViewer_View_P1, 
	                0, 
	                0);
	I_SimpleProperty(osgViewer::View *, ViewWithFocus, 
	                 __osgViewer_View_P1__getViewWithFocus, 
	                 0);
	I_SimpleProperty(osg::FrameStamp *, ViewerFrameStamp, 
	                 __osg_FrameStamp_P1__getViewerFrameStamp, 
	                 0);
END_REFLECTOR

