#ifndef SCREEN_H
#define SCREEN_H

#include <curses.h>

// #include "process.h"
#include "system.h"

namespace Screen {
    void Setup();
    void Display(System& sys);
    void Update();

// void Display(System& system, int n = 10);
// void DisplaySystem(System& system, WINDOW* window);
// void DisplayProcesses(std::vector<Process>& processes, WINDOW* window, int n);
// std::string ProgressBar(float percent);
};

#endif