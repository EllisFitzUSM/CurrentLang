#include <iostream>
#include <chrono>
#include <string>

#include "expression.h"
#include "parser.h"
#include "scanner.h"

int sequential(const std::string &arg) {
    std::cout << "sequential";
    return 0;
}

int concurrent(const std::string &arg) {
    std::cout << "concurrent";
    return 0;
}

int parallel(const std::string &arg) {
    std::cout << "parallel";
    return 0;
}

typedef int (*RunMethod)(const std::string &arg);
RunMethod parseRunMethod(const std::string &arg) {
    if (arg == "-C" or arg == "-c") {
        return &concurrent;
    }
    if (arg == "-P" or arg == "-p") {
        return &parallel;
    }
    return &sequential;
}

int main(int argc, char *argv[]) {
    std::string runMethodStr;
    std::string expression;
    RunMethod method;
    int result;

    if (argc > 2) {
        std::cout << "Usage: ./main <Run method> <Expression>\n\t-S for Sequential\n\t-C for Concurrent\n\t-P for Parallel\nExpression: Infix using +-/*() tokens.";
        return 1;
    }

    if (argc == 2) {
        runMethodStr = argv[0];
        expression = argv[1];
        method = parseRunMethod(runMethodStr);
    }
    else {
        std::cout << "Run method:\n\t-S for Sequential\n\t-C for Concurrent\n\t-P for Parallel\nInput:";
        getline(std::cin, runMethodStr);
        method = parseRunMethod(runMethodStr);
        std::cout << "Expression: Infix using +-/*() tokens.\nInput:";
        getline(std::cin, expression);
    }

    std::vector<Token> tokens = Scanner(expression).scanTokens();
    auto parser = Parser(tokens);
    std::unique_ptr<Expression> expressionObj = parser.parse();


    method(expression);
    return 0;
}

