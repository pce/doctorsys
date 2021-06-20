#include "format.h"

#include <string>

using std::string;

string Format::ElapsedTime(long seconds) {
  int h = seconds / 3600;
  seconds = seconds % 3600;
  int min = seconds / 60;
  seconds = seconds % 60;
  int sec = seconds;
  int days{0};

  if (h > 24) {
    days = h / 24;
    h = h % 24;
  }

  std::string fh = std::to_string(h);
  if (fh.length() < 2) {
    fh = "0" + fh;
  }

  std::string fm = std::to_string(min);
  if (fm.length() < 2) {
    fm = "0" + fm;
  }

  std::string fs = std::to_string(sec);
  if (fs.length() < 2) {
    fs = "0" + fs;
  }

  if (days > 0) {
    return string(std::to_string(days) + " Days, " + fh + ":" + fm + ":" + fs);
  }
  return string(fh + ":" + fm + ":" + fs);
}