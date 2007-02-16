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

#include <osg/Geode>
#include <osg/Geometry>
#include <osgUtil/SmoothingVisitor>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgUtil::SmoothingVisitor)
	I_BaseType(osg::NodeVisitor);
	I_Constructor0(____SmoothingVisitor,
	               "default to traversing all children. ",
	               "");
	I_Method1(void, apply, IN, osg::Geode &, geode,
	          Properties::VIRTUAL,
	          __void__apply__osg_Geode_R1,
	          "apply smoothing method to all geode geosets. ",
	          "");
	I_StaticMethod1(void, smooth, IN, osg::Geometry &, geoset,
	                __void__smooth__osg_Geometry_R1_S,
	                "smooth geoset by creating per vertex normals. ",
	                "");
END_REFLECTOR

