#include <gtest/gtest.h>
#include <three_of_even_or_odd.hpp>

namespace sprint1 {

constexpr auto kWin = "WIN";
constexpr auto kFail = "FAIL";

TEST(CalculateThreeOfEvenOrOddTest, Test1) {
  const auto result = ThreeOfEvenOrOdd(7, 11, 7);
  EXPECT_EQ(result, kWin);
}

TEST(CalculateThreeOfEvenOrOddTest, Test2) {
  const auto result = ThreeOfEvenOrOdd(6, -2, 0);
  EXPECT_EQ(result, kWin);
}

TEST(CalculateThreeOfEvenOrOddTest, Test3) {
  const auto result = ThreeOfEvenOrOdd(1, 2, 3);
  EXPECT_EQ(result, kFail);
}

}  // namespace sprint1