#include "ConfigLoaderFactory.h"

ConfigLoader& ConfigLoaderFactory::get(LoaderType type) {
	ConfigLoader *ploader = NULL;
	switch (type) {
		case LUA_LOADER:
			ploader = new LuaConfigLoader();
			break;
		default:
			std::cout << "ConfigLoaderFactory get ConfigLoader error: Unknown loader type "<< type << std::endl;
			ploader = new LuaConfigLoader();  //lua configure loader is as default
			break;
	}
	return *ploader;
}
