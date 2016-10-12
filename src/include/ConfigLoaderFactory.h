#ifndef CONFIGLOADERFACTORY_H
#define CONFIGLOADERFACTORY_H

#include "common.h"
#include "ConfigLoader.h"

enum LoaderType 
{
	LUA_LOADER,
	XML_LOADER,
	JSON_LOADER,
};

class ConfigLoaderFactory
{
public:
	static ConfigLoader* get(LoaderType type);
};

#endif /* CONFIGLOADERFACTORY_H */
