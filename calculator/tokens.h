#include <map>
#include <string>

#ifndef TOKENS_H
#define TOKENS_H

#endif //TOKENS_H

enum TokenType {
    // Scope
    LEFT_BRACE, RIGHT_BRACE,
    LEFT_PAREN, RIGHT_PAREN,

    // Binary Operators
    PLUS, DASH, STAR, MODULO, FORWARD_SLASH,

    // Literals
    NUMBER,
};

inline std::map<TokenType, std::string> tokenStringMap = {
    { LEFT_BRACE, "LEFT_BRACE" },
    { RIGHT_BRACE, "RIGHT_BRACE" },
    { LEFT_PAREN, "LEFT_PAREN" },
    { RIGHT_PAREN, "RIGHT_PAREN" },
    { FORWARD_SLASH, "FORWARD_SLASH" },
    { PLUS, "PLUS" },
    { DASH, "DASH" },
    { STAR, "STAR" },
    { MODULO, "MODULO" },
    { NUMBER, "NUMBER" }
};

inline std::map<TokenType, char> tokenLexemeMap = {
    { LEFT_BRACE, '{' },
    { RIGHT_BRACE, '}' },
    { LEFT_PAREN, '(' },
    { RIGHT_PAREN, ')' },
    { FORWARD_SLASH, '/' },
    { PLUS, '+' },
    { DASH, '-' },
    { STAR, '*' },
    { MODULO, '%' },
    { NUMBER, '' }
};

template <typename T>
class Token {
public:
    const TokenType type;
    const std::string lexeme;
    const int line;
    const int column;
    const T literal;
    Token(const TokenType &type, const std::string &lexeme, const int &line, const int &column);
};