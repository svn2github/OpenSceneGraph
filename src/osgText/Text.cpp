/* --------------------------------------------------------------------------
 *
 *	openscenegraph textLib / FTGL
 *
 * --------------------------------------------------------------------------
 *	
 *	prog:	max rheiner;mrn@paus.ch
 *	date:	4/25/2001	(m/d/y)
 *
 * ----------------------------------------------------------------------------
 *
 * --------------------------------------------------------------------------
 */


#include <osgText/Text>

#include <osgDB/FileUtils>

#include "FTFace.h"
#include "FTGLBitmapFont.h"
#include "FTGLPixmapFont.h"
#include "FTGLOutlineFont.h"
#include "FTGLPolygonFont.h"
#include "FTGLTextureFont.h"


using namespace osg;
using namespace osgText;

// define the default paths to look for fonts.
// note delimator is : for unix, ; for windows.
#if defined(__linux) || defined(__FreeBSD__) || defined (__sgi)
    static char* s_FontFilePath = ".:/usr/share/fonts/ttf:/usr/share/fonts/ttf/western:/usr/share/fonts/ttf/decoratives";
#elif defined(WIN32)
    static char* s_FontFilePath = ".;C:/windows/fonts";
#else
    static char* s_FontFilePath = ".:";
#endif

std::string findFontFile(const std::string& str)
{
    // try looking in OSGFILEPATH etc first for fonts.
    char* filename = osgDB::findFile(str.c_str());
    if (filename) return std::string(filename);

    // else fallback into the standard font file paths.
    if (s_FontFilePath)
    {
        filename = osgDB::findFileInPath(str.c_str(),s_FontFilePath);
        if (filename) return std::string(filename);
    }
    
    return std::string();
}



///////////////////////////////////////////////////////////////////////////////
// Font
Font::
Font()
{
	_init=false;
	_font=NULL;
	_created=false;

	_pointSize=14;
	_res=72;
}

bool Font::
init(const std::string& font)
{
	_font=NULL;
	_created=false;

	open(font);

	if(_font!=NULL)
		return true; 
	else
		return false;
}

Font::
~Font()
{
	clear();
}

bool Font::
open(const std::string& font)
{
	clear();
        
        std::string filename = findFontFile(font);
        if (filename.empty()) return false;

	_font=createFontObj();
	if( _font!=NULL && _font->Open(filename.c_str()) )
	{
		_init=true;
		_fontName=font;
		return true;
	}
	else
		return false;
}

bool Font::
create(int pointSize,const unsigned int res)
{
	_pointSize=pointSize;
	_res=res;

	return create();
}

