/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2003 Robert Osfield 
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


#include <osg/GL>
#include <osg/Math>
#include <osgUtil/CullVisitor>
#include <osgDB/ReadFile>
#include <osgText/Text>

#include "DefaultFont.h"

using namespace osgText;

struct TextCullCallback : public osg::Drawable::CullCallback
{

    struct PositionData
    {    
        PositionData():
            _traversalNumber(-1),
            _previousWidth(0),
            _previousHeight(0) {}
    
        int         _traversalNumber;
        int         _previousWidth;
        int         _previousHeight;
        osg::Vec3   _eyePosition;
    };

    TextCullCallback(osgText::Text* text):
        _text(text) {}

    /** do customized cull code.*/
    virtual bool cull(osg::NodeVisitor *nv, osg::Drawable*, osg::State*) const
    {
        osgUtil::CullVisitor* cs = static_cast<osgUtil::CullVisitor*>(nv);
        if (!cs) return false;
        
        unsigned int contextID = cs->getState() ? cs->getState()->getContextID() : 0;
        
        PositionData& positionData = _positions[contextID];
        
        int width = positionData._previousWidth;
        int height = positionData._previousHeight;

        osg::Viewport* viewport = cs->getViewport();
        if (viewport)
        {
            width = viewport->width();
            height = viewport->height();
        }

        osg::Vec3 eyePoint = cs->getEyeLocal();  
        
        bool doUpdate = positionData._traversalNumber==-1;
        if (positionData._traversalNumber>=0)
        {
            osg::Vec3 dv = positionData._eyePosition-eyePoint;
            if (dv.length2()>_text->getAutoUpdateEyeMovementTolerance()*(eyePoint-_text->getPosition()).length2())
            {
                doUpdate = true;
            }
            else if (width!=positionData._previousWidth || height!=positionData._previousHeight)
            {
                doUpdate = true;
            } 
        }
        
        positionData._traversalNumber = nv->getTraversalNumber();
        positionData._previousWidth = width;
        positionData._previousHeight = height;
        
        if (doUpdate)
        {            

            float scale=_text->getScale(contextID);

            if (_text->getAutoScaleToLimitScreenSizeToFontResolution())
            {
                float numPixels = cs->pixelSize(_text->getPosition(),_text->getCharacterHeight());
                if (numPixels>_text->getFontHeight())
                {
                    scale = _text->getFontHeight()/numPixels;
                }
            
                //float size = 1.0f/cs->pixelSize(_text->getPosition(),1.0f);
                //_text->setScale(size);
            }

            osg::Quat rotation = _text->getRotation(contextID);
            if (_text->getAutoRotateToScreen())
            {
                rotation.set(cs->getModelViewMatrix());
                rotation = rotation.inverse();
            }

            _text->setScaleAndRotation(contextID,scale,rotation);

        }

        return false;
    }

    typedef osg::buffered_object<PositionData> PositionList;
    mutable PositionList    _positions;
    mutable osgText::Text*  _text;

};



Text::Text():
    _fontWidth(32),
    _fontHeight(32),
    _characterHeight(32),
    _characterAspectRatio(1.0f),
    _maximumWidth(0.0f),
    _maximumHeight(0.0f),
    _alignment(BASE_LINE),
    _autoUpdateEyeMovementTolerance(0.0f),
    _autoRotateToScreen(false),
    _autoScaleToLimitScreenSizeToFontResolution(false),
    _layout(LEFT_TO_RIGHT),
    _color(1.0f,1.0f,1.0f,1.0f),
    _drawMode(TEXT)
{
    setUseDisplayList(false);
    setScale(1.0f);
}

Text::Text(const Text& text,const osg::CopyOp& copyop):
    osg::Drawable(text,copyop),
    _font(text._font),
    _fontWidth(text._fontWidth),
    _fontHeight(text._fontHeight),
    _characterHeight(text._characterHeight),
    _characterAspectRatio(text._characterAspectRatio),
    _maximumWidth(text._maximumWidth),
    _maximumHeight(text._maximumHeight),
    _text(text._text),
    _position(text._position),
    _alignment(text._alignment),
    _rotation(text._rotation),
    _scale(text._scale),
    _autoUpdateEyeMovementTolerance(text._autoUpdateEyeMovementTolerance),
    _autoRotateToScreen(text._autoRotateToScreen),
    _autoScaleToLimitScreenSizeToFontResolution(text._autoScaleToLimitScreenSizeToFontResolution),
    _layout(text._layout),
    _color(text._color),
    _drawMode(text._drawMode)
{
    setUpAutoCallback();
    computeGlyphRepresentation();
}

