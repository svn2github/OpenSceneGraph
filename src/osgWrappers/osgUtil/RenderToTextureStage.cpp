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
#include <osg/Image>
#include <osg/Object>
#include <osg/State>
#include <osg/Texture2D>
#include <osgUtil/RenderLeaf>
#include <osgUtil/RenderToTextureStage>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgUtil::RenderToTextureStage)
	I_BaseType(osgUtil::RenderStage);
	I_Constructor0();
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, x);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(void, reset);
	I_Method1(void, setTexture, IN, osg::Texture2D *, texture);
	I_Method0(osg::Texture2D *, getTexture);
	I_Method1(void, setImage, IN, osg::Image *, image);
	I_Method0(osg::Image *, getImage);
	I_Method1(void, setImageReadPixelFormat, IN, GLenum, format);
	I_Method0(GLenum, getImageReadPixelFormat);
	I_Method1(void, setImageReadPixelDataType, IN, GLenum, type);
	I_Method0(GLenum, getImageReadPixelDataType);
	I_Method2(void, draw, IN, osg::State &, state, IN, osgUtil::RenderLeaf *&, previous);
	I_Property(osg::Image *, Image);
	I_Property(GLenum, ImageReadPixelDataType);
	I_Property(GLenum, ImageReadPixelFormat);
	I_Property(osg::Texture2D *, Texture);
END_REFLECTOR

