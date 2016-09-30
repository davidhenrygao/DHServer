#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include "common.h"

using namespace std;

class ConfigLoader
{
public:
	virtual bool init(string configFilePath) = 0;
	virtual string get(string property) = 0;
	virtual void set(string property, string value) = 0;
	virtual int getInt(string property) = 0;
	virtual void setInt(string property, int value) = 0;

private:
	std::map<string, string> m_configMap;
};

class LuaConfigLoader: public ConfigLoader
{
public:
	LuaConfigLoader () {};
	~LuaConfigLoader () {};
	bool init(string configFilePath);
	string get(string property);
	void set(string property, string value);
	int getInt(string property);
	void setInt(string property, int value);

private:
};

#endif /* CONFIGLOADER_H */