Text::~Text()
{
}

void Text::setFont(Font* font)
{
    if (_font==font) return;
    
    _font = font;
    
    computeGlyphRepresentation();
}

void Text::setFont(const std::string& fontfile)
{
    setFont(readFontFile(fontfile));
}

void Text::setFontResolution(unsigned int width, unsigned int height)
{
    _fontWidth = width;
    _fontHeight = height;
    computeGlyphRepresentation();
}


void Text::setCharacterSize(float height,float aspectRatio)
{
    _characterHeight = height;
    _characterAspectRatio = aspectRatio;
    computeGlyphRepresentation();
}

void Text::setMaximumWidth(float maximumWidth)
{
    _maximumWidth = maximumWidth;
    computeGlyphRepresentation();
}

void  Text::setMaximumHeight(float maximumHeight)
{
    _maximumHeight = maximumHeight;
    computeGlyphRepresentation();
}
    

void Text::setText(const String& text)
{
    if (_text==text) return;
    
    _text = text;
    computeGlyphRepresentation();
}

void Text::setText(const std::string& text)
{
    setText(String(text));
//     _text.set(text);
//     computeGlyphRepresentation();
}

void Text::setText(const std::string& text,String::Encoding encoding)
{
    setText(String(text,encoding));
//     _text.set(text,encoding);
//     computeGlyphRepresentation();
}
    

void Text::setText(const wchar_t* text)
{
    setText(String(text));
//     _text.set(text);
//     computeGlyphRepresentation();
}

void Text::setPosition(const osg::Vec3& pos)
{
    if (_position==pos) return;

    _position = pos;
    computePositions();
}

void Text::setAlignment(AlignmentType alignment)
{
    if (_alignment==alignment) return;
    
    _alignment = alignment;
    computePositions();
}

void Text::setAxisAlignment(AxisAlignment axis)
{
    switch(axis)
    {
    case XZ_PLANE:
        setRotation(osg::Quat(osg::inDegrees(90.0f),osg::Vec3(1.0f,0.0f,0.0f))); 
        break;
    case YZ_PLANE:  
        setRotation(osg::Quat(osg::inDegrees(90.0f),osg::Vec3(1.0f,0.0f,0.0f))*
                    osg::Quat(osg::inDegrees(90.0f),osg::Vec3(0.0f,0.0f,1.0f)));
        break;
    case XY_PLANE:
        setRotation(osg::Quat());  // nop - already on XY plane.
        break;
    case SCREEN:
        setAutoRotateToScreen(true);
        break;
    }
}

void Text::setRotation(const osg::Quat& quat)
{
    for(unsigned int i=0;i<_rotation.size();++i)
    {
        setRotation(i,quat);
    } 
}

void Text::setRotation(unsigned int contextID, const osg::Quat& quat)
{
    if (_rotation[contextID]==quat) return;
    
    _rotation[contextID] = quat;
    computePositions(contextID);
}

void Text::setScale(float scale)
{
    for(unsigned int i=0;i<_scale.size();++i)
    {
        setScale(i,scale);
    } 
}

void Text::setScale(unsigned int contextID, float scale)
{
    if (_scale[contextID]==scale) return;
    
    _scale[contextID] = scale;
    computePositions(contextID);
}

void Text::setScaleAndRotation(unsigned int contextID, float scale,const osg::Quat& quat)
{
    if (_scale[contextID]==scale && _rotation[contextID]==quat) return;
    
    _scale[contextID] = scale;
    _rotation[contextID] = quat;
    
    computePositions(contextID);
}

void Text::setAutoScaleToLimitScreenSizeToFontResolution(bool autoScaleToScreen)
{
    if (_autoScaleToLimitScreenSizeToFontResolution==autoScaleToScreen) return;

    _autoScaleToLimitScreenSizeToFontResolution = autoScaleToScreen;
    setUpAutoCallback();
}

void Text::setAutoRotateToScreen(bool autoRotateToScreen)
{
    if (_autoRotateToScreen==autoRotateToScreen) return;
    
    _autoRotateToScreen = autoRotateToScreen;
    setUpAutoCallback();
}


