#include <cstdlib>
#include "ConfigLoader.h"
#include "LuaHeader.h"
#include "LuaUtils.h"
#include "facilities.h"

using namespace std;

static const string luaCfgLoadString = "\
	local cfg_file = ...\
	local result = {}\
	local result_func = assert(loadfile(cfg_file, \"bt\", result))\
	result_func()\
	return result\
";

bool LuaConfigLoader::init(string configFilePath) {
	const char *cfgFile = configFilePath.c_str();

	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	int err = luaL_loadbuffer(L, luaCfgLoadString.c_str(), 
			luaCfgLoadString.length(), "luaCfgLoadString");
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

	if (LuaUtils::tableToMap(L, -1, m_configMap) == false) {
		std::cout << "Load configure file error: Transfer lua table to map failed!" 
			<< std::endl;
		lua_close(L);
		return false;
	}

	lua_close(L);
	return true;
}

bool LuaConfigLoader::get(string property, string &value) {
	if (m_configMap.find(property) != m_configMap.end()) {
		value = m_configMap[property];
		return true;
	}
	return false;
}

bool LuaConfigLoader::getInt(string property, int &value) {
	if (m_configMap.find(property) != m_configMap.end()) {
		string strVal = m_configMap[property];
		value = atoi(strVal.c_str());
		return true;
	}
	return false;
}

void LuaConfigLoader::set(string property, string value) {
	m_configMap[property] = value;
}

void LuaConfigLoader::setInt(string property, int value) {
	string strVal = DataTypeTranfer::intToString(value);
	m_configMap[property] = strVal;
}

void LuaConfigLoader::print() {
	for (std::map<string,string>::iterator iter = m_configMap.begin(); iter != m_configMap.end(); ++iter) {
		std::cout << "key: "<< iter->first << "; value: " << iter->second << std::endl;
	}
	
}
