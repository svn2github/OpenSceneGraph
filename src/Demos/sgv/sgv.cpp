#ifdef USE_MEM_CHECK
#include <mcheck.h>
#endif

#include <osg/Group>
#include <osg/Notify>

#include <osgDB/Registry>
#include <osgDB/ReadFile>

#include <osgUtil/TrackballManipulator>
#include <osgUtil/FlightManipulator>
#include <osgUtil/DriveManipulator>

#include <GL/glut.h>
#include <osgGLUT/Viewer>

#include <osg/Quat>

/*
 * Function to read several files (typically one) as specified on the command
 * line, and return them in an osg::Node
 */
osg::Node* getNodeFromFiles(int argc,char **argv)
{
    osg::Node *rootnode = new osg::Node;

    int i;

    typedef std::vector<osg::Node*> NodeList;
    NodeList nodeList;
    for( i = 1; i < argc; i++ )
    {

        if (argv[i][0]=='-')
        {
            switch(argv[i][1])
            {
                case('l'):
                    ++i;
                    if (i<argc)
                    {
                        osgDB::Registry::instance()->loadLibrary(argv[i]);
                    }
                    break;
                case('e'):
                    ++i;
                    if (i<argc)
                    {
                        std::string libName = osgDB::Registry::instance()->createLibraryNameForExt(argv[i]);
                        osgDB::Registry::instance()->loadLibrary(libName);
                    }
                    break;
            }
        } else
        {
            osg::Node *node = osgDB::readNodeFile( argv[i] );

            if( node != (osg::Node *)0L )
            {
                if (node->getName().empty()) node->setName( argv[i] );
                nodeList.push_back(node);
            }
        }

    }

    if (nodeList.size()==0)
    {
        osg::notify(osg::WARN) << "No data loaded."<<endl;
        exit(0);
    }

    if (nodeList.size()==1)
    {
        rootnode = nodeList.front();
    }
    else                         // size >1
    {
        osg::Group* group = new osg::Group();
        for(NodeList::iterator itr=nodeList.begin();
            itr!=nodeList.end();
            ++itr)
        {
            group->addChild(*itr);
        }

        rootnode = group;
    }

    return rootnode;
}


int main( int argc, char **argv )
{

#ifdef USE_MEM_CHECK
    mtrace();
#endif

    // initialize the GLUT
    glutInit( &argc, argv );

    if (argc<2)
    {
        osg::notify(osg::NOTICE)<<"usage:"<<endl;
        osg::notify(osg::NOTICE)<<"    sgv [options] infile1 [infile2 ...]"<<endl;
        osg::notify(osg::NOTICE)<<endl;
        osg::notify(osg::NOTICE)<<"options:"<<endl;
        osg::notify(osg::NOTICE)<<"    -l libraryName     - load plugin of name libraryName"<<endl;
        osg::notify(osg::NOTICE)<<"                         i.e. -l osgdb_pfb"<<endl;
        osg::notify(osg::NOTICE)<<"                         Useful for loading reader/writers which can load"<<endl;
        osg::notify(osg::NOTICE)<<"                         other file formats in addition to its extension."<<endl;
        osg::notify(osg::NOTICE)<<"    -e extensionName   - load reader/wrter plugin for file extension"<<endl;
        osg::notify(osg::NOTICE)<<"                         i.e. -e pfb"<<endl;
        osg::notify(osg::NOTICE)<<"                         Useful short hand for specifying full library name as"<<endl;
        osg::notify(osg::NOTICE)<<"                         done with -l above, as it automatically expands to the"<<endl;
        osg::notify(osg::NOTICE)<<"                         full library name appropriate for each platform."<<endl;
        osg::notify(osg::NOTICE)<<endl;

        return 0;
    }

    osg::Timer timer;
    osg::Timer_t before_load = timer.tick();
    
    osg::Node* rootnode = getNodeFromFiles( argc, argv);
    
    osg::Timer_t after_load = timer.tick();
    cout << "Time for load = "<<timer.delta_s(before_load,after_load)<<" seconds"<<endl;

    // initialize the viewer.
    osgGLUT::Viewer viewer;
    viewer.addViewport( rootnode );

    // register trackball, flight and drive.
    viewer.registerCameraManipulator(new osgUtil::TrackballManipulator);
    viewer.registerCameraManipulator(new osgUtil::FlightManipulator);
    viewer.registerCameraManipulator(new osgUtil::DriveManipulator);

    viewer.open();
    viewer.run();

    return 0;
}
