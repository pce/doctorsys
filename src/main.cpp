#include "screen.h"

#include "system.h"
#include "system_linux.h"




int main() {

  System* sys = System::Factory();
  Screen::Display(sys);
}