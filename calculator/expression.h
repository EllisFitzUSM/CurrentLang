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
    const Expression& leftOp;
    const Token& binOp;
    const Expression& rightOp;
public:
    BinaryOperation(Expression& leftOp, Token& binOp, Expression& rightOp);
    template <typename T>
    T accept(Visitor<T> &visitor);
};

// ( Expression )
class Grouping : public Expression {
    const Expression& innerExpression;
public:
    explicit Grouping(Expression& innerExpression);
    template<class T>
    T accept(Visitor<T> &visitor);
};

// -Expression
class UnaryOperation : public Expression {
    const Token& unaryOp;
    const Expression& operand;
public:
    UnaryOperation(Token& unaryOp, Expression& operand);
    template<class T>
    T accept(Visitor<T> &visitor);
};

// Numbers
class Literal : public Expression {
    const LiteralType& literal;
public:
    explicit Literal(LiteralType& literal);
    template<class T>
    T accept(Visitor<T> &visitor);
};

#endif //EXPRESSION_H
