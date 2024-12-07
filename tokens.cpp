#include <string>
#include <iostream>
#include <map>
#include "tokens.h"

/**
 * @param type
 * @param lexeme
 * @param line
 * @param column
 */
Token::Token(const TokenType &type, const std::string &lexeme, const int &line, const int &column)
    : type(type), lexeme(lexeme), line(line), column(column) {}

std::map<TokenType, std::string> tokenTypeMap = {
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

std::ostream& operator<<(std::ostream &os, const TokenType &t) {
    return (os << tokenTypeMap[t]);
}

std::ostream& operator<<(std::ostream &os, const Token &t) {
    return (os << "Type: " << t.type <<  "\nLexeme: " << t.lexeme
        << "\nLine: " << t.line << "\nColumn: " << t.column);
}
