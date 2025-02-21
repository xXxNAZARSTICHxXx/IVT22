///Стич Назар Иванович ИВТ-22
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <functional>
#include <cassert>
#include <stack>


template<typename T>
struct TreeNode {
    T n_data;              // Данные, хранящиеся в узле
    TreeNode<T>* n_left;   // Указатель на левое поддерево
    TreeNode<T>* n_right;  // Указатель на правое поддерево

    // Конструктор узла без параметров
    TreeNode() : n_data(T()), n_left(nullptr), n_right(nullptr) {
        // Инициализация по умолчанию: пустые указатели на поддеревья и значение по умолчанию для данных
    }

    // Конструктор с инициализацией данных
    TreeNode(const T& data) : n_data(data), n_left(nullptr), n_right(nullptr) {
        // Инициализирует узел с заданными данными и пустыми указателями на поддеревья
    }

    // Конструктор с указателями на левое и правое поддеревья
    TreeNode(const T& data, TreeNode<T>* left, TreeNode<T>* right)
        : n_data(data), n_left(left), n_right(right) {
        // Инициализация узла с данными и указателями на дочерние узлы
    }
    /*
    // Деструктор для очистки памяти
    ~TreeNode() {
        delete n_left;  // Удаляем левое поддерево
        delete n_right; // Удаляем правое поддерево
    }*/

    // Конструктор копирования
    TreeNode(const TreeNode& other)
        : n_data(other.n_data), n_left(nullptr), n_right(nullptr) {
        // Копирование данных и создание новых поддеревьев, если они есть
        if (other.n_left) n_left = new TreeNode(*other.n_left);   // Рекурсивное копирование левого поддерева
        if (other.n_right) n_right = new TreeNode(*other.n_right); // Рекурсивное копирование правого поддерева
    }

    // Оператор присваивания копированием
    TreeNode& operator=(const TreeNode& other) {
        if (this == &other) return *this; // Защита от самоприсваивания
        delete n_left;  // Удаление текущих поддеревьев
        delete n_right;
        n_data = other.n_data; // Копирование данных
        n_left = other.n_left ? new TreeNode(*other.n_left) : nullptr; // Копирование поддеревьев, если они существуют
        n_right = other.n_right ? new TreeNode(*other.n_right) : nullptr;

        return *this;
    }

    // Конструктор перемещения
    TreeNode(TreeNode&& other) noexcept
        : n_data(std::move(other.n_data)), n_left(other.n_left), n_right(other.n_right) {
        // Передаем данные и указатели на поддеревья из другого объекта, оставляя его пустым
        other.n_left = nullptr;
        other.n_right = nullptr;
    }

    // Оператор присваивания перемещением
    TreeNode& operator=(TreeNode&& other) noexcept {
        if (this == &other) return *this; // Защита от самоприсваивания
        delete n_left;  // Удаление текущих поддеревьев
        delete n_right;
        
        n_data = std::move(other.n_data); // Перемещение данных и указателей на поддеревья
        n_left = other.n_left;
        n_right = other.n_right;

        other.n_left = nullptr; // Очищаем перемещаемый объект
        other.n_right = nullptr;

        return *this;
    }
};


//Big(O)- По лучшему, среднему, худшему будет O(n)
/// <summary>
/// Обход дерева через стек (прямой порядок).
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в узлах дерева.</typeparam>
/// <param name="root">Указатель на корень дерева (узел).</param>
template<typename T>
void iterativePreOrderSTACK(TreeNode<T>* root) {
    if (!root) return;  // Если дерево пустое, выходим.

    std::stack<TreeNode<T>*> stack;  // Используем стек для хранения узлов.
    stack.push(root);  // Начинаем с корневого узла.

    while (!stack.empty()) {
        TreeNode<T>* current = stack.top();  // Берем верхний узел.
        stack.pop();  // Удаляем его из стека.

        //std::cout << current->n_data << " ";  // Обрабатываем текущий узел.

        // Сначала добавляем правого потомка, чтобы левый был обработан первым.
        if (current->n_right) stack.push(current->n_right);  // Здесь убираем .get()
        if (current->n_left) stack.push(current->n_left);    // Здесь убираем .get()
    }
}


/// <summary>
/// /// Шаблонная структура узла бинарного дерева с конструкторами из правила пяти
/// </summary>
template<typename T>
class BinTree {
public:
    T n_data;              // Данные, хранящиеся в узле
    BinTree<T>* n_left;   // Указатель на левое поддерево
    BinTree<T>* n_right;  // Указатель на правое поддерево

    /// Конструктор по умолчанию
    BinTree() : n_data(T()), n_left(nullptr), n_right(nullptr) {}

    /// Конструктор с параметром для инициализации узла
    BinTree(const T& data) : n_data(data), n_left(nullptr), n_right(nullptr) {}

    /// Конструктор с данными и указателями на левое и правое поддеревья
    BinTree(const T& data, BinTree<T>* left, BinTree<T>* right)
        : n_data(data), n_left(left), n_right(right) {}

    /// Деструктор
    ~BinTree() {
        delete n_left;
        delete n_right;
    }

    /// Конструктор копирования
    BinTree(const BinTree& other)
        : n_data(other.n_data), n_left(nullptr), n_right(nullptr) {
        if (other.n_left != nullptr) {
            n_left = new BinTree(*other.n_left);  // Глубокое копирование
        }
        if (other.n_right != nullptr) {
            n_right = new BinTree(*other.n_right);  // Глубокое копирование
        }
    }

    /// Оператор присваивания копированием
    BinTree& operator=(const BinTree& other) {
        if (this == &other) return *this;  // Проверка самоприсваивания

        // Удаляем текущее дерево
        delete n_left;
        delete n_right;

        n_data = other.n_data;
        n_left = other.n_left ? new BinTree(*other.n_left) : nullptr;
        n_right = other.n_right ? new BinTree(*other.n_right) : nullptr;

        return *this;
    }

    /// Конструктор перемещения
    BinTree(BinTree&& other) noexcept
        : n_data(std::move(other.n_data)), n_left(other.n_left), n_right(other.n_right) {
        other.n_left = nullptr;
        other.n_right = nullptr;
    }

    /// Оператор присваивания перемещением
    BinTree& operator=(BinTree&& other) noexcept {
        if (this == &other) return *this;  // Проверка самоприсваивания

        // Удаляем текущие ресурсы
        delete n_left;
        delete n_right;

        n_data = std::move(other.n_data);
        n_left = other.n_left;
        n_right = other.n_right;

        other.n_left = nullptr;
        other.n_right = nullptr;

        return *this;
    }
};

/// <summary>
/// Создание бинарного дерева
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"> Значение хранящееся в корне </param>
/// <returns></returns>
template<typename T>
TreeNode<T>* createTree(const std::vector<T>& data) {
    if (data.empty()) return nullptr; // Если входной вектор пуст, возвращаем nullptr (дерево не создаётся)

    TreeNode<T>* root = new TreeNode<T>(data[0]); // Создаём корневой узел дерева с первым элементом вектора
    for (size_t i = 1; i < data.size(); ++i) { // Перебираем оставшиеся элементы вектора начиная с индекса 1
        insertIntoTree(root, data[i]); // Вставляем каждый элемент в дерево
    }

    return root; // Возвращаем указатель на корень дерева
}

/// <summary>
/// Вставка узла в дерево
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> Узел дерева </param>
/// <param name="value"> Значение в дерево </param>
template<typename T>
void insertIntoTree(TreeNode<T>*& node, const T& value) {
    if (!node) { // Если текущий узел пустой, создаём новый узел
        node = new TreeNode<T>(value);
        return; // Прерываем дальнейшее выполнение после вставки
    }
    if (value < node->n_data) { // Если значение меньше текущего узла, переходим в левое поддерево
        insertIntoTree(node->n_left, value); // Рекурсивно вставляем в левое поддерево
    }
    else { // Иначе переходим в правое поддерево
        insertIntoTree(node->n_right, value); // Рекурсивно вставляем в правое поддерево
    }
}



/// /// Шаблонный класс для реализации бинарного дерева поиска
template<typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;  // Корень дерева

