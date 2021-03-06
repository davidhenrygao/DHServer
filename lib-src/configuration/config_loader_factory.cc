/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-15 16:16
 *
 * Note: 
 *
 */

#include "config_loader_factory.h"
#include "lua_config_loader.h"

//Allocate a loader according to the given loader type and renturn its pointer.
//Default, return a pointer of lua loader.
ConfigLoaderInterface* ConfigLoaderFactory::GetLoader(LoaderType type) {
  ConfigLoaderInterface *ploader = NULL;
  switch (type) {
    case kLuaLoader:
      ploader = new LuaConfigLoader();
      break;
    default:
      LOG_INFO("ConfigLoaderFactory get ConfigLoader error: \
        Unknown loader type(%u).", type);
      ploader = new LuaConfigLoader();  //lua configure loader is as default
      break;
  }
  if (ploader == NULL) {
    LOG_ERROR("Allocate configure loader object error!");
  }
  return ploader;
}
