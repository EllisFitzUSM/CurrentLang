#include <string>

#ifndef TOKENS_H
#define TOKENS_H

#endif //TOKENS_H

enum TokenType {
    LEFT_BRACE, RIGHT_BRACE,
    LEFT_PAREN, RIGHT_PAREN,
    FORWARD_SLASH,
    PLUS, DASH, STAR, MODULO,
    NUMBER,
};


class Token {
public:
    const TokenType type;
    const std::string lexeme;
    const int line;
    const int column;
    Token(const TokenType &type, const std::string &lexeme, const int &line, const int &column);
};