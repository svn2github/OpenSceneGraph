// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/CopyOp>
#include <osg/Object>
#include <osg/PolygonOffset>
#include <osg/State>
#include <osg/StateAttribute>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osg::PolygonOffset)
	I_BaseType(osg::StateAttribute);
	I_Constructor0();
	I_Constructor2(IN, float, factor, IN, float, units);
	I_ConstructorWithDefaults2(IN, const osg::PolygonOffset &, po, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(osg::StateAttribute::Type, getType);
	I_Method1(int, compare, IN, const osg::StateAttribute &, sa);
	I_Method1(bool, getModeUsage, IN, osg::StateAttribute::ModeUsage &, usage);
	I_Method1(void, setFactor, IN, float, factor);
	I_Method0(float, getFactor);
	I_Method1(void, setUnits, IN, float, units);
	I_Method0(float, getUnits);
	I_Method1(void, apply, IN, osg::State &, state);
	I_Property(float, Factor);
	I_ReadOnlyProperty(osg::StateAttribute::Type, Type);
	I_Property(float, Units);
END_REFLECTOR

