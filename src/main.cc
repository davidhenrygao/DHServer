/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-15 16:36
 *
 * Note: 
 *
 */

#include "common.h"
#include "config_loader_factory.h"
#include "configuration_factory.h"
#include "log_thread.h"
#include "worker_thread.h"
#include "facilities.h"

ConfigurationInterface * g_psysconfig = NULL;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    LOG_ERROR("Inupt Arguments Error!\n" \
      "Usage: DHServer configure_file");
    return -1;
  }
  g_psysconfig = ConfigurationFactory::GetConfiguration();
  ConfigLoaderInterface *ploader = 
    ConfigLoaderFactory::GetLoader(kLuaLoader);
  if (g_psysconfig == NULL || ploader == NULL) {
    return -1;
  }
  string cfg_file(argv[1]);
  if (!ploader->Load(cfg_file, g_psysconfig)) {
    LOG_ERROR("Init configure file failed!");
    return -1;
  }
  delete ploader;
  ploader = NULL;
  g_psysconfig->Print();
  LOG_INFO("DHServer Setup Success!");
  LogThread logthread(kDebug);
  logthread.Init();
  logthread.Start();
  WorkerThread *wokers[10];
  for (int i = 0; i < 10; ++i) {
    wokers[i] = new WorkerThread(DataTypeTransfer::IntToString(i));
    wokers[i]->Init();
    wokers[i]->Start();
  }
  for (int i = 0; i < 10; ++i) {
    wokers[i]->Join();
  }
  logthread.Join();
  return 0;
}