void Text::setUpAutoCallback()
{
    if (_autoRotateToScreen || _autoScaleToLimitScreenSizeToFontResolution)
    {
        if (!getCullCallback())
        {
            setCullCallback(new TextCullCallback(this));
        }
    }
    else setCullCallback(0);
}

void Text::setLayout(Layout layout)
{
    if (_layout==layout) return;

    _layout = layout;
    computeGlyphRepresentation();
}

void Text::setColor(const osg::Vec4& color)
{
    _color = color;
}

void Text::setDrawMode(unsigned int mode) 
{ 
    if (_drawMode==mode) return;

    if ((_drawMode&3) != (mode&3))
    {
        _drawMode=mode;
        if (_drawMode&TEXT_PIXMAP)
        {
            setAutoScaleToLimitScreenSizeToFontResolution(true);
            setAutoRotateToScreen(true);
        }
        computeGlyphRepresentation();
    }
    else
    {
        _drawMode=mode;
    }
}


bool Text::computeBound() const
{
    _bbox.init();

    if (_textBB.valid())
    {
    
        for(unsigned int i=0;i<_matrix.size();++i)
        {
            osg::Matrix& matrix = _matrix[i];
            _bbox.expandBy(osg::Vec3(_textBB.xMin(),_textBB.yMin(),_textBB.zMin())*matrix);
            _bbox.expandBy(osg::Vec3(_textBB.xMax(),_textBB.yMin(),_textBB.zMin())*matrix);
            _bbox.expandBy(osg::Vec3(_textBB.xMax(),_textBB.yMax(),_textBB.zMin())*matrix);
            _bbox.expandBy(osg::Vec3(_textBB.xMin(),_textBB.yMax(),_textBB.zMin())*matrix);
        }
    }
    
    _bbox_computed = true;
    return true;
}

Font* Text::getActiveFont()
{
    return _font.valid() ? _font.get() : DefaultFont::instance();
}

const Font* Text::getActiveFont() const
{
    return _font.valid() ? _font.get() : DefaultFont::instance();
}

