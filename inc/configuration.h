/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-22 15:24
 *
 * Note: 
 *
 */
#ifndef DHSERVER_CONFIGURATION_H_
#define DHSERVER_CONFIGURATION_H_

#include "common.h"

class ConfigurationInterface{
 public:
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
  //Print all the comfigure properties.
  virtual void Print() const = 0;
};

enum ConfigurationContainerType { 
  kMapContainer,
  kHashMapContainer,  // TODO: not implement now.
};

#endif /* end of include guard: DHSERVER_CONFIGURATION_H_ */
