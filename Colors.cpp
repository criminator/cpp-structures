#include "Colors.hpp"

std::string red(const std::string &text) {
  return "\033[91m" + text + "\033[0m";
}

std::string green(const std::string &text) {
  return "\033[92m" + text + "\033[0m";
}