void Text::computeGlyphRepresentation()
{
    Font* activefont = getActiveFont();
    if (!activefont) return;
    
    _textureGlyphQuadMap.clear();
    
    if (_text.empty()) return;
    
    osg::Vec2 startOfLine(0.0f,0.0f);
    osg::Vec2 cursor(startOfLine);
    osg::Vec2 local(0.0f,0.0f);
    
    unsigned int previous_charcode = 0;
    bool horizontal = _layout!=VERTICAL;
    bool kerning = true;

    activefont->setSize(_fontWidth,_fontHeight);
    
    float hr = _characterHeight/(float)activefont->getHeight();
    float wr = hr/_characterAspectRatio;

    for(String::iterator itr=_text.begin();
        itr!=_text.end();
        ++itr)
    {
        unsigned int charcode = *itr;
        
        if (charcode=='\n')
        {
            if (horizontal) startOfLine.y() -= _characterHeight;
            else startOfLine.x() += _characterHeight;
            cursor = startOfLine;
            previous_charcode = 0;
            continue;
        }
        
        
        Font::Glyph* glyph = activefont->getGlyph(charcode);
        if (glyph)
        {

            float width = (float)(glyph->s()-2*activefont->getGlyphImageMargin()) * wr;
            float height = (float)(glyph->t()-2*activefont->getGlyphImageMargin()) * hr;

            if (_layout==RIGHT_TO_LEFT)
            {
                cursor.x() -= glyph->getHorizontalAdvance() * wr;
            }

            // adjust cursor position w.r.t any kerning.
            if (kerning && previous_charcode)
            {
                switch(_layout)
                {
                  case LEFT_TO_RIGHT:
                  {
                    osg::Vec2 delta(activefont->getKerning(previous_charcode,charcode));
                    cursor.x() += delta.x() * wr;
                    cursor.y() += delta.y() * hr;
                    break;
                  }
                  case RIGHT_TO_LEFT:
                  {
                    osg::Vec2 delta(activefont->getKerning(charcode,previous_charcode));
                    cursor.x() -= delta.x() * wr;
                    cursor.y() -= delta.y() * hr;
                    break;
                  }
                  case VERTICAL:
                    break; // no kerning when vertical.
                }
            }
        
            local = cursor;
        

            osg::Vec2 bearing(horizontal?glyph->getHorizontalBearing():glyph->getVerticalBearing());
            local.x() += bearing.x() * wr;
            local.y() += bearing.y() * hr;

            // check to see if we are still within line if not move to next line.
            switch(_layout)
            {
              case LEFT_TO_RIGHT:
              {
                if (_maximumWidth>0.0f)
                {
                    if (local.x()+width>_maximumWidth)
                    {
                        startOfLine.y() -= _characterHeight;
                        cursor = startOfLine;
                        previous_charcode = 0;

                        local = cursor;
                        local.x() += bearing.x() * wr;
                        local.y() += bearing.y() * hr;
                    }
                }
                break;
              }
              case RIGHT_TO_LEFT:
              {
                if (_maximumWidth>0.0f)
                {
                    if (local.x()<-_maximumWidth)
                    {
                        startOfLine.y() -= _characterHeight;
                        cursor = startOfLine;
                        previous_charcode = 0;

                        local = cursor;
                        local.x() += bearing.x() * wr;
                        local.y() += bearing.y() * hr;
                    }
;                }
                break;
              }
              case VERTICAL:
                if (_maximumHeight>0.0f)
                {
                    if (local.y()<-_maximumHeight)
                    {
                        startOfLine.x() += _characterHeight/_characterAspectRatio;
                        cursor = startOfLine;
                        previous_charcode = 0;

                        local = cursor;
                        local.x() += bearing.x() * wr;
                        local.y() += bearing.y() * hr;
                    }
                }
                break;
            }
        
            GlyphQuads& glyphquad = _textureGlyphQuadMap[glyph->getTexture()->getStateSet()];
            
            glyphquad._glyphs.push_back(glyph);

            // set up the coords of the quad
            glyphquad._coords.push_back(local+osg::Vec2(0.0f,height));
            glyphquad._coords.push_back(local+osg::Vec2(0.0f,0.0f));
            glyphquad._coords.push_back(local+osg::Vec2(width,0.0f));
            glyphquad._coords.push_back(local+osg::Vec2(width,height));
            
            // set up the tex coords of the quad
            const osg::Vec2& mintc = glyph->getMinTexCoord();
            const osg::Vec2& maxtc = glyph->getMaxTexCoord();
            
            glyphquad._texcoords.push_back(osg::Vec2(mintc.x(),maxtc.y()));
            glyphquad._texcoords.push_back(osg::Vec2(mintc.x(),mintc.y()));
            glyphquad._texcoords.push_back(osg::Vec2(maxtc.x(),mintc.y()));
            glyphquad._texcoords.push_back(osg::Vec2(maxtc.x(),maxtc.y()));
            
            // move the cursor onto the next character.
            switch(_layout)
            {
              case LEFT_TO_RIGHT: cursor.x() += glyph->getHorizontalAdvance() * wr; break;
              case VERTICAL:      cursor.y() -= glyph->getVerticalAdvance() *hr; break;
              case RIGHT_TO_LEFT: break; // nop.
            }            
        }
        
        previous_charcode = charcode;
    }

    _textBB.init();

    for(TextureGlyphQuadMap::const_iterator titr=_textureGlyphQuadMap.begin();
        titr!=_textureGlyphQuadMap.end();
        ++titr)
    {
        const GlyphQuads& glyphquad = titr->second;
        
        for(GlyphQuads::Coords2::const_iterator citr = glyphquad._coords.begin();
            citr != glyphquad._coords.end();
            ++citr)
        {
            _textBB.expandBy(osg::Vec3(citr->x(),citr->y(),0.0f));
        }
    }

    if (!_textureGlyphQuadMap.empty()) 
    {
        setStateSet(const_cast<osg::StateSet*>((*_textureGlyphQuadMap.begin()).first.get()));
    }

    computePositions();
}


void Text::computePositions()
{
    for(unsigned int i=0;i<_matrix.size();++i)
    {
        computePositions(i);
    }
}

