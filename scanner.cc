#include "scanner.h"

Scanner::Scanner(const std::string& src) : source(src) {
    tokens = std::vector<Token>();
    start = 0;
    current = 0;
    line = 1;
}

char Scanner::advance() {
    return source[current++];
}

void Scanner::add_token(TokenType type) {
    add_token(type, nullptr);
}

void Scanner::add_token(TokenType type, Literal *literal) {
    std::string text = source.substr(start, current);
    Token token(type, text, literal, line);
    tokens.push_back(token);
}

void Scanner::scan_token() {
    char c = advance();
    switch (c) {
        case '(': add_token(TokenType::LEFT_PAREN); break;
        case ')': add_token(TokenType::RIGHT_PAREN); break;
        case '{': add_token(TokenType::LEFT_BRACE); break;
        case '}': add_token(TokenType::RIGHT_BRACE); break;
        case ',': add_token(TokenType::COMMA); break;
        case '.': add_token(TokenType::DOT); break;
        case '-': add_token(TokenType::MINUS); break;
        case '+': add_token(TokenType::PLUS); break;
        case ';': add_token(TokenType::SEMICOLON); break;
        case '*': add_token(TokenType::STAR); break;
        default: lox::error(line, "Unexpected character."); break;
    }
}

bool Scanner::is_at_end() {
    return current >= source.length();
}

std::vector<Token> Scanner::scan_tokens() {
    while(!is_at_end()) {
        start = current;
        scan_token();
    }

    Token token(TokenType::EOF_TOK, "", nullptr, line);
    tokens.push_back(token);
    return tokens;
}
