#include "literal.h"

Literal::Literal() : value("null") {}

StringLiteral::StringLiteral(const std::string& v) : value(v) {}

NumberLiteral::NumberLiteral(const double v) : value(v) {}