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

#include <osg/Plane>
#include <osg/Vec4>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>
#include <osgManipulator/Dragger>
#include <osgManipulator/Translate2DDragger>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgManipulator::Translate2DDragger)
	I_BaseType(osgManipulator::Dragger);
	I_Constructor0(____Translate2DDragger,
	               "",
	               "");
	I_Constructor1(IN, const osg::Plane &, plane,
	               ____Translate2DDragger__C5_osg_Plane_R1,
	               "",
	               "");
	I_Method3(bool, handle, IN, const osgManipulator::Dragger::PointerInfo &, pi, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          __bool__handle__C5_PointerInfo_R1__C5_osgGA_GUIEventAdapter_R1__osgGA_GUIActionAdapter_R1,
	          "Handle pick events on dragger and generate TranslateInLine commands. ",
	          "");
	I_Method0(void, setupDefaultGeometry,
	          __void__setupDefaultGeometry,
	          "Setup default geometry for dragger. ",
	          "");
	I_Method1(void, setColor, IN, const osg::Vec4 &, color,
	          __void__setColor__C5_osg_Vec4_R1,
	          "Set/Get color for dragger. ",
	          "");
	I_Method0(const osg::Vec4, getColor,
	          __C5_osg_Vec4__getColor,
	          "",
	          "");
	I_Method1(void, setPickColor, IN, const osg::Vec4 &, color,
	          __void__setPickColor__C5_osg_Vec4_R1,
	          "Set/Get pick color for dragger. ",
	          "Pick color is color of the dragger when picked. It gives a visual feedback to show that the dragger has been picked. ");
	I_Method0(const osg::Vec4, getPickColor,
	          __C5_osg_Vec4__getPickColor,
	          "",
	          "");
	I_SimpleProperty(const osg::Vec4 &, Color, 
	                 0, 
	                 __void__setColor__C5_osg_Vec4_R1);
	I_SimpleProperty(const osg::Vec4 &, PickColor, 
	                 0, 
	                 __void__setPickColor__C5_osg_Vec4_R1);
END_REFLECTOR

