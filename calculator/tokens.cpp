#include <string>
#include <iostream>
#include <map>
#include <utility>
#include "tokens.h"

Token::Token(const TokenType &type, std::string lexeme, const int &line, const int &column, const LiteralVar &literal)
    : type(type), lexeme(std::move(lexeme)), line(line), column(column), literal(literal) {}

std::ostream& operator<<(std::ostream &os, const TokenType &t) {
    return (os << tokenStringMap[t]);
}

std::ostream& operator<<(std::ostream &os, const Token &t) {
    return os << "Type: " << t.type <<  "\nLexeme: " << t.lexeme << "\nLine: " << t.line << "\nColumn: " << t.column;
}
