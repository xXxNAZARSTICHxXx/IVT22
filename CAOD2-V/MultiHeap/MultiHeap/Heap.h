//Стич Назар ИВТ-22

#include <cassert>   // Библиотека для использования assert
#include <iostream>  // Библиотека для ввода и вывода
#include <stdexcept> // Библиотека для обработки исключений
#include <vector>    // Для использования вектора
#include <algorithm>

///Куча это такая структура данных, которая состоит из узлов содержащие 0, 1, 2 потомка; Максимальная куча - максимальный элемент в корне
///Минимальная куча - максимальный элемент в листьях; Куча похоже на дерево, только она старается быть совершенным деревом или законченным деревом.


/// <summary>
/// Шаблонный класс MinHeap реализует минимальную кучу с использованием динамического массива.
/// </summary>
template <typename T>
class MinHeap {
private:
    T* heap;          // Указатель на массив элементов
    size_t capacity;  // Вместимость массива
    size_t size;      // Текущий размер кучи

    /// <summary>
    /// Увеличивает вместимость массива в 2 раза, когда не хватает места.
    /// </summary>
    void resize() {
        capacity *= 2;                   // Увеличиваем вместимость
        T* newHeap = new T[capacity];    // Создаем новый массив с увеличенной вместимостью
        for (size_t i = 0; i < size; i++) {
            newHeap[i] = heap[i];        // Копируем элементы в новый массив
        }
        delete[] heap;                   // Освобождаем старый массив
        heap = newHeap;                  // Обновляем указатель на новый массив
    }

    /// <summary>
    /// heapifyUp поддерживает свойство минимальной кучи при добавлении элемента.
    /// </summary>
    /// <param name="index">Индекс элемента, который нужно переместить вверх.</param>
    void heapifyUp(size_t index) {
        while (index > 0) { // Пока индекс не корневой (индекс > 0)
            size_t parentIndex = (index - 1) / 2; // Найдем индекс родительского элемента
            if (heap[index] >= heap[parentIndex]) break; // Если элемент больше или равен родителю, выходим
            std::swap(heap[index], heap[parentIndex]); // Меняем местами элемент и родителя
            index = parentIndex; // Поднимаемся к родителю
        }
    }

    /// <summary>
    /// heapifyDown поддерживает свойство минимальной кучи при удалении минимального элемента.
    /// </summary>
    /// <param name="index">Индекс элемента, который нужно переместить вниз.</param>
    void heapifyDown(size_t index) {
        size_t leftChild = 2 * index + 1; // Индекс левого потомка
        size_t rightChild = 2 * index + 2; // Индекс правого потомка
        size_t smallest = index; // Предполагаем, что текущий элемент — наименьший

        if (leftChild < size && heap[leftChild] < heap[smallest]) { // Проверяем левый потомок
            smallest = leftChild; // Если он меньше текущего, обновляем smallest
        }

        if (rightChild < size && heap[rightChild] < heap[smallest]) { // Проверяем правый потомок
            smallest = rightChild; // Если он меньше текущего, обновляем smallest
        }

        if (smallest != index) { // Если наименьший элемент не текущий
            std::swap(heap[index], heap[smallest]); // Меняем их местами
            heapifyDown(smallest); // Спускаем элемент дальше
        }
    }

public:
    /// <summary>
    /// Конструктор для инициализации минимальной кучи с заданной начальной вместимостью.
    /// </summary>
    /// <param name="initialCapacity">Начальная вместимость массива.</param>
    MinHeap(size_t initialCapacity = 10) {
        capacity = initialCapacity;
        size = 0;
        heap = new T[capacity]; // Выделяем память для массива
    }

    /// <summary>
    /// Деструктор для освобождения выделенной памяти.
    /// </summary>
    ~MinHeap() {
        delete[] heap; // Освобождаем память
    }

    /// <summary>
    /// insert добавляет новый элемент в кучу.
    /// </summary>
    /// <param name="value">Значение элемента, которое нужно добавить.</param>
    void insert(T value) {
        if (size == capacity) {
            resize(); // Если места нет, увеличиваем массив
        }
        heap[size] = value; // Добавляем элемент в конец массива
        heapifyUp(size);    // Поднимаем его до нужного места
        size++;             // Увеличиваем размер кучи
    }

