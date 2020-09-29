#include <curses.h>
#include <chrono>
#include <string>
#include <thread>
#include <vector>

#include "screen.h"


// std::string;
// std::to_string;


void Screen::Setup() {

}


void Screen::Update() {

}

void Screen::Display(System& sys) {
  int n = 10;
  initscr();      // start ncurses
  noecho();       // do not print input values
  cbreak();       // terminate ncurses on ctrl + c
  start_color();  // enable color

  int x_max{getmaxx(stdscr)};
  WINDOW* system_window = newwin(9, x_max - 1, 0, 0);
  // WINDOW* process_window =
  //     newwin(3 + n, x_max - 1, system_window->_maxy + 1, 0);

  bool is_running = true;
  while (is_running) {
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    box(system_window, 0, 0);
    // box(process_window, 0, 0);
    // DisplaySystem(system, system_window);
    // DisplayProcesses(system.Processes(), process_window, n);
    sys.UpTime();
    wrefresh(system_window);
    // wrefresh(process_window);
    refresh();
    // non-blocking input
    nodelay(stdscr, true);
    if (getch() == 'q') {
      is_running = false;
    }
    // 1 sec. sleep
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  endwin();
}


