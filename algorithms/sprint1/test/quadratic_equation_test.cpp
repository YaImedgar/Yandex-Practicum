#include <gtest/gtest.h>
#include <quadratic_equation.hpp>

namespace sprint1 {

TEST(CalculateTheQuadraticEquationTest, Test1) {
  int64_t result = CalculateTheQuadraticEquation(-8, -5, -2, 7);
  EXPECT_EQ(result, -183);
}

TEST(CalculateTheQuadraticEquationTest, Test2) {
  int64_t result = CalculateTheQuadraticEquation(8, 2, 9, -10);
  EXPECT_EQ(result, 40);
}

}  // namespace sprint1
