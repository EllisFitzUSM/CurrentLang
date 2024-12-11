#include <vector>
#include <memory>

#ifndef PARSER_H
#define PARSER_H

class Parser {
    std::vector<Token> &tokens;
    int current = 0;
public:
    explicit Parser(std::vector<Token> &tokens);
    std::unique_ptr<Expression>parse();

    std::unique_ptr<Expression> term();
    std::unique_ptr<Expression> factor();
    std::unique_ptr<Expression> unary();
    std::unique_ptr<Expression> primary();

    bool match(const std::vector<TokenType>& types);
    bool check(TokenType type) const;
    bool checkIfEnd() const;
    Token& next();
    Token& peekCurrent() const;
    Token& previous();
    Token& consume(TokenType type, const std::string& message);
};

#endif //PARSER_H
