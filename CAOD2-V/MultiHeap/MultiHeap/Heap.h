//���� ����� ���-22

#include <cassert>   // ���������� ��� ������������� assert
#include <iostream>  // ���������� ��� ����� � ������
#include <stdexcept> // ���������� ��� ��������� ����������
#include <vector>    // ��� ������������� �������
#include <algorithm>

///���� ��� ����� ��������� ������, ������� ������� �� ����� ���������� 0, 1, 2 �������; ������������ ���� - ������������ ������� � �����
///����������� ���� - ������������ ������� � �������; ���� ������ �� ������, ������ ��� ��������� ���� ����������� ������� ��� ����������� �������.


/// <summary>
/// ��������� ����� MinHeap ��������� ����������� ���� � �������������� ������������� �������.
/// </summary>
template <typename T>
class MinHeap {
private:
    T* heap;          // ��������� �� ������ ���������
    size_t capacity;  // ����������� �������
    size_t size;      // ������� ������ ����

    /// <summary>
    /// ����������� ����������� ������� � 2 ����, ����� �� ������� �����.
    /// </summary>
    void resize() {
        capacity *= 2;                   // ����������� �����������
        T* newHeap = new T[capacity];    // ������� ����� ������ � ����������� ������������
        for (size_t i = 0; i < size; i++) {
            newHeap[i] = heap[i];        // �������� �������� � ����� ������
        }
        delete[] heap;                   // ����������� ������ ������
        heap = newHeap;                  // ��������� ��������� �� ����� ������
    }

    /// <summary>
    /// heapifyUp ������������ �������� ����������� ���� ��� ���������� ��������.
    /// </summary>
    /// <param name="index">������ ��������, ������� ����� ����������� �����.</param>
    void heapifyUp(size_t index) {
        while (index > 0) { // ���� ������ �� �������� (������ > 0)
            size_t parentIndex = (index - 1) / 2; // ������ ������ ������������� ��������
            if (heap[index] >= heap[parentIndex]) break; // ���� ������� ������ ��� ����� ��������, �������
            std::swap(heap[index], heap[parentIndex]); // ������ ������� ������� � ��������
            index = parentIndex; // ����������� � ��������
        }
    }

    /// <summary>
    /// heapifyDown ������������ �������� ����������� ���� ��� �������� ������������ ��������.
    /// </summary>
    /// <param name="index">������ ��������, ������� ����� ����������� ����.</param>
    void heapifyDown(size_t index) {
        size_t leftChild = 2 * index + 1; // ������ ������ �������
        size_t rightChild = 2 * index + 2; // ������ ������� �������
        size_t smallest = index; // ������������, ��� ������� ������� � ����������

        if (leftChild < size && heap[leftChild] < heap[smallest]) { // ��������� ����� �������
            smallest = leftChild; // ���� �� ������ ��������, ��������� smallest
        }

        if (rightChild < size && heap[rightChild] < heap[smallest]) { // ��������� ������ �������
            smallest = rightChild; // ���� �� ������ ��������, ��������� smallest
        }

        if (smallest != index) { // ���� ���������� ������� �� �������
            std::swap(heap[index], heap[smallest]); // ������ �� �������
            heapifyDown(smallest); // �������� ������� ������
        }
    }

public:
    /// <summary>
    /// ����������� ��� ������������� ����������� ���� � �������� ��������� ������������.
    /// </summary>
    /// <param name="initialCapacity">��������� ����������� �������.</param>
    MinHeap(size_t initialCapacity = 10) {
        capacity = initialCapacity;
        size = 0;
        heap = new T[capacity]; // �������� ������ ��� �������
    }

    /// <summary>
    /// ���������� ��� ������������ ���������� ������.
    /// </summary>
    ~MinHeap() {
        delete[] heap; // ����������� ������
    }

    /// <summary>
    /// insert ��������� ����� ������� � ����.
    /// </summary>
    /// <param name="value">�������� ��������, ������� ����� ��������.</param>
    void insert(T value) {
        if (size == capacity) {
            resize(); // ���� ����� ���, ����������� ������
        }
        heap[size] = value; // ��������� ������� � ����� �������
        heapifyUp(size);    // ��������� ��� �� ������� �����
        size++;             // ����������� ������ ����
    }

