#include "palindrome.hpp"

namespace sprint1 {

bool IsPalindrome(const std::string& s){
  auto left_it = s.begin();
  auto right_it = std::prev(s.end());

  while (left_it < right_it){
    while (left_it < right_it && !std::isalnum(*left_it)){
        ++left_it;
    }

    while (right_it > left_it && !std::isalnum(*right_it)){
        --right_it;
    }

    if (std::tolower(*left_it) != std::tolower(*right_it)){
        return false;
    }

    ++left_it;
    --right_it;
  }

  return true;
}

}  // namespace sprint1