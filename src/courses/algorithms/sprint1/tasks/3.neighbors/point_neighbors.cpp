#include "point_neighbors.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <optional>

namespace sprint1 {

constexpr auto kMaxPointNeighborsCount = 4;

bool PointIsOutOfMap(const Map& map, const Point& point) {
  const auto [x, y] = point;

  if (x < 0 || y < 0) {
    return true;
  }

  if (x > static_cast<int>(map.size()) - 1 ||
      y > static_cast<int>(map.back().size()) - 1) {
    return true;
  }

  return false;
}

std::optional<int32_t> TryGetPointValue(const Map& map, const Point& point) {
  if (PointIsOutOfMap(map, point)) {
    return std::nullopt;
  }

  return map.at(point.x).at(point.y);
}

std::vector<int32_t> GetPointNeighbors(const Map& map, const Point& point) {
  if (PointIsOutOfMap(map, point)) {
    return {};
  }

  std::vector<int32_t> real_neighbors{};
  real_neighbors.reserve(kMaxPointNeighborsCount);

  constexpr std::array<Point, 4> offsets{
      Point{0, -1},
      Point{0, 1},
      Point{-1, 0},
      Point{1, 0},
  };

  for (const auto& offset : offsets) {
    const Point neighbor_point = Point{
        .x = point.x + offset.x,
        .y = point.y + offset.y,
    };

    if (const auto neighbor = TryGetPointValue(map, neighbor_point)) {
      real_neighbors.emplace_back(neighbor.value());
    }
  }

  std::sort(real_neighbors.begin(), real_neighbors.end());

  return real_neighbors;
}

}  // namespace sprint1