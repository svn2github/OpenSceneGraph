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
#include <osg/Transform>
#include <osgAnimation/Bone>
#include <osgAnimation/BoneMapVisitor>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

#include <osg/observer_ptr>
        
BEGIN_OBJECT_REFLECTOR(osgAnimation::BoneMapVisitor)
	I_DeclaringFile("osgAnimation/BoneMapVisitor");
	I_BaseType(osg::NodeVisitor);
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the library name/namespapce of the visitor's. ",
	          "Should be defined by derived classes. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the visitor's class type. ",
	          "Should be defined by derived classes. ");
	I_Constructor0(____BoneMapVisitor,
	               "",
	               "");
	I_Method1(void, apply, IN, osg::Node &, x,
	          Properties::VIRTUAL,
	          __void__apply__osg_Node_R1,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::Transform &, node,
	          Properties::VIRTUAL,
	          __void__apply__osg_Transform_R1,
	          "",
	          "");
	I_Method0(const osgAnimation::BoneMap &, getBoneMap,
	          Properties::NON_VIRTUAL,
	          __C5_BoneMap_R1__getBoneMap,
	          "",
	          "");
	I_SimpleProperty(const osgAnimation::BoneMap &, BoneMap, 
	                 __C5_BoneMap_R1__getBoneMap, 
	                 0);
END_REFLECTOR

