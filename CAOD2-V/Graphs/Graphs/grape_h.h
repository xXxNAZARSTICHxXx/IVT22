///Стич Назар Иванович ИВТ-22
#include <iostream> 
#include <cassert>  
#include <vector>   
#include <queue>   
#include <stack>    
#include <iomanip>  
//Метод загрузки и сохранения TODO++
/// <summary>
/// Функция для генерации алфавитных идентификаторов узлов - Генерирует идентификатор узла в виде строки на основе заданного индекса
/// </summary>
/// <param name="index">Индекс узла</param>
/// <returns>Идентификатор узла в виде строки</returns>
std::string generateNodeName(int index) {
    std::string name; // Строка для хранения имени узла
    while (index >= 0) { // Пока индекс не отрицательный
        name.insert(name.begin(), 'a' + (index % 26)); // Добавляем символ к началу имени
        index = index / 26 - 1; // Переход к следующему символу
    }
    return name; // Возвращаем сгенерированное имя узла
}

//TODO+ двойной шаблон vector map или другое (вместо имени name)
// Шаблонная структура для представления узла графа
template <typename T, typename L>
struct Node {
    L name; // Имя узла
    std::vector<std::pair<Node*, T>> adj; // Список смежности (соседние узлы и веса рёбер) //Хранится вектор(массив) из пар(множеств), которые состоят из указателя на узел и вес ребра
    int index; // Добавление индекса узла
    /// <summary>
    /// Конструктор для создания узла с заданным именем
    /// </summary>
    /// <param name="nodeName">Имя узла</param>
    Node(L nodeName) : name(std::move(nodeName)) {} // Инициализация имени узла

    /// <summary>
    /// Метод для добавления ребра - Добавляет рёбер между узлом и его соседом
    /// </summary>
    /// <param name="neighbor">Указатель на соседний узел</param>
    /// <param name="weight">Вес ребра</param>
    void addEdge(Node* neighbor, T weight) {
        adj.push_back({ neighbor, weight }); // Добавляем соседний узел и вес в список смежности
    }
    // Перегрузка оператора ->
    Node* operator->() {
        return this;
    }
};
// Класс для представления графа
template <typename T, typename L>
class Graph {
private:
    std::vector<Node<T, L>> nodes; // Список узлов

public:


    /// <summary>
    /// Конструктор для создания графа с заданным количеством узлов - Конструктор для создания графа с заданным количеством узлов
    /// </summary>
    /// <param name="numNodes">Количество узлов в графе</param>
    Graph(int numNodes) {
        for (int i = 0; i < numNodes; ++i) {
            // Имена узлов генерируются автоматически (например, "a", "b", "c" и т.д.)
            std::string nodeName(1, 'a' + i);
            nodes.emplace_back(nodeName);
            nodes.back().index = i;
        }
    }

    /// <summary>
    /// Получить указатель на узел по индексу
    /// </summary>
    /// <param name="index">Индекс узла</param>
    /// <returns>Указатель на узел</returns>
    Node<T, L>* getNode(int index) {
        return &nodes[index];
    }

    /// <summary>
    /// Метод для добавления одностороннего ребра между двумя узлами - Добавляет одностороннее ребро между двумя узлами
    /// </summary>
    /// <param name="fromIndex">Индекс начального узла</param>
    /// <param name="toIndex">Индекс конечного узла</param>
    /// <param name="weight">Вес ребра</param>
    template <typename T>
    void addEdge(int fromIndex, int toIndex, T weight) {
        if (fromIndex < nodes.size() && toIndex < nodes.size()) { // Проверка, что индексы в пределах допустимого диапазона
            for (const auto& edge : nodes[fromIndex]->adj) { // Проверяем существующие рёбра
                if (edge.first == nodes[toIndex]) {
                    std::cout << "Ребро между узлами " << nodes[fromIndex]->name << " и " << nodes[toIndex]->name << " уже существует." << std::endl;
                    return; // Если рёбер уже существует, выходим из функции
                }
            }
            nodes[fromIndex]->addEdge(nodes[toIndex], weight); // Добавляем новое ребро
        }
    }

