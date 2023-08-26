#include <gtest/gtest.h>
#include <point_neighbors.hpp>

namespace sprint1 {

struct NeighborsTest {
  const Map& map;
  const Point point;
  const std::vector<int32_t> expected;
};

class PointNeighborsTest : public ::testing::TestWithParam<NeighborsTest> {};

TEST_P(PointNeighborsTest, MyTestCase) {
  const auto [map, point, expected] = GetParam();

  auto result = GetPointNeighbors(map, point);

  EXPECT_EQ(result, expected);
}


const Map SingleMap = {
    {1},
};

const Map DefaultMap = {
    {1, 2, 3},
    {0, 2, 6},
    {7, 4, 1},
    {2, 7, 0},
};

std::vector<NeighborsTest> NormalTestValues{
    NeighborsTest{
        .map = DefaultMap,
        .point = Point{0, 0},
        .expected = {0, 2},
    },
    NeighborsTest{
        .map = DefaultMap,
        .point = Point{0, 1},
        .expected = {1, 2, 3},
    },
    NeighborsTest{
        .map = DefaultMap,
        .point = Point{0, 2},
        .expected = {2, 6},
    },
    NeighborsTest{
        .map = DefaultMap,
        .point = Point{1, 0},
        .expected = {1, 2, 7},
    },
    NeighborsTest{
        .map = DefaultMap,
        .point = Point{2, 0},
        .expected = {0, 2, 4},
    },
    NeighborsTest{
        .map = DefaultMap,
        .point = Point{3, 0},
        .expected = {7, 7},
    },
    NeighborsTest{
        .map = DefaultMap,
        .point = Point{3, 1},
        .expected = {0, 2, 4},
    },
    NeighborsTest{
        .map = DefaultMap,
        .point = Point{3, 2},
        .expected = {1, 7},
    },
    NeighborsTest{
        .map = DefaultMap,
        .point = Point{2, 2},
        .expected = {0, 4, 6},
    },
    NeighborsTest{
        .map = DefaultMap,
        .point = Point{1, 2},
        .expected = {1, 2, 3},
    },
    NeighborsTest{
        .map = SingleMap,
        .point = Point{0, 0},
        .expected = {},
    },
};

std::vector<NeighborsTest> UndefinedTestValues{
    NeighborsTest{
        .map = SingleMap,
        .point = Point{-1, 0},
        .expected = {},
    },
    NeighborsTest{
        .map = SingleMap,
        .point = Point{0, -1},
        .expected = {},
    },
    NeighborsTest{
        .map = SingleMap,
        .point = Point{1, 0},
        .expected = {},
    },
    NeighborsTest{
        .map = SingleMap,
        .point = Point{0, 1},
        .expected = {},
    },
};

INSTANTIATE_TEST_SUITE_P(NormalNeighbors, PointNeighborsTest,
                         ::testing::ValuesIn(NormalTestValues));

INSTANTIATE_TEST_SUITE_P(BadNeighbors, PointNeighborsTest,
                         ::testing::ValuesIn(UndefinedTestValues));

}  // namespace sprint1