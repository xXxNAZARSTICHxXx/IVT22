#include <iostream> // Подключение стандартной библиотеки для ввода-вывода
#include <algorithm> // Подключение стандартной библиотеки алгоритмов (std::for_each, std::any_of, и т.д.)
#include <iterator> // Подключение стандартной библиотеки для работы с итераторами
#include <cassert> // Подключение стандартной библиотеки для проверок с помощью assert
#include "TREE_H.h" // Подключение заголовочного файла для работы с деревьями (например, для BinarySearchTree)

// DoubleList - класс двусвязного списка
template <typename T> // Шаблон класса для работы с различными типами данных
class DoubleList {
private:
    // Узел, представляющий элемент двусвязного списка
    struct Node {
        T data; // Данные узла (элемент списка)
        Node* prev; // Указатель на предыдущий узел
        Node* next; // Указатель на следующий узел

        // Конструктор узла с возможностью указания данных и соседних узлов
        Node(const T& newData, Node* newPrev = nullptr, Node* newNext = nullptr)
            : data(newData), prev(newPrev), next(newNext) {} // Инициализация узла
    };

    Node* head; // Указатель на первый элемент списка (голова)
    Node* tail; // Указатель на последний элемент списка (хвост)
    size_t size; // Размер списка (количество узлов)

public:
    using value_type = T;  // Определение типа value_type для поддержки стандартных алгоритмов

    /// <summary>
    /// Конструктор по умолчанию, инициализирующий пустой список
    /// </summary>
    DoubleList() : head(nullptr), tail(nullptr), size(0) {}

    /// <summary>
    /// Деструктор, вызывающий очистку списка
    /// </summary>
    ~DoubleList() { clear(); }

    /// <summary>
    /// Метод для добавления элемента в конец списка
    /// </summary>
    /// <param name="value">Элемент для добавления в конец списка</param>
    void push_back(const T& value) {
        if (!head) { // Если список пуст
            head = tail = new Node(value); // Создаем новый узел, который становится и головой, и хвостом
        }
        else { // Если список не пуст
            tail->next = new Node(value, tail); // Создаем новый узел и связываем его с предыдущим хвостом
            tail = tail->next; // Новый узел становится хвостом
        }
        size++; // Увеличиваем размер списка
    }

    /// <summary>
    /// Метод для очистки списка, удаляющий все узлы
    /// </summary>
    void clear() {
        Node* current = head; // Начинаем с головы списка
        while (current) { // Пока есть узлы
            Node* next = current->next; // Сохраняем указатель на следующий узел
            delete current; // Удаляем текущий узел
            current = next; // Переходим к следующему узлу
        }
        head = tail = nullptr; // После удаления всех узлов сбрасываем указатели
        size = 0; // Размер списка становится 0
    }

    /// <summary>
    /// Проверка, пуст ли список
    /// </summary>
    /// <returns>Возвращает true, если список пуст, иначе false</returns>
    bool empty() const { return size == 0; }

    /// <summary>
    /// Получение размера списка
    /// </summary>
    /// <returns>Возвращает количество элементов в списке</returns>
    size_t getSize() const { return size; }

    // Итераторы
    class Iterator { // Внутренний класс итератора для обхода списка
    private:
        Node* current; // Указатель на текущий узел

    public:
        /// <summary>
        /// Конструктор итератора, принимающий указатель на узел
        /// </summary>
        /// <param name="node">Указатель на узел списка</param>
        Iterator(Node* node) : current(node) {}

        /// <summary>
        /// Оператор разыменования, возвращающий данные текущего узла (не меняя поле класса)
        /// </summary>
        /// <returns>Возвращает ссылку на данные узла</returns>
        T& operator*() const { return current->data; }

        /// <summary>
        /// Оператор стрелки, возвращающий указатель на данные текущего узла (не меняя поле класса)
        /// </summary>
        /// <returns>Возвращает указатель на данные узла</returns>
        T* operator->() const { return &current->data; }

        /// <summary>
        /// Оператор префиксного инкремента, перемещающий итератор к следующему узлу
        /// </summary>
        /// <returns>Возвращает ссылку на текущий итератор</returns>
        Iterator& operator++() {
            current = current->next; // Переход к следующему узлу
            return *this; // Возвращаем текущий итератор
        }

        /// <summary>
        /// Оператор постфиксного инкремента, перемещающий итератор к следующему узлу
        /// </summary>
        /// <returns>Возвращает старое состояние итератора</returns>
        Iterator operator++(int) {
            Iterator temp = *this; // Сохраняем текущее состояние итератора
            ++(*this); // Переходим к следующему узлу
            return temp; // Возвращаем старое состояние итератора
        }

