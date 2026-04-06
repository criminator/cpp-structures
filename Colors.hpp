#pragma once

#include <string>

// Simple namespace for easy color printing using ANSI escape codes.

namespace Colors {
    inline std::string red(const std::string &text) {
        return "\033[91m" + text + "\033[0m";
    }

    inline std::string green(const std::string &text) {
        return "\033[92m" + text + "\033[0m";
    }

    inline std::string yellow(const std::string &text) {
        return "\033[93m" + text + "\033[0m";
    }

    inline std::string blue(const std::string &text) {
        return "\033[94m" + text + "\033[0m";
    }

    inline std::string magenta(const std::string &text) {
        return "\033[95m" + text + "\033[0m";
    }

    inline std::string cyan(const std::string &text) {
        return "\033[96m" + text + "\033[0m";
    }
};
