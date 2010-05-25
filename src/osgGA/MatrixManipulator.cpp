#include <osg/GL>
#include <osg/Matrix>
#include <osg/ComputeBoundsVisitor>
#include <osgGA/MatrixManipulator>
#include <string.h>

using namespace osg;
using namespace osgGA;

MatrixManipulator::MatrixManipulator()
{
    _intersectTraversalMask = 0xffffffff;

    _autoComputeHomePosition = true;

    _homeEye.set(0.0,-1.0,0.0);
    _homeCenter.set(0.0,0.0,0.0);
    _homeUp.set(0.0,0.0,1.0);
}


MatrixManipulator::MatrixManipulator(const MatrixManipulator& mm, const CopyOp& copyOp)
   : inherited(mm, copyOp),
     _intersectTraversalMask(mm._intersectTraversalMask),
     _autoComputeHomePosition(mm._autoComputeHomePosition),
     _homeEye(mm._homeEye),
     _homeCenter(mm._homeCenter),
     _homeUp(mm._homeUp),
     _coordinateFrameCallback(dynamic_cast<CoordinateFrameCallback*>(copyOp(mm._coordinateFrameCallback.get())))
{
}


MatrixManipulator::~MatrixManipulator()
{
}


std::string MatrixManipulator::getManipulatorName() const
{
    const char* className = this->className();
    const char* manipString = strstr(className, "Manipulator");
    if (!manipString)
        return std::string(className);
    else
        return std::string(className, manipString-className);
}


bool MatrixManipulator::handle(const GUIEventAdapter&,GUIActionAdapter&)
{
    return false;
}


/** Compute the home position.
 *
 *  The computation considers camera's fov (field of view) and model size and
 *  positions camera far enough to fit the model to the screen.
 *
 *  camera parameter enables computations of camera's fov. If camera is NULL,
 *  scene to camera distance can not be computed and default value is used,
 *  based on model size only.
 *
 *  useBoundingBox parameter enables to use bounding box instead of bounding sphere
 *  for scene bounds. Bounding box provide more precise scene center that may be
 *  important for many applications.*/
void MatrixManipulator::computeHomePosition(const osg::Camera *camera, bool useBoundingBox)
{
    if (getNode())
    {
        osg::BoundingSphere boundingSphere;

        if (useBoundingBox) {

            // compute bounding box
            // (bounding box computes model center more precisely than bounding sphere)
            osg::ComputeBoundsVisitor cbVisitor;
            getNode()->accept(cbVisitor);
            osg::BoundingBox &bb = cbVisitor.getBoundingBox();
            boundingSphere.expandBy(bb);

        }
        else
        {
            // compute bounding sphere
            boundingSphere = getNode()->getBound();
        }

        // set dist to default
        double dist = 3.5f * boundingSphere.radius();

        if (camera) {

            // try to compute dist from frustrum
            double left,right,bottom,top,zNear,zFar;
            if (camera->getProjectionMatrixAsFrustum(left,right,bottom,top,zNear,zFar))
            {
                double vertical2 = fabs(right - left) / zNear / 2.;
                double horizontal2 = fabs(top - bottom) / zNear / 2.;
                double dim = horizontal2 < vertical2 ? horizontal2 : vertical2;
                double viewAngle = atan2(dim,1.);
                dist = boundingSphere.radius() / sin(viewAngle);
            }
            else
                // try to compute dist from ortho
                if (camera->getProjectionMatrixAsOrtho(left,right,bottom,top,zNear,zFar))
                {
                    dist = fabs(zFar - zNear) / 2.;
                }
        }

        // set home position
        setHomePosition(boundingSphere.center() + osg::Vec3d(0.0,-dist,0.0f),
                        boundingSphere.center(),
                        osg::Vec3d(0.0f,0.0f,1.0f),
                        _autoComputeHomePosition);
    }
}
