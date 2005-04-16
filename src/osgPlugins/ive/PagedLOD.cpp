/**********************************************************************
 *
 *	FILE:			PagedLOD.cpp
 *
 *	DESCRIPTION:	Read/Write osg::PagedLOD in binary format to disk.
 *
 *	CREATED BY:		Auto generated by iveGenerate
 *					and later modified by Rune Schmidt Jensen.
 *
 *	HISTORY:		Created 24.3.2003
 *
 *	Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "PagedLOD.h"
#include "Node.h"

using namespace ive;

void PagedLOD::write(DataOutputStream* out){
	// Write LOD's identification.
	out->writeInt(IVEPAGEDLOD);
	// If the osg class is inherited by any other class we should also write this to file.

        osg::Node* node = dynamic_cast<osg::Node*>(this);
        if(node){
            static_cast<ive::Node*>(node)->write(out);
        }
        else
		throw Exception("PagedLOD::write(): Could not cast this osg::PagedLOD to an osg::LOD.");

        out->writeString(getDatabasePath());
        out->writeFloat(getRadius());
        out->writeUInt(getNumChildrenThatCannotBeExpired());


        unsigned int numChildrenToWriteOut = 0;

        int i;
        for(i=0; i<(int)getNumFileNames();++i)
        {
            if (getFileName(i).empty())
            {
                ++numChildrenToWriteOut;
            }
        }

	// Write Group's properties.
        // Write number of children.
        out->writeInt(numChildrenToWriteOut);
        // Write children.
        for(i=0; i<(int)getNumChildren(); i++){
            if (getFileName(i).empty())
            {
                osg::Node* child = getChild(i);
                out->writeNode(child);
            }
        }

        // LOD properties
	// Write centermode
	out->writeInt(getCenterMode());
	out->writeVec3(getCenter());

        out->writeInt(getRangeMode());


        // Write rangelist
	int size = getNumRanges();
	out->writeInt(size);
	for(i=0;i<size;i++){
		out->writeFloat(getMinRange(i));
		out->writeFloat(getMaxRange(i));
	}


        // PagedLOD properties
	size = getNumFileNames();
	out->writeInt(size);
	for(i=0;i<size;i++){
		out->writeString(getFileName(i));
	}
}

void PagedLOD::read(DataInputStream* in){
	// Peek on LOD's identification.
	int id = in->peekInt();
	if(id == IVEPAGEDLOD){
		// Read LOD's identification.
		id = in->readInt();
		// If the osg class is inherited by any other class we should also read this from file.
                osg::Node* node = dynamic_cast<osg::Node*>(this);
                if(node){
                    ((ive::Node*)(node))->read(in);
                }
                else
                    throw Exception("Group::read(): Could not cast this osg::Group to an osg::Node.");


		  if ( in->getVersion() >= VERSION_0006 ) {
               setDatabasePath(in->readString());
            }

                if (getDatabasePath().empty() && in->getOptions() && !in->getOptions()->getDatabasePathList().empty())
                {
                    const std::string& path = in->getOptions()->getDatabasePathList().front();
                    if (!path.empty()) 
                    {
                        setDatabasePath(path);
                    }
                } 


                setRadius(in->readFloat());
                setNumChildrenThatCannotBeExpired(in->readUInt());


                // Read groups properties.
                // Read number of children.
                int size = in->readInt();
                // Read children.
		int i;
                for(i=0; i<size; i++)
                {
                    addChild(in->readNode());            
                }

		// Read centermode
		setCenterMode((osg::LOD::CenterMode)in->readInt());
		setCenter(in->readVec3());

                setRangeMode((RangeMode)in->readInt());

		// Read rangelist
		size = in->readInt();
		for(i=0;i<size;i++){
			float min = in->readFloat();
			float max = in->readFloat();
			setRange(i, min, max);
		}

		size = in->readInt();
		for(i=0;i<size;i++){
			setFileName(i, in->readString());
		}
	}
	else{
		throw Exception("LOD::read(): Expected LOD identification.");
	}
}
