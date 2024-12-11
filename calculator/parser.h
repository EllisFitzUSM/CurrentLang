#include <vector>
#include "expression.h"

#ifndef PARSER_H
#define PARSER_H

class Parser {
    std::vector<Token> &tokens;
    int current = 0;
public:
    Parser(std::vector<Token> &tokens);

    Expression term();
    Expression factor();
    Expression unary();
    Expression primary();

    bool match(const std::vector<TokenType>& types);
    bool check(TokenType type) const;
    bool checkIfEnd() const;
    Token next();
    Token peekCurrent() const;
    Token previous() const;
};

#endif //PARSER_H
