// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/CopyOp>
#include <osg/Object>
#include <osg/State>
#include <osgUtil/RenderBin>
#include <osgUtil/RenderGraph>
#include <osgUtil/RenderLeaf>
#include <osgUtil/RenderStage>
#include <osgUtil/Statistics>

BEGIN_VALUE_REFLECTOR(osgUtil::RegisterRenderBinProxy)
	Constructor2(IN, const std::string &, binName, IN, osgUtil::RenderBin *, proto);
END_REFLECTOR

TYPE_NAME_ALIAS(std::vector< osgUtil::RenderLeaf * >, osgUtil::RenderBin::RenderLeafList);

TYPE_NAME_ALIAS(std::vector< osgUtil::RenderGraph * >, osgUtil::RenderBin::RenderGraphList);

TYPE_NAME_ALIAS(std::map< int COMMA  osg::ref_ptr< osgUtil::RenderBin > >, osgUtil::RenderBin::RenderBinList);

BEGIN_ENUM_REFLECTOR(osgUtil::RenderBin::SortMode)
	EnumLabel(osgUtil::RenderBin::SORT_BY_STATE);
	EnumLabel(osgUtil::RenderBin::SORT_FRONT_TO_BACK);
	EnumLabel(osgUtil::RenderBin::SORT_BACK_TO_FRONT);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::RenderBin)
	BaseType(osg::Object);
	ConstructorWithDefaults1(IN, osgUtil::RenderBin::SortMode, mode, osgUtil::RenderBin::SORT_BY_STATE);
	ConstructorWithDefaults2(IN, const osgUtil::RenderBin &, rhs, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	Method0(osg::Object *, cloneType);
	Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	Method0(const char *, libraryName);
	Method0(const char *, className);
	Method0(void, reset);
	Method0(osgUtil::RenderBin *, getParent);
	Method0(const osgUtil::RenderBin *, getParent);
	Method0(osgUtil::RenderStage *, getStage);
	Method0(const osgUtil::RenderStage *, getStage);
	Method0(int, getBinNum);
	Method0(osgUtil::RenderBin::RenderGraphList &, getRenderGraphList);
	Method0(const osgUtil::RenderBin::RenderGraphList &, getRenderGraphList);
	Method0(osgUtil::RenderBin::RenderBinList &, getRenderBinList);
	Method0(const osgUtil::RenderBin::RenderBinList &, getRenderBinList);
	Method0(osgUtil::RenderBin::RenderLeafList &, getRenderLeafList);
	Method0(const osgUtil::RenderBin::RenderLeafList &, getRenderLeafList);
	Method2(osgUtil::RenderBin *, find_or_insert, IN, int, binNum, IN, const std::string &, binName);
	Method1(void, addRenderGraph, IN, osgUtil::RenderGraph *, rg);
	Method0(void, sort);
	Method0(void, sortImplementation);
	Method1(void, setSortMode, IN, osgUtil::RenderBin::SortMode, mode);
	Method0(osgUtil::RenderBin::SortMode, getSortMode);
	Method0(void, sortByState);
	Method0(void, sortFrontToBack);
	Method0(void, sortBackToFront);
	Method1(void, setSortCallback, IN, osgUtil::RenderBin::SortCallback *, sortCallback);
	Method0(osgUtil::RenderBin::SortCallback *, getSortCallback);
	Method0(const osgUtil::RenderBin::SortCallback *, getSortCallback);
	Method2(void, draw, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
	Method2(void, drawImplementation, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
	Method1(void, setDrawCallback, IN, osgUtil::RenderBin::DrawCallback *, drawCallback);
	Method0(osgUtil::RenderBin::DrawCallback *, getDrawCallback);
	Method0(const osgUtil::RenderBin::DrawCallback *, getDrawCallback);
	Method1(bool, getStats, IN, osgUtil::Statistics *, primStats);
	Method1(void, getPrims, IN, osgUtil::Statistics *, primStats);
	Method2(bool, getPrims, IN, osgUtil::Statistics *, primStats, IN, int, nbin);
	ReadOnlyProperty(int, BinNum);
	Property(osgUtil::RenderBin::DrawCallback *, DrawCallback);
	ReadOnlyProperty(osgUtil::RenderBin *, Parent);
	ReadOnlyProperty(osgUtil::RenderBin::RenderBinList &, RenderBinList);
	ReadOnlyProperty(osgUtil::RenderBin::RenderGraphList &, RenderGraphList);
	ReadOnlyProperty(osgUtil::RenderBin::RenderLeafList &, RenderLeafList);
	Property(osgUtil::RenderBin::SortCallback *, SortCallback);
	Property(osgUtil::RenderBin::SortMode, SortMode);
	ReadOnlyProperty(osgUtil::RenderStage *, Stage);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgUtil::RenderBin::DrawCallback)
	BaseType(osg::Referenced);
	Constructor0();
	Method3(void, drawImplementation, IN, osgUtil::RenderBin *, bin, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgUtil::RenderBin::SortCallback)
	BaseType(osg::Referenced);
	Constructor0();
	Method1(void, sortImplementation, IN, osgUtil::RenderBin *, x);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osgUtil::RenderBin >)
	Constructor0();
	Constructor1(IN, osgUtil::RenderBin *, t);
	Constructor1(IN, const osg::ref_ptr< osgUtil::RenderBin > &, rp);
	Method0(bool, valid);
	Method0(osgUtil::RenderBin *, get);
	Method0(const osgUtil::RenderBin *, get);
	Method0(osgUtil::RenderBin *, take);
	Method0(osgUtil::RenderBin *, release);
	ReadOnlyProperty(osgUtil::RenderBin *, );
END_REFLECTOR

STD_MAP_REFLECTOR(std::map< int COMMA  osg::ref_ptr< osgUtil::RenderBin > >);

STD_VECTOR_REFLECTOR(std::vector< osgUtil::RenderGraph * >);

STD_VECTOR_REFLECTOR(std::vector< osgUtil::RenderLeaf * >);

