#include "gtest/gtest.h"
#define NAME "bob"


TEST(Macro, identifier_is_substituted) {
  ASSERT_EQ("bob", NAME);
}

#include <string>
using std::string;

string stack();

TEST(Macro, conditional) {
  #define fuzz 
  //uncomment the line below will makes the test failed
  //#define buzz 
  ASSERT_EQ("fuzz", stack());
}

string stack() {
  string stack{""};

  #ifdef fuzz
    stack += "fuzz";
  #else
    stack += "";
  #endif

  #ifdef buzz
    stack += "buzz";
  #else
    stack += "";
  #endif

  return stack;
}


TEST(Macro, use_if_0_to_skip_compiling) {
  #if 0
    undefinedVar = 5;
  #endif
}


TEST(Macro, include_header_files) {
  #include "run.h"

  ASSERT_EQ(5, run(5));
  ASSERT_EQ(10, run(5.2));
}



