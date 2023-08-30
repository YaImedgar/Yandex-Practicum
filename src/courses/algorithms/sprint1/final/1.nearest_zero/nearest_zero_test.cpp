#include "nearest_zero.hpp"
#include <gtest/gtest.h>

namespace sprint1 {

struct NearestZero {
  const std::vector<int32_t> sequence;
  const std::vector<int32_t> expected;
};

class NearestZeroTest : public ::testing::TestWithParam<NearestZero> {};

TEST_P(NearestZeroTest, MyTestCase) {
  const auto [sequence, expected] = GetParam();

  auto result = GetNearestZeroSequence(sequence);

  EXPECT_EQ(result, expected);
}

std::vector<NearestZero> NormalNearestZeroTestValues{
    NearestZero{
        .sequence = {0, 1, 4, 9, 0},
        .expected = {0, 1, 2, 1, 0},
    },
    NearestZero{
        .sequence = {0, 7, 9, 4, 8, 20},
        .expected = {0, 1, 2, 3, 4, 5},
    },
    NearestZero{
        .sequence = {},
        .expected = {},
    },
    NearestZero{
        .sequence = {0},
        .expected = {0},
    },
    NearestZero{
        .sequence = {5, 4, 3, 2, 1, 0},
        .expected = {5, 4, 3, 2, 1, 0},
    },
};

INSTANTIATE_TEST_SUITE_P(NearestZero, NearestZeroTest,
                         ::testing::ValuesIn(NormalNearestZeroTestValues));

}  // namespace sprint1