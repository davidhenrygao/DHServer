/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-01-25 10:39
 *
 * Note: 
 *
 */

#include "common.h"
#include "thread.h"

Thread::~Thread() {
  if (state_ != kUninit) {
    pthread_attr_destroy(&attr_);
  }
}

bool Thread::Init() {
  char err_buf[MAX_ERROR_MSG_LEN];
  if (state_ == kUninit) {
    int ret = pthread_attr_init(&attr_);
    if (ret == 0) {
      state_ = kInit;
      return true;
    }
    else {
      strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN);
      LOG_ERROR("Init thread attribute error: %s!", err_buf);
    }
  }
  else {
    LOG_INFO("Thread attribute had been initialized before!");
  }
  return false;
}

bool Thread::Start() {
  char err_buf[MAX_ERROR_MSG_LEN];
  if (state_ == kInit || state_ == kExit) {
    int ret = pthread_create(&tid_, &attr_, &RtAdaptor, this);
    if (ret == 0) {
      state_ = kStart;
      return true;
    }
    else {
      strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN);
      LOG_ERROR("Thread start error: %s!", err_buf);
      return false;
    }
  }
  else {
    LOG_INFO("Thread can't start from state %u!", state_);
    return false;
  }
}

bool Thread::SetDetach() {
  char err_buf[MAX_ERROR_MSG_LEN];
  int ret;
  if (!joinable_) {
    return true;
  }
  if (state_ == kInit || state_ == kExit) {
    ret = pthread_attr_setdetachstate(&attr_, PTHREAD_CREATE_DETACHED);
    if (ret == 0) {
      joinable_ = false;
      return true;
    }
    else {
      strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN);
      LOG_ERROR("Set thread attribute detached error: %s!", err_buf);
      return false;
    }
  }
  if (state_ == kStart) {
    ret = pthread_detach(tid_);
    if (ret == 0) {
      joinable_ = false;
      return true;
    } else {
      strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN);
      LOG_ERROR("Set thread detach error: %s!", err_buf);
      return false;
    }
  }
  LOG_INFO("Thread can't be set detach in state %u!", state_);
  return false;
}

bool Thread::SetJoinable() {
  char err_buf[MAX_ERROR_MSG_LEN];
  int ret;
  if (joinable_) {
    return true;
  }
  if (state_ == kInit || state_ == kExit) {
    ret = pthread_attr_setdetachstate(&attr_, PTHREAD_CREATE_JOINABLE);
    if (ret == 0) {
      joinable_ = true;
      return true;
    }
    else {
      strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN);
      LOG_ERROR("Set thread attribute joinable error: %s!", err_buf);
      return false;
    }
  }
  LOG_INFO("Thread can't be set detach in state %u!", state_);
  return false;
}

bool Thread::Join() {
  char err_buf[MAX_ERROR_MSG_LEN];
  int ret;
  if(!joinable_) {
    LOG_INFO("Thread is not joinable!");
    return false;
  }
  if (state_ == kStart || state_ == kExit) {
    ret = pthread_join(tid_, NULL);
    if (ret == 0) {
      return true;
    }
    else {
      strerror_r(ret, err_buf, MAX_ERROR_MSG_LEN);
      LOG_ERROR("Thread join error: %s!", err_buf);
      return false;
    }
  }
  LOG_INFO("Thread can't be join in state %u!", state_);
  return false;
}

bool Thread::GetTid(Tid &tid)const {
  if (state_ != kStart) {
    LOG_INFO("Thread is not in the start state!");
    return false;
  }
  tid = tid_;
  return true;
}

bool Thread::Equal(Tid t1, Tid t2) {
  int ret = pthread_equal(t1, t2);
  return ret == 0 ? false : true;
}

void* Thread::RtAdaptor(void *arg) {
  Thread *pthread = (Thread*)arg;
  pthread->Routine();
  pthread->state_ = kExit;
  return NULL;
}
