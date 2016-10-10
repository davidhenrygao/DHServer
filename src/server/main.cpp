#include "common.h"
#include "ConfigLoaderFactory.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Error: Inupt Arguments Error!\n" \
			"Usage: DHServer configure_file" << std::endl;
		return -1;
	}
	ConfigLoader *pLoader = ConfigLoaderFactory::get(LUA_LOADER);
	string cfgFilePath(argv[1]);
	if(!pLoader->init(cfgFilePath)) {
		std::cout << "Init configure file failed!" << std::endl;
		return -1;
	}
	pLoader->print();
	std::cout << "DHServer Setup Success!" << std::endl;
	return 0;
}
