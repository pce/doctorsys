#include "screen.h"

#include "system.h"
#include "system_linux.h"


int main() {

  std::shared_ptr<System> sys = System::Factory();
  // std::shared_ptr<SystemLinux> sys = std::make_unique<SystemLinux>();
  Screen::Display(sys);
}
