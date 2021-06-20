#ifndef SYSTEM_DARWIN_H
#define SYSTEM_DARWIN_H

#include <string>
#include <vector>

#include "system.h"

class SystemWin : public System {
public:
  long int UpTime();
  std::string SpaceInfo();
};

#endif