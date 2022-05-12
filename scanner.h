#ifndef SCANNER_H_
#define SCANNER_H_

#include <cstdio>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "literal.h"
#include "lox.h"
#include "token.h"

static const std::map<std::string, TokenType> keywords = {
    {"and", TokenType::AND},
    {"class", TokenType::CLASS},
    {"else", TokenType::ELSE},
    {"false", TokenType::FALSE},
    {"for", TokenType::FOR},
    {"fun", TokenType::FUN},
    {"if", TokenType::IF},
    {"nil", TokenType::NIL},
    {"or", TokenType::OR},
    {"print", TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super", TokenType::SUPER},
    {"this", TokenType::THIS},
    {"true", TokenType::TRUE},
    {"var", TokenType::VAR},
    {"while", TokenType::WHILE}
};

class Scanner
{
public:
    Scanner(const std::string &src);
    std::vector<Token> scan_tokens();

private:
    const std::string source;
    std::vector<Token> tokens{};
    int start{};
    int current{};
    int line{1};
    char advance();
    void add_token(TokenType type);
    void add_token(TokenType type, Literal *literal);
    bool is_at_end();
    bool match(char expected);
    char peek();
    char peek_next();
    void string();
    void number();
    void identifier();
    void scan_token();
};

#endif // SCANNER_H_