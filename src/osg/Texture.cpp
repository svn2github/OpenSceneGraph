#if defined(_MSC_VER)
	#pragma warning( disable : 4786 )
#endif

#include <osg/ref_ptr>
#include <osg/Image>
#include <osg/Texture>
#include <osg/State>
#include <osg/Notify>
#include <osg/GLExtensions>

#include <osg/GLU>

using namespace osg;


Texture::DeletedTextureObjectCache Texture::s_deletedTextureObjectCache;

Texture::Texture()
{
    _handleList.resize(DisplaySettings::instance()->getMaxNumberOfGraphicsContexts(),0);
    _modifiedTag.resize(DisplaySettings::instance()->getMaxNumberOfGraphicsContexts(),0);

    _textureUnit = 0;

    _wrap_s    = CLAMP;
    _wrap_t    = CLAMP;
    _wrap_r    = CLAMP;
    //_min_filter    = LINEAR_MIPMAP_LINEAR; // trilinear
    //_min_filter    = LINEAR_MIPMAP_NEAREST; // bilinear
    _min_filter     = NEAREST_MIPMAP_LINEAR; // OpenGL default
    _mag_filter     = LINEAR;

    _internalFormatMode = USE_IMAGE_DATA_FORMAT;
    _internalFormatValue = 0;

    _textureWidth = _textureHeight = 0;

    _textureObjectSize = 0;

    _subloadMode   = OFF;
    _subloadOffsX = _subloadOffsY = 0;

    _borderColor.set(0.0, 0.0, 0.0, 0.0);//OpenGL default

    _texParamtersDirty = true;
}


Texture::~Texture()
{
    // delete old texture objects.
    dirtyTextureObject();
}

int Texture::compare(const StateAttribute& sa) const
{
    // check the types are equal and then create the rhs variable
    // used by the COMPARE_StateAttribute_Paramter macro's below.
    COMPARE_StateAttribute_Types(Texture,sa)

    if (_image!=rhs._image) // smart pointer comparison.
    {
        if (_image.valid())
        {
            if (rhs._image.valid())
            {
                if (_image->getFileName()<rhs._image->getFileName()) return -1;
                else if (_image->getFileName()>rhs._image->getFileName()) return 1;;
            }
            else
            {
                return 1; // valid lhs._image is greater than null. 
            }
        }
        else if (rhs._image.valid()) 
        {
            return -1; // valid rhs._image is greater than null. 
        }
    }

    // compare each paramter in turn against the rhs.
    COMPARE_StateAttribute_Parameter(_textureUnit)
    COMPARE_StateAttribute_Parameter(_wrap_s)
    COMPARE_StateAttribute_Parameter(_wrap_t)
    COMPARE_StateAttribute_Parameter(_wrap_r)
    COMPARE_StateAttribute_Parameter(_min_filter)
    COMPARE_StateAttribute_Parameter(_mag_filter)
    COMPARE_StateAttribute_Parameter(_internalFormatMode)
    COMPARE_StateAttribute_Parameter(_internalFormatValue)
    COMPARE_StateAttribute_Parameter(_textureWidth)
    COMPARE_StateAttribute_Parameter(_textureHeight)
    COMPARE_StateAttribute_Parameter(_subloadMode)
    COMPARE_StateAttribute_Parameter(_subloadOffsX)
    COMPARE_StateAttribute_Parameter(_subloadOffsY)

    return 0; // passed all the above comparison macro's, must be equal.
}

void Texture::setImage(Image* image)
{
    // delete old texture objects.
    for(TextureNameList::iterator itr=_handleList.begin();
                               itr!=_handleList.end();
                               ++itr)
    {
        if (*itr != 0)
        {
            // contact global texture object handler to delete texture objects
            // in appropriate context.
            // glDeleteTextures( 1L, (const GLuint *)itr );
            *itr = 0;
        }
    }

    _image = image;
}


