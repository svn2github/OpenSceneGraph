#include "osg/StateSet"

#include "osgDB/Registry"
#include "osgDB/Input"
#include "osgDB/Output"

using namespace osg;
using namespace osgDB;

// forward declare functions to use later.
bool GeoState_readLocalData(Object& obj, Input& fr);

bool StateSet_readLocalData(Object& obj, Input& fr);
bool StateSet_writeLocalData(const Object& obj, Output& fw);

bool StateSet_matchModeStr(const char* str,StateAttribute::GLModeValue& mode);
const char* StateSet_getModeStr(StateAttribute::GLModeValue mode);

bool StateSet_matchRenderBinModeStr(const char* str,StateSet::RenderBinMode& mode);
const char* StateSet_getRenderBinModeStr(StateSet::RenderBinMode mode);

// register the read and write functions with the osgDB::Registry.
RegisterDotOsgWrapperProxy g_StateSetFuncProxy
(
    new osg::StateSet,
    "StateSet",
    "Object StateSet",
    &StateSet_readLocalData,
    &StateSet_writeLocalData,
    DotOsgWrapper::READ_AND_WRITE
);

// register the read and write functions with the osgDB::Registry.
RegisterDotOsgWrapperProxy g_GeoStateFuncProxy
(
    new osg::StateSet,
    "GeoState",
    "Object GeoState",
    &GeoState_readLocalData,
    NULL,
    DotOsgWrapper::READ_ONLY
);

//
// Set up the maps from name to GLMode and visa versa.
//
typedef std::map<std::string,StateAttribute::GLMode> GLNameToGLModeMap;
typedef std::map<StateAttribute::GLMode,std::string> GLModeToGLNameMap;

GLNameToGLModeMap s_GLNameToGLModeMap;
GLModeToGLNameMap s_GLModeToGLNameMap;

#define ADD_NAME(name,mode) s_GLNameToGLModeMap[name]=mode; s_GLModeToGLNameMap[mode]=name;

void initGLNames()
{
    static bool first_time = true;
    if (!first_time) return;
    
    ADD_NAME("GL_ALPHA_TEST",GL_ALPHA_TEST)
    ADD_NAME("GL_BLEND",GL_BLEND)
    ADD_NAME("GL_COLOR_MATERIAL",GL_COLOR_MATERIAL)
    ADD_NAME("GL_CULL_FACE",GL_CULL_FACE)
    ADD_NAME("GL_DEPTH_TEST",GL_DEPTH_TEST)
    ADD_NAME("GL_FOG",GL_FOG)
    ADD_NAME("GL_LIGHTING",GL_LIGHTING)
    ADD_NAME("GL_POINT_SMOOTH",GL_POINT_SMOOTH)
    ADD_NAME("GL_POLYGON_OFFSET_FILL",GL_POLYGON_OFFSET_FILL)
    ADD_NAME("GL_POLYGON_OFFSET_LINE",GL_POLYGON_OFFSET_LINE)
    ADD_NAME("GL_POLYGON_OFFSET_POINT",GL_POLYGON_OFFSET_POINT)
    
    ADD_NAME("GL_TEXTURE_2D",GL_TEXTURE_2D)
    ADD_NAME("GL_TEXTURE_GEN_Q",GL_TEXTURE_GEN_Q)
    ADD_NAME("GL_TEXTURE_GEN_R",GL_TEXTURE_GEN_R)
    ADD_NAME("GL_TEXTURE_GEN_S",GL_TEXTURE_GEN_S)
    ADD_NAME("GL_TEXTURE_GEN_T",GL_TEXTURE_GEN_T)
    
    ADD_NAME("GL_STENCIL_TEST",GL_STENCIL_TEST)
    
    ADD_NAME("GL_CLIP_PLANE0",GL_CLIP_PLANE0);
    ADD_NAME("GL_CLIP_PLANE1",GL_CLIP_PLANE1);
    ADD_NAME("GL_CLIP_PLANE2",GL_CLIP_PLANE2);
    ADD_NAME("GL_CLIP_PLANE3",GL_CLIP_PLANE3);
    ADD_NAME("GL_CLIP_PLANE4",GL_CLIP_PLANE4);
    ADD_NAME("GL_CLIP_PLANE5",GL_CLIP_PLANE5);

    ADD_NAME("GL_LIGHT0",GL_LIGHT0);
    ADD_NAME("GL_LIGHT1",GL_LIGHT1);
    ADD_NAME("GL_LIGHT2",GL_LIGHT2);
    ADD_NAME("GL_LIGHT3",GL_LIGHT3);
    ADD_NAME("GL_LIGHT4",GL_LIGHT4);
    ADD_NAME("GL_LIGHT5",GL_LIGHT5);
    ADD_NAME("GL_LIGHT6",GL_LIGHT6);
    ADD_NAME("GL_LIGHT7",GL_LIGHT7);

//     for(GLNameToGLModeMap::iterator itr=s_GLNameToGLModeMap.begin();
//         itr!=s_GLNameToGLModeMap.end();
//         ++itr)
//     {
//         cout << "Name ["<<itr->first<<","<<itr->second<<"]"<<endl;
//     }
    
    first_time = false;
}


