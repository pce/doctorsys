#ifndef SCREEN_H
#define SCREEN_H

#include <curses.h>

// #include "process.h"
#include "system.h"

namespace Screen {
    void Setup();

    void Display(std::shared_ptr<System> sys);
    void DisplaySystem(std::shared_ptr<System> sys, WINDOW* window, int count);
    //void DisplayProcesses(std::vector<Process>& processes, WINDOW* window, int n);
    void Update();

// void DisplayProcesses(std::vector<Process>& processes, WINDOW* window, int n);
// std::string ProgressBar(float percent);
};

#endif