    /// <summary>
    /// extractMin ��������� ����������� ������� �� ����.
    /// </summary>
    /// <returns>���������� ����������� �������.</returns>
    /// <exception cref="std::out_of_range">���������� �������������, ���� ���� �����.</exception>
    T extractMin() {
        if (size == 0) { // ���� ���� ������, ����������� ����������
            throw std::out_of_range("Heap is empty");
        }

        T minVal = heap[0];  // ��������� ����������� ������� (������ ����)
        heap[0] = heap[size - 1]; // �������� ������ ��������� ���������
        size--;                 // ��������� ������ ����
        heapifyDown(0);         // �������� ����� ������ �� ������� �����
        return minVal;          // ���������� ����������� �������
    }

    /// <summary>
    /// getMin ���������� ����������� ������� ��� ��� ��������.
    /// </summary>
    /// <returns>���������� ����������� �������.</returns>
    /// <exception cref="std::out_of_range">���������� �������������, ���� ���� �����.</exception>
    T getMin() const {
        if (size == 0) { // ���� ���� ������, ����������� ����������
            throw std::out_of_range("Heap is empty");
        }
        return heap[0]; // ���������� ����������� ������� (������ ����)
    }

    // ���������� ��������� �� ���������� ������ ��������� ����
    const T* getHeap() const {
        return heap;
    }

    // ��������, ����� �� ����
    bool isEmpty() const {
        return size == 0;
    }

    // ��������� ������� ����
    size_t getSize() const {
        return size;
    }

    /// <summary>
    /// getSorted ���������� ������ ���� ��������� � ��������������� ����.
    /// </summary>
    /// <returns>������ ��������������� ���������.</returns>
    std::vector<T> getSorted() {
        std::vector<T> sortedHeap;
        while (!isEmpty()) {
            sortedHeap.push_back(extractMin()); // ��������� ����������� ������� � ��������� ��� � ������
        }
        return sortedHeap;
    }

    /// <summary>
    /// printHeap ������� �������� ���� ��� �������.
    /// </summary>
    /// <remarks>�������� ��������� � ������� � ���� ������, ����������� ���������.</remarks>
    void printHeap() const {
        for (size_t i = 0; i < size; i++) { // �������� �� ���� ��������� �������
            std::cout << heap[i] << " "; // ������� ������ �������
        }
        std::cout << std::endl; // ������� �� ����� ������ ����� ������ ���� ���������
    }

    /// <summary>
    /// heapSort ��������� ������������� ���������� �������.
    /// </summary>
    /// <param name="arr">������ ���������, ������� ����� �������������.</param>
    /// <returns>��������������� ������ ���������.</returns>
    std::vector<T> heapSort(const std::vector<T>& arr) {
        MinHeap<T> heap(arr.size());

        // ���������� ���� ����������
        for (const T& element : arr) {
            heap.insert(element);
        }

        std::vector<T> sorted;

        // ���������� ��������� �� ���� ��� ��������� ���������������� �������
        while (!heap.isEmpty()) {
            sorted.push_back(heap.extractMin());
        }

        return sorted;
    }

    /// <summary>
    /// tournamentSort ��������� ��������� ���������� �������.
    /// </summary>
    /// <param name="arr">������ ���������, ������� ����� �������������.</param>
    /// <returns>������ � ������������ ��������� � ����������� ������� (���������� ������� �������).</returns>
    std::vector<T> tournamentSort(std::vector<T> arr) {
        while (arr.size() > 1) {
            std::vector<T> winners;

            // �������� �� ������� � ���������� �������� ������
            for (size_t i = 0; i < arr.size(); i += 2) {
                if (i + 1 < arr.size()) {
                    // ��������� ������� �� ���� ���������
                    winners.push_back(std::min(arr[i], arr[i + 1]));
                }
                else {
                    // ���� �������� ���������� ���������, ��������� ��������� ������� � ����������
                    winners.push_back(arr[i]);
                }
            }

            // ��������� ������ ������������ �������� ������
            arr = winners;
        }

        return arr;
    }


