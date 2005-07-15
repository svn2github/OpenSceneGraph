// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/ColorMask>
#include <osg/CopyOp>
#include <osg/Matrix>
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>
#include <osg/Vec4>
#include <osg/Viewport>
#include <osgUtil/RenderBin>
#include <osgUtil/RenderLeaf>
#include <osgUtil/RenderStage>
#include <osgUtil/RenderStageLighting>
#include <osgUtil/Statistics>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgUtil::RenderStage)
	I_BaseType(osgUtil::RenderBin);
	I_Constructor0();
	I_Constructor1(IN, osgUtil::RenderBin::SortMode, mode);
	I_ConstructorWithDefaults2(IN, const osgUtil::RenderStage &, rhs, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, className);
	I_Method0(void, reset);
	I_Method1(void, setViewport, IN, osg::Viewport *, viewport);
	I_Method0(const osg::Viewport *, getViewport);
	I_Method0(osg::Viewport *, getViewport);
	I_Method1(void, setClearMask, IN, GLbitfield, mask);
	I_Method0(GLbitfield, getClearMask);
	I_Method1(void, setColorMask, IN, osg::ColorMask *, cm);
	I_Method0(osg::ColorMask *, getColorMask);
	I_Method0(const osg::ColorMask *, getColorMask);
	I_Method1(void, setClearColor, IN, const osg::Vec4 &, color);
	I_Method0(const osg::Vec4 &, getClearColor);
	I_Method1(void, setClearAccum, IN, const osg::Vec4 &, color);
	I_Method0(const osg::Vec4 &, getClearAccum);
	I_Method1(void, setClearDepth, IN, double, depth);
	I_Method0(double, getClearDepth);
	I_Method1(void, setClearStencil, IN, int, stencil);
	I_Method0(int, getClearStencil);
	I_Method1(void, setRenderStageLighting, IN, osgUtil::RenderStageLighting *, rsl);
	I_Method0(osgUtil::RenderStageLighting *, getRenderStageLighting);
	I_Method2(void, addPositionedAttribute, IN, osg::RefMatrix *, matrix, IN, const osg::StateAttribute *, attr);
	I_Method3(void, addPositionedTextureAttribute, IN, unsigned int, textureUnit, IN, osg::RefMatrix *, matrix, IN, const osg::StateAttribute *, attr);
	I_Method2(void, drawPreRenderStages, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
	I_Method2(void, draw, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
	I_Method2(void, drawPostRenderStages, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
	I_Method2(void, drawImplementation, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
	I_Method1(void, addToDependencyList, IN, osgUtil::RenderStage *, rs);
	I_Method1(void, addPreRenderStage, IN, osgUtil::RenderStage *, rs);
	I_Method1(void, addPostRenderStage, IN, osgUtil::RenderStage *, rs);
	I_Method1(bool, getStats, IN, osgUtil::Statistics *, primStats);
	I_Property(const osg::Vec4 &, ClearAccum);
	I_Property(const osg::Vec4 &, ClearColor);
	I_Property(double, ClearDepth);
	I_Property(GLbitfield, ClearMask);
	I_Property(int, ClearStencil);
	I_Property(osg::ColorMask *, ColorMask);
	I_Property(osgUtil::RenderStageLighting *, RenderStageLighting);
	I_Property(osg::Viewport *, Viewport);
END_REFLECTOR

