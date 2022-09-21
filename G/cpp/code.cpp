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

/**
 * @brief
 * Считаем "метрику городских кварталов"
 * https://ru.wikipedia.org/wiki/Расстояние_городских_кварталов
 * @param a std::pair<int, int> координаты начальной точки
 * @param b std::pair<int, int> коордмнаты конечной точки
 * @return int
 */
int dist(ii a, ii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

/**
 * @brief
 * Алгоритм поиска в ширину (BFS). Он позволяет за время O(E), где Е -
 * количество рёбер в графе, проверить достижимость любой вершины v из стартовой
 * вершины s, а также посчитать минимальное количество рёбер, необходимое для
 * этого (длину пути).
 * @param G std::vector<std::set<int>> граф в виде списка смежности (0-indexed)
 * @param start int номер начальной точки (0-indexed)
 * @param end int номер конечной точки (0-indexed)
 * @return int длина пути из start в end
 */
int BFS(vsi G, int start, int end) {
  vi distance(G.size(), -1);  // массив расстояний
  distance[start] = 0;  // расстояние до начальной точки
  std::queue<int> q;   // очередь FIFO
  q.push(start);        // начинаем со стартовой точки
  while (!q.empty()) {  // пока очередь не опустеет
    auto u = q.front();  // извлекаем первый элемент из очереди
    q.pop();                     // и удаляем
    for (const auto v : G[u]) {  // перебираем все смежные вершины
      if (distance[v] == -1) {  // если эту вершину ещё не посетили
        q.push(v);  // добавляем в конец очереди
        distance[v] = distance[u] + 1;  // записываем расстояние до вершины v
      }
    }
  }
  return distance[end];
}

int main() {
  //  freopen("input.txt", "r", stdin);

  int n, k, start, end;
  scanf("%d", &n);
  vii cords(n);
  for (auto &el : cords) {
    int x, y;
    scanf("%d %d", &x, &y);
    el = {x, y};
  }
  scanf("%d", &k);
  scanf("%d %d", &start, &end);
  start--;
  end--;
  if (dist(cords[start], cords[end]) <= k) {
    printf("1\n");
    return 0;
  }
  vsi G(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (dist(cords[i], cords[j])<=k) {
        G[i].insert(j);
        G[j].insert(i);
      }
    }
  }

  printf("%d\n", BFS(G, start, end));

  return 0;
}