void Texture::setWrap(const WrapParameter which, const WrapMode wrap)
{
    switch( which )
    {
        case WRAP_S : _wrap_s = wrap; _texParamtersDirty = true; break;
        case WRAP_T : _wrap_t = wrap; _texParamtersDirty = true; break;
        case WRAP_R : _wrap_r = wrap; _texParamtersDirty = true; break;
        default : notify(WARN)<<"Error: invalid 'which' passed Texture::setWrap("<<(unsigned int)which<<","<<(unsigned int)wrap<<")"<<std::endl; break;
    }
    
}


const Texture::WrapMode Texture::getWrap(const WrapParameter which) const
{
    switch( which )
    {
        case WRAP_S : return _wrap_s;
        case WRAP_T : return _wrap_t;
        case WRAP_R : return _wrap_r;
        default : notify(WARN)<<"Error: invalid 'which' passed Texture::getWrap(which)"<<std::endl; return _wrap_s;
    }
}


void Texture::setFilter(const FilterParameter which, const FilterMode filter)
{
    switch( which )
    {
        case MIN_FILTER : _min_filter = filter; _texParamtersDirty = true; break;
        case MAG_FILTER : _mag_filter = filter; _texParamtersDirty = true; break;
        default : notify(WARN)<<"Error: invalid 'which' passed Texture::setFilter("<<(unsigned int)which<<","<<(unsigned int)filter<<")"<<std::endl; break;
    }
}


const Texture::FilterMode Texture::getFilter(const FilterParameter which) const
{
    switch( which )
    {
        case MIN_FILTER : return _min_filter;
        case MAG_FILTER : return _mag_filter;
        default : notify(WARN)<<"Error: invalid 'which' passed Texture::getFilter(which)"<< std::endl; return _min_filter;
    }
}

/** Force a recompile on next apply() of associated OpenGL texture objects.*/
void Texture::dirtyTextureObject()
{
    for(uint i=0;i<_handleList.size();++i)
    {
        if (_handleList[i] != 0)
        {
            Texture::deleteTextureObject(i,_handleList[i]);
            _handleList[i] = 0;
        }
    }
}

void Texture::apply(State& state) const
{

    // get the contextID (user defined ID of 0 upwards) for the 
    // current OpenGL context.
    const uint contextID = state.getContextID();

    // get the globj for the current contextID.
    GLuint& handle = getHandle(contextID);

    // For multi-texturing will need something like...
    // glActiveTextureARB((GLenum)(GL_TEXTURE0_ARB+_textureUnit));

    if (handle != 0)
    {
        if (_subloadMode == OFF)
        {
            glBindTexture( GL_TEXTURE_2D, handle );
            if (_texParamtersDirty) applyTexParameters(state);
        }
        else  if (_image.valid() && _image->data())
        {
            uint& modifiedTag = getModifiedTag(contextID);

            if (_subloadMode == AUTO ||
                (_subloadMode == IF_DIRTY && modifiedTag != _image->getModifiedTag()))
            {
                glBindTexture( GL_TEXTURE_2D, handle );
                if (_texParamtersDirty) applyTexParameters(state);
                glTexSubImage2D(GL_TEXTURE_2D, 0,
                                _subloadOffsX, _subloadOffsY,
                                _image->s(), _image->t(),
                                (GLenum) _image->pixelFormat(), (GLenum) _image->dataType(),
                                _image->data());
                // update the modified flag to show that the image has been loaded.
                modifiedTag = _image->getModifiedTag();
            }
        }
    }
    else if (_image.valid() && _image->data())
    {

        glGenTextures( 1L, (GLuint *)&handle );
        glBindTexture( GL_TEXTURE_2D, handle );

        applyImmediateMode(state);

        // in theory the following line is redundent, but in practice
        // have found that the first frame drawn doesn't apply the textures
        // unless a second bind is called?!!
        // perhaps it is the first glBind which is not required...
        glBindTexture( GL_TEXTURE_2D, handle );

    }
}

void Texture::compile(State& state) const
{
    apply(state);
}