    /// <summary>
    /// Удалить ребро между двумя узлами
    /// </summary>
    /// <param name="fromIndex">Индекс узла-источника</param>
    /// <param name="toIndex">Индекс узла-назначения</param>
    void removeEdge(int fromIndex, int toIndex) {
        auto& adj = nodes[fromIndex].adj;
        adj.erase(
            std::remove_if(adj.begin(), adj.end(), [&](const auto& edge) {
                return edge.first == &nodes[toIndex];
                }),
            adj.end()
        );
    }

    /// <summary>
    /// Обновить вес ребра между двумя узлами
    /// </summary>
    /// <param name="fromIndex">Индекс узла-источника</param>
    /// <param name="toIndex">Индекс узла-назначения</param>
    /// <param name="newWeight">Новый вес</param>
    void updateEdgeWeight(int fromIndex, int toIndex, T newWeight) {
        auto& adj = nodes[fromIndex].adj;
        for (auto& edge : adj) {
            if (edge.first == &nodes[toIndex]) {
                edge.second = newWeight;
                break;
            }
        }
    }

    /// <summary>
    /// Метод для обхода графа в ширину (BFS) - Выполняет обход графа в ширину, начиная с указанного узла
    /// </summary>
    /// <param name="startIndex">Индекс начального узла</param>
    /// <returns>Количество посещённых узлов</returns>
    int bfs(int startIndex) const {
        //Есть ли начальный индекс в пределах размера графа. Если индекс недопустим, возвращается 0
        if (startIndex >= nodes.size() || startIndex < 0) return 0; // Проверка на допустимый индекс
        //Создается очередь queue для хранения узлов, которые будут посещены, и булев вектор visited для отслеживания состояния посещения каждого узла
        std::queue<Node<int, std::string>*> queue; // Очередь для BFS
        std::vector<bool> visited(nodes.size(), false); // Вектор для отслеживания посещённых узлов
        //Начальный узел добавляется в очередь и помечается как посещенный
        queue.push(nodes[startIndex]); // Добавляем начальный узел в очередь
        visited[startIndex] = true; // Отмечаем начальный узел как посещённый

        int count = 1; // Счётчик посещённых узлов, начинаем с 1 (начальный узел)

        std::cout << "Посетили узел " << nodes[startIndex]->name << std::endl; // Выводим имя начального узла
        //Начало обхода, извлечение узлов из начала очереди и посещение их
        while (!queue.empty()) { // Пока очередь не пуста
            Node<int, std::string>* current = queue.front(); // Получаем текущий узел
            queue.pop(); // Удаляем текущий узел из очереди
            //Прохождение по всем его соседям
            for (const auto& neighbor : current->adj) { // Перебираем соседей текущего узла
                int index = neighbor.first->name[0] - 'a'; // Вычисляем индекс соседа
                //Если сосед еще не был посещен, он добавляется в очередь, помечается как посещенный, а счётчик увеличивается
                if (!visited[index]) { // Если сосед не посещён
                    queue.push(neighbor.first); // Добавляем соседа в очередь
                    visited[index] = true; // Отмечаем соседа как посещённый
                    count++; // Увеличиваем счётчик
                    std::cout << "Посетили узел " << neighbor.first->name << std::endl; // Выводим имя соседа
                }
            }
        }
        //После обхода всех достижимых узлов метод возвращает общее количество посещённых узлов
        return count; // Возвращаем количество посещённых узлов ?IteratorTODO? //TODO список посещенных узлов
    }


