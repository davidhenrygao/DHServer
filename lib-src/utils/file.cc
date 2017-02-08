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

#include "file.h"

#include <cstdio>
#include <cerrno>
#include <unistd.h>
#include <sys/stat.h>

File::~File() {
  Close();
}

/*
 * Todo:
 * Transfer // or /./ or /../ path.
 */
static bool TransferDirPath(const string &src, string &result) {
  string temp = src;
  string::size_type len = temp.length();
  if (temp[len-1] == '/') {
    temp[len-1] = '\0';
    len = len - 1;
  }
  result = temp.c_str();
  return true;
}

bool File::CreateDirs(const string &dirpath) {
  string multidir;
  if (TransferDirPath(dirpath, multidir) == false) {
    LOG_ERROR("File's directory(%s) format error!", dirpath.c_str());
    return false;
  }
  string::size_type len = multidir.length();
  string temp = multidir;
  string::size_type pos = len;
  while (pos) {
    if (access(temp.c_str(), F_OK) == 0) {
      break;
    }
    while (pos > 0 && temp[--pos] != '/');
    temp[pos] = '\0';
  }
  while (pos < len) {
    while (pos < len) {
      pos++;
      if (multidir[pos] == '/') {
        break;
      }
    }
    temp = multidir.substr(0, pos);
    if (mkdir(temp.c_str(), S_IRWXU|S_IRWXG|S_IRWXO) != 0) {
      LOG_ERROR("Create File's directory(%s) error: %s!", 
          multidir.c_str(), StrError(errno).c_str());
      return false;
    }
  }
  return true;
}

bool File::IsExist(const string &filename) {
  if (access(filename.c_str(), F_OK) == 0) {
    return true;
  }
  return false;
}

bool File::Open(const string &filename, const string &mode) {
  string::size_type pos = filename.length();
  while (pos > 0 && filename[--pos] != '/');
  if (pos != 0) {
    string dir = filename.substr(0, pos);
    if (!IsExist(dir) && !CreateDirs(dir)) {
      LOG_ERROR("Open file error: directory(%s) is illegal!", dir.c_str());
      return false;
    }
  }
  fp_ = fopen(filename.c_str(), mode.c_str());
  if (fp_ == NULL) {
    LOG_ERROR("Open file error: %s!", StrError(errno).c_str());
    return false;
  }
  return true;
}

bool File::Close() {
  if (fp_ != NULL) {
    int ret = fclose(fp_);
    fp_ = NULL;
    if (ret != 0) {
      LOG_ERROR("Close file error: %s!", StrError(errno).c_str());
      return false;
    }
  }
  return true;
}

size_t File::Read(void *pbuf, size_t size) {
  size_t rb = 0;
  while (rb < size) {
    rb += fread(pbuf, 1, size, fp_);
    if (feof(fp_) != 0) {
      break;
    }
    if (ferror(fp_) != 0) {
      LOG_ERROR("Read file error: %s!", StrError(errno).c_str());
      break;
    }
  }
  return rb;
}

size_t File::Write(const void *pbuf, size_t size) {
  size_t wb = 0;
  while (wb < size) {
    wb += fwrite(pbuf, 1, size, fp_);
    if (ferror(fp_) != 0) {
      LOG_ERROR("Write file error: %s!", StrError(errno).c_str());
      break;
    }
  }
  fflush(fp_);
  return wb;
}

size_t File::WriteString(const string& s) {
  size_t len = s.length();
  size_t wb = Write(s.c_str(), len);
  return wb;
}