void Texture::applyTexParameters(State&) const
{
    WrapMode ws = _wrap_s, wt = _wrap_t;

    // GL_IBM_texture_mirrored_repeat, fall-back REPEAT
    static bool s_mirroredSupported = isGLExtensionSupported("GL_IBM_texture_mirrored_repeat");
    if (!s_mirroredSupported)
    {
        if (ws == MIRROR)
            ws = REPEAT;
        if (wt == MIRROR)
            wt = REPEAT;
    }

    // GL_EXT_texture_edge_clamp, fall-back CLAMP
    static bool s_edgeClampSupported = isGLExtensionSupported("GL_EXT_texture_edge_clamp");
    if (!s_edgeClampSupported)
    {
        if (ws == CLAMP_TO_EDGE)
            ws = CLAMP;
        if (wt == CLAMP_TO_EDGE)
            wt = CLAMP;
    }

    static bool s_borderClampSupported = isGLExtensionSupported("GL_ARB_texture_border_clamp");
    if(!s_borderClampSupported)
    {
        if(ws == CLAMP_TO_BORDER)
            ws = CLAMP;
        if(wt == CLAMP_TO_BORDER)
            wt = CLAMP;
    }

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, ws );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wt );

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _min_filter);

    if (s_borderClampSupported)
    {
        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, _borderColor.ptr());
    }

    if (_mag_filter == ANISOTROPIC)
    {
        // check for support for anisotropic filter,
        // note since this is static varible it is intialised
        // only on the first time entering this code block,
        // is then never reevaluated on subsequent calls.
        static bool s_anisotropicSupported =
            isGLExtensionSupported("GL_EXT_texture_filter_anisotropic");

        if (s_anisotropicSupported)
        {
            // note, GL_TEXTURE_MAX_ANISOTROPY_EXT will either be defined
            // by gl.h (or via glext.h) or by include/osg/Texture.
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 2.f);
        }
        else
        {
            glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, LINEAR);
        }
    }
    else
    {
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _mag_filter);
    }

    _texParamtersDirty=false;

}

