/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-01-11 15:03
 *
 * Note: 
 *
 */

#include "common.h"
#include "logger.h"

Logger::Logger() : init_(false), lq_() {
  init_ = lq_.Init();
}

Logger& Logger::getInstance() {
  static Logger logger;
  return logger;
}

void Logger::Log(LogLevel lv, const string &msg) {
  //std::cout << msg << std::endl;
  size_t sz;
  if (init_) {
    LogMsg *pmsg = new LogMsg(lv, msg);
    sz = lq_.Push(pmsg);
    if (sz == 0) {
      std::cout << "Push message error: message queue overflow!" << std::endl;
    }
  }
}

bool Logger::IsInit()const {
  return init_;
}

LogMsg* Logger::FetchLogMsg() {
  LogMsg* pmsg = NULL;
  lq_.Pop(pmsg);
  return pmsg;
}
