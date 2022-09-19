#include <iostream>
#include <set>
#include <vector>

using ii = std::pair<int, int>;
using vii = std::vector<ii>;
using sii = std::set<ii>;
using vsi = std::vector<sii>;

int main() {
  int n, k, from, to;
  scanf("%d", &n);
  vii cords(n);
  for (auto &el : cords) {
    int x, y;
    scanf("%d %d", &x, &y);
    el = ii(x, y);
  }
  scanf("%d", &k);
  scanf("%d %d", &from, &to);
  vsi G(n + 1, sii());
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      auto dist = abs(cords[i].first - cords[j].first) +
                  abs(cords[i].second - cords[j].second);
      if (k >= dist) {
        G[i].insert(ii(j, dist));
      }
    }
  }
  return 0;
}
