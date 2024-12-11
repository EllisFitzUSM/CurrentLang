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

public:
    explicit Scanner(const std::string &source);
    std::vector<Token> scanTokens();
    void scanToken();
    void addToken(TokenType type);
    void addToken(TokenType type, LiteralVar literal);
    char next();
    bool checkIfEnd() const;
    bool match(char expected);
    char peek() const;
    char peekNext() const;

    // Literal Functions
    void number();
};

#endif //SCANNER_H
