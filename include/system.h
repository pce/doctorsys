#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

class System
{
  public:
  static System* Factory();
	virtual long int UpTime() = 0;
};


#endif