    /// <summary>
    /// Метод для обхода графа в глубину (DFS) - Выполняет обход графа в глубину, начиная с указанного узла
    /// </summary>
    /// <param name="startIndex">Индекс начального узла</param>
    /// <returns>Количество посещённых узлов</returns>
    int dfs(int startIndex) const {
        //Проверяется, находится ли startIndex в допустимых пределах; в противном случае возвращается 0
        if (startIndex >= nodes.size() || startIndex < 0) return 0; // Проверка на допустимый индекс
        //Создается стек stack для хранения узлов, которые нужно посетить, и вектор visited для отслеживания посещённых узлов
        std::stack<Node<int, std::string>*> stack; // Стек для DFS
        std::vector<bool> visited(nodes.size(), false); // Вектор для отслеживания посещённых узлов
        //Начальный узел добавляется в стек
        stack.push(nodes[startIndex]); // Добавляем начальный узел в стек

        int count = 0; // Счётчик посещённых узлов
        //Начинает обход, извлекая узлы из вершины стека и посещая их
        while (!stack.empty()) { // Пока стек не пуст
            Node<int, std::string>* current = stack.top(); // Получаем текущий узел
            stack.pop(); // Удаляем текущий узел из стека
            //Если узел еще не был посещен, он помечается как посещённый, счётчик увеличивается, и его имя выводится
            if (!visited[current->name[0] - 'a']) { // Проверяем, был ли узел посещён
                visited[current->name[0] - 'a'] = true; // Отмечаем текущий узел как посещённый
                count++; // Увеличиваем счётчик
                std::cout << "Посетили узел " << current->name << std::endl; // Выводим имя текущего узла
            }
            //Затем проходит по всем соседям текущего узла, добавляя их в стек, если они ещё не были посещены
            for (const auto& neighbor : current->adj) { // Перебираем соседей текущего узла
                int index = neighbor.first->name[0] - 'a'; // Вычисляем индекс соседа
                if (index >= 0 && index < visited.size() && !visited[index]) { // Проверяем допустимость индекса
                    stack.push(neighbor.first); // Добавляем соседа в стек
                }
            }
        }
        //По завершении обхода метод возвращает количество посещённых узлов
        return count; // Возвращаем количество посещённых узлов
    }

    /// <summary>
    /// Метод для обхода графа в ширину (BFS) - Выполняет обход графа в ширину, начиная с указанного узла
    /// </summary>
    /// <param name="startIndex">Индекс начального узла</param>
    /// <returns>Количество посещённых узлов</returns>
    template <typename T>
    std::vector<Node<T, std::string>*> bfslist(std::vector<Node<T, std::string>*>, int startIndex) const {
        //Создается очередь queue для хранения узлов, которые будут посещены, и булев вектор visited для отслеживания состояния посещения каждого узла
        std::queue<Node<int>*> queue; // Очередь для BFS
        std::vector<bool> visited(nodes.size(), false); // Вектор для отслеживания посещённых узлов
        //Начальный узел добавляется в очередь и помечается как посещенный
        queue.push(nodes[startIndex]); // Добавляем начальный узел в очередь
        visited[startIndex] = true; // Отмечаем начальный узел как посещённый

        int count = 1; // Счётчик посещённых узлов, начинаем с 1 (начальный узел)

        std::cout << "Посетили узел " << nodes[startIndex]->name << std::endl; // Выводим имя начального узла
        //Начало обхода, извлечение узлов из начала очереди и посещение их
        while (!queue.empty()) { // Пока очередь не пуста
            Node<int>* current = queue.front(); // Получаем текущий узел
            queue.pop(); // Удаляем текущий узел из очереди
            //Прохождение по всем его соседям
            for (const auto& neighbor : current->adj) { // Перебираем соседей текущего узла
                int index = neighbor.first->name[0] - 'a'; // Вычисляем индекс соседа
                //Если сосед еще не был посещен, он добавляется в очередь, помечается как посещенный, а счётчик увеличивается
                if (!visited[index]) { // Если сосед не посещён
                    queue.push(neighbor.first); // Добавляем соседа в очередь
                    visited[index] = true; // Отмечаем соседа как посещённый
                    count++; // Увеличиваем счётчик
                    std::cout << "Посетили узел " << neighbor.first->name << std::endl; // Выводим имя соседа
                }
            }
        }
        //После обхода всех достижимых узлов метод возвращает общее количество посещённых узлов
        return nodes; // Возвращаем список посещённых узлов ?IteratorTODO? //TODO список посещенных узлов
    }