public:

    ///*****///

    // Итератор для симметричного (in-order) обхода дерева RNL
    class Iterator {
    private:
        std::stack<TreeNode<T>*> stack; // Стек для хранения узлов, которые нужно обойти
        TreeNode<T>* current; // Указатель на текущий узел (не обязательно для итератора)

        // Метод для обхода к самому левому узлу дерева
        void pushLeft(TreeNode<T>* node) {
            while (node) { // Пока есть узел
                stack.push(node); // Добавляем узел в стек
                node = node->n_left; // Переходим к левому потомку
            }
        }

    public:
        // Конструктор принимает корень дерева и инициализирует итератор
        Iterator(TreeNode<T>* root) : current(nullptr) {
            pushLeft(root); // Начинаем с корня и проходим к самому левому узлу
        }

        // Оператор разыменования возвращает данные текущего узла (узла на вершине стека)
        T& operator*() {
            return stack.top()->n_data; // Возвращаем данные узла, находящегося на вершине стека
        }

        // Префиксный оператор инкремента для перехода к следующему узлу в обходе
        Iterator& operator++() {
            TreeNode<T>* node = stack.top(); // Получаем узел с вершины стека
            stack.pop(); // Удаляем узел из стека (переходим к следующему узлу)
            if (node->n_right) { // Если у узла есть правый потомок
                pushLeft(node->n_right); // Переходим к самому левому узлу в правом поддереве
            }
            return *this; // Возвращаем итератор для возможности цепочечного вызова
        }

        // Оператор != для сравнения итераторов (проверка, не достигнут ли конец обхода)
        bool operator!=(const Iterator& other) const {
            return !stack.empty(); // Возвращает true, если стек не пуст (то есть, есть еще узлы для обхода)
        }
    };

    // Функция, возвращающая итератор на начало дерева
    Iterator begin() {
        return Iterator(root); // Возвращаем итератор, начинающий с корня дерева
    }

    // Функция, возвращающая итератор на конец дерева (пустой итератор)
    Iterator end() {
        return Iterator(nullptr); // Итератор на nullptr, сигнализирующий об окончании обхода
    }

    template<typename Iterator, typename Func>
    /// <summary>
    /// Применяет функцию ко всем элементам диапазона
    /// </summary>
    /// <param name="begin">Итератор на начало диапазона</param>
    /// <param name="end">Итератор на конец диапазона</param>
    /// <param name="func">Функция, применяемая к каждому элементу</param>
    void my_for_each(Iterator begin, Iterator end, Func func) {
        while (begin != end) {
            func(*begin); // Применяем функцию к текущему элементу
            ++begin; // Переходим к следующему элементу
        }
    }


    template<typename Iterator, typename Predicate>
    /// <summary>
    /// Проверяет, удовлетворяет ли хотя бы один элемент предикату
    /// </summary>
    /// <param name="begin">Итератор на начало диапазона</param>
    /// <param name="end">Итератор на конец диапазона</param>
    /// <param name="pred">Предикат, применяемый к элементам</param>
    /// <returns>Возвращает true, если хотя бы один элемент удовлетворяет предикату</returns>
    bool my_any_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // Если хотя бы один элемент удовлетворяет предикату
                return true; // Возвращаем true
            }
            ++begin; // Переходим к следующему элементу
        }
        return false; // Ни один элемент не удовлетворяет предикату
    }

    template<typename Iterator, typename Predicate>
    /// <summary>
    /// Проверяет, удовлетворяют ли все элементы предикату
    /// </summary>
    /// <param name="begin">Итератор на начало диапазона</param>
    /// <param name="end">Итератор на конец диапазона</param>
    /// <param name="pred">Предикат, применяемый к элементам</param>
    /// <returns>Возвращает true, если все элементы удовлетворяют предикату</returns>
    bool my_all_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (!pred(*begin)) { // Если хотя бы один элемент не удовлетворяет предикату
                return false; // Возвращаем false
            }
            ++begin; // Переходим к следующему элементу
        }
        return true; // Все элементы удовлетворяют предикату
    }


    template<typename Iterator, typename Predicate>
    /// <summary>
    /// Проверяет, что ни один элемент не удовлетворяет предикату
    /// </summary>
    /// <param name="begin">Итератор на начало диапазона</param>
    /// <param name="end">Итератор на конец диапазона</param>
    /// <param name="pred">Предикат, применяемый к элементам</param>
    /// <returns>Возвращает true, если ни один элемент не удовлетворяет предикату</returns>
    bool my_none_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // Если хотя бы один элемент удовлетворяет предикату
                return false; // Возвращаем false
            }
            ++begin; // Переходим к следующему элементу
        }
        return true; // Ни один элемент не удовлетворяет предикату
    }


    template<typename InputIterator, typename OutputIterator, typename Func>
    /// <summary>
    /// Преобразует элементы с помощью функции и записывает результат в другой диапазон
    /// </summary>
    /// <param name="begin">Итератор на начало исходного диапазона</param>
    /// <param name="end">Итератор на конец исходного диапазона</param>
    /// <param name="out">Итератор на начало целевого диапазона</param>
    /// <param name="func">Функция, применяемая к каждому элементу</param>
    void my_transform(InputIterator begin, InputIterator end, OutputIterator out, Func func) {
        while (begin != end) {
            *out = func(*begin); // Применяем функцию и записываем результат
            ++begin; // Переходим к следующему элементу исходного диапазона
            ++out; // Переходим к следующему элементу целевого диапазона
        }
    }


    template<typename InputIterator, typename OutputIterator, typename Predicate>
    /// <summary>
    /// Копирует элементы, удовлетворяющие предикату, в другой диапазон
    /// </summary>
    /// <param name="begin">Итератор на начало исходного диапазона</param>
    /// <param name="end">Итератор на конец исходного диапазона</param>
    /// <param name="out">Итератор на начало целевого диапазона</param>
    /// <param name="pred">Предикат, применяемый к элементам</param>
    void my_copy_if(InputIterator begin, InputIterator end, OutputIterator out, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // Если элемент удовлетворяет предикату
                *out = *begin; // Копируем его в целевой диапазон
                ++out; // Переходим к следующему элементу целевого диапазона
            }
            ++begin; // Переходим к следующему элементу исходного диапазона
        }
    }


    ///*****///

    // Метод для глубокого копирования дерева
    BinarySearchTree<T> copyTree() {
        BinarySearchTree<T> newTree;
        copyTreeRecursive(root.get(), newTree);
        return newTree;
    }

    //todo перегруженные операторы ВНЕ ДЕРЕВА

    /// <summary>
    /// Конструктор по умолчанию
    /// </summary>
    BinarySearchTree() : root(nullptr) {} // Конструктор инициализирует дерево с пустым корнем

    /// <summary>
    /// Деструктор
    /// </summary>
    ~BinarySearchTree() {
        delete root; // Деструктор удаляет корневой узел и все его поддеревья
    }

                    
                    
    //Big(O) - O(log n)
    /// <summary>
    /// Функция вставки нового узла в дерево
    /// </summary>
    /// <param name="value"> Значение в узле </param>
    void insert(const T& value) {
        root = insertRec(root, value); // Вставляем новый узел в дерево, начиная с корня
    }

    /// <summary>
    /// Метод для получения корня дерева
    /// </summary>
    TreeNode<T>* getRoot() const {
        return root; // Возвращает указатель на корень дерева
    }


        


    /// <summary>
    /// Рекурсивная функция вставки узла в бинарное дерево поиска (BST)
    /// </summary>
    /// <param name="node">Текущий узел дерева</param>
    /// <param name="value">Значение, которое нужно вставить</param>
    /// <returns>Указатель на текущий узел дерева (корень поддерева)</returns>
    TreeNode<T>* insertRec(TreeNode<T>* node, const T& value) {
        // Если текущий узел пустой, создаём новый узел с заданным значением
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }

        // Если значение меньше текущего узла, идем в левое поддерево
        if (value < node->n_data) {
            node->n_left = insertRec(node->n_left, value);
        }
        // Если значение больше текущего узла, идем в правое поддерево
        else if (value > node->n_data) {
            node->n_right = insertRec(node->n_right, value);
        }

        // Возвращаем текущий узел после вставки
        return node;
    }


    /// <summary>
    /// Поиск узла в дереве
    /// </summary>
    /// <param name="value"> Значение в узле</param>
    /// <returns></returns>
    bool search(const T& value) {
        return searchRec(root, value); // Ищем значение, начиная с корня
    }

    /// <summary>
    /// Рекурсивная функция поиска узла ///TODO Комментарии (возврат указателя на узел или nullptr)
    /// </summary>
    /// <param name="node">Текущий узел</param>
    /// <param name="value">Запрашиваемое значение</param>
    /// <returns>Возвращает узел или nullptr</returns>
    bool searchRec(TreeNode<T>* node, const T& value) {
        if (node == nullptr) return false;  // Узел не найден
        if (node->n_data == value) return true;  // Узел найден
        if (value < node->n_data) {
            return searchRec(node->n_left, value);  // Поиск в левом поддереве
        }
        return searchRec(node->n_right, value);  // Поиск в правом поддереве
    }

    /// <summary>
    /// Удаление всех узлов дерева 
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="node">Текущий узел</param>
    template<typename T>
    void deleteTree(TreeNode<T>* node) {
        if (node) {
            deleteTree(node->n_left); // Удаляем левое поддерево
            deleteTree(node->n_right); // Удаляем правое поддерево
            delete node; // Удаляем сам узел
        }
    }


    /// <summary>
    /// Удаление узла с заданным значением
    /// </summary>
    /// <param name="node">Текущий узел</param>
    /// <param name="value">Запрашиваемое значение</param>
    /// <returns>Возвращает предыдущий узел или nullptr</returns>
    TreeNode<T>* removeNode(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            return node; // Узел не найден
        }

        // Рекурсивный поиск узла для удаления
        if (value < node->n_data) {
            node->n_left = removeNode(node->n_left, value);
        }
        else if (value > node->n_data) {
            node->n_right = removeNode(node->n_right, value);
        }
        else {

            // Если это: Узел без детей
            if (node->n_left == nullptr && node->n_right == nullptr) {
                delete node; // Удаляем узел
                return nullptr; // Возвращаем nullptr, чтобы удалить узел из дерева
            }

            // Если это: Узел с одним ребенком
            if (node->n_left == nullptr) {
                TreeNode<T>* temp = node->n_right; // Сохраняем правое поддерево
                delete node; // Удаляем узел
                return temp; // Возвращаем правое поддерево
            }
            else if (node->n_right == nullptr) {
                TreeNode<T>* temp = node->n_left; // Сохраняем левое поддерево
                delete node; // Удаляем узел
                return temp; // Возвращаем левое поддерево
            }

            // Если это: Узел с двумя детьми
            // Находим минимальный узел в правом поддереве
            TreeNode<T>* minNode = findMin(node->n_right);
            node->n_data = minNode->n_data; // Копируем данные минимального узла
            node->n_right = removeRec(node->n_right, minNode->n_data); // Удаляем минимальный узел
        }
        return node;
    }





    /// Глубокое копирование дерева NLR (todo: сделать методом и функцией)
    template<typename T>
    void copyTreeRecursive(TreeNode<T>* node, BinarySearchTree<T>& tree) {
        if (node != nullptr) {
            tree.insert(node->n_data); // Вставляем данные узла в новое дерево
            copyTreeRecursive(node->n_left, tree); // Рекурсивно копируем левое поддерево
            copyTreeRecursive(node->n_right, tree); // Рекурсивно копируем правое поддерево
        }
    }

    /// <summary>
    /// Рекурсивный поиск узла
    /// </summary>
    /// <typeparam name="T">Тип данных в узле дерева</typeparam>
    /// <param name="node">Текущий узел для поиска</param>
    /// <param name="value">Значение для поиска</param>
    /// <returns>Указатель на найденный узел или nullptr, если узел не найден</returns>
    template<typename T>
    TreeNode<T>* searchRecursive(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            return nullptr; // Если узел не найден, возвращаем nullptr
        }

        if (node->n_data == value) {
            return node; // Если нашли узел, возвращаем указатель на него
        }
        else if (value < node->n_data) {
            return searchRecursive(node->n_left, value); // Ищем в левом поддереве
        }
        else {
            return searchRecursive(node->n_right, value); // Ищем в правом поддереве
        }
    }

    /// <summary>
    /// Вывод дерева (например, симметричным обходом LNR)
    /// </summary>
    void printTree() {
        std::vector<T> result;
        inorderTraversal(root, result); // Вызываем симметричный обход (LNR) для получения отсортированных данных
        for (const auto& val : result) {
            std::cout << val << " "; // Печатаем значение каждого узла
        }
        std::cout << std::endl; // Переход на новую строку
    }

    /// <summary>
    /// Симметричный (LNR) обход дерева
    /// </summary>
    /// <typeparam name="T">Тип данных в узле дерева</typeparam>
    /// <param name="node">Текущий узел</param>
    /// <param name="result">Контейнер для хранения значений узлов</param>
    void inorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        inorderTraversal(node->n_left, result);  // Левое поддерево
        result.push_back(node->n_data);          // Текущий узел
        inorderTraversal(node->n_right, result);  // Правое поддерево
    }

    /// <summary>
    /// Симметричный (RNL) обход дерева
    /// </summary>
    /// <typeparam name="T">Тип данных в узле дерева</typeparam>
    /// <param name="node">Текущий узел</param>
    /// <param name="result">Контейнер для хранения значений узлов</param>
    template<typename T>
    void reverseInorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        reverseInorderTraversal(node->n_right, result);  // Правое поддерево
        result.push_back(node->n_data);                  // Корень
        reverseInorderTraversal(node->n_left, result);   // Левое поддерево
    }

    /// <summary>
    /// Прямой (NLR) обход дерева
    /// </summary>
    /// <typeparam name="T">Тип данных в узле дерева</typeparam>
    /// <param name="node">Текущий узел</param>
    /// <param name="result">Контейнер для хранения значений узлов</param>
    template<typename T>
    void preorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        result.push_back(node->n_data);            // Корень
        preorderTraversal(node->n_left, result);   // Левое поддерево
        preorderTraversal(node->n_right, result);  // Правое поддерево
    }

    /// <summary>
    /// Прямой (NRL) обход дерева
    /// </summary>
    /// <typeparam name="T">Тип данных в узле дерева</typeparam>
    /// <param name="node">Текущий узел</param>
    /// <param name="result">Контейнер для хранения значений узлов</param>
    template<typename T>
    void reversePreorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        result.push_back(node->n_data);            // Корень
        reversePreorderTraversal(node->n_right, result);  // Правое поддерево
        reversePreorderTraversal(node->n_left, result);   // Левое поддерево
    }

    /// <summary>
    /// Обратный (LRN) обход дерева
    /// </summary>
    /// <typeparam name="T">Тип данных в узле дерева</typeparam>
    /// <param name="node">Текущий узел</param>
    /// <param name="result">Контейнер для хранения значений узлов</param>
    template<typename T>
    void postorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        postorderTraversal(node->n_left, result);   // Левое поддерево
        postorderTraversal(node->n_right, result);  // Правое поддерево
        result.push_back(node->n_data);             // Корень
    }

    /// <summary>
    /// Обратный (RLN) обход дерева
    /// </summary>
    /// <typeparam name="T">Тип данных в узле дерева</typeparam>
    /// <param name="node">Текущий узел</param>
    /// <param name="result">Контейнер для хранения значений узлов</param>
    template<typename T>
    void reversePostorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        reversePostorderTraversal(node->n_right, result);  // Правое поддерево
        reversePostorderTraversal(node->n_left, result);   // Левое поддерево
        result.push_back(node->n_data);                    // Корень
    }

    /// <summary>
