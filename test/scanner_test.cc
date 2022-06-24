#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "scanner.h"
#include "token.h"

// Demonstrate some basic assertions.
TEST(ScannerTest, Whitespace) {
  std::string source = R"(space    tabs				newlines




end)";

  Scanner s = Scanner(source);
  std::vector<Token> tokens = s.scan_tokens();
  ASSERT_EQ(tokens.size(), 5);
  ASSERT_EQ(tokens[0].to_string(), "IDENTIFIER space null");
  ASSERT_EQ(tokens[1].to_string(), "IDENTIFIER tabs null");
  ASSERT_EQ(tokens[2].to_string(), "IDENTIFIER newlines null");
  ASSERT_EQ(tokens[3].to_string(), "IDENTIFIER end null");
  ASSERT_EQ(tokens[4].to_string(), "EOF_TOK  null");
}