    /// <summary>
    /// extractMin извлекает минимальный элемент из кучи.
    /// </summary>
    /// <returns>Возвращает минимальный элемент.</returns>
    /// <exception cref="std::out_of_range">Исключение выбрасывается, если куча пуста.</exception>
    T extractMin() {
        if (size == 0) { // Если куча пустая, выбрасываем исключение
            throw std::out_of_range("Heap is empty");
        }

        T minVal = heap[0];  // Сохраняем минимальный элемент (корень кучи)
        heap[0] = heap[size - 1]; // Заменяем корень последним элементом
        size--;                 // Уменьшаем размер кучи
        heapifyDown(0);         // Опускаем новый корень до нужного места
        return minVal;          // Возвращаем минимальный элемент
    }

    /// <summary>
    /// getMin возвращает минимальный элемент без его удаления.
    /// </summary>
    /// <returns>Возвращает минимальный элемент.</returns>
    /// <exception cref="std::out_of_range">Исключение выбрасывается, если куча пуста.</exception>
    T getMin() const {
        if (size == 0) { // Если куча пустая, выбрасываем исключение
            throw std::out_of_range("Heap is empty");
        }
        return heap[0]; // Возвращаем минимальный элемент (корень кучи)
    }

    // Возвращаем указатель на внутренний массив элементов кучи
    const T* getHeap() const {
        return heap;
    }

    // Проверка, пуста ли куча
    bool isEmpty() const {
        return size == 0;
    }

    // Получение размера кучи
    size_t getSize() const {
        return size;
    }

    /// <summary>
    /// getSorted возвращает массив всех элементов в отсортированном виде.
    /// </summary>
    /// <returns>Вектор отсортированных элементов.</returns>
    std::vector<T> getSorted() {
        std::vector<T> sortedHeap;
        while (!isEmpty()) {
            sortedHeap.push_back(extractMin()); // Извлекаем минимальный элемент и добавляем его в вектор
        }
        return sortedHeap;
    }

    /// <summary>
    /// printHeap выводит элементы кучи для отладки.
    /// </summary>
    /// <remarks>Элементы выводятся в консоль в одну строку, разделенные пробелами.</remarks>
    void printHeap() const {
        for (size_t i = 0; i < size; i++) { // Проходим по всем элементам массива
            std::cout << heap[i] << " "; // Выводим каждый элемент
        }
        std::cout << std::endl; // Переход на новую строку после вывода всех элементов
    }

    /// <summary>
    /// heapSort выполняет пирамидальную сортировку массива.
    /// </summary>
    /// <param name="arr">Массив элементов, который нужно отсортировать.</param>
    /// <returns>Отсортированный вектор элементов.</returns>
    std::vector<T> heapSort(const std::vector<T>& arr) {
        MinHeap<T> heap(arr.size());

        // Заполнение кучи элементами
        for (const T& element : arr) {
            heap.insert(element);
        }

        std::vector<T> sorted;

        // Извлечение элементов из кучи для получения отсортированного массива
        while (!heap.isEmpty()) {
            sorted.push_back(heap.extractMin());
        }

        return sorted;
    }

    /// <summary>
    /// tournamentSort выполняет турнирную сортировку массива.
    /// </summary>
    /// <param name="arr">Массив элементов, который нужно отсортировать.</param>
    /// <returns>Вектор с единственным элементом — победителем турнира (наименьший элемент массива).</returns>
    std::vector<T> tournamentSort(std::vector<T> arr) {
        while (arr.size() > 1) {
            std::vector<T> winners;

            // Проходим по массиву и сравниваем элементы парами
            for (size_t i = 0; i < arr.size(); i += 2) {
                if (i + 1 < arr.size()) {
                    // Побеждает меньший из двух элементов
                    winners.push_back(std::min(arr[i], arr[i + 1]));
                }
                else {
                    // Если нечетное количество элементов, добавляем последний элемент в победители
                    winners.push_back(arr[i]);
                }
            }

            // Обновляем массив победителями текущего раунда
            arr = winners;
        }

        return arr;
    }


