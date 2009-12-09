/*  -*-c++-*- 
 *  Copyright (C) 2008 Cedric Pinson <cedric.pinson@plopbyte.net>
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
 *
 * Authors:
 *         Cedric Pinson <cedric.pinson@plopbyte.net>
 *         Michael Platings <mplatings@pixelpower.com>
 */

#include <osgAnimation/UpdateCallback>
#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osg/Math>

using namespace osgAnimation;


UpdateTransform::UpdateTransform(const UpdateTransform& apc,const osg::CopyOp& copyop) 
    : osg::Object(apc, copyop),
      AnimationUpdateCallback<osg::NodeCallback>(apc, copyop)
{
    _euler = new osgAnimation::Vec3Target(apc._euler->getValue());
    _position = new osgAnimation::Vec3Target(apc._position->getValue());
    _scale = new osgAnimation::Vec3Target(apc._scale->getValue());
}

UpdateTransform::UpdateTransform(const std::string& name):
    AnimationUpdateCallback<osg::NodeCallback>(name)
{
    _euler = new osgAnimation::Vec3Target;
    _position = new osgAnimation::Vec3Target;
    _scale = new osgAnimation::Vec3Target(osg::Vec3(1,1,1));
}

/** Callback method called by the NodeVisitor when visiting a node.*/
void UpdateTransform::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
    if (nv && nv->getVisitorType() == osg::NodeVisitor::UPDATE_VISITOR) 
    {
        osg::MatrixTransform* matrix = dynamic_cast<osg::MatrixTransform*>(node);
        if (matrix) 
        {
            update(*matrix);
        }
        else 
        {
            osg::PositionAttitudeTransform* pat = dynamic_cast<osg::PositionAttitudeTransform*>(node);
            if (pat)
                update(*pat);
        }
    }
    traverse(node,nv);
}

void UpdateTransform::update(osg::MatrixTransform& mat) 
{
    float z = _euler->getValue()[2];
    float x = _euler->getValue()[0];
    float y = _euler->getValue()[1];
    osg::Matrix m = 
        osg::Matrix::rotate(x,1.0,0.0,0.0) * 
        osg::Matrix::rotate(y,0.0,1.0,0.0) *
        osg::Matrix::rotate(z,0.0,0.0,1.0);
    m = osg::Matrix::scale(_scale->getValue()) * m * osg::Matrix::translate(_position->getValue());
    mat.setMatrix(m);

    if (!m.valid())
        osg::notify(osg::WARN) << this << " UpdateTransform::update detected NaN" << std::endl;
}

void UpdateTransform::update(osg::PositionAttitudeTransform& pat) 
{
    float heading = _euler->getValue()[0];
    float pitch = _euler->getValue()[1];
    float roll = _euler->getValue()[2];
    osg::Matrix m = osg::Matrix::rotate(roll,0.0,1.0,0.0) * osg::Matrix::rotate(pitch,1.0,0.0,0.0) * osg::Matrix::rotate(-heading,0.0,0.0,1.0);
    osg::Quat q = m.getRotate();

    pat.setPosition(_position->getValue());
    pat.setScale(_scale->getValue());
    pat.setAttitude(q);
    pat.dirtyBound();
}

bool UpdateTransform::link(osgAnimation::Channel* channel)
{
    if (channel->getName().find("euler") != std::string::npos) 
    {
        return channel->setTarget(_euler.get());
    }
    else if (channel->getName().find("position") != std::string::npos) 
    {
        return channel->setTarget(_position.get());
    }
    else if (channel->getName().find("scale") != std::string::npos) 
    {
        return channel->setTarget(_scale.get());
    } 
    else 
    {
        osg::notify(osg::WARN) << "Channel " << channel->getName() << " does not contain a valid symbolic name for this class" << className() << std::endl;
    }
    return false;
}





UpdateMaterial::UpdateMaterial(const UpdateMaterial& apc,const osg::CopyOp& copyop) 
    : osg::Object(apc, copyop),
      AnimationUpdateCallback<osg::StateAttributeCallback>(apc, copyop)
{
    _diffuse = new osgAnimation::Vec4Target(apc._diffuse->getValue());
}

UpdateMaterial::UpdateMaterial(const std::string& name):
    AnimationUpdateCallback<osg::StateAttributeCallback>(name)
{
    _diffuse = new osgAnimation::Vec4Target(osg::Vec4(1,0,1,1));
}

/** Callback method called by the NodeVisitor when visiting a node.*/
void UpdateMaterial::operator()(osg::StateAttribute* sa, osg::NodeVisitor* nv)
{
    if (nv && nv->getVisitorType() == osg::NodeVisitor::UPDATE_VISITOR)
    {
        osg::Material* material = dynamic_cast<osg::Material*>(sa);
        if (material)
            update(*material);
    }
}


osgAnimation::Vec4Target* UpdateMaterial::getDiffuse() { return _diffuse.get(); }
void UpdateMaterial::update(osg::Material& material) 
{
    osg::Vec4 diffuse = _diffuse->getValue();
    material.setDiffuse(osg::Material::FRONT_AND_BACK, diffuse);
}

bool UpdateMaterial::link(osgAnimation::Channel* channel)
{
    if (channel->getName().find("diffuse") != std::string::npos)
    {
        return channel->setTarget(_diffuse.get());
    }
    else 
    {
        osg::notify(osg::WARN) << "Channel " << channel->getName() << " does not contain a valid symbolic name for this class " << className() << std::endl;
    }
    return false;
}
