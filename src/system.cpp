// #include <unistd.h>
// #include <cstddef>
// #include <iostream>
// #include <set>
// #include <string>
// #include <vector>
#include "system.h"

#include <memory>

#include "system_darwin.h"
#include "system_linux.h"

std::unique_ptr<System> System::Factory() {
#if defined(__linux__)
  return std::make_unique<SystemLinux>();
#endif
#if defined(__APPLE__)
  return std::make_unique<SystemDarwin>();
#endif

  return std::make_unique<SystemLinux>();
  //   std::unique_ptr<System> sys = std::make_unique<SystemLinux>();
  //   return std::move(sys);
  // return nullptr;
}

System::~System(){};