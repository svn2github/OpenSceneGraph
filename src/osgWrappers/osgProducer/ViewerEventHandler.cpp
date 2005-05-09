// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/ApplicationUsage>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIEventHandlerVisitor>
#include <osgProducer/OsgCameraGroup>
#include <osgProducer/ViewerEventHandler>

BEGIN_ENUM_REFLECTOR(osgProducer::ViewerEventHandler::FrameStatsMode)
	EnumLabel(osgProducer::ViewerEventHandler::NO_STATS);
	EnumLabel(osgProducer::ViewerEventHandler::FRAME_RATE);
	EnumLabel(osgProducer::ViewerEventHandler::CAMERA_STATS);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osgProducer::ViewerEventHandler)
	BaseType(osgGA::GUIEventHandler);
	Constructor1(IN, osgProducer::OsgCameraGroup *, cg);
	Method2(bool, handle, IN, const osgGA::GUIEventAdapter &, ea, IN, osgGA::GUIActionAdapter &, aa);
	Method1(void, accept, IN, osgGA::GUIEventHandlerVisitor &, gehv);
	Method1(void, getUsage, IN, osg::ApplicationUsage &, usage);
	Method0(osgProducer::OsgCameraGroup *, getOsgCameraGroup);
	Method0(const osgProducer::OsgCameraGroup *, getOsgCameraGroup);
	Method1(void, setWriteNodeFileName, IN, const std::string &, filename);
	Method0(const std::string &, getWriteNodeFileName);
	Method1(void, setDisplayHelp, IN, bool, displayHelp);
	Method0(bool, getDisplayHelp);
	Method1(void, setFrameStatsMode, IN, osgProducer::ViewerEventHandler::FrameStatsMode, mode);
	Method0(osgProducer::ViewerEventHandler::FrameStatsMode, getFrameStatsMode);
	Method1(void, setWriteImageOnNextFrame, IN, bool, writeImageOnNextFrame);
	Method1(void, setWriteImageFileName, IN, const std::string &, filename);
	Method0(const std::string &, getWriteImageFileName);
	Property(bool, DisplayHelp);
	Property(osgProducer::ViewerEventHandler::FrameStatsMode, FrameStatsMode);
	ReadOnlyProperty(osgProducer::OsgCameraGroup *, OsgCameraGroup);
	Property(const std::string &, WriteImageFileName);
	WriteOnlyProperty(bool, WriteImageOnNextFrame);
	Property(const std::string &, WriteNodeFileName);
END_REFLECTOR