    // �������� ��� ������ ����
    class Iterator {
    private:
        size_t index; // ������ �������� �������� � ����
        MinHeap<T>* heap; // ��������� �� ����

    public:
        // ����������� ��������� ��������� �� ���� � �������������� ������
        Iterator(MinHeap<T>* h, size_t idx) : heap(h), index(idx) {}

        // �������� ������������� ���������� ������� �������
        T& operator*() {
            return heap->heap[index];
        }

        // ���������� �������� ���������� ��� �������� � ���������� ��������
        Iterator& operator++() {
            index++; // ��������� � ���������� ��������
            return *this; // ���������� �������� ��� ����������� ������
        }

        // �������� != ��� ��������� ����������
        bool operator!=(const Iterator& other) const {
            return index != other.index; // ���������� true, ���� ������� �� �����
        }
    };

    // �������, ������������ �������� �� ������ ����
    Iterator begin() {
        return Iterator(this, 0); // �������� � ������� 0
    }

    // �������, ������������ �������� �� ����� ����
    Iterator end() {
        return Iterator(this, size); // ����� ���� � ��� ������ size
    }
    //TODO test 
};

/// <summary>
/// ������� ��� ������������ MinHeap � ������� assert.
/// �������� ������������ �������, ���������� ����������� ���������,
/// � ����� ������������ ������������� � ��������� ����������,
/// � �������� ��������� MinHeap � ������� std::is_heap.
/// </summary>
/// <summary>
/// ������� ��� ������������ MinHeap � ������� assert.
/// �������� ������������ �������, ���������� ����������� ���������,
/// � ����� ������������ ������������� � ��������� ����������,
/// � �������� ��������� MinHeap � ������� std::is_heap.
/// </summary>
void testMinHeap() {
    MinHeap<int> heap;

    // ������������ ���������� ���������
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(3);

    // ����� ��������� ��� �������
    heap.printHeap();

    // ��������� �������� ����� ������� ���������
    std::vector<int> expectedOrder = { 3, 5, 15, 10 };
    size_t index = 0;

    // ������������ ��������� ����� ���� for
    for (auto it = heap.begin(); it != heap.end(); ++it) {
        std::cout << "���������: " << *it << ", ���������: " << expectedOrder[index] << std::endl; // ���������� �����
        assert(*it == expectedOrder[index]); // ��������, ��� �������� ���������
        index++;
    }
    assert(index == expectedOrder.size()); // ��������, ��� �������� ��������� ���������� ���������

    // �������� ������������ ��������
    assert(heap.getMin() == 3); // ����������� ������� ������ ���� 3

    // ��������, ��� ������ ������ MinHeap �������� ����������� �����
    // ���������� std::is_heap � ������������ std::greater ��� �������� MinHeap
    assert(std::is_heap(heap.getHeap(), heap.getHeap() + heap.getSize(), std::greater<int>())); // �������� �� ������������ ����

    // ������������ ���������� ������������ ��������
    assert(heap.extractMin() == 3); // ����������� ������� ������ ���� 3
    assert(heap.getMin() == 5);     // ����� ���������� ����������� ������� ������ ���� 5

    // ������������ ����������� ����������
    assert(heap.extractMin() == 5);  // ����������� ������� ������ ���� 5
    assert(heap.extractMin() == 10); // ����������� ������� ������ ���� 10
    assert(heap.extractMin() == 15); // ����������� ������� ������ ���� 15

    // ��������, ��� ���� �����
    assert(heap.isEmpty()); // ���� ������ ���� ������

    // �������������� ����� ��� ����������
    std::vector<int> arr = { 10, 5, 20, 2, 8, 15 };

    // ������������ ������������� ����������
    std::vector<int> heapSorted = heap.heapSort(arr);
    std::vector<int> expectedSorted = { 2, 5, 8, 10, 15, 20 };
    assert(heapSorted == expectedSorted); // ��������, ��� ���������� �������� ���������

    // ������������ ��������� ����������
    std::vector<int> tournamentSorted = heap.tournamentSort(arr);
    assert(tournamentSorted[0] == 2); // ��������, ��� ����������� ������� ���������� � ��������� ����������
}



