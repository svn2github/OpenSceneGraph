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
#include <osgParticle/Particle>
#include <osgParticle/SectorPlacer>
#include <osgParticle/range>

BEGIN_OBJECT_REFLECTOR(osgParticle::SectorPlacer)
	BaseType(osgParticle::CenteredPlacer);
	Constructor0();
	ConstructorWithDefaults2(IN, const osgParticle::SectorPlacer &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	Method0(const osgParticle::rangef &, getRadiusRange);
	Method1(void, setRadiusRange, IN, const osgParticle::rangef &, r);
	Method2(void, setRadiusRange, IN, float, r1, IN, float, r2);
	Method0(const osgParticle::rangef &, getPhiRange);
	Method1(void, setPhiRange, IN, const osgParticle::rangef &, r);
	Method2(void, setPhiRange, IN, float, r1, IN, float, r2);
	Method0(osg::Object *, cloneType);
	Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	Method0(const char *, libraryName);
	Method0(const char *, className);
	Method1(void, place, IN, osgParticle::Particle *, P);
	Property(const osgParticle::rangef &, PhiRange);
	Property(const osgParticle::rangef &, RadiusRange);
END_REFLECTOR

