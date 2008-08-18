#include "osg/BlendEquation"

#include "osgDB/Registry"
#include "osgDB/Input"
#include "osgDB/Output"

using namespace osg;
using namespace osgDB;

// forward declare functions to use later.
bool BlendEquation_readLocalData(Object& obj, Input& fr);
bool BlendEquation_writeLocalData(const Object& obj, Output& fw);

bool BlendEquation_matchModeStr(const char* str,int& mode);
const char* BlendEquation_getModeStr(int value);

// register the read and write functions with the osgDB::Registry.
RegisterDotOsgWrapperProxy g_BlendEquationProxy
(
    new osg::BlendEquation,
    "BlendEquation",
    "Object StateAttribute BlendEquation",
    &BlendEquation_readLocalData,
    &BlendEquation_writeLocalData
);

bool BlendEquation_readLocalData(Object& obj, Input& fr)
{
    bool iteratorAdvanced = false;

    BlendEquation& transparency = static_cast<BlendEquation&>(obj);

    int mode;
    if (fr[0].matchWord("equation") && BlendEquation_matchModeStr(fr[1].getStr(),mode))
    {
        transparency.setEquation(osg::BlendEquation::Equation(mode));
        fr+=2;
        iteratorAdvanced = true;
    }

    return iteratorAdvanced;
}

bool BlendEquation_writeLocalData(const Object& obj, Output& fw)
{
    const BlendEquation& transparency = static_cast<const BlendEquation&>(obj);

    fw.indent() << "equation " << BlendEquation_getModeStr(transparency.getEquation()) << std::endl;

    return true;
}



bool BlendEquation_matchModeStr(const char* str,int& mode)
{
    if (strcmp(str,"RGBA_MIN")==0)                      mode = BlendEquation::RGBA_MIN;
    else if (strcmp(str,"RGBA_MAX")==0)                 mode = BlendEquation::RGBA_MAX;
    else if (strcmp(str,"ALPHA_MIN")==0)                mode = BlendEquation::ALPHA_MIN;
    else if (strcmp(str,"ALPHA_MAX")==0)                mode = BlendEquation::ALPHA_MAX;
    else if (strcmp(str,"LOGIC_OP")==0)                 mode = BlendEquation::LOGIC_OP;
    else if (strcmp(str,"FUNC_ADD")==0)                 mode = BlendEquation::FUNC_ADD;
    else if (strcmp(str,"FUNC_SUBTRACT")==0)            mode = BlendEquation::FUNC_SUBTRACT;
    else if (strcmp(str,"FUNC_REVERSE_SUBTRACT")==0)    mode = BlendEquation::FUNC_REVERSE_SUBTRACT;
    else return false;
    return true;

}
const char* BlendEquation_getModeStr(int value)
{
    switch(value)
    {
        case(BlendEquation::RGBA_MIN) :                 return "RGBA_MIN";
        case(BlendEquation::RGBA_MAX) :                 return "RGBA_MAX";
        case(BlendEquation::ALPHA_MIN) :                return "ALPHA_MIN";
        case(BlendEquation::ALPHA_MAX) :                return "ALPHA_MAX";
        case(BlendEquation::LOGIC_OP) :                 return "LOGIC_OP";
        case(BlendEquation::FUNC_ADD) :                 return "FUNC_ADD";
        case(BlendEquation::FUNC_SUBTRACT) :            return "FUNC_SUBTRACT";
        case(BlendEquation::FUNC_REVERSE_SUBTRACT) :    return "FUNC_REVERSE_SUBTRACT";
    }

    return NULL;
}
