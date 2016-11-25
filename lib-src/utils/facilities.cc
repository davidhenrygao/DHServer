/*
 *
 * Copyright © 2016, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2016-11-15 16:18
 *
 * Note: 
 *
 */

#include <cstdio>
#include "facilities.h"

using namespace std;

//Tranfer integer to string by using sprintf.
string DataTypeTranfer::IntToString(int i) {
  char buffer[256];
  sprintf(buffer, "%d", i);
  string retStr(buffer);
  return retStr;
}
