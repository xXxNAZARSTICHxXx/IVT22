#include <iostream> // ����������� ����������� ���������� ��� �����-������
#include <algorithm> // ����������� ����������� ���������� ���������� (std::for_each, std::any_of, � �.�.)
#include <iterator> // ����������� ����������� ���������� ��� ������ � �����������
#include <cassert> // ����������� ����������� ���������� ��� �������� � ������� assert
#include "TREE_H.h" // ����������� ������������� ����� ��� ������ � ��������� (��������, ��� BinarySearchTree)

// DoubleList - ����� ����������� ������
template <typename T> // ������ ������ ��� ������ � ���������� ������ ������
class DoubleList {
private:
    // ����, �������������� ������� ����������� ������
    struct Node {
        T data; // ������ ���� (������� ������)
        Node* prev; // ��������� �� ���������� ����
        Node* next; // ��������� �� ��������� ����

        // ����������� ���� � ������������ �������� ������ � �������� �����
        Node(const T& newData, Node* newPrev = nullptr, Node* newNext = nullptr)
            : data(newData), prev(newPrev), next(newNext) {} // ������������� ����
    };

    Node* head; // ��������� �� ������ ������� ������ (������)
    Node* tail; // ��������� �� ��������� ������� ������ (�����)
    size_t size; // ������ ������ (���������� �����)

public:
    using value_type = T;  // ����������� ���� value_type ��� ��������� ����������� ����������

    /// <summary>
    /// ����������� �� ���������, ���������������� ������ ������
    /// </summary>
    DoubleList() : head(nullptr), tail(nullptr), size(0) {}

    /// <summary>
    /// ����������, ���������� ������� ������
    /// </summary>
    ~DoubleList() { clear(); }

    /// <summary>
    /// ����� ��� ���������� �������� � ����� ������
    /// </summary>
    /// <param name="value">������� ��� ���������� � ����� ������</param>
    void push_back(const T& value) {
        if (!head) { // ���� ������ ����
            head = tail = new Node(value); // ������� ����� ����, ������� ���������� � �������, � �������
        }
        else { // ���� ������ �� ����
            tail->next = new Node(value, tail); // ������� ����� ���� � ��������� ��� � ���������� �������
            tail = tail->next; // ����� ���� ���������� �������
        }
        size++; // ����������� ������ ������
    }

    /// <summary>
    /// ����� ��� ������� ������, ��������� ��� ����
    /// </summary>
    void clear() {
        Node* current = head; // �������� � ������ ������
        while (current) { // ���� ���� ����
            Node* next = current->next; // ��������� ��������� �� ��������� ����
            delete current; // ������� ������� ����
            current = next; // ��������� � ���������� ����
        }
        head = tail = nullptr; // ����� �������� ���� ����� ���������� ���������
        size = 0; // ������ ������ ���������� 0
    }

    /// <summary>
    /// ��������, ���� �� ������
    /// </summary>
    /// <returns>���������� true, ���� ������ ����, ����� false</returns>
    bool empty() const { return size == 0; }

    /// <summary>
    /// ��������� ������� ������
    /// </summary>
    /// <returns>���������� ���������� ��������� � ������</returns>
    size_t getSize() const { return size; }

    // ���������
    class Iterator { // ���������� ����� ��������� ��� ������ ������
    private:
        Node* current; // ��������� �� ������� ����

    public:
        /// <summary>
        /// ����������� ���������, ����������� ��������� �� ����
        /// </summary>
        /// <param name="node">��������� �� ���� ������</param>
        Iterator(Node* node) : current(node) {}

        /// <summary>
        /// �������� �������������, ������������ ������ �������� ���� (�� ����� ���� ������)
        /// </summary>
        /// <returns>���������� ������ �� ������ ����</returns>
        T& operator*() const { return current->data; }

        /// <summary>
        /// �������� �������, ������������ ��������� �� ������ �������� ���� (�� ����� ���� ������)
        /// </summary>
        /// <returns>���������� ��������� �� ������ ����</returns>
        T* operator->() const { return &current->data; }

        /// <summary>
        /// �������� ����������� ����������, ������������ �������� � ���������� ����
        /// </summary>
        /// <returns>���������� ������ �� ������� ��������</returns>
        Iterator& operator++() {
            current = current->next; // ������� � ���������� ����
            return *this; // ���������� ������� ��������
        }

        /// <summary>
        /// �������� ������������ ����������, ������������ �������� � ���������� ����
        /// </summary>
        /// <returns>���������� ������ ��������� ���������</returns>
        Iterator operator++(int) {
            Iterator temp = *this; // ��������� ������� ��������� ���������
            ++(*this); // ��������� � ���������� ����
            return temp; // ���������� ������ ��������� ���������
        }

