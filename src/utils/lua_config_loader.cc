/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-15 16:18
 *
 * Note: 
 *
 */

#include <cstdlib>
#include "config_loader.h"
#include "lua_header.h"
#include "lua_utils.h"
#include "facilities.h"

//A snippet code string of lua.
//Helping load the lua code in the given file and return the table result.
static const string kLuaCfgLoadString = "\
  local cfg_file = ...\
  local result = {}\
  local result_func = assert(loadfile(cfg_file, \"bt\", result))\
  result_func()\
  return result\
";

//Create a lua stack to load the configure code in the given file.
//And put the result into internal attribute container.
bool LuaConfigLoader::Init(string file) {
  const char *cfgFile = file.c_str();

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  int err = luaL_loadbuffer(L, kLuaCfgLoadString.c_str(), 
      kLuaCfgLoadString.length(), "luaCfgLoadString");
  if (err) {
    std::cout << "Load configure loadString error: " 
      << lua_tostring(L, -1) << std::endl;
    lua_close(L);
    return false;
  }

  //push the cfgFile in stack
  lua_pushstring(L, cfgFile);
  err = lua_pcall(L, 1, 1, 0);
  if (err) {
    std::cout << "Load configure file error: " 
      << lua_tostring(L, -1) << std::endl;
    lua_close(L);
    return false;
  }

  int top_index = lua_gettop(L);
  if (LuaUtils::TableToMap(L, top_index, cfg_map_) == false) {
    std::cout << "Load configure file error: Transfer lua table to map failed!" 
      << std::endl;
    lua_close(L);
    return false;
  }

  lua_close(L);
  return true;
}

bool LuaConfigLoader::Get(string property, string &value) const {
  std::map<string, string>::const_iterator k_iter = cfg_map_.find(property);
  if (k_iter != cfg_map_.end()) {
    value = k_iter->second;
    return true;
  }
  return false;
}

bool LuaConfigLoader::GetInt(string property, int &value) const {
  std::map<string, string>::const_iterator k_iter = cfg_map_.find(property);
  if (k_iter != cfg_map_.end()) {
    string strVal = k_iter->second;
    value = atoi(strVal.c_str());
    return true;
  }
  return false;
}

void LuaConfigLoader::Set(string property, string value) {
  cfg_map_[property] = value;
}

void LuaConfigLoader::SetInt(string property, int value) {
  string strVal = DataTypeTranfer::IntToString(value);
  cfg_map_[property] = strVal;
}

void LuaConfigLoader::Print() const {
  for (std::map<string,string>::const_iterator k_iter = cfg_map_.begin(); k_iter != cfg_map_.end(); ++k_iter) {
    std::cout << "key: "<< k_iter->first << "; value: " << k_iter->second << std::endl;
  }
  
}