        /// <summary>
        /// Оператор сравнения на неравенство
        /// </summary>
        /// <param name="other">Другой итератор для сравнения</param>
        /// <returns>Возвращает true, если итераторы указывают на разные узлы</returns>
        bool operator!=(const Iterator& other) const { return current != other.current; }

        /// <summary>
        /// Оператор сравнения на равенство
        /// </summary>
        /// <param name="other">Другой итератор для сравнения</param>
        /// <returns>Возвращает true, если итераторы указывают на один и тот же узел</returns>
        bool operator==(const Iterator& other) const { return current == other.current; }
    };

    /// <summary>
    /// Метод для получения итератора на начало списка
    /// </summary>
    /// <returns>Возвращает итератор, указывающий на первый элемент списка</returns>
    Iterator begin() const { return Iterator(head); }

    /// <summary>
    /// Метод для получения итератора на конец списка (null-указатель)
    /// </summary>
    /// <returns>Возвращает итератор, указывающий на null (конец списка)</returns>
    Iterator end() const { return Iterator(nullptr); }

    // Методы для работы с алгоритмами

    /// <summary>
    /// Применение функции ко всем элементам диапазона итераторов
    /// </summary>
    /// <typeparam name="Iterator">Тип итератора</typeparam>
    /// <typeparam name="Func">Тип функции</typeparam>
    /// <param name="begin">Итератор на начало диапазона</param>
    /// <param name="end">Итератор на конец диапазона</param>
    /// <param name="func">Функция, применяемая к каждому элементу</param>
    template<typename Iterator, typename Func>
    void my_for_each(Iterator begin, Iterator end, Func func) {
        while (begin != end) { // Пока не достигнут конец
            func(*begin); // Применяем функцию к текущему элементу
            ++begin; // Переходим к следующему элементу
        }
    }

    /// <summary>
    /// Проверка, что хотя бы один элемент удовлетворяет предикату
    /// </summary>
    /// <typeparam name="Iterator">Тип итератора</typeparam>
    /// <typeparam name="Predicate">Тип предиката</typeparam>
    /// <param name="begin">Итератор на начало диапазона</param>
    /// <param name="end">Итератор на конец диапазона</param>
    /// <param name="pred">Предикат для проверки элементов</param>
    /// <returns>Возвращает true, если хотя бы один элемент удовлетворяет предикату</returns>
    template<typename Iterator, typename Predicate>
    bool my_any_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // Если элемент удовлетворяет предикату
                return true; // Возвращаем true
            }
            ++begin; // Переходим к следующему элементу
        }
        return false; // Если ни один элемент не удовлетворяет предикату
    }

    /// <summary>
    /// Проверка, что все элементы удовлетворяют предикату
    /// </summary>
    /// <typeparam name="Iterator">Тип итератора</typeparam>
    /// <typeparam name="Predicate">Тип предиката</typeparam>
    /// <param name="begin">Итератор на начало диапазона</param>
    /// <param name="end">Итератор на конец диапазона</param>
    /// <param name="pred">Предикат для проверки элементов</param>
    /// <returns>Возвращает true, если все элементы удовлетворяют предикату</returns>
    template<typename Iterator, typename Predicate>
    bool my_all_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (!pred(*begin)) { // Если элемент не удовлетворяет предикату
                return false; // Возвращаем false
            }
            ++begin; // Переходим к следующему элементу
        }
        return true; // Все элементы удовлетворяют предикату
    }

    template<typename Iterator, typename Predicate>
    /// <summary>
    /// Проверка, что ни один элемент не удовлетворяет предикату
    /// </summary>
    /// <param name="begin">Итератор на начало диапазона</param>
    /// <param name="end">Итератор на конец диапазона</param>
    /// <param name="pred">Предикат для проверки элементов</param>
    /// <returns>Возвращает true, если ни один элемент не удовлетворяет предикату</returns>
    bool my_none_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // Если хотя бы один элемент удовлетворяет предикату
                return false; // Немедленно возвращаем false
            }
            ++begin; // Переход к следующему элементу
        }
        return true; // Все элементы не удовлетворяют предикату, возвращаем true
    }

    template<typename InputIterator, typename OutputIterator, typename Func>
    /// <summary>
    /// Преобразование элементов диапазона с помощью функции и запись результата в другой диапазон
    /// </summary>
    /// <param name="begin">Итератор на начало диапазона</param>
    /// <param name="end">Итератор на конец диапазона</param>
    /// <param name="out">Итератор на начало целевого диапазона</param>
    /// <param name="func">Функция, применяемая к каждому элементу</param>
    void my_transform(InputIterator begin, InputIterator end, OutputIterator out, Func func) {
        while (begin != end) {
            *out = func(*begin); // Применяем функцию к элементу и записываем результат в целевой диапазон
            ++begin; // Переход к следующему элементу в исходном диапазоне
            ++out; // Переход к следующему элементу в целевом диапазоне
        }
    }

    template<typename InputIterator, typename OutputIterator, typename Predicate>
    /// <summary>
    /// Копирование элементов, удовлетворяющих предикату, в другой диапазон
    /// </summary>
    /// <param name="begin">Итератор на начало диапазона</param>
    /// <param name="end">Итератор на конец диапазона</param>
    /// <param name="out">Итератор на начало целевого диапазона</param>
    /// <param name="pred">Предикат для проверки элементов</param>
    void my_copy_if(InputIterator begin, InputIterator end, OutputIterator out, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // Если элемент удовлетворяет предикату
                *out = *begin; // Копируем его в целевой диапазон
                ++out; // Переходим к следующему элементу в целевом диапазоне
            }
            ++begin; // Переход к следующему элементу в исходном диапазоне
        }
    }


};

