// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/BoundingSphere>
#include <osg/CopyOp>
#include <osg/LOD>
#include <osg/Node>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/Vec3>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::pair< float COMMA  float >, osg::LOD::MinMaxPair);

TYPE_NAME_ALIAS(std::vector< osg::LOD::MinMaxPair >, osg::LOD::RangeList);

BEGIN_ENUM_REFLECTOR(osg::LOD::CenterMode)
	I_EnumLabel(osg::LOD::USE_BOUNDING_SPHERE_CENTER);
	I_EnumLabel(osg::LOD::USER_DEFINED_CENTER);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::LOD::RangeMode)
	I_EnumLabel(osg::LOD::DISTANCE_FROM_EYE_POINT);
	I_EnumLabel(osg::LOD::PIXEL_SIZE_ON_SCREEN);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::LOD)
	I_BaseType(osg::Group);
	I_Constructor0();
	I_ConstructorWithDefaults2(IN, const osg::LOD &, x, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, className);
	I_Method0(const char *, libraryName);
	I_Method1(void, accept, IN, osg::NodeVisitor &, nv);
	I_Method1(void, traverse, IN, osg::NodeVisitor &, nv);
	I_Method1(bool, addChild, IN, osg::Node *, child);
	I_Method3(bool, addChild, IN, osg::Node *, child, IN, float, min, IN, float, max);
	I_Method1(bool, removeChild, IN, osg::Node *, child);
	I_Method1(void, setCenterMode, IN, osg::LOD::CenterMode, mode);
	I_Method0(osg::LOD::CenterMode, getCenterMode);
	I_Method1(void, setCenter, IN, const osg::Vec3 &, center);
	I_Method0(const osg::Vec3 &, getCenter);
	I_Method1(void, setRadius, IN, float, radius);
	I_Method0(float, getRadius);
	I_Method1(void, setRangeMode, IN, osg::LOD::RangeMode, mode);
	I_Method0(osg::LOD::RangeMode, getRangeMode);
	I_Method3(void, setRange, IN, unsigned int, childNo, IN, float, min, IN, float, max);
	I_Method1(float, getMinRange, IN, unsigned int, childNo);
	I_Method1(float, getMaxRange, IN, unsigned int, childNo);
	I_Method0(unsigned int, getNumRanges);
	I_Method1(void, setRangeList, IN, const osg::LOD::RangeList &, rangeList);
	I_Method0(const osg::LOD::RangeList &, getRangeList);
	I_Method0(osg::BoundingSphere, computeBound);
	I_Property(const osg::Vec3 &, Center);
	I_Property(osg::LOD::CenterMode, CenterMode);
	I_Property(float, Radius);
	I_Property(const osg::LOD::RangeList &, RangeList);
	I_Property(osg::LOD::RangeMode, RangeMode);
END_REFLECTOR

STD_PAIR_REFLECTOR(std::pair< float COMMA  float >);

STD_VECTOR_REFLECTOR(std::vector< osg::LOD::MinMaxPair >);

