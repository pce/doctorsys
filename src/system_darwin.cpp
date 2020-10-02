#include <dirent.h>
#include <unistd.h>
// #include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "file_util.h"
#include "system_darwin.h"


long SystemDarwin::UpTime() { 
    return 42;
}


