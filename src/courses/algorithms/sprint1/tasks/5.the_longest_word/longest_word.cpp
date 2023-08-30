#include "longest_word.hpp"

#include <algorithm>

namespace sprint1 {

std::string GetLongestWord(const std::vector<std::string>& words) {
  if (words.empty()) {
    return {};
  }

  auto word_it = words.begin();

  for (auto it = std::next(word_it); it < words.end(); ++it) {
    if (it->size() > word_it->size()) {
      word_it = it;
    }
  }

  return *word_it;
}

}  // namespace sprint1
