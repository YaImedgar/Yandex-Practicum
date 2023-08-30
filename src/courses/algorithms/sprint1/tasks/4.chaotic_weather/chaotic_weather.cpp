#include "chaotic_weather.hpp"

namespace sprint1 {

int32_t CountChaoticDays(const std::vector<int32_t>& days) {
  int32_t chaotic_days{};

  for (auto i = 0ul; i < days.size(); ++i) {
    const bool is_higher_than_prev = i == 0 || days[i] > days[i - 1];
    const bool is_higher_than_next =
        i == days.size() - 1 || days[i] > days[i + 1];
    if (is_higher_than_prev && is_higher_than_next) {
      ++chaotic_days;
    }
  }

  return chaotic_days;
}

}  // namespace sprint1