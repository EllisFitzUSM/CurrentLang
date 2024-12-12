//
// Created by PC on 12/10/2024.
//

#include "visitor.h"

template <typename T>
T Evaluator<T>::visitLiteral(Literal& literal) {
    return literal.literal;
}

template <typename T>
T Evaluator<T>::visitGrouping(Grouping& group) {
    return evaluate(group.innerExpression); // FIXME: I believe there is object slicing here once passed to evaluate.
}
template <typename T>
T Evaluator<T>::visitUnaryOperation(UnaryOperation& uOp) {
    T right = uOp.operand;
    switch (uOp.unaryOp.type) {
        case DASH:
            return -static_cast<double>(right);
    }
    return 0;
}
template <typename T>
T Evaluator<T>::visitBinaryOperation(BinaryOperation& binOp) {
    T left = evaluate(binOp.leftOp);
    T right = evaluate(binOp.rightOp);

    switch (binOp.binOp.type) {
        case DASH:
            return static_cast<double>(left) - static_cast<double>(right);
        case PLUS:
            return static_cast<double>(left) + static_cast<double>(right);
        case FORWARD_SLASH:
            return static_cast<double>(left) / static_cast<double>(right);
        case STAR:
            return static_cast<double>(left) * static_cast<double>(right);
        case MODULO:
            return static_cast<double>(left) % static_cast<double>(right);
    }
}

template<typename T>
T Evaluator<T>::evaluate(Expression &expr) { // FIXME: Change the expression to a pointer to an expression so we can cast to correct child class and call overridden accept function.
    return expr.accept(this);
}
