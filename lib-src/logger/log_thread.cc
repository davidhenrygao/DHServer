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
#include "file.h"
#include "configuration.h"
#include "time_manager.h"

#include <unistd.h>

extern ConfigurationInterface* g_psysconfig;

LogThread::LogThread(LogLevel lv) : lv_(lv) {
  
}

LogThread::~LogThread() {
  
}

void LogThread::Routine() {
  File f;
  string log_dir;
  string server_name = "DHServer";
  g_psysconfig->Get("log_dir", log_dir);
  //g_psysconfig->Get("server_name", server_name);
  time_t cur_time = TimeManager::CurTime();
  string timestring = TimeManager::FormatTimeString(
                          cur_time, "_%Y_%m_%d");
  string filename = log_dir + server_name + timestring + ".log";
  bool bopen = f.Open(filename, "a+");
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
      if (bopen) {
        f.WriteString(pmsg->GetLogMsg());
      } else {
        std::cout << pmsg->GetLogMsg() << std::endl;
      }
    }
    delete pmsg;
  }
  return;
}
