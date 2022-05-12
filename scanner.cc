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
    Literal literal = Literal();
    add_token(type, &literal);
}

void Scanner::add_token(TokenType type, Literal *literal) {
    std::string text = source.substr(start, current);
    Token token(type, text, literal, line);
    tokens.push_back(token);
}

bool Scanner::is_at_end() {
    return current >= source.length();
}

bool Scanner::match(char expected) {
    if (is_at_end()) return false;
    if (source[current] != expected) return false;
    current++;
    return true;
}

char Scanner::peek() {
    if (is_at_end()) return '\0';
    return source[current];
}

char Scanner::peek_next() {
    if (current + 1 >= source.length()) return '\0';
    return source[current+1];
}

void Scanner::string() {
    while (peek() != '"' && !is_at_end()) {
        if (peek() == '\n') line++;
        advance();
    }
    if (is_at_end()) {
        lox::error(line, "Unterminated string.");
        return;
    }
    advance(); // closing '"'
    // trim surrounding quotes
    std::string value = source.substr(start+1, current-1);
    StringLiteral string_literal = StringLiteral(value);
    add_token(TokenType::STRING, &string_literal);
}

void Scanner::number() {
    while(isdigit(peek())) advance();
    // look for a fractional part
    if (peek() == '.' && isdigit(peek_next())) {
        advance();
        while (isdigit(peek())) advance();
    }
    double d = std::stod(source.substr(start, current));
    NumberLiteral number_literal = NumberLiteral(d);
    add_token(TokenType::NUMBER, &number_literal);
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

        case '!': add_token(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG); break;
        case '=': add_token(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL); break;
        case '<': add_token(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER); break;
        case '>': add_token(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS); break;

        case '/':
            if (match('/')) { // comment goes until end of line
                while (peek() != '\n' && !is_at_end()) advance();
            } else {
                add_token(TokenType::SLASH);
            }
            break;

        case ' ':
        case '\r':
        case '\t':
            // ignore whitespace
            break;

        case '\n':
            line++;
            break;

        case '"': string(); break;

        default:
            if (isdigit(c)) {
                number();
            } else {
                lox::error(line, "Unexpected character.");
            }
            break;
    }
}

std::vector<Token> Scanner::scan_tokens() {
    while(!is_at_end()) {
        start = current;
        scan_token();
    }

    Literal literal = Literal();
    Token token(TokenType::EOF_TOK, "", &literal, line);
    tokens.push_back(token);
    return tokens;
}
