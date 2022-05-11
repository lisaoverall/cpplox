#ifndef SCANNER_H_
#define SCANNER_H_

#include <cstdio>
#include <string>
#include <vector>

#include "lox.h"
#include "token.h"

class Scanner {
public:
    Scanner(const std::string& src);
    std::vector<Token> scan_tokens();
private:
    const std::string source;
    std::vector<Token> tokens;
    int start;
    int current;
    int line;
    char advance();
    void add_token(TokenType type);
    void add_token(TokenType type, Literal *literal);
    bool is_at_end();
    void scan_token();
};

#endif  // SCANNER_H_