/// Вставка 500 элементов в дерево, с корнем, равным центральному элементу
/// </summary>
    TreeNode<int>* create500ElementsTree() {
        BinarySearchTree<int> tree;  // Создаём экземпляр дерева

        // Выбираем центральное значение как корень
        int mid = 5000 / 2;
        tree.insert(mid);  // Вставляем центральный элемент как корень

        // Вставляем остальные элементы
        for (int i = 0; i < 5000; ++i) {
            if (i != mid) {
                tree.insert(i);  // Вставляем остальные элементы
            }
        }

        return tree.getRoot();  // Предполагается, что вы добавили метод getRoot() в класс BinarySearchTree
    }

    TreeNode<int>* create1000ElementsTree() {
        BinarySearchTree<int> tree;
        int mid = 1000 / 2;
        tree.insert(mid);  // Вставляем центральный элемент как корень

        for (int i = 0; i < 1000; ++i) {
            if (i != mid) {
                tree.insert(i);  // Вставляем остальные элементы
            }
        }

        return tree.getRoot();
    }

    TreeNode<int>* create5000ElementsTree() {
        BinarySearchTree<int> tree;
        int mid = 5000 / 2;
        tree.insert(mid);  // Вставляем центральный элемент как корень

        for (int i = 0; i < 5000; ++i) {
            if (i != mid) {
                tree.insert(i);  // Вставляем остальные элементы
            }
        }

        return tree.getRoot();
    }

    TreeNode<int>* create10000ElementsTree() {
        BinarySearchTree<int> tree;
        int mid = 10000 / 2;
        tree.insert(mid);  // Вставляем центральный элемент как корень

        for (int i = 0; i < 10000; ++i) {
            if (i != mid) {
                tree.insert(i);  // Вставляем остальные элементы
            }
        }

        return tree.getRoot();
    }

    TreeNode<int>* create25000ElementsTree() {
        BinarySearchTree<int> tree;
        int mid = 25000 / 2;
        tree.insert(mid);  // Вставляем центральный элемент как корень

        for (int i = 0; i < 25000; ++i) {
            if (i != mid) {
                tree.insert(i);  // Вставляем остальные элементы
            }
        }

        return tree.getRoot();
    }


    /// <summary>
    /// Создание большого бинарного дерева с предопределенными значениями
    /// </summary>
    /// <returns>Указатель на корень дерева</returns>
    TreeNode<int>* createBinBigTree() {
        insert(16); // Вставляем корневой узел со значением 16
        insert(8);  // Вставляем узел со значением 8 (левый ребенок от 16)
        insert(24); // Вставляем узел со значением 24 (правый ребенок от 16)
        insert(4);  // Вставляем узел со значением 4 (левый ребенок от 8)
        insert(12); // Вставляем узел со значением 12 (правый ребенок от 8)
        insert(20); // Вставляем узел со значением 20 (левый ребенок от 24)
        insert(28); // Вставляем узел со значением 28 (правый ребенок от 24)
        insert(2);  // Вставляем узел со значением 2 (левый ребенок от 4)
        insert(6);  // Вставляем узел со значением 6 (правый ребенок от 4)
        insert(10); // Вставляем узел со значением 10 (левый ребенок от 12)
        insert(14); // Вставляем узел со значением 14 (правый ребенок от 12)
        insert(18); // Вставляем узел со значением 18 (левый ребенок от 20)
        insert(22); // Вставляем узел со значением 22 (правый ребенок от 20)
        insert(26); // Вставляем узел со значением 26 (левый ребенок от 28)
        insert(30); // Вставляем узел со значением 30 (правый ребенок от 28)

        return root; // Возвращаем указатель на корень текущего дерева
    }

    

};



