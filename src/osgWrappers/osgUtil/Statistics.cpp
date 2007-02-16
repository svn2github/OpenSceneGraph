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

#include <osg/Drawable>
#include <osg/Geode>
#include <osg/Group>
#include <osg/LOD>
#include <osg/Node>
#include <osg/Switch>
#include <osg/Transform>
#include <osg/Vec2>
#include <osg/Vec3>
#include <osg/Vec4>
#include <osgUtil/Statistics>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::pair< unsigned int COMMA  unsigned int >, osgUtil::Statistics::PrimitivePair);

TYPE_NAME_ALIAS(std::map< GLenum COMMA  osgUtil::Statistics::PrimitivePair >, osgUtil::Statistics::PrimitiveValueMap);

TYPE_NAME_ALIAS(std::map< GLenum COMMA  unsigned int >, osgUtil::Statistics::PrimitiveCountMap);

BEGIN_ENUM_REFLECTOR(osgUtil::Statistics::StatsType)
	I_EnumLabel(osgUtil::Statistics::STAT_NONE);
	I_EnumLabel(osgUtil::Statistics::STAT_FRAMERATE);
	I_EnumLabel(osgUtil::Statistics::STAT_GRAPHS);
	I_EnumLabel(osgUtil::Statistics::STAT_PRIMS);
	I_EnumLabel(osgUtil::Statistics::STAT_PRIMSPERVIEW);
	I_EnumLabel(osgUtil::Statistics::STAT_PRIMSPERBIN);
	I_EnumLabel(osgUtil::Statistics::STAT_DC);
	I_EnumLabel(osgUtil::Statistics::STAT_RESTART);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::Statistics)
	I_BaseType(osg::PrimitiveFunctor);
	I_Constructor0(____Statistics,
	               "",
	               "");
	I_Method0(void, reset,
	          Properties::NON_VIRTUAL,
	          __void__reset,
	          "",
	          "");
	I_Method1(void, setType, IN, osgUtil::Statistics::StatsType, t,
	          Properties::NON_VIRTUAL,
	          __void__setType__StatsType,
	          "",
	          "");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec3 *, x,
	          Properties::VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_osg_Vec3_P1,
	          "Sets the array of vertices used to describe the primitives. ",
	          "Somehow mimics the OpenGL glVertexPointer() function.");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec2 *, x,
	          Properties::VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_osg_Vec2_P1,
	          "Sets the array of vertices used to describe the primitives. ",
	          "Somehow mimics the OpenGL glVertexPointer() function.");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec4 *, x,
	          Properties::VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_osg_Vec4_P1,
	          "Sets the array of vertices used to describe the primitives. ",
	          "Somehow mimics the OpenGL glVertexPointer() function.");
	I_Method3(void, drawArrays, IN, GLenum, mode, IN, GLint, x, IN, GLsizei, count,
	          Properties::VIRTUAL,
	          __void__drawArrays__GLenum__GLint__GLsizei,
	          "Mimics the OpenGL glDrawArrays() function. ",
	          "");
	I_Method3(void, drawElements, IN, GLenum, mode, IN, GLsizei, count, IN, const GLubyte *, x,
	          Properties::VIRTUAL,
	          __void__drawElements__GLenum__GLsizei__C5_GLubyte_P1,
	          "Mimics the OpenGL glDrawElements() function. ",
	          "");
	I_Method3(void, drawElements, IN, GLenum, mode, IN, GLsizei, count, IN, const GLushort *, x,
	          Properties::VIRTUAL,
	          __void__drawElements__GLenum__GLsizei__C5_GLushort_P1,
	          "Mimics the OpenGL glDrawElements() function. ",
	          "");
	I_Method3(void, drawElements, IN, GLenum, mode, IN, GLsizei, count, IN, const GLuint *, x,
	          Properties::VIRTUAL,
	          __void__drawElements__GLenum__GLsizei__C5_GLuint_P1,
	          "Mimics the OpenGL glDrawElements() function. ",
	          "");
	I_Method1(void, begin, IN, GLenum, mode,
	          Properties::VIRTUAL,
	          __void__begin__GLenum,
	          "Mimics the OpenGL glBegin() function. ",
	          "");
	I_Method0(void, vertex,
	          Properties::NON_VIRTUAL,
	          __void__vertex,
	          "",
	          "");
	I_Method3(void, vertex, IN, float, x, IN, float, x, IN, float, x,
	          Properties::VIRTUAL,
	          __void__vertex__float__float__float,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method1(void, vertex, IN, const osg::Vec3 &, x,
	          Properties::VIRTUAL,
	          __void__vertex__C5_osg_Vec3_R1,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method1(void, vertex, IN, const osg::Vec2 &, x,
	          Properties::VIRTUAL,
	          __void__vertex__C5_osg_Vec2_R1,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method1(void, vertex, IN, const osg::Vec4 &, x,
	          Properties::VIRTUAL,
	          __void__vertex__C5_osg_Vec4_R1,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method2(void, vertex, IN, float, x, IN, float, x,
	          Properties::VIRTUAL,
	          __void__vertex__float__float,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method4(void, vertex, IN, float, x, IN, float, x, IN, float, x, IN, float, x,
	          Properties::VIRTUAL,
	          __void__vertex__float__float__float__float,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method0(void, end,
	          Properties::VIRTUAL,
	          __void__end,
	          "Mimics the OpenGL glEnd() function. ",
	          "");
	I_Method0(void, addDrawable,
	          Properties::NON_VIRTUAL,
	          __void__addDrawable,
	          "",
	          "");
	I_Method0(void, addMatrix,
	          Properties::NON_VIRTUAL,
	          __void__addMatrix,
	          "",
	          "");
	I_Method1(void, addLight, IN, int, np,
	          Properties::NON_VIRTUAL,
	          __void__addLight__int,
	          "",
	          "");
	I_Method1(void, addImpostor, IN, int, np,
	          Properties::NON_VIRTUAL,
	          __void__addImpostor__int,
	          "",
	          "");
	I_Method0(int, getBins,
	          Properties::NON_VIRTUAL,
	          __int__getBins,
	          "",
	          "");
	I_Method1(void, setDepth, IN, int, d,
	          Properties::NON_VIRTUAL,
	          __void__setDepth__int,
	          "",
	          "");
	I_Method1(void, addBins, IN, int, np,
	          Properties::NON_VIRTUAL,
	          __void__addBins__int,
	          "",
	          "");
	I_Method1(void, setBinNo, IN, int, n,
	          Properties::NON_VIRTUAL,
	          __void__setBinNo__int,
	          "",
	          "");
	I_Method1(void, add, IN, const osgUtil::Statistics &, stats,
	          Properties::NON_VIRTUAL,
	          __void__add__C5_Statistics_R1,
	          "",
	          "");
	I_Method0(osgUtil::Statistics::PrimitiveCountMap::iterator, GetPrimitivesBegin,
	          Properties::NON_VIRTUAL,
	          __PrimitiveCountMap_iterator__GetPrimitivesBegin,
	          "",
	          "");
	I_Method0(osgUtil::Statistics::PrimitiveCountMap::iterator, GetPrimitivesEnd,
	          Properties::NON_VIRTUAL,
	          __PrimitiveCountMap_iterator__GetPrimitivesEnd,
	          "",
	          "");
	I_SimpleProperty(int, BinNo, 
	                 0, 
	                 __void__setBinNo__int);
	I_SimpleProperty(int, Bins, 
	                 __int__getBins, 
	                 0);
	I_SimpleProperty(int, Depth, 
	                 0, 
	                 __void__setDepth__int);
	I_SimpleProperty(osgUtil::Statistics::StatsType, Type, 
	                 0, 
	                 __void__setType__StatsType);
	I_PublicMemberProperty(int, numDrawables);
	I_PublicMemberProperty(int, nummat);
	I_PublicMemberProperty(int, nbins);
	I_PublicMemberProperty(int, nlights);
	I_PublicMemberProperty(int, depth);
	I_PublicMemberProperty(int, _binNo);
	I_PublicMemberProperty(osgUtil::Statistics::StatsType, stattype);
	I_PublicMemberProperty(int, nimpostor);
	I_PublicMemberProperty(unsigned int, _vertexCount);
	I_PublicMemberProperty(osgUtil::Statistics::PrimitiveValueMap, _primitiveCount);
	I_PublicMemberProperty(GLenum, _currentPrimitiveFunctorMode);
END_REFLECTOR

TYPE_NAME_ALIAS(std::set< osg::Node * >, osgUtil::StatsVisitor::NodeSet);

TYPE_NAME_ALIAS(std::set< osg::Drawable * >, osgUtil::StatsVisitor::DrawableSet);

TYPE_NAME_ALIAS(std::set< osg::StateSet * >, osgUtil::StatsVisitor::StateSetSet);

BEGIN_OBJECT_REFLECTOR(osgUtil::StatsVisitor)
	I_BaseType(osg::NodeVisitor);
	I_Constructor0(____StatsVisitor,
	               "",
	               "");
	I_Method0(void, reset,
	          Properties::VIRTUAL,
	          __void__reset,
	          "Method to call to reset visitor. ",
	          "Useful if your visitor accumulates state during a traversal, and you plan to reuse the visitor. To flush that state for the next traversal: call reset() prior to each traversal. ");
	I_Method1(void, apply, IN, osg::Node &, node,
	          Properties::VIRTUAL,
	          __void__apply__osg_Node_R1,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::Group &, node,
	          Properties::VIRTUAL,
	          __void__apply__osg_Group_R1,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::Transform &, node,
	          Properties::VIRTUAL,
	          __void__apply__osg_Transform_R1,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::LOD &, node,
	          Properties::VIRTUAL,
	          __void__apply__osg_LOD_R1,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::Switch &, node,
	          Properties::VIRTUAL,
	          __void__apply__osg_Switch_R1,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::Geode &, node,
	          Properties::VIRTUAL,
	          __void__apply__osg_Geode_R1,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::Drawable &, drawable,
	          Properties::NON_VIRTUAL,
	          __void__apply__osg_Drawable_R1,
	          "",
	          "");
	I_Method0(void, totalUpStats,
	          Properties::NON_VIRTUAL,
	          __void__totalUpStats,
	          "",
	          "");
	I_Method1(void, print, IN, std::ostream &, out,
	          Properties::NON_VIRTUAL,
	          __void__print__std_ostream_R1,
	          "",
	          "");
	I_PublicMemberProperty(unsigned int, _numInstancedGroup);
	I_PublicMemberProperty(unsigned int, _numInstancedSwitch);
	I_PublicMemberProperty(unsigned int, _numInstancedLOD);
	I_PublicMemberProperty(unsigned int, _numInstancedTransform);
	I_PublicMemberProperty(unsigned int, _numInstancedGeode);
	I_PublicMemberProperty(unsigned int, _numInstancedDrawable);
	I_PublicMemberProperty(unsigned int, _numInstancedGeometry);
	I_PublicMemberProperty(unsigned int, _numInstancedStateSet);
	I_PublicMemberProperty(osgUtil::StatsVisitor::NodeSet, _groupSet);
	I_PublicMemberProperty(osgUtil::StatsVisitor::NodeSet, _transformSet);
	I_PublicMemberProperty(osgUtil::StatsVisitor::NodeSet, _lodSet);
	I_PublicMemberProperty(osgUtil::StatsVisitor::NodeSet, _switchSet);
	I_PublicMemberProperty(osgUtil::StatsVisitor::NodeSet, _geodeSet);
	I_PublicMemberProperty(osgUtil::StatsVisitor::DrawableSet, _drawableSet);
	I_PublicMemberProperty(osgUtil::StatsVisitor::DrawableSet, _geometrySet);
	I_PublicMemberProperty(osgUtil::StatsVisitor::StateSetSet, _statesetSet);
	I_PublicMemberProperty(osgUtil::Statistics, _uniqueStats);
	I_PublicMemberProperty(osgUtil::Statistics, _instancedStats);
END_REFLECTOR

STD_MAP_REFLECTOR(std::map< GLenum COMMA  osgUtil::Statistics::PrimitivePair >);

STD_MAP_REFLECTOR(std::map< GLenum COMMA  unsigned int >);

STD_PAIR_REFLECTOR(std::pair< unsigned int COMMA  unsigned int >);

STD_SET_REFLECTOR(std::set< osg::Drawable * >);

STD_SET_REFLECTOR(std::set< osg::StateSet * >);

