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
#include <osg/StateAttribute>
#include <osg/TextureRectangle>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::TextureRectangle)
	I_BaseType(osg::Texture);
	I_Constructor0();
	I_Constructor1(IN, osg::Image *, image);
	I_ConstructorWithDefaults2(IN, const osg::TextureRectangle &, text, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(osg::StateAttribute::Type, getType);
	I_Method1(int, compare, IN, const osg::StateAttribute &, rhs);
	I_Method0(GLenum, getTextureTarget);
	I_Method1(void, setImage, IN, osg::Image *, image);
	I_Method0(osg::Image *, getImage);
	I_Method0(const osg::Image *, getImage);
	I_Method1(unsigned int &, getModifiedCount, IN, unsigned int, contextID);
	I_Method2(void, setImage, IN, unsigned, int, IN, osg::Image *, image);
	I_Method1(osg::Image *, getImage, IN, unsigned, int);
	I_Method1(const osg::Image *, getImage, IN, unsigned, int);
	I_Method0(unsigned int, getNumImages);
	I_Method2(void, setTextureSize, IN, int, width, IN, int, height);
	I_Method1(void, setTextureWidth, IN, int, width);
	I_Method1(void, setTextureHeight, IN, int, height);
	I_Method0(int, getTextureWidth);
	I_Method0(int, getTextureHeight);
	I_Method0(int, getTextureDepth);
	I_Method1(void, setSubloadCallback, IN, osg::TextureRectangle::SubloadCallback *, cb);
	I_Method0(osg::TextureRectangle::SubloadCallback *, getSubloadCallback);
	I_Method0(const osg::TextureRectangle::SubloadCallback *, getSubloadCallback);
	I_Method5(void, copyTexImage2D, IN, osg::State &, state, IN, int, x, IN, int, y, IN, int, width, IN, int, height);
	I_Method7(void, copyTexSubImage2D, IN, osg::State &, state, IN, int, xoffset, IN, int, yoffset, IN, int, x, IN, int, y, IN, int, width, IN, int, height);
	I_Method1(void, apply, IN, osg::State &, state);
	I_Property(osg::Image *, Image);
	I_Property(osg::TextureRectangle::SubloadCallback *, SubloadCallback);
	I_ReadOnlyProperty(int, TextureDepth);
	I_Property(int, TextureHeight);
	I_ReadOnlyProperty(GLenum, TextureTarget);
	I_Property(int, TextureWidth);
	I_ReadOnlyProperty(osg::StateAttribute::Type, Type);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::TextureRectangle::SubloadCallback)
	I_BaseType(osg::Referenced);
	I_Constructor0();
	I_Method2(void, load, IN, const osg::TextureRectangle &, x, IN, osg::State &, x);
	I_Method2(void, subload, IN, const osg::TextureRectangle &, x, IN, osg::State &, x);
END_REFLECTOR

