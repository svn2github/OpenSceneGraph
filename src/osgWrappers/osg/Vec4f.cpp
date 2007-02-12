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

#include <osg/Vec3f>
#include <osg/Vec4f>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

#include <osg/io_utils>
	
TYPE_NAME_ALIAS(float, osg::Vec4f::value_type);

BEGIN_VALUE_REFLECTOR(osg::Vec4f)
	I_ReaderWriter(osgIntrospection::StdReaderWriter<reflected_type>);	// user-defined
	I_Comparator(osgIntrospection::PartialOrderComparator<reflected_type>);	// user-defined
	I_Constructor0(____Vec4f,
	               "",
	               "");
	I_Constructor4(IN, osg::Vec4f::value_type, x, IN, osg::Vec4f::value_type, y, IN, osg::Vec4f::value_type, z, IN, osg::Vec4f::value_type, w,
	               ____Vec4f__value_type__value_type__value_type__value_type,
	               "",
	               "");
	I_Constructor2(IN, const osg::Vec3f &, v3, IN, osg::Vec4f::value_type, w,
	               ____Vec4f__C5_Vec3f_R1__value_type,
	               "",
	               "");
	I_Method0(osg::Vec4f::value_type *, ptr,
	          Properties::NON_VIRTUAL,
	          __value_type_P1__ptr,
	          "",
	          "");
	I_Method0(const osg::Vec4f::value_type *, ptr,
	          Properties::NON_VIRTUAL,
	          __C5_value_type_P1__ptr,
	          "",
	          "");
	I_Method4(void, set, IN, osg::Vec4f::value_type, x, IN, osg::Vec4f::value_type, y, IN, osg::Vec4f::value_type, z, IN, osg::Vec4f::value_type, w,
	          Properties::NON_VIRTUAL,
	          __void__set__value_type__value_type__value_type__value_type,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type &, x,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__x,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type &, y,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__y,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type &, z,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__z,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type &, w,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__w,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type, x,
	          Properties::NON_VIRTUAL,
	          __value_type__x,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type, y,
	          Properties::NON_VIRTUAL,
	          __value_type__y,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type, z,
	          Properties::NON_VIRTUAL,
	          __value_type__z,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type, w,
	          Properties::NON_VIRTUAL,
	          __value_type__w,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type &, r,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__r,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type &, g,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__g,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type &, b,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__b,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type &, a,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__a,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type, r,
	          Properties::NON_VIRTUAL,
	          __value_type__r,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type, g,
	          Properties::NON_VIRTUAL,
	          __value_type__g,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type, b,
	          Properties::NON_VIRTUAL,
	          __value_type__b,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type, a,
	          Properties::NON_VIRTUAL,
	          __value_type__a,
	          "",
	          "");
	I_Method0(unsigned int, asABGR,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__asABGR,
	          "",
	          "");
	I_Method0(unsigned int, asRGBA,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__asRGBA,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(bool, isNaN,
	          Properties::NON_VIRTUAL,
	          __bool__isNaN,
	          "",
	          "");
	I_Method0(osg::Vec4f::value_type, length,
	          Properties::NON_VIRTUAL,
	          __value_type__length,
	          "Length of the vector = sqrt( vec . ",
	          "vec ) ");
	I_Method0(osg::Vec4f::value_type, length2,
	          Properties::NON_VIRTUAL,
	          __value_type__length2,
	          "Length squared of the vector = vec . ",
	          "vec ");
	I_Method0(osg::Vec4f::value_type, normalize,
	          Properties::NON_VIRTUAL,
	          __value_type__normalize,
	          "Normalize the vector so that it has length unity. ",
	          "Returns the previous length of the vector.");
END_REFLECTOR

