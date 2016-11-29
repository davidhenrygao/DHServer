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

static void LogCommon(LogLevel lv, const char *format, va_list ap) {
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
