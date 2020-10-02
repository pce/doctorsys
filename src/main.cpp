#include "screen.h"

#include "system.h"
#include "system_linux.h"


int main() {
  // System factory instead of: 
  // std::shared_ptr<SystemLinux> sys = std::make_unique<SystemLinux>();
  std::shared_ptr<System> sys = System::Factory();
  Screen::Display(sys);
}
