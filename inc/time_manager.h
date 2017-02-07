/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-02-07 19:32
 *
 * Note: 
 *
 */
#ifndef DHSERVER_TIME_MANAGER_H_
#define DHSERVER_TIME_MANAGER_H_

#include "common.h"
#include <ctime>

#define MAX_TIME_STRING_LEN 128

class TimeManager {
 public:
  static time_t CurTime();
  //Please look 'man 3 strftime' for format details.
  //The max time string is MAX_TIME_STRING_LEN.
  static string FormatTimeString(time_t &t, const char *format);

 private:
};

#endif /* end of include guard: DHSERVER_TIME_MANAGER_H_ */
