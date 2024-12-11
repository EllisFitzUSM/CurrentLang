#include <map>
#include <string>
#include <variant>

#ifndef TOKENS_H
#define TOKENS_H

enum TokenType {
    // Scope
    LEFT_PAREN, RIGHT_PAREN,

    // Binary Operators
    PLUS, DASH, STAR, MODULO, FORWARD_SLASH,

    // Literals
    NUMBER,

    EOF_T
};

inline std::map<TokenType, std::string> tokenStringMap = {
    { LEFT_PAREN, "LEFT_PAREN" },
    { RIGHT_PAREN, "RIGHT_PAREN" },
    { FORWARD_SLASH, "FORWARD_SLASH" },
    { PLUS, "PLUS" },
    { DASH, "DASH" },
    { STAR, "STAR" },
    { MODULO, "MODULO" },
    { NUMBER, "NUMBER" },
    {EOF_T, "\0"}
};

/* Not sure if this is quite needed yet (or at all)
inline std::map<TokenType, char> tokenLexemeMap = {
    { LEFT_PAREN, '(' },
    { RIGHT_PAREN, ')' },
    { FORWARD_SLASH, '/' },
    { PLUS, '+' },
    { DASH, '-' },
    { STAR, '*' },
    { MODULO, '%' },
    { NUMBER, '\0' }
};
*/

using LiteralVar = std::variant<int, double>;
class Token {
public:
    const TokenType type;
    const std::string lexeme;
    const int line;
    const int column;
    const LiteralVar literal;
    Token(const TokenType &type, std::string lexeme, const int &line, const int &column, const LiteralVar &literal);
};

#endif //TOKENS_H