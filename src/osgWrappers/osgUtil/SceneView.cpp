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
#include <osg/CollectOccludersVisitor>
#include <osg/DisplaySettings>
#include <osg/FrameStamp>
#include <osg/Light>
#include <osg/Matrixd>
#include <osg/Matrixf>
#include <osg/Node>
#include <osg/NodeVisitor>
#include <osg/RenderInfo>
#include <osg/State>
#include <osg/StateSet>
#include <osg/Vec3>
#include <osg/Vec4>
#include <osg/View>
#include <osg/Viewport>
#include <osgUtil/CullVisitor>
#include <osgUtil/RenderStage>
#include <osgUtil/SceneView>
#include <osgUtil/StateGraph>
#include <osgUtil/Statistics>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(osgUtil::SceneView::Options, osgUtil::SceneView::LightingMode);

BEGIN_ENUM_REFLECTOR(osgUtil::SceneView::Options)
	I_EnumLabel(osgUtil::SceneView::NO_SCENEVIEW_LIGHT);
	I_EnumLabel(osgUtil::SceneView::HEADLIGHT);
	I_EnumLabel(osgUtil::SceneView::SKY_LIGHT);
	I_EnumLabel(osgUtil::SceneView::COMPILE_GLOBJECTS_AT_INIT);
	I_EnumLabel(osgUtil::SceneView::STANDARD_SETTINGS);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgUtil::SceneView::ActiveUniforms)
	I_EnumLabel(osgUtil::SceneView::FRAME_NUMBER_UNIFORM);
	I_EnumLabel(osgUtil::SceneView::FRAME_TIME_UNIFORM);
	I_EnumLabel(osgUtil::SceneView::DELTA_FRAME_TIME_UNIFORM);
	I_EnumLabel(osgUtil::SceneView::VIEW_MATRIX_UNIFORM);
	I_EnumLabel(osgUtil::SceneView::VIEW_MATRIX_INVERSE_UNIFORM);
	I_EnumLabel(osgUtil::SceneView::DEFAULT_UNIFORMS);
	I_EnumLabel(osgUtil::SceneView::ALL_UNIFORMS);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgUtil::SceneView::FusionDistanceMode)
	I_EnumLabel(osgUtil::SceneView::USE_FUSION_DISTANCE_VALUE);
	I_EnumLabel(osgUtil::SceneView::PROPORTIONAL_TO_SCREEN_DISTANCE);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::SceneView)
	I_BaseType(osg::Referenced);
	I_BaseType(osg::CullSettings);
	I_ConstructorWithDefaults1(IN, osg::DisplaySettings *, ds, NULL,
	                           ____SceneView__osg_DisplaySettings_P1,
	                           "Construct a default scene view. ",
	                           "");
	I_MethodWithDefaults1(void, setDefaults, IN, unsigned int, options, osgUtil::SceneView::STANDARD_SETTINGS,
	                      __void__setDefaults__unsigned_int,
	                      "Set scene view to use default global state, light, camera and render visitor. ",
	                      "");
	I_Method1(void, setCamera, IN, osg::CameraNode *, camera,
	          __void__setCamera__osg_CameraNode_P1,
	          "Set the camera used to represent the camera view of this SceneView. ",
	          "");
	I_Method0(osg::CameraNode *, getCamera,
	          __osg_CameraNode_P1__getCamera,
	          "Get the camera used to represent the camera view of this SceneView. ",
	          "");
	I_Method0(const osg::CameraNode *, getCamera,
	          __C5_osg_CameraNode_P1__getCamera,
	          "Get the const camera used to represent the camera view of this SceneView. ",
	          "");
	I_Method1(void, setSceneData, IN, osg::Node *, node,
	          __void__setSceneData__osg_Node_P1,
	          "Set the data to view. ",
	          "The data will typically be an osg::Scene but can be any osg::Node type.");
	I_MethodWithDefaults1(osg::Node *, getSceneData, IN, unsigned int, childNo, 0,
	                      __osg_Node_P1__getSceneData__unsigned_int,
	                      "Get the scene data to view. ",
	                      "The data will typically be an osg::Scene but can be any osg::Node type.");
	I_MethodWithDefaults1(const osg::Node *, getSceneData, IN, unsigned int, childNo, 0,
	                      __C5_osg_Node_P1__getSceneData__unsigned_int,
	                      "Get the const scene data which to view. ",
	                      "The data will typically be an osg::Scene but can be any osg::Node type.");
	I_Method0(unsigned int, getNumSceneData,
	          __unsigned_int__getNumSceneData,
	          "Get the number of scene data subgraphs added to the SceneView's camera. ",
	          "");
	I_Method1(void, setViewport, IN, osg::Viewport *, viewport,
	          __void__setViewport__osg_Viewport_P1,
	          "Set the viewport of the scene view to use specified osg::Viewport. ",
	          "");
	I_Method4(void, setViewport, IN, int, x, IN, int, y, IN, int, width, IN, int, height,
	          __void__setViewport__int__int__int__int,
	          "Set the viewport of the scene view to specified dimensions. ",
	          "");
	I_Method0(osg::Viewport *, getViewport,
	          __osg_Viewport_P1__getViewport,
	          "Get the viewport. ",
	          "");
	I_Method0(const osg::Viewport *, getViewport,
	          __C5_osg_Viewport_P1__getViewport,
	          "Get the const viewport. ",
	          "");
	I_Method4(void, getViewport, IN, int &, x, IN, int &, y, IN, int &, width, IN, int &, height,
	          __void__getViewport__int_R1__int_R1__int_R1__int_R1,
	          "Get the viewport of the scene view. ",
	          "");
	I_Method1(void, setDisplaySettings, IN, osg::DisplaySettings *, vs,
	          __void__setDisplaySettings__osg_DisplaySettings_P1,
	          "Set the DisplaySettings. ",
	          "");
	I_Method0(const osg::DisplaySettings *, getDisplaySettings,
	          __C5_osg_DisplaySettings_P1__getDisplaySettings,
	          "Get the const DisplaySettings. ",
	          "");
	I_Method0(osg::DisplaySettings *, getDisplaySettings,
	          __osg_DisplaySettings_P1__getDisplaySettings,
	          "Get the DisplaySettings. ",
	          "");
	I_Method1(void, setClearColor, IN, const osg::Vec4 &, color,
	          __void__setClearColor__C5_osg_Vec4_R1,
	          "Set the color used in glClearColor(). ",
	          "Defaults to an off blue color. ");
	I_Method0(const osg::Vec4 &, getClearColor,
	          __C5_osg_Vec4_R1__getClearColor,
	          "Get the color used in glClearColor. ",
	          "");
	I_Method1(void, setRedrawInterlacedStereoStencilMask, IN, bool, flag,
	          __void__setRedrawInterlacedStereoStencilMask__bool,
	          "Manually set the redraw interlaced stereo stencil mask request flag to control whether to redraw the stencil buffer on the next frame. ",
	          "");
	I_Method0(bool, getRedrawInterlacedStereoStencilMask,
	          __bool__getRedrawInterlacedStereoStencilMask,
	          "Get the redraw interlaced stereo stencil mask request flag. ",
	          "");
	I_Method1(void, setGlobalStateSet, IN, osg::StateSet *, state,
	          __void__setGlobalStateSet__osg_StateSet_P1,
	          "",
	          "");
	I_Method0(osg::StateSet *, getGlobalStateSet,
	          __osg_StateSet_P1__getGlobalStateSet,
	          "",
	          "");
	I_Method0(const osg::StateSet *, getGlobalStateSet,
	          __C5_osg_StateSet_P1__getGlobalStateSet,
	          "",
	          "");
	I_Method1(void, setLocalStateSet, IN, osg::StateSet *, state,
	          __void__setLocalStateSet__osg_StateSet_P1,
	          "",
	          "");
	I_Method0(osg::StateSet *, getLocalStateSet,
	          __osg_StateSet_P1__getLocalStateSet,
	          "",
	          "");
	I_Method0(const osg::StateSet *, getLocalStateSet,
	          __C5_osg_StateSet_P1__getLocalStateSet,
	          "",
	          "");
	I_Method1(void, setActiveUniforms, IN, int, activeUniforms,
	          __void__setActiveUniforms__int,
	          "Set the uniforms that SceneView should set set up on each frame. ",
	          "");
	I_Method0(int, getActiveUniforms,
	          __int__getActiveUniforms,
	          "Get the uniforms that SceneView should set set up on each frame. ",
	          "");
	I_Method0(void, updateUniforms,
	          __void__updateUniforms,
	          "",
	          "");
	I_Method1(void, setLightingMode, IN, osgUtil::SceneView::LightingMode, mode,
	          __void__setLightingMode__LightingMode,
	          "",
	          "");
	I_Method0(osgUtil::SceneView::LightingMode, getLightingMode,
	          __LightingMode__getLightingMode,
	          "",
	          "");
	I_Method1(void, setLight, IN, osg::Light *, light,
	          __void__setLight__osg_Light_P1,
	          "",
	          "");
	I_Method0(osg::Light *, getLight,
	          __osg_Light_P1__getLight,
	          "",
	          "");
	I_Method0(const osg::Light *, getLight,
	          __C5_osg_Light_P1__getLight,
	          "",
	          "");
	I_Method1(void, setState, IN, osg::State *, state,
	          __void__setState__osg_State_P1,
	          "",
	          "");
	I_Method0(osg::State *, getState,
	          __osg_State_P1__getState,
	          "",
	          "");
	I_Method0(const osg::State *, getState,
	          __C5_osg_State_P1__getState,
	          "",
	          "");
	I_Method1(void, setView, IN, osg::View *, view,
	          __void__setView__osg_View_P1,
	          "",
	          "");
	I_Method0(osg::View *, getView,
	          __osg_View_P1__getView,
	          "",
	          "");
	I_Method0(const osg::View *, getView,
	          __C5_osg_View_P1__getView,
	          "",
	          "");
	I_Method1(void, setRenderInfo, IN, osg::RenderInfo &, renderInfo,
	          __void__setRenderInfo__osg_RenderInfo_R1,
	          "",
	          "");
	I_Method0(osg::RenderInfo &, getRenderInfo,
	          __osg_RenderInfo_R1__getRenderInfo,
	          "",
	          "");
	I_Method0(const osg::RenderInfo &, getRenderInfo,
	          __C5_osg_RenderInfo_R1__getRenderInfo,
	          "",
	          "");
	I_Method1(void, setProjectionMatrix, IN, const osg::Matrixf &, matrix,
	          __void__setProjectionMatrix__C5_osg_Matrixf_R1,
	          "Set the projection matrix. ",
	          "Can be thought of as setting the lens of a camera. ");
	I_Method1(void, setProjectionMatrix, IN, const osg::Matrixd &, matrix,
	          __void__setProjectionMatrix__C5_osg_Matrixd_R1,
	          "Set the projection matrix. ",
	          "Can be thought of as setting the lens of a camera. ");
	I_Method6(void, setProjectionMatrixAsOrtho, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top, IN, double, zNear, IN, double, zFar,
	          __void__setProjectionMatrixAsOrtho__double__double__double__double__double__double,
	          "Set to an orthographic projection. ",
	          "See OpenGL glOrtho for documentation further details. ");
	I_Method4(void, setProjectionMatrixAsOrtho2D, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top,
	          __void__setProjectionMatrixAsOrtho2D__double__double__double__double,
	          "Set to a 2D orthographic projection. ",
	          "See OpenGL glOrtho2D documentation for further details. ");
	I_Method6(void, setProjectionMatrixAsFrustum, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top, IN, double, zNear, IN, double, zFar,
	          __void__setProjectionMatrixAsFrustum__double__double__double__double__double__double,
	          "Set to a perspective projection. ",
	          "See OpenGL glFrustum documentation for further details. ");
	I_Method4(void, setProjectionMatrixAsPerspective, IN, double, fovy, IN, double, aspectRatio, IN, double, zNear, IN, double, zFar,
	          __void__setProjectionMatrixAsPerspective__double__double__double__double,
	          "Create a symmetrical perspective projection, See OpenGL gluPerspective documentation for further details. ",
	          "Aspect ratio is defined as width/height. ");
	I_Method0(osg::Matrixd &, getProjectionMatrix,
	          __osg_Matrixd_R1__getProjectionMatrix,
	          "Get the projection matrix. ",
	          "");
	I_Method0(const osg::Matrixd &, getProjectionMatrix,
	          __C5_osg_Matrixd_R1__getProjectionMatrix,
	          "Get the const projection matrix. ",
	          "");
	I_Method6(bool, getProjectionMatrixAsOrtho, IN, double &, left, IN, double &, right, IN, double &, bottom, IN, double &, top, IN, double &, zNear, IN, double &, zFar,
	          __bool__getProjectionMatrixAsOrtho__double_R1__double_R1__double_R1__double_R1__double_R1__double_R1,
	          "Get the orthographic settings of the orthographic projection matrix. ",
	          "Returns false if matrix is not an orthographic matrix, where parameter values are undefined. ");
	I_Method6(bool, getProjectionMatrixAsFrustum, IN, double &, left, IN, double &, right, IN, double &, bottom, IN, double &, top, IN, double &, zNear, IN, double &, zFar,
	          __bool__getProjectionMatrixAsFrustum__double_R1__double_R1__double_R1__double_R1__double_R1__double_R1,
	          "Get the frustum setting of a perspective projection matrix. ",
	          "Returns false if matrix is not a perspective matrix, where parameter values are undefined. ");
	I_Method4(bool, getProjectionMatrixAsPerspective, IN, double &, fovy, IN, double &, aspectRatio, IN, double &, zNear, IN, double &, zFar,
	          __bool__getProjectionMatrixAsPerspective__double_R1__double_R1__double_R1__double_R1,
	          "Get the frustum setting of a symmetric perspective projection matrix. ",
	          "Returns false if matrix is not a perspective matrix, where parameter values are undefined. Note, if matrix is not a symmetric perspective matrix then the shear will be lost. Asymmetric matrices occur when stereo, power walls, caves and reality center display are used. In these configurations one should use the 'getProjectionMatrixAsFrustum' method instead. ");
	I_Method1(void, setViewMatrix, IN, const osg::Matrixf &, matrix,
	          __void__setViewMatrix__C5_osg_Matrixf_R1,
	          "Set the view matrix. ",
	          "Can be thought of as setting the position of the world relative to the camera in camera coordinates. ");
	I_Method1(void, setViewMatrix, IN, const osg::Matrixd &, matrix,
	          __void__setViewMatrix__C5_osg_Matrixd_R1,
	          "Set the view matrix. ",
	          "Can be thought of as setting the position of the world relative to the camera in camera coordinates. ");
	I_Method3(void, setViewMatrixAsLookAt, IN, const osg::Vec3 &, eye, IN, const osg::Vec3 &, center, IN, const osg::Vec3 &, up,
	          __void__setViewMatrixAsLookAt__C5_osg_Vec3_R1__C5_osg_Vec3_R1__C5_osg_Vec3_R1,
	          "Set to the position and orientation of view matrix, using the same convention as gluLookAt. ",
	          "");
	I_Method0(osg::Matrixd &, getViewMatrix,
	          __osg_Matrixd_R1__getViewMatrix,
	          "Get the view matrix. ",
	          "");
	I_Method0(const osg::Matrixd &, getViewMatrix,
	          __C5_osg_Matrixd_R1__getViewMatrix,
	          "Get the const view matrix. ",
	          "");
	I_MethodWithDefaults4(void, getViewMatrixAsLookAt, IN, osg::Vec3 &, eye, , IN, osg::Vec3 &, center, , IN, osg::Vec3 &, up, , IN, float, lookDistance, 1.0f,
	                      __void__getViewMatrixAsLookAt__osg_Vec3_R1__osg_Vec3_R1__osg_Vec3_R1__float,
	                      "Get to the position and orientation of a modelview matrix, using the same convention as gluLookAt. ",
	                      "");
	I_Method1(void, setInitVisitor, IN, osg::NodeVisitor *, av,
	          __void__setInitVisitor__osg_NodeVisitor_P1,
	          "",
	          "");
	I_Method0(osg::NodeVisitor *, getInitVisitor,
	          __osg_NodeVisitor_P1__getInitVisitor,
	          "",
	          "");
	I_Method0(const osg::NodeVisitor *, getInitVisitor,
	          __C5_osg_NodeVisitor_P1__getInitVisitor,
	          "",
	          "");
	I_Method1(void, setUpdateVisitor, IN, osg::NodeVisitor *, av,
	          __void__setUpdateVisitor__osg_NodeVisitor_P1,
	          "",
	          "");
	I_Method0(osg::NodeVisitor *, getUpdateVisitor,
	          __osg_NodeVisitor_P1__getUpdateVisitor,
	          "",
	          "");
	I_Method0(const osg::NodeVisitor *, getUpdateVisitor,
	          __C5_osg_NodeVisitor_P1__getUpdateVisitor,
	          "",
	          "");
	I_Method1(void, setCullVisitor, IN, osgUtil::CullVisitor *, cv,
	          __void__setCullVisitor__osgUtil_CullVisitor_P1,
	          "",
	          "");
	I_Method0(osgUtil::CullVisitor *, getCullVisitor,
	          __osgUtil_CullVisitor_P1__getCullVisitor,
	          "",
	          "");
	I_Method0(const osgUtil::CullVisitor *, getCullVisitor,
	          __C5_osgUtil_CullVisitor_P1__getCullVisitor,
	          "",
	          "");
	I_Method1(void, setCullVisitorLeft, IN, osgUtil::CullVisitor *, cv,
	          __void__setCullVisitorLeft__osgUtil_CullVisitor_P1,
	          "",
	          "");
	I_Method0(osgUtil::CullVisitor *, getCullVisitorLeft,
	          __osgUtil_CullVisitor_P1__getCullVisitorLeft,
	          "",
	          "");
	I_Method0(const osgUtil::CullVisitor *, getCullVisitorLeft,
	          __C5_osgUtil_CullVisitor_P1__getCullVisitorLeft,
	          "",
	          "");
	I_Method1(void, setCullVisitorRight, IN, osgUtil::CullVisitor *, cv,
	          __void__setCullVisitorRight__osgUtil_CullVisitor_P1,
	          "",
	          "");
	I_Method0(osgUtil::CullVisitor *, getCullVisitorRight,
	          __osgUtil_CullVisitor_P1__getCullVisitorRight,
	          "",
	          "");
	I_Method0(const osgUtil::CullVisitor *, getCullVisitorRight,
	          __C5_osgUtil_CullVisitor_P1__getCullVisitorRight,
	          "",
	          "");
	I_Method1(void, setCollectOccludersVisitor, IN, osg::CollectOccludersVisitor *, cov,
	          __void__setCollectOccludersVisitor__osg_CollectOccludersVisitor_P1,
	          "",
	          "");
	I_Method0(osg::CollectOccludersVisitor *, getCollectOccludersVisitor,
	          __osg_CollectOccludersVisitor_P1__getCollectOccludersVisitor,
	          "",
	          "");
	I_Method0(const osg::CollectOccludersVisitor *, getCollectOccludersVisitor,
	          __C5_osg_CollectOccludersVisitor_P1__getCollectOccludersVisitor,
	          "",
	          "");
	I_Method1(void, setStateGraph, IN, osgUtil::StateGraph *, rg,
	          __void__setStateGraph__osgUtil_StateGraph_P1,
	          "",
	          "");
	I_Method0(osgUtil::StateGraph *, getStateGraph,
	          __osgUtil_StateGraph_P1__getStateGraph,
	          "",
	          "");
	I_Method0(const osgUtil::StateGraph *, getStateGraph,
	          __C5_osgUtil_StateGraph_P1__getStateGraph,
	          "",
	          "");
	I_Method1(void, setStateGraphLeft, IN, osgUtil::StateGraph *, rg,
	          __void__setStateGraphLeft__osgUtil_StateGraph_P1,
	          "",
	          "");
	I_Method0(osgUtil::StateGraph *, getStateGraphLeft,
	          __osgUtil_StateGraph_P1__getStateGraphLeft,
	          "",
	          "");
	I_Method0(const osgUtil::StateGraph *, getStateGraphLeft,
	          __C5_osgUtil_StateGraph_P1__getStateGraphLeft,
	          "",
	          "");
	I_Method1(void, setStateGraphRight, IN, osgUtil::StateGraph *, rg,
	          __void__setStateGraphRight__osgUtil_StateGraph_P1,
	          "",
	          "");
	I_Method0(osgUtil::StateGraph *, getStateGraphRight,
	          __osgUtil_StateGraph_P1__getStateGraphRight,
	          "",
	          "");
	I_Method0(const osgUtil::StateGraph *, getStateGraphRight,
	          __C5_osgUtil_StateGraph_P1__getStateGraphRight,
	          "",
	          "");
	I_Method1(void, setRenderStage, IN, osgUtil::RenderStage *, rs,
	          __void__setRenderStage__osgUtil_RenderStage_P1,
	          "",
	          "");
	I_Method0(osgUtil::RenderStage *, getRenderStage,
	          __osgUtil_RenderStage_P1__getRenderStage,
	          "",
	          "");
	I_Method0(const osgUtil::RenderStage *, getRenderStage,
	          __C5_osgUtil_RenderStage_P1__getRenderStage,
	          "",
	          "");
	I_Method1(void, setRenderStageLeft, IN, osgUtil::RenderStage *, rs,
	          __void__setRenderStageLeft__osgUtil_RenderStage_P1,
	          "",
	          "");
	I_Method0(osgUtil::RenderStage *, getRenderStageLeft,
	          __osgUtil_RenderStage_P1__getRenderStageLeft,
	          "",
	          "");
	I_Method0(const osgUtil::RenderStage *, getRenderStageLeft,
	          __C5_osgUtil_RenderStage_P1__getRenderStageLeft,
	          "",
	          "");
	I_Method1(void, setRenderStageRight, IN, osgUtil::RenderStage *, rs,
	          __void__setRenderStageRight__osgUtil_RenderStage_P1,
	          "",
	          "");
	I_Method0(osgUtil::RenderStage *, getRenderStageRight,
	          __osgUtil_RenderStage_P1__getRenderStageRight,
	          "",
	          "");
	I_Method0(const osgUtil::RenderStage *, getRenderStageRight,
	          __C5_osgUtil_RenderStage_P1__getRenderStageRight,
	          "",
	          "");
	I_Method1(void, setDrawBufferValue, IN, GLenum, drawBufferValue,
	          __void__setDrawBufferValue__GLenum,
	          "Set the draw buffer value used at the start of each frame draw. ",
	          "Note, overridden in quad buffer stereo mode ");
	I_Method0(GLenum, getDrawBufferValue,
	          __GLenum__getDrawBufferValue,
	          "Get the draw buffer value used at the start of each frame draw. ",
	          "");
	I_MethodWithDefaults2(void, setFusionDistance, IN, osgUtil::SceneView::FusionDistanceMode, mode, , IN, float, value, 1.0f,
	                      __void__setFusionDistance__FusionDistanceMode__float,
	                      "Set the FusionDistanceMode and Value. ",
	                      "Note, is used only when working in stereo. ");
	I_Method0(osgUtil::SceneView::FusionDistanceMode, getFusionDistanceMode,
	          __FusionDistanceMode__getFusionDistanceMode,
	          "Get the FusionDistanceMode. ",
	          "");
	I_Method0(float, getFusionDistanceValue,
	          __float__getFusionDistanceValue,
	          "Get the FusionDistanceValue. ",
	          "Note, only used for USE_FUSION_DISTANCE_VALUE & PROPORTIONAL_TO_SCREEN_DISTANCE modes. ");
	I_Method1(void, setPrioritizeTextures, IN, bool, pt,
	          __void__setPrioritizeTextures__bool,
	          "Set whether the draw method should call renderer->prioritizeTexture. ",
	          "");
	I_Method0(bool, getPrioritizeTextures,
	          __bool__getPrioritizeTextures,
	          "Get whether the draw method should call renderer->prioritizeTexture. ",
	          "");
	I_Method1(void, setComputeStereoMatricesCallback, IN, osgUtil::SceneView::ComputeStereoMatricesCallback *, callback,
	          __void__setComputeStereoMatricesCallback__ComputeStereoMatricesCallback_P1,
	          "",
	          "");
	I_Method0(osgUtil::SceneView::ComputeStereoMatricesCallback *, getComputeStereoMatricesCallback,
	          __ComputeStereoMatricesCallback_P1__getComputeStereoMatricesCallback,
	          "",
	          "");
	I_Method0(const osgUtil::SceneView::ComputeStereoMatricesCallback *, getComputeStereoMatricesCallback,
	          __C5_ComputeStereoMatricesCallback_P1__getComputeStereoMatricesCallback,
	          "",
	          "");
	I_Method2(bool, projectWindowIntoObject, IN, const osg::Vec3 &, window, IN, osg::Vec3 &, object,
	          __bool__projectWindowIntoObject__C5_osg_Vec3_R1__osg_Vec3_R1,
	          "Calculate the object coordinates of a point in window coordinates. ",
	          "Note, current implementation requires that SceneView::draw() has been previously called for projectWindowIntoObject to produce valid values. Consistent with OpenGL windows coordinates are calculated relative to the bottom left of the window. Returns true on successful projection.");
	I_Method4(bool, projectWindowXYIntoObject, IN, int, x, IN, int, y, IN, osg::Vec3 &, near_point, IN, osg::Vec3 &, far_point,
	          __bool__projectWindowXYIntoObject__int__int__osg_Vec3_R1__osg_Vec3_R1,
	          "Calculate the object coordinates of a window x,y when projected onto the near and far planes. ",
	          "Note, current implementation requires that SceneView::draw() has been previously called for projectWindowIntoObject to produce valid values. Consistent with OpenGL windows coordinates are calculated relative to the bottom left of the window. Returns true on successful projection.");
	I_Method2(bool, projectObjectIntoWindow, IN, const osg::Vec3 &, object, IN, osg::Vec3 &, window,
	          __bool__projectObjectIntoWindow__C5_osg_Vec3_R1__osg_Vec3_R1,
	          "Calculate the window coordinates of a point in object coordinates. ",
	          "Note, current implementation requires that SceneView::draw() has been previously called for projectWindowIntoObject to produce valid values. Consistent with OpenGL windows coordinates are calculated relative to the bottom left of the window, whereas window API's normally have the top left as the origin, so you may need to pass in (mouseX,window_height-mouseY,...). Returns true on successful projection.");
	I_Method1(void, setFrameStamp, IN, osg::FrameStamp *, fs,
	          __void__setFrameStamp__osg_FrameStamp_P1,
	          "Set the frame stamp for the current frame. ",
	          "");
	I_Method0(const osg::FrameStamp *, getFrameStamp,
	          __C5_osg_FrameStamp_P1__getFrameStamp,
	          "Get the frame stamp for the current frame. ",
	          "");
	I_Method1(osg::Matrixd, computeLeftEyeProjection, IN, const osg::Matrixd &, projection,
	          __osg_Matrixd__computeLeftEyeProjection__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method1(osg::Matrixd, computeLeftEyeView, IN, const osg::Matrixd &, view,
	          __osg_Matrixd__computeLeftEyeView__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method1(osg::Matrixd, computeRightEyeProjection, IN, const osg::Matrixd &, projection,
	          __osg_Matrixd__computeRightEyeProjection__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method1(osg::Matrixd, computeRightEyeView, IN, const osg::Matrixd &, view,
	          __osg_Matrixd__computeRightEyeView__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method1(osg::Matrixd, computeLeftEyeProjectionImplementation, IN, const osg::Matrixd &, projection,
	          __osg_Matrixd__computeLeftEyeProjectionImplementation__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method1(osg::Matrixd, computeLeftEyeViewImplementation, IN, const osg::Matrixd &, view,
	          __osg_Matrixd__computeLeftEyeViewImplementation__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method1(osg::Matrixd, computeRightEyeProjectionImplementation, IN, const osg::Matrixd &, projection,
	          __osg_Matrixd__computeRightEyeProjectionImplementation__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method1(osg::Matrixd, computeRightEyeViewImplementation, IN, const osg::Matrixd &, view,
	          __osg_Matrixd__computeRightEyeViewImplementation__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method0(void, init,
	          __void__init,
	          "Do init traversal of attached scene graph using Init NodeVisitor. ",
	          "The init traversal is called once for each SceneView, and should be used to compile display list, texture objects intialize data not otherwise intialized during scene graph loading. Note, is called automatically by update & cull if it hasn't already been called elsewhere. Also init() should only ever be called within a valid graphics context. ");
	I_Method0(void, update,
	          __void__update,
	          "Do app traversal of attached scene graph using App NodeVisitor. ",
	          "");
	I_Method0(void, cull,
	          __void__cull,
	          "Do cull traversal of attached scene graph using Cull NodeVisitor. ",
	          "");
	I_Method0(void, draw,
	          __void__draw,
	          "Do draw traversal of draw bins generated by cull traversal. ",
	          "");
	I_Method0(void, releaseAllGLObjects,
	          __void__releaseAllGLObjects,
	          "Release all OpenGL objects from the scene graph, such as texture objects, display lists etc. ",
	          "These released scene graphs placed in the respective delete GLObjects cache, which then need to be deleted in OpenGL by SceneView::flushAllDeleteGLObjects(). ");
	I_Method0(void, flushAllDeletedGLObjects,
	          __void__flushAllDeletedGLObjects,
	          "Flush all deleted OpenGL objects, such as texture objects, display lists etc. ",
	          "");
	I_Method1(void, flushDeletedGLObjects, IN, double &, availableTime,
	          __void__flushDeletedGLObjects__double_R1,
	          "Flush deleted OpenGL objects, such as texture objects, display lists etc within specified available time. ",
	          "");
	I_Method1(bool, getStats, IN, osgUtil::Statistics &, primStats,
	          __bool__getStats__Statistics_R1,
	          "Extract stats for current draw list. ",
	          "");
	I_SimpleProperty(int, ActiveUniforms, 
	                 __int__getActiveUniforms, 
	                 __void__setActiveUniforms__int);
	I_SimpleProperty(osg::CameraNode *, Camera, 
	                 __osg_CameraNode_P1__getCamera, 
	                 __void__setCamera__osg_CameraNode_P1);
	I_SimpleProperty(const osg::Vec4 &, ClearColor, 
	                 __C5_osg_Vec4_R1__getClearColor, 
	                 __void__setClearColor__C5_osg_Vec4_R1);
	I_SimpleProperty(osg::CollectOccludersVisitor *, CollectOccludersVisitor, 
	                 __osg_CollectOccludersVisitor_P1__getCollectOccludersVisitor, 
	                 __void__setCollectOccludersVisitor__osg_CollectOccludersVisitor_P1);
	I_SimpleProperty(osgUtil::SceneView::ComputeStereoMatricesCallback *, ComputeStereoMatricesCallback, 
	                 __ComputeStereoMatricesCallback_P1__getComputeStereoMatricesCallback, 
	                 __void__setComputeStereoMatricesCallback__ComputeStereoMatricesCallback_P1);
	I_SimpleProperty(osgUtil::CullVisitor *, CullVisitor, 
	                 __osgUtil_CullVisitor_P1__getCullVisitor, 
	                 __void__setCullVisitor__osgUtil_CullVisitor_P1);
	I_SimpleProperty(osgUtil::CullVisitor *, CullVisitorLeft, 
	                 __osgUtil_CullVisitor_P1__getCullVisitorLeft, 
	                 __void__setCullVisitorLeft__osgUtil_CullVisitor_P1);
	I_SimpleProperty(osgUtil::CullVisitor *, CullVisitorRight, 
	                 __osgUtil_CullVisitor_P1__getCullVisitorRight, 
	                 __void__setCullVisitorRight__osgUtil_CullVisitor_P1);
	I_SimpleProperty(unsigned int, Defaults, 
	                 0, 
	                 __void__setDefaults__unsigned_int);
	I_SimpleProperty(osg::DisplaySettings *, DisplaySettings, 
	                 __osg_DisplaySettings_P1__getDisplaySettings, 
	                 __void__setDisplaySettings__osg_DisplaySettings_P1);
	I_SimpleProperty(GLenum, DrawBufferValue, 
	                 __GLenum__getDrawBufferValue, 
	                 __void__setDrawBufferValue__GLenum);
	I_SimpleProperty(osg::FrameStamp *, FrameStamp, 
	                 0, 
	                 __void__setFrameStamp__osg_FrameStamp_P1);
	I_SimpleProperty(osgUtil::SceneView::FusionDistanceMode, FusionDistanceMode, 
	                 __FusionDistanceMode__getFusionDistanceMode, 
	                 0);
	I_SimpleProperty(float, FusionDistanceValue, 
	                 __float__getFusionDistanceValue, 
	                 0);
	I_SimpleProperty(osg::StateSet *, GlobalStateSet, 
	                 __osg_StateSet_P1__getGlobalStateSet, 
	                 __void__setGlobalStateSet__osg_StateSet_P1);
	I_SimpleProperty(osg::NodeVisitor *, InitVisitor, 
	                 __osg_NodeVisitor_P1__getInitVisitor, 
	                 __void__setInitVisitor__osg_NodeVisitor_P1);
	I_SimpleProperty(osg::Light *, Light, 
	                 __osg_Light_P1__getLight, 
	                 __void__setLight__osg_Light_P1);
	I_SimpleProperty(osgUtil::SceneView::LightingMode, LightingMode, 
	                 __LightingMode__getLightingMode, 
	                 __void__setLightingMode__LightingMode);
	I_SimpleProperty(osg::StateSet *, LocalStateSet, 
	                 __osg_StateSet_P1__getLocalStateSet, 
	                 __void__setLocalStateSet__osg_StateSet_P1);
	I_SimpleProperty(bool, PrioritizeTextures, 
	                 __bool__getPrioritizeTextures, 
	                 __void__setPrioritizeTextures__bool);
	I_SimpleProperty(const osg::Matrixd &, ProjectionMatrix, 
	                 __C5_osg_Matrixd_R1__getProjectionMatrix, 
	                 __void__setProjectionMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(bool, RedrawInterlacedStereoStencilMask, 
	                 __bool__getRedrawInterlacedStereoStencilMask, 
	                 __void__setRedrawInterlacedStereoStencilMask__bool);
	I_SimpleProperty(osg::RenderInfo &, RenderInfo, 
	                 __osg_RenderInfo_R1__getRenderInfo, 
	                 __void__setRenderInfo__osg_RenderInfo_R1);
	I_SimpleProperty(osgUtil::RenderStage *, RenderStage, 
	                 __osgUtil_RenderStage_P1__getRenderStage, 
	                 __void__setRenderStage__osgUtil_RenderStage_P1);
	I_SimpleProperty(osgUtil::RenderStage *, RenderStageLeft, 
	                 __osgUtil_RenderStage_P1__getRenderStageLeft, 
	                 __void__setRenderStageLeft__osgUtil_RenderStage_P1);
	I_SimpleProperty(osgUtil::RenderStage *, RenderStageRight, 
	                 __osgUtil_RenderStage_P1__getRenderStageRight, 
	                 __void__setRenderStageRight__osgUtil_RenderStage_P1);
	I_ArrayProperty(const osg::Node *, SceneData, 
	                __C5_osg_Node_P1__getSceneData__unsigned_int, 
	                0, 
	                __unsigned_int__getNumSceneData, 
	                0, 
	                0, 
	                0);
	I_SimpleProperty(osg::State *, State, 
	                 __osg_State_P1__getState, 
	                 __void__setState__osg_State_P1);
	I_SimpleProperty(osgUtil::StateGraph *, StateGraph, 
	                 __osgUtil_StateGraph_P1__getStateGraph, 
	                 __void__setStateGraph__osgUtil_StateGraph_P1);
	I_SimpleProperty(osgUtil::StateGraph *, StateGraphLeft, 
	                 __osgUtil_StateGraph_P1__getStateGraphLeft, 
	                 __void__setStateGraphLeft__osgUtil_StateGraph_P1);
	I_SimpleProperty(osgUtil::StateGraph *, StateGraphRight, 
	                 __osgUtil_StateGraph_P1__getStateGraphRight, 
	                 __void__setStateGraphRight__osgUtil_StateGraph_P1);
	I_SimpleProperty(osg::NodeVisitor *, UpdateVisitor, 
	                 __osg_NodeVisitor_P1__getUpdateVisitor, 
	                 __void__setUpdateVisitor__osg_NodeVisitor_P1);
	I_SimpleProperty(osg::View *, View, 
	                 __osg_View_P1__getView, 
	                 __void__setView__osg_View_P1);
	I_SimpleProperty(const osg::Matrixd &, ViewMatrix, 
	                 __C5_osg_Matrixd_R1__getViewMatrix, 
	                 __void__setViewMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(osg::Viewport *, Viewport, 
	                 __osg_Viewport_P1__getViewport, 
	                 __void__setViewport__osg_Viewport_P1);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgUtil::SceneView::ComputeStereoMatricesCallback)
	I_BaseType(osg::Referenced);
	I_Constructor0(____ComputeStereoMatricesCallback,
	               "",
	               "");
	I_Method1(osg::Matrixd, computeLeftEyeProjection, IN, const osg::Matrixd &, projection,
	          __osg_Matrixd__computeLeftEyeProjection__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method1(osg::Matrixd, computeLeftEyeView, IN, const osg::Matrixd &, view,
	          __osg_Matrixd__computeLeftEyeView__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method1(osg::Matrixd, computeRightEyeProjection, IN, const osg::Matrixd &, projection,
	          __osg_Matrixd__computeRightEyeProjection__C5_osg_Matrixd_R1,
	          "",
	          "");
	I_Method1(osg::Matrixd, computeRightEyeView, IN, const osg::Matrixd &, view,
	          __osg_Matrixd__computeRightEyeView__C5_osg_Matrixd_R1,
	          "",
	          "");
END_REFLECTOR