//TODO расписать КОММЕНТАРИИ - ДОЛБ**Б
// Функция для тестирования алгоритмов стандартной библиотеки
void runAlgorithms() {
    DoubleList<int> list;

    // Тестирование добавления элементов
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    assert(list.getSize() == 5); // Проверка размера списка
    assert(!list.empty()); // Проверка, что список не пустой

    /// <summary>
    /// Пример использования std::for_each для суммирования элементов списка
    /// </summary>
    /// <param name="list.begin()">Итератор на начало контейнера</param>
    /// <param name="list.end()">Итератор на конец контейнера</param>
    /// <param name="&sum">Переменная, которая захватывается по ссылке, для хранения суммы элементов</param>
    /// <param name="n">Текущий элемент списка, передаваемый в лямбду</param>
    int sum = 0;
    std::for_each(list.begin(), list.end(), [&sum](int n) { sum += n; });
    assert(sum == 15); // Проверка: сумма должна быть равна 15

    /// <summary>
    /// Пример использования std::any_of для проверки, есть ли элементы больше 3
    /// </summary>
    /// <param name="list.begin()">Итератор на начало контейнера</param>
    /// <param name="list.end()">Итератор на конец контейнера</param>
    /// <param name="n">Текущий элемент списка, передаваемый в лямбду</param>
    /// <returns>Возвращает true, если хотя бы один элемент больше 3</returns>
    bool anyGreaterThan3 = std::any_of(list.begin(), list.end(), [](int n) { return n > 3; });
    assert(anyGreaterThan3);

    /// <summary>
    /// Пример использования std::all_of для проверки, все ли элементы меньше 10
    /// </summary>
    /// <param name="list.begin()">Итератор на начало контейнера</param>
    /// <param name="list.end()">Итератор на конец контейнера</param>
    /// <param name="n">Текущий элемент списка, передаваемый в лямбду</param>
    /// <returns>Возвращает true, если все элементы меньше 10</returns>
    bool allLessThan10 = std::all_of(list.begin(), list.end(), [](int n) { return n < 10; });
    assert(allLessThan10);

    /// <summary>
    /// Пример использования std::none_of для проверки, что ни один элемент не равен 0
    /// </summary>
    /// <param name="list.begin()">Итератор на начало контейнера</param>
    /// <param name="list.end()">Итератор на конец контейнера</param>
    /// <param name="n">Текущий элемент списка, передаваемый в лямбду</param>
    /// <returns>Возвращает true, если ни один элемент не равен 0</returns>
    bool noneEqualTo0 = std::none_of(list.begin(), list.end(), [](int n) { return n == 0; });
    assert(noneEqualTo0);

    /// <summary>
    /// Пример использования std::copy_if для копирования чётных чисел в другой контейнер
    /// </summary>
    /// <param name="list.begin()">Итератор на начало контейнера</param>
    /// <param name="list.end()">Итератор на конец контейнера</param>
    /// <param name="evenNumbers">Контейнер для хранения чётных чисел</param>
    /// <param name="n">Текущий элемент списка, передаваемый в лямбду</param>
    /// <returns>Копирует элементы, если они чётные</returns>
    DoubleList<int> evenNumbers;
    std::copy_if(list.begin(), list.end(), std::back_inserter(evenNumbers), [](int n) { return n % 2 == 0; });
    assert(evenNumbers.getSize() == 2);  // Проверка: должно быть 2 чётных числа
    assert(*evenNumbers.begin() == 2);   // Проверка: первое чётное число 2
    assert(*(++evenNumbers.begin()) == 4); // Проверка: второе чётное число 4

    /// <summary>
    /// Пример использования std::for_each для вывода элементов списка на экран
    /// </summary>
    /// <param name="list.begin()">Итератор на начало контейнера</param>
    /// <param name="list.end()">Итератор на конец контейнера</param>
    /// <param name="element">Текущий элемент списка, передаваемый в лямбду</param>
    std::for_each(list.begin(), list.end(), [](int element) {
        std::cout << element << " ";  // Вывод элемента на экран
        });
    std::cout << std::endl;

    // Очистка списка
    list.clear();
    assert(list.empty()); // Проверка, что список пуст после очистки
}



