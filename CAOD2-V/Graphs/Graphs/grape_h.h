///���� ����� �������� ���-22
#include <iostream> 
#include <cassert>  
#include <vector>   
#include <queue>   
#include <stack>    
#include <iomanip>  
//����� �������� � ���������� TODO++
/// <summary>
/// ������� ��� ��������� ���������� ��������������� ����� - ���������� ������������� ���� � ���� ������ �� ������ ��������� �������
/// </summary>
/// <param name="index">������ ����</param>
/// <returns>������������� ���� � ���� ������</returns>
std::string generateNodeName(int index) {
    std::string name; // ������ ��� �������� ����� ����
    while (index >= 0) { // ���� ������ �� �������������
        name.insert(name.begin(), 'a' + (index % 26)); // ��������� ������ � ������ �����
        index = index / 26 - 1; // ������� � ���������� �������
    }
    return name; // ���������� ��������������� ��� ����
}

//TODO+ ������� ������ vector map ��� ������ (������ ����� name)
// ��������� ��������� ��� ������������� ���� �����
template <typename T, typename L>
struct Node {
    L name; // ��� ����
    std::vector<std::pair<Node*, T>> adj; // ������ ��������� (�������� ���� � ���� ����) //�������� ������(������) �� ���(��������), ������� ������� �� ��������� �� ���� � ��� �����
    int index; // ���������� ������� ����
    /// <summary>
    /// ����������� ��� �������� ���� � �������� ������
    /// </summary>
    /// <param name="nodeName">��� ����</param>
    Node(L nodeName) : name(std::move(nodeName)) {} // ������������� ����� ����

    /// <summary>
    /// ����� ��� ���������� ����� - ��������� ���� ����� ����� � ��� �������
    /// </summary>
    /// <param name="neighbor">��������� �� �������� ����</param>
    /// <param name="weight">��� �����</param>
    void addEdge(Node* neighbor, T weight) {
        adj.push_back({ neighbor, weight }); // ��������� �������� ���� � ��� � ������ ���������
    }
    // ���������� ��������� ->
    Node* operator->() {
        return this;
    }
};
// ����� ��� ������������� �����
template <typename T, typename L>
class Graph {
private:
    std::vector<Node<T, L>> nodes; // ������ �����

public:


    /// <summary>
    /// ����������� ��� �������� ����� � �������� ����������� ����� - ����������� ��� �������� ����� � �������� ����������� �����
    /// </summary>
    /// <param name="numNodes">���������� ����� � �����</param>
    Graph(int numNodes) {
        for (int i = 0; i < numNodes; ++i) {
            // ����� ����� ������������ ������������� (��������, "a", "b", "c" � �.�.)
            std::string nodeName(1, 'a' + i);
            nodes.emplace_back(nodeName);
            nodes.back().index = i;
        }
    }

    /// <summary>
    /// �������� ��������� �� ���� �� �������
    /// </summary>
    /// <param name="index">������ ����</param>
    /// <returns>��������� �� ����</returns>
    Node<T, L>* getNode(int index) {
        return &nodes[index];
    }

    /// <summary>
    /// ����� ��� ���������� �������������� ����� ����� ����� ������ - ��������� ������������� ����� ����� ����� ������
    /// </summary>
    /// <param name="fromIndex">������ ���������� ����</param>
    /// <param name="toIndex">������ ��������� ����</param>
    /// <param name="weight">��� �����</param>
    template <typename T>
    void addEdge(int fromIndex, int toIndex, T weight) {
        if (fromIndex < nodes.size() && toIndex < nodes.size()) { // ��������, ��� ������� � �������� ����������� ���������
            for (const auto& edge : nodes[fromIndex]->adj) { // ��������� ������������ ����
                if (edge.first == nodes[toIndex]) {
                    std::cout << "����� ����� ������ " << nodes[fromIndex]->name << " � " << nodes[toIndex]->name << " ��� ����������." << std::endl;
                    return; // ���� ���� ��� ����������, ������� �� �������
                }
            }
            nodes[fromIndex]->addEdge(nodes[toIndex], weight); // ��������� ����� �����
        }
    }

