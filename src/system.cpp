// #include <unistd.h>
// #include <cstddef>
// #include <iostream>
// #include <set>
// #include <string>
// #include <vector>
#include <memory>

#include "system.h"
#include "system_linux.h"


std::unique_ptr<System> System::Factory() {
/*
#if defined(OS_DARWIN)
    return SystemDarwin;
#endif
#if defined(OS_LINUX)
    return SystemLinux;
#endif
*/
    // memleak: return new SystemLinux;
    return std::make_unique<SystemLinux>();
    // return std::unique_ptr<SystemLinux>();
    // return nullptr;
}

/*
long int System::UpTime() { 
    system_.UpTime();
};
*/