    // Итератор для обхода кучи
    class Iterator {
    private:
        size_t index; // Индекс текущего элемента в куче
        MinHeap<T>* heap; // Указатель на кучу

    public:
        // Конструктор принимает указатель на кучу и инициализирует индекс
        Iterator(MinHeap<T>* h, size_t idx) : heap(h), index(idx) {}

        // Оператор разыменования возвращает текущий элемент
        T& operator*() {
            return heap->heap[index];
        }

        // Префиксный оператор инкремента для перехода к следующему элементу
        Iterator& operator++() {
            index++; // Переходим к следующему элементу
            return *this; // Возвращаем итератор для цепочечного вызова
        }

        // Оператор != для сравнения итераторов
        bool operator!=(const Iterator& other) const {
            return index != other.index; // Возвращаем true, если индексы не равны
        }
    };

    // Функция, возвращающая итератор на начало кучи
    Iterator begin() {
        return Iterator(this, 0); // Начинаем с индекса 0
    }

    // Функция, возвращающая итератор на конец кучи
    Iterator end() {
        return Iterator(this, size); // Конец кучи — это индекс size
    }
    //TODO test 
};

/// <summary>
/// Функция для тестирования MinHeap с помощью assert.
/// Включает тестирование вставки, извлечения минимальных элементов,
/// а также тестирование пирамидальной и турнирной сортировок,
/// и проверку структуры MinHeap с помощью std::is_heap.
/// </summary>
/// <summary>
/// Функция для тестирования MinHeap с помощью assert.
/// Включает тестирование вставки, извлечения минимальных элементов,
/// а также тестирование пирамидальной и турнирной сортировок,
/// и проверку структуры MinHeap с помощью std::is_heap.
/// </summary>
void testMinHeap() {
    MinHeap<int> heap;

    // Тестирование добавления элементов
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(3);

    // Вывод элементов для отладки
    heap.printHeap();

    // Ожидаемое значение после вставки элементов
    std::vector<int> expectedOrder = { 3, 5, 15, 10 };
    size_t index = 0;

    // Тестирование итератора через цикл for
    for (auto it = heap.begin(); it != heap.end(); ++it) {
        std::cout << "Настоящее: " << *it << ", Ожидалось: " << expectedOrder[index] << std::endl; // Отладочный вывод
        assert(*it == expectedOrder[index]); // Проверка, что элементы совпадают
        index++;
    }
    assert(index == expectedOrder.size()); // Проверка, что пройдено ожидаемое количество элементов

    // Проверка минимального элемента
    assert(heap.getMin() == 3); // Минимальный элемент должен быть 3

    // Проверка, что массив внутри MinHeap является минимальной кучей
    // Используем std::is_heap с компаратором std::greater для проверки MinHeap
    assert(std::is_heap(heap.getHeap(), heap.getHeap() + heap.getSize(), std::greater<int>())); // Проверка на корректность кучи

    // Тестирование извлечения минимального элемента
    assert(heap.extractMin() == 3); // Минимальный элемент должен быть 3
    assert(heap.getMin() == 5);     // После извлечения минимальный элемент должен быть 5

    // Тестирование дальнейшего извлечения
    assert(heap.extractMin() == 5);  // Минимальный элемент должен быть 5
    assert(heap.extractMin() == 10); // Минимальный элемент должен быть 10
    assert(heap.extractMin() == 15); // Минимальный элемент должен быть 15

    // Проверка, что куча пуста
    assert(heap.isEmpty()); // Куча должна быть пустой

    // Дополнительные тесты для сортировки
    std::vector<int> arr = { 10, 5, 20, 2, 8, 15 };

    // Тестирование пирамидальной сортировки
    std::vector<int> heapSorted = heap.heapSort(arr);
    std::vector<int> expectedSorted = { 2, 5, 8, 10, 15, 20 };
    assert(heapSorted == expectedSorted); // Проверка, что сортировка работает правильно

    // Тестирование турнирной сортировки
    std::vector<int> tournamentSorted = heap.tournamentSort(arr);
    assert(tournamentSorted[0] == 2); // Проверка, что минимальный элемент правильный в турнирной сортировке
}



