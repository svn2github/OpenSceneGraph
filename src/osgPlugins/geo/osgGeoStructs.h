/*===========================================================================*\

NAME:			osgGeoStructs.h

DESCRIPTION:	OSG data format for reading a Geo file into OSG

AUTHOR:			Geoff Michel

//	-------------------------------------------------------------------------


\ *===========================================================================*/



#ifndef _GEO_STRUCTS_H_
#define _GEO_STRUCTS_H_

class geoField { // holds one field of data as read from the disk of a GEO file
public:
	geoField() {
		tokenId=TypeId=0; numItems=0;storeSize=0;
	}

	unsigned char *readStorage(std::ifstream &fin, const unsigned sz) {
		unsigned char *st=new unsigned char[numItems*sz];
		storeSize=sz;
		fin.read((char *)st, sz*numItems);
		return st;
	}
	void storageRead(std::ifstream &fin) {
		switch (TypeId) {
		case DB_CHAR:
			storage=readStorage(fin,SIZEOF_CHAR);
			break;
		case DB_SHORT:
			storage=readStorage(fin,SIZEOF_SHORT);
			break;
		case DB_INT:
			storage=readStorage(fin,SIZEOF_INT);
			break;
		case DB_FLOAT:
			storage=readStorage(fin,SIZEOF_FLOAT);
			break;
		case DB_LONG:
			storage=readStorage(fin,SIZEOF_LONG);
			break;
		case DB_ULONG:
			storage=readStorage(fin,SIZEOF_ULONG);
			break;
		case DB_DOUBLE:
			storage=readStorage(fin,SIZEOF_DOUBLE);
			break;
		case DB_VEC2F:
			storage=readStorage(fin,SIZEOF_VEC2F);
			break;
		case DB_VEC3F:
			storage=readStorage(fin,SIZEOF_VEC3F);
			break;
		case DB_VEC4F:
			storage=readStorage(fin,SIZEOF_VEC4F);
			break;
		case DB_VEC16F:
			storage=readStorage(fin,SIZEOF_VEC16F);
			break;
		case DB_VEC2I:
			storage=readStorage(fin,SIZEOF_VEC2I);
			break;
		case DB_VEC3I:
			storage=readStorage(fin,SIZEOF_VEC3I);
			break;
		case DB_VEC4I:
			storage=readStorage(fin,SIZEOF_VEC4I);
			break;
		case DB_VEC2D:
			storage=readStorage(fin,SIZEOF_VEC2D);
			break;
		case DB_VEC3D:
			storage=readStorage(fin,SIZEOF_VEC3D);
			break;
		case DB_VEC4D:
			storage=readStorage(fin,SIZEOF_VEC4D);
			break;
		case DB_VEC16D:
			storage=readStorage(fin,SIZEOF_VEC16D);
			break;
		case DB_VRTX_STRUCT:
			storage=readStorage(fin,SIZEOF_VRTX_STRUCT);
			break;
		case DB_UINT:
			storage=readStorage(fin,SIZEOF_UINT);
			break;
		case DB_USHORT:
			storage=readStorage(fin,SIZEOF_USHORT);
			break;
		case DB_UCHAR:
			storage=readStorage(fin,SIZEOF_UCHAR);
			break;
		case DB_EXT_STRUCT:
			storage=readStorage(fin,SIZEOF_EXT_STRUCT);
			break;
		case DB_SHORT_WITH_PADDING:
			storage=readStorage(fin,SIZEOF_ULONG);
			break;
		case DB_CHAR_WITH_PADDING:
			storage=readStorage(fin,SIZEOF_CHAR_WITH_PADDING);
			break;
		case DB_USHORT_WITH_PADDING:
			storage=readStorage(fin,SIZEOF_USHORT_WITH_PADDING);
			break;
		case DB_UCHAR_WITH_PADDING:
			storage=readStorage(fin,SIZEOF_UCHAR_WITH_PADDING);
			break;
		case DB_BOOL_WITH_PADDING:
			storage=readStorage(fin,SIZEOF_BOOL_WITH_PADDING);
			break;
		case DB_EXTENDED_FIELD_STRUCT:
			storage=readStorage(fin,SIZEOF_EXTENDED_FIELD_STRUCT);
			break;
		case DB_VEC4UC:
			storage=readStorage(fin,SIZEOF_VEC4UC);
			break;
		case DB_DISCRETE_MAPPING_STRUCT:
			storage=readStorage(fin,SIZEOF_DISCRETE_MAPPING_STRUCT);
			break;
		case DB_BITFLAGS:
			storage=readStorage(fin,SIZEOF_BITFLAGS);
			break;
		}
	}
	void readfile(std::ifstream &fin) { 
		osg::uchar tokid, type;
		osg::ushort nits;
		if (!fin.eof()) {
			fin.read((char *)&tokid,1);fin.read((char *)&type,1);
			fin.read((char *)&nits,sizeof(unsigned short));
			if (TypeId == GEO_DB_EXTENDED_FIELD) {
				fin.read((char *)&tokenId,sizeof(tokenId));fin.read((char *)&TypeId,sizeof(TypeId));
				fin.read((char *)&numItems,sizeof(unsigned int));
			} else {
				tokenId=tokid; TypeId=type;
				numItems=nits;
			}
			storageRead(fin); // allocate & fill the storage
		}
	}
	inline osg::uchar getToken() const { return tokenId;}
	inline osg::uchar getType() const { return TypeId;}
	inline unsigned short getNum() const { return numItems;}
	inline unsigned char *getstore (unsigned int i) const {
		return storage+i*storeSize;
	}
	void uncompress() { // folow the recipe to uncompress
		if (TypeId==DB_VEC3F) { // already uncompressed
		} else {
			float *norms=new float[numItems*SIZEOF_VEC3F]; // uncompressed size
			for (uint i=0; i<numItems; i++) {
				switch (TypeId) {
				case DB_UINT:
					norms[3*i]=storage[4*i+1]/255.0f;
					norms[3*i+1]=storage[4*i+2]/255.0f;
					norms[3*i+2]=storage[4*i+3]/255.0f;
					if (storage[4*i] & 0x01) norms[3*i] *= -1;
					if (storage[4*i] & 0x02) norms[3*i+1] *= -1;
					if (storage[4*i] & 0x04) norms[3*i+2] *= -1;
					break;
				case DB_SHORT:
					norms[3*i]=(storage[6*i]*255+storage[6*i+1])/32767.0f;
					norms[3*i+1]=(storage[6*i+2]*255+storage[6*i+3])/32767.0f;
					norms[3*i+2]=(storage[6*i+4]*255+storage[6*i+5])/32767.0f;
					break;
				case DB_CHAR:
					norms[3*i]=storage[3*i]/127.0f;
					norms[3*i+1]=storage[3*i+1]/127.0f;
					norms[3*i+2]=storage[3*i+2]/127.0f;
					break;
				}
			}
			delete [] storage;
			TypeId=DB_VEC3F;
			storage=(unsigned char *)norms;
		}
	}
	void warn(const char *type, unsigned tval) const { if (getType() != tval) 
			osg::notify(osg::WARN) << "Wrong type " << type <<" expecting "<< getType() << std::endl;}
	unsigned int getUInt() const {warn("getUInt",DB_UINT); return *((unsigned int*)storage);} // return int value
	char *getChar() const {warn("getChar",DB_CHAR); return (char *)storage;} // return chars, eg for name or file name
	int getInt() const {warn("getInt", DB_INT); return *((int*)storage);} // return int value
	float getFloat() const {warn("getFloat", DB_FLOAT); return (*(float *)storage);	}
	float *getFloatArr() const {warn("getFloatArr", DB_FLOAT); return ( (float *)storage);	}
	float *getVec3Arr() const {warn("getVec3Arr", DB_VEC3F); return ( (float *)storage);	}
	float *getMat44Arr() const {warn("getMat44Arr", DB_VEC16F); return ( (float *)storage);	}
	double getDouble() const {warn("getDouble", DB_DOUBLE); return (*(double *)storage);	}
	friend inline std::ostream& operator << (std::ostream& output, const geoField& gf)
    {
		if (gf.tokenId!=GEO_DB_LAST_FIELD) {
			output << " Field:token " << (int)gf.tokenId << " type " << (int)gf.TypeId
				<< " num its " << gf.numItems << " size " << gf.storeSize << std::endl;
			for (uint i=0; i<gf.numItems; i++) {
				int j,k;
				union {
					unsigned char *uch;
					char *ch;
					float *ft;
					int *in;
					uint *uin;
					short *sh;
					osg::ushort *ush;
					long *ln;
					unsigned long *uln;
					double *dbl;
				} st;
				st.uch=gf.storage+i*gf.storeSize;
				switch (gf.TypeId) {
		case DB_CHAR:
			if (st.ch[0]) output << st.ch[0];
			break;
		case DB_SHORT:
			output << st.sh[0] << std::endl;
			break;
		case DB_INT:
			output << st.in[0] << std::endl;
			break;
		case DB_FLOAT:
			output << st.ft[0] << std::endl;
			break;
		case DB_LONG:
			output << st.ln[0] << std::endl;
			break;
		case DB_ULONG:
			output << st.uln[0] << std::endl;
			break;
		case DB_DOUBLE:
			output << st.dbl[0] << std::endl;
			break;
		case DB_VEC2F:
			for (j=0; j<2; j++) output << st.ft[j] << " ";
			output << std::endl;
			break;
		case DB_VEC3F:
			for (j=0; j<3; j++) output << st.ft[j] << " ";
			output << std::endl;
			break;
		case DB_VEC4F:
			for (j=0; j<4; j++) output << st.ft[j] << " ";
			output << std::endl;
			break;
		case DB_VEC16F:
			for (j=0; j<4; j++) {
				for (k=0; k<4; k++) output << st.ch[j*4+k] << " ";
				output << std::endl;
			}
			break;
		case DB_VEC2I:
			for (j=0; j<2; j++) output << st.in[j] << " ";
			output << std::endl;
			break;
		case DB_VEC3I:
			for ( j=0; j<3; j++) output << st.in[j] << " ";
			output << std::endl;
			break;
		case DB_VEC4I:
			for ( j=0; j<4; j++) output << st.in[j] << " ";
			output << std::endl;
			break;
		case DB_VEC2D:
			for ( j=0; j<2; j++) output << st.dbl[j] << " ";
			output << std::endl;
			break;
		case DB_VEC3D:
			for ( j=0; j<3; j++) output << st.dbl[j] << " ";
			output << std::endl;
			break;
		case DB_VEC4D:
			for ( j=0; j<4; j++) output << st.dbl[j] << " ";
			output << std::endl;
			break;
		case DB_VEC16D:
			for (j=0; j<4; j++) {
				for (k=0; k<4; k++) output << st.dbl[j*4+k] << " ";
				output << std::endl;
			}
			break;
		case DB_VRTX_STRUCT:
			output << st.ch[0] << std::endl;
			break;
		case DB_UINT:
			output << st.uin[0] << std::endl;
			break;
		case DB_USHORT:
			output << st.ush[0] << std::endl;
			break;
		case DB_UCHAR:
			output << (int)st.ch[0] << std::endl;
			break;
		case DB_EXT_STRUCT:
			output << st.ch[0] << std::endl;
			break;
		case DB_SHORT_WITH_PADDING:
			output << st.ch[0] << std::endl;
			break;
		case DB_CHAR_WITH_PADDING:
			output << st.ch[0] << std::endl;
			break;
		case DB_USHORT_WITH_PADDING:
			output << st.ch[0] << std::endl;
			break;
		case DB_UCHAR_WITH_PADDING:
			output << (int)st.ch[0] << std::endl;
			break;
		case DB_BOOL_WITH_PADDING:
			output << st.ch[0] << std::endl;
			break;
		case DB_EXTENDED_FIELD_STRUCT:
			output << st.ch[0] << std::endl;
			break;
		case DB_VEC4UC:
			for ( j=0; j<4; j++) output << (int)st.uch[j] << " ";
			output << std::endl;
			break;
		case DB_DISCRETE_MAPPING_STRUCT:
			output << st.ch[i] << std::endl;
			break;
		case DB_BITFLAGS:
			output << st.ch[i] << std::endl;
			break;
				}
			}
		}
	    return output; 	// to enable cascading, monkey copy from osg\plane or \quat, Ubyte4, vec2,3,4,... 
	}
private:
	osg::ushort tokenId, TypeId; // these are longer than standard field; are extended field length
	uint numItems;
	unsigned char *storage; // data relating
	uint storeSize; // size*numItems in storage
};

