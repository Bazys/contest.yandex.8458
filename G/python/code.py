def dist(a, b):
    """
    Считаем "метрику городских кварталов" L1:
    https://ru.wikipedia.org/wiki/Расстояние_городских_кварталов
    :param a: a = (x1, y1) - tuple with 1st coordinates
    :param b: b = (x2, y2) - tuple with 2nd coordinates
    :return: integer number
    """
    return abs(b[0] - a[0]) + abs(b[1] - a[1])


def BFS(G, start, stop):
    """
    Алгоритм поиска в ширину (BFS). Он позволяет за время O(E), где Е - количество рёбер в графе, проверить достижимость
    любой вершины v из стартовой вершины s, а также посчитать минимальное количество рёбер, необходимое для этого (стоимость пути).
    :param s: int, индекс стартовой вершины графа.
    :param G: List[List[int]], матрица смежности вершин графа (вершины, которые достижимы из каждой конкретной вершины).
    :return: List[int], "стоимости" путей до всех вершин - минимальное количество ребёр графа, чтобы достигнуть каждую вершину из стартовой.
    """
    distance = [-1] * len(G)  # стоимость прохода до нужной вершины
    distance[start] = 0  # стоимость пути из любой вершины графа в саму себя равна нулю
    q = [
        start]  # для простоты создаём очередь в виде List, но для оптимизации лучше использовать связный список, например, queue.Queue()

    while q:
        u = q.pop(0)
        # запускаем алгоритм обхода по вершинам графа:
        for v in G[u]:
            # проверяем каждую вершину, посещали её или нет:
            if distance[v] == -1:
                q.append(v)  # если вершина не посещалась, добавляем её в очередь
                distance[v] = distance[u] + 1  # увеличиваем стоимость пути

    return distance[stop]


def main(inpFile="input.txt"):
    # получаем входные параметры из файла:
    with open(inpFile, "r", encoding="UTF-8") as fH:
        inpLines = fH.readlines()  # строки исходного входного файла
        # удаляем ненужное окончание строк и читаем строки как числа:
        n = int(inpLines[0])  # количество городов n (2 <= n <= 1000). Важно! Города пронумерованы от 1 до n
        coordList = []  # сохраняем координаты как list of tuples

        for item in inpLines[1: -2]:
            # координата очередного города:
            coordList.append(
                (
                    int(item.split(" ")[0]),
                    int(item.split(" ")[1].rstrip("\n"))
                )
            )

        k = int(inpLines[
                    -2])  # число k <= 2 млрд., максимальное расстояние между городами, которое Петя может преодолеть без дозаправки машины

        # читаем номера городов - начала и конца пути:
        start = int(inpLines[-1].split(" ")[0])-1
        end = int(inpLines[-1].split(" ")[1].rstrip("\n"))-1

    # Если расстояние между 1 и 2 городами сразу меньше либо равно k (доступный бензин), то путь сразу равен 1
    if dist(coordList[start], coordList[end] ) <= k:
        costs = 1

    else:
        # Предварительно создаём список достижимости городов - это матрица смежности каждого города с каждым другим городом,
        # если до него хватает бензина. В список заносим только индексы достижимых городов.
        # Если начальный и конечный город совпадают, отмечаем это как достижимый город.
        adjList = [
            [index for index, city1 in enumerate(coordList) if dist(city1, city2) <= k] for city2 in coordList
        ]

        # считаем стоимости всех путей из стартового города до всех остальных достижимых городов:
        # получаем стоимость пути до конечного города, -1 если такого пути нет, либо он недостижим:
        costs = BFS(adjList, start, end)

    with open("output.txt", "w", encoding="UTF-8") as fH:
        fH.write(str(costs))

    return costs


if __name__ == "__main__":
    print(main(inpFile="input.txt"))
