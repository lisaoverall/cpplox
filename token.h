#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>

class Token {
public:
    Token();
};

std::ostream& operator<<(std::ostream& os, const Token& t);

#endif  // TOKEN_H_