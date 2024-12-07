#include <string>
#include <vector>
#include "tokens.h"

#ifndef SCANNER_H
#define SCANNER_H



class Scanner {
    std::string source;
    std::vector<Token> tokens = {};
    int start = 0;
    int current = 0;
    int line = 1;

    explicit Scanner(const std::string &source);

    std::vector<Token> ScanTokens();
    Token scanToken();
    void addToken(Token token);
    bool checkIfEnd();
};



#endif //SCANNER_H
