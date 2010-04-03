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
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/State>
#include <osgTerrain/TerrainTechnique>
#include <osgTerrain/TerrainTile>
#include <osgUtil/CullVisitor>
#include <osgUtil/UpdateVisitor>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgTerrain::TerrainTechnique)
	I_DeclaringFile("osgTerrain/TerrainTechnique");
	I_BaseType(osg::Object);
	I_BaseType(osg::Observer);
	I_Constructor0(____TerrainTechnique,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgTerrain::TerrainTechnique &, x, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____TerrainTechnique__C5_TerrainTechnique_R1__C5_osg_CopyOp_R1,
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
	I_Method0(osgTerrain::TerrainTile *, getTerrainTile,
	          Properties::NON_VIRTUAL,
	          __TerrainTile_P1__getTerrainTile,
	          "",
	          "");
	I_Method0(const osgTerrain::TerrainTile *, getTerrainTile,
	          Properties::NON_VIRTUAL,
	          __C5_TerrainTile_P1__getTerrainTile,
	          "",
	          "");
	I_Method2(void, init, IN, int, dirtyMask, IN, bool, assumeMultiThreaded,
	          Properties::VIRTUAL,
	          __void__init__int__bool,
	          "",
	          "");
	I_Method1(void, update, IN, osgUtil::UpdateVisitor *, nv,
	          Properties::VIRTUAL,
	          __void__update__osgUtil_UpdateVisitor_P1,
	          "",
	          "");
	I_Method1(void, cull, IN, osgUtil::CullVisitor *, nv,
	          Properties::VIRTUAL,
	          __void__cull__osgUtil_CullVisitor_P1,
	          "",
	          "");
	I_Method0(void, cleanSceneGraph,
	          Properties::VIRTUAL,
	          __void__cleanSceneGraph,
	          "Clean scene graph from any terrain technique specific nodes. ",
	          "");
	I_Method1(void, traverse, IN, osg::NodeVisitor &, nv,
	          Properties::VIRTUAL,
	          __void__traverse__osg_NodeVisitor_R1,
	          "Traverse the terrain subgraph. ",
	          "");
	I_MethodWithDefaults1(void, releaseGLObjects, IN, osg::State *, x, 0,
	                      Properties::VIRTUAL,
	                      __void__releaseGLObjects__osg_State_P1,
	                      "If State is non-zero, this function releases any associated OpenGL objects for the specified graphics context. ",
	                      "Otherwise, releases OpenGL objects for all graphics contexts. ");
	I_Method1(void, addNeighbour, IN, osgTerrain::TerrainTile *, tile,
	          Properties::NON_VIRTUAL,
	          __void__addNeighbour__TerrainTile_P1,
	          "",
	          "");
	I_Method1(void, removeNeighbour, IN, osgTerrain::TerrainTile *, tile,
	          Properties::NON_VIRTUAL,
	          __void__removeNeighbour__TerrainTile_P1,
	          "",
	          "");
	I_Method1(bool, containsNeighbour, IN, osgTerrain::TerrainTile *, tile,
	          Properties::NON_VIRTUAL,
	          __bool__containsNeighbour__TerrainTile_P1,
	          "",
	          "");
	I_ProtectedMethod1(void, setTerrainTile, IN, osgTerrain::TerrainTile *, tile,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__setTerrainTile__TerrainTile_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, setDirty, IN, bool, dirty,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__setDirty__bool,
	                   "",
	                   "");
	I_SimpleProperty(osgTerrain::TerrainTile *, TerrainTile, 
	                 __TerrainTile_P1__getTerrainTile, 
	                 0);
END_REFLECTOR

