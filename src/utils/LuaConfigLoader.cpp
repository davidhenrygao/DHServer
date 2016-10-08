#include "ConfigLoader.h"
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

using namespace std;

bool LuaConfigLoader::init(string configFilePath) {
	const char *defaultFile = "config_default";
	const char *cfgFile = configFilePath.c_str();
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	int err = luaL_loadfile(L, defaultFile) || lua_pcall(L, 0, 0, 0);
	if (err) {
		std::cout << "Load default configure file error: " << lua_tostring(L, -1) << std::endl;
		lua_close(L);
		return false;
	}
	err = luaL_loadfile(L, cfgFile) || lua_pcall(L, 0, 0, 0);
	if (err) {
		std::cout << "Load configure file error: " << lua_tostring(L, -1) << std::endl;
		lua_close(L);
		return false;
	}
	lua_close(L);
	return true;
}