void Text::computePositions(unsigned int contextID)
{

    switch(_alignment)
    {
    case LEFT_TOP:      _offset.set(_textBB.xMin(),_textBB.yMax(),_textBB.zMin()); break;
    case LEFT_CENTER:   _offset.set(_textBB.xMin(),(_textBB.yMax()+_textBB.yMin())*0.5f,_textBB.zMin()); break;
    case LEFT_BOTTOM:   _offset.set(_textBB.xMin(),_textBB.yMin(),_textBB.zMin()); break;

    case CENTER_TOP:    _offset.set((_textBB.xMax()+_textBB.xMin())*0.5f,_textBB.yMax(),_textBB.zMin()); break;
    case CENTER_CENTER: _offset.set((_textBB.xMax()+_textBB.xMin())*0.5f,(_textBB.yMax()+_textBB.yMin())*0.5f,_textBB.zMin()); break;
    case CENTER_BOTTOM: _offset.set((_textBB.xMax()+_textBB.xMin())*0.5f,_textBB.yMin(),_textBB.zMin()); break;

    case RIGHT_TOP:     _offset.set(_textBB.xMax(),_textBB.yMax(),_textBB.zMin()); break;
    case RIGHT_CENTER:  _offset.set(_textBB.xMax(),(_textBB.yMax()+_textBB.yMin())*0.5f,_textBB.zMin()); break;
    case RIGHT_BOTTOM:  _offset.set(_textBB.xMax(),_textBB.yMin(),_textBB.zMin()); break;
    case LEFT_BASE_LINE:  _offset.set(0.0f,0.0f,0.0f); break;
    case CENTER_BASE_LINE:  _offset.set((_textBB.xMax()+_textBB.xMin())*0.5f,0.0f,0.0f); break;
    case RIGHT_BASE_LINE:  _offset.set((_textBB.xMax()+_textBB.xMin()),0.0f,0.0f); break;
    }
    
    osg::Matrix& matrix = _matrix[contextID];

    if (_scale[contextID]!=1.0f || !_rotation[contextID].zeroRotation())
    {
        matrix.makeTranslate(-_offset);

        if (_scale[contextID]!=1.0f)
            matrix.postMult(osg::Matrix::scale(_scale[contextID],_scale[contextID],_scale[contextID]));
        if (!_rotation[contextID].zeroRotation())
            matrix.postMult(osg::Matrix::rotate(_rotation[contextID]));


        matrix.postMult(osg::Matrix::translate(_position));
    }
    else
    {
        matrix.makeTranslate(_position-_offset);
    }


    // now apply matrix to the glyphs.
    for(TextureGlyphQuadMap::iterator titr=_textureGlyphQuadMap.begin();
        titr!=_textureGlyphQuadMap.end();
        ++titr)
    {
        GlyphQuads& glyphquad = titr->second;
        GlyphQuads::Coords2& coords2 = glyphquad._coords;
        GlyphQuads::Coords3& transformedCoords = glyphquad._transformedCoords[contextID];
        
        unsigned int numCoords = coords2.size();
        if (numCoords!=transformedCoords.size())
        {
            transformedCoords.resize(numCoords);
        }
        
        for(unsigned int i=0;i<numCoords;++i)
        {
            transformedCoords[i] = osg::Vec3(coords2[i].x(),coords2[i].y(),0.0f)*matrix;
        }
    }

    _normal = osg::Matrix::transform3x3(osg::Vec3(0.0f,0.0f,1.0f),matrix);
    _normal.normalize();

    dirtyBound();    
}

