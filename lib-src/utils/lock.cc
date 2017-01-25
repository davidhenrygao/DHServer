/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-01-11 20:11
 *
 * Note: 
 *
 */

#include "common.h"
#include "lock.h"

Mutex::Mutex() {
  
}

Mutex::~Mutex() {
  int ret = pthread_mutex_destroy(&lock_);
  if (ret != 0) {
    if (ret == EBUSY) {
      LOG_FATAL("Destory Failed: The mutex is locked or referenced "
          "by another thread!");
    }
    if (ret == EINVAL) {
      LOG_ERROR("Destory Failed: The value specified by mutex is invalid.");
    }
  }
}

bool Mutex::Init() {
  char err_buf[MAX_ERROR_MSG_LEN];
  pthread_mutexattr_t attr;
  int ret = pthread_mutexattr_init(&attr);
  if (ret != 0) {
    LOG_ERROR("pthread_mutexattr_init error: %s!", 
        strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN));
    return false;
  }
  ret = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
  if (ret != 0) {
    LOG_ERROR("pthread_mutexattr_settype error: %s!", 
        strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN));
    return false;
  }
  ret = pthread_mutex_init(&lock_, &attr);
  if (ret != 0) {
    LOG_ERROR("pthread_mutex_init error: %s!", 
        strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN));
    return false;
  }
  return true;
}

bool Mutex::Lock() {
  char err_buf[MAX_ERROR_MSG_LEN];
  int ret = pthread_mutex_lock(&lock_);
  if (ret != 0) {
    LOG_ERROR("pthread_mutexattr_lock error: %s!", 
        strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN));
    return false;
  }
  return true;
}

bool Mutex::UnLock() {
  char err_buf[MAX_ERROR_MSG_LEN];
  int ret = pthread_mutex_unlock(&lock_);
  if (ret != 0) {
    LOG_ERROR("pthread_mutexattr_unlock error: %s!", 
        strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN));
    return false;
  }
  return true;
}

bool Mutex::TryLock() {
  char err_buf[MAX_ERROR_MSG_LEN];
  int ret = pthread_mutex_trylock(&lock_);
  if (ret != 0) {
    if (ret != EBUSY) {
      LOG_ERROR("pthread_mutexattr_trylock error: %s!", 
          strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN));
    }
    return false;
  }
  return true;
}
