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

#include <osg/Node>
#include <osg/Vec3d>
#include <osgSim/LineOfSight>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

#include <osg/observer_ptr>
        
BEGIN_OBJECT_REFLECTOR(osgSim::DatabaseCacheReadCallback)
	I_DeclaringFile("osgSim/LineOfSight");
	I_BaseType(osgUtil::IntersectionVisitor::ReadCallback);
	I_Constructor0(____DatabaseCacheReadCallback,
	               "",
	               "");
	I_Method1(void, setMaximumNumOfFilesToCache, IN, unsigned int, maxNumFilesToCache,
	          Properties::NON_VIRTUAL,
	          __void__setMaximumNumOfFilesToCache__unsigned_int,
	          "",
	          "");
	I_Method0(unsigned int, getMaximumNumOfFilesToCache,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getMaximumNumOfFilesToCache,
	          "",
	          "");
	I_Method0(void, clearDatabaseCache,
	          Properties::NON_VIRTUAL,
	          __void__clearDatabaseCache,
	          "",
	          "");
	I_Method0(void, pruneUnusedDatabaseCache,
	          Properties::NON_VIRTUAL,
	          __void__pruneUnusedDatabaseCache,
	          "",
	          "");
	I_Method1(osg::Node *, readNodeFile, IN, const std::string &, filename,
	          Properties::VIRTUAL,
	          __osg_Node_P1__readNodeFile__C5_std_string_R1,
	          "",
	          "");
	I_SimpleProperty(unsigned int, MaximumNumOfFilesToCache, 
	                 __unsigned_int__getMaximumNumOfFilesToCache, 
	                 __void__setMaximumNumOfFilesToCache__unsigned_int);
END_REFLECTOR

TYPE_NAME_ALIAS(std::vector< osg::Vec3d >, osgSim::LineOfSight::Intersections)

BEGIN_VALUE_REFLECTOR(osgSim::LineOfSight)
	I_DeclaringFile("osgSim/LineOfSight");
	I_Constructor0(____LineOfSight,
	               "",
	               "");
	I_Method0(void, clear,
	          Properties::NON_VIRTUAL,
	          __void__clear,
	          "Clear the internal LOS List so it contains no line of sight tests. ",
	          "");
	I_Method2(unsigned int, addLOS, IN, const osg::Vec3d &, start, IN, const osg::Vec3d &, end,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__addLOS__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1,
	          "Add a line of sight test, consisting of start and end point. ",
	          "Returns the index number of the newly adding LOS test. ");
	I_Method0(unsigned int, getNumLOS,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumLOS,
	          "Get the number of line of sight tests. ",
	          "");
	I_Method2(void, setStartPoint, IN, unsigned int, i, IN, const osg::Vec3d &, start,
	          Properties::NON_VIRTUAL,
	          __void__setStartPoint__unsigned_int__C5_osg_Vec3d_R1,
	          "Set the start point of single line of sight test. ",
	          "");
	I_Method1(const osg::Vec3d &, getStartPoint, IN, unsigned int, i,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec3d_R1__getStartPoint__unsigned_int,
	          "Get the start point of single line of sight test. ",
	          "");
	I_Method2(void, setEndPoint, IN, unsigned int, i, IN, const osg::Vec3d &, end,
	          Properties::NON_VIRTUAL,
	          __void__setEndPoint__unsigned_int__C5_osg_Vec3d_R1,
	          "Set the end point of single line of sight test. ",
	          "");
	I_Method1(const osg::Vec3d &, getEndPoint, IN, unsigned int, i,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec3d_R1__getEndPoint__unsigned_int,
	          "Get the end point of single line of sight test. ",
	          "");
	I_Method1(const osgSim::LineOfSight::Intersections &, getIntersections, IN, unsigned int, i,
	          Properties::NON_VIRTUAL,
	          __C5_Intersections_R1__getIntersections__unsigned_int,
	          "Get the intersection points for a single line of sight test. ",
	          "");
	I_MethodWithDefaults2(void, computeIntersections, IN, osg::Node *, scene, , IN, osg::Node::NodeMask, traversalMask, 0xffffffff,
	                      Properties::NON_VIRTUAL,
	                      __void__computeIntersections__osg_Node_P1__osg_Node_NodeMask,
	                      "Compute the LOS intersections with the specified scene graph. ",
	                      "The results are all stored in the form of Intersections list, one per LOS test. ");
	I_Method0(void, clearDatabaseCache,
	          Properties::NON_VIRTUAL,
	          __void__clearDatabaseCache,
	          "Clear the database cache. ",
	          "");
	I_Method1(void, setDatabaseCacheReadCallback, IN, osgSim::DatabaseCacheReadCallback *, dcrc,
	          Properties::NON_VIRTUAL,
	          __void__setDatabaseCacheReadCallback__DatabaseCacheReadCallback_P1,
	          "Set the ReadCallback that does the reading of external PagedLOD models, and caching of loaded subgraphs. ",
	          "Note, if you have multiple LineOfSight or HeightAboveTerrain objects in use at one time then you should share a single DatabaseCacheReadCallback between all of them. ");
	I_Method0(osgSim::DatabaseCacheReadCallback *, getDatabaseCacheReadCallback,
	          Properties::NON_VIRTUAL,
	          __DatabaseCacheReadCallback_P1__getDatabaseCacheReadCallback,
	          "Get the ReadCallback that does the reading of external PagedLOD models, and caching of loaded subgraphs. ",
	          "");
	I_StaticMethodWithDefaults4(osgSim::LineOfSight::Intersections, computeIntersections, IN, osg::Node *, scene, , IN, const osg::Vec3d &, start, , IN, const osg::Vec3d &, end, , IN, osg::Node::NodeMask, traversalMask, 0xffffffff,
	                            __Intersections__computeIntersections__osg_Node_P1__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__osg_Node_NodeMask_S,
	                            "Compute the intersection between the specified scene graph and a single LOS start,end pair. ",
	                            "Returns an IntersectionList, of all the points intersected. ");
	I_SimpleProperty(osgSim::DatabaseCacheReadCallback *, DatabaseCacheReadCallback, 
	                 __DatabaseCacheReadCallback_P1__getDatabaseCacheReadCallback, 
	                 __void__setDatabaseCacheReadCallback__DatabaseCacheReadCallback_P1);
	I_IndexedProperty(const osg::Vec3d &, EndPoint, 
	                  __C5_osg_Vec3d_R1__getEndPoint__unsigned_int, 
	                  __void__setEndPoint__unsigned_int__C5_osg_Vec3d_R1, 
	                  0);
	I_IndexedProperty(const osg::Vec3d &, StartPoint, 
	                  __C5_osg_Vec3d_R1__getStartPoint__unsigned_int, 
	                  __void__setStartPoint__unsigned_int__C5_osg_Vec3d_R1, 
	                  0);
END_REFLECTOR

