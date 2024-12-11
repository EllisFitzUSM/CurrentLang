#include <memory>
#include "tokens.h"
#include "visitor.h"

#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
    template <typename T>
    T accept(Visitor<T> &visitor);
};

// Comments showcase all possible tokens (for now).

/*
 * Add (+)
 * Sub (-)
 * Divide (/)
 * Multiply (*)
 */
class BinaryOperation : public Expression {
    const std::unique_ptr<Expression> leftOp;
    const Token& binOp;
    const std::unique_ptr<Expression> rightOp;
public:
    BinaryOperation(std::unique_ptr<Expression> leftOp, Token& binOp, std::unique_ptr<Expression> rightOp);
    template <typename T>
    T accept(Visitor<T> &visitor);
};

// ( Expression )
class Grouping : public Expression {
    const std::unique_ptr<Expression> innerExpression;
public:
    explicit Grouping(std::unique_ptr<Expression> innerExpression);
    template<class T>
    T accept(Visitor<T> &visitor);
};

// -Expression
class UnaryOperation : public Expression {
    const Token& unaryOp;
    const std::unique_ptr<Expression> operand;
public:
    UnaryOperation(Token& unaryOp, std::unique_ptr<Expression> operand);
    template<class T>
    T accept(Visitor<T> &visitor);
};

// Numbers
class Literal : public Expression {
    const LiteralVar& literal;
public:
    explicit Literal(const LiteralVar& literal);
    template<class T>
    T accept(Visitor<T> &visitor);
};

#endif //EXPRESSION_H
