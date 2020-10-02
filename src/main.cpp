#include "screen.h"

#include "system.h"
#include "system_linux.h"


int main() {
  // auto sys = System::Factory();
  std::unique_ptr<System> sys = std::move(System::Factory());
  Screen::Display(std::move(sys));
}