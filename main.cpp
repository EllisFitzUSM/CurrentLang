#include <pthread.h>
#include <iostream>
#include <chrono>
#include <string>

using namespace std::chrono;
using namespace std;

int sequential(const string &arg) {
    cout << "sequential" << endl;
    return 0;
}

int concurrent(const string &arg) {
    cout << "concurrent" << endl;
    return 0;
}

int parallel(const string &arg) {
    cout << "parallel" << endl;
    return 0;
}

typedef int (*RunMethod)(const string &arg);

RunMethod parseRunMethod(const string &arg) {
    if (arg == "-C" or arg == "-c") {
        return &concurrent;
    }
    if (arg == "-P" or arg == "-p") {
        return &parallel;
    }
    return &sequential;
}

int main(int argc, char *argv[]) {
    string runMethodStr;
    string expression;
    RunMethod method;
    int result = 0;
    if (argc > 2) {
        cout << "Usage: ./main <Run method> <Expression>\n\t-S for Sequential\n\t-C for Concurrent\n\t-P for Parallel\nExpression: Infix using +-/*() tokens." << endl;
        return 1;
    }
    else if (argc == 2) {
        runMethodStr = argv[0];
        expression = argv[1];
        method = parseRunMethod(runMethodStr);
    }
    else {
        cout << "Run method:\n\t-S for Sequential\n\t-C for Concurrent\n\t-P for Parallel\nInput:";
        getline(cin, runMethodStr);
        method = parseRunMethod(runMethodStr);
        cout << "Expression: Infix using +-/*() tokens.\nInput:";
        getline(cin, expression);
    }

    method(expression);
    return 0;
}

