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

#include <OpenThreads/Mutex>
#include <osg/Camera>
#include <osg/ColorMask>
#include <osg/CopyOp>
#include <osg/GraphicsContext>
#include <osg/GraphicsThread>
#include <osg/Image>
#include <osg/Matrix>
#include <osg/Matrixd>
#include <osg/Matrixf>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/State>
#include <osg/Stats>
#include <osg/Texture>
#include <osg/Vec3>
#include <osg/Vec4>
#include <osg/View>
#include <osg/Viewport>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::map< osg::Camera::BufferComponent COMMA  osg::Camera::Attachment >, osg::Camera::BufferAttachmentMap)

BEGIN_ENUM_REFLECTOR(osg::Camera::TransformOrder)
	I_DeclaringFile("osg/Camera");
	I_EnumLabel(osg::Camera::PRE_MULTIPLY);
	I_EnumLabel(osg::Camera::POST_MULTIPLY);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Camera::ProjectionResizePolicy)
	I_DeclaringFile("osg/Camera");
	I_EnumLabel(osg::Camera::FIXED);
	I_EnumLabel(osg::Camera::HORIZONTAL);
	I_EnumLabel(osg::Camera::VERTICAL);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Camera::RenderOrder)
	I_DeclaringFile("osg/Camera");
	I_EnumLabel(osg::Camera::PRE_RENDER);
	I_EnumLabel(osg::Camera::NESTED_RENDER);
	I_EnumLabel(osg::Camera::POST_RENDER);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Camera::RenderTargetImplementation)
	I_DeclaringFile("osg/Camera");
	I_EnumLabel(osg::Camera::FRAME_BUFFER_OBJECT);
	I_EnumLabel(osg::Camera::PIXEL_BUFFER_RTT);
	I_EnumLabel(osg::Camera::PIXEL_BUFFER);
	I_EnumLabel(osg::Camera::FRAME_BUFFER);
	I_EnumLabel(osg::Camera::SEPERATE_WINDOW);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Camera::BufferComponent)
	I_DeclaringFile("osg/Camera");
	I_EnumLabel(osg::Camera::DEPTH_BUFFER);
	I_EnumLabel(osg::Camera::STENCIL_BUFFER);
	I_EnumLabel(osg::Camera::COLOR_BUFFER);
	I_EnumLabel(osg::Camera::COLOR_BUFFER0);
	I_EnumLabel(osg::Camera::COLOR_BUFFER1);
	I_EnumLabel(osg::Camera::COLOR_BUFFER2);
	I_EnumLabel(osg::Camera::COLOR_BUFFER3);
	I_EnumLabel(osg::Camera::COLOR_BUFFER4);
	I_EnumLabel(osg::Camera::COLOR_BUFFER5);
	I_EnumLabel(osg::Camera::COLOR_BUFFER6);
	I_EnumLabel(osg::Camera::COLOR_BUFFER7);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::Camera)
	I_DeclaringFile("osg/Camera");
	I_BaseType(osg::Transform);
	I_BaseType(osg::CullSettings);
	I_Constructor0(____Camera,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::Camera &, x, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____Camera__C5_Camera_R1__C5_CopyOp_R1,
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
	I_Method1(void, setView, IN, osg::View *, view,
	          Properties::NON_VIRTUAL,
	          __void__setView__View_P1,
	          "Set the View that this Camera is part of. ",
	          "");
	I_Method0(osg::View *, getView,
	          Properties::NON_VIRTUAL,
	          __View_P1__getView,
	          "Get the View that this Camera is part of. ",
	          "");
	I_Method0(const osg::View *, getView,
	          Properties::NON_VIRTUAL,
	          __C5_View_P1__getView,
	          "Get the const View that this Camera is part of. ",
	          "");
	I_Method1(void, setStats, IN, osg::Stats *, stats,
	          Properties::NON_VIRTUAL,
	          __void__setStats__osg_Stats_P1,
	          "Set the Stats object used for collect various frame related timing and scene graph stats. ",
	          "");
	I_Method0(osg::Stats *, getStats,
	          Properties::NON_VIRTUAL,
	          __osg_Stats_P1__getStats,
	          "Get the Stats object. ",
	          "");
	I_Method0(const osg::Stats *, getStats,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Stats_P1__getStats,
	          "Get the const Stats object. ",
	          "");
	I_Method1(void, setAllowEventFocus, IN, bool, focus,
	          Properties::NON_VIRTUAL,
	          __void__setAllowEventFocus__bool,
	          "Set whether this camera allows events to be generated by the associated graphics window to be associated with this camera. ",
	          "");
	I_Method0(bool, getAllowEventFocus,
	          Properties::NON_VIRTUAL,
	          __bool__getAllowEventFocus,
	          "Get whether this camera allows events to be generated by the associated graphics window to be associated with this camera. ",
	          "");
	I_Method1(void, setClearColor, IN, const osg::Vec4 &, color,
	          Properties::NON_VIRTUAL,
	          __void__setClearColor__C5_Vec4_R1,
	          "Sets the clear color. ",
	          "");
	I_Method0(const osg::Vec4 &, getClearColor,
	          Properties::NON_VIRTUAL,
	          __C5_Vec4_R1__getClearColor,
	          "Returns the clear color. ",
	          "");
	I_Method1(void, setClearMask, IN, GLbitfield, mask,
	          Properties::NON_VIRTUAL,
	          __void__setClearMask__GLbitfield,
	          "Set the clear mask used in glClear(. ",
	          ".). Defaults to GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT. ");
	I_Method0(GLbitfield, getClearMask,
	          Properties::NON_VIRTUAL,
	          __GLbitfield__getClearMask,
	          "Get the clear mask. ",
	          "");
	I_Method1(void, setColorMask, IN, osg::ColorMask *, colorMask,
	          Properties::NON_VIRTUAL,
	          __void__setColorMask__osg_ColorMask_P1,
	          "Set the color mask of the camera to use specified osg::ColorMask. ",
	          "");
	I_Method4(void, setColorMask, IN, bool, red, IN, bool, green, IN, bool, blue, IN, bool, alpha,
	          Properties::NON_VIRTUAL,
	          __void__setColorMask__bool__bool__bool__bool,
	          "Set the color mask of the camera to specified values. ",
	          "");
	I_Method0(const osg::ColorMask *, getColorMask,
	          Properties::NON_VIRTUAL,
	          __C5_ColorMask_P1__getColorMask,
	          "Get the const ColorMask. ",
	          "");
	I_Method0(osg::ColorMask *, getColorMask,
	          Properties::NON_VIRTUAL,
	          __ColorMask_P1__getColorMask,
	          "Get the ColorMask. ",
	          "");
	I_Method1(void, setViewport, IN, osg::Viewport *, viewport,
	          Properties::NON_VIRTUAL,
	          __void__setViewport__osg_Viewport_P1,
	          "Set the viewport of the camera to use specified osg::Viewport. ",
	          "");
	I_Method4(void, setViewport, IN, int, x, IN, int, y, IN, int, width, IN, int, height,
	          Properties::NON_VIRTUAL,
	          __void__setViewport__int__int__int__int,
	          "Set the viewport of the camera to specified dimensions. ",
	          "");
	I_Method0(const osg::Viewport *, getViewport,
	          Properties::NON_VIRTUAL,
	          __C5_Viewport_P1__getViewport,
	          "Get the const viewport. ",
	          "");
	I_Method0(osg::Viewport *, getViewport,
	          Properties::NON_VIRTUAL,
	          __Viewport_P1__getViewport,
	          "Get the viewport. ",
	          "");
	I_Method1(void, setTransformOrder, IN, osg::Camera::TransformOrder, order,
	          Properties::NON_VIRTUAL,
	          __void__setTransformOrder__TransformOrder,
	          "Set the transformation order for world-to-local and local-to-world transformation. ",
	          "");
	I_Method0(osg::Camera::TransformOrder, getTransformOrder,
	          Properties::NON_VIRTUAL,
	          __TransformOrder__getTransformOrder,
	          "Get the transformation order. ",
	          "");
	I_Method1(void, setProjectionResizePolicy, IN, osg::Camera::ProjectionResizePolicy, policy,
	          Properties::NON_VIRTUAL,
	          __void__setProjectionResizePolicy__ProjectionResizePolicy,
	          "Set the policy used to determin if and how the projection matrix should be adjusted on window resizes. ",
	          "");
	I_Method0(osg::Camera::ProjectionResizePolicy, getProjectionResizePolicy,
	          Properties::NON_VIRTUAL,
	          __ProjectionResizePolicy__getProjectionResizePolicy,
	          "Get the policy used to determin if and how the projection matrix should be adjusted on window resizes. ",
	          "");
	I_Method1(void, setProjectionMatrix, IN, const osg::Matrixf &, matrix,
	          Properties::NON_VIRTUAL,
	          __void__setProjectionMatrix__C5_osg_Matrixf_R1,
	          "Set the projection matrix. ",
	          "Can be thought of as setting the lens of a camera. ");
	I_Method1(void, setProjectionMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::NON_VIRTUAL,
	          __void__setProjectionMatrix__C5_osg_Matrixd_R1,
	          "Set the projection matrix. ",
	          "Can be thought of as setting the lens of a camera. ");
	I_Method6(void, setProjectionMatrixAsOrtho, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top, IN, double, zNear, IN, double, zFar,
	          Properties::NON_VIRTUAL,
	          __void__setProjectionMatrixAsOrtho__double__double__double__double__double__double,
	          "Set to an orthographic projection. ",
	          "See OpenGL glOrtho for documentation further details. ");
	I_Method4(void, setProjectionMatrixAsOrtho2D, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top,
	          Properties::NON_VIRTUAL,
	          __void__setProjectionMatrixAsOrtho2D__double__double__double__double,
	          "Set to a 2D orthographic projection. ",
	          "See OpenGL glOrtho2D documentation for further details. ");
	I_Method6(void, setProjectionMatrixAsFrustum, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top, IN, double, zNear, IN, double, zFar,
	          Properties::NON_VIRTUAL,
	          __void__setProjectionMatrixAsFrustum__double__double__double__double__double__double,
	          "Set to a perspective projection. ",
	          "See OpenGL glFrustum documentation for further details. ");
	I_Method4(void, setProjectionMatrixAsPerspective, IN, double, fovy, IN, double, aspectRatio, IN, double, zNear, IN, double, zFar,
	          Properties::NON_VIRTUAL,
	          __void__setProjectionMatrixAsPerspective__double__double__double__double,
	          "Create a symmetrical perspective projection, See OpenGL gluPerspective documentation for further details. ",
	          "Aspect ratio is defined as width/height. ");
	I_Method0(osg::Matrixd &, getProjectionMatrix,
	          Properties::NON_VIRTUAL,
	          __osg_Matrixd_R1__getProjectionMatrix,
	          "Get the projection matrix. ",
	          "");
	I_Method0(const osg::Matrixd &, getProjectionMatrix,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Matrixd_R1__getProjectionMatrix,
	          "Get the const projection matrix. ",
	          "");
	I_Method6(bool, getProjectionMatrixAsOrtho, IN, double &, left, IN, double &, right, IN, double &, bottom, IN, double &, top, IN, double &, zNear, IN, double &, zFar,
	          Properties::NON_VIRTUAL,
	          __bool__getProjectionMatrixAsOrtho__double_R1__double_R1__double_R1__double_R1__double_R1__double_R1,
	          "Get the othographic settings of the orthographic projection matrix. ",
	          "Returns false if matrix is not an orthographic matrix, where parameter values are undefined. ");
	I_Method6(bool, getProjectionMatrixAsFrustum, IN, double &, left, IN, double &, right, IN, double &, bottom, IN, double &, top, IN, double &, zNear, IN, double &, zFar,
	          Properties::NON_VIRTUAL,
	          __bool__getProjectionMatrixAsFrustum__double_R1__double_R1__double_R1__double_R1__double_R1__double_R1,
	          "Get the frustum setting of a perspective projection matrix. ",
	          "Returns false if matrix is not a perspective matrix, where parameter values are undefined. ");
	I_Method4(bool, getProjectionMatrixAsPerspective, IN, double &, fovy, IN, double &, aspectRatio, IN, double &, zNear, IN, double &, zFar,
	          Properties::NON_VIRTUAL,
	          __bool__getProjectionMatrixAsPerspective__double_R1__double_R1__double_R1__double_R1,
	          "Get the frustum setting of a symmetric perspective projection matrix. ",
	          "Returns false if matrix is not a perspective matrix, where parameter values are undefined. Note, if matrix is not a symmetric perspective matrix then the shear will be lost. Asymmetric matrices occur when stereo, power walls, caves and reality center display are used. In these configurations one should use the 'getProjectionMatrixAsFrustum' method instead. ");
	I_Method1(void, setViewMatrix, IN, const osg::Matrixf &, matrix,
	          Properties::NON_VIRTUAL,
	          __void__setViewMatrix__C5_osg_Matrixf_R1,
	          "Set the view matrix. ",
	          "Can be thought of as setting the position of the world relative to the camera in camera coordinates. ");
	I_Method1(void, setViewMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::NON_VIRTUAL,
	          __void__setViewMatrix__C5_osg_Matrixd_R1,
	          "Set the view matrix. ",
	          "Can be thought of as setting the position of the world relative to the camera in camera coordinates. ");
	I_Method3(void, setViewMatrixAsLookAt, IN, const osg::Vec3 &, eye, IN, const osg::Vec3 &, center, IN, const osg::Vec3 &, up,
	          Properties::NON_VIRTUAL,
	          __void__setViewMatrixAsLookAt__C5_osg_Vec3_R1__C5_osg_Vec3_R1__C5_osg_Vec3_R1,
	          "Set to the position and orientation of view matrix, using the same convention as gluLookAt. ",
	          "");
	I_Method0(osg::Matrixd &, getViewMatrix,
	          Properties::NON_VIRTUAL,
	          __osg_Matrixd_R1__getViewMatrix,
	          "Get the view matrix. ",
	          "");
	I_Method0(const osg::Matrixd &, getViewMatrix,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Matrixd_R1__getViewMatrix,
	          "Get the const view matrix. ",
	          "");
	I_MethodWithDefaults4(void, getViewMatrixAsLookAt, IN, osg::Vec3 &, eye, , IN, osg::Vec3 &, center, , IN, osg::Vec3 &, up, , IN, float, lookDistance, 1.0f,
	                      Properties::NON_VIRTUAL,
	                      __void__getViewMatrixAsLookAt__osg_Vec3_R1__osg_Vec3_R1__osg_Vec3_R1__float,
	                      "Get to the position and orientation of a modelview matrix, using the same convention as gluLookAt. ",
	                      "");
	I_Method0(osg::Matrixd, getInverseViewMatrix,
	          Properties::NON_VIRTUAL,
	          __Matrixd__getInverseViewMatrix,
	          "Get the inverse view matrix. ",
	          "");
	I_MethodWithDefaults2(void, setRenderOrder, IN, osg::Camera::RenderOrder, order, , IN, int, orderNum, 0,
	                      Properties::NON_VIRTUAL,
	                      __void__setRenderOrder__RenderOrder__int,
	                      "Set the rendering order of this camera's subgraph relative to any camera that this subgraph is nested within. ",
	                      "For rendering to a texture, one typically uses PRE_RENDER. For Head Up Displays, one would typically use POST_RENDER. ");
	I_Method0(osg::Camera::RenderOrder, getRenderOrder,
	          Properties::NON_VIRTUAL,
	          __RenderOrder__getRenderOrder,
	          "Get the rendering order of this camera's subgraph relative to any camera that this subgraph is nested within. ",
	          "");
	I_Method0(int, getRenderOrderNum,
	          Properties::NON_VIRTUAL,
	          __int__getRenderOrderNum,
	          "Get the rendering order number of this camera relative to any sibling cameras in this subgraph. ",
	          "");
	I_Method0(bool, isRenderToTextureCamera,
	          Properties::NON_VIRTUAL,
	          __bool__isRenderToTextureCamera,
	          "Return true if this Camera is set up as a render to texture camera, i.e. ",
	          "it has textures assigned to it. ");
	I_Method1(void, setRenderTargetImplementation, IN, osg::Camera::RenderTargetImplementation, impl,
	          Properties::NON_VIRTUAL,
	          __void__setRenderTargetImplementation__RenderTargetImplementation,
	          "Set the render target. ",
	          "");
	I_Method2(void, setRenderTargetImplementation, IN, osg::Camera::RenderTargetImplementation, impl, IN, osg::Camera::RenderTargetImplementation, fallback,
	          Properties::NON_VIRTUAL,
	          __void__setRenderTargetImplementation__RenderTargetImplementation__RenderTargetImplementation,
	          "Set the render target and fall-back that's used if the former isn't available. ",
	          "");
	I_Method0(osg::Camera::RenderTargetImplementation, getRenderTargetImplementation,
	          Properties::NON_VIRTUAL,
	          __RenderTargetImplementation__getRenderTargetImplementation,
	          "Get the render target. ",
	          "");
	I_Method0(osg::Camera::RenderTargetImplementation, getRenderTargetFallback,
	          Properties::NON_VIRTUAL,
	          __RenderTargetImplementation__getRenderTargetFallback,
	          "Get the render target fallback. ",
	          "");
	I_Method1(void, setDrawBuffer, IN, GLenum, buffer,
	          Properties::NON_VIRTUAL,
	          __void__setDrawBuffer__GLenum,
	          "Set the draw buffer used at the start of each frame draw. ",
	          "Note, a buffer value of GL_NONE is used to sepecify that the rendering back-end should choose the most appropriate buffer. ");
	I_Method0(GLenum, getDrawBuffer,
	          Properties::NON_VIRTUAL,
	          __GLenum__getDrawBuffer,
	          "Get the draw buffer used at the start of each frame draw. ",
	          "");
	I_Method1(void, setReadBuffer, IN, GLenum, buffer,
	          Properties::NON_VIRTUAL,
	          __void__setReadBuffer__GLenum,
	          "Set the read buffer for any required copy operations to use. ",
	          "Note, a buffer value of GL_NONE is used to sepecify that the rendering back-end should choose the most appropriate buffer. ");
	I_Method0(GLenum, getReadBuffer,
	          Properties::NON_VIRTUAL,
	          __GLenum__getReadBuffer,
	          "Get the read buffer for any required copy operations to use. ",
	          "");
	I_Method2(void, attach, IN, osg::Camera::BufferComponent, buffer, IN, GLenum, internalFormat,
	          Properties::NON_VIRTUAL,
	          __void__attach__BufferComponent__GLenum,
	          "",
	          "");
	I_MethodWithDefaults5(void, attach, IN, osg::Camera::BufferComponent, buffer, , IN, osg::Texture *, texture, , IN, unsigned int, level, 0, IN, unsigned int, face, 0, IN, bool, mipMapGeneration, false,
	                      Properties::NON_VIRTUAL,
	                      __void__attach__BufferComponent__osg_Texture_P1__unsigned_int__unsigned_int__bool,
	                      "",
	                      "");
	I_Method2(void, attach, IN, osg::Camera::BufferComponent, buffer, IN, osg::Image *, image,
	          Properties::NON_VIRTUAL,
	          __void__attach__BufferComponent__osg_Image_P1,
	          "",
	          "");
	I_Method1(void, detach, IN, osg::Camera::BufferComponent, buffer,
	          Properties::NON_VIRTUAL,
	          __void__detach__BufferComponent,
	          "",
	          "");
	I_Method0(osg::Camera::BufferAttachmentMap &, getBufferAttachmentMap,
	          Properties::NON_VIRTUAL,
	          __BufferAttachmentMap_R1__getBufferAttachmentMap,
	          "Get the BufferAttachmentMap, used to configure frame buffer objects, pbuffers and texture reads. ",
	          "");
	I_Method0(const osg::Camera::BufferAttachmentMap &, getBufferAttachmentMap,
	          Properties::NON_VIRTUAL,
	          __C5_BufferAttachmentMap_R1__getBufferAttachmentMap,
	          "Get the const BufferAttachmentMap, used to configure frame buffer objects, pbuffers and texture reads. ",
	          "");
	I_Method0(void, createCameraThread,
	          Properties::NON_VIRTUAL,
	          __void__createCameraThread,
	          "Create a operation thread for this camera. ",
	          "");
	I_Method1(void, setCameraThread, IN, osg::OperationsThread *, gt,
	          Properties::NON_VIRTUAL,
	          __void__setCameraThread__OperationsThread_P1,
	          "Assign a operation thread to the camera. ",
	          "");
	I_Method0(osg::OperationsThread *, getCameraThread,
	          Properties::NON_VIRTUAL,
	          __OperationsThread_P1__getCameraThread,
	          "Get the operation thread assigned to this camera. ",
	          "");
	I_Method0(const osg::OperationsThread *, getCameraThread,
	          Properties::NON_VIRTUAL,
	          __C5_OperationsThread_P1__getCameraThread,
	          "Get the const operation thread assigned to this camera. ",
	          "");
	I_Method1(void, setGraphicsContext, IN, osg::GraphicsContext *, context,
	          Properties::NON_VIRTUAL,
	          __void__setGraphicsContext__GraphicsContext_P1,
	          "Set the GraphicsContext that provides the mechansim for managing the OpenGL graphics context associated with this camera. ",
	          "");
	I_Method0(osg::GraphicsContext *, getGraphicsContext,
	          Properties::NON_VIRTUAL,
	          __GraphicsContext_P1__getGraphicsContext,
	          "Get the GraphicsContext. ",
	          "");
	I_Method0(const osg::GraphicsContext *, getGraphicsContext,
	          Properties::NON_VIRTUAL,
	          __C5_GraphicsContext_P1__getGraphicsContext,
	          "Get the const GraphicsContext. ",
	          "");
	I_Method2(void, setRenderingCache, IN, unsigned int, contextID, IN, osg::Object *, rc,
	          Properties::NON_VIRTUAL,
	          __void__setRenderingCache__unsigned_int__osg_Object_P1,
	          "Set the Rendering object that is used to implement rendering of the subgraph. ",
	          "");
	I_Method1(osg::Object *, getRenderingCache, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __osg_Object_P1__getRenderingCache__unsigned_int,
	          "Get the Rendering object that is used to implement rendering of the subgraph. ",
	          "");
	I_Method1(const osg::Object *, getRenderingCache, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Object_P1__getRenderingCache__unsigned_int,
	          "Get the const Rendering object that is used to implement rendering of the subgraph. ",
	          "");
	I_Method1(void, setPreDrawCallback, IN, osg::Camera::DrawCallback *, cb,
	          Properties::NON_VIRTUAL,
	          __void__setPreDrawCallback__DrawCallback_P1,
	          "Set the pre draw callback for custom operations to be done before the drawing of the camera's subgraph has been completed. ",
	          "");
	I_Method0(osg::Camera::DrawCallback *, getPreDrawCallback,
	          Properties::NON_VIRTUAL,
	          __DrawCallback_P1__getPreDrawCallback,
	          "Get the pre draw callback. ",
	          "");
	I_Method0(const osg::Camera::DrawCallback *, getPreDrawCallback,
	          Properties::NON_VIRTUAL,
	          __C5_DrawCallback_P1__getPreDrawCallback,
	          "Get the const pre draw callback. ",
	          "");
	I_Method1(void, setPostDrawCallback, IN, osg::Camera::DrawCallback *, cb,
	          Properties::NON_VIRTUAL,
	          __void__setPostDrawCallback__DrawCallback_P1,
	          "Set the post draw callback for custom operations to be done after the drawing of the camera's subgraph has been completed. ",
	          "");
	I_Method0(osg::Camera::DrawCallback *, getPostDrawCallback,
	          Properties::NON_VIRTUAL,
	          __DrawCallback_P1__getPostDrawCallback,
	          "Get the post draw callback. ",
	          "");
	I_Method0(const osg::Camera::DrawCallback *, getPostDrawCallback,
	          Properties::NON_VIRTUAL,
	          __C5_DrawCallback_P1__getPostDrawCallback,
	          "Get the const post draw callback. ",
	          "");
	I_Method0(OpenThreads::Mutex *, getDataChangeMutex,
	          Properties::NON_VIRTUAL,
	          __OpenThreads_Mutex_P1__getDataChangeMutex,
	          "",
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
	I_Method2(bool, computeLocalToWorldMatrix, IN, osg::Matrix &, matrix, IN, osg::NodeVisitor *, x,
	          Properties::VIRTUAL,
	          __bool__computeLocalToWorldMatrix__Matrix_R1__NodeVisitor_P1,
	          "Transform method that must be defined to provide generic interface for scene graph traversals. ",
	          "");
	I_Method2(bool, computeWorldToLocalMatrix, IN, osg::Matrix &, matrix, IN, osg::NodeVisitor *, x,
	          Properties::VIRTUAL,
	          __bool__computeWorldToLocalMatrix__Matrix_R1__NodeVisitor_P1,
	          "Transform method that must be defined to provide generic interface for scene graph traversals. ",
	          "");
	I_SimpleProperty(bool, AllowEventFocus, 
	                 __bool__getAllowEventFocus, 
	                 __void__setAllowEventFocus__bool);
	I_SimpleProperty(osg::Camera::BufferAttachmentMap &, BufferAttachmentMap, 
	                 __BufferAttachmentMap_R1__getBufferAttachmentMap, 
	                 0);
	I_SimpleProperty(osg::OperationsThread *, CameraThread, 
	                 __OperationsThread_P1__getCameraThread, 
	                 __void__setCameraThread__OperationsThread_P1);
	I_SimpleProperty(const osg::Vec4 &, ClearColor, 
	                 __C5_Vec4_R1__getClearColor, 
	                 __void__setClearColor__C5_Vec4_R1);
	I_SimpleProperty(GLbitfield, ClearMask, 
	                 __GLbitfield__getClearMask, 
	                 __void__setClearMask__GLbitfield);
	I_SimpleProperty(osg::ColorMask *, ColorMask, 
	                 __ColorMask_P1__getColorMask, 
	                 __void__setColorMask__osg_ColorMask_P1);
	I_SimpleProperty(OpenThreads::Mutex *, DataChangeMutex, 
	                 __OpenThreads_Mutex_P1__getDataChangeMutex, 
	                 0);
	I_SimpleProperty(GLenum, DrawBuffer, 
	                 __GLenum__getDrawBuffer, 
	                 __void__setDrawBuffer__GLenum);
	I_SimpleProperty(osg::GraphicsContext *, GraphicsContext, 
	                 __GraphicsContext_P1__getGraphicsContext, 
	                 __void__setGraphicsContext__GraphicsContext_P1);
	I_SimpleProperty(osg::Matrixd, InverseViewMatrix, 
	                 __Matrixd__getInverseViewMatrix, 
	                 0);
	I_SimpleProperty(osg::Camera::DrawCallback *, PostDrawCallback, 
	                 __DrawCallback_P1__getPostDrawCallback, 
	                 __void__setPostDrawCallback__DrawCallback_P1);
	I_SimpleProperty(osg::Camera::DrawCallback *, PreDrawCallback, 
	                 __DrawCallback_P1__getPreDrawCallback, 
	                 __void__setPreDrawCallback__DrawCallback_P1);
	I_SimpleProperty(const osg::Matrixd &, ProjectionMatrix, 
	                 __C5_osg_Matrixd_R1__getProjectionMatrix, 
	                 __void__setProjectionMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(osg::Camera::ProjectionResizePolicy, ProjectionResizePolicy, 
	                 __ProjectionResizePolicy__getProjectionResizePolicy, 
	                 __void__setProjectionResizePolicy__ProjectionResizePolicy);
	I_SimpleProperty(GLenum, ReadBuffer, 
	                 __GLenum__getReadBuffer, 
	                 __void__setReadBuffer__GLenum);
	I_SimpleProperty(osg::Camera::RenderOrder, RenderOrder, 
	                 __RenderOrder__getRenderOrder, 
	                 0);
	I_SimpleProperty(int, RenderOrderNum, 
	                 __int__getRenderOrderNum, 
	                 0);
	I_SimpleProperty(osg::Camera::RenderTargetImplementation, RenderTargetFallback, 
	                 __RenderTargetImplementation__getRenderTargetFallback, 
	                 0);
	I_SimpleProperty(osg::Camera::RenderTargetImplementation, RenderTargetImplementation, 
	                 __RenderTargetImplementation__getRenderTargetImplementation, 
	                 __void__setRenderTargetImplementation__RenderTargetImplementation);
	I_IndexedProperty(osg::Object *, RenderingCache, 
	                  __osg_Object_P1__getRenderingCache__unsigned_int, 
	                  __void__setRenderingCache__unsigned_int__osg_Object_P1, 
	                  0);
	I_SimpleProperty(osg::Stats *, Stats, 
	                 __osg_Stats_P1__getStats, 
	                 __void__setStats__osg_Stats_P1);
	I_SimpleProperty(osg::Camera::TransformOrder, TransformOrder, 
	                 __TransformOrder__getTransformOrder, 
	                 __void__setTransformOrder__TransformOrder);
	I_SimpleProperty(osg::View *, View, 
	                 __View_P1__getView, 
	                 __void__setView__View_P1);
	I_SimpleProperty(const osg::Matrixd &, ViewMatrix, 
	                 __C5_osg_Matrixd_R1__getViewMatrix, 
	                 __void__setViewMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(osg::Viewport *, Viewport, 
	                 __Viewport_P1__getViewport, 
	                 __void__setViewport__osg_Viewport_P1);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::Camera::Attachment)
	I_DeclaringFile("osg/Camera");
	I_Constructor0(____Attachment,
	               "",
	               "");
	I_Method0(int, width,
	          Properties::NON_VIRTUAL,
	          __int__width,
	          "",
	          "");
	I_Method0(int, height,
	          Properties::NON_VIRTUAL,
	          __int__height,
	          "",
	          "");
	I_Method0(int, depth,
	          Properties::NON_VIRTUAL,
	          __int__depth,
	          "",
	          "");
	I_PublicMemberProperty(GLenum, _internalFormat);
	I_PublicMemberProperty(osg::ref_ptr< osg::Image >, _image);
	I_PublicMemberProperty(osg::ref_ptr< osg::Texture >, _texture);
	I_PublicMemberProperty(unsigned int, _level);
	I_PublicMemberProperty(unsigned int, _face);
	I_PublicMemberProperty(bool, _mipMapGeneration);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::Camera::DrawCallback)
	I_DeclaringFile("osg/Camera");
	I_VirtualBaseType(osg::Object);
	I_Constructor0(____DrawCallback,
	               "",
	               "");
	I_Constructor2(IN, const osg::Camera::DrawCallback &, x, IN, const osg::CopyOp &, x,
	               ____DrawCallback__C5_DrawCallback_R1__C5_CopyOp_R1,
	               "",
	               "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
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
END_REFLECTOR

STD_MAP_REFLECTOR(std::map< osg::Camera::BufferComponent COMMA  osg::Camera::Attachment >)

