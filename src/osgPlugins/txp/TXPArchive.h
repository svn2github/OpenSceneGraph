#ifndef __TXPARCHIVE_H_
#define __TXPARCHIVE_H_

#include "trpage_sys.h"
#include "trpage_read.h"

#include <osg/Referenced>
#include <osg/BoundingBox>
#include <osg/Texture2D>
#include <osg/StateSet>
#include <osg/Node>
#include <osg/PagedLOD>
#include <osgSim/LightPointNode>

namespace txp
{
    // this one handles different placement of light direction in osg and terrapage
    struct DefferedLightAttribute
    {
        // light point at (0,0,0) looking in (0,0,0) direction
        osg::ref_ptr<osgSim::LightPointNode> lightPoint;
        osg::ref_ptr<osg::StateSet> fallback;
        osg::Vec3 attitude;
    };

    class TXPParser;
    class TXPArchive : public trpgr_Archive, public osg::Referenced
    {
    public:
        // Constructor
        TXPArchive();

        // Opens the archive file and reads the header
        bool openFile(const std::string& archiveName);

        // Load the materials from the archve
        bool loadMaterials();

        // Load the models from the archive
        bool loadModels();

        // Load the light attribs from the archive
        bool loadLightAttributes();

        // Add light attrib
        void addLightAttribute(osgSim::LightPointNode* lpn, osg::StateSet* fallback , const osg::Vec3& attitude);

        // Get light attrib
        inline DefferedLightAttribute& getLightAttribute(unsigned int i) { return _lights[i]; };

        // Gets some informations for a given tile
        struct TileInfo
        {
            osg::Vec3            center;
            double                minRange;
            double                maxRange;
            float                radius;
            osg::BoundingBox    bbox;
        };
        bool getTileInfo(int x, int y, int lod, TileInfo& info);

        // Set/Get the archive id
        inline void setId(int id) { _id = id; }
        inline const int& getId() const { return _id; }

        // Returns the number of LODs for this archive
        inline const int& getNumLODs() const { return _numLODs; }

        // Returns the extents of the archive
        inline void getExtents(osg::BoundingBox& extents)
        {
            extents.set(_swExtents.x,_swExtents.y,0.0f,_neExtents.x,_neExtents.y,0.0f);
        }

        // Returns the origin of the archive
        inline void getOrigin(double& x, double& y) { x=_swExtents.x; y=_swExtents.y; }

        inline osg::Texture2D* getGlobalTexture(int id) { return _textures[id].get(); }

        osg::Group* getTileContent(int x, int y, int lod);


    protected:


        // Destructor
        virtual ~TXPArchive();

        // Id of the archive
        int _id;

        // Number of the LODs
        int _numLODs;

        // Archive extents
        trpg2dPoint _swExtents;
        trpg2dPoint _neExtents;

        // Terra Page Parser
        osg::ref_ptr<TXPParser>    _parser;

        // Textures
        std::vector< osg::ref_ptr<osg::Texture2D> >        _textures;

        // States
        std::vector< osg::ref_ptr<osg::StateSet> >        _gstates;

        // Models
        std::vector< osg::ref_ptr<osg::Node> >            _models;

        // Light attributes vector
        std::vector<DefferedLightAttribute>                _lights;

    };

} // namespace

#endif // __TXPARCHIVE_H_
