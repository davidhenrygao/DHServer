/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-04-12 10:40
 *
 * Note: 
 *
 */
#include <unistd.h>

#include "common.h"
#include "logger.h"

int Daemonize(const char* root_dir) {
  int ret = daemon(1, 0);
  if (ret == 0) {
    if (root_dir != NULL) {
      ret = chdir(root_dir);
      if (ret != 0) {
        LOG_ERROR("Server daemonize chdir error: %s\n", 
            StrError(errno).c_str());
        return ret;
      }
    }
    Logger &l = Logger::getInstance();
    l.SetDaemonize();
  } else {
    LOG_ERROR("Server daemonize error: %s.\n", StrError(errno).c_str());
  }
  return ret;
}
