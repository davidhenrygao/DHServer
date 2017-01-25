/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-01-24 10:29
 *
 * Note: 
 *
 */
#ifndef DHSERVER_THREAD_DEF_H_
#define DHSERVER_THREAD_DEF_H_

enum ThreadState { 
  kUninit = 0,
  kInit,
  kStart,
  kExit,
};

#include <pthread.h>
typedef pthread_t Tid;
typedef pthread_attr_t Tattr;
typedef void* (RoutineAdaptor)(void*);

#endif /* end of include guard: DHSERVER_THREAD_DEF_H_ */
