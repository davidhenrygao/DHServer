/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-29 17:25
 *
 * Note: 
 *
 */

#include <cstdio>
#include <cstdarg>

#include "logger.h"
#include "log.h"
#include "time_manager.h"


//prefix string format is '[YYYY-MM-DD HH:MM:SS] [LogLevel]'
static const ssize_t kPrefixStrLen = 64;

static string GetPrefixString(LogLevel lv) {
  char prefix_buf[kPrefixStrLen] = {'\0'};
  time_t cur_time = TimeManager::CurTime();
  string timestring = TimeManager::FormatTimeString(
                          cur_time, "%Y-%m-%d %H:%M:%S");
  string level_str;
  switch (lv) {
    case kFatal:
      level_str = "Fatal";
      break;
    case kError:
      level_str = "Error";
      break;
    case kWarning:
      level_str = "Warning";
      break;
    case kInfo:
      level_str = "Info";
      break;
    case kDebug:
      level_str = "Debug";
      break;
    default:
      level_str = "Unknown";
      break;
  }
  snprintf(prefix_buf, kPrefixStrLen, "[%s] [%s]", 
      timestring.c_str(), level_str.c_str());
  return string(prefix_buf);
}

static void LogCommon(LogLevel lv, const char *format, va_list ap) {
  //extra char for '\n'.
  char msg_buf[MAX_MSG_LEN+1] = {'\0'};
  Logger &logger = Logger::getInstance();

  string prefix_str = GetPrefixString(lv);
  snprintf(msg_buf, MAX_MSG_LEN, "%s ", prefix_str.c_str());
  string::size_type prefix_str_len = prefix_str.length();
  size_t left_len = MAX_MSG_LEN - prefix_str_len - 1;
  char *pbuf_pos = msg_buf + prefix_str_len + 1;
  int ret = vsnprintf(pbuf_pos, left_len, format, ap);
  if (ret < 0 || (size_t)ret >= left_len) {
    logger.Log(kError, prefix_str + string(" Log message body is truncated!\n"));
  }

  size_t len = strlen(msg_buf);
  msg_buf[len] = '\n';
  msg_buf[len+1] = '\0';
  logger.Log(lv, string(msg_buf));
}

void LogFatal(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  LogCommon(kFatal, format, ap);
  va_end(ap);
}
void LogError(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  LogCommon(kError, format, ap);
  va_end(ap);
}
void LogWarning(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  LogCommon(kWarning, format, ap);
  va_end(ap);
}
void LogInfo(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  LogCommon(kInfo, format, ap);
  va_end(ap);
}
void LogDebug(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  LogCommon(kDebug, format, ap);
  va_end(ap);
}
