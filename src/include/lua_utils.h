/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Datetime: 2016-11-15 15:33
 *
 * Note: 
 *
 */

#ifndef DHSERVER_LUA_UTILS_H_
#define DHSERVER_LUA_UTILS_H_

#include "common.h"
#include "lua_header.h"

//An utility helps using lua in C/C++.
class LuaUtils {
 public:
  //Transfer lua table to C++ map. Return ture if success.
  static bool TableToMap(lua_State *L, int index, std::map<string, string> &map);

 private:
  /* data */
};

#endif /* end of include guard: DHSERVER_LUA_UTILS_H_*/
