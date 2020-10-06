#include <sys/sysctl.h>
#include <chrono> 
#include <time.h>
#include <errno.h>
// #include <dirent.h>
// #include <unistd.h>
// #include <filesystem>
// #include <iostream>
// #include <string>
// #include <vector>

#include "file_util.h"
#include "system_darwin.h"


long SystemDarwin::UpTime() {
    std::chrono::milliseconds uptime(0u);
    struct timeval ts;
    std::size_t len = sizeof(ts);
    int mib[2] = { CTL_KERN, KERN_BOOTTIME };
    if (sysctl(mib, 2, &ts, &len, NULL, 0) == 0) {
        uptime = std::chrono::milliseconds(
            static_cast<unsigned long long>(ts.tv_sec)*1000ULL +
            static_cast<unsigned long long>(ts.tv_usec)/1000ULL
        );
        return uptime.count() / 1000;
    }
    return 0;
}