/// <summary>
/// Создание бинарного дерева
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns> Узел на дерево </returns>
template<typename T>
TreeNode<T>* createTree() {
    T value;
    std::cout << "Введите данные для корня: ";
    std::cin >> value;
    return new TreeNode<T>(value);
}

//Big(O) - O(n)
/// <summary>
/// Удаление бинарного дерева 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"></param>
template<typename T>
void deleteTree(TreeNode<T>* root) {
    if (root == nullptr) return;  // Если дерево пустое, ничего не делаем
    deleteTree(root->n_left); // Рекурсивно удаляем левое поддерево
    deleteTree(root->n_right); // Рекурсивно удаляем правое поддерево
    delete root; // Удаляем текущий узел (корень)
}





//Big(O)- По лучшему, среднему, худшему случаю будет O(n)
/// <summary>
/// Прямой обход (NLR)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Узел на корень дерева </param>
/// <param name="result"> Результирующий вектор </param>
template<typename T>
void preorder(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    result.push_back(root->n_data);
    preorder(root->n_left, result);
    preorder(root->n_right, result);
}

//Big(O)- По лучшему, среднему, худшему случаю будет O(n)
/// <summary>
/// Симметричный обход (LNR)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Узел на корень дерева </param>
/// <param name="result"> Результирующий вектор </param>
template<typename T>
void inorder(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    inorder(root->n_left, result);
    result.push_back(root->n_data);
    inorder(root->n_right, result);
}

//Big(O)- По лучшему, среднему, худшему случаю будет O(n), если дерево сбалансировано, то O(log n)
/// <summary>
/// Обратный обход (LRN)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Узел на корень дерева </param>
/// <param name="result"> Результирующий вектор </param>
template<typename T>
void postorder(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    postorder(root->n_left, result);
    postorder(root->n_right, result);
    result.push_back(root->n_data);
}

//Big(O)- По лучшему, среднему, худшему случаю будет O(n), если дерево сбалансировано, то O(log n)
/// <summary>
/// Обратный обход (RLN)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Узел на корень дерева </param>
/// <param name="result"> Результирующий вектор </param>
template<typename T>
void rln(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    rln(root->n_right, result);   // Правое поддерево
    rln(root->n_left, result);    // Левое поддерево
    result.push_back(root->n_data); // Текущий узел
}

//Big(O)- По лучшему, среднему, худшему случаю будет O(n), если дерево сбалансировано, то O(log n)
/// <summary>
/// Симметричный обход (RNL)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Узел на корень дерева </param>
/// <param name="result"> Результирующий вектор </param>
template<typename T>
void rnl(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    rnl(root->n_right, result);   // Правое поддерево
    result.push_back(root->n_data); // Текущий узел
    rnl(root->n_left, result);    // Левое поддерево
}

//Big(O)- По лучшему, среднему, худшему случаю будет O(n), если дерево сбалансировано, то O(log n)
/// <summary>
/// Обратный обход (NRL)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Узел на корень дерева </param>
/// <param name="result"> Результирующий вектор </param>
template<typename T>
void nrl(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    result.push_back(root->n_data); // Текущий узел
    nrl(root->n_right, result);   // Правое поддерево
    nrl(root->n_left, result);    // Левое поддерево
}



/// <summary>
/// Применение функции ко всем узлам NLR
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> Узел на корень дерева </param>
/// <param name="func"> Лямбда функция, которая принимает ссылку на шаблонное значение, которая ничего не возвращает</param>
template<typename T>
void applyFunction(TreeNode<T>* node, const std::function<void(T&)>& func) {
    if (node == nullptr) return;  // Если узел пустой (нет узла), возвращаемся из функции (базовый случай рекурсии)
    func(node->n_data); // Применяем переданную функцию func к данным текущего узла;
    applyFunction(node->n_left, func); // Рекурсивно вызываем функцию для левого поддерева (проход NLR — сначала обрабатываем левое поддерево)
    applyFunction(node->n_right, func); // Рекурсивно вызываем функцию для правого поддерева (после обработки левого поддерева обрабатываем правое)
}


/// <summary>
/// Прямое NRL применение функции
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> Узел на корень дерева </param>
/// <param name="func">  Любая функция  </param>
template<typename T>
void applyPreorder(TreeNode<T>* node, const std::function<void(T&)>& func) {
    if (node == nullptr) return;  // Если узел пустой, выходим из функции
    func(node->n_data);  // Применяем функцию к данным текущего узла
    applyPreorder(node->n_left, func);  // Рекурсивно применяем функцию к левому поддереву
    applyPreorder(node->n_right, func); // Рекурсивно применяем функцию к правому поддереву
}

/// <summary>
/// Симметричное NLR применение функции
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> Узел на корень дерева </param>
/// <param name="func">  Любая функция  </param>
template<typename T>
void applyInorder(TreeNode<T>* node, const std::function<void(T&)>& func) {
    if (node == nullptr) return;  // Если узел пустой, выходим из функции
    applyInorder(node->n_left, func);  // Рекурсивно применяем функцию к левому поддереву
    func(node->n_data);  // Применяем функцию к данным текущего узла
    applyInorder(node->n_right, func); // Рекурсивно применяем функцию к правому поддереву
}

/// <summary>
/// Обратное LRN применение функции
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> Узел на корень дерева </param>
/// <param name="func">  Любая функция  </param>
template<typename T>
void applyPostorder(TreeNode<T>* node, const std::function<void(T&)>& func) {
    if (node == nullptr) return;  // Если узел пустой, выходим из функции
    applyPostorder(node->n_left, func);  // Рекурсивно применяем функцию к левому поддереву
    applyPostorder(node->n_right, func); // Рекурсивно применяем функцию к правому поддереву
    func(node->n_data);  // Применяем функцию к данным текущего узла
}