/// <summary>
/// Шаблонный класс MaxHeap реализует максимальную кучу с использованием динамического массива.
/// </summary>
template <typename T>
class MaxHeap {
private:
    T* heap;          // Указатель на массив элементов
    size_t capacity;  // Вместимость массива
    size_t size;      // Текущий размер кучи

    /// <summary>
    /// Увеличивает вместимость массива в 2 раза, когда не хватает места.
    /// </summary>
    void resize() {
        capacity *= 2;                   // Увеличиваем вместимость
        T* newHeap = new T[capacity];    // Создаем новый массив с увеличенной вместимостью
        for (size_t i = 0; i < size; i++) {
            newHeap[i] = heap[i];        // Копируем элементы в новый массив
        }
        delete[] heap;                   // Освобождаем старый массив
        heap = newHeap;                  // Обновляем указатель на новый массив
    }

    /// <summary>
    /// heapifyUp поддерживает свойство максимальной кучи при добавлении элемента.
    /// </summary>
    /// <param name="index">Индекс элемента, который нужно переместить вверх.</param>
    void heapifyUp(size_t index) {
        while (index > 0) { // Пока индекс не корневой (индекс > 0)
            size_t parentIndex = (index - 1) / 2; // Найдем индекс родительского элемента
            if (heap[index] <= heap[parentIndex]) break; // Если элемент меньше или равен родителю, выходим
            std::swap(heap[index], heap[parentIndex]); // Меняем местами элемент и родителя
            index = parentIndex; // Поднимаемся к родителю
        }
    }

    /// <summary>
    /// heapifyDown поддерживает свойство максимальной кучи при удалении максимального элемента.
    /// </summary>
    /// <param name="index">Индекс элемента, который нужно переместить вниз.</param>
    void heapifyDown(size_t index) {
        size_t leftChild = 2 * index + 1; // Индекс левого потомка
        size_t rightChild = 2 * index + 2; // Индекс правого потомка
        size_t largest = index; // Предполагаем, что текущий элемент — наибольший

        if (leftChild < size && heap[leftChild] > heap[largest]) { // Проверяем левый потомок
            largest = leftChild; // Если он больше текущего, обновляем largest
        }

        if (rightChild < size && heap[rightChild] > heap[largest]) { // Проверяем правый потомок
            largest = rightChild; // Если он больше текущего, обновляем largest
        }

        if (largest != index) { // Если наибольший элемент не текущий
            std::swap(heap[index], heap[largest]); // Меняем их местами
            heapifyDown(largest); // Спускаем элемент дальше
        }
    }

public:
    /// <summary>
    /// Конструктор для инициализации максимальной кучи с заданной начальной вместимостью.
    /// </summary>
    /// <param name="initialCapacity">Начальная вместимость массива.</param>
    MaxHeap(size_t initialCapacity = 10) {
        capacity = initialCapacity;
        size = 0;
        heap = new T[capacity]; // Выделяем память для массива
    }

    /// <summary>
    /// Деструктор для освобождения выделенной памяти.
    /// </summary>
    ~MaxHeap() {
        delete[] heap; // Освобождаем память
    }

    // Возвращаем указатель на внутренний массив элементов кучи
    const T* getHeap() const {
        return heap;
    }

    // Проверка, пуста ли куча
    bool isEmpty() const {
        return size == 0;
    }

    // Получение размера кучи
    size_t getSize() const {
        return size;
    }

    /// <summary>
    /// insert добавляет новый элемент в кучу.
    /// </summary>
    /// <param name="value">Значение элемента, которое нужно добавить.</param>
    void insert(T value) {
        if (size == capacity) {
            resize(); // Если места нет, увеличиваем массив
        }
        heap[size] = value; // Добавляем элемент в конец массива
        heapifyUp(size);    // Поднимаем его до нужного места
        size++;             // Увеличиваем размер кучи
    }

