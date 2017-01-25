/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-29 16:55
 *
 * Note: 
 *
 */

#ifndef DHSERVER_LOG_H_
#define DHSERVER_LOG_H_

enum LogLevel { 
  kFatal,
  kError,
  kWarning,
  kInfo,
  kDebug,
};

//Max Message body's length
#define MAX_MSG_LEN 128

//Formatting details are in man page("man 3 printf").
//These functions use vsnprintf c function to get a format string.
//And put the log string into the logger queue.
void LogFatal(const char *format, ...);
void LogError(const char *format, ...);
void LogWarning(const char *format, ...);
void LogInfo(const char *format, ...);
void LogDebug(const char *format, ...);

//Thess macros give more readable profit.
#define LOG_FATAL(fmt, ...) LogFatal(fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) LogError(fmt, ##__VA_ARGS__)
#define LOG_WARNING(fmt, ...) LogWarning(fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...) LogInfo(fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...) LogDebug(fmt, ##__VA_ARGS__)

//If you use gcc, you can alse define the macro as below
//#define LOG_FATAL(fmt, args...) LogFatal(fmt, ##args)

#endif /* end of include guard: DHSERVER_LOG_H_ */
