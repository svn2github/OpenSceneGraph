/*************************************************************************** 
 * December 2003
 *
 * This TerraPage loader was re-written in a fashion to use PagedLOD 
 * to manage paging entirely, also includes a version of Terrex's smart mesh 
 * adapted to work with PagedLOD. The essential code by Boris Bralo is still present, 
 * slight modified.
 * nick at terrex dot com
 * 
 * Ported to PagedLOD technology by Trajce Nikolov (Nick) & Robert Osfield
 *****************************************************************************/

/***************************************************************************
 * OpenSceneGraph loader for Terrapage format database 
 * by Boris Bralo 2002
 *
 * based on/modifed  sgl (Scene Graph Library) loader by Bryan Walsh
 *
 * This loader is based on/modified from Terrain Experts Performer Loader,
 * and was ported to SGL by Bryan Walsh / bryanw at earthlink dot net
 *
 * That loader is redistributed under the terms listed on Terrain Experts
 * website (www.terrex.com/www/pages/technology/technologypage.htm)
 *
 * "TerraPage is provided as an Open Source format for use by anyone...
 * We supply the TerraPage C++ source code free of charge.  Anyone
 * can use it and redistribute it as needed (including our competitors).
 * We do, however, ask that you keep the TERREX copyrights intact."
 *
 * Copyright Terrain Experts Inc. 1999.
 * All Rights Reserved.
 *
 *****************************************************************************/

#ifndef TXPSeamLOD_H
#define TXPSeamLOD_H

#include <osg/LOD>
#include <map>
#include <string>

#include "TXPTileNode.h"
#include "TXPArchive.h"

namespace txp
{
class TXPSeamLOD : public osg::Group
{
public:

    TXPSeamLOD();

    TXPSeamLOD(int x, int y, int lod, const osg::Vec3& center, float dmin,
        float dmid, float dmax);

    TXPSeamLOD(const TXPSeamLOD&,
        const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);

    META_Node(txp, TXPSeamLOD);

    virtual void traverse(osg::NodeVisitor& nv);

    void setTileRef(bool* b)
    {
        _tileRef = b;
    }

    void setTxpNode(TXPTileNode* txpNode)
    {
        _txpNode = txpNode;
    }

    TXPTileNode* getTxpNode() const
    {
        return _txpNode;
    }

    void setArchive(TXPArchive* ar)
    {
        _archive = ar;
    }

    inline void setHiResPresent(bool p) { _hiResPresent = p; }
    inline void setNonSeamChildrenIndex(int ix) { _nonSeamChildrenIndex = ix; }

protected:

    bool _hiResPresent;

    int _nonSeamChildrenIndex;

    int _neighbourTileX;
    int _neighbourTileY;
    int _neighbourTileLOD;

    osg::Vec3 _center;

    float _min;
    float _mid;
    float _max;

    bool* _tileRef;

    TXPTileNode* _txpNode;
    TXPArchive* _archive;
};

}

#endif

