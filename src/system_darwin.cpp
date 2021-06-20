#include <errno.h>
#include <sys/sysctl.h>
#include <time.h>

#include <chrono>
// #include <dirent.h>
// #include <unistd.h>
// #include <filesystem>
// #include <iostream>
// #include <string>
// #include <vector>

#include "file_util.h"
#include "system_darwin.h"

long SystemDarwin::UpTime() {
  struct timeval ts;
  auto ts_len = sizeof(ts);
  int mib[2] = {CTL_KERN, KERN_BOOTTIME};
  auto constexpr mib_len = sizeof(mib) / sizeof(mib[0]);
  if (sysctl(mib, mib_len, &ts, &ts_len, nullptr, 0) == 0) {
    std::chrono::system_clock::time_point boot{
        std::chrono::seconds{ts.tv_sec} +
        std::chrono::microseconds{ts.tv_usec}};
    return (std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now() - boot))
               .count() /
           1000;
  }
  return 0;
}

std::string SystemDarwin::SpaceInfo() { return FileUtil::GetSpaceInfo(); }
