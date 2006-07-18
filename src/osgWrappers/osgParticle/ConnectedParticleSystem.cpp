// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/Object>
#include <osg/test/CopyOp>
#include <osg/test/State>
#include <osgParticle/ConnectedParticleSystem>
#include <osgParticle/Particle>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgParticle::ConnectedParticleSystem)
	I_BaseType(osgParticle::ParticleSystem);
	I_Constructor0();
	I_ConstructorWithDefaults2(IN, const osgParticle::ConnectedParticleSystem &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method1(osgParticle::Particle *, createParticle, IN, const osgParticle::Particle *, ptemplate);
	I_Method1(void, reuseParticle, IN, int, i);
	I_Method1(void, drawImplementation, IN, osg::State &, state);
END_REFLECTOR

