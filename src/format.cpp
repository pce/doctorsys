#include <string>

#include "format.h"

using std::string;

string Format::ElapsedTime(long seconds) {
  int h = seconds / 3600;
  seconds = seconds % 3600;
  int min = seconds / 60;
  seconds = seconds % 60;
  int sec = seconds;

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

  return string(fh + ":" + fm + ":" + fs);
}