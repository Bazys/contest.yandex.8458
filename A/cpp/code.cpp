#include <iostream>
#include <set>

int main() {
  std::string s, j;

  std::cin >> s;
  std::cin >> j;

  std::set<char> seen;
  for (auto letter : s) {
    seen.insert(letter);
  }

  int result{0};
  for (auto el : j) {
    if (seen.count(el)) {
      result++;
    }
  }

  printf("%d\n", result);
  return 0;
}