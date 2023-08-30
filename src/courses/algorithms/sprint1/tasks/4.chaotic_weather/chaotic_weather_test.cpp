#include <gtest/gtest.h>
#include "chaotic_weather.hpp"

namespace sprint1 {

struct ChaoticWeather {
  const std::vector<int32_t> days;
  const int32_t expected;
};

class ChaoticWeatherTest : public ::testing::TestWithParam<ChaoticWeather> {};

TEST_P(ChaoticWeatherTest, MyTestCase) {
  const auto [days, expected] = GetParam();

  auto result = CountChaoticDays(days);

  EXPECT_EQ(result, expected);
}

std::vector<ChaoticWeather> NormalChaoticWeatherTestValues{
    ChaoticWeather{
        .days = {-1, -10, -8, 0, 2, 0, 5},
        .expected = 3,
    },
    ChaoticWeather{
        .days = {1, 2, 5, 4, 8},
        .expected = 2,
    },
    ChaoticWeather{
        .days = {0},
        .expected = 1,
    },
    ChaoticWeather{
        .days = {0, 1},
        .expected = 1,
    },
    ChaoticWeather{
        .days = {2, 1},
        .expected = 1,
    },
    ChaoticWeather{
        .days = {2, 1,2},
        .expected = 2,
    },
    ChaoticWeather{
        .days = {},
        .expected = 0,
    },
};

INSTANTIATE_TEST_SUITE_P(ChaoticWeather, ChaoticWeatherTest,
                         ::testing::ValuesIn(NormalChaoticWeatherTestValues));

}  // namespace sprint1