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

#include <osg/Camera>
#include <osg/CopyOp>
#include <osg/Light>
#include <osg/Matrix>
#include <osg/Matrixd>
#include <osg/Object>
#include <osg/Stats>
#include <osg/View>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osg::View::LightingMode)
	I_DeclaringFile("osg/View");
	I_EnumLabel(osg::View::NO_LIGHT);
	I_EnumLabel(osg::View::HEADLIGHT);
	I_EnumLabel(osg::View::SKY_LIGHT);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::View)
	I_DeclaringFile("osg/View");
	I_BaseType(osg::Object);
	I_Constructor0(____View,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::View &, view, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____View__C5_osg_View_R1__C5_osg_CopyOp_R1,
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
	I_Method1(void, take, IN, osg::View &, rhs,
	          Properties::VIRTUAL,
	          __void__take__View_R1,
	          "Take all the settings, Camera and Slaves from the passed in view, leaving it empty. ",
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
	I_Method1(void, setLightingMode, IN, osg::View::LightingMode, lightingMode,
	          Properties::NON_VIRTUAL,
	          __void__setLightingMode__LightingMode,
	          "Set the global lighting to use for this view. ",
	          "Defaults to headlight. ");
	I_Method0(osg::View::LightingMode, getLightingMode,
	          Properties::NON_VIRTUAL,
	          __LightingMode__getLightingMode,
	          "Get the global lighting used for this view. ",
	          "");
	I_Method1(void, setLight, IN, osg::Light *, light,
	          Properties::NON_VIRTUAL,
	          __void__setLight__osg_Light_P1,
	          "Get the global light. ",
	          "");
	I_Method0(osg::Light *, getLight,
	          Properties::NON_VIRTUAL,
	          __osg_Light_P1__getLight,
	          "Get the global lighting if assigned. ",
	          "");
	I_Method0(const osg::Light *, getLight,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Light_P1__getLight,
	          "Get the const global lighting if assigned. ",
	          "");
	I_Method1(void, setCamera, IN, osg::Camera *, camera,
	          Properties::NON_VIRTUAL,
	          __void__setCamera__osg_Camera_P1,
	          "Set the master camera of the view. ",
	          "");
	I_Method0(osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __osg_Camera_P1__getCamera,
	          "Get the master camera of the view. ",
	          "");
	I_Method0(const osg::Camera *, getCamera,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Camera_P1__getCamera,
	          "Get the const master camera of the view. ",
	          "");
	I_MethodWithDefaults2(bool, addSlave, IN, osg::Camera *, camera, , IN, bool, useMastersSceneData, true,
	                      Properties::NON_VIRTUAL,
	                      __bool__addSlave__osg_Camera_P1__bool,
	                      "",
	                      "");
	I_MethodWithDefaults4(bool, addSlave, IN, osg::Camera *, camera, , IN, const osg::Matrix &, projectionOffset, , IN, const osg::Matrix &, viewOffse, , IN, bool, useMastersSceneData, true,
	                      Properties::NON_VIRTUAL,
	                      __bool__addSlave__osg_Camera_P1__C5_osg_Matrix_R1__C5_osg_Matrix_R1__bool,
	                      "",
	                      "");
	I_Method1(bool, removeSlave, IN, unsigned int, pos,
	          Properties::NON_VIRTUAL,
	          __bool__removeSlave__unsigned_int,
	          "",
	          "");
	I_Method0(unsigned int, getNumSlaves,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumSlaves,
	          "",
	          "");
	I_Method1(osg::View::Slave &, getSlave, IN, unsigned int, pos,
	          Properties::NON_VIRTUAL,
	          __Slave_R1__getSlave__unsigned_int,
	          "",
	          "");
	I_Method1(const osg::View::Slave &, getSlave, IN, unsigned int, pos,
	          Properties::NON_VIRTUAL,
	          __C5_Slave_R1__getSlave__unsigned_int,
	          "",
	          "");
	I_Method1(unsigned int, findSlaveIndexForCamera, IN, osg::Camera *, camera,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__findSlaveIndexForCamera__osg_Camera_P1,
	          "",
	          "");
	I_Method1(osg::View::Slave *, findSlaveForCamera, IN, osg::Camera *, camera,
	          Properties::NON_VIRTUAL,
	          __Slave_P1__findSlaveForCamera__osg_Camera_P1,
	          "",
	          "");
	I_Method0(void, updateSlaves,
	          Properties::NON_VIRTUAL,
	          __void__updateSlaves,
	          "",
	          "");
	I_Method1(void, updateSlave, IN, unsigned int, i,
	          Properties::NON_VIRTUAL,
	          __void__updateSlave__unsigned_int,
	          "",
	          "");
	I_ProtectedMethod1(osg::GraphicsOperation *, createRenderer, IN, osg::Camera *, x,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_GraphicsOperation_P1__createRenderer__osg_Camera_P1,
	                   "",
	                   "");
	I_SimpleProperty(osg::Camera *, Camera, 
	                 __osg_Camera_P1__getCamera, 
	                 __void__setCamera__osg_Camera_P1);
	I_SimpleProperty(osg::Light *, Light, 
	                 __osg_Light_P1__getLight, 
	                 __void__setLight__osg_Light_P1);
	I_SimpleProperty(osg::View::LightingMode, LightingMode, 
	                 __LightingMode__getLightingMode, 
	                 __void__setLightingMode__LightingMode);
	I_ArrayProperty(osg::View::Slave &, Slave, 
	                __Slave_R1__getSlave__unsigned_int, 
	                0, 
	                __unsigned_int__getNumSlaves, 
	                0, 
	                0, 
	                __bool__removeSlave__unsigned_int);
	I_SimpleProperty(osg::Stats *, Stats, 
	                 __osg_Stats_P1__getStats, 
	                 __void__setStats__osg_Stats_P1);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::View::Slave)
	I_DeclaringFile("osg/View");
	I_ConstructorWithDefaults1(IN, bool, useMastersSceneData, true,
	                           Properties::NON_EXPLICIT,
	                           ____Slave__bool,
	                           "",
	                           "");
	I_ConstructorWithDefaults4(IN, osg::Camera *, camera, , IN, const osg::Matrixd &, projectionOffset, , IN, const osg::Matrixd &, viewOffset, , IN, bool, useMastersSceneData, true,
	                           ____Slave__osg_Camera_P1__C5_osg_Matrixd_R1__C5_osg_Matrixd_R1__bool,
	                           "",
	                           "");
	I_Constructor1(IN, const osg::View::Slave &, rhs,
	               Properties::NON_EXPLICIT,
	               ____Slave__C5_Slave_R1,
	               "",
	               "");
	I_PublicMemberProperty(osg::ref_ptr< osg::Camera >, _camera);
	I_PublicMemberProperty(osg::Matrixd, _projectionOffset);
	I_PublicMemberProperty(osg::Matrixd, _viewOffset);
	I_PublicMemberProperty(bool, _useMastersSceneData);
END_REFLECTOR