    /// <summary>
    /// ������� ����� ����� ����� ������
    /// </summary>
    /// <param name="fromIndex">������ ����-���������</param>
    /// <param name="toIndex">������ ����-����������</param>
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
    /// �������� ��� ����� ����� ����� ������
    /// </summary>
    /// <param name="fromIndex">������ ����-���������</param>
    /// <param name="toIndex">������ ����-����������</param>
    /// <param name="newWeight">����� ���</param>
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
    /// ����� ��� ������ ����� � ������ (BFS) - ��������� ����� ����� � ������, ������� � ���������� ����
    /// </summary>
    /// <param name="startIndex">������ ���������� ����</param>
    /// <returns>���������� ���������� �����</returns>
    int bfs(int startIndex) const {
        //���� �� ��������� ������ � �������� ������� �����. ���� ������ ����������, ������������ 0
        if (startIndex >= nodes.size() || startIndex < 0) return 0; // �������� �� ���������� ������
        //��������� ������� queue ��� �������� �����, ������� ����� ��������, � ����� ������ visited ��� ������������ ��������� ��������� ������� ����
        std::queue<Node<int, std::string>*> queue; // ������� ��� BFS
        std::vector<bool> visited(nodes.size(), false); // ������ ��� ������������ ���������� �����
        //��������� ���� ����������� � ������� � ���������� ��� ����������
        queue.push(nodes[startIndex]); // ��������� ��������� ���� � �������
        visited[startIndex] = true; // �������� ��������� ���� ��� ����������

        int count = 1; // ������� ���������� �����, �������� � 1 (��������� ����)

        std::cout << "�������� ���� " << nodes[startIndex]->name << std::endl; // ������� ��� ���������� ����
        //������ ������, ���������� ����� �� ������ ������� � ��������� ��
        while (!queue.empty()) { // ���� ������� �� �����
            Node<int, std::string>* current = queue.front(); // �������� ������� ����
            queue.pop(); // ������� ������� ���� �� �������
            //����������� �� ���� ��� �������
            for (const auto& neighbor : current->adj) { // ���������� ������� �������� ����
                int index = neighbor.first->name[0] - 'a'; // ��������� ������ ������
                //���� ����� ��� �� ��� �������, �� ����������� � �������, ���������� ��� ����������, � ������� �������������
                if (!visited[index]) { // ���� ����� �� �������
                    queue.push(neighbor.first); // ��������� ������ � �������
                    visited[index] = true; // �������� ������ ��� ����������
                    count++; // ����������� �������
                    std::cout << "�������� ���� " << neighbor.first->name << std::endl; // ������� ��� ������
                }
            }
        }
        //����� ������ ���� ���������� ����� ����� ���������� ����� ���������� ���������� �����
        return count; // ���������� ���������� ���������� ����� ?IteratorTODO? //TODO ������ ���������� �����
    }


