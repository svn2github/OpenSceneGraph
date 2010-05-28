/*
 * Copyright 2006 Sony Computer Entertainment Inc.
 *
 * Licensed under the SCEA Shared Source License, Version 1.0 (the "License"); you may not use this 
 * file except in compliance with the License. You may obtain a copy of the License at:
 * http://research.scea.com/scea_shared_source_license.html
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License 
 * is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
 * implied. See the License for the specific language governing permissions and limitations under the 
 * License. 
 */

#include "domSourceReader.h"

#include <dom/domSource.h>

using namespace osgDAE;

domSourceReader::domSourceReader() : m_array_type( None ), m_count( 0 )
{}

domSourceReader::domSourceReader( domSource *src ) : m_array_type( None ), m_count( 0 )
{
    domSource::domTechnique_common* technique = src->getTechnique_common();
    if ( technique == NULL ) {
        OSG_WARN<<"Warning: IntDaeSource::createFrom: Unable to find COMMON technique"<<std::endl;
        return;
    }

    domAccessor* accessor = technique->getAccessor();
    int stride = accessor->getStride();
    m_count = accessor->getCount();

    // Only handle floats or name array for now...
    daeDoubleArray* float_array = NULL;
    if (src->getFloat_array()) 
    {
        float_array = &(src->getFloat_array()->getValue());
    }
    else if (src->getName_array())
    {
        m_array_type = String;
        return;
    }

    switch (stride) 
    {
        case 1:
            m_array_type = Float;
            m_float_array = new osg::FloatArray();
            break;
        case 2:
            m_array_type = Vec2;
            m_vec2_array = new osg::Vec2Array();
            break;
        case 3:
            m_array_type = Vec3;
            m_vec3_array = new osg::Vec3Array();
            break;
        case 4:
            m_array_type = Vec4;
            m_vec4_array = new osg::Vec4Array();
            break;
        case 16:
            m_array_type = Matrix;
            m_matrix_array = new osg::MatrixfArray();
            break;
        default:
            OSG_WARN<<"Unsupported stride: "<<stride<<std::endl;
            return;
    }

    if (float_array) 
    {
        daeDoubleArray& va = *float_array;
        for ( size_t i = 0; i < accessor->getCount(); i++ ) 
        {
            switch ( accessor->getStride() ) 
            {
                case 1:
                    m_float_array->push_back(va[i]);
                    break;
                case 2:
                    m_vec2_array->push_back( osg::Vec2( va[i*2], va[i*2+1]));
                    break;
                case 3:
                    m_vec3_array->push_back( osg::Vec3( va[i*3], va[i*3+1], va[i*3+2]));
                    break;
                case 4:
                    m_vec4_array->push_back( osg::Vec4( va[i*4], va[i*4+1], va[i*4+2], va[i*4+3]));
                    break;
                case 16:
                    m_matrix_array->push_back(osg::Matrixf( va[i*16+0],    va[i*16+4],    va[i*16+8],    va[i*16+12],
                                                            va[i*16+1],    va[i*16+5],    va[i*16+9],    va[i*16+13],
                                                            va[i*16+2],    va[i*16+6],    va[i*16+10],    va[i*16+14],
                                                            va[i*16+3],    va[i*16+7],    va[i*16+11],    va[i*16+15]));
                    break;
                default:
                    OSG_WARN << "Unsupported stride in Source: " << accessor->getStride() << std::endl;
                    return;
            }
        }
    }
    else
    {
        OSG_WARN << "No float array found" << std::endl;
    }
}
