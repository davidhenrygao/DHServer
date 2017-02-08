/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-02-08 16:17
 *
 * Note: 
 *
 */
#ifndef DHSERVER_WORKER_THREAD_H_
#define DHSERVER_WORKER_THREAD_H_

#include "thread.h"

class WorkerThread: public Thread {
 public:
  WorkerThread(const string &name);
  virtual ~WorkerThread();
  void Routine();

 private:
  string name_;
};


#endif /* end of include guard: DHSERVER_WORKER_THREAD_H_ */
