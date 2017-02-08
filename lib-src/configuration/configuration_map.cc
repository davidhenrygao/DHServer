/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-22 15:37
 *
 * Note: 
 *
 */
#include <cstdlib>
#include "configuration_map.h"
#include "facilities.h"

bool ConfigurationMap::Get(string property, string &value) const {
  std::map<string, string>::const_iterator k_iter = cfg_map_.find(property);
  if (k_iter != cfg_map_.end()) {
    value = k_iter->second;
    return true;
  }
  return false;
}

bool ConfigurationMap::GetInt(string property, int &value) const {
  std::map<string, string>::const_iterator k_iter = cfg_map_.find(property);
  if (k_iter != cfg_map_.end()) {
    string strVal = k_iter->second;
    value = atoi(strVal.c_str());
    return true;
  }
  return false;
}

void ConfigurationMap::Set(string property, string value) {
  cfg_map_[property] = value;
}

void ConfigurationMap::SetInt(string property, int value) {
  string strVal = DataTypeTransfer::IntToString(value);
  cfg_map_[property] = strVal;
}

void ConfigurationMap::Print() const {
  for (std::map<string,string>::const_iterator k_iter = cfg_map_.begin(); 
      k_iter != cfg_map_.end(); ++k_iter) {
    LOG_INFO("key: %s; value: %s", 
        k_iter->first.c_str(), k_iter->second.c_str());
  }
}
