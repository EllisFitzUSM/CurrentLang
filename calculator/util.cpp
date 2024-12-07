#include <iostream>
#include <ostream>
#include <string>

using namespace std;

void error(int line, int column, const string &func, const string &msg) {
    cerr << "[Line: " << line << "| Char: " << column << "] Error in " << func << ": " << msg << endl;
    exit(1);
}