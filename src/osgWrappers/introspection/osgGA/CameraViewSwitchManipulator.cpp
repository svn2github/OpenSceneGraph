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

#include <osg/ApplicationUsage>
#include <osg/CameraView>
#include <osg/Matrixd>
#include <osg/Node>
#include <osgGA/CameraViewSwitchManipulator>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

#include <osg/observer_ptr>
        
TYPE_NAME_ALIAS(std::vector< osg::ref_ptr< osg::CameraView > >, osgGA::CameraViewSwitchManipulator::CameraViewList)

BEGIN_OBJECT_REFLECTOR(osgGA::CameraViewSwitchManipulator)
	I_DeclaringFile("osgGA/CameraViewSwitchManipulator");
	I_BaseType(osgGA::CameraManipulator);
	I_Constructor0(____CameraViewSwitchManipulator,
	               "",
	               "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, setByMatrix, IN, const osg::Matrixd &, x,
	          Properties::VIRTUAL,
	          __void__setByMatrix__C5_osg_Matrixd_R1,
	          "set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method1(void, setByInverseMatrix, IN, const osg::Matrixd &, x,
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
	I_Method1(void, setNode, IN, osg::Node *, x,
	          Properties::VIRTUAL,
	          __void__setNode__osg_Node_P1,
	          "Attach a node to the manipulator. ",
	          "Automatically detaches previously attached node. setNode(NULL) detaches previously nodes. Is ignored by manipulators which do not require a reference model. ");
	I_Method0(const osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __C5_osg_Node_P1__getNode,
	          "Return node if attached. ",
	          "");
	I_Method0(osg::Node *, getNode,
	          Properties::VIRTUAL,
	          __osg_Node_P1__getNode,
	          "Return node if attached. ",
	          "");
	I_Method2(void, init, IN, const osgGA::GUIEventAdapter &, x, IN, osgGA::GUIActionAdapter &, x,
	          Properties::VIRTUAL,
	          __void__init__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "Start/restart the manipulator. ",
	          "");
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us,
	          Properties::VIRTUAL,
	          __bool__handle__C5_GUIEventAdapter_R1__GUIActionAdapter_R1,
	          "handle events, return true if handled, false otherwise. ",
	          "");
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage,
	          Properties::VIRTUAL,
	          __void__getUsage__osg_ApplicationUsage_R1,
	          "Get the keyboard and mouse usage of this manipulator. ",
	          "");
	I_SimpleProperty(const osg::Matrixd &, ByInverseMatrix, 
	                 0, 
	                 __void__setByInverseMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(const osg::Matrixd &, ByMatrix, 
	                 0, 
	                 __void__setByMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(osg::Matrixd, InverseMatrix, 
	                 __osg_Matrixd__getInverseMatrix, 
	                 0);
	I_SimpleProperty(osg::Matrixd, Matrix, 
	                 __osg_Matrixd__getMatrix, 
	                 0);
	I_SimpleProperty(osg::Node *, Node, 
	                 __osg_Node_P1__getNode, 
	                 __void__setNode__osg_Node_P1);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osg::CameraView >)
	I_DeclaringFile("osg/ref_ptr");
	I_Constructor0(____ref_ptr,
	               "",
	               "");
	I_Constructor1(IN, osg::CameraView *, ptr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osg::CameraView > &, rp,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__C5_ref_ptr_R1,
	               "",
	               "");
	I_Constructor1(IN, osg::observer_ptr< osg::CameraView > &, optr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__observer_ptrT1_T__R1,
	               "",
	               "");
	I_Method0(osg::CameraView *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(osg::CameraView *, release,
	          Properties::NON_VIRTUAL,
	          __T_P1__release,
	          "",
	          "");
	I_Method1(void, swap, IN, osg::ref_ptr< osg::CameraView > &, rp,
	          Properties::NON_VIRTUAL,
	          __void__swap__ref_ptr_R1,
	          "",
	          "");
	I_SimpleProperty(osg::CameraView *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::ref_ptr< osg::CameraView > >)

