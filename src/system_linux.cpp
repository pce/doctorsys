#include <dirent.h>
#include <unistd.h>
// #include <filesystem>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "file_util.h"
#include "system_linux.h"

long SystemLinux::UpTime() {
  std::chrono::milliseconds uptime(0u);
  double uptime_seconds;
  if (std::ifstream("/proc/uptime", std::ios::in) >> uptime_seconds) {
    uptime = std::chrono::milliseconds(
        static_cast<unsigned long long>(uptime_seconds * 1000.0));
  }
  return uptime.count() / 1000;
}
