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
	I_Constructor0(____ParticleSystem,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgParticle::ParticleSystem &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____ParticleSystem__C5_ParticleSystem_R1__C5_osg_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method0(osgParticle::ParticleSystem::Alignment, getParticleAlignment,
	          __Alignment__getParticleAlignment,
	          "Get the alignment type of particles. ",
	          "");
	I_Method1(void, setParticleAlignment, IN, osgParticle::ParticleSystem::Alignment, a,
	          __void__setParticleAlignment__Alignment,
	          "Set the alignment type of particles. ",
	          "");
	I_Method0(const osg::Vec3 &, getAlignVectorX,
	          __C5_osg_Vec3_R1__getAlignVectorX,
	          "Get the X-axis alignment vector. ",
	          "");
	I_Method1(void, setAlignVectorX, IN, const osg::Vec3 &, v,
	          __void__setAlignVectorX__C5_osg_Vec3_R1,
	          "Set the X-axis alignment vector. ",
	          "");
	I_Method0(const osg::Vec3 &, getAlignVectorY,
	          __C5_osg_Vec3_R1__getAlignVectorY,
	          "Get the Y-axis alignment vector. ",
	          "");
	I_Method1(void, setAlignVectorY, IN, const osg::Vec3 &, v,
	          __void__setAlignVectorY__C5_osg_Vec3_R1,
	          "Set the Y-axis alignment vector. ",
	          "");
	I_Method2(void, setAlignVectors, IN, const osg::Vec3 &, X, IN, const osg::Vec3 &, Y,
	          __void__setAlignVectors__C5_osg_Vec3_R1__C5_osg_Vec3_R1,
	          "Set the alignment vectors. ",
	          "");
	I_Method0(const osg::BoundingBox &, getDefaultBoundingBox,
	          __C5_osg_BoundingBox_R1__getDefaultBoundingBox,
	          "Get the default bounding box. ",
	          "");
	I_Method1(void, setDefaultBoundingBox, IN, const osg::BoundingBox &, bbox,
	          __void__setDefaultBoundingBox__C5_osg_BoundingBox_R1,
	          "Set the default bounding box. ",
	          "The default bounding box is used when a real bounding box cannot be computed, for example because no particles has been updated yet.");
	I_Method0(bool, getDoublePassRendering,
	          __bool__getDoublePassRendering,
	          "Get the double pass rendering flag. ",
	          "");
	I_Method1(void, setDoublePassRendering, IN, bool, v,
	          __void__setDoublePassRendering__bool,
	          "Set the double pass rendering flag. ",
	          "Double pass rendering avoids overdraw problems between particle systems and other opaque objects. If you can render all the particle systems after the opaque objects, then double pass is not necessary and can be turned off (best choice). If you set the default attributes with setDefaultAttributes, then the particle system will fall into a transparent bin.");
	I_Method0(bool, isFrozen,
	          __bool__isFrozen,
	          "Return true if the particle system is frozen. ",
	          "");
	I_Method1(void, setFrozen, IN, bool, v,
	          __void__setFrozen__bool,
	          "Set or reset the frozen state. ",
	          "When the particle system is frozen, emitters and programs won't do anything on it.");
	I_Method0(int, numParticles,
	          __int__numParticles,
	          "Get the number of allocated particles (alive + dead). ",
	          "");
	I_Method0(int, numDeadParticles,
	          __int__numDeadParticles,
	          "Get the number of dead particles. ",
	          "");
	I_Method0(bool, areAllParticlesDead,
	          __bool__areAllParticlesDead,
	          "Get whether all particles are dead. ",
	          "");
	I_Method1(osgParticle::Particle *, getParticle, IN, int, i,
	          __Particle_P1__getParticle__int,
	          "Get a pointer to the i-th particle. ",
	          "");
	I_Method1(const osgParticle::Particle *, getParticle, IN, int, i,
	          __C5_Particle_P1__getParticle__int,
	          "Get a const pointer to the i-th particle. ",
	          "");
	I_Method1(osgParticle::Particle *, createParticle, IN, const osgParticle::Particle *, ptemplate,
	          __Particle_P1__createParticle__C5_Particle_P1,
	          "Create a new particle from the specified template (or the default one if ptemplate is null). ",
	          "");
	I_Method1(void, destroyParticle, IN, int, i,
	          __void__destroyParticle__int,
	          "Destroy the i-th particle. ",
	          "");
	I_Method1(void, reuseParticle, IN, int, i,
	          __void__reuseParticle__int,
	          "Reuse the i-th particle. ",
	          "");
	I_Method0(int, getLastFrameNumber,
	          __int__getLastFrameNumber,
	          "Get the last frame number. ",
	          "");
	I_Method0(osgParticle::Particle &, getDefaultParticleTemplate,
	          __Particle_R1__getDefaultParticleTemplate,
	          "Get a reference to the default particle template. ",
	          "");
	I_Method0(const osgParticle::Particle &, getDefaultParticleTemplate,
	          __C5_Particle_R1__getDefaultParticleTemplate,
	          "Get a const reference to the default particle template. ",
	          "");
	I_Method1(void, setDefaultParticleTemplate, IN, const osgParticle::Particle &, p,
	          __void__setDefaultParticleTemplate__C5_Particle_R1,
	          "Set the default particle template (particle is copied). ",
	          "");
	I_Method0(bool, getFreezeOnCull,
	          __bool__getFreezeOnCull,
	          "Get whether the particle system can freeze when culled. ",
	          "");
	I_Method1(void, setFreezeOnCull, IN, bool, v,
	          __void__setFreezeOnCull__bool,
	          "Set whether the particle system can freeze when culled (default is true). ",
	          "");
	I_MethodWithDefaults4(void, setDefaultAttributes, IN, const std::string &, texturefile, "", IN, bool, emissive_particles, true, IN, bool, lighting, false, IN, int, texture_unit, 0,
	                      __void__setDefaultAttributes__C5_std_string_R1__bool__bool__int,
	                      "A useful method to set the most common StateAttribute's in one call. ",
	                      "If texturefile is empty, then texturing is turned off.");
	I_Method0(int, getLevelOfDetail,
	          __int__getLevelOfDetail,
	          "(EXPERIMENTAL) Get the level of detail. ",
	          "");
	I_Method1(void, setLevelOfDetail, IN, int, v,
	          __void__setLevelOfDetail__int,
	          "(EXPERIMENTAL) Set the level of detail. ",
	          "The total number of particles is divided by the detail value to get the actual number of particles to be drawn. This value must be greater than zero.");
	I_Method1(void, update, IN, double, dt,
	          __void__update__double,
	          "Update the particles. Don't call this directly, use a ParticleSystemUpdater instead. ",
	          "");
	I_Method1(void, drawImplementation, IN, osg::State &, state,
	          __void__drawImplementation__osg_State_R1,
	          "Deprecated. ",
	          "");
	I_Method0(osg::BoundingBox, computeBound,
	          __osg_BoundingBox__computeBound,
	          "Compute the bounding box around Drawables's geometry. ",
	          "");
	I_SimpleProperty(const osg::Vec3 &, AlignVectorX, 
	                 __C5_osg_Vec3_R1__getAlignVectorX, 
	                 __void__setAlignVectorX__C5_osg_Vec3_R1);
	I_SimpleProperty(const osg::Vec3 &, AlignVectorY, 
	                 __C5_osg_Vec3_R1__getAlignVectorY, 
	                 __void__setAlignVectorY__C5_osg_Vec3_R1);
	I_SimpleProperty(const osg::BoundingBox &, DefaultBoundingBox, 
	                 __C5_osg_BoundingBox_R1__getDefaultBoundingBox, 
	                 __void__setDefaultBoundingBox__C5_osg_BoundingBox_R1);
	I_SimpleProperty(const osgParticle::Particle &, DefaultParticleTemplate, 
	                 __C5_Particle_R1__getDefaultParticleTemplate, 
	                 __void__setDefaultParticleTemplate__C5_Particle_R1);
	I_SimpleProperty(bool, DoublePassRendering, 
	                 __bool__getDoublePassRendering, 
	                 __void__setDoublePassRendering__bool);
	I_SimpleProperty(bool, FreezeOnCull, 
	                 __bool__getFreezeOnCull, 
	                 __void__setFreezeOnCull__bool);
	I_SimpleProperty(bool, Frozen, 
	                 0, 
	                 __void__setFrozen__bool);
	I_SimpleProperty(int, LastFrameNumber, 
	                 __int__getLastFrameNumber, 
	                 0);
	I_SimpleProperty(int, LevelOfDetail, 
	                 __int__getLevelOfDetail, 
	                 __void__setLevelOfDetail__int);
	I_SimpleProperty(osgParticle::ParticleSystem::Alignment, ParticleAlignment, 
	                 __Alignment__getParticleAlignment, 
	                 __void__setParticleAlignment__Alignment);
END_REFLECTOR

