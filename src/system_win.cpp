#include <dirent.h>
#include <unistd.h>

#include <windows>
// #include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "file_util.h"
#include "system_darwin.h"

long SystemWin::UpTime() {
  auto uptime = std::chrono::milliseconds(GetTickCount64());
}
std::string SystemWin::SpaceInfo() { return FileUtil::GetSpaceInfo(); }