//Big(O) - O(log n)
/// <summary>
/// Поиск следующего наибольшего элемента //todo расписать
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="current"> Узел на корень дерева </param>
/// <param name="value"> Запрашиваемое значение </param>
/// <returns>Возвращает найденный узел или nullptr</returns>
template<typename T>
TreeNode<T>* searchSucc(TreeNode<T>* current, const T& value) {
    TreeNode<T>* prev = nullptr; // prev будет хранить предыдущий узел (предшественник в процессе поиска)
    while (current != nullptr) { // Цикл продолжается, пока current не указывает на пустой узел
        if (current->n_data == value) { // Если текущий узел содержит запрашиваемое значение
            break;  // Мы нашли нужный элемент и можем прекратить поиск
        }
        else if (value < current->n_data) { // Если значение меньше, чем данные в текущем узле
            prev = current;         // Сохраняем текущий узел как предшественника
            current = current->n_left;  // Идем в левое поддерево (где значения меньше)
        }
        else { // Если значение больше, чем данные в текущем узле
            prev = current;         // Сохраняем текущий узел как предшественника
            current = current->n_right; // Идем в правое поддерево (где значения больше)
        }
    }
    if (current == nullptr) return nullptr; // Если мы дошли до конца дерева (значение не найдено), возвращаем nullptr
    if (current->n_right != nullptr) { // Если правое поддерево не пустое, то следующий наибольший элемент будет в правом поддереве
        current = current->n_right;  // Идем в правое поддерево
        while (current->n_left != nullptr) { // Находим самый левый узел в правом поддереве (самый маленький узел в правом поддереве)
            current = current->n_left;
        }
        return current;  // Возвращаем этот самый левый узел
    }  
    return prev ? prev : nullptr; // Если правого поддерева нет, то возвращаем предыдущий узел (предшественник)
}

//Big(O) - O(log n)
/// <summary>
/// Рекурсивный метод для поиска узла с заданным значением
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node">Хранимый узел</param>
/// <param name="value">Запрашиваемое значение</param>
/// <returns>Возвращает найденный узел или nullptr</returns>
template<typename T>
TreeNode<T>* findBST(std::shared_ptr<TreeNode<T>> node, const T& value) {
    // Базовый случай: узел пуст или найден элемент
    if (node == nullptr || node->data == value) {
        return node;
    }
    // Если искомое значение меньше данных текущего узла, идем влево
    if (value < node->data) {
        return search(node->left, value);
    }
    // Если искомое значение больше данных текущего узла, идем вправо
    return search(node->right, value);
}



/// <summary>
/// Функция для глубокого копирования бинарного дерева
/// </summary>
/// <typeparam name="T"> Тип данных, хранящихся в узлах дерева </typeparam>
/// <param name="node"> Указатель на узел (корень) исходного дерева </param>
/// <returns> Указатель на корень нового (скопированного) дерева </returns>
template<typename T>
TreeNode<T>* deepCopy(TreeNode<T>* node) {
    // Если текущий узел пустой (null), возвращаем nullptr
    // Это базовый случай рекурсии — когда дерево пустое или дошли до конца ветви
    if (node == nullptr) {
        return nullptr;
    }
    TreeNode<T>* newNode = new TreeNode<T>(node->n_data); // Создаем новый узел, копируя данные текущего узла (node->n_data)
    newNode->n_left = deepCopy(node->n_left); // Рекурсивно копируем левое поддерево текущего узла
    newNode->n_right = deepCopy(node->n_right); // Рекурсивно копируем правое поддерево текущего узла
    return newNode; // Возвращаем новый узел, который является корнем нового поддерева (или дерева)
}




/// <summary>
/// Поиск наименьшего элемента
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="current"> Узел дерева, с которого начинается поиск </param>
/// <returns> Возвращает узел с наименьшим значением </returns>
template<typename T>
TreeNode<T>* searchMin(TreeNode<T>* current) {
    if (current == nullptr) return nullptr;  // Если дерево пустое, возвращаем nullptr

    // Идем влево, пока есть элементы
    while (current->n_left != nullptr) {
        current = current->n_left; // Перемещаемся в левое поддерево
    }

    return current;  // Возвращаем узел с наименьшим значением
}

/// <summary>
/// Поиск наибольшего элемента
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="current"> Узел дерева, с которого начинается поиск </param>
/// <returns> Возвращает узел с наибольшим значением </returns>
template<typename T>
TreeNode<T>* searchMax(TreeNode<T>* current) {
    if (current == nullptr) return nullptr;  // Если дерево пустое, возвращаем nullptr

    // Идем вправо, пока есть элементы
    while (current->n_right != nullptr) {
        current = current->n_right; // Перемещаемся в правое поддерево
    }

    return current;  // Возвращаем узел с наибольшим значением
}

//Big(O) - O(n)
/// <summary>
/// Рекурсивное удаление узла
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> Узел дерева, с которого начинается удаление </param>
/// <param name="value"> Значение, которое нужно удалить </param>
template<typename T>
void deleteNodeRecursive(TreeNode<T>** node, const T& value) {
    if (*node == nullptr) return; // Если узел не найден, ничего не делаем

    if (value < (*node)->n_data) {  // Если значение меньше текущего узла
        deleteNodeRecursive(&(*node)->n_left, value);  // Идем в левое поддерево
    }
    else if (value > (*node)->n_data) {  // Если значение больше текущего узла
        deleteNodeRecursive(&(*node)->n_right, value);  // Идем в правое поддерево
    }
    else {  // Значение найдено, удаляем узел
        TreeNode<T>* nodeToDelete = *node;  // Сохраняем указатель на узел для удаления

        if ((*node)->n_left == nullptr && (*node)->n_right == nullptr) {  // Если у узла нет детей
            *node = nullptr;  // Устанавливаем узел как nullptr
            delete nodeToDelete;  // Удаляем узел
        }
        else if ((*node)->n_left != nullptr && (*node)->n_right == nullptr) {  // Если есть только левый ребенок
            *node = (*node)->n_left;  // Перемещаем указатель на левого ребенка
            delete nodeToDelete;  // Удаляем узел
        }
        else if ((*node)->n_left == nullptr && (*node)->n_right != nullptr) {  // Если есть только правый ребенок
            *node = (*node)->n_right;  // Перемещаем указатель на правого ребенка
            delete nodeToDelete;  // Удаляем узел
        }
        else {  // У узла есть оба ребенка
            TreeNode<T>* nextLargest = searchSucc(*node, (*node)->n_data);  // Находим преемника
            (*node)->n_data = nextLargest->n_data;  // Копируем данные преемника в текущий узел
            deleteNodeRecursive(&(*node)->n_right, nextLargest->n_data);  // Удаляем преемника из правого поддерева
        }
    }
}

/// <summary>
/// Вывод содержимого вектора
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="result"> Вектор значений, который нужно вывести </param>
template<typename T>
void printVector(const std::vector<T>& result) {
    for (const auto& val : result) {
        std::cout << val << " ";  // Печатаем каждое значение через пробел
    }
    std::cout << std::endl;  // Переход на новую строку
}

/// <summary>
/// Подсчет количества узлов в дереве
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Узел дерева, с которого начинается подсчет </param>
/// <returns> Количество узлов в дереве </returns>
template<typename T>
int countNodes(TreeNode<T>* root) {
    if (root == nullptr) return 0;  // Если узел пустой, возвращаем 0
    return 1 + countNodes(root->n_left) + countNodes(root->n_right);  // Подсчитываем узлы в левом и правом поддеревьях
}

/// <summary>
/// Определение глубины дерева
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Узел дерева, с которого начинается подсчет глубины </param>
/// <returns> Глубина дерева </returns>
template<typename T>
int treeDepth(TreeNode<T>* root) {
    if (root == nullptr) return 0;  // Если узел пустой, возвращаем 0
    return 1 + std::max(treeDepth(root->n_left), treeDepth(root->n_right));  // Возвращаем максимальную глубину среди поддеревьев
}

/// <summary>
/// Рекурсивная печать дерева в виде структуры
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Узел дерева, который нужно распечатать </param>
/// <param name="space"> Текущий уровень отступов для красивого вывода </param>
/// <param name="height"> Высота отступа между уровнями дерева </param>
template<typename T>
void printTree(TreeNode<T>* root, int space = 0, int height = 10) {
    if (root == nullptr) return;  // Если узел пустой, выходим
    space += height;  // Увеличиваем отступы для следующего уровня
    printTree(root->n_right, space);  // Печатаем правое поддерево
    std::cout << std::endl;
    for (int i = height; i < space; i++) std::cout << " ";  // Добавляем отступы
    std::cout << root->n_data << std::endl;  // Печатаем данные текущего узла
    printTree(root->n_left, space);  // Печатаем левое поддерево
}


