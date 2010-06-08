#ifndef READERWRITERFBX_H
#define READERWRITERFBX_H

#include <osgDB/ReaderWriter>

///////////////////////////////////////////////////////////////////////////
// OSG reader plugin for the ".fbx" format.
// See http://usa.autodesk.com/adsk/servlet/index?siteID=123112&id=6837478
// This plugin requires the FBX SDK version 2011.2

class ReaderWriterFBX : public osgDB::ReaderWriter
{
public:
    ReaderWriterFBX()
    {
        supportsExtension("fbx", "FBX format");
        supportsOption("Embedded", "(Write option) Embed textures in FBX file");
        supportsOption("UseFbxRoot", "(Read/write option) If the source OSG root node is a simple group with no stateset, the writer will put its children directly under the FBX root, and vice-versa for reading");
        supportsOption("LightmapTextures", "(Read option) Interpret texture maps as overriding the lighting. 3D Studio Max may export files that should be interpreted in this way.");
    }

    const char* className() const { return "FBX reader/writer"; }

    virtual ReadResult readNode(const std::string& filename, const Options*) const;
    virtual WriteResult writeNode(const osg::Node&, const std::string& filename, const Options*) const;
};

///////////////////////////////////////////////////////////////////////////

#endif