    /// <summary>
    /// Метод для обхода графа в глубину (DFS) - Выполняет обход графа в глубину, начиная с указанного узла
    /// </summary>
    /// <param name="startIndex">Индекс начального узла</param>
    /// <returns>Количество посещённых узлов</returns>
    template <typename T>
    std::vector<Node<T, std::string>*> dfslist(std::vector<Node<T, std::string>*>, int startIndex) const {
        //Создается стек stack для хранения узлов, которые нужно посетить, и вектор visited для отслеживания посещённых узлов
        std::stack<Node<int>*> stack; // Стек для DFS
        std::vector<bool> visited(nodes.size(), false); // Вектор для отслеживания посещённых узлов
        //Начальный узел добавляется в стек
        stack.push(nodes[startIndex]); // Добавляем начальный узел в стек

        int count = 0; // Счётчик посещённых узлов
        //Начинает обход, извлекая узлы из вершины стека и посещая их
        while (!stack.empty()) { // Пока стек не пуст
            Node<int>* current = stack.top(); // Получаем текущий узел
            stack.pop(); // Удаляем текущий узел из стека
            //Если узел еще не был посещен, он помечается как посещённый, счётчик увеличивается, и его имя выводится
            if (!visited[current->name[0] - 'a']) { // Проверяем, был ли узел посещён
                visited[current->name[0] - 'a'] = true; // Отмечаем текущий узел как посещённый
                count++; // Увеличиваем счётчик
                std::cout << "Посетили узел " << current->name << std::endl; // Выводим имя текущего узла
            }
            //Затем проходит по всем соседям текущего узла, добавляя их в стек, если они ещё не были посещены
            for (const auto& neighbor : current->adj) { // Перебираем соседей текущего узла
                int index = neighbor.first->name[0] - 'a'; // Вычисляем индекс соседа
                if (index >= 0 && index < visited.size() && !visited[index]) { // Проверяем допустимость индекса
                    stack.push(neighbor.first); // Добавляем соседа в стек
                }
            }
        }
        //По завершении обхода метод возвращает количество посещённых узлов
        return nodes; // Возвращаем список посещённых узлов
    }


    /// <summary>
    /// Метод для печати списка смежности графа - выводит информацию о каждом узле и его соседях.
    /// </summary>
    void printAdjacencyList() const {
        for (const auto& node : nodes) {
            std::cout << node.name << ": {";
            bool first = true;
            for (const auto& edge : node.adj) {
                if (!first) {
                    std::cout << ", "; // Добавляем запятую между соседями
                }
                std::cout << "(" << edge.first->name << ", " << edge.second << ")"; // Печатаем соседей и вес рёбер
                first = false; // Устанавливаем флаг, чтобы не добавлять запятую перед первым соседом
            }
            std::cout << "}" << std::endl; // Закрываем список смежности для текущего узла
        }
    }

