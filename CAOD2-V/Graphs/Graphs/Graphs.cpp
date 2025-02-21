/// Стич Назар Иванович ИВТ-22

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include "grape_h.h"

int main() {
    setlocale(LC_ALL, "russian");

    // Тестирование функционала графа
    testGraph();

    // Создание графа с 9 вершинами
    Graph<int, int> graph(9); // Указываем типы данных для узлов и весов рёбер

    // Добавление рёбер
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 5);
    graph.addEdge(1, 4, 0);
    graph.addEdge(3, 0, 2);
    graph.addEdge(3, 2, -3);
    graph.addEdge(4, 3, 2);
    graph.addEdge(4, 6, 10);
    graph.addEdge(5, 2, 4);
    graph.addEdge(6, 4, -1);
    graph.addEdge(6, 5, 6);
    graph.addEdge(7, 2, 29);
    graph.addEdge(8, 8, 0);

    // Печать обходов графа
    std::cout << "Обход в ширину (BFS):" << std::endl;
    graph.bfs(0);

    std::cout << "\nОбход в глубину (DFS):" << std::endl;
    graph.dfs(0);

    // Печать списка смежности
    std::cout << "\nСписок смежности:" << std::endl;
    graph.printAdjacencyList();

    // Печать матрицы смежности
    std::cout << "\nМатрица смежности:" << std::endl;
    graph.printAdjacencyMatrix();

    return 0;
}
