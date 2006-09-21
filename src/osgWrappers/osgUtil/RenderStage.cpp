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

#include <osg/CameraNode>
#include <osg/ColorMask>
#include <osg/CopyOp>
#include <osg/FrameBufferObject>
#include <osg/GraphicsContext>
#include <osg/Image>
#include <osg/Matrix>
#include <osg/Object>
#include <osg/RenderInfo>
#include <osg/StateAttribute>
#include <osg/Texture>
#include <osg/Vec4>
#include <osg/Viewport>
#include <osgUtil/PositionalStateContainer>
#include <osgUtil/RenderBin>
#include <osgUtil/RenderLeaf>
#include <osgUtil/RenderStage>
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
	I_Method1(void, setDrawBuffer, IN, GLenum, buffer);
	I_Method0(GLenum, getDrawBuffer);
	I_Method1(void, setReadBuffer, IN, GLenum, buffer);
	I_Method0(GLenum, getReadBuffer);
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
	I_Method1(void, setCameraNode, IN, osg::CameraNode *, camera);
	I_Method0(osg::CameraNode *, getCameraNode);
	I_Method0(const osg::CameraNode *, getCameraNode);
	I_Method1(void, setCameraRequiresSetUp, IN, bool, flag);
	I_Method0(bool, getCameraRequiresSetUp);
	I_Method1(void, runCameraSetUp, IN, osg::RenderInfo &, renderInfo);
	I_MethodWithDefaults3(void, setTexture, IN, osg::Texture *, texture, , IN, unsigned int, level, 0, IN, unsigned int, face, 0);
	I_Method0(osg::Texture *, getTexture);
	I_Method1(void, setImage, IN, osg::Image *, image);
	I_Method0(osg::Image *, getImage);
	I_Method1(void, setImageReadPixelFormat, IN, GLenum, format);
	I_Method0(GLenum, getImageReadPixelFormat);
	I_Method1(void, setImageReadPixelDataType, IN, GLenum, type);
	I_Method0(GLenum, getImageReadPixelDataType);
	I_Method1(void, setFrameBufferObject, IN, osg::FrameBufferObject *, fbo);
	I_Method0(osg::FrameBufferObject *, getFrameBufferObject);
	I_Method0(const osg::FrameBufferObject *, getFrameBufferObject);
	I_Method1(void, setGraphicsContext, IN, osg::GraphicsContext *, context);
	I_Method0(osg::GraphicsContext *, getGraphicsContext);
	I_Method0(const osg::GraphicsContext *, getGraphicsContext);
	I_Method1(void, setInheritedPositionalStateContainerMatrix, IN, const osg::Matrix &, matrix);
	I_Method0(const osg::Matrix &, getInheritedPositionalStateContainerMatrix);
	I_Method1(void, setInheritedPositionalStateContainer, IN, osgUtil::PositionalStateContainer *, rsl);
	I_Method0(osgUtil::PositionalStateContainer *, getInheritedPositionalStateContainer);
	I_Method1(void, setPositionalStateContainer, IN, osgUtil::PositionalStateContainer *, rsl);
	I_Method0(osgUtil::PositionalStateContainer *, getPositionalStateContainer);
	I_Method2(void, addPositionedAttribute, IN, osg::RefMatrix *, matrix, IN, const osg::StateAttribute *, attr);
	I_Method3(void, addPositionedTextureAttribute, IN, unsigned int, textureUnit, IN, osg::RefMatrix *, matrix, IN, const osg::StateAttribute *, attr);
	I_Method1(void, copyTexture, IN, osg::RenderInfo &, renderInfo);
	I_Method0(void, sort);
	I_Method2(void, drawPreRenderStages, IN, osg::RenderInfo &, renderInfo, IN, osgUtil::RenderLeaf *&, previous);
	I_Method2(void, draw, IN, osg::RenderInfo &, renderInfo, IN, osgUtil::RenderLeaf *&, previous);
	I_Method3(void, drawInner, IN, osg::RenderInfo &, renderInfo, IN, osgUtil::RenderLeaf *&, previous, IN, bool &, doCopyTexture);
	I_Method2(void, drawPostRenderStages, IN, osg::RenderInfo &, renderInfo, IN, osgUtil::RenderLeaf *&, previous);
	I_Method2(void, drawImplementation, IN, osg::RenderInfo &, renderInfo, IN, osgUtil::RenderLeaf *&, previous);
	I_Method1(void, addToDependencyList, IN, osgUtil::RenderStage *, rs);
	I_MethodWithDefaults2(void, addPreRenderStage, IN, osgUtil::RenderStage *, rs, , IN, int, order, 0);
	I_MethodWithDefaults2(void, addPostRenderStage, IN, osgUtil::RenderStage *, rs, , IN, int, order, 0);
	I_Method1(bool, getStats, IN, osgUtil::Statistics &, stats);
	I_Property(osg::CameraNode *, CameraNode);
	I_Property(bool, CameraRequiresSetUp);
	I_Property(const osg::Vec4 &, ClearAccum);
	I_Property(const osg::Vec4 &, ClearColor);
	I_Property(double, ClearDepth);
	I_Property(GLbitfield, ClearMask);
	I_Property(int, ClearStencil);
	I_Property(osg::ColorMask *, ColorMask);
	I_Property(GLenum, DrawBuffer);
	I_Property(osg::FrameBufferObject *, FrameBufferObject);
	I_Property(osg::GraphicsContext *, GraphicsContext);
	I_Property(osg::Image *, Image);
	I_Property(GLenum, ImageReadPixelDataType);
	I_Property(GLenum, ImageReadPixelFormat);
	I_Property(osgUtil::PositionalStateContainer *, InheritedPositionalStateContainer);
	I_Property(const osg::Matrix &, InheritedPositionalStateContainerMatrix);
	I_Property(osgUtil::PositionalStateContainer *, PositionalStateContainer);
	I_Property(GLenum, ReadBuffer);
	I_ReadOnlyProperty(osg::Texture *, Texture);
	I_Property(osg::Viewport *, Viewport);
END_REFLECTOR

