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
#include <osg/Matrixd>
#include <osg/Matrixf>
#include <osg/Object>
#include <osg/Quat>
#include <osg/Vec3d>
#include <osg/Vec3f>
#include <osg/Vec4d>
#include <osg/Vec4f>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(double, osg::Matrixd::value_type);

BEGIN_VALUE_REFLECTOR(osg::Matrixd)
	I_Constructor0();
	I_Constructor1(IN, const osg::Matrixd &, mat);
	I_Constructor1(IN, const osg::Matrixf &, mat);
	I_Constructor1(IN, float const *const, ptr);
	I_Constructor1(IN, double const *const, ptr);
	I_Constructor1(IN, const osg::Quat &, quat);
	I_Constructor16(IN, osg::Matrixd::value_type, a00, IN, osg::Matrixd::value_type, a01, IN, osg::Matrixd::value_type, a02, IN, osg::Matrixd::value_type, a03, IN, osg::Matrixd::value_type, a10, IN, osg::Matrixd::value_type, a11, IN, osg::Matrixd::value_type, a12, IN, osg::Matrixd::value_type, a13, IN, osg::Matrixd::value_type, a20, IN, osg::Matrixd::value_type, a21, IN, osg::Matrixd::value_type, a22, IN, osg::Matrixd::value_type, a23, IN, osg::Matrixd::value_type, a30, IN, osg::Matrixd::value_type, a31, IN, osg::Matrixd::value_type, a32, IN, osg::Matrixd::value_type, a33);
	I_Method1(int, compare, IN, const osg::Matrixd &, m);
	I_Method0(bool, valid);
	I_Method0(bool, isNaN);
	I_Method1(void, set, IN, const osg::Matrixd &, rhs);
	I_Method1(void, set, IN, const osg::Matrixf &, rhs);
	I_Method1(void, set, IN, float const *const, ptr);
	I_Method1(void, set, IN, double const *const, ptr);
	I_Method16(void, set, IN, osg::Matrixd::value_type, a00, IN, osg::Matrixd::value_type, a01, IN, osg::Matrixd::value_type, a02, IN, osg::Matrixd::value_type, a03, IN, osg::Matrixd::value_type, a10, IN, osg::Matrixd::value_type, a11, IN, osg::Matrixd::value_type, a12, IN, osg::Matrixd::value_type, a13, IN, osg::Matrixd::value_type, a20, IN, osg::Matrixd::value_type, a21, IN, osg::Matrixd::value_type, a22, IN, osg::Matrixd::value_type, a23, IN, osg::Matrixd::value_type, a30, IN, osg::Matrixd::value_type, a31, IN, osg::Matrixd::value_type, a32, IN, osg::Matrixd::value_type, a33);
	I_Method0(osg::Matrixd::value_type *, ptr);
	I_Method0(const osg::Matrixd::value_type *, ptr);
	I_Method0(void, makeIdentity);
	I_Method1(void, makeScale, IN, const osg::Vec3f &, x);
	I_Method1(void, makeScale, IN, const osg::Vec3d &, x);
	I_Method3(void, makeScale, IN, osg::Matrixd::value_type, x, IN, osg::Matrixd::value_type, x, IN, osg::Matrixd::value_type, x);
	I_Method1(void, makeTranslate, IN, const osg::Vec3f &, x);
	I_Method1(void, makeTranslate, IN, const osg::Vec3d &, x);
	I_Method3(void, makeTranslate, IN, osg::Matrixd::value_type, x, IN, osg::Matrixd::value_type, x, IN, osg::Matrixd::value_type, x);
	I_Method2(void, makeRotate, IN, const osg::Vec3f &, from, IN, const osg::Vec3f &, to);
	I_Method2(void, makeRotate, IN, const osg::Vec3d &, from, IN, const osg::Vec3d &, to);
	I_Method2(void, makeRotate, IN, osg::Matrixd::value_type, angle, IN, const osg::Vec3f &, axis);
	I_Method2(void, makeRotate, IN, osg::Matrixd::value_type, angle, IN, const osg::Vec3d &, axis);
	I_Method4(void, makeRotate, IN, osg::Matrixd::value_type, angle, IN, osg::Matrixd::value_type, x, IN, osg::Matrixd::value_type, y, IN, osg::Matrixd::value_type, z);
	I_Method1(void, makeRotate, IN, const osg::Quat &, x);
	I_Method6(void, makeRotate, IN, osg::Matrixd::value_type, angle1, IN, const osg::Vec3f &, axis1, IN, osg::Matrixd::value_type, angle2, IN, const osg::Vec3f &, axis2, IN, osg::Matrixd::value_type, angle3, IN, const osg::Vec3f &, axis3);
	I_Method6(void, makeRotate, IN, osg::Matrixd::value_type, angle1, IN, const osg::Vec3d &, axis1, IN, osg::Matrixd::value_type, angle2, IN, const osg::Vec3d &, axis2, IN, osg::Matrixd::value_type, angle3, IN, const osg::Vec3d &, axis3);
	I_Method6(void, makeOrtho, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top, IN, double, zNear, IN, double, zFar);
	I_Method6(bool, getOrtho, IN, double &, left, IN, double &, right, IN, double &, bottom, IN, double &, top, IN, double &, zNear, IN, double &, zFar);
	I_Method4(void, makeOrtho2D, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top);
	I_Method6(void, makeFrustum, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top, IN, double, zNear, IN, double, zFar);
	I_Method6(bool, getFrustum, IN, double &, left, IN, double &, right, IN, double &, bottom, IN, double &, top, IN, double &, zNear, IN, double &, zFar);
	I_Method4(void, makePerspective, IN, double, fovy, IN, double, aspectRatio, IN, double, zNear, IN, double, zFar);
	I_Method4(bool, getPerspective, IN, double &, fovy, IN, double &, aspectRatio, IN, double &, zNear, IN, double &, zFar);
	I_Method3(void, makeLookAt, IN, const osg::Vec3d &, eye, IN, const osg::Vec3d &, center, IN, const osg::Vec3d &, up);
	I_MethodWithDefaults4(void, getLookAt, IN, osg::Vec3f &, eye, , IN, osg::Vec3f &, center, , IN, osg::Vec3f &, up, , IN, osg::Matrixd::value_type, lookDistance, 1.0f);
	I_MethodWithDefaults4(void, getLookAt, IN, osg::Vec3d &, eye, , IN, osg::Vec3d &, center, , IN, osg::Vec3d &, up, , IN, osg::Matrixd::value_type, lookDistance, 1.0f);
	I_Method1(bool, invert, IN, const osg::Matrixd &, rhs);
	I_Method1(bool, invert_4x3, IN, const osg::Matrixd &, rhs);
	I_Method1(bool, invert_4x4, IN, const osg::Matrixd &, rhs);
	I_Method1(void, orthoNormalize, IN, const osg::Matrixd &, rhs);
	I_Method1(osg::Vec3f, preMult, IN, const osg::Vec3f &, v);
	I_Method1(osg::Vec3d, preMult, IN, const osg::Vec3d &, v);
	I_Method1(osg::Vec3f, postMult, IN, const osg::Vec3f &, v);
	I_Method1(osg::Vec3d, postMult, IN, const osg::Vec3d &, v);
	I_Method1(osg::Vec4f, preMult, IN, const osg::Vec4f &, v);
	I_Method1(osg::Vec4d, preMult, IN, const osg::Vec4d &, v);
	I_Method1(osg::Vec4f, postMult, IN, const osg::Vec4f &, v);
	I_Method1(osg::Vec4d, postMult, IN, const osg::Vec4d &, v);
	I_Method1(void, set, IN, const osg::Quat &, q);
	I_Method1(void, get, IN, osg::Quat &, q);
	I_Method1(void, setRotate, IN, const osg::Quat &, q);
	I_Method0(osg::Quat, getRotate);
	I_Method3(void, setTrans, IN, osg::Matrixd::value_type, tx, IN, osg::Matrixd::value_type, ty, IN, osg::Matrixd::value_type, tz);
	I_Method1(void, setTrans, IN, const osg::Vec3f &, v);
	I_Method1(void, setTrans, IN, const osg::Vec3d &, v);
	I_Method0(osg::Vec3d, getTrans);
	I_Method0(osg::Vec3d, getScale);
	I_Method2(void, mult, IN, const osg::Matrixd &, x, IN, const osg::Matrixd &, x);
	I_Method1(void, preMult, IN, const osg::Matrixd &, x);
	I_Method1(void, postMult, IN, const osg::Matrixd &, x);
	I_WriteOnlyProperty(float const *const, );
	I_ReadOnlyProperty(osg::Quat, Rotate);
	I_ReadOnlyProperty(osg::Vec3d, Scale);
	I_ReadOnlyProperty(osg::Vec3d, Trans);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::RefMatrixd)
	I_BaseType(osg::Object);
	I_BaseType(osg::Matrixd);
	I_Constructor0();
	I_Constructor1(IN, const osg::Matrixd &, other);
	I_Constructor1(IN, const osg::Matrixf &, other);
	I_Constructor1(IN, const osg::RefMatrixd &, other);
	I_Constructor1(IN, osg::Matrixd::value_type const *const, def);
	I_Constructor16(IN, osg::Matrixd::value_type, a00, IN, osg::Matrixd::value_type, a01, IN, osg::Matrixd::value_type, a02, IN, osg::Matrixd::value_type, a03, IN, osg::Matrixd::value_type, a10, IN, osg::Matrixd::value_type, a11, IN, osg::Matrixd::value_type, a12, IN, osg::Matrixd::value_type, a13, IN, osg::Matrixd::value_type, a20, IN, osg::Matrixd::value_type, a21, IN, osg::Matrixd::value_type, a22, IN, osg::Matrixd::value_type, a23, IN, osg::Matrixd::value_type, a30, IN, osg::Matrixd::value_type, a31, IN, osg::Matrixd::value_type, a32, IN, osg::Matrixd::value_type, a33);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, x);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
END_REFLECTOR