        /// <summary>
        /// �������� ��������� �� �����������
        /// </summary>
        /// <param name="other">������ �������� ��� ���������</param>
        /// <returns>���������� true, ���� ��������� ��������� �� ������ ����</returns>
        bool operator!=(const Iterator& other) const { return current != other.current; }

        /// <summary>
        /// �������� ��������� �� ���������
        /// </summary>
        /// <param name="other">������ �������� ��� ���������</param>
        /// <returns>���������� true, ���� ��������� ��������� �� ���� � ��� �� ����</returns>
        bool operator==(const Iterator& other) const { return current == other.current; }
    };

    /// <summary>
    /// ����� ��� ��������� ��������� �� ������ ������
    /// </summary>
    /// <returns>���������� ��������, ����������� �� ������ ������� ������</returns>
    Iterator begin() const { return Iterator(head); }

    /// <summary>
    /// ����� ��� ��������� ��������� �� ����� ������ (null-���������)
    /// </summary>
    /// <returns>���������� ��������, ����������� �� null (����� ������)</returns>
    Iterator end() const { return Iterator(nullptr); }

    // ������ ��� ������ � �����������

    /// <summary>
    /// ���������� ������� �� ���� ��������� ��������� ����������
    /// </summary>
    /// <typeparam name="Iterator">��� ���������</typeparam>
    /// <typeparam name="Func">��� �������</typeparam>
    /// <param name="begin">�������� �� ������ ���������</param>
    /// <param name="end">�������� �� ����� ���������</param>
    /// <param name="func">�������, ����������� � ������� ��������</param>
    template<typename Iterator, typename Func>
    void my_for_each(Iterator begin, Iterator end, Func func) {
        while (begin != end) { // ���� �� ��������� �����
            func(*begin); // ��������� ������� � �������� ��������
            ++begin; // ��������� � ���������� ��������
        }
    }

    /// <summary>
    /// ��������, ��� ���� �� ���� ������� ������������� ���������
    /// </summary>
    /// <typeparam name="Iterator">��� ���������</typeparam>
    /// <typeparam name="Predicate">��� ���������</typeparam>
    /// <param name="begin">�������� �� ������ ���������</param>
    /// <param name="end">�������� �� ����� ���������</param>
    /// <param name="pred">�������� ��� �������� ���������</param>
    /// <returns>���������� true, ���� ���� �� ���� ������� ������������� ���������</returns>
    template<typename Iterator, typename Predicate>
    bool my_any_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // ���� ������� ������������� ���������
                return true; // ���������� true
            }
            ++begin; // ��������� � ���������� ��������
        }
        return false; // ���� �� ���� ������� �� ������������� ���������
    }

    /// <summary>
    /// ��������, ��� ��� �������� ������������� ���������
    /// </summary>
    /// <typeparam name="Iterator">��� ���������</typeparam>
    /// <typeparam name="Predicate">��� ���������</typeparam>
    /// <param name="begin">�������� �� ������ ���������</param>
    /// <param name="end">�������� �� ����� ���������</param>
    /// <param name="pred">�������� ��� �������� ���������</param>
    /// <returns>���������� true, ���� ��� �������� ������������� ���������</returns>
    template<typename Iterator, typename Predicate>
    bool my_all_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (!pred(*begin)) { // ���� ������� �� ������������� ���������
                return false; // ���������� false
            }
            ++begin; // ��������� � ���������� ��������
        }
        return true; // ��� �������� ������������� ���������
    }

    template<typename Iterator, typename Predicate>
    /// <summary>
    /// ��������, ��� �� ���� ������� �� ������������� ���������
    /// </summary>
    /// <param name="begin">�������� �� ������ ���������</param>
    /// <param name="end">�������� �� ����� ���������</param>
    /// <param name="pred">�������� ��� �������� ���������</param>
    /// <returns>���������� true, ���� �� ���� ������� �� ������������� ���������</returns>
    bool my_none_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // ���� ���� �� ���� ������� ������������� ���������
                return false; // ���������� ���������� false
            }
            ++begin; // ������� � ���������� ��������
        }
        return true; // ��� �������� �� ������������� ���������, ���������� true
    }

    template<typename InputIterator, typename OutputIterator, typename Func>
    /// <summary>
    /// �������������� ��������� ��������� � ������� ������� � ������ ���������� � ������ ��������
    /// </summary>
    /// <param name="begin">�������� �� ������ ���������</param>
    /// <param name="end">�������� �� ����� ���������</param>
    /// <param name="out">�������� �� ������ �������� ���������</param>
    /// <param name="func">�������, ����������� � ������� ��������</param>
    void my_transform(InputIterator begin, InputIterator end, OutputIterator out, Func func) {
        while (begin != end) {
            *out = func(*begin); // ��������� ������� � �������� � ���������� ��������� � ������� ��������
            ++begin; // ������� � ���������� �������� � �������� ���������
            ++out; // ������� � ���������� �������� � ������� ���������
        }
    }

    template<typename InputIterator, typename OutputIterator, typename Predicate>
    /// <summary>
    /// ����������� ���������, ��������������� ���������, � ������ ��������
    /// </summary>
    /// <param name="begin">�������� �� ������ ���������</param>
    /// <param name="end">�������� �� ����� ���������</param>
    /// <param name="out">�������� �� ������ �������� ���������</param>
    /// <param name="pred">�������� ��� �������� ���������</param>
    void my_copy_if(InputIterator begin, InputIterator end, OutputIterator out, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // ���� ������� ������������� ���������
                *out = *begin; // �������� ��� � ������� ��������
                ++out; // ��������� � ���������� �������� � ������� ���������
            }
            ++begin; // ������� � ���������� �������� � �������� ���������
        }
    }


};

