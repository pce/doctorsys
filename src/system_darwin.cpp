#include <dirent.h>
#include <unistd.h>
// #include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "file_util.h"
#include "system_darwin.h"


long SystemDarwin::UpTime() { 
  const std::string kProcDirectory{"/proc/"};
  const std::string kUptimeFilename{"/uptime"};
  std::string value, key;
  std::string line;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> value;
    return std::stol(value);
  }
  return 0;
}


