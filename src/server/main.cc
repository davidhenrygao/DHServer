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

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error: Inupt Arguments Error!\n" \
      "Usage: DHServer configure_file" << std::endl;
    return -1;
  }
  ConfigLoaderInterface *ploader = ConfigLoaderFactory::GetLoader(kLuaLoader);
  string cfg_file(argv[1]);
  if (!ploader->Init(cfg_file)) {
    std::cout << "Init configure file failed!" << std::endl;
    return -1;
  }
  ploader->Print();
  std::cout << "DHServer Setup Success!" << std::endl;
  return 0;
}
