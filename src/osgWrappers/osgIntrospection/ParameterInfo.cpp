// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osgIntrospection/ParameterInfo>
#include <osgIntrospection/Type>
#include <osgIntrospection/Value>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osgIntrospection::ParameterInfo::ParameterAttributes)
	I_EnumLabel(osgIntrospection::ParameterInfo::NONE);
	I_EnumLabel(osgIntrospection::ParameterInfo::IN);
	I_EnumLabel(osgIntrospection::ParameterInfo::OUT);
	I_EnumLabel(osgIntrospection::ParameterInfo::INOUT);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osgIntrospection::ParameterInfo)
	I_ConstructorWithDefaults4(IN, const std::string &, name, , IN, const osgIntrospection::Type &, type, , IN, int, attribs, , IN, const osgIntrospection::Value &, defval, osgIntrospection::Value());
	I_Method0(const std::string &, getName);
	I_Method0(const osgIntrospection::Type &, getParameterType);
	I_Method0(int, getAttributes);
	I_Method0(const osgIntrospection::Value &, getDefaultValue);
	I_Method0(bool, isIn);
	I_Method0(bool, isOut);
	I_Method0(bool, isInOut);
	I_ReadOnlyProperty(int, Attributes);
	I_ReadOnlyProperty(const osgIntrospection::Value &, DefaultValue);
	I_ReadOnlyProperty(const std::string &, Name);
	I_ReadOnlyProperty(const osgIntrospection::Type &, ParameterType);
END_REFLECTOR