    /// <summary>
    /// Метод для печати матрицы смежности графа - выводит матрицу, где строки и столбцы соответствуют узлам,
    /// а элементы матрицы представляют веса рёбер между узлами.
    /// </summary>
    void printAdjacencyMatrix() const {
        int size = nodes.size(); // Получаем количество узлов
        std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0)); // Создаем матрицу смежности

        // Заполняем матрицу смежности
        for (int i = 0; i < size; ++i) {
            for (const auto& edge : nodes[i].adj) {
                int j = edge.first->name - 'a'; // Если name - это символ
                matrix[i][j] = edge.second; // Заполняем матрицу весом рёбер
            }
        }

        // Печать матрицы
        for (const auto& row : matrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    /// <summary>
    /// Добавить новый узел с заданным именем
    /// </summary>
    /// <param name="name">Имя нового узла</param>
    void addNode(L name) {
        nodes.emplace_back(name);
        nodes.back().index = nodes.size() - 1;
    }

    /// <summary>
    /// Метод для нахождения кратчайших путей из начального узла до всех остальных с использованием алгоритма Дейкстры
    /// </summary>
    /// <param name="startIndex">Индекс начального узла</param>
    template <typename T>
    std::vector<T> dijkstra(int startIndex) const {
        // Проверяем, что индекс начального узла находится в допустимых пределах
        if (startIndex < 0 || startIndex >= nodes.size()) {
            throw std::invalid_argument("Недопустимый индекс начального узла");
        }

        // Создаём вектор расстояний, инициализированный значением INT_MAX (практически бесконечность)
        std::vector<int> distances(nodes.size(), INT_MAX);
        // Устанавливаем расстояние до начального узла равным 0
        distances[startIndex] = 0;


        // Создаём очередь с приоритетом для обработки узлов (минимальное расстояние обрабатывается первым)
        ///Первый аргумент: обрабатывается пара
        ///Второй аргумент: контейнер с парами
        ///Третий аргумент: компаратор "больше чем"
        ///То есть очередь будет отсортирована по по расстояниям, чем оно меньше, тем выше приоритет
        ///TODO Вам шаблон или double... 
        
        // std::priority_queue - контейнер для очереди с приоритетом, которая организует элементы в таком порядке,
        // чтобы элемент с наивысшим приоритетом (в данном случае минимальным расстоянием) был на первом месте.

        // std::pair<int, int> - тип данных для хранения пар значений.
        // Первое значение (int) в паре будет представлять расстояние до узла.
        // Второе значение (int) будет идентификатором узла или его индексов (например, позиция в графе).

        // std::vector<std::pair<int, int>> - контейнер, который будет использоваться для хранения элементов очереди.
        // Вектор нужен для хранения всех элементов очереди (пар), и этот контейнер позволяет динамически увеличивать размер.

        // std::greater<> - это компаратор, который используется для сортировки очереди по возрастанию значения первого элемента пары (то есть расстояния).
        // Он делает так, что пара с меньшим значением (расстоянием) будет иметь более высокий приоритет и будет извлечена первой.


        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq; //TODO приоритетная очередь - а шо это?
        
        // Добавляем начальный узел в очередь с расстоянием 0
        pq.push({ 0, startIndex });

        // Пока очередь из узлов не пуста, продолжаем обработку
        while (!pq.empty()) {
            // Получаем узел с минимальным расстоянием из очереди
            int currentDist = pq.top().first;
            int currentIndex = pq.top().second;
            pq.pop(); // Удаляем обработанный элемент из очереди

            // Если текущее расстояние больше записанного в distances, пропускаем узел
            if (currentDist > distances[currentIndex]) continue;

            // Перебираем всех соседей текущего узла
            for (const auto& edge : nodes[currentIndex]->adj) {
                // Получаем индекс соседа (из имени узла)
                int neighborIndex = edge.first->name[0] - 'a';
                // Получаем вес ребра до соседа
                int weight = edge.second;

                // Если найден более короткий путь до соседа, обновляем расстояние
                if (distances[currentIndex] + weight < distances[neighborIndex]) {
                    distances[neighborIndex] = distances[currentIndex] + weight; // Обновляем расстояние
                    pq.push({ distances[neighborIndex], neighborIndex }); // Добавляем соседа в очередь
                }
            }
        }

        // Возвращаем вектор кратчайших расстояний до всех узлов
        return distances;
    }


    /// <summary>
    /// Метод для нахождения кратчайших путей из начального узла до всех остальных с использованием алгоритма Беллмана-Форда
    /// </summary>
    /// <param name="startIndex">Индекс начального узла</param>
    template <typename T>
    std::vector<T> bellmanFord(int startIndex) const {
        // Проверяем, что индекс начального узла находится в допустимых пределах
        if (startIndex < 0 || startIndex >= nodes.size()) {
            throw std::invalid_argument("Недопустимый индекс начального узла");
        }

        // Создаём вектор расстояний, инициализированный значением INT_MAX
        std::vector<int> distances(nodes.size(), INT_MAX);
        // Устанавливаем расстояние до начального узла равным 0
        distances[startIndex] = 0;

        // Выполняем итерации (|V| - 1) раз, где V — количество узлов
        for (size_t i = 1; i < nodes.size(); i++) {
            // Перебираем все узлы графа
            for (const auto& node : nodes) {
                // Перебираем все рёбра текущего узла
                for (const auto& edge : node->adj) {
                    // Получаем индекс текущего узла
                    int currentIndex = node->name[0] - 'a';
                    // Получаем индекс соседнего узла
                    int neighborIndex = edge.first->name[0] - 'a';
                    // Получаем вес ребра
                    int weight = edge.second;

                    // Игнорируем рёбра с отрицательным весом
                    if (weight < 0) {
                        continue; // Переходим к следующему ребру
                    }

                    // Если найден более короткий путь, обновляем расстояние
                    if (distances[currentIndex] != INT_MAX && distances[currentIndex] + weight < distances[neighborIndex]) {
                        distances[neighborIndex] = distances[currentIndex] + weight;
                    }
                }
            }
        }

        // Возвращаем вектор кратчайших расстояний до всех узлов
        return distances;
    }


};


