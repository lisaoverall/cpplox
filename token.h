#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>
#include <string>

#define ENUM_TOKENTYPES \
    X(LEFT_PAREN) \
    X(RIGHT_PAREN) \
    X(LEFT_BRACE) \
    X(RIGHT_BRACE) \
    X(COMMA) \
    X(DOT) \
    X(MINUS) \
    X(PLUS) \
    X(SEMICOLON) \
    X(SLASH) \
    X(STAR) \
    X(BANG) \
    X(BANG_EQUAL) \
    X(EQUAL) \
    X(EQUAL_EQUAL) \
    X(GREATER) \
    X(GREATER_EQUAL) \
    X(LESS) \
    X(LESS_EQUAL) \
    X(IDENTIFIER) \
    X(STRING) \
    X(NUMBER) \
    X(AND) \
    X(CLASS) \
    X(ELSE) \
    X(FALSE) \
    X(FUN) \
    X(FOR) \
    X(IF) \
    X(NIL) \
    X(OR) \
    X(PRINT) \
    X(RETURN) \
    X(SUPER) \
    X(THIS) \
    X(TRUE) \
    X(VAR) \
    X(WHILE) \
    X(EOF_TOK)

enum class TokenType {
    #define X(token_type) token_type,
    ENUM_TOKENTYPES
    #undef X
};

std::string token_type_to_string(const TokenType& token_type);

class Literal {
public:
    std::string to_string() const;
};

class Token {
public:
    const TokenType type;
    const std::string lexeme;
    const Literal literal;
    const int line;
    Token(TokenType t, const std::string& lxm, const Literal& ltrl, int ln);
    std::string to_string() const;
};

std::ostream& operator<<(std::ostream& os, const Token& t);

#endif  // TOKEN_H_