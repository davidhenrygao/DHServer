#include <cstdio>
#include "facilities.h"

using namespace std;

string DataTypeTranfer::intToString(int i) {
	char buffer[256];
	sprintf(buffer, "%d", i);
	string retStr(buffer);
	return retStr;
}
