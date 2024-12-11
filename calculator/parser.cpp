//
// Created by PC on 12/11/2024.
//

#include "parser.h"

Parser::Parser(std::vector<Token> &tokens) : tokens(tokens) {}

bool Parser::checkIfEnd() const {
    return current >= tokens.size();
}

bool Parser::match(const std::vector<TokenType> &types) {
    for (TokenType type : types) {
        if (check(type)) {
            next();
            return true;
        }
    }
    return false;
}

bool Parser::check(const TokenType type) const {
    if (checkIfEnd()) {
        return false;
    }
    return peekCurrent().type == type;
}

// TODO: All these Token returns need to be references/pointers.
Token Parser::peekCurrent() const {
    return tokens.at(current);
}

Token Parser::next() {
    if (!checkIfEnd()) {
        current++;
    }
    return previous();
}

Token Parser::previous() const {
    return tokens.at(current - 1);
}

Expression Parser::term() {
    Expression expr = factor();

    while (match({DASH, PLUS})) {
        Token op = previous();
        Expression right = factor();
        expr = BinaryOperation(expr, op, right);
    }
    return expr;
}

Expression Parser::factor() {
    Expression expr = unary();

    while (match({FORWARD_SLASH, STAR, MODULO})) {
        Token op = previous();
        Expression right = unary();
        expr = BinaryOperation(expr, op, right);
    }
    return expr;
}

Expression Parser::unary() {
    if (match({DASH})) {
        Token op = previous();
        Expression right = unary();
        return UnaryOperation(op, right);
    }
    return primary();
}

Expression Parser::primary() {
    if (match({NUMBER})) {
        return new Literal(previous().literal);
    }
}


