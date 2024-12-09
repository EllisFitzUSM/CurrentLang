#include <iostream>
#include <ostream>
#include <string>

using namespace std;

static bool hadError = false;

void error(int line, int column, const string &func, const string &msg) {
    cerr << "[Line: " << line << "| Char: " << column << "] Error in " << func << ": " << msg << endl;
    hadError = true;
    // exit(1); Refer to 4.5.1 https://craftinginterpreters.com/scanning.html
    // "we keep scanning if finding an error"
}