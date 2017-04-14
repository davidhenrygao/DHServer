/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-22 15:28
 *
 * Note: 
 *
 */
#ifndef DHSERVER_INTERNAL_COMFIGURATION_MAP_H_
#define DHSERVER_INTERNAL_COMFIGURATION_MAP_H_

#include "configuration.h"

class ConfigurationMap: public ConfigurationInterface {
 public:
  ConfigurationMap() {};
  virtual ~ConfigurationMap() {};
  bool Get(const string &property, string &value) const;
  void Set(const string &property, string value);
  bool GetInt(const string &property, int &value) const;
  void SetInt(const string &property, int value);
  void Print() const;

 private:
  map<string, string> cfg_map_;
};

#endif /* end of include guard: DHSERVER_INTERNAL_COMFIGURATION_MAP_H_ */