class georecord { // holds a single record with a vector of geoFields as read from disk
public:
    typedef std::vector< geoField > geoFieldList;
	georecord() {id=0; parent=NULL; instance=NULL;}
	~georecord() {;}
	inline int getType(void) const {return id;}
	inline void setparent(georecord *p) { parent=p;}
	inline class georecord *getparent() { return parent;}
	inline std::vector<georecord *> getchildren(void) { return children;}
	void addchild(class georecord *gr) { children.push_back(gr);}
	void readfile(std::ifstream &fin) {
		if (!fin.eof()) {
			fin.read((char *)&id,sizeof(int));
			if (id==DB_DSK_PUSH) {
				// there are no fields for a push
			} else if (id==DB_DSK_POP) {
				// there are no fields for a pop
			} else { // get the fields
				geoField gf;
				do {
					gf.readfile(fin);
					if (id == DB_DSK_NORMAL_POOL && gf.getToken()==GEO_DB_NORMAL_POOL_VALUES) {
						// uncompress the normals
						gf.uncompress();
					}
					fields.push_back(gf);
				} while (gf.getToken()!=GEO_DB_LAST_FIELD);
			}
		}
	}
	friend inline std::ostream& operator << (std::ostream& output, const georecord& gr)
    {
		if (gr.id == DB_DSK_PUSH) output << "Push" << std::endl;
		else if (gr.id == DB_DSK_POP) output << "Pop" << std::endl;
		else if (gr.id == DB_DSK_HEADER) output << "Header" << std::endl;
		else if (gr.id == DB_DSK_GROUP) output << "Group" << std::endl;
		else if (gr.id == DB_DSK_BILLBOARD) output << "Billboard" << std::endl;
		else if (gr.id == DB_DSK_SEQUENCE) output << "Sequence" << std::endl;
		else if (gr.id == DB_DSK_LOD) output << "LOD" << std::endl;
		else if (gr.id == DB_DSK_GEODE) output << "Geode" << std::endl;
		else if (gr.id == DB_DSK_POLYGON) output << "Polygon" << std::endl;
		else if (gr.id == DB_DSK_MESH) output << "Mesh" << std::endl;
		else if (gr.id == DB_DSK_CUBE) output << "Cube" << std::endl;
		else if (gr.id == DB_DSK_SPHERE) output << "Sphere" << std::endl;
		else if (gr.id == DB_DSK_CONE) output << "Cone" << std::endl;
		else if (gr.id == DB_DSK_CYLINDER) output << "Cylinder" << std::endl;
		else if (gr.id == DB_DSK_VERTEX) output << "Vertex" << std::endl;
		else if (gr.id == DB_DSK_TEXTURE) output << "Texture" << std::endl;
		else if (gr.id == DB_DSK_MATERIAL) output << "Material" << std::endl;
		else if (gr.id == DB_DSK_VIEW) output << "View" << std::endl;
		else if (gr.id == DB_DSK_EXTENSION_LIST) output << "Extensions" << std::endl;
		else if (gr.id == DB_DSK_COORD_POOL) output << "Coords" << std::endl;
		else if (gr.id == DB_DSK_NORMAL_POOL) output << "Normals" << std::endl;
		else if (gr.id == DB_DSK_SWITCH) output << "Switch" << std::endl;
		else if (gr.id == DB_DSK_TEXT) output << "Text" << std::endl;
		else if (gr.id == DB_DSK_BASE_GROUP) output << "Base group" << std::endl;
		else if (gr.id == DB_DSK_BASE_SURFACE) output << "Base Surface" << std::endl;
		else if (gr.id == DB_DSK_INSTANCE) output << "Instance" << std::endl;
		else if (gr.id == DB_DSK_LIGHTPT) output << "Light Point" << std::endl;
		else if (gr.id == DB_DSK_EXTERNAL) output << "External" << std::endl;
		else if (gr.id == DB_DSK_PAGE) output << "Page" << std::endl;
		else if (gr.id == DB_DSK_COLOR_PALETTE) output << "Colour palette" << std::endl;
		else output << " inp record " << gr.id << std::endl;
 
		for (geoFieldList::const_iterator itr=gr.fields.begin();
		itr!=gr.fields.end();
		++itr)
		{
			output << *itr << std::endl;
		}
	    return output; 	// to enable cascading, monkey copy from osg\plane or \quat, Ubyte4, vec2,3,4,... 
	}
/*	const char *getCharField(const int fieldid) const {
		const geoField *gfd=getField(fieldid);
		if (gfd) return (char *)gfd->getstore(0);
		return NULL;
	} */
	const geoField *getField(const int fieldid) const { // return field if it exists.
		for (geoFieldList::const_iterator itr=fields.begin();
		itr!=fields.end();
		++itr)
		{
			if (itr->getToken()==fieldid) return &(*itr);
		}
		return NULL;
	}
	void setMaterial(osg::Material *mt) const {
		if (id == DB_DSK_MATERIAL) {
			for (geoFieldList::const_iterator itr=fields.begin();
			itr!=fields.end();
			++itr)
			{
				float *fval;
				if (itr->getToken()==GEO_DB_MAT_AMBIENT) {
					fval= (float *)(*itr).getstore(0);
					mt->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(fval[0],fval[1],fval[2],fval[3]));
				}
				if (itr->getToken()==GEO_DB_MAT_DIFFUSE) {
					fval= (float *)(*itr).getstore(0);
					mt->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(fval[0],fval[1],fval[2],fval[3]));
				}
				if (itr->getToken()==GEO_DB_MAT_SPECULAR) {
					fval= (float *)(*itr).getstore(0);
					mt->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(fval[0],fval[1],fval[2],fval[3]));
				}
				if (itr->getToken()==GEO_DB_MAT_EMISSIVE) {
					fval= (float *)(*itr).getstore(0);
					mt->setEmission(osg::Material::FRONT_AND_BACK, osg::Vec4(fval[0],fval[1],fval[2],fval[3]));
				}
				if (itr->getToken()==GEO_DB_MAT_SHININESS) {
					fval= (float *)(*itr).getstore(0);
					mt->setShininess(osg::Material::FRONT_AND_BACK, fval[0]);
				}
			}
		}
	}
private:
	int id;
	std::vector<geoField> fields; // each geo record has a variable number of fields
	class georecord *parent; // parent of pushed/popped records
	class georecord *instance; // this record is an instance of the pointed to record
	std::vector< georecord *> children; // children of this record
};


typedef std::vector< georecord > geoRecordList;

#endif //_GEO_STRUCTS_H_
