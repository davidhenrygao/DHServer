/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-22 16:07
 *
 * Note: 
 *
 */
#ifndef DHSERVER_CONFIGURATION_FACTORY_H_
#define DHSERVER_CONFIGURATION_FACTORY_H_

#include "common.h"
#include "configuration.h"

class ConfigurationFactory {
 public:
  //Get configuration object with default properties.
  //Default configuration container type is kMapContainer.
  static ConfigurationInterface* GetConfiguration(
      ConfigurationContainerType type = kMapContainer);
 private:
  static void SetDefaultConfiguration(
      ConfigurationInterface* pconfiguration);
};

#endif /* end of include guard: DHSERVER_CONFIGURATION_FACTORY_H_ */
