// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osgViewer/CompositeViewer>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgViewer::CompositeViewer)
	I_BaseType(osg::Referenced);
	I_Constructor0(____CompositeViewer,
	               "",
	               "");
	I_Method1(void, addView, IN, osgViewer *, view,
	          __void__addView__osgViewer_P1,
	          "",
	          "");
	I_Method1(osgViewer *, getView, IN, unsigned, i,
	          __osgViewer_P1__getView__unsigned,
	          "",
	          "");
	I_Method1(const osgViewer *, getView, IN, unsigned, i,
	          __C5_osgViewer_P1__getView__unsigned,
	          "",
	          "");
	I_Method0(void, getNumViews,
	          __void__getNumViews,
	          "",
	          "");
	I_Method0(void, frame,
	          __void__frame,
	          "Render a complete new frame. ",
	          "Calls frameAdvance(), frameEventTraversal(), frameUpateTraversal(), frameCullTraversal() and frameDrawTraversal(). Note, no internal makeCurrent() is issued before, or swap buffers called after frame(), these operations are the responsibility of the calling code. ");
	I_Method0(void, frameAdvance,
	          __void__frameAdvance,
	          "",
	          "");
	I_Method0(void, frameEventTraversal,
	          __void__frameEventTraversal,
	          "",
	          "");
	I_Method0(void, frameUpdateTraversal,
	          __void__frameUpdateTraversal,
	          "",
	          "");
	I_Method0(void, frameCullTraversal,
	          __void__frameCullTraversal,
	          "",
	          "");
	I_Method0(void, frameDrawTraversal,
	          __void__frameDrawTraversal,
	          "",
	          "");
	I_Method0(void, releaseAllGLObjects,
	          __void__releaseAllGLObjects,
	          "Release all OpenGL objects associated with this viewer's scenegraph. ",
	          "Note, does not deleted the actual OpenGL objects, it just releases them to the pending GL object delete lists which will need flushing once a valid graphics context is obtained. ");
	I_Method0(void, cleanup,
	          __void__cleanup,
	          "Clean up all OpenGL objects associated with this viewer's scenegraph. ",
	          "Note, must only be called from the graphics context associated with this viewer. ");
	I_Method0(void, init,
	          __void__init,
	          "",
	          "");
	I_ArrayProperty(osgViewer *, View, 
	                __osgViewer_P1__getView__unsigned, 
	                0, 
	                __void__getNumViews, 
	                __void__addView__osgViewer_P1, 
	                0, 
	                0);
END_REFLECTOR

