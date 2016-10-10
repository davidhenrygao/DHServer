#include "common.h"
#include "facilities.h"
#include "LuaUtils.h"

/*
 * Note: lua table must only contain string key, 
 *       and the value only can be string, number or boolean type.
 */
bool LuaUtils::tableToMap(lua_State *L, int index, std::map<string, string> &map) {
	if (L == NULL) {
		return false;
	}
	if (lua_istable(L, index) == 0) {
		return false;
	}
	//iterate the table in the stack.
	lua_pushnil(L);
	bool errFlag = false;
	while (lua_next(L, index) != 0) {
		//key's index is -2, and value's index is -1.
		//make sure the key type must string.
		if (lua_type(L, -2) == LUA_TSTRING) {
			string key(lua_tostring(L, -2));
			string value;
			switch (lua_type(L, -1)) {
				case LUA_TSTRING:
				case LUA_TNUMBER:
					value = lua_tostring(L, -1);
					break;
				case LUA_TBOOLEAN:
					value = DataTypeTranfer::intToString(lua_toboolean(L, -1));
					break;
				default:
					errFlag = true;
					break;
			}
			map[key] = value;
		} else {
			errFlag = true;
		}

		//pop the value and leave the key for next iteration.
		lua_pop(L, 1);

		if (errFlag) {
			lua_pop(L, 1);
			map.clear();
			return false;
		}
	}
	return true;
}
