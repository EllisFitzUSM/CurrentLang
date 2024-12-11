#include "scanner.h"
#include <format>
#include <string>
#include <iostream>
#include "util.cpp"

Scanner::Scanner(const std::string &source) {
    this->source = source;
}

std::vector<Token> Scanner::scanTokens() {
    while (!checkIfEnd()) {
        start = current;
        scanToken();
    }
    return tokens;
}

void Scanner::scanToken() {
    switch (char c = next()) {
        case '(':
            addToken(LEFT_PAREN);
        case ')':
            addToken(RIGHT_PAREN);
        case '/':
            // This is for comments, but we aren't doing comments right now. I thought including it would be a good way to look for the future.
            if (match('/')) {
                while (peek() != '\n' && !checkIfEnd()) next();
            }
            else {
                addToken(FORWARD_SLASH);
            }
        case '+':
            addToken(PLUS);
        case '-':
            addToken(DASH);
        case '*':
            addToken(STAR);
        case '%':
            addToken(MODULO);
        case ' ':
        case '\r':
        case '\t':
            break;
        case '\n':
            line++;
        default:
            if (isdigit(c)) {
                number();
            }
            else {
                parse_err(line, current, "scanToken()", std::format("Unexpected character {}", c));
            }
    }
}

bool Scanner::checkIfEnd() const {
    return current >= source.length();
}

char Scanner::next() {
    if (!checkIfEnd()) {
        return source.at(current++);
    }
    return '\0'; // I believe this should be unreachable
}

char Scanner::peek() const {
    if (checkIfEnd()) return '\0';
    return source.at(current);
}

char Scanner::peekNext() const {
    if (current + 1 >= source.length()) return '\0';
    return source.at(current + 1);
}

// Optimization could be made here since this function is only using forward slash ATM.
bool Scanner::match(const char expected) {
    if (checkIfEnd()) return false;
    if (source.at(current) != expected) return false;
    // ^ This is technically peek
    current++;
    return true;
}

void Scanner::addToken(const TokenType type) {
    addToken(type, 0);
}

void Scanner::addToken(const TokenType type, const LiteralType literal) {
    std::string text = source.substr(start, current);
    tokens.emplace_back(type, text, line, current, literal);
}

void Scanner::number() {
    while (isdigit(peek())) {
        next();
    }

    if (peek() == '.' && isdigit(peekNext())) {
        next();

        while (isdigit(peek())) {
            next();
        }
    }
    addToken(NUMBER, std::stod(source.substr(start, current)));
}
