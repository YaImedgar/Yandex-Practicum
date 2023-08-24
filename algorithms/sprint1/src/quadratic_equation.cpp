#include "quadratic_equation.hpp"

namespace sprint1 {

int64_t CalculateTheQuadraticEquation(int32_t a, int32_t x, int32_t b,
                                      int32_t c) {
  return a * (x * x) + b * x + c;
}

}  // namespace sprint1