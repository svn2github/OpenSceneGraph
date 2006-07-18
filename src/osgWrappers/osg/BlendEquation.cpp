// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/BlendEquation>
#include <osg/CopyOp>
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osg::BlendEquation::Equation)
	I_EnumLabel(osg::BlendEquation::RGBA_MIN);
	I_EnumLabel(osg::BlendEquation::RGBA_MAX);
	I_EnumLabel(osg::BlendEquation::ALPHA_MIN);
	I_EnumLabel(osg::BlendEquation::ALPHA_MAX);
	I_EnumLabel(osg::BlendEquation::LOGIC_OP);
	I_EnumLabel(osg::BlendEquation::FUNC_ADD);
	I_EnumLabel(osg::BlendEquation::FUNC_SUBTRACT);
	I_EnumLabel(osg::BlendEquation::FUNC_REVERSE_SUBTRACT);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::BlendEquation)
	I_BaseType(osg::StateAttribute);
	I_Constructor0();
	I_Constructor1(IN, osg::BlendEquation::Equation, equation);
	I_ConstructorWithDefaults2(IN, const osg::BlendEquation &, trans, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(osg::StateAttribute::Type, getType);
	I_Method1(int, compare, IN, const osg::StateAttribute &, sa);
	I_Method1(bool, getModeUsage, IN, osg::StateAttribute::ModeUsage &, usage);
	I_Method1(void, setEquation, IN, osg::BlendEquation::Equation, equation);
	I_Method0(osg::BlendEquation::Equation, getEquation);
	I_Method1(void, apply, IN, osg::State &, state);
	I_Property(osg::BlendEquation::Equation, Equation);
	I_ReadOnlyProperty(osg::StateAttribute::Type, Type);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::BlendEquation::Extensions)
	I_BaseType(osg::Referenced);
	I_Constructor1(IN, unsigned int, contextID);
	I_Constructor1(IN, const osg::BlendEquation::Extensions &, rhs);
	I_Method1(void, lowestCommonDenominator, IN, const osg::BlendEquation::Extensions &, rhs);
	I_Method1(void, setupGLExtenions, IN, unsigned int, contextID);
	I_Method1(void, setBlendEquationSupported, IN, bool, flag);
	I_Method0(bool, isBlendEquationSupported);
	I_Method0(bool, isSGIXMinMaxSupported);
	I_Method0(bool, isLogicOpSupported);
	I_Method1(void, setBlendEquationProc, IN, void *, ptr);
	I_Method1(void, glBlendEquation, IN, GLenum, mode);
	I_WriteOnlyProperty(void *, BlendEquationProc);
	I_WriteOnlyProperty(bool, BlendEquationSupported);
	I_WriteOnlyProperty(unsigned int, upGLExtenions);
END_REFLECTOR

