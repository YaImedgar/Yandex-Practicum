#pragma once

#include <cstdint>
#include <vector>

namespace sprint1 {

struct Point {
  int32_t x{};
  int32_t y{};
};

using Map = std::vector<std::vector<int32_t>>;

std::vector<int32_t> GetPointNeighbors(const Map& map, const Point& point);

}  // namespace sprint1
