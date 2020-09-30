#include <curses.h>
#include <chrono>
#include <string>
#include <thread>
#include <vector>

#include "screen.h"
#include "format.h"


// std::string;
// std::to_string;


void Screen::Setup() {

}


void Screen::Update() {

}

/*
std::string NCursesDisplay::ProgressBar(float percent) {
  std::string result{"0%"};
  int size{50};
  float bars{percent * size};

  for (int i{0}; i < size; ++i) {
    result += i <= bars ? '|' : ' ';
  }

  string display{to_string(percent * 100).substr(0, 4)};
  if (percent < 0.1 || percent == 1.0)
    display = " " + to_string(percent * 100).substr(0, 3);
  return result + " " + display + "/100%";
}
*/

void Screen::DisplaySystem(System& sys, WINDOW* window, int count) {
  int row{0};
  wattron(window, COLOR_PAIR(1));

  row++;
  const char chars[] = { '|','/','-','\\' }; 
  // mvaddch(row, 2, chars[count%4]);
  wmove(window, row, 2) == -1 ? -1 : waddch(window, chars[count%4]);

  mvwprintw(window, ++row, 2,
            ("Up Time: " + Format::ElapsedTime(sys.UpTime())).c_str());
  wrefresh(window);

}

void Screen::Display(System& sys) {
  int n = 10;
  initscr();      // start ncurses
  noecho();       // do not print input values
  cbreak();       // terminate ncurses on ctrl + c
  start_color();  // enable color
  // curs_set(0);

  int x_max{getmaxx(stdscr)};
  WINDOW* system_window = newwin(9, x_max - 1, 0, 0);
  // WINDOW* process_window =
  //     newwin(3 + n, x_max - 1, system_window->_maxy + 1, 0);
  int count = 0;
  bool is_running = true;
  while (is_running) {
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    box(system_window, 0, 0);
    // box(process_window, 0, 0);
    DisplaySystem(sys, system_window, count);
    // DisplayProcesses(system.Processes(), process_window, n);
    
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
    count++;
  }
  endwin();
}