//////////////////////////////////////////////////////////////////////

bool GeoState_readLocalData(Object& obj, Input& fr)
{
    bool iteratorAdvanced = false;

    // note, StateSet replaced GeoState April 2001.
    StateSet& statset = static_cast<StateSet&>(obj);

    statset.setRenderingHint(StateSet::OPAQUE_BIN);

    StateAttribute::GLModeValue mode;
    if (fr[0].matchWord("transparency") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        if (mode==StateAttribute::ON || mode==StateAttribute::OVERRIDE_ON)
        {
            statset.setRenderingHint(StateSet::TRANSPARENT_BIN);
        }
        statset.setMode(GL_BLEND,mode);
        fr+=2;
        iteratorAdvanced = true;
    }

    if (fr[0].matchWord("antialiasing") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        // what is the OpenGL modes for antialissing, need to look up.
        // statset.setMode(GeoState::ANTIALIAS,mode);
        fr+=2;
        iteratorAdvanced = true;
    }

    if (fr[0].matchWord("face_culling") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        statset.setMode(GL_CULL_FACE,mode);
        fr+=2;
        iteratorAdvanced = true;
    }

    if (fr[0].matchWord("lighting") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        statset.setMode(GL_LIGHTING,mode);
        fr+=2;
        iteratorAdvanced = true;
    }

    if (fr[0].matchWord("texturing") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        statset.setMode(GL_TEXTURE_2D,mode);
        fr+=2;
        iteratorAdvanced = true;
    }

    if (fr[0].matchWord("fogging") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        statset.setMode(GL_FOG,mode);
        fr+=2;
        iteratorAdvanced = true;
    }

    if (fr[0].matchWord("colortable") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        // what is the OpenGL modes for colortable, need to look up...
        // statset.setMode(GeoState::COLORTABLE,mode);
        fr+=2;
        iteratorAdvanced = true;
    }

    StateAttribute::GLModeValue texgening = StateAttribute::OFF;
    if (fr[0].matchWord("texgening") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        // leave up to a tex gen object to set modes associated with TexGen
        // as there are mutiple modes associated with TexGen.  See below
        // attribute reading code.
        texgening = mode;
        fr+=2;
        iteratorAdvanced = true;
    }

    if (fr[0].matchWord("point_smoothing") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        statset.setMode(GL_POINT_SMOOTH,mode);
        fr+=2;
        iteratorAdvanced = true;
    }


    if (fr[0].matchWord("polygon_offset") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        // no GL mode associated with polygon offset so commenting out.
        // statset.setMode(GeoState::POLYGON_OFFSET,mode);
        fr+=2;
        iteratorAdvanced = true;
    }

    if (fr[0].matchWord("alpha_test") && StateSet_matchModeStr(fr[1].getStr(),mode))
    {
        statset.setMode(GL_ALPHA_TEST,mode);
        fr+=2;
        iteratorAdvanced = true;
    }


    // new code using osg::Registry's list of prototypes to loaded attributes.
    StateAttribute* attribute = NULL;
    while((attribute=fr.readStateAttribute())!=NULL)
    {
        statset.setAttribute(attribute);
        
        if (attribute->getType()==StateAttribute::TEXGEN) 
            attribute->setStateSetModes(statset,texgening);
            
        iteratorAdvanced = true;
    }

    return iteratorAdvanced;
}

