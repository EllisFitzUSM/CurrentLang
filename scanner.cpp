#include "scanner.h"
#include <string>
#include <iostream>

Scanner::Scanner(const std::string &source) {
    this->source = source;
}

std::vector<Token> Scanner::ScanTokens() {
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
        case '(':
            addToken()

    }

}

void Scanner::addToken(Token token) {
    tokens.push_back(token);
}
