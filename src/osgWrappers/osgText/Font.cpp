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
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>
#include <osg/StateSet>
#include <osg/TexEnv>
#include <osg/Texture>
#include <osg/Vec2>
#include <osgText/Font>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(OpenThreads::Mutex, osgText::Font::FontMutex)

BEGIN_OBJECT_REFLECTOR(osgText::Font)
	I_DeclaringFile("osgText/Font");
	I_BaseType(osg::Object);
	I_ConstructorWithDefaults1(IN, osgText::Font::FontImplementation *, implementation, 0,
	                           Properties::NON_EXPLICIT,
	                           ____Font__FontImplementation_P1,
	                           "",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, x,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(std::string, getFileName,
	          Properties::VIRTUAL,
	          __std_string__getFileName,
	          "",
	          "");
	I_Method1(void, setTexEnv, IN, osg::TexEnv *, texenv,
	          Properties::NON_VIRTUAL,
	          __void__setTexEnv__osg_TexEnv_P1,
	          "",
	          "");
	I_Method0(osg::TexEnv *, getTexEnv,
	          Properties::NON_VIRTUAL,
	          __osg_TexEnv_P1__getTexEnv,
	          "",
	          "");
	I_Method0(const osg::TexEnv *, getTexEnv,
	          Properties::NON_VIRTUAL,
	          __C5_osg_TexEnv_P1__getTexEnv,
	          "",
	          "");
	I_Method1(void, setStateSet, IN, osg::StateSet *, stateset,
	          Properties::NON_VIRTUAL,
	          __void__setStateSet__osg_StateSet_P1,
	          "",
	          "");
	I_Method0(osg::StateSet *, getStateSet,
	          Properties::NON_VIRTUAL,
	          __osg_StateSet_P1__getStateSet,
	          "",
	          "");
	I_Method0(const osg::StateSet *, getStateSet,
	          Properties::NON_VIRTUAL,
	          __C5_osg_StateSet_P1__getStateSet,
	          "",
	          "");
	I_Method2(void, setFontResolution, IN, unsigned int, width, IN, unsigned int, height,
	          Properties::VIRTUAL,
	          __void__setFontResolution__unsigned_int__unsigned_int,
	          "Set the pixel width and height hint. ",
	          "");
	I_Method0(unsigned int, getFontWidth,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getFontWidth,
	          "",
	          "");
	I_Method0(unsigned int, getFontHeight,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getFontHeight,
	          "",
	          "");
	I_Method3(osg::Vec2, getKerning, IN, unsigned int, leftcharcode, IN, unsigned int, rightcharcode, IN, osgText::KerningType, kerningType,
	          Properties::VIRTUAL,
	          __osg_Vec2__getKerning__unsigned_int__unsigned_int__KerningType,
	          "Get a kerning (adjustment of spacing of two adjacent character) for specified charcodes, w.r.t the current font size hint. ",
	          "");
	I_Method1(osgText::Font::Glyph *, getGlyph, IN, unsigned int, charcode,
	          Properties::VIRTUAL,
	          __Glyph_P1__getGlyph__unsigned_int,
	          "Get a Glyph for specified charcode, and the font size nearest to the current font size hint. ",
	          "");
	I_Method0(bool, hasVertical,
	          Properties::VIRTUAL,
	          __bool__hasVertical,
	          "Return true if this font provides vertical alignments and spacing or glyphs. ",
	          "");
	I_Method1(void, setGlyphImageMargin, IN, unsigned int, margin,
	          Properties::NON_VIRTUAL,
	          __void__setGlyphImageMargin__unsigned_int,
	          "Set the margin around each glyph, to ensure that texture filtering doesn't bleed adjacent glyph's into each other. ",
	          "Default margin is 1 texels. ");
	I_Method0(unsigned int, getGlyphImageMargin,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getGlyphImageMargin,
	          "",
	          "");
	I_Method1(void, setGlyphImageMarginRatio, IN, float, margin,
	          Properties::NON_VIRTUAL,
	          __void__setGlyphImageMarginRatio__float,
	          "Set the margin ratio around each glyph, relative to the glyph's size. ",
	          "to ensure that texture filtering doesn't bleed adjacent glyph's into each other. Default margin is 0.05. ");
	I_Method0(float, getGlyphImageMarginRatio,
	          Properties::NON_VIRTUAL,
	          __float__getGlyphImageMarginRatio,
	          "",
	          "");
	I_Method2(void, setTextureSizeHint, IN, unsigned int, width, IN, unsigned int, height,
	          Properties::NON_VIRTUAL,
	          __void__setTextureSizeHint__unsigned_int__unsigned_int,
	          "Set the size of texture to create to store the glyph images when rendering. ",
	          "Note, this doesn't affect already created Texture Glhph's. ");
	I_Method0(unsigned int, getTextureWidthHint,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getTextureWidthHint,
	          "",
	          "");
	I_Method0(unsigned int, getTextureHeightHint,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getTextureHeightHint,
	          "",
	          "");
	I_Method1(void, setMinFilterHint, IN, osg::Texture::FilterMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setMinFilterHint__osg_Texture_FilterMode,
	          "Set the minification texture filter to use when creating the texture to store the glyph images when rendering. ",
	          "Note, this doesn't affect already created Texture Glhph's. ");
	I_Method0(osg::Texture::FilterMode, getMinFilterHint,
	          Properties::NON_VIRTUAL,
	          __osg_Texture_FilterMode__getMinFilterHint,
	          "",
	          "");
	I_Method1(void, setMagFilterHint, IN, osg::Texture::FilterMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setMagFilterHint__osg_Texture_FilterMode,
	          "Set the magnification texture filter to use when creating the texture to store the glyph images when rendering. ",
	          "Note, this doesn't affect already created Texture Glhph's. ");
	I_Method0(osg::Texture::FilterMode, getMagFilterHint,
	          Properties::NON_VIRTUAL,
	          __osg_Texture_FilterMode__getMagFilterHint,
	          "",
	          "");
	I_Method1(void, setImplementation, IN, osgText::Font::FontImplementation *, implementation,
	          Properties::NON_VIRTUAL,
	          __void__setImplementation__FontImplementation_P1,
	          "",
	          "");
	I_Method0(osgText::Font::FontImplementation *, getImplementation,
	          Properties::NON_VIRTUAL,
	          __FontImplementation_P1__getImplementation,
	          "",
	          "");
	I_Method0(const osgText::Font::FontImplementation *, getImplementation,
	          Properties::NON_VIRTUAL,
	          __C5_FontImplementation_P1__getImplementation,
	          "",
	          "");
	I_Method1(void, setThreadSafeRefUnref, IN, bool, threadSafe,
	          Properties::VIRTUAL,
	          __void__setThreadSafeRefUnref__bool,
	          "Set whether to use a mutex to ensure ref() and unref() are thread safe. ",
	          "");
	I_Method1(void, resizeGLObjectBuffers, IN, unsigned int, maxSize,
	          Properties::VIRTUAL,
	          __void__resizeGLObjectBuffers__unsigned_int,
	          "Resize any per context GLObject buffers to specified size. ",
	          "");
	I_MethodWithDefaults1(void, releaseGLObjects, IN, osg::State *, state, 0,
	                      Properties::VIRTUAL,
	                      __void__releaseGLObjects__osg_State_P1,
	                      "If State is non-zero, this function releases OpenGL objects for the specified graphics context. ",
	                      "Otherwise, releases OpenGL objexts for all graphics contexts. ");
	I_StaticMethod0(osgText::Font::FontMutex *, getSerializeFontCallsMutex,
	                __FontMutex_P1__getSerializeFontCallsMutex_S,
	                "Get the mutex that enables the serialization of calls to this font. ",
	                "");
	I_ProtectedMethod4(void, addGlyph, IN, unsigned int, width, IN, unsigned int, height, IN, unsigned int, charcode, IN, osgText::Font::Glyph *, glyph,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__addGlyph__unsigned_int__unsigned_int__unsigned_int__Glyph_P1,
	                   "",
	                   "");
	I_SimpleProperty(std::string, FileName, 
	                 __std_string__getFileName, 
	                 0);
	I_SimpleProperty(unsigned int, FontHeight, 
	                 __unsigned_int__getFontHeight, 
	                 0);
	I_SimpleProperty(unsigned int, FontWidth, 
	                 __unsigned_int__getFontWidth, 
	                 0);
	I_SimpleProperty(unsigned int, GlyphImageMargin, 
	                 __unsigned_int__getGlyphImageMargin, 
	                 __void__setGlyphImageMargin__unsigned_int);
	I_SimpleProperty(float, GlyphImageMarginRatio, 
	                 __float__getGlyphImageMarginRatio, 
	                 __void__setGlyphImageMarginRatio__float);
	I_SimpleProperty(osgText::Font::FontImplementation *, Implementation, 
	                 __FontImplementation_P1__getImplementation, 
	                 __void__setImplementation__FontImplementation_P1);
	I_SimpleProperty(osg::Texture::FilterMode, MagFilterHint, 
	                 __osg_Texture_FilterMode__getMagFilterHint, 
	                 __void__setMagFilterHint__osg_Texture_FilterMode);
	I_SimpleProperty(osg::Texture::FilterMode, MinFilterHint, 
	                 __osg_Texture_FilterMode__getMinFilterHint, 
	                 __void__setMinFilterHint__osg_Texture_FilterMode);
	I_SimpleProperty(osg::StateSet *, StateSet, 
	                 __osg_StateSet_P1__getStateSet, 
	                 __void__setStateSet__osg_StateSet_P1);
	I_SimpleProperty(osg::TexEnv *, TexEnv, 
	                 __osg_TexEnv_P1__getTexEnv, 
	                 __void__setTexEnv__osg_TexEnv_P1);
	I_SimpleProperty(unsigned int, TextureHeightHint, 
	                 __unsigned_int__getTextureHeightHint, 
	                 0);
	I_SimpleProperty(unsigned int, TextureWidthHint, 
	                 __unsigned_int__getTextureWidthHint, 
	                 0);
	I_SimpleProperty(bool, ThreadSafeRefUnref, 
	                 0, 
	                 __void__setThreadSafeRefUnref__bool);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgText::Font::FontImplementation)
	I_DeclaringFile("osgText/Font");
	I_BaseType(osg::Referenced);
	I_Constructor0(____FontImplementation,
	               "",
	               "");
	I_Method0(std::string, getFileName,
	          Properties::PURE_VIRTUAL,
	          __std_string__getFileName,
	          "",
	          "");
	I_Method2(void, setFontResolution, IN, unsigned int, width, IN, unsigned int, height,
	          Properties::PURE_VIRTUAL,
	          __void__setFontResolution__unsigned_int__unsigned_int,
	          "Set the pixel width and height hint. ",
	          "");
	I_Method1(osgText::Font::Glyph *, getGlyph, IN, unsigned int, charcode,
	          Properties::PURE_VIRTUAL,
	          __Glyph_P1__getGlyph__unsigned_int,
	          "Get a Glyph for specified charcode, and the font size nearest to the current font size hint. ",
	          "");
	I_Method3(osg::Vec2, getKerning, IN, unsigned int, leftcharcode, IN, unsigned int, rightcharcode, IN, osgText::KerningType, kerningType,
	          Properties::PURE_VIRTUAL,
	          __osg_Vec2__getKerning__unsigned_int__unsigned_int__KerningType,
	          "Get a kerning (adjustment of spacing of two adjacent character) for specified charcodes, w.r.t the current font size hint. ",
	          "");
	I_Method0(bool, hasVertical,
	          Properties::PURE_VIRTUAL,
	          __bool__hasVertical,
	          "Return true if this font provides vertical alignments and spacing or glyphs. ",
	          "");
	I_Method1(void, setFontWidth, IN, unsigned int, width,
	          Properties::NON_VIRTUAL,
	          __void__setFontWidth__unsigned_int,
	          "",
	          "");
	I_Method1(void, setFontHeight, IN, unsigned int, height,
	          Properties::NON_VIRTUAL,
	          __void__setFontHeight__unsigned_int,
	          "",
	          "");
	I_Method4(void, addGlyph, IN, unsigned int, width, IN, unsigned int, height, IN, unsigned int, charcode, IN, osgText::Font::Glyph *, glyph,
	          Properties::NON_VIRTUAL,
	          __void__addGlyph__unsigned_int__unsigned_int__unsigned_int__Glyph_P1,
	          "",
	          "");
	I_SimpleProperty(std::string, FileName, 
	                 __std_string__getFileName, 
	                 0);
	I_SimpleProperty(unsigned int, FontHeight, 
	                 0, 
	                 __void__setFontHeight__unsigned_int);
	I_SimpleProperty(unsigned int, FontWidth, 
	                 0, 
	                 __void__setFontWidth__unsigned_int);
	I_PublicMemberProperty(osgText::Font *, _facade);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgText::Font::Glyph)
	I_DeclaringFile("osgText/Font");
	I_BaseType(osg::Image);
	I_Constructor0(____Glyph,
	               "",
	               "");
	I_Method0(unsigned int, getGlyphCode,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getGlyphCode,
	          "",
	          "");
	I_Method1(void, setHorizontalBearing, IN, const osg::Vec2 &, bearing,
	          Properties::NON_VIRTUAL,
	          __void__setHorizontalBearing__C5_osg_Vec2_R1,
	          "",
	          "");
	I_Method0(const osg::Vec2 &, getHorizontalBearing,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec2_R1__getHorizontalBearing,
	          "",
	          "");
	I_Method1(void, setHorizontalAdvance, IN, float, advance,
	          Properties::NON_VIRTUAL,
	          __void__setHorizontalAdvance__float,
	          "",
	          "");
	I_Method0(float, getHorizontalAdvance,
	          Properties::NON_VIRTUAL,
	          __float__getHorizontalAdvance,
	          "",
	          "");
	I_Method1(void, setVerticalBearing, IN, const osg::Vec2 &, bearing,
	          Properties::NON_VIRTUAL,
	          __void__setVerticalBearing__C5_osg_Vec2_R1,
	          "",
	          "");
	I_Method0(const osg::Vec2 &, getVerticalBearing,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec2_R1__getVerticalBearing,
	          "",
	          "");
	I_Method1(void, setVerticalAdvance, IN, float, advance,
	          Properties::NON_VIRTUAL,
	          __void__setVerticalAdvance__float,
	          "",
	          "");
	I_Method0(float, getVerticalAdvance,
	          Properties::NON_VIRTUAL,
	          __float__getVerticalAdvance,
	          "",
	          "");
	I_Method1(void, setTexture, IN, osgText::Font::GlyphTexture *, texture,
	          Properties::NON_VIRTUAL,
	          __void__setTexture__GlyphTexture_P1,
	          "",
	          "");
	I_Method0(osgText::Font::GlyphTexture *, getTexture,
	          Properties::NON_VIRTUAL,
	          __GlyphTexture_P1__getTexture,
	          "",
	          "");
	I_Method0(const osgText::Font::GlyphTexture *, getTexture,
	          Properties::NON_VIRTUAL,
	          __C5_GlyphTexture_P1__getTexture,
	          "",
	          "");
	I_Method2(void, setTexturePosition, IN, int, posX, IN, int, posY,
	          Properties::NON_VIRTUAL,
	          __void__setTexturePosition__int__int,
	          "",
	          "");
	I_Method0(int, getTexturePositionX,
	          Properties::NON_VIRTUAL,
	          __int__getTexturePositionX,
	          "",
	          "");
	I_Method0(int, getTexturePositionY,
	          Properties::NON_VIRTUAL,
	          __int__getTexturePositionY,
	          "",
	          "");
	I_Method1(void, setMinTexCoord, IN, const osg::Vec2 &, coord,
	          Properties::NON_VIRTUAL,
	          __void__setMinTexCoord__C5_osg_Vec2_R1,
	          "",
	          "");
	I_Method0(const osg::Vec2 &, getMinTexCoord,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec2_R1__getMinTexCoord,
	          "",
	          "");
	I_Method1(void, setMaxTexCoord, IN, const osg::Vec2 &, coord,
	          Properties::NON_VIRTUAL,
	          __void__setMaxTexCoord__C5_osg_Vec2_R1,
	          "",
	          "");
	I_Method0(const osg::Vec2 &, getMaxTexCoord,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec2_R1__getMaxTexCoord,
	          "",
	          "");
	I_Method0(void, subload,
	          Properties::NON_VIRTUAL,
	          __void__subload,
	          "",
	          "");
	I_Method1(void, draw, IN, osg::State &, state,
	          Properties::NON_VIRTUAL,
	          __void__draw__osg_State_R1,
	          "",
	          "");
	I_SimpleProperty(unsigned int, GlyphCode, 
	                 __unsigned_int__getGlyphCode, 
	                 0);
	I_SimpleProperty(float, HorizontalAdvance, 
	                 __float__getHorizontalAdvance, 
	                 __void__setHorizontalAdvance__float);
	I_SimpleProperty(const osg::Vec2 &, HorizontalBearing, 
	                 __C5_osg_Vec2_R1__getHorizontalBearing, 
	                 __void__setHorizontalBearing__C5_osg_Vec2_R1);
	I_SimpleProperty(const osg::Vec2 &, MaxTexCoord, 
	                 __C5_osg_Vec2_R1__getMaxTexCoord, 
	                 __void__setMaxTexCoord__C5_osg_Vec2_R1);
	I_SimpleProperty(const osg::Vec2 &, MinTexCoord, 
	                 __C5_osg_Vec2_R1__getMinTexCoord, 
	                 __void__setMinTexCoord__C5_osg_Vec2_R1);
	I_SimpleProperty(osgText::Font::GlyphTexture *, Texture, 
	                 __GlyphTexture_P1__getTexture, 
	                 __void__setTexture__GlyphTexture_P1);
	I_SimpleProperty(int, TexturePositionX, 
	                 __int__getTexturePositionX, 
	                 0);
	I_SimpleProperty(int, TexturePositionY, 
	                 __int__getTexturePositionY, 
	                 0);
	I_SimpleProperty(float, VerticalAdvance, 
	                 __float__getVerticalAdvance, 
	                 __void__setVerticalAdvance__float);
	I_SimpleProperty(const osg::Vec2 &, VerticalBearing, 
	                 __C5_osg_Vec2_R1__getVerticalBearing, 
	                 __void__setVerticalBearing__C5_osg_Vec2_R1);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgText::Font::GlyphTexture)
	I_DeclaringFile("osgText/Font");
	I_BaseType(osg::Texture2D);
	I_Constructor0(____GlyphTexture,
	               "",
	               "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "Return the name of the attribute's class type. ",
	          "");
	I_Method1(int, compare, IN, const osg::StateAttribute &, rhs,
	          Properties::VIRTUAL,
	          __int__compare__C5_osg_StateAttribute_R1,
	          "return -1 if *this < *rhs, 0 if *this==*rhs, 1 if *this>*rhs. ",
	          "");
	I_Method1(void, setGlyphImageMargin, IN, unsigned int, margin,
	          Properties::NON_VIRTUAL,
	          __void__setGlyphImageMargin__unsigned_int,
	          "Set the margin around each glyph, to ensure that texture filtering doesn't bleed adjacent glyph's into each other. ",
	          "");
	I_Method0(unsigned int, getGlyphImageMargin,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getGlyphImageMargin,
	          "",
	          "");
	I_Method1(void, setGlyphImageMarginRatio, IN, float, margin,
	          Properties::NON_VIRTUAL,
	          __void__setGlyphImageMarginRatio__float,
	          "",
	          "");
	I_Method0(float, getGlyphImageMarginRatio,
	          Properties::NON_VIRTUAL,
	          __float__getGlyphImageMarginRatio,
	          "",
	          "");
	I_Method3(bool, getSpaceForGlyph, IN, osgText::Font::Glyph *, glyph, IN, int &, posX, IN, int &, posY,
	          Properties::NON_VIRTUAL,
	          __bool__getSpaceForGlyph__Glyph_P1__int_R1__int_R1,
	          "",
	          "");
	I_Method3(void, addGlyph, IN, osgText::Font::Glyph *, glyph, IN, int, posX, IN, int, posY,
	          Properties::NON_VIRTUAL,
	          __void__addGlyph__Glyph_P1__int__int,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::State &, state,
	          Properties::VIRTUAL,
	          __void__apply__osg_State_R1,
	          "Bind the texture object. ",
	          "If the texture object hasn't already been compiled, create the texture mipmap levels. ");
	I_Method1(void, setThreadSafeRefUnref, IN, bool, threadSafe,
	          Properties::VIRTUAL,
	          __void__setThreadSafeRefUnref__bool,
	          "Set whether to use a mutex to ensure ref() and unref() are thread safe. ",
	          "");
	I_Method1(void, resizeGLObjectBuffers, IN, unsigned int, maxSize,
	          Properties::VIRTUAL,
	          __void__resizeGLObjectBuffers__unsigned_int,
	          "Resize any per context GLObject buffers to specified size. ",
	          "");
	I_SimpleProperty(unsigned int, GlyphImageMargin, 
	                 __unsigned_int__getGlyphImageMargin, 
	                 __void__setGlyphImageMargin__unsigned_int);
	I_SimpleProperty(float, GlyphImageMarginRatio, 
	                 __float__getGlyphImageMarginRatio, 
	                 __void__setGlyphImageMarginRatio__float);
	I_SimpleProperty(bool, ThreadSafeRefUnref, 
	                 0, 
	                 __void__setThreadSafeRefUnref__bool);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgText::KerningType)
	I_DeclaringFile("osgText/Font");
	I_EnumLabel(osgText::KERNING_DEFAULT);
	I_EnumLabel(osgText::KERNING_UNFITTED);
	I_EnumLabel(osgText::KERNING_NONE);
END_REFLECTOR

