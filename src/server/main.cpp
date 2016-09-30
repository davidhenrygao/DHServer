#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Error: Inupt Arguments Error!\n" \
			"Usage: DHServer configure_file" << std::endl;
		return -1;
	}
	std::cout << "DHServer Setup Success!" << std::endl;
	return 0;
}