void Text::drawImplementation(osg::State& state) const
{
    unsigned int contextID = state.getContextID();

    glNormal3fv(_normal.ptr());
    glColor4fv(_color.ptr());

    if (_drawMode & TEXT && !(_drawMode & TEXT_PIXMAP))
    {

        state.disableAllVertexArrays();

        for(TextureGlyphQuadMap::const_iterator titr=_textureGlyphQuadMap.begin();
            titr!=_textureGlyphQuadMap.end();
            ++titr)
        {
            // need to set the texture here...
            state.apply(titr->first.get());

            const GlyphQuads& glyphquad = titr->second;

            state.setVertexPointer( 3, GL_FLOAT, 0, &(glyphquad._transformedCoords[contextID].front()));
            state.setTexCoordPointer( 0, 2, GL_FLOAT, 0, &(glyphquad._texcoords.front()));

            glDrawArrays(GL_QUADS,0,glyphquad._coords.size());

        }
    }
    
    if (_drawMode & TEXT_PIXMAP)
    {

        state.applyTextureMode(0,GL_TEXTURE_2D,osg::StateAttribute::OFF);

        for(TextureGlyphQuadMap::const_iterator titr=_textureGlyphQuadMap.begin();
            titr!=_textureGlyphQuadMap.end();
            ++titr)
        {
            const GlyphQuads& glyphquad = titr->second;

            int ci=1;

            for(GlyphQuads::Glyphs::const_iterator gitr=glyphquad._glyphs.begin();
                gitr!=glyphquad._glyphs.end();
                ++gitr, ci+=4)
            {
            
                Font::Glyph* glyph = *gitr;
                

                glRasterPos3fv(glyphquad._transformedCoords[contextID][ci].ptr());

                glyph->draw(state);

            }

        }
    }

    if (_drawMode & BOUNDINGBOX)
    {
    
        if (_textBB.valid())
        {
            state.applyTextureMode(0,GL_TEXTURE_2D,osg::StateAttribute::OFF);
            
            osg::Matrix& matrix = _matrix[contextID];

            osg::Vec3 c00(osg::Vec3(_textBB.xMin(),_textBB.yMin(),_textBB.zMin())*matrix);
            osg::Vec3 c10(osg::Vec3(_textBB.xMax(),_textBB.yMin(),_textBB.zMin())*matrix);
            osg::Vec3 c11(osg::Vec3(_textBB.xMax(),_textBB.yMax(),_textBB.zMin())*matrix);
            osg::Vec3 c01(osg::Vec3(_textBB.xMin(),_textBB.yMax(),_textBB.zMin())*matrix);

        
            glColor4f(1.0f,1.0f,0.0f,1.0f);
            glBegin(GL_LINE_LOOP);
                glVertex3fv(c00.ptr());
                glVertex3fv(c10.ptr());
                glVertex3fv(c11.ptr());
                glVertex3fv(c01.ptr());
            glEnd();
        }
    }    

    if (_drawMode & ALIGNMENT)
    {
        glColor4f(1.0f,0.0f,1.0f,1.0f);

        float cursorsize = _characterHeight*0.5f*_scale[contextID];

        osg::Matrix& matrix = _matrix[contextID];

        osg::Vec3 hl(osg::Vec3(_offset.x()-cursorsize,_offset.y(),_offset.z())*matrix);
        osg::Vec3 hr(osg::Vec3(_offset.x()+cursorsize,_offset.y(),_offset.z())*matrix);
        osg::Vec3 vt(osg::Vec3(_offset.x(),_offset.y()-cursorsize,_offset.z())*matrix);
        osg::Vec3 vb(osg::Vec3(_offset.x(),_offset.y()+cursorsize,_offset.z())*matrix);

        state.applyTextureMode(0,GL_TEXTURE_2D,osg::StateAttribute::OFF);
        
        glBegin(GL_LINES);
            glVertex3fv(hl.ptr());
            glVertex3fv(hr.ptr());
            glVertex3fv(vt.ptr());
            glVertex3fv(vb.ptr());
        glEnd();
        
    }    


//    glPopMatrix();
}

void Text::accept(osg::Drawable::ConstAttributeFunctor& af) const
{
    for(TextureGlyphQuadMap::const_iterator titr=_textureGlyphQuadMap.begin();
        titr!=_textureGlyphQuadMap.end();
        ++titr)
    {
        const GlyphQuads& glyphquad = titr->second;
        af.apply(osg::Drawable::VERTICES,glyphquad._transformedCoords[0].size(),&(glyphquad._transformedCoords[0].front()));
        af.apply(osg::Drawable::TEXTURE_COORDS_0,glyphquad._texcoords.size(),&(glyphquad._texcoords.front()));
    }
}

void Text::accept(osg::Drawable::PrimitiveFunctor& pf) const
{
    for(TextureGlyphQuadMap::const_iterator titr=_textureGlyphQuadMap.begin();
        titr!=_textureGlyphQuadMap.end();
        ++titr)
    {
        const GlyphQuads& glyphquad = titr->second;

        pf.setVertexArray(glyphquad._transformedCoords[0].size(),&(glyphquad._transformedCoords[0].front()));
        pf.drawArrays(GL_QUADS,0,glyphquad._transformedCoords[0].size());
            
//         pf.begin(GL_QUADS);
//         for(GlyphQuads::Coords3::const_iterator itr = glyphquad._transformedCoords.begin();
//             itr!=glyphquad._transformedCoords.end();
//             ++itr)
//         {
//             pf.vertex(*itr);
//         }
//         pf.end();
    }
    
}