    /// <summary>
    /// ����� ��� ������ ����� � ������� (DFS) - ��������� ����� ����� � �������, ������� � ���������� ����
    /// </summary>
    /// <param name="startIndex">������ ���������� ����</param>
    /// <returns>���������� ���������� �����</returns>
    int dfs(int startIndex) const {
        //�����������, ��������� �� startIndex � ���������� ��������; � ��������� ������ ������������ 0
        if (startIndex >= nodes.size() || startIndex < 0) return 0; // �������� �� ���������� ������
        //��������� ���� stack ��� �������� �����, ������� ����� ��������, � ������ visited ��� ������������ ���������� �����
        std::stack<Node<int, std::string>*> stack; // ���� ��� DFS
        std::vector<bool> visited(nodes.size(), false); // ������ ��� ������������ ���������� �����
        //��������� ���� ����������� � ����
        stack.push(nodes[startIndex]); // ��������� ��������� ���� � ����

        int count = 0; // ������� ���������� �����
        //�������� �����, �������� ���� �� ������� ����� � ������� ��
        while (!stack.empty()) { // ���� ���� �� ����
            Node<int, std::string>* current = stack.top(); // �������� ������� ����
            stack.pop(); // ������� ������� ���� �� �����
            //���� ���� ��� �� ��� �������, �� ���������� ��� ����������, ������� �������������, � ��� ��� ���������
            if (!visited[current->name[0] - 'a']) { // ���������, ��� �� ���� �������
                visited[current->name[0] - 'a'] = true; // �������� ������� ���� ��� ����������
                count++; // ����������� �������
                std::cout << "�������� ���� " << current->name << std::endl; // ������� ��� �������� ����
            }
            //����� �������� �� ���� ������� �������� ����, �������� �� � ����, ���� ��� ��� �� ���� ��������
            for (const auto& neighbor : current->adj) { // ���������� ������� �������� ����
                int index = neighbor.first->name[0] - 'a'; // ��������� ������ ������
                if (index >= 0 && index < visited.size() && !visited[index]) { // ��������� ������������ �������
                    stack.push(neighbor.first); // ��������� ������ � ����
                }
            }
        }
        //�� ���������� ������ ����� ���������� ���������� ���������� �����
        return count; // ���������� ���������� ���������� �����
    }

    /// <summary>
    /// ����� ��� ������ ����� � ������ (BFS) - ��������� ����� ����� � ������, ������� � ���������� ����
    /// </summary>
    /// <param name="startIndex">������ ���������� ����</param>
    /// <returns>���������� ���������� �����</returns>
    template <typename T>
    std::vector<Node<T, std::string>*> bfslist(std::vector<Node<T, std::string>*>, int startIndex) const {
        //��������� ������� queue ��� �������� �����, ������� ����� ��������, � ����� ������ visited ��� ������������ ��������� ��������� ������� ����
        std::queue<Node<int>*> queue; // ������� ��� BFS
        std::vector<bool> visited(nodes.size(), false); // ������ ��� ������������ ���������� �����
        //��������� ���� ����������� � ������� � ���������� ��� ����������
        queue.push(nodes[startIndex]); // ��������� ��������� ���� � �������
        visited[startIndex] = true; // �������� ��������� ���� ��� ����������

        int count = 1; // ������� ���������� �����, �������� � 1 (��������� ����)

        std::cout << "�������� ���� " << nodes[startIndex]->name << std::endl; // ������� ��� ���������� ����
        //������ ������, ���������� ����� �� ������ ������� � ��������� ��
        while (!queue.empty()) { // ���� ������� �� �����
            Node<int>* current = queue.front(); // �������� ������� ����
            queue.pop(); // ������� ������� ���� �� �������
            //����������� �� ���� ��� �������
            for (const auto& neighbor : current->adj) { // ���������� ������� �������� ����
                int index = neighbor.first->name[0] - 'a'; // ��������� ������ ������
                //���� ����� ��� �� ��� �������, �� ����������� � �������, ���������� ��� ����������, � ������� �������������
                if (!visited[index]) { // ���� ����� �� �������
                    queue.push(neighbor.first); // ��������� ������ � �������
                    visited[index] = true; // �������� ������ ��� ����������
                    count++; // ����������� �������
                    std::cout << "�������� ���� " << neighbor.first->name << std::endl; // ������� ��� ������
                }
            }
        }
        //����� ������ ���� ���������� ����� ����� ���������� ����� ���������� ���������� �����
        return nodes; // ���������� ������ ���������� ����� ?IteratorTODO? //TODO ������ ���������� �����
    }


