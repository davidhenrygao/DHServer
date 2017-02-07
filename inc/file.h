/*
 *
 * Copyright © 2017, David Henry.
 * All Rights Reserved.
 * 
 * Author: David Henry
 * Email: davidhenrygao@gmail.com
 * Datetime: 2017-02-06 17:28
 *
 * Note: 
 *
 */
#ifndef DHSERVER_FILE_H_
#define DHSERVER_FILE_H_

#include "common.h"

class File {
 public:
  File():fp_(NULL) {}
  ~File();
  //mode is the same as fopen api description.
  bool Open(const string &filename, const string &mode);
  bool Close();
  size_t Read(void *pbuf, size_t size);
  size_t Write(const void *pbuf, size_t size);
  size_t WriteString(const string &s);
  static bool IsExist(const string &filename);

 private:
  FILE *fp_;
  static bool CreateDirs(const string &dirpath);
};

#endif /* end of include guard: DHSERVER_FILE_H_ */
