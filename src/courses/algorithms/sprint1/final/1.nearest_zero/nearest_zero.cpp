#include "nearest_zero.hpp"

#include <limits>
#include <optional>

namespace sprint1 {

std::vector<int32_t> GetNearestZeroSequence(
    const std::vector<int32_t>& sequence) {
  std::vector<int32_t> nearest_to_zero(sequence.size(),
                                       std::numeric_limits<int32_t>::max());

  std::optional<int32_t> left_zero_position;
  for (int32_t i = 0; i < static_cast<int32_t>(sequence.size()); ++i) {
    if (sequence[i] == 0) {
      nearest_to_zero[i] = 0;
      left_zero_position = i;
      continue;
    }

    if (left_zero_position) {
      nearest_to_zero[i] =
          std::min(nearest_to_zero[i], i - left_zero_position.value());
    }
  }

  std::optional<int32_t> right_zero_position;
  for (int32_t i = sequence.size() - 1; i >= 0; --i) {
    if (sequence[i] == 0) {
      nearest_to_zero[i] = 0;
      right_zero_position = i;
      continue;
    }

    if (right_zero_position) {
      nearest_to_zero[i] =
          std::min(nearest_to_zero[i], right_zero_position.value() - i);
    }
  }

  return nearest_to_zero;
}

}  // namespace sprint1