/// <summary>
/// ��������� ����� MaxHeap ��������� ������������ ���� � �������������� ������������� �������.
/// </summary>
template <typename T>
class MaxHeap {
private:
    T* heap;          // ��������� �� ������ ���������
    size_t capacity;  // ����������� �������
    size_t size;      // ������� ������ ����

    /// <summary>
    /// ����������� ����������� ������� � 2 ����, ����� �� ������� �����.
    /// </summary>
    void resize() {
        capacity *= 2;                   // ����������� �����������
        T* newHeap = new T[capacity];    // ������� ����� ������ � ����������� ������������
        for (size_t i = 0; i < size; i++) {
            newHeap[i] = heap[i];        // �������� �������� � ����� ������
        }
        delete[] heap;                   // ����������� ������ ������
        heap = newHeap;                  // ��������� ��������� �� ����� ������
    }

    /// <summary>
    /// heapifyUp ������������ �������� ������������ ���� ��� ���������� ��������.
    /// </summary>
    /// <param name="index">������ ��������, ������� ����� ����������� �����.</param>
    void heapifyUp(size_t index) {
        while (index > 0) { // ���� ������ �� �������� (������ > 0)
            size_t parentIndex = (index - 1) / 2; // ������ ������ ������������� ��������
            if (heap[index] <= heap[parentIndex]) break; // ���� ������� ������ ��� ����� ��������, �������
            std::swap(heap[index], heap[parentIndex]); // ������ ������� ������� � ��������
            index = parentIndex; // ����������� � ��������
        }
    }

    /// <summary>
    /// heapifyDown ������������ �������� ������������ ���� ��� �������� ������������� ��������.
    /// </summary>
    /// <param name="index">������ ��������, ������� ����� ����������� ����.</param>
    void heapifyDown(size_t index) {
        size_t leftChild = 2 * index + 1; // ������ ������ �������
        size_t rightChild = 2 * index + 2; // ������ ������� �������
        size_t largest = index; // ������������, ��� ������� ������� � ����������

        if (leftChild < size && heap[leftChild] > heap[largest]) { // ��������� ����� �������
            largest = leftChild; // ���� �� ������ ��������, ��������� largest
        }

        if (rightChild < size && heap[rightChild] > heap[largest]) { // ��������� ������ �������
            largest = rightChild; // ���� �� ������ ��������, ��������� largest
        }

        if (largest != index) { // ���� ���������� ������� �� �������
            std::swap(heap[index], heap[largest]); // ������ �� �������
            heapifyDown(largest); // �������� ������� ������
        }
    }

public:
    /// <summary>
    /// ����������� ��� ������������� ������������ ���� � �������� ��������� ������������.
    /// </summary>
    /// <param name="initialCapacity">��������� ����������� �������.</param>
    MaxHeap(size_t initialCapacity = 10) {
        capacity = initialCapacity;
        size = 0;
        heap = new T[capacity]; // �������� ������ ��� �������
    }

    /// <summary>
    /// ���������� ��� ������������ ���������� ������.
    /// </summary>
    ~MaxHeap() {
        delete[] heap; // ����������� ������
    }

    // ���������� ��������� �� ���������� ������ ��������� ����
    const T* getHeap() const {
        return heap;
    }

    // ��������, ����� �� ����
    bool isEmpty() const {
        return size == 0;
    }

    // ��������� ������� ����
    size_t getSize() const {
        return size;
    }

    /// <summary>
    /// insert ��������� ����� ������� � ����.
    /// </summary>
    /// <param name="value">�������� ��������, ������� ����� ��������.</param>
    void insert(T value) {
        if (size == capacity) {
            resize(); // ���� ����� ���, ����������� ������
        }
        heap[size] = value; // ��������� ������� � ����� �������
        heapifyUp(size);    // ��������� ��� �� ������� �����
        size++;             // ����������� ������ ����
    }

