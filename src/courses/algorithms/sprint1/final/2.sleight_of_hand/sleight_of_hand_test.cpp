#include "sleight_of_hand.hpp"
#include <gtest/gtest.h>
#include <array>

namespace sprint1 {

struct SleightOfHand {
  const Map<4, 4> map{};
  const int32_t num_of_keys_per_player{};
  const int32_t expected{};
};

class SleightOfHandTest : public ::testing::TestWithParam<SleightOfHand> {};

TEST_P(SleightOfHandTest, MyTestCase) {
  const auto [map, num_of_keys_per_player, expected] = GetParam();

  auto result = GetMaxNumberOfPoints(map, num_of_keys_per_player);

  EXPECT_EQ(result, expected);
}

std::vector<SleightOfHand> NormalSleightOfHandTestValues{
    SleightOfHand{
        .map =
            Map<4, 4>{
                std::array<char16_t, 4>{'1', '2', '3', '1'},
                std::array<char16_t, 4>{'2', '.', '.', '2'},
                std::array<char16_t, 4>{'2', '.', '.', '2'},
                std::array<char16_t, 4>{'2', '.', '.', '2'},
            },
        .num_of_keys_per_player = 3,
        .expected = 2,
    },
    SleightOfHand{
        .map =
            Map<4, 4>{
                std::array<char16_t, 4>{'1', '1', '1', '1'},
                std::array<char16_t, 4>{'9', '9', '9', '9'},
                std::array<char16_t, 4>{'1', '1', '1', '1'},
                std::array<char16_t, 4>{'9', '9', '1', '1'},
            },
        .num_of_keys_per_player = 4,
        .expected = 1,
    },
    SleightOfHand{
        .map =
            Map<4, 4>{
                std::array<char16_t, 4>{'1', '1', '1', '1'},
                std::array<char16_t, 4>{'1', '1', '1', '1'},
                std::array<char16_t, 4>{'1', '1', '1', '1'},
                std::array<char16_t, 4>{'1', '1', '1', '1'},
            },
        .num_of_keys_per_player = 4,
        .expected = 0,
    },
};

INSTANTIATE_TEST_SUITE_P(SleightOfHand, SleightOfHandTest,
                         ::testing::ValuesIn(NormalSleightOfHandTestValues));

TEST(SleightOfHandTest, Test1) {
  Map<1, 1> map{};
  map[0][0] = '1';

  auto result = GetMaxNumberOfPoints(map, 1, 1);
  EXPECT_EQ(result, 1);
}

}  // namespace sprint1