bool StateSet_readLocalData(Object& obj, Input& fr)
{
    bool iteratorAdvanced = false;

    // note, StateSet replaced GeoState April 2001.
    StateSet& stateset = static_cast<StateSet&>(obj);

    initGLNames();
    
    // read the rendering hint value.    
    if (fr[0].matchWord("rendering_hint"))
    {
        if (fr[1].matchWord("DEFAULT_BIN"))
        {
            stateset.setRenderingHint(StateSet::DEFAULT_BIN);
            fr+=2;
            iteratorAdvanced = true;
        }
        else if (fr[1].matchWord("OPAQUE_BIN"))
        {
            stateset.setRenderingHint(StateSet::OPAQUE_BIN);
            fr+=2;
            iteratorAdvanced = true;
        }
        else if (fr[1].matchWord("TRANSPARENT_BIN"))
        {
            stateset.setRenderingHint(StateSet::TRANSPARENT_BIN);
            fr+=2;
            iteratorAdvanced = true;
        }
        else if (fr[1].isInt())
        {
            int value;
            fr[1].getInt(value);
            stateset.setRenderingHint(value);
            fr+=2;
            iteratorAdvanced = true;
        }
    }

    bool setRenderBinDetails=false;
    StateSet::RenderBinMode rbmode = stateset.getRenderBinMode();
    if (fr[0].matchWord("renderBinMode") && StateSet_matchRenderBinModeStr(fr[1].getStr(),rbmode))
    {
        setRenderBinDetails=true;
        fr+=2;
        iteratorAdvanced = true;
    }

    int binNumber = stateset.getBinNumber();
    if (fr[0].matchWord("binNumber") && fr[1].getInt(binNumber))
    {
        setRenderBinDetails=true;
        fr+=2;
        iteratorAdvanced = true;
    }

    std::string binName = stateset.getBinName();
    if (fr[0].matchWord("binName"))
    {
        setRenderBinDetails=true;
        binName = fr[1].getStr();
        
        fr+=2;
        iteratorAdvanced = true;
    }

    if (setRenderBinDetails)
    {
        stateset.setRenderBinDetails(binNumber,binName,rbmode);
    }


    bool readingMode = true;
    StateAttribute::GLModeValue value;
    while (readingMode)
    {

        readingMode=false;
        if (fr[0].isInt())
        {
            if (StateSet_matchModeStr(fr[1].getStr(),value))
            {

                int mode;
                fr[0].getInt(mode);
                stateset.setMode((StateAttribute::GLMode)mode,value);
                fr+=2;
                iteratorAdvanced = true;
                readingMode=true;
            }
        }
        else
        if (fr[0].getStr())
        {
            if (StateSet_matchModeStr(fr[1].getStr(),value))
            {
                GLNameToGLModeMap::iterator nitr = s_GLNameToGLModeMap.find(fr[0].getStr());
                if (nitr!=s_GLNameToGLModeMap.end())
                {
                    StateAttribute::GLMode mode = nitr->second;
                    stateset.setMode(mode,value);
                    fr+=2;
                    iteratorAdvanced = true;
                    readingMode=true;
                }
            }
        } 
    }



    // new code using osg::Registry's list of prototypes to loaded attributes.
    StateAttribute* attribute = NULL;
    while((attribute=fr.readStateAttribute())!=NULL)
    {
        stateset.setAttribute(attribute);
        iteratorAdvanced = true;
    }

    return iteratorAdvanced;
}