    /// <summary>
    /// extractMax ��������� ������������ ������� �� ����.
    /// </summary>
    /// <returns>���������� ������������ �������.</returns>
    /// <exception cref="std::out_of_range">���������� �������������, ���� ���� �����.</exception>
    T extractMax() {
        if (size == 0) { // ���� ���� ������, ����������� ����������
            throw std::out_of_range("Heap is empty");
        }

        T maxVal = heap[0];  // ��������� ������������ ������� (������ ����)
        heap[0] = heap[size - 1]; // �������� ������ ��������� ���������
        size--;                 // ��������� ������ ����
        heapifyDown(0);         // �������� ����� ������ �� ������� �����
        return maxVal;          // ���������� ������������ �������
    }

    /// <summary>
    /// getMax ���������� ������������ ������� ��� ��� ��������.
    /// </summary>
    /// <returns>���������� ������������ �������.</returns>
    /// <exception cref="std::out_of_range">���������� �������������, ���� ���� �����.</exception>
    T getMax() const {
        if (size == 0) { // ���� ���� ������, ����������� ����������
            throw std::out_of_range("Heap is empty");
        }
        return heap[0]; // ���������� ������������ ������� (������ ����)
    }

    /// <summary>
    /// getSorted ���������� ������ ���� ��������� � ��������������� ����.
    /// </summary>
    /// <returns>������ ��������������� ���������.</returns>
    std::vector<T> getSorted() {
        std::vector<T> sortedHeap;
        while (!isEmpty()) {
            sortedHeap.push_back(extractMax()); // ��������� ������������ ������� � ��������� ��� � ������
        }
        return sortedHeap;
    }

    /// <summary>
    /// printHeap ������� �������� ���� ��� �������.
    /// </summary>
    void printHeap() const {
        for (size_t i = 0; i < size; i++) { // �������� �� ���� ��������� �������
            std::cout << heap[i] << " "; // ������� ������ �������
        }
        std::cout << std::endl; // ������� �� ����� ������ ����� ������ ���� ���������
    }

    /// <summary>
    /// ������������� ���������� �������.
    /// </summary>
    std::vector<T> heapSort(const std::vector<T>& arr) {
        MaxHeap<T> heap(arr.size());

        // ���������� ���� ����������
        for (const T& element : arr) {
            heap.insert(element);
        }

        std::vector<T> sorted;

        // ���������� ��������� �� ���� ��� ��������� ���������������� �������
        while (!heap.isEmpty()) {
            sorted.push_back(heap.extractMax());
        }

        return sorted;
    }

    /// <summary>
    /// ��������� ���������� �������.
    /// </summary>
    std::vector<T> tournamentSort(std::vector<T> arr) {
        while (arr.size() > 1) {
            std::vector<T> winners;

            // �������� �� ������� � ���������� �������� ������
            for (size_t i = 0; i < arr.size(); i += 2) {
                if (i + 1 < arr.size()) {
                    // ��������� ������� �� ���� ���������
                    winners.push_back(std::max(arr[i], arr[i + 1]));
                }
                else {
                    // ���� �������� ���������� ���������, ��������� ��������� ������� � ����������
                    winners.push_back(arr[i]);
                }
            }

            // ��������� ������ ������������ �������� ������
            arr = winners;
        }

        return arr;

    }

    // �������� ��� ������ ����
    class Iterator {
    private:
        size_t index; // ������ �������� �������� � ����
        MaxHeap<T>* heap; // ��������� �� ����

    public:
        // ����������� ��������� ��������� �� ���� � �������������� ������
        Iterator(MaxHeap<T>* h, size_t idx) : heap(h), index(idx) {}

        // �������� ������������� ���������� ������� �������
        T& operator*() {
            return heap->heap[index];
        }

        // ���������� �������� ���������� ��� �������� � ���������� ��������
        Iterator& operator++() {
            index++; // ��������� � ���������� ��������
            return *this; // ���������� �������� ��� ����������� ������
        }

        // �������� != ��� ��������� ����������
        bool operator!=(const Iterator& other) const {
            return index != other.index; // ���������� true, ���� ������� �� �����
        }
    };

    // �������, ������������ �������� �� ������ ����
    Iterator begin() {
        return Iterator(this, 0); // �������� � ������� 0
    }

