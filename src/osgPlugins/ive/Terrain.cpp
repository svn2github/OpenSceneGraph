/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2008 Robert Osfield 
 *
 * This library is open source and may be redistributed and/or modified under  
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * OpenSceneGraph Public License for more details.
*/

#include "Exception.h"
#include "Terrain.h"
#include "Group.h"
#include "Layer.h"

#include <osgTerrain/GeometryTechnique>

using namespace ive;

void Terrain::write(DataOutputStream* out)
{
    // Write Terrain's identification.
    out->writeInt(IVETERRAIN);
    // If the osg class is inherited by any other class we should also write this to file.
    osg::Group*  group = dynamic_cast<osg::Group*>(this);
    if(group)
        ((ive::Group*)(group))->write(out);
    else
        throw Exception("Terrain::write(): Could not cast this osgTerrain::Terrain to an osg::Group.");

    LayerHelper helper;

    helper.writeLocator(out, getLocator());

    helper.writeLayer(out, getElevationLayer());
    
    out->writeUInt(getNumColorLayers());
    
    for(unsigned int i=0; i<getNumColorLayers(); ++i)
    {
        helper.writeLayer(out, getColorLayer(i));
    }
    
    writeTerrainTechnique(out, getTerrainTechnique());

}

void Terrain::read(DataInputStream* in)
{
    // Peek on Terrain's identification.
    int id = in->peekInt();
    if (id != IVETERRAIN) throw Exception("Terrain::read(): Expected Terrain identification.");

    // Read Terrain's identification.
    id = in->readInt();
    // If the osg class is inherited by any other class we should also read this from file.
    osg::Group*  group = dynamic_cast<osg::Group*>(this);
    if(group)
        ((ive::Group*)(group))->read(in);
    else
        throw Exception("Terrain::read(): Could not cast this osgTerrain::Terrain to an osg::Group.");

    LayerHelper helper;

    setLocator(helper.readLocator(in));

    setElevationLayer(helper.readLayer(in));

    unsigned int numColorLayers = in->readUInt();
    for(unsigned int i=0; i<numColorLayers; ++i)
    {
        setColorLayer(i, helper.readLayer(in));
    }
    
    setTerrainTechnique(readTerrainTechnique(in));

}

void Terrain::writeTerrainTechnique(DataOutputStream* out, osgTerrain::TerrainTechnique* technique)
{
    if (dynamic_cast<osgTerrain::GeometryTechnique*>(technique))
    {
        out->writeBool(true);
        out->writeInt(IVEGEOMETRYTECHNIQUE);
    }
    else
    {
        out->writeBool(false);
    }
}

osgTerrain::TerrainTechnique* Terrain::readTerrainTechnique(DataInputStream* in)
{
    bool hasTechnique = in->readBool();
    if (!hasTechnique) return 0;
    
    int id = in->readInt();
    if (id==IVEGEOMETRYTECHNIQUE)
    {
        return new osgTerrain::GeometryTechnique;
    }
    else
    {
        return 0;
    }
}
