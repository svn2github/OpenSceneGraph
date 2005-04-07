// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/BoundingBox>
#include <osg/ClipNode>
#include <osg/ClipPlane>
#include <osg/CopyOp>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/StateAttribute>
#include <osg/StateSet>

TYPE_NAME_ALIAS(std::vector< osg::ref_ptr< osg::ClipPlane > >, osg::ClipNode::ClipPlaneList);

BEGIN_OBJECT_REFLECTOR(osg::ClipNode)
	BaseType(osg::Group);
	Constructor0();
	ConstructorWithDefaults2(IN, const osg::ClipNode &, es, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	Method0(osg::Object *, cloneType);
	Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	Method0(const char *, className);
	Method0(const char *, libraryName);
	Method1(void, accept, IN, osg::NodeVisitor &, nv);
	MethodWithDefaults2(void, createClipBox, IN, const osg::BoundingBox &, bb, , IN, unsigned int, clipPlaneNumberBase, 0);
	Method1(bool, addClipPlane, IN, osg::ClipPlane *, clipplane);
	Method1(bool, removeClipPlane, IN, osg::ClipPlane *, clipplane);
	Method1(bool, removeClipPlane, IN, unsigned int, pos);
	Method0(unsigned int, getNumClipPlanes);
	Method1(osg::ClipPlane *, getClipPlane, IN, unsigned int, pos);
	Method1(const osg::ClipPlane *, getClipPlane, IN, unsigned int, pos);
	Method1(void, getClipPlaneList, IN, const osg::ClipNode::ClipPlaneList &, cpl);
	Method0(osg::ClipNode::ClipPlaneList &, getClipPlaneList);
	Method0(const osg::ClipNode::ClipPlaneList &, getClipPlaneList);
	Method2(void, setStateSetModes, IN, osg::StateSet &, x, IN, osg::StateAttribute::GLModeValue, x);
	MethodWithDefaults1(void, setLocalStateSetModes, IN, osg::StateAttribute::GLModeValue, x, osg::StateAttribute::ON);
	ArrayProperty_GA(osg::ClipPlane *, ClipPlane, ClipPlanes, unsigned int, bool);
	ReadOnlyProperty(osg::ClipNode::ClipPlaneList &, ClipPlaneList);
	WriteOnlyProperty(osg::StateAttribute::GLModeValue, LocalStateSetModes);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osg::ClipPlane >)
	Constructor0();
	Constructor1(IN, osg::ClipPlane *, t);
	Constructor1(IN, const osg::ref_ptr< osg::ClipPlane > &, rp);
	Method0(bool, valid);
	Method0(osg::ClipPlane *, get);
	Method0(const osg::ClipPlane *, get);
	Method0(osg::ClipPlane *, take);
	Method0(osg::ClipPlane *, release);
	ReadOnlyProperty(osg::ClipPlane *, );
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::ref_ptr< osg::ClipPlane > >);