bool  Font::
create()
{
	if(_init)
	{
		if(_font->FaceSize(_pointSize,_res))
		{
			_created=true;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

void Font::
output(const char* text)
{
	if(_created)
		_font->render(text);
	else
		create(_pointSize);
}

void  Font::
clear()
{
	_init=false;
	
	if(_font)
	{
		delete _font;
		_font=NULL;
	}

	_fontName="";
}

float Font::
getWidth(const char* text)  const
{
	if(_init && _created)
		return _font->Advance(text);
	else
		return -1;
}

int Font::
getHeight()  const
{
	if(_init && _created)
		return _pointSize;
	else
		return -1;
}

int Font::
getDescender() const
{
	if(_init && _created)
		return _font->Descender();
	else
		return -1;
}

int Font::
getAscender() const
{
	if(_init && _created)
		return _font->Ascender();
	else
		return -1;
}


// Font
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// BitmapFont

BitmapFont::
BitmapFont(const std::string&	font, 
		   int					point_size):
RasterFont()
{
	if(init(font))
	{
	}
	_pointSize=point_size;
}

FTFont*  BitmapFont::
createFontObj(void)
{
	return (FTFont*)(new FTGLBitmapFont);
}
	
// BitmapFont
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PixmapFont

PixmapFont::
PixmapFont(const std::string&	font, 
			int					point_size):
RasterFont(font)
{
	if(init(font))
	{
	}
	_pointSize=point_size;
}
	

FTFont*  PixmapFont::
createFontObj(void)
{
	return (FTFont*)(new FTGLPixmapFont);
}
	
// PixmapFont
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PixmapFont

TextureFont::
TextureFont(const std::string&	font, 
			int					point_size):
RasterFont(font)
{
	if(init(font))
	{
	}
	_pointSize=point_size;
}
	

FTFont*  TextureFont::
createFontObj(void)
{
	return (FTFont*)(new FTGLTextureFont);
}
	
// PixmapFont
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// _FTGLOutlineFont

OutlineFont::
OutlineFont(const std::string&	font, 
			int					point_size,
			double				precision):
VectorFont(font)
{
	if(init(font))
	{
	}
	_pointSize=point_size;
	_precision=precision;
}
	

FTFont*  OutlineFont::
createFontObj(void)
{
	return (FTFont*)(new FTGLOutlineFont);
}
	
// _FTGLOutlineFont
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// PolygonFont

PolygonFont::
PolygonFont(const std::string&	font, 
			int					point_size,
			double				precision):
VectorFont(font)
{
	if(init(font))
	{
	}
	_pointSize=point_size;
	_precision=precision;
}
	
FTFont*  PolygonFont::
createFontObj(void)
{
	return (FTFont*)(new FTGLPolygonFont);
}
	

// PolygonFont
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Text
Text::
Text()
{
	setDefaults();
}

Text::
Text(Font* font)
{
	setDefaults();

	if(font && font->isOk())
	{
		_init=true;
		_font=font;

		if(dynamic_cast<PolygonFont*>(_font.get()))
			_fontType=POLYGON;
		else if(dynamic_cast<BitmapFont*>(_font.get()))
			_fontType=BITMAP;
		else if(dynamic_cast<PixmapFont*>(_font.get()))
			_fontType=PIXMAP;
		else if(dynamic_cast<TextureFont*>(_font.get()))
			_fontType=TEXTURE;
		else if(dynamic_cast<OutlineFont*>(_font.get()))
			_fontType=OUTLINE;

	}
}

Text::
~Text()
{
}

void Text::setFont(Font* font)
{
    if (_font==font) return;
    
    if(font && font->isOk())
    {
	_init=true;
	_font=font;

	if(dynamic_cast<PolygonFont*>(_font.get()))
		_fontType=POLYGON;
	else if(dynamic_cast<BitmapFont*>(_font.get()))
		_fontType=BITMAP;
	else if(dynamic_cast<PixmapFont*>(_font.get()))
		_fontType=PIXMAP;
	else if(dynamic_cast<TextureFont*>(_font.get()))
		_fontType=TEXTURE;
	else if(dynamic_cast<OutlineFont*>(_font.get()))
		_fontType=OUTLINE;

        _initAlignment = false;
        dirtyBound();            

    }
}

void Text::
setDefaults()
{
	_init=false;
	
	_pos.set(0,0,0);
	_alignmentPos.set(0,0,0);
	
	_fontType=UNDEF;
	_alignment=LEFT_BOTTOM;
	_drawMode=DEFAULT;

	_boundingBoxType=GLYPH;
	_boundingBoxType=GEOMETRY;

	_initAlignment=false;

	_useDisplayList=false;
}

const bool Text::
computeBound() const
{
	if(!_init)
	{
		_bbox_computed=false;
		return true;
	}

	// culling
	if(_font->isCreated())
	{	// ready to get the siz
		_bbox.init();

		Vec3 min,max;
		calcBounds(&min,&max);

		_bbox.expandBy(min);
		_bbox.expandBy(max);

		_bbox_computed=true;
	}
	else
	{	// have to wait for the init.
		_bbox.init();

		// to be sure that the obj isn't culled
//		_bbox.expandBy(_pos);

		_bbox.expandBy(_pos + Vec3(-100,-100,-100));
		_bbox.expandBy(_pos + Vec3(100,100,100));

		/*
		_bbox.expandBy(Vec3(-FLT_MAX,-FLT_MAX,-FLT_MAX));
		_bbox.expandBy(Vec3(FLT_MAX,FLT_MAX,FLT_MAX));
		*/
		_bbox_computed=true;

	}
	return true;
}

void Text::drawImmediateMode(State& state)
{
	if(!_init)
		return;
	
	if(!_font->isCreated())
	{
		_font->create();
		dirtyBound();
	}

	if(!_initAlignment)
		initAlignment();
	
	// draw boundingBox
	if(_drawMode & BOUNDINGBOX)
		drawBoundingBox();
	// draw alignment
	if(_drawMode & ALIGNEMENT)
		drawAlignment();

	// draw boundingBox
	if(_drawMode & TEXT)
	{
		Vec3	drawPos(_pos+_alignmentPos);
		glPushMatrix();
			switch(_fontType)
			{
				case POLYGON:
					glTranslatef(drawPos.x(),drawPos.y(),drawPos.z());
					_font->output(_text.c_str());
					break;
				case OUTLINE:
					glTranslatef(drawPos.x(),drawPos.y(),drawPos.z());
					_font->output(_text.c_str());
					break;
				case BITMAP:
					glRasterPos3f(drawPos.x(),drawPos.y(),drawPos.z());
					_font->output(_text.c_str());
					break;
				case PIXMAP:
					glRasterPos3f(drawPos.x(),drawPos.y(),drawPos.z());
					_font->output(_text.c_str());
					break;
				case TEXTURE:
					glTranslatef(drawPos.x(),drawPos.y(),drawPos.z());
					_font->output(_text.c_str());
					break;

			};
		glPopMatrix();
	}
}

void Text::
drawBoundingBox(void) 
{
	if(!_init)
		return;

	glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT );
		glDisable(GL_TEXTURE_2D);
		glColor3f(0,1,0);
		glBegin(GL_LINE_LOOP);
			glVertex3f(_bbox.xMin(),_bbox.yMin(),_bbox.zMin());
			glVertex3f(_bbox.xMax(),_bbox.yMin(),_bbox.zMin());
			glVertex3f(_bbox.xMax(),_bbox.yMax(),_bbox.zMin());
			glVertex3f(_bbox.xMin(),_bbox.yMax(),_bbox.zMin());
		glEnd();
	glPopAttrib();
}

void Text::
drawAlignment(void)
{
	if(!_init)
		return;

	double		size=_font->getPointSize()/4;

	glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT );
		glDisable(GL_TEXTURE_2D);
		glColor3f(1,0,0);
		glBegin(GL_LINES);
			glVertex3f(_pos.x() - size,_pos.y(),_pos.z());
			glVertex3f(_pos.x() + size,_pos.y(),_pos.z());
			
			glVertex3f(_pos.x(),_pos.y() - size,_pos.z());
			glVertex3f(_pos.x(),_pos.y() + size,_pos.z());
 
		glEnd();
	glPopAttrib();
}
	
void Text::
setPosition(const Vec3& pos)
{ 
	_pos=pos;
}

void Text::
setPosition(const Vec2& pos)
{  
	setPosition(Vec3(pos.x(),pos.y(),0)); 
}

void Text::
calcBounds(Vec3* min,Vec3* max) const
{
	if(!_init)
		return;

	float h=_font->getHeight();
	float w=_font->getWidth(_text.c_str());
	float descender=_font->getDescender();

	min->set(0,descender,0);
	max->set(w,h + descender ,0);
}

bool Text::
initAlignment(void)
{
	if(!_init)
		return false;

	// culling
	if(_font->isCreated())
	{	// ready to get the siz
		_bbox.init();

		Vec3 min,max;
		initAlignment(&min,&max);

		_bbox.expandBy(min);
		_bbox.expandBy(max);

		_bbox_computed=true;

		_initAlignment=true;
	}
	else
	{	// have to wait for the init.
		_bbox.init();

		// to be sure that the obj isn't culled
		_bbox.expandBy(Vec3(-FLT_MAX,-FLT_MAX,-FLT_MAX));
		_bbox.expandBy(Vec3(FLT_MAX,FLT_MAX,FLT_MAX));

		_bbox_computed=true;
	}

	return true;
}

void Text::
initAlignment(Vec3* min,Vec3* max)
{
	if(!_init)
		return;

	float h=_font->getHeight();
	float w=_font->getWidth(_text.c_str());
	float descender=_font->getDescender();

	min->set(0,descender,0);
	max->set(w,h + descender ,0);

	switch(_boundingBoxType)
	{
		case GLYPH:
			h+=descender;
			switch(_alignment)
			{
				case LEFT_TOP:
					_alignmentPos.set(0.0,h,0.0);
					break;
				case LEFT_CENTER:
					_alignmentPos.set(0.0,h/2.0,0.0);
					break;
				case LEFT_BOTTOM:
					_alignmentPos.set(0.0,0.0,0.0);
					break;

				case CENTER_TOP:
					_alignmentPos.set(w/2.0,h,0.0);
					break;
				case CENTER_CENTER:
					_alignmentPos.set(w/2.0,h/2.0,0.0);
					break;
				case CENTER_BOTTOM:
					_alignmentPos.set(w/2.0,0.0,0.0);
					break;

				case RIGHT_TOP:
					_alignmentPos.set(w,h,0.0);
					break;
				case RIGHT_CENTER:
					_alignmentPos.set(w,h/2.0,0.0);
					break;
				case RIGHT_BOTTOM:
					_alignmentPos.set(w,0.0,0.0);
					break;
			};
			_alignmentPos=-_alignmentPos;

			*min+=_pos+_alignmentPos;
			*max+=_pos+_alignmentPos;
			break;

		case GEOMETRY:
			switch(_alignment)
			{
				case LEFT_TOP:
					_alignmentPos.set(0.0,h + descender,0.0);
					break;
				case LEFT_CENTER:
					_alignmentPos.set(0.0,(max->y()-min->y()) /2.0 + descender,0.0);
					break;
				case LEFT_BOTTOM:
					_alignmentPos.set(0.0,descender,0.0);
					break;

				case CENTER_TOP:
					_alignmentPos.set(w/2.0,h + descender,0.0);
					break;
				case CENTER_CENTER:
					_alignmentPos.set(w/2.0,(max->y()-min->y()) /2.0 + descender,0.0);
					break;
				case CENTER_BOTTOM:
					_alignmentPos.set(w/2.0,descender,0.0);
					break;

				case RIGHT_TOP:
					_alignmentPos.set(w,h + descender,0.0);
					break;
				case RIGHT_CENTER:
					_alignmentPos.set(w,(max->y()-min->y()) /2.0 + descender,0.0);
					break;
				case RIGHT_BOTTOM:
					_alignmentPos.set(w,descender,0.0);
					break;
			};
			_alignmentPos=-_alignmentPos;

			*min+=_pos+_alignmentPos;
			*max+=_pos+_alignmentPos;
			break;
	};

	

	switch(_fontType)
	{
		case BITMAP:
			break;
		case PIXMAP:
			break;

	};
}


void Text::
setAlignment(int alignment)
{
	_alignment=alignment;
	
	if(!_init || !_font->isCreated())
		return;

	initAlignment();
}

void Text::
setBoundingBox(int mode)
{
	_boundingBoxType=mode;
	
	if(!_init || !_font->isCreated())
		return;

	initAlignment();
}

// Text
///////////////////////////////////////////////////////////////////////////////
