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

#include <osgAnimation/Channel>
#include <osgAnimation/Sampler>
#include <osgAnimation/Target>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgAnimation::Channel)
	I_DeclaringFile("osgAnimation/Channel");
	I_BaseType(osg::Referenced);
	I_Constructor0(____Channel,
	               "",
	               "");
	I_Constructor1(IN, const osgAnimation::Channel &, channel,
	               Properties::NON_EXPLICIT,
	               ____Channel__C5_Channel_R1,
	               "",
	               "");
	I_Method0(osgAnimation::Channel *, clone,
	          Properties::PURE_VIRTUAL,
	          __Channel_P1__clone,
	          "",
	          "");
	I_Method1(void, update, IN, float, time,
	          Properties::PURE_VIRTUAL,
	          __void__update__float,
	          "",
	          "");
	I_Method0(void, reset,
	          Properties::PURE_VIRTUAL,
	          __void__reset,
	          "",
	          "");
	I_Method0(osgAnimation::Target *, getTarget,
	          Properties::PURE_VIRTUAL,
	          __Target_P1__getTarget,
	          "",
	          "");
	I_Method0(const std::string &, getName,
	          Properties::NON_VIRTUAL,
	          __C5_std_string_R1__getName,
	          "",
	          "");
	I_Method1(void, setName, IN, const std::string &, name,
	          Properties::NON_VIRTUAL,
	          __void__setName__C5_std_string_R1,
	          "",
	          "");
	I_Method0(float, getStartTime,
	          Properties::PURE_VIRTUAL,
	          __float__getStartTime,
	          "",
	          "");
	I_Method0(float, getEndTime,
	          Properties::PURE_VIRTUAL,
	          __float__getEndTime,
	          "",
	          "");
	I_Method0(const std::string &, getTargetName,
	          Properties::NON_VIRTUAL,
	          __C5_std_string_R1__getTargetName,
	          "",
	          "");
	I_Method1(void, setTargetName, IN, const std::string &, name,
	          Properties::NON_VIRTUAL,
	          __void__setTargetName__C5_std_string_R1,
	          "",
	          "");
	I_Method0(float, getWeight,
	          Properties::NON_VIRTUAL,
	          __float__getWeight,
	          "",
	          "");
	I_Method1(void, setWeight, IN, float, w,
	          Properties::NON_VIRTUAL,
	          __void__setWeight__float,
	          "",
	          "");
	I_Method0(osgAnimation::Sampler *, getSampler,
	          Properties::PURE_VIRTUAL,
	          __Sampler_P1__getSampler,
	          "",
	          "");
	I_Method0(const osgAnimation::Sampler *, getSampler,
	          Properties::PURE_VIRTUAL,
	          __C5_Sampler_P1__getSampler,
	          "",
	          "");
	I_SimpleProperty(float, EndTime, 
	                 __float__getEndTime, 
	                 0);
	I_SimpleProperty(const std::string &, Name, 
	                 __C5_std_string_R1__getName, 
	                 __void__setName__C5_std_string_R1);
	I_SimpleProperty(osgAnimation::Sampler *, Sampler, 
	                 __Sampler_P1__getSampler, 
	                 0);
	I_SimpleProperty(float, StartTime, 
	                 __float__getStartTime, 
	                 0);
	I_SimpleProperty(osgAnimation::Target *, Target, 
	                 __Target_P1__getTarget, 
	                 0);
	I_SimpleProperty(const std::string &, TargetName, 
	                 __C5_std_string_R1__getTargetName, 
	                 __void__setTargetName__C5_std_string_R1);
	I_SimpleProperty(float, Weight, 
	                 __float__getWeight, 
	                 __void__setWeight__float);
END_REFLECTOR

TYPE_NAME_ALIAS(std::vector< osg::ref_ptr< osgAnimation::Channel > >, osgAnimation::ChannelList)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::DoubleLinearSampler >, osgAnimation::DoubleLinearChannel)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::FloatLinearSampler >, osgAnimation::FloatLinearChannel)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::Vec2LinearSampler >, osgAnimation::Vec2LinearChannel)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::Vec3LinearSampler >, osgAnimation::Vec3LinearChannel)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::Vec4LinearSampler >, osgAnimation::Vec4LinearChannel)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::QuatSphericalLinearSampler >, osgAnimation::QuatSphericalLinearChannel)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::FloatCubicBezierSampler >, osgAnimation::FloatCubicBezierChannel)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::DoubleCubicBezierSampler >, osgAnimation::DoubleCubicBezierChannel)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::Vec2CubicBezierSampler >, osgAnimation::Vec2CubicBezierChannel)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::Vec3CubicBezierSampler >, osgAnimation::Vec3CubicBezierChannel)

TYPE_NAME_ALIAS(osgAnimation::TemplateChannel< osgAnimation::Vec4CubicBezierSampler >, osgAnimation::Vec4CubicBezierChannel)

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osgAnimation::Channel >)
	I_DeclaringFile("osg/ref_ptr");
	I_Constructor0(____ref_ptr,
	               "",
	               "");
	I_Constructor1(IN, osgAnimation::Channel *, ptr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osgAnimation::Channel > &, rp,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__C5_ref_ptr_R1,
	               "",
	               "");
	I_Method0(osgAnimation::Channel *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(osgAnimation::Channel *, release,
	          Properties::NON_VIRTUAL,
	          __T_P1__release,
	          "",
	          "");
	I_Method1(void, swap, IN, osg::ref_ptr< osgAnimation::Channel > &, rp,
	          Properties::NON_VIRTUAL,
	          __void__swap__ref_ptr_R1,
	          "",
	          "");
	I_SimpleProperty(osgAnimation::Channel *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::ref_ptr< osgAnimation::Channel > >)

