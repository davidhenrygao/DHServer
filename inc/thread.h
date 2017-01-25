/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-01-23 19:53
 *
 * Note: 
 *
 */
#ifndef DHSERVER_THREAD_H_
#define DHSERVER_THREAD_H_

#include "thread_def.h"

//This is a simple thread model.
//The only way to exit the thread is return by Routine().
//Not support any exit, cancel, kill or cleanup operations.
//You must do it all in the Routine() function.
class Thread {
 public:
  Thread() : state_(kUninit), joinable_(true) {}
  virtual ~Thread();
  bool Init();
  bool Start();
  bool SetDetach();
  bool SetJoinable();
  bool Join();
  bool GetTid(Tid&)const;
  virtual void Routine()=0;
  static bool Equal(Tid, Tid);

 private:
  Tid tid_;
  Tattr attr_;
  ThreadState state_;
  bool joinable_;

  //Note: You can define the class argument members and result members 
  //      for Routine() function to use and set in the concrete class 
  //      you defined.
  //      Also, include their setters and getters.

  //RoutineAdaptor will call the abstract virtual function Routine().
  static RoutineAdaptor RtAdaptor;

  //forbidden to call copy constuctor and assign operator.
  Thread(const Thread&);
  Thread& operator=(const Thread&);
};

#endif /* end of include guard: DHSERVER_THREAD_H_ */
