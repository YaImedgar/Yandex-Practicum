#pragma once

#include <array>
#include <cstdint>
#include <unordered_map>

namespace sprint1 {

constexpr auto kMaxAllowedChars = 9;

template <std::size_t RowSize, std::size_t ColumnSize>
using Map = std::array<std::array<char16_t, RowSize>, ColumnSize>;

template <std::size_t RowSize = 4, std::size_t ColumnSize = 4>
int32_t GetMaxNumberOfPoints(const Map<RowSize, ColumnSize>& map,
                             int32_t num_of_keys_per_player,
                             int32_t num_of_players = 2) {
  std::unordered_map<uint8_t, int32_t> num_of_map_values{};
  num_of_map_values.reserve(kMaxAllowedChars);

  for (const auto& column : map) {
    for (const auto cell : column) {
      ++num_of_map_values[cell];
    }
  }

  int32_t result{};

  const auto max_keys_per_team = num_of_players * num_of_keys_per_player;
  for (auto i = '1'; i <= '9'; ++i) {
    if (num_of_map_values.count(i) > 0 &&
        max_keys_per_team >= num_of_map_values.at(i)) {
      ++result;
    }
  }

  return result;
}

}  // namespace sprint1
