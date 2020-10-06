#ifndef SYSTEM_H
#define SYSTEM_H

#include <memory>
#include <string>
#include <vector>

class System {
public:
  static std::unique_ptr<System> Factory();
  virtual long int UpTime() = 0;
};

#endif