//TODO ��������� ����������� - ����**�
// ������� ��� ������������ ���������� ����������� ����������
void runAlgorithms() {
    DoubleList<int> list;

    // ������������ ���������� ���������
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    assert(list.getSize() == 5); // �������� ������� ������
    assert(!list.empty()); // ��������, ��� ������ �� ������

    /// <summary>
    /// ������ ������������� std::for_each ��� ������������ ��������� ������
    /// </summary>
    /// <param name="list.begin()">�������� �� ������ ����������</param>
    /// <param name="list.end()">�������� �� ����� ����������</param>
    /// <param name="&sum">����������, ������� ������������� �� ������, ��� �������� ����� ���������</param>
    /// <param name="n">������� ������� ������, ������������ � ������</param>
    int sum = 0;
    std::for_each(list.begin(), list.end(), [&sum](int n) { sum += n; });
    assert(sum == 15); // ��������: ����� ������ ���� ����� 15

    /// <summary>
    /// ������ ������������� std::any_of ��� ��������, ���� �� �������� ������ 3
    /// </summary>
    /// <param name="list.begin()">�������� �� ������ ����������</param>
    /// <param name="list.end()">�������� �� ����� ����������</param>
    /// <param name="n">������� ������� ������, ������������ � ������</param>
    /// <returns>���������� true, ���� ���� �� ���� ������� ������ 3</returns>
    bool anyGreaterThan3 = std::any_of(list.begin(), list.end(), [](int n) { return n > 3; });
    assert(anyGreaterThan3);

    /// <summary>
    /// ������ ������������� std::all_of ��� ��������, ��� �� �������� ������ 10
    /// </summary>
    /// <param name="list.begin()">�������� �� ������ ����������</param>
    /// <param name="list.end()">�������� �� ����� ����������</param>
    /// <param name="n">������� ������� ������, ������������ � ������</param>
    /// <returns>���������� true, ���� ��� �������� ������ 10</returns>
    bool allLessThan10 = std::all_of(list.begin(), list.end(), [](int n) { return n < 10; });
    assert(allLessThan10);

    /// <summary>
    /// ������ ������������� std::none_of ��� ��������, ��� �� ���� ������� �� ����� 0
    /// </summary>
    /// <param name="list.begin()">�������� �� ������ ����������</param>
    /// <param name="list.end()">�������� �� ����� ����������</param>
    /// <param name="n">������� ������� ������, ������������ � ������</param>
    /// <returns>���������� true, ���� �� ���� ������� �� ����� 0</returns>
    bool noneEqualTo0 = std::none_of(list.begin(), list.end(), [](int n) { return n == 0; });
    assert(noneEqualTo0);

    /// <summary>
    /// ������ ������������� std::copy_if ��� ����������� ������ ����� � ������ ���������
    /// </summary>
    /// <param name="list.begin()">�������� �� ������ ����������</param>
    /// <param name="list.end()">�������� �� ����� ����������</param>
    /// <param name="evenNumbers">��������� ��� �������� ������ �����</param>
    /// <param name="n">������� ������� ������, ������������ � ������</param>
    /// <returns>�������� ��������, ���� ��� ������</returns>
    DoubleList<int> evenNumbers;
    std::copy_if(list.begin(), list.end(), std::back_inserter(evenNumbers), [](int n) { return n % 2 == 0; });
    assert(evenNumbers.getSize() == 2);  // ��������: ������ ���� 2 ������ �����
    assert(*evenNumbers.begin() == 2);   // ��������: ������ ������ ����� 2
    assert(*(++evenNumbers.begin()) == 4); // ��������: ������ ������ ����� 4

    /// <summary>
    /// ������ ������������� std::for_each ��� ������ ��������� ������ �� �����
    /// </summary>
    /// <param name="list.begin()">�������� �� ������ ����������</param>
    /// <param name="list.end()">�������� �� ����� ����������</param>
    /// <param name="element">������� ������� ������, ������������ � ������</param>
    std::for_each(list.begin(), list.end(), [](int element) {
        std::cout << element << " ";  // ����� �������� �� �����
        });
    std::cout << std::endl;

    // ������� ������
    list.clear();
    assert(list.empty()); // ��������, ��� ������ ���� ����� �������
}