/// <summary>
/// LNR вывод (симметричный обход)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Корневой узел дерева </param>
/// <param name="result"> Вектор для хранения результата обхода </param>
template<typename T>
void printInorder(TreeNode<T>* root, std::vector<T>& result) {
    inorderTraversal(root, result);  // Вызываем симметричный обход
    std::cout << "LNR вывод:" << std::endl;  // Сообщаем о типе обхода
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";  // Выводим каждый элемент вектора
    }
    std::cout << std::endl;  // Переход на новую строку
}

/// <summary>
/// LRN вывод (обратный симметричный обход)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Корневой узел дерева </param>
/// <param name="result"> Вектор для хранения результата обхода </param>
template<typename T>
void printPostorder(TreeNode<T>* root, std::vector<T>& result) {
    postorderTraversal(root, result);  // Вызываем обратный обход
    std::cout << "LRN вывод:" << std::endl;  // Сообщаем о типе обхода
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";  // Выводим каждый элемент вектора
    }
    std::cout << std::endl;  // Переход на новую строку
}

/// <summary>
/// NLR вывод (прямой обход)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Корневой узел дерева </param>
/// <param name="result"> Вектор для хранения результата обхода </param>
template<typename T>
void printPreorder(TreeNode<T>* root, std::vector<T>& result) {
    preorderTraversal(root, result);  // Вызываем прямой обход
    std::cout << "NLR вывод:" << std::endl;  // Сообщаем о типе обхода
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";  // Выводим каждый элемент вектора
    }
    std::cout << std::endl;  // Переход на новую строку
}

/// <summary>
/// Симметричный (LNR) обход дерева
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> Узел дерева </param>
/// <param name="result"> Вектор для хранения результата обхода </param>
template<typename T>
void inorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
    if (node == nullptr) return;  // Если узел пустой, выходим
    inorderTraversal(node->n_left, result);  // Рекурсивно обходим левое поддерево
    result.push_back(node->n_data);  // Добавляем данные текущего узла в результат
    inorderTraversal(node->n_right, result);  // Рекурсивно обходим правое поддерево
}

/// <summary>
/// Печать дерева в случайном порядке
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> Корневой узел дерева </param>
template<typename T>
void printRandomOrder(TreeNode<T>* root) {
    if (root == nullptr) return;  // Если дерево пустое, выходим
    std::vector<T> result;
    inorderTraversal(root, result);  // Получаем симметричный обход дерева
    std::random_shuffle(result.begin(), result.end());  // Перемешиваем элементы
    for (const auto& val : result) {
        std::cout << val << " ";  // Выводим случайно перемешанные элементы
    }
    std::cout << std::endl;  // Переход на новую строку
}


/// <summary>
/// Функция для создания бинарного дерева с данными от 1 до 31
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>Корневой узел дерева</returns>
template<typename T>
TreeNode<T>* createBigTree() {
    TreeNode<T>* root = new TreeNode<T>(1);  // Создаем корневой узел с данными 1
    root->n_left = new TreeNode<T>(2);       // Левый потомок с данными 2
    root->n_right = new TreeNode<T>(3);      // Правый потомок с данными 3

    root->n_left->n_left = new TreeNode<T>(4);   // Левый потомок 2
    root->n_left->n_right = new TreeNode<T>(5);  // Правый потомок 2
    root->n_right->n_left = new TreeNode<T>(6);  // Левый потомок 3
    root->n_right->n_right = new TreeNode<T>(7); // Правый потомок 3

    root->n_left->n_left->n_left = new TreeNode<T>(8);   // Левый потомок 4
    root->n_left->n_left->n_right = new TreeNode<T>(9);  // Правый потомок 4
    root->n_left->n_right->n_left = new TreeNode<T>(10); // Левый потомок 5
    root->n_left->n_right->n_right = new TreeNode<T>(11);// Правый потомок 5

    root->n_right->n_left->n_left = new TreeNode<T>(12);  // Левый потомок 6
    root->n_right->n_left->n_right = new TreeNode<T>(13); // Правый потомок 6
    root->n_right->n_right->n_left = new TreeNode<T>(14); // Левый потомок 7
    root->n_right->n_right->n_right = new TreeNode<T>(15);// Правый потомок 7

    root->n_left->n_left->n_left->n_left = new TreeNode<T>(16);  // Левый потомок 8
    root->n_left->n_left->n_left->n_right = new TreeNode<T>(17); // Правый потомок 8
    root->n_left->n_left->n_right->n_left = new TreeNode<T>(18); // Левый потомок 9
    root->n_left->n_left->n_right->n_right = new TreeNode<T>(19);// Правый потомок 9

    root->n_left->n_right->n_left->n_left = new TreeNode<T>(20);  // Левый потомок 10
    root->n_left->n_right->n_left->n_right = new TreeNode<T>(21); // Правый потомок 10
    root->n_left->n_right->n_right->n_left = new TreeNode<T>(22); // Левый потомок 11
    root->n_left->n_right->n_right->n_right = new TreeNode<T>(23);// Правый потомок 11

    root->n_right->n_left->n_left->n_left = new TreeNode<T>(24);  // Левый потомок 12
    root->n_right->n_left->n_left->n_right = new TreeNode<T>(25); // Правый потомок 12
    root->n_right->n_left->n_right->n_left = new TreeNode<T>(26); // Левый потомок 13
    root->n_right->n_left->n_right->n_right = new TreeNode<T>(27);// Правый потомок 13

    root->n_right->n_right->n_left->n_left = new TreeNode<T>(28);  // Левый потомок 14
    root->n_right->n_right->n_left->n_right = new TreeNode<T>(29); // Правый потомок 14
    root->n_right->n_right->n_right->n_left = new TreeNode<T>(30); // Левый потомок 15
    root->n_right->n_right->n_right->n_right = new TreeNode<T>(31);// Правый потомок 15

    return root;  // Возвращаем корневой узел дерева
}

/// <summary>
/// Функция для создания бинарного дерева с данными от 1 до 7 для тестов
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>Корневой узел дерева</returns>
template<typename T>
TreeNode<T>* createSampleTree() {
    TreeNode<T>* root = new TreeNode<T>(1);  // Создаем корневой узел с данными 1
    root->n_left = new TreeNode<T>(2);       // Левый потомок с данными 2
    root->n_right = new TreeNode<T>(3);      // Правый потомок с данными 3

    root->n_left->n_left = new TreeNode<T>(4);   // Левый потомок 2
    root->n_left->n_right = new TreeNode<T>(5);  // Правый потомок 2
    root->n_right->n_left = new TreeNode<T>(6);  // Левый потомок 3
    root->n_right->n_right = new TreeNode<T>(7); // Правый потомок 3

    return root;  // Возвращаем корневой узел дерева
}

/// <summary>
/// Функция для создания бинарного дерева с единственным узлом с данными 5 для тестов
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>Корневой узел дерева</returns>
template<typename T>
TreeNode<T>* createSampleTree2() {
    TreeNode<T>* root = new TreeNode<T>(5);  // Создаем корневой узел с данными 5
    return root;  // Возвращаем корневой узел дерева
}

/// <summary>
/// Функция для создания бинарного дерева с данными от 1 до 6 (вырожденное дерево)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>Корневой узел дерева</returns>
template<typename T>
TreeNode<T>* createSampleTree3() {
    TreeNode<T>* root = new TreeNode<T>(1);  // Создаем корневой узел с данными 1
    root->n_left = new TreeNode<T>(2);       // Левый потомок 1
    root->n_left->n_left = new TreeNode<T>(3);      // Левый потомок 2

    root->n_left->n_left->n_left = new TreeNode<T>(4);  // Левый потомок 3
    root->n_left->n_left->n_left->n_left = new TreeNode<T>(5); // Левый потомок 4
    root->n_left->n_left->n_left->n_left->n_left = new TreeNode<T>(6); // Левый потомок 5

    return root;  // Возвращаем корневой узел дерева
}

/// <summary>
/// Функция для создания бинарного дерева без данных
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>Указатель на пустое дерево</returns>
template<typename T>
TreeNode<T>* createSampleTree4() {
    return nullptr;  // Возвращаем указатель на пустое дерево
}

