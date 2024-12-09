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
    void scanToken();
    void addToken(TokenType type);

    template <typename T>
    void addToken(TokenType type, T literal);

    char next();
    bool checkIfEnd();
    bool match(char expected);
    char peek();
    char peekNext() const;

    // Literal Functions
    void number();
};

#endif //SCANNER_H
