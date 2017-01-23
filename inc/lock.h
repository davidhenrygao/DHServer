/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-12-14 16:43
 *
 * Note: 
 *
 */
#ifndef DHSERVER_LOCK_H_
#define DHSERVER_LOCK_H_

#include <pthread.h>

class Mutex {
 public:
  Mutex();
  ~Mutex();
  bool Init();
  bool Lock();
  bool TryLock();
  bool UnLock();

 private:
  pthread_mutex_t lock_;
};

#endif /* end of include guard: DHSERVER_LOCK_H_ */