    // �������, ������������ �������� �� ����� ����
    Iterator end() {
        return Iterator(this, size); // ����� ���� � ��� ������ size
    }

};


/// <summary>
/// ������� ��� ������������ MaxHeap � ������� assert.
/// �������� ������������ �������, ���������� ������������ ���������,
/// � ����� ������������ ������������� � ��������� ����������,
/// �������� ��������� MaxHeap � ������� std::is_heap � �������������� �������� � ����������.
/// </summary>
void testMaxHeap() {
    MaxHeap<int> heap;

    // ������������ ���������� ���������
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(20);

    // ����� ��������� ��� �������
    heap.printHeap(); // ����� ��� ������ ����������� ����

    // ��������� �������� ����� ������� ���������
    std::vector<int> expectedOrder = { 20, 15, 10, 5 }; // ������� ��������� ������� �� ���������� ����
    size_t index = 0;

    // ������������ ��������� ����� ���� for
    for (auto it = heap.begin(); it != heap.end(); ++it) {
        std::cout << "��������: " << *it << ", ���������: " << expectedOrder[index] << std::endl; // ���������� �����
        assert(*it == expectedOrder[index]); // ��������, ��� �������� ���������
        index++;
    }
    assert(index == expectedOrder.size()); // ��������, ��� �������� ��������� ���������� ���������

    // ����� ���� �������� � ����������� �� 5
    std::cout << "�������� � ���� +5: ";
    for (auto it = heap.begin(); it != heap.end(); ++it) {
        std::cout << (*it + 5) << " "; // ����� �������� � ����������� 5
    }
    std::cout << std::endl;

    // ����� ������ ������ ����� � ����
    std::cout << "������ �������� � ����: ";
    for (auto it = heap.begin(); it != heap.end(); ++it) {
        if (*it % 2 == 0) {
            std::cout << *it << " "; // ����� ������ ������ ��������
        }
    }
    std::cout << std::endl;

    // �������� ������������� ��������
    assert(heap.getMax() == 20); // ������������ ������� ������ ���� 20

    // ������������ ���������� ������������� ��������
    assert(heap.extractMax() == 20); // ������������ ������� ������ ���� 20
    assert(heap.getMax() == 15);     // ����� ���������� ������������ ������� ������ ���� 15

    // ������������ ����������� ����������
    assert(heap.extractMax() == 15);  // ������������ ������� ������ ���� 15
    assert(heap.extractMax() == 10);  // ������������ ������� ������ ���� 10
    assert(heap.extractMax() == 5);   // ������������ ������� ������ ���� 5

    // ��������, ��� ���� �����
    assert(heap.isEmpty()); // ���� ������ ���� ������

    // �������������� ����� ��� ����������
    std::vector<int> arr = { 10, 5, 20, 2, 8, 15 };

    // ������������ ������������� ����������
    std::vector<int> heapSorted = heap.heapSort(arr);
    std::vector<int> expectedSorted = { 20, 15, 10, 8, 5, 2 };
    assert(heapSorted == expectedSorted); // ��������, ��� ���������� �������� ���������

    // ������������ ��������� ����������
    std::vector<int> tournamentSorted = heap.tournamentSort(arr);
    assert(tournamentSorted[0] == 20); // ��������, ��� ������������ ������� ���������� � ��������� ����������

    // �������� ��������� ���� ����� std::is_heap
    assert(std::is_heap(heap.getHeap(), heap.getHeap() + heap.getSize(), std::less<int>())); // �������� �� ������������ ������������ ����

    // �������� ����� ���� � ����� ���������
    MaxHeap<int> singleElementHeap;
    singleElementHeap.insert(20); // ��������� ������� 20

    // ������������� ��������� ��� ��������� ��������
    for (auto it = singleElementHeap.begin(); it != singleElementHeap.end(); ++it) {
        *it += 22; // ����������� ������� �� 22
    }

    // �������� ������ ��������
    assert(singleElementHeap.getMax() == 42); // ������ ������������ �������� ������ ���� 42
    std::cout << "������ ����� ������� ������ �������������: " << singleElementHeap.getMax() << std::endl;
}
