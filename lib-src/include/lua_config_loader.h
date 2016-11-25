/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-22 17:17
 *
 * Note: 
 *
 */
#ifndef DHSERVER_INTERNAL_LUA_CONFIG_LOADER_H_
#define DHSERVER_INTERNAL_LUA_CONFIG_LOADER_H_

#include "config_loader.h"

class LuaConfigLoader: public ConfigLoaderInterface {
 public:
  bool Load(string file_path, ConfigurationInterface *pconfiguration);
};

#endif /* end of include guard: DHSERVER_INTERNAL_LUA_CONFIG_LOADER_H_ */
