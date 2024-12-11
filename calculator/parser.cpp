//
// Created by PC on 12/11/2024.
//

#include "expression.h"
#include "parser.h"
#include <stdexcept>

Parser::Parser(std::vector<Token> &tokens) : tokens(tokens) {}

std::unique_ptr<Expression> Parser::parse() {
    try {
        return std::move(term());
    }
    catch (const std::exception& e) {
        return 0;
    }
}

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

Token& Parser::peekCurrent() const {
    return tokens.at(current);
}

Token& Parser::next() {
    if (!checkIfEnd()) {
        current++;
    }
    return previous();
}

Token& Parser::previous() {
    return tokens.at(current - 1);
}

std::unique_ptr<Expression> Parser::term() {
    std::unique_ptr<Expression> expr = factor();

    while (match({DASH, PLUS})) {
        Token& op = previous();
        std::unique_ptr<Expression> right = factor();
        expr = std::make_unique<BinaryOperation>(std::move(expr), op, std::move(right));
    }
    return expr;
}

std::unique_ptr<Expression> Parser::factor() {
    std::unique_ptr<Expression> expr = unary();

    while (match({FORWARD_SLASH, STAR, MODULO})) {
        Token& op = previous();
        std::unique_ptr<Expression> right = unary();
        expr = std::make_unique<BinaryOperation>(std::move(expr), op, std::move(right));
    }
    return expr;
}

std::unique_ptr<Expression> Parser::unary() {
    if (match({DASH})) {
        Token& op = previous();
        std::unique_ptr<Expression> right = unary();
        return std::make_unique<UnaryOperation>(op, std::move(right));
    }
    return primary();
}

std::unique_ptr<Expression> Parser::primary() {
    if (match({NUMBER})) {
        return std::make_unique<Literal>(previous().literal);
    }
    if (match({LEFT_PAREN})) {
        std::unique_ptr<Expression> expr = term();
        // consume()
        return std::make_unique<Grouping>(std::move(expr));
    }
    exit(1);
}

Token& Parser::consume(TokenType type, const std::string& message) {
    if (check({type})) {
        return next();
    }
    throw std::runtime_error(message);
}


