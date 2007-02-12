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

#include <osgGA/EventQueue>
#include <osgGA/GUIEventAdapter>
#include <osgProducer/KeyboardMouseCallback>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(osgGA::EventQueue::Events, osgProducer::KeyboardMouseCallback::EventQueue);

BEGIN_OBJECT_REFLECTOR(osgProducer::KeyboardMouseCallback)
	I_ConstructorWithDefaults3(IN, Producer::KeyboardMouse *, keyboardMouse, , IN, bool &, done, , IN, bool, escapeKeySetsDone, true,
	                           ____KeyboardMouseCallback__Producer_KeyboardMouse_P1__bool_R1__bool,
	                           "",
	                           "");
	I_Method1(void, mouseScroll, IN, Producer::KeyboardMouseCallback::ScrollingMotion, sm,
	          Properties::VIRTUAL,
	          __void__mouseScroll__Producer_KeyboardMouseCallback_ScrollingMotion,
	          "",
	          "");
	I_Method2(void, mouseScroll2D, IN, float, x, IN, float, x,
	          Properties::VIRTUAL,
	          __void__mouseScroll2D__float__float,
	          "",
	          "");
	I_Method1(void, penPressure, IN, float, pressure,
	          Properties::VIRTUAL,
	          __void__penPressure__float,
	          "",
	          "");
	I_Method2(void, penProximity, IN, Producer::KeyboardMouseCallback::TabletPointerType, x, IN, bool, x,
	          Properties::VIRTUAL,
	          __void__penProximity__Producer_KeyboardMouseCallback_TabletPointerType__bool,
	          "",
	          "");
	I_Method2(void, mouseMotion, IN, float, mx, IN, float, my,
	          Properties::VIRTUAL,
	          __void__mouseMotion__float__float,
	          "",
	          "");
	I_Method2(void, passiveMouseMotion, IN, float, mx, IN, float, my,
	          Properties::VIRTUAL,
	          __void__passiveMouseMotion__float__float,
	          "",
	          "");
	I_Method2(void, mouseWarp, IN, float, mx, IN, float, my,
	          Properties::VIRTUAL,
	          __void__mouseWarp__float__float,
	          "",
	          "");
	I_Method3(void, buttonPress, IN, float, mx, IN, float, my, IN, unsigned int, mbutton,
	          Properties::VIRTUAL,
	          __void__buttonPress__float__float__unsigned_int,
	          "",
	          "");
	I_Method3(void, doubleButtonPress, IN, float, mx, IN, float, my, IN, unsigned int, mbutton,
	          Properties::VIRTUAL,
	          __void__doubleButtonPress__float__float__unsigned_int,
	          "",
	          "");
	I_Method3(void, buttonRelease, IN, float, mx, IN, float, my, IN, unsigned int, mbutton,
	          Properties::VIRTUAL,
	          __void__buttonRelease__float__float__unsigned_int,
	          "",
	          "");
	I_Method1(void, keyPress, IN, Producer::KeyCharacter, key,
	          Properties::VIRTUAL,
	          __void__keyPress__Producer_KeyCharacter,
	          "",
	          "");
	I_Method1(void, keyRelease, IN, Producer::KeyCharacter, key,
	          Properties::VIRTUAL,
	          __void__keyRelease__Producer_KeyCharacter,
	          "",
	          "");
	I_Method1(void, specialKeyPress, IN, Producer::KeyCharacter, key,
	          Properties::VIRTUAL,
	          __void__specialKeyPress__Producer_KeyCharacter,
	          "",
	          "");
	I_Method1(void, specialKeyRelease, IN, Producer::KeyCharacter, key,
	          Properties::VIRTUAL,
	          __void__specialKeyRelease__Producer_KeyCharacter,
	          "",
	          "");
	I_Method4(void, windowConfig, IN, int, x, IN, int, y, IN, unsigned int, width, IN, unsigned int, height,
	          Properties::VIRTUAL,
	          __void__windowConfig__int__int__unsigned_int__unsigned_int,
	          "",
	          "");
	I_Method0(void, shutdown,
	          Properties::VIRTUAL,
	          __void__shutdown,
	          "",
	          "");
	I_Method1(void, setEscapeSetDone, IN, bool, esc,
	          Properties::NON_VIRTUAL,
	          __void__setEscapeSetDone__bool,
	          "",
	          "");
	I_Method0(bool, getEscapeSetDone,
	          Properties::NON_VIRTUAL,
	          __bool__getEscapeSetDone,
	          "",
	          "");
	I_Method1(void, setEventQueue, IN, osgGA::EventQueue *, eventQueue,
	          Properties::NON_VIRTUAL,
	          __void__setEventQueue__osgGA_EventQueue_P1,
	          "",
	          "");
	I_Method0(osgGA::EventQueue *, getEventQueue,
	          Properties::NON_VIRTUAL,
	          __osgGA_EventQueue_P1__getEventQueue,
	          "",
	          "");
	I_Method1(bool, takeEventQueue, IN, osgProducer::KeyboardMouseCallback::EventQueue &, queue,
	          Properties::NON_VIRTUAL,
	          __bool__takeEventQueue__EventQueue_R1,
	          "",
	          "");
	I_Method1(bool, copyEventQueue, IN, osgProducer::KeyboardMouseCallback::EventQueue &, queue,
	          Properties::NON_VIRTUAL,
	          __bool__copyEventQueue__EventQueue_R1,
	          "",
	          "");
	I_Method1(void, setEventQueue, IN, osgProducer::KeyboardMouseCallback::EventQueue &, queue,
	          Properties::NON_VIRTUAL,
	          __void__setEventQueue__EventQueue_R1,
	          "",
	          "");
	I_Method1(void, appendEventQueue, IN, osgProducer::KeyboardMouseCallback::EventQueue &, queue,
	          Properties::NON_VIRTUAL,
	          __void__appendEventQueue__EventQueue_R1,
	          "",
	          "");
	I_Method0(bool, done,
	          Properties::NON_VIRTUAL,
	          __bool__done,
	          "",
	          "");
	I_Method0(double, getTime,
	          Properties::NON_VIRTUAL,
	          __double__getTime,
	          "",
	          "");
	I_Method0(Producer::KeyboardMouse *, getKeyboardMouse,
	          Properties::NON_VIRTUAL,
	          __Producer_KeyboardMouse_P1__getKeyboardMouse,
	          "",
	          "");
	I_Method0(const Producer::KeyboardMouse *, getKeyboardMouse,
	          Properties::NON_VIRTUAL,
	          __C5_Producer_KeyboardMouse_P1__getKeyboardMouse,
	          "",
	          "");
	I_Method0(osgGA::GUIEventAdapter *, createEventAdapter,
	          Properties::NON_VIRTUAL,
	          __osgGA_GUIEventAdapter_P1__createEventAdapter,
	          "",
	          "");
	I_Method0(void, updateWindowSize,
	          Properties::NON_VIRTUAL,
	          __void__updateWindowSize,
	          "",
	          "");
	I_SimpleProperty(bool, EscapeSetDone, 
	                 __bool__getEscapeSetDone, 
	                 __void__setEscapeSetDone__bool);
	I_SimpleProperty(osgGA::EventQueue *, EventQueue, 
	                 __osgGA_EventQueue_P1__getEventQueue, 
	                 __void__setEventQueue__osgGA_EventQueue_P1);
	I_SimpleProperty(Producer::KeyboardMouse *, KeyboardMouse, 
	                 __Producer_KeyboardMouse_P1__getKeyboardMouse, 
	                 0);
	I_SimpleProperty(double, Time, 
	                 __double__getTime, 
	                 0);
END_REFLECTOR