void Texture::applyImmediateMode(State& state) const
{
    // if we don't have a valid image we can't create a texture!
    if (!_image.valid() || !_image->data())
        return;

    // get the contextID (user defined ID of 0 upwards) for the 
    // current OpenGL context.
    const uint contextID = state.getContextID();

    // update the modified tag to show that it is upto date.
    getModifiedTag(contextID) = _image->getModifiedTag();


    if (_subloadMode == OFF)
        _image->ensureDimensionsArePowerOfTwo();

    glPixelStorei(GL_UNPACK_ALIGNMENT,_image->packing());
    
    applyTexParameters(state);

    static bool s_ARB_Compression = isGLExtensionSupported("GL_ARB_texture_compression");
    static bool s_S3TC_Compression = isGLExtensionSupported("GL_EXT_texture_compression_s3tc");

    // select the internalFormat required for the texture.
    int internalFormat = _image->internalFormat();
    switch(_internalFormatMode)
    {
        case(USE_IMAGE_DATA_FORMAT):
            internalFormat = _image->internalFormat();
            break;

        case(USE_ARB_COMPRESSION):
            if (s_ARB_Compression)
            {
                switch(_image->pixelFormat())
                {
                    case(1): internalFormat = GL_COMPRESSED_ALPHA_ARB; break;
                    case(2): internalFormat = GL_COMPRESSED_LUMINANCE_ALPHA_ARB; break;
                    case(3): internalFormat = GL_COMPRESSED_RGB_ARB; break;
                    case(4): internalFormat = GL_COMPRESSED_RGBA_ARB; break;
                    case(GL_RGB): internalFormat = GL_COMPRESSED_RGB_ARB; break;
                    case(GL_RGBA): internalFormat = GL_COMPRESSED_RGBA_ARB; break;
                    case(GL_ALPHA): internalFormat = GL_COMPRESSED_ALPHA_ARB; break;
                    case(GL_LUMINANCE): internalFormat = GL_COMPRESSED_LUMINANCE_ARB; break;
                    case(GL_LUMINANCE_ALPHA): internalFormat = GL_COMPRESSED_LUMINANCE_ALPHA_ARB; break;
                    case(GL_INTENSITY): internalFormat = GL_COMPRESSED_INTENSITY_ARB; break;
                }
            }
            else internalFormat = _image->internalFormat();
            break;

        case(USE_S3TC_DXT1_COMPRESSION):
            if (s_S3TC_Compression)
            {
                switch(_image->pixelFormat())
                {
                    case(3):        internalFormat = GL_COMPRESSED_RGB_S3TC_DXT1_EXT; break;
                    case(4):        internalFormat = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT; break;
                    case(GL_RGB):   internalFormat = GL_COMPRESSED_RGB_S3TC_DXT1_EXT; break;
                    case(GL_RGBA):  internalFormat = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT; break;
                    default:        internalFormat = _image->internalFormat(); break;
                }
            }
            else internalFormat = _image->internalFormat();
            break;

        case(USE_S3TC_DXT3_COMPRESSION):
            if (s_S3TC_Compression)
            {
                switch(_image->pixelFormat())
                {
                    case(3):
                    case(GL_RGB):   internalFormat = GL_COMPRESSED_RGB_S3TC_DXT1_EXT; break;
                    case(4):
                    case(GL_RGBA):  internalFormat = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT; break;
                    default:        internalFormat = _image->internalFormat(); break;
                }
            }
            else internalFormat = _image->internalFormat();
            break;

        case(USE_S3TC_DXT5_COMPRESSION):
            if (s_S3TC_Compression)
            {
                switch(_image->pixelFormat())
                {
                    case(3):
                    case(GL_RGB):   internalFormat = GL_COMPRESSED_RGB_S3TC_DXT1_EXT; break;
                    case(4):
                    case(GL_RGBA):  internalFormat = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT; break;
                    default:        internalFormat = _image->internalFormat(); break;
                }
            }
            else internalFormat = _image->internalFormat();
            break;

        case(USE_USER_DEFINED_FORMAT):
            internalFormat = _internalFormatValue;
            break;

    }

    if (_subloadMode == OFF) {
        if( _min_filter == LINEAR || _min_filter == NEAREST )
        {
            glTexImage2D( GL_TEXTURE_2D, 0, internalFormat,
                _image->s(), _image->t(), 0,
                (GLenum)_image->pixelFormat(),
                (GLenum)_image->dataType(),
                _image->data() );

            // just estimate estimate it right now..
            // note, ignores texture compression..
            _textureObjectSize = _image->s()*_image->t()*4;

        }
        else
        {

            gluBuild2DMipmaps( GL_TEXTURE_2D, internalFormat,
                _image->s(),_image->t(),
                (GLenum)_image->pixelFormat(), (GLenum)_image->dataType(),
                _image->data() );

            // just estimate size it right now..
            // crude x2 multiplier to account for minmap storage.
            // note, ignores texture compression..
            _textureObjectSize = _image->s()*_image->t()*4;

        }

        _textureWidth = _image->s();
        _textureHeight = _image->t();
    }
    else
    {
        static bool s_SGIS_GenMipmap = isGLExtensionSupported("GL_SGIS_generate_mipmap");

        if (s_SGIS_GenMipmap && (_min_filter != LINEAR && _min_filter != NEAREST)) {
            glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
        }

        // calculate texture dimension
        _textureWidth = 1;
        for (; _textureWidth < (_subloadOffsX + _image->s()); _textureWidth <<= 1)
            ;

        _textureHeight = 1;
        for (; _textureHeight < (_subloadOffsY + _image->t()); _textureHeight <<= 1)
            ;

        // reserve appropriate texture memory
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat,
                     _textureWidth, _textureHeight, 0,
                     (GLenum) _image->pixelFormat(), (GLenum) _image->dataType(),
                     NULL);

        glTexSubImage2D(GL_TEXTURE_2D, 0,
                        _subloadOffsX, _subloadOffsY,
                        _image->s(), _image->t(),
                        (GLenum) _image->pixelFormat(), (GLenum) _image->dataType(),
                        _image->data());
    }
    
}

