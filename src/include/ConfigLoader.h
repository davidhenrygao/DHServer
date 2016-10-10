#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include "common.h"

using namespace std;

class ConfigLoader
{
public:
	virtual bool init(string configFilePath) = 0;
	virtual bool get(string property, string &value) = 0;
	virtual void set(string property, string value) = 0;
	virtual bool getInt(string property, int &value) = 0;
	virtual void setInt(string property, int value) = 0;

	//just for test
	virtual void print() = 0;

private:
};

class LuaConfigLoader: public ConfigLoader
{
public:
	LuaConfigLoader () {};
	~LuaConfigLoader () {};
	bool init(string configFilePath);
	bool get(string property, string &value);
	void set(string property, string value);
	bool getInt(string property, int &value);
	void setInt(string property, int value);

	//just for test
	void print();

private:
	std::map<string, string> m_configMap;
};

#endif /* CONFIGLOADER_H */
