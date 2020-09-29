#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <fstream>
#include <regex>
#include <string>

namespace FileUtil {
std::string GetValueOfLine(std::string file, std::string find_str);
std::string GetContentsOfFile(std::string file);
std::string GetNthValue(std::string file, int n, char sep = ' ');
};  // namespace FileUtil

#endif