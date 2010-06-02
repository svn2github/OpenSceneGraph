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

#include <osg/CopyOp>
#include <osg/CullFace>
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

#include <osg/observer_ptr>
        
BEGIN_ENUM_REFLECTOR(osg::CullFace::Mode)
	I_DeclaringFile("osg/CullFace");
	I_EnumLabel(osg::CullFace::FRONT);
	I_EnumLabel(osg::CullFace::BACK);
	I_EnumLabel(osg::CullFace::FRONT_AND_BACK);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::CullFace)
	I_DeclaringFile("osg/CullFace");
	I_BaseType(osg::StateAttribute);
	I_ConstructorWithDefaults1(IN, osg::CullFace::Mode, mode, osg::CullFace::BACK,
	                           Properties::NON_EXPLICIT,
	                           ____CullFace__Mode,
	                           "",
	                           "");
	I_ConstructorWithDefaults2(IN, const osg::CullFace &, cf, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____CullFace__C5_CullFace_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an attribute, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, x,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an attribute, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "Return true if this and obj are of the same kind of object. ",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "Return the name of the attribute's library. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "Return the name of the attribute's class type. ",
	          "");
	I_Method0(osg::StateAttribute::Type, getType,
	          Properties::VIRTUAL,
	          __Type__getType,
	          "Return the Type identifier of the attribute's class type. ",
	          "");
	I_Method1(int, compare, IN, const osg::StateAttribute &, sa,
	          Properties::VIRTUAL,
	          __int__compare__C5_StateAttribute_R1,
	          "return -1 if *this < *rhs, 0 if *this==*rhs, 1 if *this>*rhs. ",
	          "");
	I_Method1(bool, getModeUsage, IN, osg::StateAttribute::ModeUsage &, x,
	          Properties::VIRTUAL,
	          __bool__getModeUsage__StateAttribute_ModeUsage_R1,
	          "Return the modes associated with this StateAttribute. ",
	          "");
	I_Method1(void, setMode, IN, osg::CullFace::Mode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setMode__Mode,
	          "",
	          "");
	I_Method0(osg::CullFace::Mode, getMode,
	          Properties::NON_VIRTUAL,
	          __Mode__getMode,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::State &, x,
	          Properties::VIRTUAL,
	          __void__apply__State_R1,
	          "apply the OpenGL state attributes. ",
	          "The render info for the current OpenGL context is passed in to allow the StateAttribute to obtain details on the the current context and state. ");
	I_SimpleProperty(osg::CullFace::Mode, Mode, 
	                 __Mode__getMode, 
	                 __void__setMode__Mode);
	I_SimpleProperty(osg::StateAttribute::Type, Type, 
	                 __Type__getType, 
	                 0);
END_REFLECTOR

