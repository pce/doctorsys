#ifndef SYSTEM_LINUX_H
#define SYSTEM_LINUX_H

#include <string>
#include <vector>

#include "system.h"

class SystemDarwin : public System
{
  public:
	  long int UpTime();
};


#endif