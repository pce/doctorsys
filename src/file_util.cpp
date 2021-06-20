// #include <dirent.h>
#include <unistd.h>

#include <filesystem>
#include <fstream>
// #include <iostream>
#include <cstdint>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#include "file_util.h"

using std::stof;
using std::to_string;
using std::vector;

/**
 * @brief Reads Line by Line and returns line where find_str occurs, without
 * find_str
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
 * @brief Return Contents of File as string
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


/**
 * \brief "Human-readable" output.
 * 
 * \see https://en.cppreference.com/w/cpp/filesystem/file_size
 * \param size 
 * \return std::string 
 */
std::string FileUtil::HumanReadable(std::uintmax_t size) 
{
  std::stringstream ss;
  int i{};
  double mantissa = size;
  for (; mantissa >= 1024.; mantissa /= 1024., ++i) { }
  mantissa = std::ceil(mantissa * 10.) / 10.;
  ss << mantissa << "BKMGTPE"[i];
  if (i == 0) {
    return ss.str();
  }
  ss << "B (" << size << ')';
  return ss.str();
}


std::string FileUtil::GetSpaceInfo() {
  std::error_code ec;
  std::stringstream ss;

  const auto dirs = {"/"}; // , "/tmp", "/home", "/null" };
  for (auto const &dir : dirs) {
    const std::filesystem::space_info si = std::filesystem::space(dir, ec);

    auto capa = static_cast<std::intmax_t>(si.capacity);
    // auto free = static_cast<std::intmax_t>(si.free);
    auto avail = static_cast<std::intmax_t>(si.available); 

    ss << "Capa:  " << HumanReadable(static_cast<uintmax_t>(capa))  << " "
       << "Avail: " << HumanReadable(static_cast<uintmax_t>(avail)) << " " << dir << "\n";
  }
  return ss.str();
}
