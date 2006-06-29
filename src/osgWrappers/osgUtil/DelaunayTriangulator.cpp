// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/Array>
#include <osg/CopyOp>
#include <osg/PrimitiveSet>
#include <osg/Vec3>
#include <osgUtil/DelaunayTriangulator>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgUtil::DelaunayConstraint)
	I_BaseType(osg::Geometry);
	I_Constructor0();
	I_Method3(void, addtriangle, IN, const int, i1, IN, const int, i2, IN, const int, i3);
	I_Method0(const osg::DrawElementsUInt *, getTriangles);
	I_Method0(osg::DrawElementsUInt *, getTriangles);
	I_Method1(osg::Vec3Array *, getPoints, IN, const osg::Vec3Array *, points);
	I_Method0(osg::DrawElementsUInt *, makeDrawable);
	I_Method1(void, merge, IN, osgUtil::DelaunayConstraint *, dco);
	I_Method1(void, removeVerticesInside, IN, const osgUtil::DelaunayConstraint *, dco);
	I_Method1(float, windingNumber, IN, const osg::Vec3, testpoint);
	I_Method1(bool, contains, IN, const osg::Vec3, testpoint);
	I_Method1(bool, outside, IN, const osg::Vec3, testpoint);
	I_Method0(void, handleOverlaps);
	I_ReadOnlyProperty(osg::DrawElementsUInt *, Triangles);
END_REFLECTOR

TYPE_NAME_ALIAS(std::vector< osg::ref_ptr< osgUtil::DelaunayConstraint > >, osgUtil::DelaunayTriangulator::linelist);

BEGIN_OBJECT_REFLECTOR(osgUtil::DelaunayTriangulator)
	I_BaseType(osg::Referenced);
	I_Constructor0();
	I_ConstructorWithDefaults2(IN, osg::Vec3Array *, points, , IN, osg::Vec3Array *, normals, 0);
	I_ConstructorWithDefaults2(IN, const osgUtil::DelaunayTriangulator &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(const osg::Vec3Array *, getInputPointArray);
	I_Method0(osg::Vec3Array *, getInputPointArray);
	I_Method1(void, setInputPointArray, IN, osg::Vec3Array *, points);
	I_Method1(void, addInputConstraint, IN, osgUtil::DelaunayConstraint *, dc);
	I_Method0(const osg::Vec3Array *, getOutputNormalArray);
	I_Method0(osg::Vec3Array *, getOutputNormalArray);
	I_Method1(void, setOutputNormalArray, IN, osg::Vec3Array *, normals);
	I_Method0(bool, triangulate);
	I_Method0(const osg::DrawElementsUInt *, getTriangles);
	I_Method0(osg::DrawElementsUInt *, getTriangles);
	I_Method1(void, removeInternalTriangles, IN, osgUtil::DelaunayConstraint *, constraint);
	I_Property(osg::Vec3Array *, InputPointArray);
	I_Property(osg::Vec3Array *, OutputNormalArray);
	I_ReadOnlyProperty(osg::DrawElementsUInt *, Triangles);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osgUtil::DelaunayConstraint >)
	I_Constructor0();
	I_Constructor1(IN, osgUtil::DelaunayConstraint *, ptr);
	I_Constructor1(IN, const osg::ref_ptr< osgUtil::DelaunayConstraint > &, rp);
	I_Method0(osgUtil::DelaunayConstraint *, get);
	I_Method0(bool, valid);
	I_Method0(osgUtil::DelaunayConstraint *, release);
	I_Method1(void, swap, IN, osg::ref_ptr< osgUtil::DelaunayConstraint > &, rp);
	I_ReadOnlyProperty(osgUtil::DelaunayConstraint *, );
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::ref_ptr< osgUtil::DelaunayConstraint > >);

