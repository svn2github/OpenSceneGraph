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
#include <osg/Matrixd>
#include <osg/Object>
#include <osg/Vec3d>
#include <osgVolume/Locator>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgVolume::Locator)
	I_DeclaringFile("osgVolume/Locator");
	I_BaseType(osg::Object);
	I_Constructor0(____Locator,
	               "",
	               "");
	I_Constructor1(IN, const osg::Matrixd &, transform,
	               Properties::NON_EXPLICIT,
	               ____Locator__C5_osg_Matrixd_R1,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgVolume::Locator &, locator, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____Locator__C5_Locator_R1__C5_osg_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, x,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, setTransform, IN, const osg::Matrixd &, transform,
	          Properties::NON_VIRTUAL,
	          __void__setTransform__C5_osg_Matrixd_R1,
	          "Set the transformation from local coordinates to model coordinates. ",
	          "");
	I_Method0(const osg::Matrixd &, getTransform,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Matrixd_R1__getTransform,
	          "Set the transformation from local coordinates to model coordinates. ",
	          "");
	I_Method6(void, setTransformAsExtents, IN, double, minX, IN, double, minY, IN, double, maxX, IN, double, maxY, IN, double, minZ, IN, double, maxZ,
	          Properties::NON_VIRTUAL,
	          __void__setTransformAsExtents__double__double__double__double__double__double,
	          "Set the extents of the local coords. ",
	          "");
	I_Method2(bool, convertLocalToModel, IN, const osg::Vec3d &, x, IN, osg::Vec3d &, x,
	          Properties::VIRTUAL,
	          __bool__convertLocalToModel__C5_osg_Vec3d_R1__osg_Vec3d_R1,
	          "",
	          "");
	I_Method2(bool, convertModelToLocal, IN, const osg::Vec3d &, x, IN, osg::Vec3d &, x,
	          Properties::VIRTUAL,
	          __bool__convertModelToLocal__C5_osg_Vec3d_R1__osg_Vec3d_R1,
	          "",
	          "");
	I_Method2(bool, computeLocalBounds, IN, osg::Vec3d &, bottomLeft, IN, osg::Vec3d &, topRight,
	          Properties::NON_VIRTUAL,
	          __bool__computeLocalBounds__osg_Vec3d_R1__osg_Vec3d_R1,
	          "",
	          "");
	I_Method3(bool, computeLocalBounds, IN, osgVolume::Locator &, source, IN, osg::Vec3d &, bottomLeft, IN, osg::Vec3d &, topRight,
	          Properties::NON_VIRTUAL,
	          __bool__computeLocalBounds__Locator_R1__osg_Vec3d_R1__osg_Vec3d_R1,
	          "",
	          "");
	I_StaticMethod4(bool, convertLocalCoordBetween, IN, const osgVolume::Locator &, source, IN, const osg::Vec3d &, sourceNDC, IN, const osgVolume::Locator &, destination, IN, osg::Vec3d &, destinationNDC,
	                __bool__convertLocalCoordBetween__C5_Locator_R1__C5_osg_Vec3d_R1__C5_Locator_R1__osg_Vec3d_R1_S,
	                "",
	                "");
	I_SimpleProperty(const osg::Matrixd &, Transform, 
	                 __C5_osg_Matrixd_R1__getTransform, 
	                 __void__setTransform__C5_osg_Matrixd_R1);
END_REFLECTOR

