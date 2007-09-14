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
#include <osg/Matrixd>
#include <osg/Node>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>
#include <osgGA/NodeTrackerManipulator>
#include <osgUtil/SceneView>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::vector< osg::observer_ptr< osg::Node > >, osgGA::NodeTrackerManipulator::ObserverNodePath)

BEGIN_ENUM_REFLECTOR(osgGA::NodeTrackerManipulator::TrackerMode)
	I_DeclaringFile("osgGA/NodeTrackerManipulator");
	I_EnumLabel(osgGA::NodeTrackerManipulator::NODE_CENTER);
	I_EnumLabel(osgGA::NodeTrackerManipulator::NODE_CENTER_AND_AZIM);
	I_EnumLabel(osgGA::NodeTrackerManipulator::NODE_CENTER_AND_ROTATION);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgGA::NodeTrackerManipulator::RotationMode)
	I_DeclaringFile("osgGA/NodeTrackerManipulator");
	I_EnumLabel(osgGA::NodeTrackerManipulator::TRACKBALL);
	I_EnumLabel(osgGA::NodeTrackerManipulator::ELEVATION_AZIM);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgGA::NodeTrackerManipulator)
	I_DeclaringFile("osgGA/NodeTrackerManipulator");
	I_BaseType(osgGA::MatrixManipulator);
	I_Constructor0(____NodeTrackerManipulator,
	               "",
	               "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, setTrackNodePath, IN, const osg::NodePath &, nodePath,
	          Properties::NON_VIRTUAL,
	          __void__setTrackNodePath__C5_osg_NodePath_R1,
	          "",
	          "");
	I_Method1(void, setTrackNodePath, IN, const osgGA::NodeTrackerManipulator::ObserverNodePath &, nodePath,
	          Properties::NON_VIRTUAL,
	          __void__setTrackNodePath__C5_ObserverNodePath_R1,
	          "",
	          "");
	I_Method0(osgGA::NodeTrackerManipulator::ObserverNodePath &, getTrackNodePath,
	          Properties::NON_VIRTUAL,
	          __ObserverNodePath_R1__getTrackNodePath,
	          "",
	          "");
	I_Method1(void, setTrackNode, IN, osg::Node *, node,
	          Properties::NON_VIRTUAL,
	          __void__setTrackNode__osg_Node_P1,
	          "",
	          "");
	I_Method0(osg::Node *, getTrackNode,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__getTrackNode,
	          "",
	          "");
	I_Method0(const osg::Node *, getTrackNode,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Node_P1__getTrackNode,
	          "",
	          "");
	I_Method1(void, setTrackerMode, IN, osgGA::NodeTrackerManipulator::TrackerMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setTrackerMode__TrackerMode,
	          "",
	          "");
	I_Method0(osgGA::NodeTrackerManipulator::TrackerMode, getTrackerMode,
	          Properties::NON_VIRTUAL,
	          __TrackerMode__getTrackerMode,
	          "",
	          "");
	I_Method1(void, setRotationMode, IN, osgGA::NodeTrackerManipulator::RotationMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setRotationMode__RotationMode,
	          "",
	          "");
	I_Method0(osgGA::NodeTrackerManipulator::RotationMode, getRotationMode,
	          Properties::NON_VIRTUAL,
	          __RotationMode__getRotationMode,
	          "",
	          "");
	I_Method1(void, setByMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByMatrix__C5_osg_Matrixd_R1,
	          "set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method1(void, setByInverseMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByInverseMatrix__C5_osg_Matrixd_R1,
	          "set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getMatrix,
	          "get the position of the manipulator as 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getInverseMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getInverseMatrix,
	          "get the position of the manipulator as a inverse matrix of the manipulator, typically used as a model view matrix. ",
	          "");
	I_Method0(osgUtil::SceneView::FusionDistanceMode, getFusionDistanceMode,
	          Properties::VIRTUAL,
	          __osgUtil_SceneView_FusionDistanceMode__getFusionDistanceMode,
	          "Get the FusionDistanceMode. ",
	          "Used by SceneView for setting up setereo convergence. ");
	I_Method0(float, getFusionDistanceValue,
	          Properties::VIRTUAL,
	          __float__getFusionDistanceValue,
	          "Get the FusionDistanceValue. ",
	          "Used by SceneView for setting up setereo convergence. ");
	I_Method1(void, setNode, IN, osg::Node *, x,
	          Properties::VIRTUAL,
	          __void__setNode__osg_Node_P1,
	          "Attach a node to the manipulator. ",
	          "Automatically detaches previously attached node. setNode(NULL) detaches previously nodes. Is ignored by manipulators which do not require a reference model. ");
	I_Method0(const osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __C5_osg_Node_P1__getNode,
	          "Return node if attached. ",
	          "");
	I_Method0(osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __osg_Node_P1__getNode,
	          "Return node if attached. ",
	          "");
	I_Method0(void, computeHomePosition,
	          Properties::VIRTUAL,
	          __void__computeHomePosition,
	          "Compute the home position. ",
	          "");
	I_Method2(void, home, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          Properties::VIRTUAL,
	          __void__home__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "Move the camera to the default position. ",
	          "May be ignored by manipulators if home functionality is not appropriate. ");
	I_Method2(void, init, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          Properties::VIRTUAL,
	          __void__init__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "Start/restart the manipulator. ",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          Properties::VIRTUAL,
	          __bool__handle__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "handle events, return true if handled, false otherwise. ",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_ProtectedMethod0(osg::NodePath, getNodePath,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __osg_NodePath__getNodePath,
	                   "",
	                   "");
	I_ProtectedMethod0(bool, validateNodePath,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __bool__validateNodePath,
	                   "",
	                   "");
	I_ProtectedMethod0(void, flushMouseEventStack,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__flushMouseEventStack,
	                   "Reset the internal GUIEvent stack. ",
	                   "");
	I_ProtectedMethod1(void, addMouseEvent, IN, const osgGA::GUIEventAdapter &, ea,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__addMouseEvent__C5_GUIEventAdapter_R1,
	                   "Add the current mouse GUIEvent to internal stack. ",
	                   "");
	I_ProtectedMethod1(void, computeNodeWorldToLocal, IN, osg::Matrixd &, worldToLocal,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeNodeWorldToLocal__osg_Matrixd_R1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, computeNodeLocalToWorld, IN, osg::Matrixd &, localToWorld,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeNodeLocalToWorld__osg_Matrixd_R1,
	                   "",
	                   "");
	I_ProtectedMethod2(void, computeNodeCenterAndRotation, IN, osg::Vec3d &, center, IN, osg::Quat &, rotation,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeNodeCenterAndRotation__osg_Vec3d_R1__osg_Quat_R1,
	                   "",
	                   "");
	I_ProtectedMethod3(void, computePosition, IN, const osg::Vec3d &, eye, IN, const osg::Vec3d &, lv, IN, const osg::Vec3d &, up,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__computePosition__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1,
	                   "",
	                   "");
	I_ProtectedMethod0(bool, calcMovement,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool__calcMovement,
	                   "For the give mouse movement calculate the movement of the camera. ",
	                   "Return true is camera has moved and a redraw is required. ");
	I_ProtectedMethod6(void, trackball, IN, osg::Vec3 &, axis, IN, double &, angle, IN, double, p1x, IN, double, p1y, IN, double, p2x, IN, double, p2y,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__trackball__osg_Vec3_R1__double_R1__double__double__double__double,
	                   "",
	                   "");
	I_ProtectedMethod3(double, tb_project_to_sphere, IN, double, r, IN, double, x, IN, double, y,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __double__tb_project_to_sphere__double__double__double,
	                   "",
	                   "");
	I_ProtectedMethod0(bool, isMouseMoving,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool__isMouseMoving,
	                   "Check the speed at which the mouse is moving. ",
	                   "If speed is below a threshold then return false, otherwise return true. ");
	I_ProtectedMethod0(void, clampOrientation,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__clampOrientation,
	                   "",
	                   "");
	I_SimpleProperty(const osg::Matrixd &, ByInverseMatrix, 
	                 0, 
	                 __void__setByInverseMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(const osg::Matrixd &, ByMatrix, 
	                 0, 
	                 __void__setByMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(osgUtil::SceneView::FusionDistanceMode, FusionDistanceMode, 
	                 __osgUtil_SceneView_FusionDistanceMode__getFusionDistanceMode, 
	                 0);
	I_SimpleProperty(float, FusionDistanceValue, 
	                 __float__getFusionDistanceValue, 
	                 0);
	I_SimpleProperty(osg::Matrixd, InverseMatrix, 
	                 __osg_Matrixd__getInverseMatrix, 
	                 0);
	I_SimpleProperty(osg::Matrixd, Matrix, 
	                 __osg_Matrixd__getMatrix, 
	                 0);
	I_SimpleProperty(osg::Node *, Node, 
	                 __osg_Node_P1__getNode, 
	                 __void__setNode__osg_Node_P1);
	I_SimpleProperty(osgGA::NodeTrackerManipulator::RotationMode, RotationMode, 
	                 __RotationMode__getRotationMode, 
	                 __void__setRotationMode__RotationMode);
	I_SimpleProperty(osg::Node *, TrackNode, 
	                 __osg_Node_P1__getTrackNode, 
	                 __void__setTrackNode__osg_Node_P1);
	I_SimpleProperty(osgGA::NodeTrackerManipulator::ObserverNodePath &, TrackNodePath, 
	                 __ObserverNodePath_R1__getTrackNodePath, 
	                 0);
	I_SimpleProperty(osgGA::NodeTrackerManipulator::TrackerMode, TrackerMode, 
	                 __TrackerMode__getTrackerMode, 
	                 __void__setTrackerMode__TrackerMode);
END_REFLECTOR

