#include <unistd.h>
#include <cstddef>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "system.h"
#include "system_linux.h"


System* System::Factory() {
/*
#if defined(OS_DARWIN)
    return SystemDarwin;
#endif
#if defined(OS_LINUX)
    return SystemLinux;
#endif
*/
    return new SystemLinux;
    // return nullptr;
}

/*
long int System::UpTime() { 
    system_.UpTime();
};
*/


