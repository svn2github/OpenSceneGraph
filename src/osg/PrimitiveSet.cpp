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
#include <osg/PrimitiveSet>

using namespace osg;

void DrawArrays::draw() const 
{
    glDrawArrays(_mode,_first,_count);
}

void DrawArrays::accept(Drawable::PrimitiveFunctor& functor) const
{
    functor.drawArrays(_mode,_first,_count);
}

void DrawArrays::accept(Drawable::PrimitiveIndexFunctor& functor) const
{
    functor.drawArrays(_mode,_first,_count);
}

void DrawArrayLengths::draw() const
{
    GLint first = _first;
    for(VectorSizei::const_iterator itr=begin();
        itr!=end();
        ++itr)
    {
        glDrawArrays(_mode,first,*itr);
        first += *itr;
    }
}

void DrawArrayLengths::accept(Drawable::PrimitiveFunctor& functor) const
{
    GLint first = _first;
    for(VectorSizei::const_iterator itr=begin();
        itr!=end();
        ++itr)
    {
        functor.drawArrays(_mode,first,*itr);
        first += *itr;
    }
}

void DrawArrayLengths::accept(Drawable::PrimitiveIndexFunctor& functor) const
{
    GLint first = _first;
    for(VectorSizei::const_iterator itr=begin();
        itr!=end();
        ++itr)
    {
        functor.drawArrays(_mode,first,*itr);
        first += *itr;
    }
}

unsigned int DrawArrayLengths::getNumIndices() const
{
    unsigned int count = 0;
    for(VectorSizei::const_iterator itr=begin();
        itr!=end();
        ++itr)
    {
        count += *itr;
    }
    return count;
}

void DrawElementsUByte::draw() const 
{
    glDrawElements(_mode,size(),GL_UNSIGNED_BYTE,&front());
}

void DrawElementsUByte::accept(Drawable::PrimitiveFunctor& functor) const
{
    if (!empty()) functor.drawElements(_mode,size(),&front());
}

void DrawElementsUByte::accept(Drawable::PrimitiveIndexFunctor& functor) const
{
    if (!empty()) functor.drawElements(_mode,size(),&front());
}

void DrawElementsUByte::offsetIndices(int offset)
{
    for(iterator itr=begin();
        itr!=end();
        ++itr)
    {
        *itr += offset;
    }
}


void DrawElementsUShort::draw() const 
{
    glDrawElements(_mode,size(),GL_UNSIGNED_SHORT,&front());
}

void DrawElementsUShort::accept(Drawable::PrimitiveFunctor& functor) const
{
    if (!empty()) functor.drawElements(_mode,size(),&front());
}

void DrawElementsUShort::accept(Drawable::PrimitiveIndexFunctor& functor) const
{
    if (!empty()) functor.drawElements(_mode,size(),&front());
}

void DrawElementsUShort::offsetIndices(int offset)
{
    for(iterator itr=begin();
        itr!=end();
        ++itr)
    {
        *itr += offset;
    }
}


void DrawElementsUInt::draw() const 
{
    glDrawElements(_mode,size(),GL_UNSIGNED_INT,&front());
}

void DrawElementsUInt::accept(Drawable::PrimitiveFunctor& functor) const
{
    if (!empty()) functor.drawElements(_mode,size(),&front());
}

void DrawElementsUInt::accept(Drawable::PrimitiveIndexFunctor& functor) const
{
    if (!empty()) functor.drawElements(_mode,size(),&front());
}

void DrawElementsUInt::offsetIndices(int offset)
{
    for(iterator itr=begin();
        itr!=end();
        ++itr)
    {
        *itr += offset;
    }
}
