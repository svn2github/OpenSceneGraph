// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/CameraNode>
#include <osg/CopyOp>
#include <osg/FrameBufferObject>
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>
#include <osg/Texture1D>
#include <osg/Texture2D>
#include <osg/Texture3D>
#include <osg/TextureCubeMap>
#include <osg/TextureRectangle>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglBindRenderbufferEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglDeleteRenderbuffersEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglGenRenderbuffersEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglRenderbufferStorageEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglBindFramebufferEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglDeleteFramebuffersEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglGenFramebuffersEXT);

TYPE_NAME_ALIAS(GLenum , osg::FBOExtensions::TglCheckFramebufferStatusEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglFramebufferTexture1DEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglFramebufferTexture2DEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglFramebufferTexture3DEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglFramebufferRenderbufferEXT);

TYPE_NAME_ALIAS(void , osg::FBOExtensions::TglGenerateMipmapEXT);

BEGIN_OBJECT_REFLECTOR(osg::FBOExtensions)
	I_BaseType(osg::Referenced);
	I_Method0(bool, isSupported);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::FrameBufferAttachment)
	I_Constructor0();
	I_Constructor1(IN, const osg::FrameBufferAttachment &, copy);
	I_Constructor1(IN, osg::RenderBuffer *, target);
	I_ConstructorWithDefaults2(IN, osg::Texture1D *, target, , IN, int, level, 0);
	I_ConstructorWithDefaults2(IN, osg::Texture2D *, target, , IN, int, level, 0);
	I_ConstructorWithDefaults3(IN, osg::Texture3D *, target, , IN, int, zoffset, , IN, int, level, 0);
	I_ConstructorWithDefaults3(IN, osg::TextureCubeMap *, target, , IN, int, face, , IN, int, level, 0);
	I_Constructor1(IN, osg::TextureRectangle *, target);
	I_Constructor1(IN, osg::CameraNode::Attachment &, attachment);
	I_Method2(void, createRequiredTexturesAndApplyGenerateMipMap, IN, osg::State &, state, IN, const osg::FBOExtensions *, ext);
	I_Method3(void, attach, IN, osg::State &, state, IN, GLenum, attachment_point, IN, const osg::FBOExtensions *, ext);
	I_Method1(int, compare, IN, const osg::FrameBufferAttachment &, fa);
END_REFLECTOR

TYPE_NAME_ALIAS(std::map< GLenum COMMA  osg::FrameBufferAttachment >, osg::FrameBufferObject::AttachmentMap);

BEGIN_OBJECT_REFLECTOR(osg::FrameBufferObject)
	I_BaseType(osg::StateAttribute);
	I_Constructor0();
	I_ConstructorWithDefaults2(IN, const osg::FrameBufferObject &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(osg::StateAttribute::Type, getType);
	I_Method0(const osg::FrameBufferObject::AttachmentMap &, getAttachmentMap);
	I_Method1(bool, hasAttachment, IN, GLenum, attachment_point);
	I_Method1(const osg::FrameBufferAttachment &, getAttachment, IN, GLenum, attachment_point);
	I_Method2(void, setAttachment, IN, GLenum, attachment_point, IN, const osg::FrameBufferAttachment &, attachment);
	I_Method1(int, compare, IN, const osg::StateAttribute &, sa);
	I_Method1(void, apply, IN, osg::State &, state);
	I_IndexedProperty1(const osg::FrameBufferAttachment &, Attachment, GLenum, attachment_point);
	I_ReadOnlyProperty(const osg::FrameBufferObject::AttachmentMap &, AttachmentMap);
	I_ReadOnlyProperty(osg::StateAttribute::Type, Type);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::RenderBuffer)
	I_BaseType(osg::Object);
	I_Constructor0();
	I_Constructor3(IN, int, width, IN, int, height, IN, GLenum, internalFormat);
	I_ConstructorWithDefaults2(IN, const osg::RenderBuffer &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(int, getWidth);
	I_Method0(int, getHeight);
	I_Method1(void, setWidth, IN, int, w);
	I_Method1(void, setHeight, IN, int, h);
	I_Method2(void, setSize, IN, int, w, IN, int, h);
	I_Method0(GLenum, getInternalFormat);
	I_Method1(void, setInternalFormat, IN, GLenum, format);
	I_Method2(GLuint, getObjectID, IN, unsigned int, contextID, IN, const osg::FBOExtensions *, ext);
	I_Method1(int, compare, IN, const osg::RenderBuffer &, rb);
	I_Property(int, Height);
	I_Property(GLenum, InternalFormat);
	I_Property(int, Width);
END_REFLECTOR

STD_MAP_REFLECTOR(std::map< GLenum COMMA  osg::FrameBufferAttachment >);