    /// <summary>
    /// ����� ��� ������ ����� � ������� (DFS) - ��������� ����� ����� � �������, ������� � ���������� ����
    /// </summary>
    /// <param name="startIndex">������ ���������� ����</param>
    /// <returns>���������� ���������� �����</returns>
    template <typename T>
    std::vector<Node<T, std::string>*> dfslist(std::vector<Node<T, std::string>*>, int startIndex) const {
        //��������� ���� stack ��� �������� �����, ������� ����� ��������, � ������ visited ��� ������������ ���������� �����
        std::stack<Node<int>*> stack; // ���� ��� DFS
        std::vector<bool> visited(nodes.size(), false); // ������ ��� ������������ ���������� �����
        //��������� ���� ����������� � ����
        stack.push(nodes[startIndex]); // ��������� ��������� ���� � ����

        int count = 0; // ������� ���������� �����
        //�������� �����, �������� ���� �� ������� ����� � ������� ��
        while (!stack.empty()) { // ���� ���� �� ����
            Node<int>* current = stack.top(); // �������� ������� ����
            stack.pop(); // ������� ������� ���� �� �����
            //���� ���� ��� �� ��� �������, �� ���������� ��� ����������, ������� �������������, � ��� ��� ���������
            if (!visited[current->name[0] - 'a']) { // ���������, ��� �� ���� �������
                visited[current->name[0] - 'a'] = true; // �������� ������� ���� ��� ����������
                count++; // ����������� �������
                std::cout << "�������� ���� " << current->name << std::endl; // ������� ��� �������� ����
            }
            //����� �������� �� ���� ������� �������� ����, �������� �� � ����, ���� ��� ��� �� ���� ��������
            for (const auto& neighbor : current->adj) { // ���������� ������� �������� ����
                int index = neighbor.first->name[0] - 'a'; // ��������� ������ ������
                if (index >= 0 && index < visited.size() && !visited[index]) { // ��������� ������������ �������
                    stack.push(neighbor.first); // ��������� ������ � ����
                }
            }
        }
        //�� ���������� ������ ����� ���������� ���������� ���������� �����
        return nodes; // ���������� ������ ���������� �����
    }


    /// <summary>
    /// ����� ��� ������ ������ ��������� ����� - ������� ���������� � ������ ���� � ��� �������.
    /// </summary>
    void printAdjacencyList() const {
        for (const auto& node : nodes) {
            std::cout << node.name << ": {";
            bool first = true;
            for (const auto& edge : node.adj) {
                if (!first) {
                    std::cout << ", "; // ��������� ������� ����� ��������
                }
                std::cout << "(" << edge.first->name << ", " << edge.second << ")"; // �������� ������� � ��� ����
                first = false; // ������������� ����, ����� �� ��������� ������� ����� ������ �������
            }
            std::cout << "}" << std::endl; // ��������� ������ ��������� ��� �������� ����
        }
    }

