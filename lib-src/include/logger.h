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
#include "common.h"

enum LogLevel { 
  kFatal,
  kError,
  kWarning,
  kInfo,
  kDebug,
};

//Singleton use a function's local static object variable.
class Logger {
 public:
  static Logger& getInstance() {
    static Logger logger;
    return logger;
  }
  void Log(LogLevel lv, string msg);

 private:
};
