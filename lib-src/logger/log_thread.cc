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

#include "common.h"
#include "log_thread.h"
#include "logger.h"

#include <unistd.h>

LogThread::LogThread(LogLevel lv) : lv_(lv) {
  
}

LogThread::~LogThread() {
  
}

void LogThread::Routine() {
  Logger &logger = Logger::getInstance();
  LogMsg *pmsg = NULL;
  for (;;) {
    pmsg = logger.FetchLogMsg();
    if (pmsg == NULL) {
      //std::cout << "No message, sleep 500 us." << std::endl;
      usleep(500);
      continue;
    }
    if (lv_ >= pmsg->GetLogLv()) {
      std::cout << pmsg->GetLogMsg() << std::endl;
    }
    delete pmsg;
  }
  return;
}
