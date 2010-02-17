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
#include <stdlib.h>

#include <osg/Referenced>
#include <osg/Notify>
#include <osg/ApplicationUsage>
#include <osg/observer_ptr>

#include <typeinfo>
#include <memory>
#include <set>

#include <OpenThreads/ScopedLock>
#include <OpenThreads/Mutex>

#include <osg/DeleteHandler>

namespace osg
{

//#define ENFORCE_THREADSAFE
//#define DEBUG_OBJECT_ALLOCATION_DESTRUCTION

// specialized smart pointer, used to get round auto_ptr<>'s lack of the destructor reseting itself to 0.
template<typename T>
struct ResetPointer
{
    ResetPointer():
        _ptr(0) {}

    ResetPointer(T* ptr):
        _ptr(ptr) {}

    ~ResetPointer()
    {
        delete _ptr;
        _ptr = 0;
    }

    inline ResetPointer& operator = (T* ptr)
    {
        if (_ptr==ptr) return *this;
        delete _ptr;
        _ptr = ptr;
        return *this;
    }

    void reset(T* ptr)
    {
        if (_ptr==ptr) return;
        delete _ptr;
        _ptr = ptr;
    }

    inline T& operator*()  { return *_ptr; }

    inline const T& operator*() const { return *_ptr; }

    inline T* operator->() { return _ptr; }

    inline const T* operator->() const   { return _ptr; }

    T* get() { return _ptr; }

    const T* get() const { return _ptr; }

