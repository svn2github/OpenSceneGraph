// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/BoundingBox>
#include <osg/CopyOp>
#include <osg/Object>
#include <osg/State>
#include <osg/Vec3>
#include <osgParticle/Particle>
#include <osgParticle/ParticleSystem>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osgParticle::ParticleSystem::Alignment)
	I_EnumLabel(osgParticle::ParticleSystem::BILLBOARD);
	I_EnumLabel(osgParticle::ParticleSystem::FIXED);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgParticle::ParticleSystem)
	I_BaseType(osg::Drawable);
	I_Constructor0();
	I_ConstructorWithDefaults2(IN, const osgParticle::ParticleSystem &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(osgParticle::ParticleSystem::Alignment, getParticleAlignment);
	I_Method1(void, setParticleAlignment, IN, osgParticle::ParticleSystem::Alignment, a);
	I_Method0(const osg::Vec3 &, getAlignVectorX);
	I_Method1(void, setAlignVectorX, IN, const osg::Vec3 &, v);
	I_Method0(const osg::Vec3 &, getAlignVectorY);
	I_Method1(void, setAlignVectorY, IN, const osg::Vec3 &, v);
	I_Method2(void, setAlignVectors, IN, const osg::Vec3 &, X, IN, const osg::Vec3 &, Y);
	I_Method0(const osg::BoundingBox &, getDefaultBoundingBox);
	I_Method1(void, setDefaultBoundingBox, IN, const osg::BoundingBox &, bbox);
	I_Method0(bool, getDoublePassRendering);
	I_Method1(void, setDoublePassRendering, IN, bool, v);
	I_Method0(bool, isFrozen);
	I_Method1(void, setFrozen, IN, bool, v);
	I_Method0(int, numParticles);
	I_Method0(int, numDeadParticles);
	I_Method0(bool, areAllParticlesDead);
	I_Method1(osgParticle::Particle *, getParticle, IN, int, i);
	I_Method1(const osgParticle::Particle *, getParticle, IN, int, i);
	I_Method1(osgParticle::Particle *, createParticle, IN, const osgParticle::Particle *, ptemplate);
	I_Method1(void, destroyParticle, IN, int, i);
	I_Method1(void, reuseParticle, IN, int, i);
	I_Method0(int, getLastFrameNumber);
	I_Method0(osgParticle::Particle &, getDefaultParticleTemplate);
	I_Method0(const osgParticle::Particle &, getDefaultParticleTemplate);
	I_Method1(void, setDefaultParticleTemplate, IN, const osgParticle::Particle &, p);
	I_Method0(bool, getFreezeOnCull);
	I_Method1(void, setFreezeOnCull, IN, bool, v);
	I_MethodWithDefaults4(void, setDefaultAttributes, IN, const std::string &, texturefile, "", IN, bool, emissive_particles, true, IN, bool, lighting, false, IN, int, texture_unit, 0);
	I_Method0(int, getLevelOfDetail);
	I_Method1(void, setLevelOfDetail, IN, int, v);
	I_Method1(void, update, IN, double, dt);
	I_Method1(void, drawImplementation, IN, osg::State &, state);
	I_Method0(osg::BoundingBox, computeBound);
	I_Property(const osg::Vec3 &, AlignVectorX);
	I_Property(const osg::Vec3 &, AlignVectorY);
	I_Property(const osg::BoundingBox &, DefaultBoundingBox);
	I_Property(const osgParticle::Particle &, DefaultParticleTemplate);
	I_Property(bool, DoublePassRendering);
	I_Property(bool, FreezeOnCull);
	I_WriteOnlyProperty(bool, Frozen);
	I_ReadOnlyProperty(int, LastFrameNumber);
	I_Property(int, LevelOfDetail);
	I_Property(osgParticle::ParticleSystem::Alignment, ParticleAlignment);
END_REFLECTOR

