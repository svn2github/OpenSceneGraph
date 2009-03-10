/*
 *  DarwinUtils.h
 *  OpenSceneGraph
 *
 *  Created by Stephan Huber on 27.06.08.
 *  Copyright 2008 Stephan Maximilian Huber, digital mind. All rights reserved.
 *
 */

#ifdef __APPLE__
 
#ifndef DARWIN_UTILS_HEADER_
#define DARWIN_UTILS_HEADER_

#include <osg/DeleteHandler>
#include <osg/GraphicsContext>
#include <osgViewer/GraphicsWindow>
#include <Carbon/Carbon.h>


//#define USE_DARWIN_COCOA_IMPLEMENTATION 1
//#define USE_DARWIN_CARBON_IMPLEMENTATION 1

namespace osgDarwin {


/** the MenubarController class checks all open windows if they intersect with the menubar / dock and hide the menubar/dock if necessary */
class MenubarController : public osg::Referenced 
{

    public:
		class WindowAdapter : public osg::Referenced {
			
			public:
				WindowAdapter() : osg::Referenced() {}
				
				virtual bool valid() = 0;
				virtual void getWindowBounds(CGRect& rect) = 0;
				virtual osgViewer::GraphicsWindow* getWindow() = 0;
				
			protected:
				virtual ~WindowAdapter() {}
		};
		
        MenubarController();        
        static MenubarController* instance();
        
        void attachWindow(WindowAdapter* win);
        void update();
        void detachWindow(osgViewer::GraphicsWindow* win);
        
    private: 
        typedef std::list< osg::ref_ptr< WindowAdapter > > WindowList;
        WindowList				_list;
        bool					_menubarShown;
        CGRect					_availRect;
        CGRect					_mainScreenBounds;
        OpenThreads::Mutex		_mutex;
        
};



struct DarwinWindowingSystemInterface : public osg::GraphicsContext::WindowingSystemInterface
{
    public:
		DarwinWindowingSystemInterface();
		
		/** dtor */
		~DarwinWindowingSystemInterface();
		
	/** @return a CGDirectDisplayID for a ScreenIdentifier */
	CGDirectDisplayID getDisplayID(const osg::GraphicsContext::ScreenIdentifier& si);
	
	/** @return count of attached screens */
	virtual unsigned int getNumScreens(const osg::GraphicsContext::ScreenIdentifier& si) ;
	
	virtual void getScreenSettings(const osg::GraphicsContext::ScreenIdentifier& si, osg::GraphicsContext::ScreenSettings & resolution);

	virtual void enumerateScreenSettings(const osg::GraphicsContext::ScreenIdentifier& screenIdentifier, osg::GraphicsContext::ScreenSettingsList & resolutionList);

	/** return the top left coord of a specific screen in global screen space */
	void getScreenTopLeft(const osg::GraphicsContext::ScreenIdentifier& si, int& x, int& y);
	
	/** implementation of setScreenResolution */
	virtual bool setScreenResolution(const osg::GraphicsContext::ScreenIdentifier& screenIdentifier, unsigned int width, unsigned int height) ;

	/** implementation of setScreenRefreshRate */
	virtual bool setScreenRefreshRate(const osg::GraphicsContext::ScreenIdentifier& screenIdentifier, double refreshRate);
	
	
	/** returns screen-ndx containing rect x,y,w,h */
	unsigned int getScreenContaining(int x, int y, int w, int h);
	
	protected:
	
		template<class PixelBufferImplementation, class GraphicsWindowImplementation>
		osg::GraphicsContext* createGraphicsContextImplementation(osg::GraphicsContext::Traits* traits)
		{
			if (traits->pbuffer)
			{
				osg::ref_ptr<PixelBufferImplementation> pbuffer = new PixelBufferImplementation(traits);
				if (pbuffer->valid()) return pbuffer.release();
				else return 0;
			}
			else
			{
				osg::ref_ptr<GraphicsWindowImplementation> window = new GraphicsWindowImplementation(traits);
				if (window->valid()) return window.release();
				else return 0;
			}
		}
	
    
	private:
        CGDisplayCount        _displayCount;
        CGDirectDisplayID*    _displayIds;


};

template <class WSI>
struct RegisterWindowingSystemInterfaceProxy
{
    RegisterWindowingSystemInterfaceProxy()
    {
        osg::GraphicsContext::setWindowingSystemInterface(new WSI);
    }

    ~RegisterWindowingSystemInterfaceProxy()
    {
        if (osg::Referenced::getDeleteHandler())
        {
            osg::Referenced::getDeleteHandler()->setNumFramesToRetainObjects(0);
            osg::Referenced::getDeleteHandler()->flushAll();
        }

        osg::GraphicsContext::setWindowingSystemInterface(0);
    }
};



}

#endif

#endif // __APPLE__