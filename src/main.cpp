#include "screen.h"

#include "system.h"
#include "system_linux.h"

int main() {
  std::shared_ptr<System> sys = System::Factory();
  Screen::Display(sys);
}
