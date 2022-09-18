#include <iostream>

int main() {
  int count, ch{-99999};
  scanf("%d", &count);
  while (count--) {
    int el;
    scanf("%d", &el);
    if (el != ch) {
      printf("%d\n", el);
    }
    ch = el;
  }
  return 0;
}