// ������� ��� ������������ ���������������� ���������� //assert TODO
void runMyAlgorithms() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);

    // ������������� ����������������� ��������� ��� ������ ���� ��������� ������
    list.my_for_each(list.begin(), list.end(), [](int n) { std::cout << n << " "; });
    std::cout << std::endl;

    // �������� ����������������� my_any_of
    bool anyGreaterThan5 = list.my_any_of(list.begin(), list.end(), [](int n) { return n > 5; });
    std::cout << "�������� ������ 5: " << anyGreaterThan5 << std::endl;

    // �������� ����������������� my_all_of
    bool allLessThan10 = list.my_all_of(list.begin(), list.end(), [](int n) { return n < 10; });
    std::cout << "��� �������� ������ 10: " << allLessThan10 << std::endl;

    // �������� ����������������� my_none_of
    bool noneEqualTo0 = list.my_none_of(list.begin(), list.end(), [](int n) { return n == 0; });
    std::cout << "�������� �� ������ 0: " << noneEqualTo0 << std::endl;

    // ���������� my_transform ��� �������� �������� ���� ��������� ������
    DoubleList<int> transformedList;
    list.my_transform(list.begin(), list.end(), std::back_inserter(transformedList), [](int n) { return n * 2; });
    list.my_for_each(transformedList.begin(), transformedList.end(), [](int n) { std::cout << n << " "; });
    std::cout << std::endl;

    // ���������� my_copy_if ��� ���������� ������ �����
    DoubleList<int> evenNumbers;
    list.my_copy_if(list.begin(), list.end(), std::back_inserter(evenNumbers), [](int n) { return n % 2 == 0; });
    list.my_for_each(evenNumbers.begin(), evenNumbers.end(), [](int n) { std::cout << n << " "; });
    std::cout << std::endl;
}

// ������� ��� ������������ ���������� � �������� ������� ������
void runBSTAlgorithms() {
    BinarySearchTree<int> bst; // �������� ��������� ������ ������
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(17);

    // �������� ������ my_for_each ��� ������������� ������ ������
    std::vector<int> inorderResult;
    bst.my_for_each(bst.begin(), bst.end(), [&inorderResult](int n) { inorderResult.push_back(n); });
    std::vector<int> expectedInorder = { 3, 5, 7, 10, 12, 15, 17 };
    assert(inorderResult == expectedInorder); // �������� ������������� ������

    // �������� ������ my_any_of
    bool anyGreaterThan10 = bst.my_any_of(bst.begin(), bst.end(), [](int n) { return n > 10; });
    assert(anyGreaterThan10 == true); // ���� �������� ������ 10

    // �������� ������ my_all_of
    bool allLessThan20 = bst.my_all_of(bst.begin(), bst.end(), [](int n) { return n < 20; });
    assert(allLessThan20 == true); // ��� �������� ������ 20

    // �������� ������ my_none_of
    bool noneEqualTo100 = bst.my_none_of(bst.begin(), bst.end(), [](int n) { return n == 100; });
    assert(noneEqualTo100 == true); // ��� ���������, ������ 100

    // �������� ������ my_transform
    std::vector<int> transformedResult;
    bst.my_transform(bst.begin(), bst.end(), std::back_inserter(transformedResult), [](int n) { return n * 2; });
    std::vector<int> expectedTransformed = { 6, 10, 14, 20, 24, 30, 34 };
    assert(transformedResult == expectedTransformed); // ��� �������� �������� �� 2

    // �������� ������ my_copy_if
    std::vector<int> evenNumbers;
    bst.my_copy_if(bst.begin(), bst.end(), std::back_inserter(evenNumbers), [](int n) { return n % 2 == 0; });
    std::vector<int> expectedEvens = { 10, 12 };
    assert(evenNumbers == expectedEvens); // ��������� ������ ������ �����
}
