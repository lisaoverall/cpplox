#ifndef LOX_H_
#define LOX_H_

#include <iostream>
#include <string>

namespace lox {
    extern bool had_error;
    void report(int line, const std::string& where, const std::string& message);
    void error(int line, const std::string& message);
};

#endif  // LOX_H_