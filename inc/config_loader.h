/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Datetime: 2016-11-15 15:21
 *
 * Note: 
 *
 */

#ifndef DHSERVER_CONFIG_LOADER_H_
#define DHSERVER_CONFIG_LOADER_H_

#include "common.h"
#include "configuration.h"

class ConfigLoaderInterface {
 public:
  virtual ~ConfigLoaderInterface() {}
  //Load configure attributes from file and initialize configuration container.
  virtual bool Load(string file_path, 
                    ConfigurationInterface *pconfiguration) = 0;
};


enum LoaderType {
  kLuaLoader,
  kPropertyLoader,  // TODO: not implement now.
};

#endif /* end of include guard: DHSERVER_CONFIG_LOADER_H_ */
