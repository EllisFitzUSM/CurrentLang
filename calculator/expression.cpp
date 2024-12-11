#include "expression.h"

BinaryOperation::BinaryOperation(Expression& leftOp, Token &binOp, Expression& rightOp)
    : leftOp(leftOp), binOp(binOp), rightOp(rightOp) {}

template <typename T>
T BinaryOperation::accept(Visitor<T> &visitor) {
    return visitor.visitBinaryOperation(this);
}

Grouping::Grouping(Expression& innerExpression)
    : innerExpression(innerExpression) {}

template <typename T>
T Grouping::accept(Visitor<T> &visitor) {
    return visitor.visitGrouping(this);
}

UnaryOperation::UnaryOperation(Token &unaryOp, Expression &operand)
    : unaryOp(unaryOp), operand(operand) {}

template <typename T>
T UnaryOperation::accept(Visitor<T> &visitor) {
    return visitor.visitUnaryOperation(this);
}

Literal::Literal(LiteralType& literal)
    : literal(literal) {}

template <typename T>
T Literal::accept(Visitor<T> &visitor) {
    return visitor.visitLiteral(this);
}