/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-01-25 11:41
 *
 * Note: 
 *
 */
#ifndef DHSERVER_LOG_THREAD_H_
#define DHSERVER_LOG_THREAD_H_

#include "common.h"
#include "log.h"
#include "thread.h"

class LogThread: public Thread {
 public:
  LogThread(LogLevel lv = kError);
  virtual ~LogThread();
  void Routine();

 private:
  LogLevel lv_;
};

#endif /* end of include guard: DHSERVER_LOG_THREAD_H_ */