    /// <summary>
    /// extractMax извлекает максимальный элемент из кучи.
    /// </summary>
    /// <returns>Возвращает максимальный элемент.</returns>
    /// <exception cref="std::out_of_range">Исключение выбрасывается, если куча пуста.</exception>
    T extractMax() {
        if (size == 0) { // Если куча пустая, выбрасываем исключение
            throw std::out_of_range("Heap is empty");
        }

        T maxVal = heap[0];  // Сохраняем максимальный элемент (корень кучи)
        heap[0] = heap[size - 1]; // Заменяем корень последним элементом
        size--;                 // Уменьшаем размер кучи
        heapifyDown(0);         // Опускаем новый корень до нужного места
        return maxVal;          // Возвращаем максимальный элемент
    }

    /// <summary>
    /// getMax возвращает максимальный элемент без его удаления.
    /// </summary>
    /// <returns>Возвращает максимальный элемент.</returns>
    /// <exception cref="std::out_of_range">Исключение выбрасывается, если куча пуста.</exception>
    T getMax() const {
        if (size == 0) { // Если куча пустая, выбрасываем исключение
            throw std::out_of_range("Heap is empty");
        }
        return heap[0]; // Возвращаем максимальный элемент (корень кучи)
    }

    /// <summary>
    /// getSorted возвращает массив всех элементов в отсортированном виде.
    /// </summary>
    /// <returns>Вектор отсортированных элементов.</returns>
    std::vector<T> getSorted() {
        std::vector<T> sortedHeap;
        while (!isEmpty()) {
            sortedHeap.push_back(extractMax()); // Извлекаем максимальный элемент и добавляем его в вектор
        }
        return sortedHeap;
    }

    /// <summary>
    /// printHeap выводит элементы кучи для отладки.
    /// </summary>
    void printHeap() const {
        for (size_t i = 0; i < size; i++) { // Проходим по всем элементам массива
            std::cout << heap[i] << " "; // Выводим каждый элемент
        }
        std::cout << std::endl; // Переход на новую строку после вывода всех элементов
    }

    /// <summary>
    /// Пирамидальная сортировка массива.
    /// </summary>
    std::vector<T> heapSort(const std::vector<T>& arr) {
        MaxHeap<T> heap(arr.size());

        // Заполнение кучи элементами
        for (const T& element : arr) {
            heap.insert(element);
        }

        std::vector<T> sorted;

        // Извлечение элементов из кучи для получения отсортированного массива
        while (!heap.isEmpty()) {
            sorted.push_back(heap.extractMax());
        }

        return sorted;
    }

    /// <summary>
    /// Турнирная сортировка массива.
    /// </summary>
    std::vector<T> tournamentSort(std::vector<T> arr) {
        while (arr.size() > 1) {
            std::vector<T> winners;

            // Проходим по массиву и сравниваем элементы парами
            for (size_t i = 0; i < arr.size(); i += 2) {
                if (i + 1 < arr.size()) {
                    // Побеждает больший из двух элементов
                    winners.push_back(std::max(arr[i], arr[i + 1]));
                }
                else {
                    // Если нечетное количество элементов, добавляем последний элемент в победители
                    winners.push_back(arr[i]);
                }
            }

            // Обновляем массив победителями текущего раунда
            arr = winners;
        }

        return arr;

    }

    // Итератор для обхода кучи
    class Iterator {
    private:
        size_t index; // Индекс текущего элемента в куче
        MaxHeap<T>* heap; // Указатель на кучу

    public:
        // Конструктор принимает указатель на кучу и инициализирует индекс
        Iterator(MaxHeap<T>* h, size_t idx) : heap(h), index(idx) {}

        // Оператор разыменования возвращает текущий элемент
        T& operator*() {
            return heap->heap[index];
        }

        // Префиксный оператор инкремента для перехода к следующему элементу
        Iterator& operator++() {
            index++; // Переходим к следующему элементу
            return *this; // Возвращаем итератор для цепочечного вызова
        }

        // Оператор != для сравнения итераторов
        bool operator!=(const Iterator& other) const {
            return index != other.index; // Возвращаем true, если индексы не равны
        }
    };

    // Функция, возвращающая итератор на начало кучи
    Iterator begin() {
        return Iterator(this, 0); // Начинаем с индекса 0
    }