void testGraph() {
    Graph<int, std::string> graph(5); // Создание графа с 5 узлами

    // Добавление рёбер
    graph.getNode(0)->addEdge(graph.getNode(1), 10); // Добавляем ребро от узла 0 к узлу 1 с весом 10

    // Тест добавления рёбер
    assert(graph.getNode(0)->adj.size() == 1); // Узел 0 должен иметь 1 соседа
    assert(graph.getNode(0)->adj[0].first->name == "b"); // Сосед должен быть b
    assert(graph.getNode(0)->adj[0].second == 10); // Вес должен быть 10

    // Тест обновления рёбер
    graph.updateEdgeWeight(0, 1, 20);
    assert(graph.getNode(0)->adj[0].second == 20); // Вес должен быть обновлён до 20

    // Тест удаления рёбер
    graph.removeEdge(0, 1);
    assert(graph.getNode(0)->adj.size() == 0); // У узла 0 больше нет соседей

    // Тест на корректное добавление нового узла
    graph.addNode("f"); // Добавляем новый узел с именем "f"
    assert(graph.getNode(5)->name == "f"); // Новый узел должен быть f

    // Тест на обработку графа с одним узлом
    Graph<int, std::string> singleNodeGraph(1); // Граф с 1 узлом
    assert(singleNodeGraph.getNode(0)->name == "a"); // Единственный узел — a
    auto distancesDijkstraSingle = singleNodeGraph.dijkstra<int>(0);
    assert(distancesDijkstraSingle[0] == 0); // Расстояние до самого себя - 0
    auto distancesBellmanSingle = singleNodeGraph.bellmanFord<int>(0);
    assert(distancesBellmanSingle[0] == 0); // Расстояние до самого себя - 0

    // Тест на пустой граф
    try {
        Graph<int, std::string> emptyGraph(0); // Граф без узлов
        emptyGraph.dijkstra<int>(0); // Ожидается ошибка
        assert(false);
    }
    catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Недопустимый индекс начального узла");
    }

    // Тест на несвязный граф
    Graph<int, std::string> disconnectedGraph(3); // Создание графа с 3 несвязанными узлами
    auto distancesDisconnected = disconnectedGraph.dijkstra<int>(0);
    assert(distancesDisconnected[1] == INT_MAX); // Узел 1 недостижим из узла 0
    assert(distancesDisconnected[2] == INT_MAX); // Узел 2 недостижим из узла 0

    // Тест на отрицательные циклы для Беллмана-Форда
    Graph<int, std::string> negativeCycleGraph(3);
    negativeCycleGraph.addEdge(0, 1, 1);
    negativeCycleGraph.addEdge(1, 2, -2);
    negativeCycleGraph.addEdge(2, 0, 1); // Замкнутый цикл с отрицательной суммой весов
    try {
        negativeCycleGraph.bellmanFord<int>(0); // Ожидается ошибка
    }
    catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Обнаружен отрицательный цикл");
    }

    // Тесты на алгоритмы поиска путей
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 5);
    auto distancesDijkstra = graph.dijkstra<int>(0);
    assert(distancesDijkstra[2] == 5); // Проверка Дейкстры
    auto distancesBellmanFord = graph.bellmanFord<int>(0);
    assert(distancesBellmanFord[2] == 5); // Проверка Беллмана-Форда
}




