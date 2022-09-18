#include <iostream>

int main() {
  int count, el, result{0}, max{0};
  scanf("%d", &count);
  while (count--) {
    scanf("%d", &el);
    if (el == 1) {
      result++;
    } else {
      max = std::max(max, result);
      result = 0;
    }
  }
  printf("%d\n", std::max(max, result));
  return 0;
}