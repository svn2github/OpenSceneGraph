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

#include <osgDB/fstream>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_VALUE_REFLECTOR(osgDB::fstream)
	I_DeclaringFile("osgDB/fstream");
	I_Constructor0(____fstream,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const char *, filename, , IN, std::ios_base::openmode, mode, std::ios_base::in|std::ios_base::out,
	                           ____fstream__C5_char_P1__std_ios_base_openmode,
	                           "",
	                           "");
	I_MethodWithDefaults2(void, open, IN, const char *, filename, , IN, std::ios_base::openmode, mode, std::ios_base::in|std::ios_base::out,
	                      Properties::NON_VIRTUAL,
	                      __void__open__C5_char_P1__std_ios_base_openmode,
	                      "",
	                      "");
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osgDB::ifstream)
	I_DeclaringFile("osgDB/fstream");
	I_Constructor0(____ifstream,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const char *, filename, , IN, std::ios_base::openmode, mode, std::ios_base::in,
	                           ____ifstream__C5_char_P1__std_ios_base_openmode,
	                           "",
	                           "");
	I_MethodWithDefaults2(void, open, IN, const char *, filename, , IN, std::ios_base::openmode, mode, std::ios_base::in,
	                      Properties::NON_VIRTUAL,
	                      __void__open__C5_char_P1__std_ios_base_openmode,
	                      "",
	                      "");
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osgDB::ofstream)
	I_DeclaringFile("osgDB/fstream");
	I_Constructor0(____ofstream,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const char *, filename, , IN, std::ios_base::openmode, mode, std::ios_base::out,
	                           ____ofstream__C5_char_P1__std_ios_base_openmode,
	                           "",
	                           "");
	I_MethodWithDefaults2(void, open, IN, const char *, filename, , IN, std::ios_base::openmode, mode, std::ios_base::out,
	                      Properties::NON_VIRTUAL,
	                      __void__open__C5_char_P1__std_ios_base_openmode,
	                      "",
	                      "");
END_REFLECTOR