// Функция для тестирования пользовательских алгоритмов //assert TODO
void runMyAlgorithms() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);

    // Использование пользовательского алгоритма для вывода всех элементов списка
    list.my_for_each(list.begin(), list.end(), [](int n) { std::cout << n << " "; });
    std::cout << std::endl;

    // Проверка пользовательского my_any_of
    bool anyGreaterThan5 = list.my_any_of(list.begin(), list.end(), [](int n) { return n > 5; });
    std::cout << "Элементы больше 5: " << anyGreaterThan5 << std::endl;

    // Проверка пользовательского my_all_of
    bool allLessThan10 = list.my_all_of(list.begin(), list.end(), [](int n) { return n < 10; });
    std::cout << "Все элементы меньше 10: " << allLessThan10 << std::endl;

    // Проверка пользовательского my_none_of
    bool noneEqualTo0 = list.my_none_of(list.begin(), list.end(), [](int n) { return n == 0; });
    std::cout << "Элементы не равные 0: " << noneEqualTo0 << std::endl;

    // Применение my_transform для удвоения значений всех элементов списка
    DoubleList<int> transformedList;
    list.my_transform(list.begin(), list.end(), std::back_inserter(transformedList), [](int n) { return n * 2; });
    list.my_for_each(transformedList.begin(), transformedList.end(), [](int n) { std::cout << n << " "; });
    std::cout << std::endl;

    // Применение my_copy_if для фильтрации четных чисел
    DoubleList<int> evenNumbers;
    list.my_copy_if(list.begin(), list.end(), std::back_inserter(evenNumbers), [](int n) { return n % 2 == 0; });
    list.my_for_each(evenNumbers.begin(), evenNumbers.end(), [](int n) { std::cout << n << " "; });
    std::cout << std::endl;
}

// Функция для тестирования алгоритмов с бинарным деревом поиска
void runBSTAlgorithms() {
    BinarySearchTree<int> bst; // Создание бинарного дерева поиска
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(17);

    // Проверка работы my_for_each для симметричного обхода дерева
    std::vector<int> inorderResult;
    bst.my_for_each(bst.begin(), bst.end(), [&inorderResult](int n) { inorderResult.push_back(n); });
    std::vector<int> expectedInorder = { 3, 5, 7, 10, 12, 15, 17 };
    assert(inorderResult == expectedInorder); // Проверка симметричного обхода

    // Проверка работы my_any_of
    bool anyGreaterThan10 = bst.my_any_of(bst.begin(), bst.end(), [](int n) { return n > 10; });
    assert(anyGreaterThan10 == true); // Есть элементы больше 10

    // Проверка работы my_all_of
    bool allLessThan20 = bst.my_all_of(bst.begin(), bst.end(), [](int n) { return n < 20; });
    assert(allLessThan20 == true); // Все элементы меньше 20

    // Проверка работы my_none_of
    bool noneEqualTo100 = bst.my_none_of(bst.begin(), bst.end(), [](int n) { return n == 100; });
    assert(noneEqualTo100 == true); // Нет элементов, равных 100

    // Проверка работы my_transform
    std::vector<int> transformedResult;
    bst.my_transform(bst.begin(), bst.end(), std::back_inserter(transformedResult), [](int n) { return n * 2; });
    std::vector<int> expectedTransformed = { 6, 10, 14, 20, 24, 30, 34 };
    assert(transformedResult == expectedTransformed); // Все элементы умножены на 2

    // Проверка работы my_copy_if
    std::vector<int> evenNumbers;
    bst.my_copy_if(bst.begin(), bst.end(), std::back_inserter(evenNumbers), [](int n) { return n % 2 == 0; });
    std::vector<int> expectedEvens = { 10, 12 };
    assert(evenNumbers == expectedEvens); // Проверяем только четные числа
}
