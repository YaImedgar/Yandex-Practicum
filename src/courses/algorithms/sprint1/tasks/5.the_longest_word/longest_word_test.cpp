#include <gtest/gtest.h>
#include "longest_word.hpp"

namespace sprint1 {

struct LongestWord {
  const std::vector<std::string> words;
  const std::string expected;
};

class LongestWordTest : public ::testing::TestWithParam<LongestWord> {};

TEST_P(LongestWordTest, MyTestCase) {
  const auto [words, expected] = GetParam();

  auto result = GetLongestWord(words);

  EXPECT_EQ(result, expected);
}

std::vector<LongestWord> NormalLongestWordTestValues{
    LongestWord{
        .words = {"i", "love", "segment", "tree"},
        .expected = "segment",
    },
    LongestWord{
        .words = {"frog", "jumps", "from", "river"},
        .expected = "jumps",
    },
    LongestWord{
        .words = {},
        .expected = "",
    },
};

INSTANTIATE_TEST_SUITE_P(LongestWord, LongestWordTest,
                         ::testing::ValuesIn(NormalLongestWordTestValues));

}  // namespace sprint1