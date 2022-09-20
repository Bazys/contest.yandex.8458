/**
 * переведем в 0 индексацию
 * 0 0 =  0
 * 0 2 =  1
 * 2 2 =  2
 * 0 -2 = 3
 * 2 -2 = 4
 * 2 -1 = 5
 * 2 1  = 6
 * Расставим точки на координатоной плоскости
 *       1 2
 *       | 6
 * ------0----------
 *       | 5
 *       3 4
 *  Получим граф
 *  0 => 1,3
 *  1 => 0,2
 *  2 => 1,6
 *  3 => 0,4
 *  4 => 3,5
 *  5 => 4,5
 *  6 => 2,5
 *  Путь из точки 0 в 2 => 0->1->2 - 2 edge
 */

#include <iostream>
#include <queue>
#include <set>
#include <vector>

using ii = std::pair<int, int>;
using vii = std::vector<ii>;
using si = std::set<int>;
using vsi = std::vector<si>;
using vi = std::vector<int>;

int BFS(vsi G, int from, int to) {
  vi distance(G.size(), -1);  // массив расстояний
  distance[from] = 0;  // расстояние до начальной точки
  std::queue<int> q;   // очередь FIFO
  q.push(from);        // начинаем со стартовой точки
  while (!q.empty()) {  // пока очередь не опустеет
    auto u = q.front();  // извлекаем первый элемент из очереди
    q.pop();                     // и удаляем
    for (const auto v : G[u]) {  // перебираем все смежные вершины
      if (distance[v] == -1) {  // если эту вершину ещё не посетили
        q.push(v);  // добавляем в очередь
        distance[v] = distance[u] + 1;  // записываем расстояние до вершины v
      }
    }
  }
  return distance[to];
}

int main() {
  //  freopen("code.txt", "r", stdin);

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
  from--;
  to--;
  vsi G(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      auto dist = abs(cords[i].first - cords[j].first) +
                  abs(cords[i].second - cords[j].second);
      if (k >= dist) {
        G[i].insert(j);
        G[j].insert(i);
      }
    }
  }

  printf("%d\n", BFS(G, from, to));

  return 0;
}
