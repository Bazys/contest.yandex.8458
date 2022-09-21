package main

import (
	"fmt"
	"math"
)

// Считаем "метрику городских кварталов"
func dist(a, b [2]int) int {
	return int(math.Abs(float64(a[0]-b[0])) + math.Abs(float64(a[1]-b[1])))
}

// Алгоритм поиска в ширину (BFS). Он позволяет за время O(E), где Е -
// количество рёбер в графе, проверить достижимость любой вершины v из стартовой
// вершины s, а также посчитать минимальное количество рёбер, необходимое для
// этого (длину пути).
func BFS(G [][]int, start, end int) int {
	distance := make([]int, len(G))
	for i := range distance {
		distance[i] = -1
	}
	distance[start] = 0
	queue := make([]int, 0)
	queue = append(queue, start)
	for len(queue) != 0 {
		u := queue[0]
		queue = queue[1:]
		for _, v := range G[u] {
			if distance[v] == -1 {
				queue = append(queue, v)
				distance[v] = distance[u] + 1
			}
		}
	}
	return distance[end]
}

func main() {
	var n, k, start, end int

	fmt.Scanf("%d", &n)
	cords := make([][2]int, n)
	for i := range cords {
		var x, y int
		fmt.Scanf("%d %d", &x, &y)
		cords[i] = [2]int{x, y}
	}
	fmt.Scanf("%d", &k)
	fmt.Scanf("%d %d", &start, &end)
	start--
	end--
	if dist(cords[start], cords[end]) <= k {
		fmt.Printf("1\n")
		return
	}
	G := make([][]int, n)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if dist(cords[i], cords[j]) <= k {
				G[i] = append(G[i], j)
				G[j] = append(G[j], i)
			}
		}
	}
	fmt.Println(BFS(G, start, end))
}
