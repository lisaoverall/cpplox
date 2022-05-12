#include "literal.h"

Literal::Literal() : value("") {}

StringLiteral::StringLiteral(const std::string& v) : value(v) {}

NumberLiteral::NumberLiteral(const double v) : value(v) {}