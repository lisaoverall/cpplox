#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
#include <vector>

#include "token.h"

class Scanner {
public:
    Scanner(std::string source);
    std::vector<Token> scan_tokens();    
};

#endif  // SCANNER_H_