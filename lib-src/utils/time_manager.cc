/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-02-07 19:40
 *
 * Note: 
 *
 */

#include "time_manager.h"

time_t TimeManager::CurTime() {
  return time(NULL);
}

string TimeManager::FormatTimeString(time_t &t, const char *format) {
  string ts;
  struct tm timeinfo;
  localtime_r(&t, &timeinfo);
  char time_buf[MAX_TIME_STRING_LEN] = {'\0'};
  size_t len = strftime(time_buf, MAX_TIME_STRING_LEN, format, &timeinfo);
  if (len == 0) {
    LOG_ERROR("Format time string is exceed max length!");
  } else {
    ts = time_buf;
  }
  return ts;
}
