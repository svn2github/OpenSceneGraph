/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2006 Robert Osfield
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

#include <osgDB/ObjectCache>

using namespace osgDB;

////////////////////////////////////////////////////////////////////////////////////////////
//
// ObjectCache
//
ObjectCache::ObjectCache():
    osg::Referenced(true)
{
    OSG_NOTICE<<"Constructed ObjectCach"<<std::endl;
}

ObjectCache::~ObjectCache()
{
    OSG_NOTICE<<"Destructed ObjectCach"<<std::endl;
}



void ObjectCache::addEntryToObjectCache(const std::string& filename, osg::Object* object, double timestamp)
{
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_objectCacheMutex);
    _objectCache[filename]=ObjectTimeStampPair(object,timestamp);
}

osg::Object* ObjectCache::getFromObjectCache(const std::string& fileName)
{
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_objectCacheMutex);
    ObjectCacheMap::iterator itr = _objectCache.find(fileName);
    if (itr!=_objectCache.end()) return itr->second.first.get();
    else return 0;
}

osg::ref_ptr<osg::Object> ObjectCache::getRefFromObjectCache(const std::string& fileName)
{
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_objectCacheMutex);
    ObjectCacheMap::iterator itr = _objectCache.find(fileName);
    if (itr!=_objectCache.end()) return itr->second.first;
    else return 0;
}

void ObjectCache::updateTimeStampOfObjectsInCacheWithExternalReferences(double referenceTime)
{
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_objectCacheMutex);

    // look for objects with external references and update their time stamp.
    for(ObjectCacheMap::iterator itr=_objectCache.begin();
        itr!=_objectCache.end();
        ++itr)
    {
        // if ref count is greater the 1 the object has an external reference.
        if (itr->second.first->referenceCount()>1)
        {
            // so update it time stamp.
            itr->second.second = referenceTime;
        }
    }
}

void ObjectCache::removeExpiredObjectsInCache(double expiryTime)
{
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_objectCacheMutex);

    // Remove expired entries from object cache
    ObjectCacheMap::iterator oitr = _objectCache.begin();
    while(oitr != _objectCache.end())
    {
        if (oitr->second.second<=expiryTime)
        {
            _objectCache.erase(oitr++);
        }
        else
        {
            ++oitr;
        }
    }
}

void ObjectCache::removeFromObjectCache(const std::string& fileName)
{
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_objectCacheMutex);
    ObjectCacheMap::iterator itr = _objectCache.find(fileName);
    if (itr!=_objectCache.end()) _objectCache.erase(itr);
}

void ObjectCache::clear()
{
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_objectCacheMutex);
    _objectCache.clear();
}

void ObjectCache::releaseGLObjects(osg::State* state)
{
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_objectCacheMutex);

    for(ObjectCacheMap::iterator itr = _objectCache.begin();
        itr != _objectCache.end();
        ++itr)
    {
        osg::Object* object = itr->second.first.get();
        object->releaseGLObjects(state);
    }
}
