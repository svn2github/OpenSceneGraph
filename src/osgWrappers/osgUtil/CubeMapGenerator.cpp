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
#include <osg/TextureCubeMap>
#include <osgUtil/CubeMapGenerator>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgUtil::CubeMapGenerator)
	I_BaseType(osg::Referenced);
	I_ConstructorWithDefaults1(IN, int, texture_size, 64,
	                           Properties::EXPLICIT,
	                           ____CubeMapGenerator__int,
	                           "",
	                           "");
	I_ConstructorWithDefaults2(IN, const osgUtil::CubeMapGenerator &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____CubeMapGenerator__C5_CubeMapGenerator_R1__C5_osg_CopyOp_R1,
	                           "",
	                           "");
	I_Method1(osg::Image *, getImage, IN, osg::TextureCubeMap::Face, face,
	          Properties::NON_VIRTUAL,
	          __osg_Image_P1__getImage__osg_TextureCubeMap_Face,
	          "",
	          "");
	I_Method1(const osg::Image *, getImage, IN, osg::TextureCubeMap::Face, face,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Image_P1__getImage__osg_TextureCubeMap_Face,
	          "",
	          "");
	I_MethodWithDefaults1(void, generateMap, IN, bool, use_osg_system, true,
	                      Properties::NON_VIRTUAL,
	                      __void__generateMap__bool,
	                      "Generate the six cube images. ",
	                      "If use_osg_system is true, then the OSG's coordinate system is used instead of the default OpenGL one.");
END_REFLECTOR

