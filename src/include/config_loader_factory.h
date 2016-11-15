/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Datetime: 2016-11-15 15:29
 *
 * Note: 
 *
 */

#ifndef DHSERVER_CONFIG_LOADER_FACTORY_H_
#define DHSERVER_CONFIG_LOADER_FACTORY_H_

#include "common.h"
#include "config_loader.h"

enum LoaderType {
  kLuaLoader,
  kXmlLoader,
  kJsonLoader,
};

class ConfigLoaderFactory {
 public:
  //Get the loader according to LoaderType.
  //Default, return the lua Loader.
  static ConfigLoaderInterface* GetLoader(LoaderType type = kLuaLoader);
};

#endif /* end of include guard: DHSERVER_CONFIG_LOADER_FACTORY_H_*/
