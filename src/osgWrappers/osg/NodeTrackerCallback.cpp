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
#include <osg/NodeTrackerCallback>
#include <osg/NodeVisitor>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::vector< osg::observer_ptr< osg::Node > >, osg::NodeTrackerCallback::ObserveredNodePath);

BEGIN_OBJECT_REFLECTOR(osg::NodeTrackerCallback)
	I_BaseType(osg::NodeCallback);
	I_Constructor0();
	I_Method1(void, setTrackNodePath, IN, const osg::NodePath &, nodePath);
	I_Method1(void, setTrackNodePath, IN, const osg::NodeTrackerCallback::ObserveredNodePath &, nodePath);
	I_Method0(osg::NodeTrackerCallback::ObserveredNodePath &, getTrackNodePath);
	I_Method1(void, setTrackNode, IN, osg::Node *, node);
	I_Method0(osg::Node *, getTrackNode);
	I_Method0(const osg::Node *, getTrackNode);
	I_Method1(void, update, IN, osg::Node &, node);
	I_Method0(bool, validateNodePath);
	I_Property(osg::Node *, TrackNode);
	I_ReadOnlyProperty(osg::NodeTrackerCallback::ObserveredNodePath &, TrackNodePath);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::observer_ptr< osg::Node >)
	I_BaseType(osg::Observer);
	I_Constructor0();
	I_Constructor1(IN, osg::Node *, t);
	I_Constructor1(IN, const osg::observer_ptr< osg::Node > &, rp);
	I_Method1(void, objectDeleted, IN, void *, ptr);
	I_Method0(bool, valid);
	I_Method0(osg::Node *, get);
	I_Method0(const osg::Node *, get);
	I_ReadOnlyProperty(osg::Node *, );
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::observer_ptr< osg::Node > >);

