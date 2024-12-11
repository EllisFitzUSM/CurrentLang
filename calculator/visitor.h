#ifndef VISITOR_H
#define VISITOR_H

template <typename T>
class Visitor {
public:
    virtual ~Visitor() = default;
    virtual T visitBinaryOperation() = 0;
    virtual T visitUnaryOperation() = 0;
    virtual T visitGrouping() = 0;
    virtual T visitLiteral() = 0;
};

template <typename T>
class Evaluator : Visitor<T> {
};

#endif //VISITOR_H
