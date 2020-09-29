// #include <dirent.h>
#include <unistd.h>
#include <filesystem>
#include <fstream>
// #include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "file_util.h"

using std::stof;
using std::to_string;
using std::vector;

/**
 * @brief Reads Line by Line and returns line where find_str occurs, without find_str
 *
 *
 * @param file
 * @param find_str
 * @return std::string
 */
std::string FileUtil::GetValueOfLine(std::string file, std::string find_str) {
  std::string line{""};
  std::string key;
  std::string value;
  std::ifstream filestream(file);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      if (line.rfind(find_str, 0) == 0) {
        // trim processes and whitespace
        line.replace(0, std::string(find_str).length(), std::string(""));
        return line;
      }
    }
  }
  return line;
}

/**
 * @brief
 *
 * @param file
 * @return std::string
 */
std::string FileUtil::GetContentsOfFile(std::string file) {
  std::stringstream buffer;
  std::ifstream filestream(file);
  if (filestream.is_open()) {
    buffer << filestream.rdbuf();
  }
  return buffer.str();
}

/**
 * @brief Get nth space-separated value
 *
 * @param file
 * @param n
 * @return std::string
 */
std::string FileUtil::GetNthValue(std::string file, int n, char sep) {
  std::string line;
  std::string token{""};
  std::ifstream filestream(file);
  if (!filestream.is_open()) {
    throw std::runtime_error("Could not open file: " + file);
  }
  std::getline(filestream, line);
  int pos = 1;
  std::istringstream linestream(line);
  while (std::getline(linestream, token, sep)) {
    if (pos == n) {
      // throw std::runtime_error("token: " + token);
      return token;
    }
    pos++;
  }
  return token;
}