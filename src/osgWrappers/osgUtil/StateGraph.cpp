// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/StateSet>
#include <osg/test/Referenced>
#include <osgUtil/RenderLeaf>
#include <osgUtil/StateGraph>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_VALUE_REFLECTOR(osgUtil::LeafDepthSortFunctor)
	I_Constructor0();
END_REFLECTOR

TYPE_NAME_ALIAS(std::map< const osg::StateSet * COMMA  osg::ref_ptr< osgUtil::StateGraph > >, osgUtil::StateGraph::ChildList);

TYPE_NAME_ALIAS(std::vector< osg::ref_ptr< osgUtil::RenderLeaf > >, osgUtil::StateGraph::LeafList);

BEGIN_OBJECT_REFLECTOR(osgUtil::StateGraph)
	I_BaseType(osg::Referenced);
	I_Constructor0();
	I_Constructor2(IN, osgUtil::StateGraph *, parent, IN, const osg::StateSet *, stateset);
	I_Method0(osgUtil::StateGraph *, cloneType);
	I_Method1(void, setUserData, IN, osg::Referenced *, obj);
	I_Method0(osg::Referenced *, getUserData);
	I_Method0(const osg::Referenced *, getUserData);
	I_Method0(bool, empty);
	I_Method0(bool, leaves_empty);
	I_Method0(float, getAverageDistance);
	I_Method0(float, getMinimumDistance);
	I_Method0(void, sortFrontToBack);
	I_Method0(void, reset);
	I_Method0(void, clean);
	I_Method0(void, prune);
	I_Method1(osgUtil::StateGraph *, find_or_insert, IN, const osg::StateSet *, stateset);
	I_Method1(void, addLeaf, IN, osgUtil::RenderLeaf *, leaf);
	I_ReadOnlyProperty(float, AverageDistance);
	I_ReadOnlyProperty(float, MinimumDistance);
	I_Property(osg::Referenced *, UserData);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osgUtil::RenderLeaf >)
	I_Constructor0();
	I_Constructor1(IN, osgUtil::RenderLeaf *, ptr);
	I_Constructor1(IN, const osg::ref_ptr< osgUtil::RenderLeaf > &, rp);
	I_Method0(osgUtil::RenderLeaf *, get);
	I_Method0(bool, valid);
	I_Method0(osgUtil::RenderLeaf *, release);
	I_Method1(void, swap, IN, osg::ref_ptr< osgUtil::RenderLeaf > &, rp);
	I_Constructor0();
	I_Constructor1(IN, osgUtil::RenderLeaf *, ptr);
	I_Constructor1(IN, const osg::ref_ptr< osgUtil::RenderLeaf > &, rp);
	I_Method0(osgUtil::RenderLeaf *, get);
	I_Method0(bool, valid);
	I_Method0(osgUtil::RenderLeaf *, release);
	I_Method1(void, swap, IN, osg::ref_ptr< osgUtil::RenderLeaf > &, rp);
	I_ReadOnlyProperty(osgUtil::RenderLeaf *, );
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osgUtil::StateGraph >)
	I_Constructor0();
	I_Constructor1(IN, osgUtil::StateGraph *, ptr);
	I_Constructor1(IN, const osg::ref_ptr< osgUtil::StateGraph > &, rp);
	I_Method0(osgUtil::StateGraph *, get);
	I_Method0(bool, valid);
	I_Method0(osgUtil::StateGraph *, release);
	I_Method1(void, swap, IN, osg::ref_ptr< osgUtil::StateGraph > &, rp);
	I_Constructor0();
	I_Constructor1(IN, osgUtil::StateGraph *, ptr);
	I_Constructor1(IN, const osg::ref_ptr< osgUtil::StateGraph > &, rp);
	I_Method0(osgUtil::StateGraph *, get);
	I_Method0(bool, valid);
	I_Method0(osgUtil::StateGraph *, release);
	I_Method1(void, swap, IN, osg::ref_ptr< osgUtil::StateGraph > &, rp);
	I_ReadOnlyProperty(osgUtil::StateGraph *, );
END_REFLECTOR

STD_MAP_REFLECTOR(std::map< const osg::StateSet * COMMA  osg::ref_ptr< osgUtil::StateGraph > >);

STD_VECTOR_REFLECTOR(std::vector< osg::ref_ptr< osgUtil::RenderLeaf > >);