    T* _ptr;
};

typedef ResetPointer<DeleteHandler> DeleteHandlerPointer;
typedef ResetPointer<OpenThreads::Mutex> GlobalMutexPointer;

OpenThreads::Mutex* Referenced::getGlobalReferencedMutex()
{
    static GlobalMutexPointer s_ReferencedGlobalMutext = new OpenThreads::Mutex;
    return s_ReferencedGlobalMutext.get();
}

typedef std::set<Observer*> ObserverSet;

#if defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
struct Referenced::ObserverSetData {
   OpenThreads::Mutex _mutex;
   ObserverSet _observers;
};
#endif

#if !defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
static bool s_useThreadSafeReferenceCounting = getenv("OSG_THREAD_SAFE_REF_UNREF")!=0;
#endif
// static std::auto_ptr<DeleteHandler> s_deleteHandler(0);
static DeleteHandlerPointer s_deleteHandler(0);

static ApplicationUsageProxy Referenced_e0(ApplicationUsage::ENVIRONMENTAL_VARIABLE,"OSG_THREAD_SAFE_REF_UNREF","");

void Referenced::setThreadSafeReferenceCounting(bool enableThreadSafeReferenceCounting)
{
#if !defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
    s_useThreadSafeReferenceCounting = enableThreadSafeReferenceCounting;
#endif
}

bool Referenced::getThreadSafeReferenceCounting()
{
#if defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
    return true;
#else
    return s_useThreadSafeReferenceCounting;
#endif
}


void Referenced::setDeleteHandler(DeleteHandler* handler)
{
    s_deleteHandler.reset(handler);
}

DeleteHandler* Referenced::getDeleteHandler()
{
    return s_deleteHandler.get();
}

#ifdef DEBUG_OBJECT_ALLOCATION_DESTRUCTION
OpenThreads::Mutex& getNumObjectMutex()
{
    static OpenThreads::Mutex s_numObjectMutex;
    return s_numObjectMutex;
}
static int s_numObjects = 0;
#endif

Referenced::Referenced():
#if defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
    _observerSetDataPtr(0),
    _refCount(0)
#else
    _refMutex(0),
    _refCount(0),
    _observers(0)
#endif
{
#if !defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
#ifndef ENFORCE_THREADSAFE
    if (s_useThreadSafeReferenceCounting)
#endif
        _refMutex = new OpenThreads::Mutex;
#endif
        
#ifdef DEBUG_OBJECT_ALLOCATION_DESTRUCTION
    {
        OpenThreads::ScopedLock<OpenThreads::Mutex> lock(getNumObjectMutex());
        ++s_numObjects;
        osg::notify(osg::NOTICE)<<"Object created, total num="<<s_numObjects<<std::endl;
    }
#endif

}

Referenced::Referenced(bool threadSafeRefUnref):
#if defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
    _observerSetDataPtr(0),
    _refCount(0)
#else
    _refMutex(0),
    _refCount(0),
    _observers(0)
#endif
{
#if !defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
#ifndef ENFORCE_THREADSAFE
    if (threadSafeRefUnref)
#endif
        _refMutex = new OpenThreads::Mutex;
#endif

#ifdef DEBUG_OBJECT_ALLOCATION_DESTRUCTION
    {
        OpenThreads::ScopedLock<OpenThreads::Mutex> lock(getNumObjectMutex());
        ++s_numObjects;
        osg::notify(osg::NOTICE)<<"Object created, total num="<<s_numObjects<<std::endl;
    }
#endif
}

Referenced::Referenced(const Referenced&):
#if defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
    _observerSetDataPtr(0),
    _refCount(0)
#else
    _refMutex(0),
    _refCount(0),
    _observers(0)
#endif
{
#if !defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
#ifndef ENFORCE_THREADSAFE
    if (s_useThreadSafeReferenceCounting)
#endif
        _refMutex = new OpenThreads::Mutex;
#endif

#ifdef DEBUG_OBJECT_ALLOCATION_DESTRUCTION
    {
        OpenThreads::ScopedLock<OpenThreads::Mutex> lock(getNumObjectMutex());
        ++s_numObjects;
        osg::notify(osg::NOTICE)<<"Object created, total num="<<s_numObjects<<std::endl;
    }
#endif
}

Referenced::~Referenced()
{
#ifdef DEBUG_OBJECT_ALLOCATION_DESTRUCTION
    {
        OpenThreads::ScopedLock<OpenThreads::Mutex> lock(getNumObjectMutex());
        --s_numObjects;
        osg::notify(osg::NOTICE)<<"Object deleted, total num="<<s_numObjects<<std::endl;
    }
#endif

    if (_refCount>0)
    {
        notify(WARN)<<"Warning: deleting still referenced object "<<this<<" of type '"<<typeid(this).name()<<"'"<<std::endl;
        notify(WARN)<<"         the final reference count was "<<_refCount<<", memory corruption possible."<<std::endl;
    }

    // signal observers that we are being deleted.
    signalObserversAndDelete(false, true, false);
}

void Referenced::signalObserversAndDelete(bool signalUnreferened, bool signalDelete, bool doDelete) const
{
    if (signalUnreferened)
    {
        // tell all observers that we have been unreferenced so that they
        // can do clean up or add their own reference to prevent deletion.
        #if !defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
            ObserverSet* os = static_cast<ObserverSet*>(_observers);
            if (os)
            {
                if (_refMutex)
                {
                    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(*_refMutex);
                    for(ObserverSet::iterator itr = os->begin();
                        itr != os->end();
                        )
                    {
                        if ((*itr)->objectUnreferenced(const_cast<Referenced*>(this)))
                        {
                            ObserverSet::iterator orig_itr = itr;
                            ++itr;
                            os.erase(orig_itr);
                        }
                        else
                        {
                            ++itr;
                        }
                    }
                }
                else
                {
                    for(ObserverSet::iterator itr = os->begin();
                        itr != os->end();
                        )
                    {
                        if ((*itr)->objectUnreferenced(const_cast<Referenced*>(this)))
                        {
                            ObserverSet::iterator orig_itr = itr;
                            ++itr;
                            os.erase(orig_itr);
                        }
                        else
                        {
                            ++itr;
                        }
                    }
                }
            }
        #else
            ObserverSetData* observerSetData = static_cast<ObserverSetData*>(_observerSetDataPtr.get());
            if (observerSetData)
            {
                OpenThreads::ScopedLock<OpenThreads::Mutex> lock(observerSetData->_mutex);
                for(ObserverSet::iterator itr = observerSetData->_observers.begin();
                    itr != observerSetData->_observers.end();
                    )
                {
                    if ((*itr)->objectUnreferenced(const_cast<Referenced*>(this)))
                    {
                        ObserverSet::iterator orig_itr = itr;
                        ++itr;
                        observerSetData->_observers.erase(orig_itr);
                    }
                    else
                    {
                        ++itr;
                    }
                }
            }
        #endif
    }

    if (_refCount!=0) return;

    if (signalDelete)
    {
        // tell all observers that we being delete so that they
        // can do cleans up and remove any references they have.
        #if !defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
            ObserverSet* os = static_cast<ObserverSet*>(_observers);
            if (os)
            {
                for(ObserverSet::iterator itr = os->begin();
                    itr != os->end();
                    ++itr)
                {
                    (*itr)->objectDeleted(const_cast<Referenced*>(this));
                }
                delete os;
                _observers = 0;
            }
        #else
            ObserverSetData* observerSetData = static_cast<ObserverSetData*>(_observerSetDataPtr.get());
            if (observerSetData)
            {
                for(ObserverSet::iterator itr = observerSetData->_observers.begin();
                    itr != observerSetData->_observers.end();
                    ++itr)
                {
                    (*itr)->objectDeleted(const_cast<Referenced*>(this));
                }
                _observerSetDataPtr.assign(0, observerSetData);
                delete observerSetData;
            }
        #endif
    }

    if (doDelete &&_refCount<=0)
    {
        if (getDeleteHandler()) deleteUsingDeleteHandler();
        else delete this;
    }
}


void Referenced::setThreadSafeRefUnref(bool threadSafe)
{
#if !defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
    if (threadSafe)
    {
        if (!_refMutex)
        {
            // we want thread safe ref()/unref() so assign a mutex
            _refMutex = new OpenThreads::Mutex;
        }
    }
    else
    {
        if (_refMutex)
        {
            // we don't want thread safe ref()/unref() so remove any assigned mutex
            OpenThreads::Mutex* tmpMutexPtr = _refMutex;
            _refMutex = 0;
            delete tmpMutexPtr;
        }
    }
#endif
}


void Referenced::unref_nodelete() const
{
#if !defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
    bool needUnreferencedSignal = false;
    if (_refMutex)
    {
        OpenThreads::ScopedLock<OpenThreads::Mutex> lock(*_refMutex); 
        needUnreferencedSignal = (--_refCount)<=0;
    }
    else
    {
        needUnreferencedSignal = (--_refCount)<=0;
    }
#else
    bool needUnreferencedSignal = (--_refCount)<=0;
#endif

    if (needUnreferencedSignal)
    {
        signalObserversAndDelete(true,false,false);
    }
}

void Referenced::addObserver(Observer* observer) const
{
#if defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
    ObserverSetData* observerSetData = static_cast<ObserverSetData*>(_observerSetDataPtr.get());
    while (0 == observerSetData) {
        ObserverSetData* newObserverSetData = new ObserverSetData;
        if (!_observerSetDataPtr.assign(newObserverSetData, 0))
            delete newObserverSetData;
        observerSetData = static_cast<ObserverSetData*>(_observerSetDataPtr.get());
    }
    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(observerSetData->_mutex);
    observerSetData->_observers.insert(observer);
#else
    if (_refMutex)
    {
        OpenThreads::ScopedLock<OpenThreads::Mutex> lock(*_refMutex); 

        if (!_observers) _observers = new ObserverSet;
        if (_observers) static_cast<ObserverSet*>(_observers)->insert(observer);
    }
    else
    {
        if (!_observers) _observers = new ObserverSet;
        if (_observers) static_cast<ObserverSet*>(_observers)->insert(observer);
    }
#endif
}

void Referenced::removeObserver(Observer* observer) const
{
#if defined(_OSG_REFERENCED_USE_ATOMIC_OPERATIONS)
    ObserverSetData* observerSetData = static_cast<ObserverSetData*>(_observerSetDataPtr.get());
    if (observerSetData)
    {
       OpenThreads::ScopedLock<OpenThreads::Mutex> lock(observerSetData->_mutex); 
       observerSetData->_observers.erase(observer);
    }
#else
    if (_refMutex)
    {
        OpenThreads::ScopedLock<OpenThreads::Mutex> lock(*_refMutex); 

        if (_observers) static_cast<ObserverSet*>(_observers)->erase(observer);
    }
    else
    {
        if (_observers) static_cast<ObserverSet*>(_observers)->erase(observer);
    }
#endif
}

void Referenced::deleteUsingDeleteHandler() const
{
    getDeleteHandler()->requestDelete(this);
}

} // end of namespace osg
