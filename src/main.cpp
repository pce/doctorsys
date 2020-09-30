#include "screen.h"
#include "system.h"

/*
System& SystemFactory() {
#if defined(OS_DARWIN)
    return SystemDarwin;
#endif
#if defined(OS_LINUX)
    return SystemLinux;
#endif
}
*/

int main() {
  System sys; // = SystemFactory();
  Screen::Display(sys);
}