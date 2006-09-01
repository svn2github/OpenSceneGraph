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
#include <osg/Matrixd>
#include <osg/Node>
#include <osgGA/FlightManipulator>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osgGA::FlightManipulator::YawControlMode)
	I_EnumLabel(osgGA::FlightManipulator::YAW_AUTOMATICALLY_WHEN_BANKED);
	I_EnumLabel(osgGA::FlightManipulator::NO_AUTOMATIC_YAW);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgGA::FlightManipulator)
	I_BaseType(osgGA::MatrixManipulator);
	I_Constructor0();
	I_Method0(const char *, className);
	I_Method1(void, setByMatrix, IN, const osg::Matrixd &, matrix);
	I_Method1(void, setByInverseMatrix, IN, const osg::Matrixd &, matrix);
	I_Method0(osg::Matrixd, getMatrix);
	I_Method0(osg::Matrixd, getInverseMatrix);
	I_Method1(void, setNode, IN, osg::Node *, x);
	I_Method0(const osg::Node *, getNode);
	I_Method0(osg::Node *, getNode);
	I_Method2(void, home, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us);
	I_Method2(void, init, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us);
	I_Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, us);
	I_Method1(void, getUsage, IN, osg::ApplicationUsage &, usage);
	I_Method1(void, setYawControlMode, IN, osgGA::FlightManipulator::YawControlMode, ycm);
	I_Method1(void, setModelScale, IN, double, in_ms);
	I_Method0(double, getModelScale);
	I_Method1(void, setAcceleration, IN, double, in_acc);
	I_Method0(double, getAcceleration);
	I_Method1(void, setVelocity, IN, double, in_vel);
	I_Method0(double, getVelocity);
	I_Property(double, Acceleration);
	I_WriteOnlyProperty(const osg::Matrixd &, ByInverseMatrix);
	I_WriteOnlyProperty(const osg::Matrixd &, ByMatrix);
	I_ReadOnlyProperty(osg::Matrixd, InverseMatrix);
	I_ReadOnlyProperty(osg::Matrixd, Matrix);
	I_Property(double, ModelScale);
	I_Property(osg::Node *, Node);
	I_Property(double, Velocity);
	I_WriteOnlyProperty(osgGA::FlightManipulator::YawControlMode, YawControlMode);
END_REFLECTOR

