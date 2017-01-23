/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-28 10:41
 *
 * Note: 
 *
 */
#ifndef DHSERVER_INTERNAL_LOGGER_H_
#define DHSERVER_INTERNAL_LOGGER_H_

#include "common.h"
#include "lockqueue.h"
#include "loglevel.h"
#include "logmsg.h"

//Singleton use a function's local static object variable.
//Note: not thread safe. 
//You should use getInstance in the main thread first.
class Logger {
 public:
  static Logger& getInstance();
  void Log(LogLevel lv, const string &msg);
  bool IsInit()const;
  LogMsg* FetchLogMsg();

 private:
  bool init_;
  LockQueue<LogMsg*> lq_;

  Logger();
  Logger(const Logger&);
  Logger& operator=(const Logger&);
};

#endif /* end of include guard: DHSERVER_INTERNAL_LOGGER_H_ */
