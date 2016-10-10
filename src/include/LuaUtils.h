#ifndef LUAUTILS_H_T5Q4NWVP
#define LUAUTILS_H_T5Q4NWVP

#include "common.h"
#include "LuaHeader.h"

class LuaUtils
{
public:
	static bool tableToMap(lua_State *L, int index, std::map<string, string> &map);

private:
	/* data */
};

#endif /* end of include guard: LUAUTILS_H_T5Q4NWVP */
