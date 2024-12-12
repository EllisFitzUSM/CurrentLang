#include <memory>
#include "tokens.h"

#ifndef EXPRESSION_H
#define EXPRESSION_H

// This fix here is called forward declaration
template <typename T>
class Visitor;

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
public:
    const std::unique_ptr<Expression> leftOp;
    const Token& binOp;
    const std::unique_ptr<Expression> rightOp;
    BinaryOperation(std::unique_ptr<Expression> leftOp, Token& binOp, std::unique_ptr<Expression> rightOp);
    template <typename T>
    T accept(Visitor<T> &visitor);
};

// ( Expression )
class Grouping : public Expression {
public:
    const std::unique_ptr<Expression> innerExpression;
    explicit Grouping(std::unique_ptr<Expression> innerExpression);
    template<class T>
    T accept(Visitor<T> &visitor);
};

// -Expression
class UnaryOperation : public Expression {
public:
    const Token& unaryOp;
    const std::unique_ptr<Expression> operand;
    UnaryOperation(Token& unaryOp, std::unique_ptr<Expression> operand);
    template<class T>
    T accept(Visitor<T> &visitor);
};

// Numbers
class Literal : public Expression {
public:
    const LiteralVar& literal;
    explicit Literal(const LiteralVar& literal);
    template<class T>
    T accept(Visitor<T> &visitor);
};

#endif //EXPRESSION_H
