/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-01-22 16:11
 *
 * Note: 
 *
 */
#ifndef DHSERVER_LOCKQUEUE_H_
#define DHSERVER_LOCKQUEUE_H_

#include <queue>
#include <list>
#include "common.h"
#include "lock.h"

#define DEFAULT_QUEUE_SIZE 1000

//Note: Like std::queue, if you define Elem as a object pointer type, 
//      you need to release the memory by yourself.
template <typename Elem>
class LockQueue {
 public:
  typedef std::queue< Elem, std::list<Elem> > ListQueueType;
  LockQueue(size_t sz = DEFAULT_QUEUE_SIZE):kMaxQueueSize(sz) {}
  ~LockQueue() {}
  bool Init();
  typename ListQueueType::size_type Size()const;
  //function Front, Pop, PopN, PopAll return 0 when the queue is empty;
  //function Push return 0 when the queue is full;
  //all functions return the actual number of elements operated successfully.
  size_t Front(Elem& e);
  size_t Push(const Elem& e);
  size_t PushN(const Elem elems[], size_t sz);
  size_t Pop(Elem& e);
  size_t PopN(Elem elems[], size_t sz);
  size_t PopAll(Elem elems[], size_t sz);

 private:
  ListQueueType q_;
  Mutex lock_;
  const size_t kMaxQueueSize;

  LockQueue(const LockQueue&);
  LockQueue& operator=(const LockQueue&);
};

template <typename Elem>
bool LockQueue<Elem>::Init() {
  return lock_.Init();
}

template <typename Elem>
typename LockQueue<Elem>::ListQueueType::size_type 
LockQueue<Elem>::Size()const {
  const_cast<Mutex&>(lock_).Lock();
  typename LockQueue<Elem>::ListQueueType::size_type sz = q_.size();
  const_cast<Mutex&>(lock_).UnLock();
  return sz;
}

template <typename Elem>
size_t LockQueue<Elem>::Front(Elem& elem) {
  size_t ret = 0;
  lock_.Lock();
  if (!q_.empty()) {
    elem = q_.front();
    ret = 1;
  }
  lock_.UnLock();
  return ret;
}

template <typename Elem>
size_t LockQueue<Elem>::Push(const Elem& elem) {
  size_t ret = PushN(&elem, 1);
  return ret;
}

template <typename Elem>
size_t LockQueue<Elem>::PushN(const Elem elems[], size_t sz) {
  size_t ret = 0;
  size_t i;
  lock_.Lock();
  if (q_.size() + sz > kMaxQueueSize) {
    //std::cout << "Log messages queue overflow!" << std::endl;
    sz = kMaxQueueSize - q_.size();
  } 
  ret = sz;
  for (i = 0; i < sz; ++i) {
    q_.push(elems[i]);
  }
  lock_.UnLock();
  return ret;
}

template <typename Elem>
size_t LockQueue<Elem>::Pop(Elem& elem) {
  size_t ret = PopN(&elem, 1);
  return ret;
}

template <typename Elem>
size_t LockQueue<Elem>::PopN(Elem elems[], size_t sz) {
  size_t ret = 0;
  size_t i;
  lock_.Lock();
  if (sz > q_.size()) {
    sz = q_.size();
  }
  ret = sz;
  for (i = 0; i < sz; ++i) {
    elems[i] = q_.front();
    q_.pop();
  }
  lock_.UnLock();
  return ret;
}

template <typename Elem>
size_t LockQueue<Elem>::PopAll(Elem elems[], size_t sz) {
  size_t ret = PopN(elems, sz);
  return ret;
}

#endif /* end of include guard: DHSERVER_LOCKQUEUE_H_*/
