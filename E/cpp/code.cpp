#include <algorithm>
#include <iostream>

int main() {
  std::string s1, s2;
  std::cin >> s1;
  std::cin >> s2;
  if (s1.size() != s2.size()) {
    printf("0\n");
    return 0;
  }
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  if (s1 == s2) {
    printf("0\n");
    return 0;
  }
  printf("1\n");
  return 0;
}