    // Функция, возвращающая итератор на конец кучи
    Iterator end() {
        return Iterator(this, size); // Конец кучи — это индекс size
    }

};


/// <summary>
/// Функция для тестирования MaxHeap с помощью assert.
/// Включает тестирование вставки, извлечения максимальных элементов,
/// а также тестирование пирамидальной и турнирной сортировок,
/// проверку структуры MaxHeap с помощью std::is_heap и дополнительные операции с итератором.
/// </summary>
void testMaxHeap() {
    MaxHeap<int> heap;

    // Тестирование добавления элементов
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(20);

    // Вывод элементов для отладки
    heap.printHeap(); // Метод для вывода содержимого кучи

    // Ожидаемое значение после вставки элементов
    std::vector<int> expectedOrder = { 20, 15, 10, 5 }; // Порядок элементов зависит от реализации кучи
    size_t index = 0;

    // Тестирование итератора через цикл for
    for (auto it = heap.begin(); it != heap.end(); ++it) {
        std::cout << "Реальное: " << *it << ", Ожидалось: " << expectedOrder[index] << std::endl; // Отладочный вывод
        assert(*it == expectedOrder[index]); // Проверка, что элементы совпадают
        index++;
    }
    assert(index == expectedOrder.size()); // Проверка, что пройдено ожидаемое количество элементов

    // Вывод всех значений с увеличением на 5
    std::cout << "Значения в куче +5: ";
    for (auto it = heap.begin(); it != heap.end(); ++it) {
        std::cout << (*it + 5) << " "; // Вывод значения с добавлением 5
    }
    std::cout << std::endl;

    // Вывод только чётных чисел в куче
    std::cout << "Четные значения в куче: ";
    for (auto it = heap.begin(); it != heap.end(); ++it) {
        if (*it % 2 == 0) {
            std::cout << *it << " "; // Вывод только чётных значений
        }
    }
    std::cout << std::endl;

    // Проверка максимального элемента
    assert(heap.getMax() == 20); // Максимальный элемент должен быть 20

    // Тестирование извлечения максимального элемента
    assert(heap.extractMax() == 20); // Максимальный элемент должен быть 20
    assert(heap.getMax() == 15);     // После извлечения максимальный элемент должен быть 15

    // Тестирование дальнейшего извлечения
    assert(heap.extractMax() == 15);  // Максимальный элемент должен быть 15
    assert(heap.extractMax() == 10);  // Максимальный элемент должен быть 10
    assert(heap.extractMax() == 5);   // Максимальный элемент должен быть 5

    // Проверка, что куча пуста
    assert(heap.isEmpty()); // Куча должна быть пустой

    // Дополнительные тесты для сортировки
    std::vector<int> arr = { 10, 5, 20, 2, 8, 15 };

    // Тестирование пирамидальной сортировки
    std::vector<int> heapSorted = heap.heapSort(arr);
    std::vector<int> expectedSorted = { 20, 15, 10, 8, 5, 2 };
    assert(heapSorted == expectedSorted); // Проверка, что сортировка работает правильно

    // Тестирование турнирной сортировки
    std::vector<int> tournamentSorted = heap.tournamentSort(arr);
    assert(tournamentSorted[0] == 20); // Проверка, что максимальный элемент правильный в турнирной сортировке

    // Проверка структуры кучи через std::is_heap
    assert(std::is_heap(heap.getHeap(), heap.getHeap() + heap.getSize(), std::less<int>())); // Проверка на корректность максимальной кучи

    // Создание новой кучи с одним элементом
    MaxHeap<int> singleElementHeap;
    singleElementHeap.insert(20); // Добавляем элемент 20

    // Использование итератора для изменения элемента
    for (auto it = singleElementHeap.begin(); it != singleElementHeap.end(); ++it) {
        *it += 22; // Увеличиваем элемент на 22
    }

    // Проверка нового значения
    assert(singleElementHeap.getMax() == 42); // Теперь максимальное значение должно быть 42
    std::cout << "Частое число Ветрова Сергея Владимировича: " << singleElementHeap.getMax() << std::endl;
}
