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

#include <osg/Group>
#include <osg/LOD>
#include <osg/Node>
#include <osgSim/InsertImpostorsVisitor>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgSim::InsertImpostorsVisitor)
	I_BaseType(osg::NodeVisitor);
	I_Constructor0();
	I_Method1(void, setImpostorThresholdRatio, IN, float, ratio);
	I_Method0(float, getImpostorThresholdRatio);
	I_Method1(void, setMaximumNumberOfNestedImpostors, IN, unsigned int, num);
	I_Method0(unsigned int, getMaximumNumberOfNestedImpostors);
	I_Method0(void, reset);
	I_Method1(void, apply, IN, osg::Node &, node);
	I_Method1(void, apply, IN, osg::Group &, node);
	I_Method1(void, apply, IN, osg::LOD &, node);
	I_Method0(void, insertImpostors);
	I_Property(float, ImpostorThresholdRatio);
	I_Property(unsigned int, MaximumNumberOfNestedImpostors);
END_REFLECTOR

