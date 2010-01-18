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
#include <osg/Node>
#include <osg/NodeCallback>
#include <osg/NodeVisitor>
#include <osg/Object>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osg::NodeCallback)
	I_DeclaringFile("osg/NodeCallback");
	I_VirtualBaseType(osg::Object);
	I_Constructor0(____NodeCallback,
	               "",
	               "");
	I_Constructor2(IN, const osg::NodeCallback &, nc, IN, const osg::CopyOp &, x,
	               ____NodeCallback__C5_NodeCallback_R1__C5_CopyOp_R1,
	               "",
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
	I_Method2(void, traverse, IN, osg::Node *, node, IN, osg::NodeVisitor *, nv,
	          Properties::NON_VIRTUAL,
	          __void__traverse__Node_P1__NodeVisitor_P1,
	          "Call any nested callbacks and then traverse the scene graph. ",
	          "");
	I_Method1(void, setNestedCallback, IN, osg::NodeCallback *, nc,
	          Properties::NON_VIRTUAL,
	          __void__setNestedCallback__NodeCallback_P1,
	          "",
	          "");
	I_Method0(osg::NodeCallback *, getNestedCallback,
	          Properties::NON_VIRTUAL,
	          __NodeCallback_P1__getNestedCallback,
	          "",
	          "");
	I_Method0(const osg::NodeCallback *, getNestedCallback,
	          Properties::NON_VIRTUAL,
	          __C5_NodeCallback_P1__getNestedCallback,
	          "",
	          "");
	I_Method1(void, addNestedCallback, IN, osg::NodeCallback *, nc,
	          Properties::NON_VIRTUAL,
	          __void__addNestedCallback__NodeCallback_P1,
	          "",
	          "");
	I_Method1(void, removeNestedCallback, IN, osg::NodeCallback *, nc,
	          Properties::NON_VIRTUAL,
	          __void__removeNestedCallback__NodeCallback_P1,
	          "",
	          "");
	I_SimpleProperty(osg::NodeCallback *, NestedCallback, 
	                 __NodeCallback_P1__getNestedCallback, 
	                 __void__setNestedCallback__NodeCallback_P1);
	I_PublicMemberProperty(osg::ref_ptr< osg::NodeCallback >, _nestedCallback);
END_REFLECTOR

