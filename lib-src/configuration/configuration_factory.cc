/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-22 17:46
 *
 * Note: 
 *
 */
#include "configuration_factory.h"
#include "configuration_map.h"

ConfigurationInterface* ConfigurationFactory::GetConfiguration(
    ConfigurationContainerType type) {
  ConfigurationInterface* pconfiguration;
  switch (type) {
    case kMapContainer:
      pconfiguration = new ConfigurationMap();
      break;
    default:
      LOG_INFO("Unknown configuration container type(%u).", type); 
      break;
  }
  if (pconfiguration != NULL) {
    SetDefaultConfiguration(pconfiguration);
  } else {
    LOG_ERROR("Allocate configuration object error!");
  }
  return pconfiguration;
}

void ConfigurationFactory::SetDefaultConfiguration(
    ConfigurationInterface* pconfiguration) {
  if (pconfiguration == NULL) {
    return;
  }
  map<string, string> cfg_map;
  cfg_map["root_dir"] = "./";
  cfg_map["ip"] = "192.168.82.198";
  cfg_map["port"] = "2016";
  cfg_map["thread"] = "8";
  cfg_map["log_dir"] = "./log/";
  cfg_map["log_level"] = "3";
  cfg_map["daemonize"] = "1";
  for (map<string, string>::const_iterator iter = cfg_map.begin(); 
      iter != cfg_map.end(); ++iter) {
    pconfiguration->Set(iter->first, iter->second);
  }
}
