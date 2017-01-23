/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-01-23 11:16
 *
 * Note: 
 *
 */
#ifndef DHSERVER_INTERNAL_LOGMSG_H_
#define DHSERVER_INTERNAL_LOGMSG_H_

#include "common.h"
#include "loglevel.h"

class LogMsg {
 public:
  LogMsg(LogLevel lv, const string &msg) : lv_(lv), msg_(msg) {}
  ~LogMsg() {}
  LogLevel GetLogLv()const { return lv_; }
  const string& GetLogMsg()const { return msg_; }

 private:
  LogLevel lv_;
  string msg_;
};

#endif /* end of include guard: DHSERVER_INTERNAL_LOGMSG_H_ */
