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

#include <osg/BoundingSphere>
#include <osg/CopyOp>
#include <osg/Group>
#include <osg/Node>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/State>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osg::Group)
	I_BaseType(osg::Node);
	I_Constructor0(____Group,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::Group &, x, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____Group__C5_Group_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "clone an object of the same type as the node. ",
	          "");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "return a clone of a node, with Object* return type. ",
	          "");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "return true if this and obj are of the same kind of object. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the node's class type. ",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the node's library. ",
	          "");
	I_Method1(void, accept, IN, osg::NodeVisitor &, nv,
	          Properties::VIRTUAL,
	          __void__accept__osg_NodeVisitor_R1,
	          "Visitor Pattern : calls the apply method of a NodeVisitor with this node's type. ",
	          "");
	I_Method0(osg::Group *, asGroup,
	          Properties::VIRTUAL,
	          __Group_P1__asGroup,
	          "convert 'this' into a Group pointer if Node is a Group, otherwise return 0. ",
	          "Equivalent to dynamic_cast<Group*>(this). ");
	I_Method0(const osg::Group *, asGroup,
	          Properties::VIRTUAL,
	          __C5_Group_P1__asGroup,
	          "convert 'const this' into a const Group pointer if Node is a Group, otherwise return 0. ",
	          "Equivalent to dynamic_cast<const Group*>(this). ");
	I_Method1(void, traverse, IN, osg::NodeVisitor &, nv,
	          Properties::VIRTUAL,
	          __void__traverse__NodeVisitor_R1,
	          "Traverse downwards : calls children's accept method with NodeVisitor. ",
	          "");
	I_Method1(bool, addChild, IN, osg::Node *, child,
	          Properties::VIRTUAL,
	          __bool__addChild__Node_P1,
	          "Add Node to Group. ",
	          "If node is not NULL and is not contained in Group then increment its reference count, add it to the child list and dirty the bounding sphere to force it to recompute on next getBound() and return true for success. Otherwise return false. Scene nodes can't be added as child nodes.");
	I_Method2(bool, insertChild, IN, unsigned int, index, IN, osg::Node *, child,
	          Properties::VIRTUAL,
	          __bool__insertChild__unsigned_int__Node_P1,
	          "Insert Node to Group at specific location. ",
	          "The new child node is inserted into the child list before the node at the specified index. No nodes are removed from the group with this operation.");
	I_Method1(bool, removeChild, IN, osg::Node *, child,
	          Properties::NON_VIRTUAL,
	          __bool__removeChild__Node_P1,
	          "Remove Node from Group. ",
	          "If Node is contained in Group then remove it from the child list, decrement its reference count, and dirty the bounding sphere to force it to recompute on next getBound() and return true for success. If Node is not found then return false and do not change the reference count of the Node. Note, do not override, only override removeChildren(,) is required.");
	I_MethodWithDefaults2(bool, removeChild, IN, unsigned int, pos, , IN, unsigned int, numChildrenToRemove, 1,
	                      Properties::NON_VIRTUAL,
	                      __bool__removeChild__unsigned_int__unsigned_int,
	                      "Remove Node from Group. ",
	                      "If Node is contained in Group then remove it from the child list, decrement its reference count, and dirty the bounding sphere to force it to recompute on next getBound() and return true for success. If Node is not found then return false and do not change the reference count of the Node. Note, do not override, only override removeChildren(,) is required.");
	I_Method2(bool, removeChildren, IN, unsigned int, pos, IN, unsigned int, numChildrenToRemove,
	          Properties::VIRTUAL,
	          __bool__removeChildren__unsigned_int__unsigned_int,
	          "Remove children from Group. ",
	          "Note, must be override by subclasses of Group which add per child attributes. ");
	I_Method2(bool, replaceChild, IN, osg::Node *, origChild, IN, osg::Node *, newChild,
	          Properties::VIRTUAL,
	          __bool__replaceChild__Node_P1__Node_P1,
	          "Replace specified Node with another Node. ",
	          "Equivalent to setChild(getChildIndex(orignChild),node) See docs for setChild for futher details on implementation.");
	I_Method0(unsigned int, getNumChildren,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumChildren,
	          "Return the number of chilren nodes. ",
	          "");
	I_Method2(bool, setChild, IN, unsigned int, i, IN, osg::Node *, node,
	          Properties::VIRTUAL,
	          __bool__setChild__unsigned_int__Node_P1,
	          "Set child node at position i. ",
	          "Return true if set correctly, false on failure (if node==NULL || i is out of range). When Set can be successful applied, the algorithm is : decrement the reference count origNode and increment the reference count of newNode, and dirty the bounding sphere to force it to recompute on next getBound() and return true. If origNode is not found then return false and do not add newNode. If newNode is NULL then return false and do not remove origNode. Also returns false if newChild is a Scene node.");
	I_Method1(osg::Node *, getChild, IN, unsigned int, i,
	          Properties::NON_VIRTUAL,
	          __Node_P1__getChild__unsigned_int,
	          "Return child node at position i. ",
	          "");
	I_Method1(const osg::Node *, getChild, IN, unsigned int, i,
	          Properties::NON_VIRTUAL,
	          __C5_Node_P1__getChild__unsigned_int,
	          "Return child node at position i. ",
	          "");
	I_Method1(bool, containsNode, IN, const osg::Node *, node,
	          Properties::NON_VIRTUAL,
	          __bool__containsNode__C5_Node_P1,
	          "Return true if node is contained within Group. ",
	          "");
	I_Method1(unsigned int, getChildIndex, IN, const osg::Node *, node,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getChildIndex__C5_Node_P1,
	          "Get the index number of child, return a value between 0 and _children.size()-1 if found, if not found then return _children.size(). ",
	          "");
	I_Method1(void, setThreadSafeRefUnref, IN, bool, threadSafe,
	          Properties::VIRTUAL,
	          __void__setThreadSafeRefUnref__bool,
	          "Set whether to use a mutex to ensure ref() and unref() are thread safe. ",
	          "");
	I_Method1(void, resizeGLObjectBuffers, IN, unsigned int, maxSize,
	          Properties::VIRTUAL,
	          __void__resizeGLObjectBuffers__unsigned_int,
	          "Resize any per context GLObject buffers to specified size. ",
	          "");
	I_MethodWithDefaults1(void, releaseGLObjects, IN, osg::State *, x, 0,
	                      Properties::VIRTUAL,
	                      __void__releaseGLObjects__osg_State_P1,
	                      "If State is non-zero, this function releases any associated OpenGL objects for the specified graphics context. ",
	                      "Otherwise, releases OpenGL objexts for all graphics contexts. ");
	I_Method0(osg::BoundingSphere, computeBound,
	          Properties::VIRTUAL,
	          __BoundingSphere__computeBound,
	          "Compute the bounding sphere around Node's geometry or children. ",
	          "This method is automatically called by getBound() when the bounding sphere has been marked dirty via dirtyBound(). ");
	I_ProtectedMethod2(void, childRemoved, IN, unsigned, int, IN, unsigned, int,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__childRemoved__unsigned__unsigned,
	                   "",
	                   "");
	I_ProtectedMethod1(void, childInserted, IN, unsigned, int,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__childInserted__unsigned,
	                   "",
	                   "");
	I_ArrayProperty(osg::Node *, Child, 
	                __Node_P1__getChild__unsigned_int, 
	                __bool__setChild__unsigned_int__Node_P1, 
	                __unsigned_int__getNumChildren, 
	                __bool__addChild__Node_P1, 
	                __bool__insertChild__unsigned_int__Node_P1, 
	                __bool__removeChild__unsigned_int__unsigned_int);
	I_SimpleProperty(bool, ThreadSafeRefUnref, 
	                 0, 
	                 __void__setThreadSafeRefUnref__bool);
END_REFLECTOR

TYPE_NAME_ALIAS(std::vector< osg::ref_ptr< osg::Node > >, osg::NodeList);

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osg::Node >)
	I_Constructor0(____ref_ptr,
	               "",
	               "");
	I_Constructor1(IN, osg::Node *, ptr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osg::Node > &, rp,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__C5_ref_ptr_R1,
	               "",
	               "");
	I_Method0(osg::Node *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(osg::Node *, release,
	          Properties::NON_VIRTUAL,
	          __T_P1__release,
	          "",
	          "");
	I_Method1(void, swap, IN, osg::ref_ptr< osg::Node > &, rp,
	          Properties::NON_VIRTUAL,
	          __void__swap__ref_ptr_R1,
	          "",
	          "");
	I_SimpleProperty(osg::Node *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::ref_ptr< osg::Node > >);

