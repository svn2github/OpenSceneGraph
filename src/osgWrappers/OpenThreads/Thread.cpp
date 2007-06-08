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

#include <OpenThreads/Thread>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(OpenThreads::Thread::ThreadPriority)
	I_DeclaringFile("OpenThreads/Thread");
	I_EnumLabel(OpenThreads::Thread::THREAD_PRIORITY_MAX);
	I_EnumLabel(OpenThreads::Thread::THREAD_PRIORITY_HIGH);
	I_EnumLabel(OpenThreads::Thread::THREAD_PRIORITY_NOMINAL);
	I_EnumLabel(OpenThreads::Thread::THREAD_PRIORITY_LOW);
	I_EnumLabel(OpenThreads::Thread::THREAD_PRIORITY_MIN);
	I_EnumLabel(OpenThreads::Thread::THREAD_PRIORITY_DEFAULT);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(OpenThreads::Thread::ThreadPolicy)
	I_DeclaringFile("OpenThreads/Thread");
	I_EnumLabel(OpenThreads::Thread::THREAD_SCHEDULE_FIFO);
	I_EnumLabel(OpenThreads::Thread::THREAD_SCHEDULE_ROUND_ROBIN);
	I_EnumLabel(OpenThreads::Thread::THREAD_SCHEDULE_TIME_SHARE);
	I_EnumLabel(OpenThreads::Thread::THREAD_SCHEDULE_DEFAULT);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(OpenThreads::Thread)
	I_DeclaringFile("OpenThreads/Thread");
	I_Constructor0(____Thread,
	               "Constructor. ",
	               "");
	I_Method0(int, getThreadId,
	          Properties::NON_VIRTUAL,
	          __int__getThreadId,
	          "Get a unique thread id. ",
	          "This id is monotonically increasing.a unique thread identifier ");
	I_Method0(size_t, getProcessId,
	          Properties::NON_VIRTUAL,
	          __size_t__getProcessId,
	          "Get the thread's process id. ",
	          "This is the pthread_t or pid_t value depending on the threading model being used.thread process id. ");
	I_Method0(int, start,
	          Properties::NON_VIRTUAL,
	          __int__start,
	          "Start the thread. ",
	          "This method will configure the thread, set it's priority, and spawn it.if the stack size specified setStackSize is smaller than the smallest allowable stack size, the threads stack size will be set to the minimum allowed, and may be retrieved via the getStackSize() 0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(int, startThread,
	          Properties::NON_VIRTUAL,
	          __int__startThread,
	          "",
	          "");
	I_Method0(int, testCancel,
	          Properties::NON_VIRTUAL,
	          __int__testCancel,
	          "Test the cancel state of the thread. ",
	          "If the thread has been canceled this method will cause the thread to exit now. This method operates on the calling thread.Returns 0 if normal, -1 if called from a thread other that this.");
	I_Method0(int, cancel,
	          Properties::VIRTUAL,
	          __int__cancel,
	          "Cancel the thread. ",
	          "Equivalent to SIGKILL.0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method1(int, setSchedulePriority, IN, OpenThreads::Thread::ThreadPriority, priority,
	          Properties::NON_VIRTUAL,
	          __int__setSchedulePriority__ThreadPriority,
	          "Set the thread's schedule priority. ",
	          "This is a complex method. Beware of thread priorities when using a many-to-many kernel entity implemenation (such as IRIX pthreads). If one is not carefull to manage the thread priorities, a priority inversion deadlock can easily occur (Although the OpenThreads::Mutex & OpenThreads::Barrier constructs have been designed with this senario in mind). Unless you have explicit need to set the schedule pirorites for a given task, it is best to leave them alone.some implementations (notably LinuxThreads and IRIX Sprocs) only alow you to decrease thread priorities dynamically. Thus, a lower priority thread will not allow it's priority to be raised on the fly.seting the environment variable OUTPUT_THREADLIB_SCHEDULING_INFO will output scheduling information for each thread to stdout. 0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(int, getSchedulePriority,
	          Properties::NON_VIRTUAL,
	          __int__getSchedulePriority,
	          "Get the thread's schedule priority (if able). ",
	          "seting the environment variable OUTPUT_THREADLIB_SCHEDULING_INFO will output scheduling information for each thread to stdout. 0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method1(int, setSchedulePolicy, IN, OpenThreads::Thread::ThreadPolicy, policy,
	          Properties::NON_VIRTUAL,
	          __int__setSchedulePolicy__ThreadPolicy,
	          "Set the thread's scheduling policy (if able). ",
	          "On some implementations (notably IRIX Sprocs & LinuxThreads) The policy may prohibit the use of SCHEDULE_ROUND_ROBIN and SCHEDULE_FIFO policies - due to their real-time nature, and the danger of deadlocking the machine when used as super-user. In such cases, the command is a no-op.seting the environment variable OUTPUT_THREADLIB_SCHEDULING_INFO will output scheduling information for each thread to stdout. 0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(int, getSchedulePolicy,
	          Properties::NON_VIRTUAL,
	          __int__getSchedulePolicy,
	          "Get the thread's policy (if able). ",
	          "seting the environment variable OUTPUT_THREADLIB_SCHEDULING_INFO will output scheduling information for each thread to stdout. policy if normal, -1 if errno set, errno code otherwise. ");
	I_Method1(int, setStackSize, IN, size_t, size,
	          Properties::NON_VIRTUAL,
	          __int__setStackSize__size_t,
	          "Set the thread's desired stack size (in bytes). ",
	          "This method is an attribute of the thread and must be called *before* the start() method is invoked.a return code of 13 (EACESS) means that the thread stack size can no longer be changed. 0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(size_t, getStackSize,
	          Properties::NON_VIRTUAL,
	          __size_t__getStackSize,
	          "Get the thread's desired stack size. ",
	          "the thread's stack size. 0 indicates that the stack size has either not yet been initialized, or not yet been specified by the application. ");
	I_Method0(void, printSchedulingInfo,
	          Properties::NON_VIRTUAL,
	          __void__printSchedulingInfo,
	          "Print the thread's scheduling information to stdout. ",
	          "");
	I_Method0(int, detach,
	          Properties::NON_VIRTUAL,
	          __int__detach,
	          "Detach the thread from the calling process. ",
	          "0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(int, join,
	          Properties::NON_VIRTUAL,
	          __int__join,
	          "Join the calling process with the thread. ",
	          "0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(int, setCancelModeDisable,
	          Properties::NON_VIRTUAL,
	          __int__setCancelModeDisable,
	          "Disable thread cancelation altogether. ",
	          "Thread::cancel() has no effect.0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(int, setCancelModeAsynchronous,
	          Properties::NON_VIRTUAL,
	          __int__setCancelModeAsynchronous,
	          "Mark the thread to cancel aysncronously on Thread::cancel(). ",
	          "(May not be available with process-level implementations).0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(int, setCancelModeDeferred,
	          Properties::NON_VIRTUAL,
	          __int__setCancelModeDeferred,
	          "Mark the thread to cancel at the earliest convenience on Thread::cancel() (This is the default). ",
	          "0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(bool, isRunning,
	          Properties::NON_VIRTUAL,
	          __bool__isRunning,
	          "Query the thread's running status. ",
	          "true if running, false if not. ");
	I_Method0(void, run,
	          Properties::PURE_VIRTUAL,
	          __void__run,
	          "Thread's run method. ",
	          "Must be implemented by derived classes. This is where the action happens.");
	I_Method0(void, cancelCleanup,
	          Properties::VIRTUAL,
	          __void__cancelCleanup,
	          "Thread's cancel cleanup routine, called upon cancel(), after the cancelation has taken place, but before the thread exits completely. ",
	          "This method should be used to repair parts of the thread's data that may have been damaged by a pre-mature cancel. No-op by default.");
	I_Method0(void *, getImplementation,
	          Properties::NON_VIRTUAL,
	          __void_P1__getImplementation,
	          "",
	          "");
	I_Method1(int, setProcessorAffinity, IN, unsigned int, cpunum,
	          Properties::NON_VIRTUAL,
	          __int__setProcessorAffinity__unsigned_int,
	          "Thread's processor affinity method. ",
	          "This binds a thread to a processor whenever possible. This call must be made before start() or startThread() and has no effect after the thread has been running. In the pthreads implementation, this is only implemented on sgi, through a pthread extension. On other pthread platforms this is ignored. Returns 0 on success, implementation's error on failure, or -1 if ignored.");
	I_StaticMethod1(int, SetConcurrency, IN, int, concurrencyLevel,
	                __int__SetConcurrency__int_S,
	                "Set the concurrency level for a running application. ",
	                "This method only has effect if the pthreads thread model is being used, and then only when that model is many-to-one (eg. irix). in other cases it is ignored. The concurrency level is only a *hint* as to the number of execution vehicles to use, the actual implementation may do anything it wants. Setting the value to 0 returns things to their default state.previous concurrency level, -1 indicates no-op. ");
	I_StaticMethod0(int, GetConcurrency,
	                __int__GetConcurrency_S,
	                "Get the concurrency level for a running application. ",
	                "In this case, a return code of 0 means that the application is in default mode. A return code of -1 means that the application is incapable of setting an arbitrary concurrency, because it is a one-to-one execution model (sprocs, linuxThreads)");
	I_StaticMethod0(OpenThreads::Thread *, CurrentThread,
	                __Thread_P1__CurrentThread_S,
	                "Return a pointer to the current running thread. ",
	                "");
	I_StaticMethod0(void, Init,
	                __void__Init_S,
	                "Initialize Threading in a program. ",
	                "This method must be called before you can do any threading in a program.");
	I_StaticMethod0(int, YieldCurrentThread,
	                __int__YieldCurrentThread_S,
	                "Yield the processor. ",
	                "This method operates on the calling process. And is equivalent to calling sched_yield(). 0 if normal, -1 if errno set, errno code otherwise. ");
	I_StaticMethod0(OpenThreads::Thread::ThreadPriority, GetMasterPriority,
	                __ThreadPriority__GetMasterPriority_S,
	                "This method will return the ThreadPriority of the master process. ",
	                "(ie, the one calling the thread->start() methods for the first time) The method will almost certainly return Thread::THREAD_PRIORITY_DEFAULT if Init() has not been called.the Thread::ThreadPriority of the master thread. ");
	I_StaticMethod1(int, microSleep, IN, unsigned int, microsec,
	                __int__microSleep__unsigned_int_S,
	                "microSleep method, equivilant to the posix usleep(microsec). ",
	                "This is not strictly thread API but is used so often with threads. It's basically UNIX usleep. Parameter is number of microseconds we current thread to sleep. Returns 0 on succes, non-zero on failure (UNIX errno or GetLastError() will give detailed description.");
	I_SimpleProperty(void *, Implementation, 
	                 __void_P1__getImplementation, 
	                 0);
	I_SimpleProperty(size_t, ProcessId, 
	                 __size_t__getProcessId, 
	                 0);
	I_SimpleProperty(unsigned int, ProcessorAffinity, 
	                 0, 
	                 __int__setProcessorAffinity__unsigned_int);
	I_SimpleProperty(OpenThreads::Thread::ThreadPolicy, SchedulePolicy, 
	                 0, 
	                 __int__setSchedulePolicy__ThreadPolicy);
	I_SimpleProperty(OpenThreads::Thread::ThreadPriority, SchedulePriority, 
	                 0, 
	                 __int__setSchedulePriority__ThreadPriority);
	I_SimpleProperty(size_t, StackSize, 
	                 __size_t__getStackSize, 
	                 __int__setStackSize__size_t);
	I_SimpleProperty(int, ThreadId, 
	                 __int__getThreadId, 
	                 0);
END_REFLECTOR

