// #include <unistd.h>
// #include <cstddef>
// #include <iostream>
// #include <set>
// #include <string>
// #include <vector>
#include <memory>

#include "system.h"
#include "system_linux.h"
#include "system_darwin.h"


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



