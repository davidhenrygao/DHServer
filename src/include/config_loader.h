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

class ConfigLoaderInterface {
 public:
  //Read configure attributes from file and initialize internal container.
  virtual bool Init(string file) = 0;
  //Get string value by the key(property), 
  //return false if the key is not exist.
  virtual bool Get(string property, string &value) const = 0;
  //Set a string value to the key(property).
  virtual void Set(string property, string value) = 0;
  //Get integer value by the key(property), 
  //return false if the key is not exist.
  virtual bool GetInt(string property, int &value) const = 0;
  //Set a integer value to the key(property).
  virtual void SetInt(string property, int value) = 0;

  //just for test.
  virtual void Print() const = 0;

 private:
};

//lua comfigure loader.
class LuaConfigLoader: public ConfigLoaderInterface {
 public:
  LuaConfigLoader () {};
  ~LuaConfigLoader () {};
  bool Init(string file);
  bool Get(string property, string &value) const;
  void Set(string property, string value);
  bool GetInt(string property, int &value) const;
  void SetInt(string property, int value);

  //just for test.
  void Print() const;

 private:
  //configure attributes map.
  std::map<string, string> cfg_map_;
};

//TODO:
//  XmlConfigLoader and JsonConfigLoader.

#endif /* end of include guard: DHSERVER_CONFIG_LOADER_H_ */
