#ifndef LITERAL_H_
#define LITERAL_H_

#include <string>

class Literal {
public:
    const std::string value;
    Literal();
};

class StringLiteral : public Literal {
public:
    const std::string value;
    StringLiteral(const std::string& v);
};

class NumberLiteral : public Literal {
public:
    const double value;
    NumberLiteral(const double value);
};

#endif