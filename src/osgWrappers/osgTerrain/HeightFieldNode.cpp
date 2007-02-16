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
#include <osg/Image>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/Shape>
#include <osgTerrain/HeightFieldNode>
#include <osgTerrain/HeightFieldRenderer>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgTerrain::HeightFieldNode)
	I_BaseType(osg::Group);
	I_Constructor0(____HeightFieldNode,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgTerrain::HeightFieldNode &, x, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____HeightFieldNode__C5_HeightFieldNode_R1__C5_osg_CopyOp_R1,
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
	I_Method1(void, traverse, IN, osg::NodeVisitor &, nv,
	          Properties::VIRTUAL,
	          __void__traverse__osg_NodeVisitor_R1,
	          "Traverse downwards : calls children's accept method with NodeVisitor. ",
	          "");
	I_Method1(void, setHeightField, IN, osg::HeightField *, heightField,
	          Properties::NON_VIRTUAL,
	          __void__setHeightField__osg_HeightField_P1,
	          "Set the HeightField for this HeightFieldNode. ",
	          "If a Renderer is attached then this will be notified. ");
	I_Method0(osg::HeightField *, getHeightField,
	          Properties::NON_VIRTUAL,
	          __osg_HeightField_P1__getHeightField,
	          "Get the HeightField. ",
	          "");
	I_Method0(const osg::HeightField *, getHeightField,
	          Properties::NON_VIRTUAL,
	          __C5_osg_HeightField_P1__getHeightField,
	          "Get the const HeightField. ",
	          "");
	I_Method0(void, heightFieldHasBeenModified,
	          Properties::NON_VIRTUAL,
	          __void__heightFieldHasBeenModified,
	          "Tell the Renderer that the height field has been modified, so that any cached data will need updating. ",
	          "");
	I_Method1(void, setRenderer, IN, osgTerrain::HeightFieldRenderer *, renderer,
	          Properties::NON_VIRTUAL,
	          __void__setRenderer__osgTerrain_HeightFieldRenderer_P1,
	          "Set the Renderer. ",
	          "");
	I_Method0(osgTerrain::HeightFieldRenderer *, getRenderer,
	          Properties::NON_VIRTUAL,
	          __HeightFieldRenderer_P1__getRenderer,
	          "Get the Renderer. ",
	          "");
	I_Method0(const osgTerrain::HeightFieldRenderer *, getRenderer,
	          Properties::NON_VIRTUAL,
	          __C5_HeightFieldRenderer_P1__getRenderer,
	          "Get the const Renderer. ",
	          "");
	I_Method1(void, setBaseTextureImage, IN, osg::Image *, image,
	          Properties::NON_VIRTUAL,
	          __void__setBaseTextureImage__osg_Image_P1,
	          "",
	          "");
	I_Method0(osg::Image *, getBaseTextureImage,
	          Properties::NON_VIRTUAL,
	          __osg_Image_P1__getBaseTextureImage,
	          "",
	          "");
	I_Method0(const osg::Image *, getBaseTextureImage,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Image_P1__getBaseTextureImage,
	          "",
	          "");
	I_Method1(void, setDetailTextureImage, IN, osg::Image *, image,
	          Properties::NON_VIRTUAL,
	          __void__setDetailTextureImage__osg_Image_P1,
	          "",
	          "");
	I_Method0(osg::Image *, getDetailTextureImage,
	          Properties::NON_VIRTUAL,
	          __osg_Image_P1__getDetailTextureImage,
	          "",
	          "");
	I_Method0(const osg::Image *, getDetailTextureImage,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Image_P1__getDetailTextureImage,
	          "",
	          "");
	I_Method1(void, setCloudShadowTextureImage, IN, osg::Image *, image,
	          Properties::NON_VIRTUAL,
	          __void__setCloudShadowTextureImage__osg_Image_P1,
	          "",
	          "");
	I_Method0(osg::Image *, getCloudShadowTextureImage,
	          Properties::NON_VIRTUAL,
	          __osg_Image_P1__getCloudShadowTextureImage,
	          "",
	          "");
	I_Method0(const osg::Image *, getCloudShadowTextureImage,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Image_P1__getCloudShadowTextureImage,
	          "",
	          "");
	I_Method1(void, setNormalMapImage, IN, osg::Image *, image,
	          Properties::NON_VIRTUAL,
	          __void__setNormalMapImage__osg_Image_P1,
	          "",
	          "");
	I_Method0(osg::Image *, getNormalMapImage,
	          Properties::NON_VIRTUAL,
	          __osg_Image_P1__getNormalMapImage,
	          "",
	          "");
	I_Method0(const osg::Image *, getNormalMapImage,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Image_P1__getNormalMapImage,
	          "",
	          "");
	I_Method0(void, computeNormalMap,
	          Properties::NON_VIRTUAL,
	          __void__computeNormalMap,
	          "",
	          "");
	I_SimpleProperty(osg::Image *, BaseTextureImage, 
	                 __osg_Image_P1__getBaseTextureImage, 
	                 __void__setBaseTextureImage__osg_Image_P1);
	I_SimpleProperty(osg::Image *, CloudShadowTextureImage, 
	                 __osg_Image_P1__getCloudShadowTextureImage, 
	                 __void__setCloudShadowTextureImage__osg_Image_P1);
	I_SimpleProperty(osg::Image *, DetailTextureImage, 
	                 __osg_Image_P1__getDetailTextureImage, 
	                 __void__setDetailTextureImage__osg_Image_P1);
	I_SimpleProperty(osg::HeightField *, HeightField, 
	                 __osg_HeightField_P1__getHeightField, 
	                 __void__setHeightField__osg_HeightField_P1);
	I_SimpleProperty(osg::Image *, NormalMapImage, 
	                 __osg_Image_P1__getNormalMapImage, 
	                 __void__setNormalMapImage__osg_Image_P1);
	I_SimpleProperty(osgTerrain::HeightFieldRenderer *, Renderer, 
	                 __HeightFieldRenderer_P1__getRenderer, 
	                 __void__setRenderer__osgTerrain_HeightFieldRenderer_P1);
END_REFLECTOR

