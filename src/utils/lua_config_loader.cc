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

#include "lua_config_loader.h"
#include "lua_header.h"
#include "lua_utils.h"

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
//And put the result into configuration container.
bool LuaConfigLoader::Load(
    string file_path,
    ConfigurationInterface *pconfiguration) {
  const char *cfgFile = file_path.c_str();

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
  map<string, string> cfg_map;
  if (LuaUtils::TableToMap(L, top_index, cfg_map) == false) {
    std::cout << "Load configure file error: Transfer lua table to map failed!" 
      << std::endl;
    lua_close(L);
    return false;
  }
  for (map<string, string>::const_iterator iter = cfg_map.begin(); 
      iter != cfg_map.end(); ++iter) {
    pconfiguration->Set(iter->first, iter->second);
  }

  lua_close(L);
  return true;
}
