#include "expression.h"

BinaryOperation::BinaryOperation(std::unique_ptr<Expression> leftOp, Token &binOp, std::unique_ptr<Expression> rightOp)
    : leftOp(std::move(leftOp)), binOp(binOp), rightOp(std::move(rightOp)) {}

template <typename T>
T BinaryOperation::accept(Visitor<T> &visitor) {
    return visitor.visitBinaryOperation(this);
}

Grouping::Grouping(std::unique_ptr<Expression> innerExpression)
    : innerExpression(std::move(innerExpression)) {}

template <typename T>
T Grouping::accept(Visitor<T> &visitor) {
    return visitor.visitGrouping(this);
}

UnaryOperation::UnaryOperation(Token &unaryOp, std::unique_ptr<Expression> operand)
    : unaryOp(unaryOp), operand(std::move(operand)) {}

template <typename T>
T UnaryOperation::accept(Visitor<T> &visitor) {
    return visitor.visitUnaryOperation(this);
}

Literal::Literal(const LiteralVar& literal)
    : literal(literal) {}

template <typename T>
T Literal::accept(Visitor<T> &visitor) {
    return visitor.visitLiteral(this);
}