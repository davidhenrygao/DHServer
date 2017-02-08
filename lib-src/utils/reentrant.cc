#include "common.h"

#include <string>
#include <cstring>

string StrError(int errnum) {
  char err_buf[MAX_ERROR_MSG_LEN];
  //If you use g++ compiler, err_buf is not use, so you can set it NULL.
  string err = strerror_r(errnum, err_buf, MAX_ERROR_MSG_LEN);
  return err;
}
