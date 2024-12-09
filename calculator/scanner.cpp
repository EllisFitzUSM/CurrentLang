#include "scanner.h"

#include <format>
#include <string>
#include <iostream>
#include "util.cpp"
using namespace std;

Scanner::Scanner(const std::string &source) {
    this->source = source;
}

vector<Token> Scanner::ScanTokens() {
    while (!checkIfEnd()) {
        start = current;
        scanToken();
    }
    return tokens;
}

bool Scanner::checkIfEnd() {
    return current >= source.length();
}

void Scanner::scanToken() {
    char c = '';
    switch (c) {
        case '{':
            addToken(LEFT_BRACE);
        case '}':
            addToken(RIGHT_BRACE);
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
                addToken(NUMBER);
            }
            else {
                error(line, current, "scanToken()", format("Unexpected character {}", c));
            }
    }
}

char Scanner::next() {
    if (!checkIfEnd()) {
        return source.at(current++);
    }
    return '\0'; // I believe this should be unreachable
}

// Optimization could be made here since this function is only using forward slash ATM.
bool Scanner::match(char expected) {
    if (checkIfEnd()) return false;
    if (source.at(current) != expected) return false;
    // ^ This is technically peek
    current++;
    return true;
}

void Scanner::addToken(TokenType type) {
    // Token token = Token(type, tokenLexemeMap[type], line, current);
    string text = source.substr(start, current);
    Token token = Token(type, text, line, current);
    tokens.push_back(token);
}

template <typename T>
void Scanner::addToken(TokenType type, T literal) {
    string text = source.substr(start, current);
    Token token = Token(type, text, line, current);
    tokens.push_back(token);
}

char Scanner::peek() {
    if (checkIfEnd()) return '\0';
    return source.at(current);
}

char Scanner::peekNext() const {
    if (current + 1 >= source.length()) return '\0';
    return source.at(current + 1);
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

    addToken(NUMBER, )

}