bool StateSet_writeLocalData(const Object& obj, Output& fw)
{

    const StateSet& stateset = static_cast<const StateSet&>(obj);

    initGLNames();

    // write the rendering hint value.    
    fw.indent()<<"rendering_hint ";
    switch(stateset.getRenderingHint())
    {
    case(StateSet::DEFAULT_BIN):
        fw<<"DEFAULT_BIN"<<endl;
        break;    
    case(StateSet::OPAQUE_BIN):
        fw<<"OPAQUE_BIN"<<endl;
        break;    
    case(StateSet::TRANSPARENT_BIN):
        fw<<"TRANSPARENT_BIN"<<endl;
        break;    
    default:
        fw<<stateset.getRenderingHint()<<endl;
        break;    
    }

    fw.indent()<<"renderBinMode "<<StateSet_getRenderBinModeStr(stateset.getRenderBinMode())<<endl;
    if (stateset.getRenderBinMode()!=StateSet::INHERIT_RENDERBIN_DETAILS)
    {
        fw.indent()<<"binNumber "<<stateset.getBinNumber()<<endl;
        fw.indent()<<"binName "<<stateset.getBinName()<<endl;
    }


  const StateSet::ModeList& ml = stateset.getModeList();
  const StateSet::AttributeList& sl = stateset.getAttributeList();

  for(StateSet::ModeList::const_iterator mitr=ml.begin();
        mitr!=ml.end();
        ++mitr)
    {
         GLModeToGLNameMap::iterator nitr = s_GLModeToGLNameMap.find(mitr->first);
         if (nitr!=s_GLModeToGLNameMap.end())
         {
             fw.indent() << nitr->second << " " << StateSet_getModeStr(mitr->second) << endl;
         }
         else
         {
            // no name defined for GLMode so just pass its value to fw.
            fw.indent() << "0x" << hex << (osg::uint)mitr->first << dec <<" " << StateSet_getModeStr(mitr->second) << endl;
         }
    }
    
    for(StateSet::AttributeList::const_iterator sitr=sl.begin();
        sitr!=sl.end();
        ++sitr)
    {
        fw.writeObject(*(sitr->second.first));
    }

    return true;
}


bool StateSet_matchModeStr(const char* str,StateAttribute::GLModeValue& mode)
{
    if (strcmp(str,"INHERIT")==0) mode = StateAttribute::INHERIT;
    else if (strcmp(str,"ON")==0) mode = StateAttribute::ON;
    else if (strcmp(str,"OFF")==0) mode = StateAttribute::OFF;
    else if (strcmp(str,"OVERRIDE_ON")==0) mode = StateAttribute::OVERRIDE_ON;
    else if (strcmp(str,"OVERRIDE_OFF")==0) mode = StateAttribute::OVERRIDE_OFF;
    else return false;
    return true;
}


const char* StateSet_getModeStr(StateAttribute::GLModeValue value)
{
    switch(value)
    {
        case(StateAttribute::INHERIT): return "INHERIT";
        case(StateAttribute::ON): return "ON";
        case(StateAttribute::OFF): return "OFF";
        case(StateAttribute::OVERRIDE_ON): return "OVERRIDE_ON";
        case(StateAttribute::OVERRIDE_OFF): return "OVERRIDE_OFF";
    }
    return "";
}

bool StateSet_matchRenderBinModeStr(const char* str,StateSet::RenderBinMode& mode)
{
    if (strcmp(str,"INHERIT")==0) mode = StateSet::INHERIT_RENDERBIN_DETAILS;
    else if (strcmp(str,"USE")==0) mode = StateSet::USE_RENDERBIN_DETAILS;
    else if (strcmp(str,"OVERRID")==0) mode = StateSet::OVERRIDE_RENDERBIN_DETAILS;
    else if (strcmp(str,"ENCLOSE")==0) mode = StateSet::ENCLOSE_RENDERBIN_DETAILS;
    else return false;
    return true;
}

const char* StateSet_getRenderBinModeStr(StateSet::RenderBinMode mode)
{
    switch(mode)
    {
        case(StateSet::INHERIT_RENDERBIN_DETAILS):  return "INHERIT";
        case(StateSet::USE_RENDERBIN_DETAILS):      return "USE";
        case(StateSet::OVERRIDE_RENDERBIN_DETAILS): return "OVERRIDE";
        case(StateSet::ENCLOSE_RENDERBIN_DETAILS):  return "ENCLOSE";
    }
    return "";
}
