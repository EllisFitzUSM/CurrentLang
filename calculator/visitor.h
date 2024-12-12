#ifndef VISITOR_H
#define VISITOR_H

#include "expression.h"

template <typename T>
class Visitor {
public:
    virtual ~Visitor() = default;
    virtual T visitBinaryOperation(BinaryOperation& binOp) = 0;
    virtual T visitUnaryOperation(UnaryOperation& uOp) = 0;
    virtual T visitGrouping(Grouping& group) = 0;
    virtual T visitLiteral(Literal& literal) = 0;
};

template <typename T>
class Evaluator : Visitor<T> {
    T visitBinaryOperation(BinaryOperation& binOp);
    T visitUnaryOperation(UnaryOperation& uOp);
    T visitGrouping(Grouping& group);
    T visitLiteral(Literal& literal);
private:
    T evaluate(Expression& expr);
};

#endif //VISITOR_H
