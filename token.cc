#include "token.h"

std::string token_type_to_string(const TokenType& token_type) {
    switch (token_type) {
        #define X(token_type) case TokenType::token_type : return #token_type;
        ENUM_TOKENTYPES
        #undef X
    }
}

Token::Token(TokenType t, const std::string& lxm, const Literal *ltrl, int ln) :
        type(t), lexeme(lxm), literal(std::make_shared<Literal>(*ltrl)), line(ln) {};

std::string Token::to_string() const {
    return token_type_to_string(type) + " " + lexeme + " " + literal->value;
}

std::ostream& operator<<(std::ostream& os, const Token& t) {
    // os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}