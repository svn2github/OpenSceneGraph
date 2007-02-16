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

#include <osg/.svn/text-base/Matrixd.svn-base>
#include <osg/.svn/text-base/Node.svn-base>
#include <osg/ApplicationUsage>
#include <osg/Vec3d>
#include <osgGA/.svn/text-base/KeySwitchMatrixManipulator.svn-base>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/MatrixManipulator>
#include <osgUtil/.svn/text-base/SceneView.svn-base>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::pair< std::string COMMA  osg::ref_ptr< osgGA::MatrixManipulator > >, osgGA::KeySwitchMatrixManipulator::NamedManipulator);

TYPE_NAME_ALIAS(std::map< int COMMA  osgGA::KeySwitchMatrixManipulator::NamedManipulator >, osgGA::KeySwitchMatrixManipulator::KeyManipMap);

BEGIN_OBJECT_REFLECTOR(osgGA::KeySwitchMatrixManipulator)
	I_BaseType(osgGA::MatrixManipulator);
	I_BaseType(osgGA::MatrixManipulator);
	I_Constructor0(____KeySwitchMatrixManipulator,
	               "",
	               "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "",
	          "");
	I_Method3(void, addMatrixManipulator, IN, int, key, IN, std::string, name, IN, osgGA::MatrixManipulator *, cm,
	          Properties::NON_VIRTUAL,
	          __void__addMatrixManipulator__int__std_string__MatrixManipulator_P1,
	          "Add a camera manipulator with an associated name, and a key to trigger the switch,. ",
	          "");
	I_Method1(void, addNumberedMatrixManipulator, IN, osgGA::MatrixManipulator *, cm,
	          Properties::NON_VIRTUAL,
	          __void__addNumberedMatrixManipulator__MatrixManipulator_P1,
	          "Add a camera manipulator with an autogenerated keybinding which is '1' + previous number of camera's registerd. ",
	          "");
	I_Method0(unsigned int, getNumMatrixManipulators,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumMatrixManipulators,
	          "",
	          "");
	I_Method1(void, selectMatrixManipulator, IN, unsigned int, num,
	          Properties::NON_VIRTUAL,
	          __void__selectMatrixManipulator__unsigned_int,
	          "",
	          "");
	I_Method0(osgGA::KeySwitchMatrixManipulator::KeyManipMap &, getKeyManipMap,
	          Properties::NON_VIRTUAL,
	          __KeyManipMap_R1__getKeyManipMap,
	          "Get the complete list of manipulators attached to this keyswitch manipulator. ",
	          "");
	I_Method0(const osgGA::KeySwitchMatrixManipulator::KeyManipMap &, getKeyManipMap,
	          Properties::NON_VIRTUAL,
	          __C5_KeyManipMap_R1__getKeyManipMap,
	          "Get the const complete list of manipulators attached to this keyswitch manipulator. ",
	          "");
	I_Method0(osgGA::MatrixManipulator *, getCurrentMatrixManipulator,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getCurrentMatrixManipulator,
	          "Get the current active manipulators. ",
	          "");
	I_Method0(const osgGA::MatrixManipulator *, getCurrentMatrixManipulator,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getCurrentMatrixManipulator,
	          "Get the const current active manipulators. ",
	          "");
	I_Method1(osgGA::MatrixManipulator *, getMatrixManipulatorWithIndex, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getMatrixManipulatorWithIndex__unsigned_int,
	          "Get manipulator assigned to a specified index. ",
	          "");
	I_Method1(const osgGA::MatrixManipulator *, getMatrixManipulatorWithIndex, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getMatrixManipulatorWithIndex__unsigned_int,
	          "Get const manipulator assigned to a specified index. ",
	          "");
	I_Method1(osgGA::MatrixManipulator *, getMatrixManipulatorWithKey, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getMatrixManipulatorWithKey__unsigned_int,
	          "Get manipulator assigned to a specified key. ",
	          "");
	I_Method1(const osgGA::MatrixManipulator *, getMatrixManipulatorWithKey, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getMatrixManipulatorWithKey__unsigned_int,
	          "Get const manipulator assigned to a specified key. ",
	          "");
	I_Method1(void, setMinimumDistance, IN, float, minimumDistance,
	          Properties::VIRTUAL,
	          __void__setMinimumDistance__float,
	          "set the minimum distance (as ratio) the eye point can be zoomed in towards the center before the center is pushed forward. ",
	          "");
	I_Method1(void, setCoordinateFrameCallback, IN, osgGA::MatrixManipulator::CoordinateFrameCallback *, cb,
	          Properties::VIRTUAL,
	          __void__setCoordinateFrameCallback__CoordinateFrameCallback_P1,
	          "set the coordinate frame which callback tells the manipulator which way is up, east and north. ",
	          "");
	I_Method1(void, setByMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByMatrix__C5_osg_Matrixd_R1,
	          "Set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method1(void, setByInverseMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByInverseMatrix__C5_osg_Matrixd_R1,
	          "set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getMatrix,
	          "get the position of the manipulator as 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getInverseMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getInverseMatrix,
	          "get the position of the manipulator as a inverse matrix of the manipulator, typically used as a model view matrix. ",
	          "");
	I_Method0(osgUtil::SceneView::FusionDistanceMode, getFusionDistanceMode,
	          Properties::VIRTUAL,
	          __osgUtil_SceneView_FusionDistanceMode__getFusionDistanceMode,
	          "Get the FusionDistanceMode. ",
	          "Used by SceneView for setting up setereo convergence. ");
	I_Method0(float, getFusionDistanceValue,
	          Properties::VIRTUAL,
	          __float__getFusionDistanceValue,
	          "Get the FusionDistanceValue. ",
	          "Used by SceneView for setting up setereo convergence. ");
	I_Method1(void, setNode, IN, osg::Node *, n,
	          Properties::VIRTUAL,
	          __void__setNode__osg_Node_P1,
	          "",
	          "");
	I_Method0(const osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __C5_osg_Node_P1__getNode,
	          "",
	          "");
	I_Method0(osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __osg_Node_P1__getNode,
	          "",
	          "");
	I_MethodWithDefaults4(void, setHomePosition, IN, const osg::Vec3d &, eye, , IN, const osg::Vec3d &, center, , IN, const osg::Vec3d &, up, , IN, bool, autoComputeHomePosition, false,
	                      Properties::VIRTUAL,
	                      __void__setHomePosition__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__bool,
	                      "",
	                      "");
	I_Method1(void, setAutoComputeHomePosition, IN, bool, flag,
	          Properties::VIRTUAL,
	          __void__setAutoComputeHomePosition__bool,
	          "",
	          "");
	I_Method0(void, computeHomePosition,
	          Properties::VIRTUAL,
	          __void__computeHomePosition,
	          "",
	          "");
	I_Method2(void, home, IN, const osgGA::GUIEventAdapter &, ee, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __void__home__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method2(void, init, IN, const osgGA::GUIEventAdapter &, ee, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __void__init__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          Properties::VIRTUAL,
	          __bool__handle__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "",
	          "");
	I_Method3(void, addMatrixManipulator, IN, int, key, IN, std::string, name, IN, osgGA::MatrixManipulator *, cm,
	          Properties::NON_VIRTUAL,
	          __void__addMatrixManipulator__int__std_string__MatrixManipulator_P1,
	          "Add a camera manipulator with an associated name, and a key to trigger the switch,. ",
	          "");
	I_Method1(void, addNumberedMatrixManipulator, IN, osgGA::MatrixManipulator *, cm,
	          Properties::NON_VIRTUAL,
	          __void__addNumberedMatrixManipulator__MatrixManipulator_P1,
	          "Add a camera manipulator with an autogenerated keybinding which is '1' + previous number of camera's registerd. ",
	          "");
	I_Method0(unsigned int, getNumMatrixManipulators,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumMatrixManipulators,
	          "",
	          "");
	I_Method1(void, selectMatrixManipulator, IN, unsigned int, num,
	          Properties::NON_VIRTUAL,
	          __void__selectMatrixManipulator__unsigned_int,
	          "",
	          "");
	I_Method0(osgGA::KeySwitchMatrixManipulator::KeyManipMap &, getKeyManipMap,
	          Properties::NON_VIRTUAL,
	          __KeyManipMap_R1__getKeyManipMap,
	          "Get the complete list of manipulators attached to this keyswitch manipulator. ",
	          "");
	I_Method0(const osgGA::KeySwitchMatrixManipulator::KeyManipMap &, getKeyManipMap,
	          Properties::NON_VIRTUAL,
	          __C5_KeyManipMap_R1__getKeyManipMap,
	          "Get the const complete list of manipulators attached to this keyswitch manipulator. ",
	          "");
	I_Method0(osgGA::MatrixManipulator *, getCurrentMatrixManipulator,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getCurrentMatrixManipulator,
	          "Get the current active manipulators. ",
	          "");
	I_Method0(const osgGA::MatrixManipulator *, getCurrentMatrixManipulator,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getCurrentMatrixManipulator,
	          "Get the const current active manipulators. ",
	          "");
	I_Method1(osgGA::MatrixManipulator *, getMatrixManipulatorWithIndex, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getMatrixManipulatorWithIndex__unsigned_int,
	          "Get manipulator assigned to a specified index. ",
	          "");
	I_Method1(const osgGA::MatrixManipulator *, getMatrixManipulatorWithIndex, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getMatrixManipulatorWithIndex__unsigned_int,
	          "Get const manipulator assigned to a specified index. ",
	          "");
	I_Method1(osgGA::MatrixManipulator *, getMatrixManipulatorWithKey, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getMatrixManipulatorWithKey__unsigned_int,
	          "Get manipulator assigned to a specified key. ",
	          "");
	I_Method1(const osgGA::MatrixManipulator *, getMatrixManipulatorWithKey, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getMatrixManipulatorWithKey__unsigned_int,
	          "Get const manipulator assigned to a specified key. ",
	          "");
	I_Method1(void, setMinimumDistance, IN, float, minimumDistance,
	          Properties::VIRTUAL,
	          __void__setMinimumDistance__float,
	          "set the minimum distance (as ratio) the eye point can be zoomed in towards the center before the center is pushed forward. ",
	          "");
	I_Method1(void, setCoordinateFrameCallback, IN, osgGA::MatrixManipulator::CoordinateFrameCallback *, cb,
	          Properties::VIRTUAL,
	          __void__setCoordinateFrameCallback__CoordinateFrameCallback_P1,
	          "set the coordinate frame which callback tells the manipulator which way is up, east and north. ",
	          "");
	I_Method1(void, setByMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByMatrix__C5_osg_Matrixd_R1,
	          "Set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method1(void, setByInverseMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByInverseMatrix__C5_osg_Matrixd_R1,
	          "set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getMatrix,
	          "get the position of the manipulator as 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getInverseMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getInverseMatrix,
	          "get the position of the manipulator as a inverse matrix of the manipulator, typically used as a model view matrix. ",
	          "");
	I_Method0(osgUtil::SceneView::FusionDistanceMode, getFusionDistanceMode,
	          Properties::VIRTUAL,
	          __osgUtil_SceneView_FusionDistanceMode__getFusionDistanceMode,
	          "Get the FusionDistanceMode. ",
	          "Used by SceneView for setting up setereo convergence. ");
	I_Method0(float, getFusionDistanceValue,
	          Properties::VIRTUAL,
	          __float__getFusionDistanceValue,
	          "Get the FusionDistanceValue. ",
	          "Used by SceneView for setting up setereo convergence. ");
	I_Method1(void, setNode, IN, osg::Node *, n,
	          Properties::VIRTUAL,
	          __void__setNode__osg_Node_P1,
	          "",
	          "");
	I_Method0(const osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __C5_osg_Node_P1__getNode,
	          "",
	          "");
	I_Method0(osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __osg_Node_P1__getNode,
	          "",
	          "");
	I_MethodWithDefaults4(void, setHomePosition, IN, const osg::Vec3d &, eye, , IN, const osg::Vec3d &, center, , IN, const osg::Vec3d &, up, , IN, bool, autoComputeHomePosition, false,
	                      Properties::VIRTUAL,
	                      __void__setHomePosition__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__bool,
	                      "",
	                      "");
	I_Method1(void, setAutoComputeHomePosition, IN, bool, flag,
	          Properties::VIRTUAL,
	          __void__setAutoComputeHomePosition__bool,
	          "",
	          "");
	I_Method0(void, computeHomePosition,
	          Properties::VIRTUAL,
	          __void__computeHomePosition,
	          "",
	          "");
	I_Method2(void, home, IN, const osgGA::GUIEventAdapter &, ee, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __void__home__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method2(void, init, IN, const osgGA::GUIEventAdapter &, ee, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __void__init__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          Properties::VIRTUAL,
	          __bool__handle__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_SimpleProperty(bool, AutoComputeHomePosition, 
	                 0, 
	                 __void__setAutoComputeHomePosition__bool);
	I_SimpleProperty(const osg::Matrixd &, ByInverseMatrix, 
	                 0, 
	                 __void__setByInverseMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(const osg::Matrixd &, ByMatrix, 
	                 0, 
	                 __void__setByMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(osgGA::MatrixManipulator::CoordinateFrameCallback *, CoordinateFrameCallback, 
	                 0, 
	                 __void__setCoordinateFrameCallback__CoordinateFrameCallback_P1);
	I_SimpleProperty(osgGA::MatrixManipulator *, CurrentMatrixManipulator, 
	                 __MatrixManipulator_P1__getCurrentMatrixManipulator, 
	                 0);
	I_SimpleProperty(osgUtil::SceneView::FusionDistanceMode, FusionDistanceMode, 
	                 __osgUtil_SceneView_FusionDistanceMode__getFusionDistanceMode, 
	                 0);
	I_SimpleProperty(float, FusionDistanceValue, 
	                 __float__getFusionDistanceValue, 
	                 0);
	I_SimpleProperty(osg::Matrixd, InverseMatrix, 
	                 __osg_Matrixd__getInverseMatrix, 
	                 0);
	I_SimpleProperty(osgGA::KeySwitchMatrixManipulator::KeyManipMap &, KeyManipMap, 
	                 __KeyManipMap_R1__getKeyManipMap, 
	                 0);
	I_SimpleProperty(osg::Matrixd, Matrix, 
	                 __osg_Matrixd__getMatrix, 
	                 0);
	I_SimpleProperty(float, MinimumDistance, 
	                 0, 
	                 __void__setMinimumDistance__float);
	I_SimpleProperty(osg::Node *, Node, 
	                 __osg_Node_P1__getNode, 
	                 __void__setNode__osg_Node_P1);
END_REFLECTOR

TYPE_NAME_ALIAS(std::pair< std::string COMMA  osg::ref_ptr< osgGA::MatrixManipulator > >, osgGA::KeySwitchMatrixManipulator::NamedManipulator);

TYPE_NAME_ALIAS(std::map< int COMMA  osgGA::KeySwitchMatrixManipulator::NamedManipulator >, osgGA::KeySwitchMatrixManipulator::KeyManipMap);

BEGIN_OBJECT_REFLECTOR(osgGA::KeySwitchMatrixManipulator)
	I_BaseType(osgGA::MatrixManipulator);
	I_BaseType(osgGA::MatrixManipulator);
	I_Constructor0(____KeySwitchMatrixManipulator,
	               "",
	               "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "",
	          "");
	I_Method3(void, addMatrixManipulator, IN, int, key, IN, std::string, name, IN, osgGA::MatrixManipulator *, cm,
	          Properties::NON_VIRTUAL,
	          __void__addMatrixManipulator__int__std_string__MatrixManipulator_P1,
	          "Add a camera manipulator with an associated name, and a key to trigger the switch,. ",
	          "");
	I_Method1(void, addNumberedMatrixManipulator, IN, osgGA::MatrixManipulator *, cm,
	          Properties::NON_VIRTUAL,
	          __void__addNumberedMatrixManipulator__MatrixManipulator_P1,
	          "Add a camera manipulator with an autogenerated keybinding which is '1' + previous number of camera's registerd. ",
	          "");
	I_Method0(unsigned int, getNumMatrixManipulators,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumMatrixManipulators,
	          "",
	          "");
	I_Method1(void, selectMatrixManipulator, IN, unsigned int, num,
	          Properties::NON_VIRTUAL,
	          __void__selectMatrixManipulator__unsigned_int,
	          "",
	          "");
	I_Method0(osgGA::KeySwitchMatrixManipulator::KeyManipMap &, getKeyManipMap,
	          Properties::NON_VIRTUAL,
	          __KeyManipMap_R1__getKeyManipMap,
	          "Get the complete list of manipulators attached to this keyswitch manipulator. ",
	          "");
	I_Method0(const osgGA::KeySwitchMatrixManipulator::KeyManipMap &, getKeyManipMap,
	          Properties::NON_VIRTUAL,
	          __C5_KeyManipMap_R1__getKeyManipMap,
	          "Get the const complete list of manipulators attached to this keyswitch manipulator. ",
	          "");
	I_Method0(osgGA::MatrixManipulator *, getCurrentMatrixManipulator,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getCurrentMatrixManipulator,
	          "Get the current active manipulators. ",
	          "");
	I_Method0(const osgGA::MatrixManipulator *, getCurrentMatrixManipulator,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getCurrentMatrixManipulator,
	          "Get the const current active manipulators. ",
	          "");
	I_Method1(osgGA::MatrixManipulator *, getMatrixManipulatorWithIndex, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getMatrixManipulatorWithIndex__unsigned_int,
	          "Get manipulator assigned to a specified index. ",
	          "");
	I_Method1(const osgGA::MatrixManipulator *, getMatrixManipulatorWithIndex, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getMatrixManipulatorWithIndex__unsigned_int,
	          "Get const manipulator assigned to a specified index. ",
	          "");
	I_Method1(osgGA::MatrixManipulator *, getMatrixManipulatorWithKey, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getMatrixManipulatorWithKey__unsigned_int,
	          "Get manipulator assigned to a specified key. ",
	          "");
	I_Method1(const osgGA::MatrixManipulator *, getMatrixManipulatorWithKey, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getMatrixManipulatorWithKey__unsigned_int,
	          "Get const manipulator assigned to a specified key. ",
	          "");
	I_Method1(void, setMinimumDistance, IN, float, minimumDistance,
	          Properties::VIRTUAL,
	          __void__setMinimumDistance__float,
	          "set the minimum distance (as ratio) the eye point can be zoomed in towards the center before the center is pushed forward. ",
	          "");
	I_Method1(void, setCoordinateFrameCallback, IN, osgGA::MatrixManipulator::CoordinateFrameCallback *, cb,
	          Properties::VIRTUAL,
	          __void__setCoordinateFrameCallback__CoordinateFrameCallback_P1,
	          "set the coordinate frame which callback tells the manipulator which way is up, east and north. ",
	          "");
	I_Method1(void, setByMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByMatrix__C5_osg_Matrixd_R1,
	          "Set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method1(void, setByInverseMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByInverseMatrix__C5_osg_Matrixd_R1,
	          "set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getMatrix,
	          "get the position of the manipulator as 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getInverseMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getInverseMatrix,
	          "get the position of the manipulator as a inverse matrix of the manipulator, typically used as a model view matrix. ",
	          "");
	I_Method0(osgUtil::SceneView::FusionDistanceMode, getFusionDistanceMode,
	          Properties::VIRTUAL,
	          __osgUtil_SceneView_FusionDistanceMode__getFusionDistanceMode,
	          "Get the FusionDistanceMode. ",
	          "Used by SceneView for setting up setereo convergence. ");
	I_Method0(float, getFusionDistanceValue,
	          Properties::VIRTUAL,
	          __float__getFusionDistanceValue,
	          "Get the FusionDistanceValue. ",
	          "Used by SceneView for setting up setereo convergence. ");
	I_Method1(void, setNode, IN, osg::Node *, n,
	          Properties::VIRTUAL,
	          __void__setNode__osg_Node_P1,
	          "",
	          "");
	I_Method0(const osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __C5_osg_Node_P1__getNode,
	          "",
	          "");
	I_Method0(osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __osg_Node_P1__getNode,
	          "",
	          "");
	I_MethodWithDefaults4(void, setHomePosition, IN, const osg::Vec3d &, eye, , IN, const osg::Vec3d &, center, , IN, const osg::Vec3d &, up, , IN, bool, autoComputeHomePosition, false,
	                      Properties::VIRTUAL,
	                      __void__setHomePosition__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__bool,
	                      "",
	                      "");
	I_Method1(void, setAutoComputeHomePosition, IN, bool, flag,
	          Properties::VIRTUAL,
	          __void__setAutoComputeHomePosition__bool,
	          "",
	          "");
	I_Method0(void, computeHomePosition,
	          Properties::VIRTUAL,
	          __void__computeHomePosition,
	          "",
	          "");
	I_Method2(void, home, IN, const osgGA::GUIEventAdapter &, ee, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __void__home__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method2(void, init, IN, const osgGA::GUIEventAdapter &, ee, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __void__init__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          Properties::VIRTUAL,
	          __bool__handle__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "",
	          "");
	I_Method3(void, addMatrixManipulator, IN, int, key, IN, std::string, name, IN, osgGA::MatrixManipulator *, cm,
	          Properties::NON_VIRTUAL,
	          __void__addMatrixManipulator__int__std_string__MatrixManipulator_P1,
	          "Add a camera manipulator with an associated name, and a key to trigger the switch,. ",
	          "");
	I_Method1(void, addNumberedMatrixManipulator, IN, osgGA::MatrixManipulator *, cm,
	          Properties::NON_VIRTUAL,
	          __void__addNumberedMatrixManipulator__MatrixManipulator_P1,
	          "Add a camera manipulator with an autogenerated keybinding which is '1' + previous number of camera's registerd. ",
	          "");
	I_Method0(unsigned int, getNumMatrixManipulators,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumMatrixManipulators,
	          "",
	          "");
	I_Method1(void, selectMatrixManipulator, IN, unsigned int, num,
	          Properties::NON_VIRTUAL,
	          __void__selectMatrixManipulator__unsigned_int,
	          "",
	          "");
	I_Method0(osgGA::KeySwitchMatrixManipulator::KeyManipMap &, getKeyManipMap,
	          Properties::NON_VIRTUAL,
	          __KeyManipMap_R1__getKeyManipMap,
	          "Get the complete list of manipulators attached to this keyswitch manipulator. ",
	          "");
	I_Method0(const osgGA::KeySwitchMatrixManipulator::KeyManipMap &, getKeyManipMap,
	          Properties::NON_VIRTUAL,
	          __C5_KeyManipMap_R1__getKeyManipMap,
	          "Get the const complete list of manipulators attached to this keyswitch manipulator. ",
	          "");
	I_Method0(osgGA::MatrixManipulator *, getCurrentMatrixManipulator,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getCurrentMatrixManipulator,
	          "Get the current active manipulators. ",
	          "");
	I_Method0(const osgGA::MatrixManipulator *, getCurrentMatrixManipulator,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getCurrentMatrixManipulator,
	          "Get the const current active manipulators. ",
	          "");
	I_Method1(osgGA::MatrixManipulator *, getMatrixManipulatorWithIndex, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getMatrixManipulatorWithIndex__unsigned_int,
	          "Get manipulator assigned to a specified index. ",
	          "");
	I_Method1(const osgGA::MatrixManipulator *, getMatrixManipulatorWithIndex, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getMatrixManipulatorWithIndex__unsigned_int,
	          "Get const manipulator assigned to a specified index. ",
	          "");
	I_Method1(osgGA::MatrixManipulator *, getMatrixManipulatorWithKey, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __MatrixManipulator_P1__getMatrixManipulatorWithKey__unsigned_int,
	          "Get manipulator assigned to a specified key. ",
	          "");
	I_Method1(const osgGA::MatrixManipulator *, getMatrixManipulatorWithKey, IN, unsigned int, key,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixManipulator_P1__getMatrixManipulatorWithKey__unsigned_int,
	          "Get const manipulator assigned to a specified key. ",
	          "");
	I_Method1(void, setMinimumDistance, IN, float, minimumDistance,
	          Properties::VIRTUAL,
	          __void__setMinimumDistance__float,
	          "set the minimum distance (as ratio) the eye point can be zoomed in towards the center before the center is pushed forward. ",
	          "");
	I_Method1(void, setCoordinateFrameCallback, IN, osgGA::MatrixManipulator::CoordinateFrameCallback *, cb,
	          Properties::VIRTUAL,
	          __void__setCoordinateFrameCallback__CoordinateFrameCallback_P1,
	          "set the coordinate frame which callback tells the manipulator which way is up, east and north. ",
	          "");
	I_Method1(void, setByMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByMatrix__C5_osg_Matrixd_R1,
	          "Set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method1(void, setByInverseMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByInverseMatrix__C5_osg_Matrixd_R1,
	          "set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getMatrix,
	          "get the position of the manipulator as 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getInverseMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getInverseMatrix,
	          "get the position of the manipulator as a inverse matrix of the manipulator, typically used as a model view matrix. ",
	          "");
	I_Method0(osgUtil::SceneView::FusionDistanceMode, getFusionDistanceMode,
	          Properties::VIRTUAL,
	          __osgUtil_SceneView_FusionDistanceMode__getFusionDistanceMode,
	          "Get the FusionDistanceMode. ",
	          "Used by SceneView for setting up setereo convergence. ");
	I_Method0(float, getFusionDistanceValue,
	          Properties::VIRTUAL,
	          __float__getFusionDistanceValue,
	          "Get the FusionDistanceValue. ",
	          "Used by SceneView for setting up setereo convergence. ");
	I_Method1(void, setNode, IN, osg::Node *, n,
	          Properties::VIRTUAL,
	          __void__setNode__osg_Node_P1,
	          "",
	          "");
	I_Method0(const osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __C5_osg_Node_P1__getNode,
	          "",
	          "");
	I_Method0(osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __osg_Node_P1__getNode,
	          "",
	          "");
	I_MethodWithDefaults4(void, setHomePosition, IN, const osg::Vec3d &, eye, , IN, const osg::Vec3d &, center, , IN, const osg::Vec3d &, up, , IN, bool, autoComputeHomePosition, false,
	                      Properties::VIRTUAL,
	                      __void__setHomePosition__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__bool,
	                      "",
	                      "");
	I_Method1(void, setAutoComputeHomePosition, IN, bool, flag,
	          Properties::VIRTUAL,
	          __void__setAutoComputeHomePosition__bool,
	          "",
	          "");
	I_Method0(void, computeHomePosition,
	          Properties::VIRTUAL,
	          __void__computeHomePosition,
	          "",
	          "");
	I_Method2(void, home, IN, const osgGA::GUIEventAdapter &, ee, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __void__home__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method2(void, init, IN, const osgGA::GUIEventAdapter &, ee, IN, osgGA::GUIActionAdapter &, aa,
	          Properties::VIRTUAL,
	          __void__init__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          Properties::VIRTUAL,
	          __bool__handle__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_SimpleProperty(bool, AutoComputeHomePosition, 
	                 0, 
	                 __void__setAutoComputeHomePosition__bool);
	I_SimpleProperty(const osg::Matrixd &, ByInverseMatrix, 
	                 0, 
	                 __void__setByInverseMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(const osg::Matrixd &, ByMatrix, 
	                 0, 
	                 __void__setByMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(osgGA::MatrixManipulator::CoordinateFrameCallback *, CoordinateFrameCallback, 
	                 0, 
	                 __void__setCoordinateFrameCallback__CoordinateFrameCallback_P1);
	I_SimpleProperty(osgGA::MatrixManipulator *, CurrentMatrixManipulator, 
	                 __MatrixManipulator_P1__getCurrentMatrixManipulator, 
	                 0);
	I_SimpleProperty(osgUtil::SceneView::FusionDistanceMode, FusionDistanceMode, 
	                 __osgUtil_SceneView_FusionDistanceMode__getFusionDistanceMode, 
	                 0);
	I_SimpleProperty(float, FusionDistanceValue, 
	                 __float__getFusionDistanceValue, 
	                 0);
	I_SimpleProperty(osg::Matrixd, InverseMatrix, 
	                 __osg_Matrixd__getInverseMatrix, 
	                 0);
	I_SimpleProperty(osgGA::KeySwitchMatrixManipulator::KeyManipMap &, KeyManipMap, 
	                 __KeyManipMap_R1__getKeyManipMap, 
	                 0);
	I_SimpleProperty(osg::Matrixd, Matrix, 
	                 __osg_Matrixd__getMatrix, 
	                 0);
	I_SimpleProperty(float, MinimumDistance, 
	                 0, 
	                 __void__setMinimumDistance__float);
	I_SimpleProperty(osg::Node *, Node, 
	                 __osg_Node_P1__getNode, 
	                 __void__setNode__osg_Node_P1);
END_REFLECTOR

