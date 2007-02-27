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

#include <osg/Node>
#include <osg/Vec4>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>
#include <osgManipulator/Dragger>
#include <osgManipulator/Scale1DDragger>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osgManipulator::Scale1DDragger::ScaleMode)
	I_EnumLabel(osgManipulator::Scale1DDragger::SCALE_WITH_ORIGIN_AS_PIVOT);
	I_EnumLabel(osgManipulator::Scale1DDragger::SCALE_WITH_OPPOSITE_HANDLE_AS_PIVOT);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgManipulator::Scale1DDragger)
	I_BaseType(osgManipulator::Dragger);
	I_ConstructorWithDefaults1(IN, osgManipulator::Scale1DDragger::ScaleMode, scaleMode, osgManipulator::Scale1DDragger::SCALE_WITH_ORIGIN_AS_PIVOT,
	                           Properties::NON_EXPLICIT,
	                           ____Scale1DDragger__ScaleMode,
	                           "",
	                           "");
	I_Method3(bool, handle, IN, const osgManipulator::PointerInfo &, pi, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          Properties::VIRTUAL,
	          __bool__handle__C5_PointerInfo_R1__C5_osgGA_GUIEventAdapter_R1__osgGA_GUIActionAdapter_R1,
	          "Handle pick events on dragger and generate TranslateInLine commands. ",
	          "");
	I_Method0(void, setupDefaultGeometry,
	          Properties::NON_VIRTUAL,
	          __void__setupDefaultGeometry,
	          "Setup default geometry for dragger. ",
	          "");
	I_Method1(void, setMinScale, IN, float, min,
	          Properties::NON_VIRTUAL,
	          __void__setMinScale__float,
	          "Set/Get min scale for dragger. ",
	          "");
	I_Method0(float, getMinScale,
	          Properties::NON_VIRTUAL,
	          __float__getMinScale,
	          "",
	          "");
	I_Method1(void, setColor, IN, const osg::Vec4 &, color,
	          Properties::NON_VIRTUAL,
	          __void__setColor__C5_osg_Vec4_R1,
	          "Set/Get color for dragger. ",
	          "");
	I_Method0(const osg::Vec4, getColor,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4__getColor,
	          "",
	          "");
	I_Method1(void, setPickColor, IN, const osg::Vec4 &, color,
	          Properties::NON_VIRTUAL,
	          __void__setPickColor__C5_osg_Vec4_R1,
	          "Set/Get pick color for dragger. ",
	          "Pick color is color of the dragger when picked. It gives a visual feedback to show that the dragger has been picked.");
	I_Method0(const osg::Vec4, getPickColor,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4__getPickColor,
	          "",
	          "");
	I_Method1(void, setLeftHandleNode, IN, osg::Node &, node,
	          Properties::NON_VIRTUAL,
	          __void__setLeftHandleNode__osg_Node_R1,
	          "Set/Get left and right handle nodes for dragger. ",
	          "");
	I_Method1(void, setRightHandleNode, IN, osg::Node &, node,
	          Properties::NON_VIRTUAL,
	          __void__setRightHandleNode__osg_Node_R1,
	          "",
	          "");
	I_Method0(osg::Node *, getLeftHandleNode,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__getLeftHandleNode,
	          "",
	          "");
	I_Method0(osg::Node *, getRightHandleNode,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__getRightHandleNode,
	          "",
	          "");
	I_Method1(void, setLeftHandlePosition, IN, float, pos,
	          Properties::NON_VIRTUAL,
	          __void__setLeftHandlePosition__float,
	          "Set left/right handle position. ",
	          "");
	I_Method0(float, getLeftHandlePosition,
	          Properties::NON_VIRTUAL,
	          __float__getLeftHandlePosition,
	          "",
	          "");
	I_Method1(void, setRightHandlePosition, IN, float, pos,
	          Properties::NON_VIRTUAL,
	          __void__setRightHandlePosition__float,
	          "",
	          "");
	I_Method0(float, getRightHandlePosition,
	          Properties::NON_VIRTUAL,
	          __float__getRightHandlePosition,
	          "",
	          "");
	I_SimpleProperty(const osg::Vec4 &, Color, 
	                 0, 
	                 __void__setColor__C5_osg_Vec4_R1);
	I_SimpleProperty(osg::Node &, LeftHandleNode, 
	                 0, 
	                 __void__setLeftHandleNode__osg_Node_R1);
	I_SimpleProperty(float, LeftHandlePosition, 
	                 __float__getLeftHandlePosition, 
	                 __void__setLeftHandlePosition__float);
	I_SimpleProperty(float, MinScale, 
	                 __float__getMinScale, 
	                 __void__setMinScale__float);
	I_SimpleProperty(const osg::Vec4 &, PickColor, 
	                 0, 
	                 __void__setPickColor__C5_osg_Vec4_R1);
	I_SimpleProperty(osg::Node &, RightHandleNode, 
	                 0, 
	                 __void__setRightHandleNode__osg_Node_R1);
	I_SimpleProperty(float, RightHandlePosition, 
	                 __float__getRightHandlePosition, 
	                 __void__setRightHandlePosition__float);
END_REFLECTOR

