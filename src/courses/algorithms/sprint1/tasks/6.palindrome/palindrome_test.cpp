#include <gtest/gtest.h>
#include "palindrome.hpp"

namespace sprint1 {

TEST(IsPalindromeTest, BlankString) {
  EXPECT_EQ(IsPalindrome(""), true);
  EXPECT_EQ(IsPalindrome("   "), true);
  EXPECT_EQ(IsPalindrome("  "), true);
}

TEST(IsPalindromeTest, IsPalindrome) {
  EXPECT_EQ(IsPalindrome("a"), true);
  EXPECT_EQ(IsPalindrome("apa"), true);
  EXPECT_EQ(IsPalindrome("A man, a plan, a canal: Panama"), true);
}

TEST(IsPalindromeTest, IsNotPalindrome) {
  EXPECT_EQ(IsPalindrome("ab"), false);
  EXPECT_EQ(IsPalindrome("ba"), false);
  EXPECT_EQ(IsPalindrome("abz"), false);
  EXPECT_EQ(IsPalindrome("10 ten animals I slam in a net 012"), false);
}

}  // namespace sprint1