/// <summary>
/// Создание простого бинарного дерева поиска с данными от 1 до 7
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>Корневой узел дерева</returns>
template<typename T>
TreeNode<T>* createBST() {
    TreeNode<T>* root = new TreeNode<T>(4);  // Корневой узел с данными 4
    root->n_left = new TreeNode<T>(2);       // Левый потомок 4
    root->n_right = new TreeNode<T>(6);      // Правый потомок 4

    root->n_left->n_left = new TreeNode<T>(1);  // Левый потомок 2
    root->n_left->n_right = new TreeNode<T>(3); // Правый потомок 2
    root->n_right->n_left = new TreeNode<T>(5); // Левый потомок 6
    root->n_right->n_right = new TreeNode<T>(7);// Правый потомок 6

    return root;  // Возвращаем корневой узел дерева
}


/// <summary>
/// Удаление полного дерева (для бинарного дерева)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> Начало дерева, корень </param>
template<typename T>
void deleteAllTree(TreeNode<T>* node) {
    if (node == nullptr) return;  // Если узел пуст, ничего не делаем

    // Рекурсивно удаляем левое и правое поддеревья
    deleteAllTree(node->n_left);
    deleteAllTree(node->n_right);

    // Удаляем текущий узел
    delete node;
}

///*ASSERT ПРОВЕРКИ*///
///*ASSERT ПРОВЕРКИ*///
///*ASSERT ПРОВЕРКИ*///
///*ASSERT ПРОВЕРКИ*///
///*ASSERT ПРОВЕРКИ*///

/// <1.0.0>
/// Функция для тестирования работы дерева
//Todo -1 дерево 0 дерево
void testTreeFunctions() {
    TreeNode<int>* root = createSampleTree<int>();  // Создаем тестовое дерево
    assert(countNodes(root) == 7);  // Проверка на количество узлов
    assert(treeDepth(root) == 3);   // Проверка на глубину дерева

    std::vector<int> result;
    preorder(root, result);  // Прямой обход
    std::vector<int> expectedPreorder = { 1, 2, 4, 5, 3, 6, 7 };
    assert(result == expectedPreorder);

    result.clear();
    inorder(root, result);  // Симметричный обход
    std::vector<int> expectedInorder = { 4, 2, 5, 1, 6, 3, 7 };
    assert(result == expectedInorder);

    result.clear();
    postorder(root, result);  // Обратный обход
    std::vector<int> expectedPostorder = { 4, 5, 2, 6, 7, 3, 1 };
    assert(result == expectedPostorder);

    result.clear();
    printRandomOrder(root);  // Печатаем дерево в случайном порядке
}


/// <1.0.1>
/// Функция для тестирования работы дерева
void testTreeFunctions2() {
    TreeNode<int>* root = createSampleTree2<int>();
    assert(countNodes(root) == 1);  // Проверка на количество узлов
    assert(treeDepth(root) == 1);   // Проверка на глубину дерева

    std::vector<int> result;
    preorder(root, result);  // Прямой обход
    std::vector<int> expectedPreorder = { 5 };
    assert(result == expectedPreorder);

    result.clear();
    inorder(root, result);  // Симметричный обход
    std::vector<int> expectedInorder = { 5 };
    assert(result == expectedInorder);

    result.clear();
    postorder(root, result);  // Обратный обход
    std::vector<int> expectedPostorder = { 5 };
    assert(result == expectedPostorder);

    result.clear();
    printRandomOrder(root);
}
/// <1.0.1>
/// Функция для тестирования работы дерева
void testTreeFunctions3() {
    TreeNode<int>* root = createSampleTree3<int>();
    assert(countNodes(root) == 6);  // Проверка на количество узлов
    assert(treeDepth(root) == 6);   // Проверка на глубину дерева

    std::vector<int> result;
    preorder(root, result);  // Прямой обход
    std::vector<int> expectedPreorder = { 1, 2, 3, 4, 5, 6 };
    assert(result == expectedPreorder);

    result.clear();
    inorder(root, result);  // Симметричный обход
    std::vector<int> expectedInorder = { 6, 5, 4, 3, 2, 1 };
    assert(result == expectedInorder);

    result.clear();
    postorder(root, result);  // Обратный обход
    std::vector<int> expectedPostorder = { 6, 5, 4, 3, 2, 1 };
    assert(result == expectedPostorder);

    result.clear();
    printRandomOrder(root);
}

/// Функция для тестирования работы дерева
void testTreeFunctions4() {
    TreeNode<int>* root = createSampleTree4<int>();  // Пустое дерево

    assert(countNodes(root) == 0);  // Проверка на количество узлов
    assert(treeDepth(root) == 0);   // Проверка на глубину дерева

    std::vector<int> result;
    preorder(root, result);  // Прямой обход
    std::vector<int> expectedPreorder = {};
    assert(result == expectedPreorder);

    result.clear();
    inorder(root, result);  // Симметричный обход
    std::vector<int> expectedInorder = {};
    assert(result == expectedInorder);

    result.clear();
    postorder(root, result);  // Обратный обход
    std::vector<int> expectedPostorder = {};
    assert(result == expectedPostorder);

    result.clear();
    printRandomOrder(root);  // Печать дерева
}

/// Функция для тестирования работы с бинарным деревом поиска (BST)
void testBSTFunctions() {
    BinarySearchTree<int> bst;

    // Вставляем элементы в дерево с использованием публичного метода insert
    std::vector<int> values = { 4, 2, 6, 1, 3, 5, 7 };
    for (const int& val : values) {
        bst.insert(val);  // Вставляем элемент в дерево
    }

    // Проверка структуры дерева
    auto testBSTStructure = [&](TreeNode<int>* root) {
        // Проверка количества узлов
        assert(countNodes(root) == 7);

        // Проверка глубины дерева
        assert(treeDepth(root) == 3);

        // Проверка минимального элемента
        TreeNode<int>* minNode = searchMin(root);
        assert(minNode != nullptr && minNode->n_data == 1);

        // Проверка максимального элемента
        TreeNode<int>* maxNode = searchMax(root);
        assert(maxNode != nullptr && maxNode->n_data == 7);
        };

    // Тест обходов
    auto testBSTTraversals = [&](TreeNode<int>* root) {
        std::vector<int> result;

        // Симметричный (inorder) обход
        inorderTraversal(root, result);
        std::vector<int> expectedInorder = { 1, 2, 3, 4, 5, 6, 7 };
        assert(result == expectedInorder);

        result.clear();
        // Обратный симметричный (rnl) обход
        rnl(root, result);
        std::vector<int> expectedRNL = { 7, 6, 5, 4, 3, 2, 1 };
        assert(result == expectedRNL);
        };

    // Тест удаления узлов
    auto testBSTDeletion = [&](TreeNode<int>*& root) {
        // Удаление элемента 4 (корень)
        deleteNodeRecursive(&root, 4);
        std::vector<int> result;
        inorderTraversal(root, result);
        std::vector<int> expectedAfterDeletion = { 1, 2, 3, 5, 6, 7 };
        assert(result == expectedAfterDeletion);

        // Удаление всего дерева
        deleteAllTree(root);
        assert(root == nullptr);
        };

    // Тест применения функций к узлам дерева
    auto testApplyFunction = [&](TreeNode<int>* root) {
        std::vector<int> result;
        inorderTraversal(root, result);
        std::vector<int> expectedModified = { 2, 4, 6, 8, 10, 12, 14 };
        assert(result == expectedModified);
        };

    // Копирование дерева
    auto testTreeCopy = [&](TreeNode<int>* root) {
        BinarySearchTree<int> copiedTree;

        std::vector<int> resultOriginal;
        std::vector<int> resultCopy;
        inorderTraversal(root, resultOriginal);
        assert(resultOriginal == resultCopy);
        };

}