    /// <summary>
    /// ����� ��� ������ ������� ��������� ����� - ������� �������, ��� ������ � ������� ������������� �����,
    /// � �������� ������� ������������ ���� ���� ����� ������.
    /// </summary>
    void printAdjacencyMatrix() const {
        int size = nodes.size(); // �������� ���������� �����
        std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0)); // ������� ������� ���������

        // ��������� ������� ���������
        for (int i = 0; i < size; ++i) {
            for (const auto& edge : nodes[i].adj) {
                int j = edge.first->name - 'a'; // ���� name - ��� ������
                matrix[i][j] = edge.second; // ��������� ������� ����� ����
            }
        }

        // ������ �������
        for (const auto& row : matrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    /// <summary>
    /// �������� ����� ���� � �������� ������
    /// </summary>
    /// <param name="name">��� ������ ����</param>
    void addNode(L name) {
        nodes.emplace_back(name);
        nodes.back().index = nodes.size() - 1;
    }

    /// <summary>
    /// ����� ��� ���������� ���������� ����� �� ���������� ���� �� ���� ��������� � �������������� ��������� ��������
    /// </summary>
    /// <param name="startIndex">������ ���������� ����</param>
    template <typename T>
    std::vector<T> dijkstra(int startIndex) const {
        // ���������, ��� ������ ���������� ���� ��������� � ���������� ��������
        if (startIndex < 0 || startIndex >= nodes.size()) {
            throw std::invalid_argument("������������ ������ ���������� ����");
        }

        // ������ ������ ����������, ������������������ ��������� INT_MAX (����������� �������������)
        std::vector<int> distances(nodes.size(), INT_MAX);
        // ������������� ���������� �� ���������� ���� ������ 0
        distances[startIndex] = 0;


        // ������ ������� � ����������� ��� ��������� ����� (����������� ���������� �������������� ������)
        ///������ ��������: �������������� ����
        ///������ ��������: ��������� � ������
        ///������ ��������: ���������� "������ ���"
        ///�� ���� ������� ����� ������������� �� �� �����������, ��� ��� ������, ��� ���� ���������
        ///TODO ��� ������ ��� double... 
        
        // std::priority_queue - ��������� ��� ������� � �����������, ������� ���������� �������� � ����� �������,
        // ����� ������� � ��������� ����������� (� ������ ������ ����������� �����������) ��� �� ������ �����.

        // std::pair<int, int> - ��� ������ ��� �������� ��� ��������.
        // ������ �������� (int) � ���� ����� ������������ ���������� �� ����.
        // ������ �������� (int) ����� ��������������� ���� ��� ��� �������� (��������, ������� � �����).

        // std::vector<std::pair<int, int>> - ���������, ������� ����� �������������� ��� �������� ��������� �������.
        // ������ ����� ��� �������� ���� ��������� ������� (���), � ���� ��������� ��������� ����������� ����������� ������.

        // std::greater<> - ��� ����������, ������� ������������ ��� ���������� ������� �� ����������� �������� ������� �������� ���� (�� ���� ����������).
        // �� ������ ���, ��� ���� � ������� ��������� (�����������) ����� ����� ����� ������� ��������� � ����� ��������� ������.


        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq; //TODO ������������ ������� - � �� ���?
        
        // ��������� ��������� ���� � ������� � ����������� 0
        pq.push({ 0, startIndex });

        // ���� ������� �� ����� �� �����, ���������� ���������
        while (!pq.empty()) {
            // �������� ���� � ����������� ����������� �� �������
            int currentDist = pq.top().first;
            int currentIndex = pq.top().second;
            pq.pop(); // ������� ������������ ������� �� �������

            // ���� ������� ���������� ������ ����������� � distances, ���������� ����
            if (currentDist > distances[currentIndex]) continue;

            // ���������� ���� ������� �������� ����
            for (const auto& edge : nodes[currentIndex]->adj) {
                // �������� ������ ������ (�� ����� ����)
                int neighborIndex = edge.first->name[0] - 'a';
                // �������� ��� ����� �� ������
                int weight = edge.second;

                // ���� ������ ����� �������� ���� �� ������, ��������� ����������
                if (distances[currentIndex] + weight < distances[neighborIndex]) {
                    distances[neighborIndex] = distances[currentIndex] + weight; // ��������� ����������
                    pq.push({ distances[neighborIndex], neighborIndex }); // ��������� ������ � �������
                }
            }
        }

        // ���������� ������ ���������� ���������� �� ���� �����
        return distances;
    }


    /// <summary>
    /// ����� ��� ���������� ���������� ����� �� ���������� ���� �� ���� ��������� � �������������� ��������� ��������-�����
    /// </summary>
    /// <param name="startIndex">������ ���������� ����</param>
    template <typename T>
    std::vector<T> bellmanFord(int startIndex) const {
        // ���������, ��� ������ ���������� ���� ��������� � ���������� ��������
        if (startIndex < 0 || startIndex >= nodes.size()) {
            throw std::invalid_argument("������������ ������ ���������� ����");
        }

        // ������ ������ ����������, ������������������ ��������� INT_MAX
        std::vector<int> distances(nodes.size(), INT_MAX);
        // ������������� ���������� �� ���������� ���� ������ 0
        distances[startIndex] = 0;

        // ��������� �������� (|V| - 1) ���, ��� V � ���������� �����
        for (size_t i = 1; i < nodes.size(); i++) {
            // ���������� ��� ���� �����
            for (const auto& node : nodes) {
                // ���������� ��� ���� �������� ����
                for (const auto& edge : node->adj) {
                    // �������� ������ �������� ����
                    int currentIndex = node->name[0] - 'a';
                    // �������� ������ ��������� ����
                    int neighborIndex = edge.first->name[0] - 'a';
                    // �������� ��� �����
                    int weight = edge.second;

                    // ���������� ���� � ������������� �����
                    if (weight < 0) {
                        continue; // ��������� � ���������� �����
                    }

                    // ���� ������ ����� �������� ����, ��������� ����������
                    if (distances[currentIndex] != INT_MAX && distances[currentIndex] + weight < distances[neighborIndex]) {
                        distances[neighborIndex] = distances[currentIndex] + weight;
                    }
                }
            }
        }

        // ���������� ������ ���������� ���������� �� ���� �����
        return distances;
    }


};