/** use deleteTextureObject instead of glDeleteTextures to allow
  * OpenGL texture objects to cached until they can be deleted
  * by the OpenGL context in which they were created, specified
  * by contextID.*/
void Texture::deleteTextureObject(uint contextID,GLuint handle)
{
    if (handle!=0)
    {
        // insert the handle into the cache for the appropriate context.
        s_deletedTextureObjectCache[contextID].insert(handle);
    }
}


/** flush all the cached display list which need to be deleted
  * in the OpenGL context related to contextID.*/
void Texture::flushDeletedTextureObjects(uint contextID)
{
    DeletedTextureObjectCache::iterator citr = s_deletedTextureObjectCache.find(contextID);
    if (citr!=s_deletedTextureObjectCache.end())
    {
        std::set<uint>& textureObjectSet = citr->second;
        for(std::set<uint>::iterator titr=textureObjectSet.begin();
                                     titr!=textureObjectSet.end();
                                     ++titr)
        {
            glDeleteTextures( 1L, (const GLuint *)&(*titr ));
        }
        s_deletedTextureObjectCache.erase(citr);
    }
}

void Texture::copyTexImage2D(State& state, int x, int y, int width, int height )
{
    const uint contextID = state.getContextID();

    // get the globj for the current contextID.
    GLuint& handle = getHandle(contextID);
    
    if (handle)
    {
        if (width==(int)_textureWidth && height==(int)_textureHeight)
        {
            // we have a valid texture object which is the right size
            // so lets play clever and use copyTexSubImage2D instead.
            // this allows use to reuse the texture object and avoid
            // expensive memory allocations.
            copyTexSubImage2D(state,0 ,0, x, y, width, height);
            return;
        }
        // the relevent texture object is not of the right size so
        // needs to been deleted    
        // remove previously bound textures. 
        dirtyTextureObject();
        // note, dirtyTextureObject() dirties all the texture objects for
        // this texture, is this right?  Perhaps we should dirty just the
        // one for this context.  Note sure yet will leave till later.
        // RO July 2001.
    }
    
    // For multi-texturing will need something like...
    // glActiveTextureARB((GLenum)(GL_TEXTURE0_ARB+_textureUnit));
    
    // remove any previously assigned images as these are nolonger valid.
    _image = NULL;

    // switch off mip-mapping.
    _min_filter = LINEAR;
    _mag_filter = LINEAR;

    // Get a new 2d texture handle.
    glGenTextures( 1, &handle );

    glBindTexture( GL_TEXTURE_2D, handle );
    applyTexParameters(state);
    glCopyTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, x, y, width, height, 0 );


    /* Redundant, delete later */
//    glBindTexture( GL_TEXTURE_2D, handle );

    _textureWidth = width;
    _textureHeight = height;
    
//    cout<<"copyTexImage2D x="<<x<<"  y="<<y<<"  w="<<width<<"  h="<<height<< std::endl;

    // inform state that this texture is the current one bound.
    state.have_applied(this);
}

void Texture::copyTexSubImage2D(State& state, int xoffset, int yoffset, int x, int y, int width, int height )
{
    const uint contextID = state.getContextID();

    // get the globj for the current contextID.
    GLuint& handle = getHandle(contextID);
    
    if (handle)
    {
        // we have a valid image
        glBindTexture( GL_TEXTURE_2D, handle );
        applyTexParameters(state);
        glCopyTexSubImage2D( GL_TEXTURE_2D, 0, xoffset,yoffset, x, y, width, height);

        /* Redundant, delete later */
        glBindTexture( GL_TEXTURE_2D, handle );

        // inform state that this texture is the current one bound.
        state.have_applied(this);

    }
    else
    {
        // no texture object already exsits for this context so need to
        // create it upfront - simply call copyTexImage2D.
        copyTexImage2D(state,x,y,width,height);
    }
}