void runAllBinaryTreeTests() {
    // Создаем дерево с помощью insertIntoTree
    std::vector<int> data = { 4, 2, 6, 1, 3, 5, 7 };
    TreeNode<int>* root = nullptr;
    for (const int& val : data) {
        insertIntoTree(root, val);
    }

    // Проверка структуры дерева
    auto testTreeStructure = [&](TreeNode<int>* root) {
        // Проверка количества узлов
        assert(countNodes(root) == 7);

        // Проверка глубины дерева
        assert(treeDepth(root) == 3);

        // Проверка минимального и максимального элемента
        TreeNode<int>* minNode = searchMin(root);
        assert(minNode != nullptr && minNode->n_data == 1);

        TreeNode<int>* maxNode = searchMax(root);
        assert(maxNode != nullptr && maxNode->n_data == 7);
        };

    // Тест обходов
    auto testTraversals = [&](TreeNode<int>* root) {
        std::vector<int> result;

        // Симметричный обход
        inorder(root, result);
        std::vector<int> expectedInorder = { 1, 2, 3, 4, 5, 6, 7 };
        assert(result == expectedInorder);

        result.clear();
        // Прямой обход
        preorder(root, result);
        std::vector<int> expectedPreorder = { 4, 2, 1, 3, 6, 5, 7 };
        assert(result == expectedPreorder);

        result.clear();
        // Обратный обход
        postorder(root, result);
        std::vector<int> expectedPostorder = { 1, 3, 2, 5, 7, 6, 4 };
        assert(result == expectedPostorder);

        result.clear();
        // Прямой обход с использованием стека
        iterativePreOrderSTACK(root);
        preorder(root, result);
        assert(result == expectedPreorder);
        };

    // Тест удаления узла и дерева
    auto testNodeDeletion = [&](TreeNode<int>*& root) {
        // Удаление узла 4
        deleteNodeRecursive(&root, 4);
        std::vector<int> result;
        inorder(root, result);
        std::vector<int> expectedAfterDeletion = { 2, 3, 5, 6, 7 };
        assert(result == expectedAfterDeletion);

        // Удаление всего дерева
        deleteAllTree(root);
        assert(root == nullptr);
        };

}

void runSingleNodeTreeTest() {
    // Создаем дерево с одним узлом
    TreeNode<int>* root = new TreeNode<int>(5);  // Дерево-пень с единственным узлом

    // Проверка структуры дерева
    auto testTreeStructure = [&](TreeNode<int>* root) {
        // Проверка количества узлов
        assert(countNodes(root) == 1);

        // Проверка глубины дерева
        assert(treeDepth(root) == 1);

        // Проверка минимального и максимального элемента
        TreeNode<int>* minNode = searchMin(root);
        assert(minNode != nullptr && minNode->n_data == 5);

        TreeNode<int>* maxNode = searchMax(root);
        assert(maxNode != nullptr && maxNode->n_data == 5);
        };

    // Тест обходов
    auto testTraversals = [&](TreeNode<int>* root) {
        std::vector<int> result;

        // Симметричный обход
        inorder(root, result);
        std::vector<int> expectedInorder = { 5 };
        assert(result == expectedInorder);

        result.clear();
        // Прямой обход
        preorder(root, result);
        std::vector<int> expectedPreorder = { 5 };
        assert(result == expectedPreorder);

        result.clear();
        // Обратный обход
        postorder(root, result);
        std::vector<int> expectedPostorder = { 5 };
        assert(result == expectedPostorder);

        result.clear();
        // Прямой обход с использованием стека
        iterativePreOrderSTACK(root);
        preorder(root, result);
        assert(result == expectedPreorder);
        };

    // Тест удаления узла и дерева
    auto testNodeDeletion = [&](TreeNode<int>*& root) {
        // Удаление узла 5 (единственного узла)
        deleteNodeRecursive(&root, 5);
        std::vector<int> result;
        inorder(root, result);
        std::vector<int> expectedAfterDeletion = {};  // Дерево пустое после удаления
        assert(result == expectedAfterDeletion);

        // Удаление всего дерева (хотя дерево уже пусто)
        deleteAllTree(root);
        assert(root == nullptr);
        };
}

void runDegenerateTreeTest() {
    // Создаем вырожденное дерево с 6 узлами (линейное дерево)
    TreeNode<int>* root = nullptr;
    std::vector<int> data = { 1, 2, 3, 4, 5, 6 };
    
    for (const int& val : data) {
        insertIntoTree(root, val);
    }

    // Проверка структуры дерева
    auto testTreeStructure = [&](TreeNode<int>* root) {
        // Проверка количества узлов
        assert(countNodes(root) == 6);

        // Проверка глубины дерева (глубина равна количеству узлов в вырожденном дереве)
        assert(treeDepth(root) == 6);

        // Проверка минимального и максимального элемента
        TreeNode<int>* minNode = searchMin(root);
        assert(minNode != nullptr && minNode->n_data == 1);

        TreeNode<int>* maxNode = searchMax(root);
        assert(maxNode != nullptr && maxNode->n_data == 6);
    };

    // Тест обходов
    auto testTraversals = [&](TreeNode<int>* root) {
        std::vector<int> result;

        // Симметричный обход (inorder) для линейного дерева: [1, 2, 3, 4, 5, 6]
        inorder(root, result);
        std::vector<int> expectedInorder = { 1, 2, 3, 4, 5, 6 };
        assert(result == expectedInorder);

        result.clear();
        // Прямой обход (preorder): [1, 2, 3, 4, 5, 6] (порядок ввода)
        preorder(root, result);
        std::vector<int> expectedPreorder = { 1, 2, 3, 4, 5, 6 };
        assert(result == expectedPreorder);

        result.clear();
        // Обратный обход (postorder): [6, 5, 4, 3, 2, 1] (обратный порядок)
        postorder(root, result);
        std::vector<int> expectedPostorder = { 6, 5, 4, 3, 2, 1 };
        assert(result == expectedPostorder);

        result.clear();
        // Прямой обход с использованием стека
        iterativePreOrderSTACK(root);
        preorder(root, result);
        assert(result == expectedPreorder);
    };

    // Тест удаления узла и дерева
    auto testNodeDeletion = [&](TreeNode<int>*& root) {
        // Удаление узла 4
        deleteNodeRecursive(&root, 4);
        std::vector<int> result;
        inorder(root, result);
        std::vector<int> expectedAfterDeletion = { 1, 2, 3, 5, 6 };
        assert(result == expectedAfterDeletion);

        // Удаление всего дерева
        deleteAllTree(root);
        assert(root == nullptr);
    };
}

void runEmptyTreeTest() {
    // Создаем пустое дерево (root = nullptr)
    TreeNode<int>* root = nullptr;

    // Проверка структуры пустого дерева
    
        // Количество узлов должно быть 0
        assert(countNodes(root) == 0);

        // Глубина дерева должна быть 0
        assert(treeDepth(root) == 0);

        // Поиск минимального и максимального элемента должен вернуть nullptr
        TreeNode<int>* minNode = searchMin(root);
        assert(minNode == nullptr);

        TreeNode<int>* maxNode = searchMax(root);
        assert(maxNode == nullptr);
    

    // Тест обходов для пустого дерева
    auto testEmptyTreeTraversals = [&](TreeNode<int>* root) {
        std::vector<int> result;

        // Симметричный обход (должен вернуть пустой результат)
        inorder(root, result);
        std::vector<int> expectedInorder = {};
        assert(result == expectedInorder);

        result.clear();
        // Прямой обход (preorder)
        preorder(root, result);
        std::vector<int> expectedPreorder = {};
        assert(result == expectedPreorder);

        result.clear();
        // Обратный обход (postorder)
        postorder(root, result);
        std::vector<int> expectedPostorder = {};
        assert(result == expectedPostorder);
        };

    // Тест удаления узлов и дерева (на пустом дереве)
    auto testEmptyTreeDeletion = [&](TreeNode<int>*& root) {
        // Попытка удаления узла в пустом дереве
        deleteNodeRecursive(&root, 4);
        assert(root == nullptr);  // Дерево остается пустым

        // Удаление всего дерева (проверка на пустом дереве)
        deleteAllTree(root);
        assert(root == nullptr);
        };
    }

///*ASSERT ПРОВЕРКИ*///
///*ASSERT ПРОВЕРКИ*///
///*ASSERT ПРОВЕРКИ*///
///*ASSERT ПРОВЕРКИ*///
///*ASSERT ПРОВЕРКИ*///

/// <summary>
/// Перегруженный оператор <
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="lhs"> 1 операнд </param>
/// <param name="rhs"> 2 операнд </param>
/// <returns></returns>
template<typename T>
bool operator<(const TreeNode<T>& lhs, const TreeNode<T>& rhs) {
    return lhs.n_data < rhs.n_data;
}

/// <summary>
/// Перегруженный оператор >
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="lhs"> 1 операнд </param>
/// <param name="rhs"> 2 операнд </param>
/// <returns></returns>
template<typename T>
bool operator>(const TreeNode<T>& lhs, const TreeNode<T>& rhs) {
    return lhs.n_data > rhs.n_data;
}


#endif