void testGraph() {
    Graph<int, std::string> graph(5); // �������� ����� � 5 ������

    // ���������� ����
    graph.getNode(0)->addEdge(graph.getNode(1), 10); // ��������� ����� �� ���� 0 � ���� 1 � ����� 10

    // ���� ���������� ����
    assert(graph.getNode(0)->adj.size() == 1); // ���� 0 ������ ����� 1 ������
    assert(graph.getNode(0)->adj[0].first->name == "b"); // ����� ������ ���� b
    assert(graph.getNode(0)->adj[0].second == 10); // ��� ������ ���� 10

    // ���� ���������� ����
    graph.updateEdgeWeight(0, 1, 20);
    assert(graph.getNode(0)->adj[0].second == 20); // ��� ������ ���� ������� �� 20

    // ���� �������� ����
    graph.removeEdge(0, 1);
    assert(graph.getNode(0)->adj.size() == 0); // � ���� 0 ������ ��� �������

    // ���� �� ���������� ���������� ������ ����
    graph.addNode("f"); // ��������� ����� ���� � ������ "f"
    assert(graph.getNode(5)->name == "f"); // ����� ���� ������ ���� f

    // ���� �� ��������� ����� � ����� �����
    Graph<int, std::string> singleNodeGraph(1); // ���� � 1 �����
    assert(singleNodeGraph.getNode(0)->name == "a"); // ������������ ���� � a
    auto distancesDijkstraSingle = singleNodeGraph.dijkstra<int>(0);
    assert(distancesDijkstraSingle[0] == 0); // ���������� �� ������ ���� - 0
    auto distancesBellmanSingle = singleNodeGraph.bellmanFord<int>(0);
    assert(distancesBellmanSingle[0] == 0); // ���������� �� ������ ���� - 0

    // ���� �� ������ ����
    try {
        Graph<int, std::string> emptyGraph(0); // ���� ��� �����
        emptyGraph.dijkstra<int>(0); // ��������� ������
        assert(false);
    }
    catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "������������ ������ ���������� ����");
    }

    // ���� �� ��������� ����
    Graph<int, std::string> disconnectedGraph(3); // �������� ����� � 3 ������������ ������
    auto distancesDisconnected = disconnectedGraph.dijkstra<int>(0);
    assert(distancesDisconnected[1] == INT_MAX); // ���� 1 ���������� �� ���� 0
    assert(distancesDisconnected[2] == INT_MAX); // ���� 2 ���������� �� ���� 0

    // ���� �� ������������� ����� ��� ��������-�����
    Graph<int, std::string> negativeCycleGraph(3);
    negativeCycleGraph.addEdge(0, 1, 1);
    negativeCycleGraph.addEdge(1, 2, -2);
    negativeCycleGraph.addEdge(2, 0, 1); // ��������� ���� � ������������� ������ �����
    try {
        negativeCycleGraph.bellmanFord<int>(0); // ��������� ������
    }
    catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "��������� ������������� ����");
    }

    // ����� �� ��������� ������ �����
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 5);
    auto distancesDijkstra = graph.dijkstra<int>(0);
    assert(distancesDijkstra[2] == 5); // �������� ��������
    auto distancesBellmanFord = graph.bellmanFord<int>(0);
    assert(distancesBellmanFord[2] == 5); // �������� ��������-�����
}




