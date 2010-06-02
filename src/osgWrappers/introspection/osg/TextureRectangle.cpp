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
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>
#include <osg/TextureRectangle>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

#include <osg/observer_ptr>
        
BEGIN_OBJECT_REFLECTOR(osg::TextureRectangle)
	I_DeclaringFile("osg/TextureRectangle");
	I_BaseType(osg::Texture);
	I_Constructor0(____TextureRectangle,
	               "",
	               "");
	I_Constructor1(IN, osg::Image *, image,
	               Properties::NON_EXPLICIT,
	               ____TextureRectangle__Image_P1,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::TextureRectangle &, text, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____TextureRectangle__C5_TextureRectangle_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an attribute, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, x,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an attribute, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "Return true if this and obj are of the same kind of object. ",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "Return the name of the attribute's library. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "Return the name of the attribute's class type. ",
	          "");
	I_Method0(osg::StateAttribute::Type, getType,
	          Properties::VIRTUAL,
	          __Type__getType,
	          "Return the Type identifier of the attribute's class type. ",
	          "");
	I_Method1(int, compare, IN, const osg::StateAttribute &, rhs,
	          Properties::VIRTUAL,
	          __int__compare__C5_StateAttribute_R1,
	          "Return -1 if *this < *rhs, 0 if *this==*rhs, 1 if *this>*rhs. ",
	          "");
	I_Method0(GLenum, getTextureTarget,
	          Properties::VIRTUAL,
	          __GLenum__getTextureTarget,
	          "",
	          "");
	I_Method1(void, setImage, IN, osg::Image *, image,
	          Properties::NON_VIRTUAL,
	          __void__setImage__Image_P1,
	          "Set the texture image. ",
	          "");
	I_Method0(osg::Image *, getImage,
	          Properties::NON_VIRTUAL,
	          __Image_P1__getImage,
	          "Get the texture image. ",
	          "");
	I_Method0(const osg::Image *, getImage,
	          Properties::NON_VIRTUAL,
	          __C5_Image_P1__getImage,
	          "Get the const texture image. ",
	          "");
	I_Method1(unsigned int &, getModifiedCount, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __unsigned_int_R1__getModifiedCount__unsigned_int,
	          "",
	          "");
	I_Method2(void, setImage, IN, unsigned, int, IN, osg::Image *, image,
	          Properties::VIRTUAL,
	          __void__setImage__unsigned__Image_P1,
	          "Set the texture image, ignoring face value as there is only one image. ",
	          "");
	I_Method1(osg::Image *, getImage, IN, unsigned, int,
	          Properties::VIRTUAL,
	          __Image_P1__getImage__unsigned,
	          "Get the texture image, ignoring face value as there is only one image. ",
	          "");
	I_Method1(const osg::Image *, getImage, IN, unsigned, int,
	          Properties::VIRTUAL,
	          __C5_Image_P1__getImage__unsigned,
	          "Get the const texture image, ignoring face value as there is only one image. ",
	          "");
	I_Method0(unsigned int, getNumImages,
	          Properties::VIRTUAL,
	          __unsigned_int__getNumImages,
	          "Get the number of images that can be assigned to the Texture. ",
	          "");
	I_Method2(void, setTextureSize, IN, int, width, IN, int, height,
	          Properties::NON_VIRTUAL,
	          __void__setTextureSize__int__int,
	          "Set the texture width and height. ",
	          "If width or height are zero then the respective size value is calculated from the source image sizes. ");
	I_Method1(void, setTextureWidth, IN, int, width,
	          Properties::NON_VIRTUAL,
	          __void__setTextureWidth__int,
	          "",
	          "");
	I_Method1(void, setTextureHeight, IN, int, height,
	          Properties::NON_VIRTUAL,
	          __void__setTextureHeight__int,
	          "",
	          "");
	I_Method0(int, getTextureWidth,
	          Properties::VIRTUAL,
	          __int__getTextureWidth,
	          "",
	          "");
	I_Method0(int, getTextureHeight,
	          Properties::VIRTUAL,
	          __int__getTextureHeight,
	          "",
	          "");
	I_Method0(int, getTextureDepth,
	          Properties::VIRTUAL,
	          __int__getTextureDepth,
	          "",
	          "");
	I_Method1(void, setSubloadCallback, IN, osg::TextureRectangle::SubloadCallback *, cb,
	          Properties::NON_VIRTUAL,
	          __void__setSubloadCallback__SubloadCallback_P1,
	          "",
	          "");
	I_Method0(osg::TextureRectangle::SubloadCallback *, getSubloadCallback,
	          Properties::NON_VIRTUAL,
	          __SubloadCallback_P1__getSubloadCallback,
	          "",
	          "");
	I_Method0(const osg::TextureRectangle::SubloadCallback *, getSubloadCallback,
	          Properties::NON_VIRTUAL,
	          __C5_SubloadCallback_P1__getSubloadCallback,
	          "",
	          "");
	I_Method5(void, copyTexImage2D, IN, osg::State &, state, IN, int, x, IN, int, y, IN, int, width, IN, int, height,
	          Properties::NON_VIRTUAL,
	          __void__copyTexImage2D__State_R1__int__int__int__int,
	          "Copies pixels into a 2D texture image, as per glCopyTexImage2D. ",
	          "Creates an OpenGL texture object from the current OpenGL background framebuffer contents at position x, y with width width and height height. width and height must be a power of two. ");
	I_Method7(void, copyTexSubImage2D, IN, osg::State &, state, IN, int, xoffset, IN, int, yoffset, IN, int, x, IN, int, y, IN, int, width, IN, int, height,
	          Properties::NON_VIRTUAL,
	          __void__copyTexSubImage2D__State_R1__int__int__int__int__int__int,
	          "Copies a two-dimensional texture subimage, as per glCopyTexSubImage2D. ",
	          "Updates a portion of an existing OpenGL texture object from the current OpenGL background framebuffer contents at position x, y with width width and height height. Loads framebuffer data into the texture using offsets xoffset and yoffset. width and height must be powers of two. ");
	I_Method1(void, apply, IN, osg::State &, state,
	          Properties::VIRTUAL,
	          __void__apply__State_R1,
	          "On first apply (unless already compiled), create and bind the texture, subsequent apply will simply bind to texture. ",
	          "");
	I_ProtectedMethod0(void, computeInternalFormat,
	                   Properties::VIRTUAL,
	                   Properties::CONST,
	                   __void__computeInternalFormat,
	                   "",
	                   "");
	I_ProtectedMethod1(void, allocateMipmap, IN, osg::State &, state,
	                   Properties::VIRTUAL,
	                   Properties::CONST,
	                   __void__allocateMipmap__State_R1,
	                   "Allocate mipmap levels of the texture by subsequent calling of glTexImage* function. ",
	                   "");
	I_ProtectedMethod5(void, applyTexImage_load, IN, GLenum, target, IN, osg::Image *, image, IN, osg::State &, state, IN, GLsizei &, inwidth, IN, GLsizei &, inheight,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__applyTexImage_load__GLenum__Image_P1__State_R1__GLsizei_R1__GLsizei_R1,
	                   "",
	                   "");
	I_ProtectedMethod6(void, applyTexImage_subload, IN, GLenum, target, IN, osg::Image *, image, IN, osg::State &, state, IN, GLsizei &, inwidth, IN, GLsizei &, inheight, IN, GLint &, inInternalFormat,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__applyTexImage_subload__GLenum__Image_P1__State_R1__GLsizei_R1__GLsizei_R1__GLint_R1,
	                   "",
	                   "");
	I_SimpleProperty(osg::Image *, Image, 
	                 __Image_P1__getImage, 
	                 __void__setImage__Image_P1);
	I_SimpleProperty(osg::TextureRectangle::SubloadCallback *, SubloadCallback, 
	                 __SubloadCallback_P1__getSubloadCallback, 
	                 __void__setSubloadCallback__SubloadCallback_P1);
	I_SimpleProperty(int, TextureDepth, 
	                 __int__getTextureDepth, 
	                 0);
	I_SimpleProperty(int, TextureHeight, 
	                 __int__getTextureHeight, 
	                 __void__setTextureHeight__int);
	I_SimpleProperty(GLenum, TextureTarget, 
	                 __GLenum__getTextureTarget, 
	                 0);
	I_SimpleProperty(int, TextureWidth, 
	                 __int__getTextureWidth, 
	                 __void__setTextureWidth__int);
	I_SimpleProperty(osg::StateAttribute::Type, Type, 
	                 __Type__getType, 
	                 0);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::TextureRectangle::SubloadCallback)
	I_DeclaringFile("osg/TextureRectangle");
	I_BaseType(osg::Referenced);
	I_Constructor0(____SubloadCallback,
	               "",
	               "");
	I_Method2(void, load, IN, const osg::TextureRectangle &, x, IN, osg::State &, x,
	          Properties::PURE_VIRTUAL,
	          __void__load__C5_TextureRectangle_R1__State_R1,
	          "",
	          "");
	I_Method2(void, subload, IN, const osg::TextureRectangle &, x, IN, osg::State &, x,
	          Properties::PURE_VIRTUAL,
	          __void__subload__C5_TextureRectangle_R1__State_R1,
	          "",
	          "");
END_REFLECTOR

