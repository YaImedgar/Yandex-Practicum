#include "three_of_even_or_odd.hpp"

namespace sprint1 {

constexpr auto kWin = "WIN";
constexpr auto kFail = "FAIL";

constexpr bool IsOdd(int32_t n) { return n & 1; }

std::string ThreeOfEvenOrOdd(int32_t a, int32_t b, int32_t c) {
  const bool is_odd_a = IsOdd(a);
  const bool is_odd_b = IsOdd(b);
  const bool is_odd_c = IsOdd(c);

  const bool is_same_even_or_odd = is_odd_a == is_odd_b && is_odd_b == is_odd_c;

  return is_same_even_or_odd ? kWin : kFail;
}

}  // namespace sprint1