#include <iostream>
#include <ostream>
#include <string>

static bool hadError = false;

inline void parse_err(int line, int column, const std::string &func, const std::string &msg) {
    std::cerr << "[Line: " << line << "| Char: " << column << "] Error in " << func << ": " << msg << std::endl;
    hadError = true;
    // exit(1); Refer to 4.5.1 https://craftinginterpreters.com/scanning.html
    // "we keep scanning if finding an error"
}