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

TYPE_NAME_ALIAS(std::map< std::string COMMA  std::string >, osg::ApplicationUsage::UsageMap);

BEGIN_ENUM_REFLECTOR(osg::ApplicationUsage::Type)
	EnumLabel(osg::ApplicationUsage::COMMAND_LINE_OPTION);
	EnumLabel(osg::ApplicationUsage::ENVIRONMENTAL_VARIABLE);
	EnumLabel(osg::ApplicationUsage::KEYBOARD_MOUSE_BINDING);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ApplicationUsage)
	Constructor0();
	Constructor1(IN, const std::string &, commandLineUsage);
	Method1(void, setApplicationName, IN, const std::string &, name);
	Method0(const std::string &, getApplicationName);
	Method1(void, setDescription, IN, const std::string &, desc);
	Method0(const std::string &, getDescription);
	Method3(void, addUsageExplanation, IN, osg::ApplicationUsage::Type, type, IN, const std::string &, option, IN, const std::string &, explanation);
	Method1(void, setCommandLineUsage, IN, const std::string &, explanation);
	Method0(const std::string &, getCommandLineUsage);
	MethodWithDefaults3(void, addCommandLineOption, IN, const std::string &, option, , IN, const std::string &, explanation, , IN, const std::string &, defaultValue, "");
	Method1(void, setCommandLineOptions, IN, const osg::ApplicationUsage::UsageMap &, usageMap);
	Method0(const osg::ApplicationUsage::UsageMap &, getCommandLineOptions);
	Method1(void, setCommandLineOptionsDefaults, IN, const osg::ApplicationUsage::UsageMap &, usageMap);
	Method0(const osg::ApplicationUsage::UsageMap &, getCommandLineOptionsDefaults);
	MethodWithDefaults3(void, addEnvironmentalVariable, IN, const std::string &, option, , IN, const std::string &, explanation, , IN, const std::string &, defaultValue, "");
	Method1(void, setEnvironmentalVariables, IN, const osg::ApplicationUsage::UsageMap &, usageMap);
	Method0(const osg::ApplicationUsage::UsageMap &, getEnvironmentalVariables);
	Method1(void, setEnvironmentalVariablesDefaults, IN, const osg::ApplicationUsage::UsageMap &, usageMap);
	Method0(const osg::ApplicationUsage::UsageMap &, getEnvironmentalVariablesDefaults);
	Method2(void, addKeyboardMouseBinding, IN, const std::string &, option, IN, const std::string &, explanation);
	Method1(void, setKeyboardMouseBindings, IN, const osg::ApplicationUsage::UsageMap &, usageMap);
	Method0(const osg::ApplicationUsage::UsageMap &, getKeyboardMouseBindings);
	MethodWithDefaults5(void, getFormattedString, IN, std::string &, str, , IN, const osg::ApplicationUsage::UsageMap &, um, , IN, unsigned int, widthOfOutput, 80, IN, bool, showDefaults, false, IN, const osg::ApplicationUsage::UsageMap &, ud, osg::ApplicationUsage::UsageMap());
	MethodWithDefaults5(void, write, IN, std::ostream &, output, , IN, const osg::ApplicationUsage::UsageMap &, um, , IN, unsigned int, widthOfOutput, 80, IN, bool, showDefaults, false, IN, const osg::ApplicationUsage::UsageMap &, ud, osg::ApplicationUsage::UsageMap());
	MethodWithDefaults4(void, write, IN, std::ostream &, output, , IN, unsigned int, type, osg::ApplicationUsage::COMMAND_LINE_OPTION, IN, unsigned int, widthOfOutput, 80, IN, bool, showDefaults, false);
	Property(const std::string &, ApplicationName);
	Property(const osg::ApplicationUsage::UsageMap &, CommandLineOptions);
	Property(const osg::ApplicationUsage::UsageMap &, CommandLineOptionsDefaults);
	Property(const std::string &, CommandLineUsage);
	Property(const std::string &, Description);
	Property(const osg::ApplicationUsage::UsageMap &, EnvironmentalVariables);
	Property(const osg::ApplicationUsage::UsageMap &, EnvironmentalVariablesDefaults);
	Property(const osg::ApplicationUsage::UsageMap &, KeyboardMouseBindings);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ApplicationUsageProxy)
	Constructor3(IN, osg::ApplicationUsage::Type, type, IN, const std::string &, option, IN, const std::string &, explanation);
END_REFLECTOR

STD_MAP_REFLECTOR(std::map< std::string COMMA  std::string >);

