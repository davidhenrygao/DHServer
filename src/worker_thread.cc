#include "common.h"
#include "worker_thread.h"

#include <unistd.h>

WorkerThread::WorkerThread(const string &name): name_(name) {
  
}

WorkerThread::~WorkerThread() {
  
}

void WorkerThread::Routine() {
  for (int i = 0; i < 10; ++i) {
    LOG_INFO("Worker %s do %d work.", name_.c_str(), i);
    if (i%5 == 0) {
      usleep(200);
    }
  }
  LOG_INFO("Worker %s done.", name_.c_str());
}
