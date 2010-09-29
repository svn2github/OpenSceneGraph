#include <osgText/Text3D>
#include <osgDB/ObjectWrapper>
#include <osgDB/InputStream>
#include <osgDB/OutputStream>

REGISTER_OBJECT_WRAPPER( osgText_Text3D,
                         new osgText::Text3D,
                         osgText::Text3D,
                         "osg::Object osg::Drawable osgText::TextBase osgText::Text3D" )
{
    ADD_FLOAT_SERIALIZER( CharacterDepth, 1.0f );  // _characterDepth

    BEGIN_ENUM_SERIALIZER( RenderMode, PER_GLYPH );
        ADD_ENUM_VALUE( PER_FACE );
        ADD_ENUM_VALUE( PER_GLYPH );
    END_ENUM_SERIALIZER();  // _renderMode
}
