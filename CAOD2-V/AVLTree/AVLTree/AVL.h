#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include "TREE_H.h" // Предположим, что этот заголовок правильно определяет TreeNode

/// <summary>
/// Узел AVL-дерева
/// </summary>
template <typename T>
struct AVLTreeNode : public TreeNode<T> {
    signed char height; // Высота узла //TODO меньше памяти

    
    /// <summary>
    /// Конструктор по умолчанию
    /// </summary>
    AVLTreeNode() : TreeNode<T>(), height(1) {}

    /// <summary>
    /// Конструктор с данными
    /// </summary>
    /// <param name="data">Данные, которые будут храниться в узле</param>
    AVLTreeNode(const T& data) : TreeNode<T>(data), height(1) {}

    /// <summary>
    /// Конструктор с данными и дочерними узлами
    /// </summary>
    /// <param name="data">Данные, которые будут храниться в узле</param>
    /// <param name="left">Указатель на левый дочерний узел</param>
    /// <param name="right">Указатель на правый дочерний узел</param>
    AVLTreeNode(const T& data, AVLTreeNode<T>* left, AVLTreeNode<T>* right)
        : TreeNode<T>(data, left, right), height(1) {}




    T data; // это может быть тип данных, хранящихся в узле
    AVLTreeNode<T>* left;
    AVLTreeNode<T>* right;
};

/// <summary>
/// Класс AVL-дерева
/// </summary>
template <typename T>
class AVLTree {

private:
    AVLTreeNode<T>* root; // Корень дерева


    /// <summary>
    /// Обновление высоты узла
    /// </summary>
    /// <param name="node">Указатель на узел</param>
    void updateHeight(AVLTreeNode<T>* node) {
        if (node) {
            // Высота узла равна максимальной высоте его дочерних узлов + 1
            node->height = std::max(getHeight(static_cast<AVLTreeNode<T>*>(node->n_left)),
                getHeight(static_cast<AVLTreeNode<T>*>(node->n_right))) + 1;
        }
    }


    /// <summary>
    /// Левый-правый поворот
    /// </summary>
    /// <param name="node">Указатель на узел, для которого выполняется поворот</param>
    /// <returns>Новый корень поддерева после поворота</returns>
    AVLTreeNode<T>* leftRightRotate(AVLTreeNode<T>* node) {
        node->n_left = leftRotate(static_cast<AVLTreeNode<T>*>(node->n_left)); // Сначала левый поворот
        return rightRotate(node); // Затем правый поворот
    }

    /// <summary>
    /// Получение высоты узла
    /// </summary>
    int getHeight(AVLTreeNode<T>* node) const {
        return node ? node->height : 0;
    }

    /// <summary>
    /// Правый-левый поворот
    /// </summary>
    /// <param name="node">Указатель на узел, для которого выполняется поворот</param>
    /// <returns>Новый корень поддерева после поворота</returns>
    AVLTreeNode<T>* rightLeftRotate(AVLTreeNode<T>* node) {
        node->n_right = rightRotate(static_cast<AVLTreeNode<T>*>(node->n_right)); // Сначала правый поворот
        return leftRotate(node); // Затем левый поворот
    }

    /// <summary>
    /// Прямой обход дерева
    /// </summary>
    /// <param name="node">Указатель на узел, с которого начинается обход</param>
    void preOrderTraversal(AVLTreeNode<T>* node) {
        if (node) {
            std::cout << node->n_data << " "; // Выводим данные узла
            preOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_left)); // Рекурсивно обходим левое поддерево
            preOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_right)); // Рекурсивно обходим правое поддерево
        }
    }

    /// <summary>
    /// Симметричный обход дерева
    /// </summary>
    /// <param name="node">Указатель на узел, с которого начинается обход</param>
    void inOrderTraversal(AVLTreeNode<T>* node) {
        if (node) {
            inOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_left)); // Рекурсивно обходим левое поддерево
            std::cout << node->n_data << " "; // Выводим данные узла
            inOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_right)); // Рекурсивно обходим правое поддерево
        }
    }

    /// <summary>
    /// Обратный обход дерева
    /// </summary>
    /// <param name="node">Указатель на узел, с которого начинается обход</param>
    void postOrderTraversal(AVLTreeNode<T>* node) {
        if (node) {
            postOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_left)); // Рекурсивно обходим левое поддерево
            postOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_right)); // Рекурсивно обходим правое поддерево
            std::cout << node->n_data << " "; // Выводим данные узла
        }
    }

//TODO SOLID принцип подстановки

    /// <summary>
    /// Широкий обход дерева (по уровням)
    /// </summary>
    /// <param name="root">Указатель на корень дерева</param>
    void breadthFirstTraversal(AVLTreeNode<T>* root) {
        if (!root) return; // Если корень пустой, выходим

        std::queue<AVLTreeNode<T>*> queue; // Создаем очередь для обхода по уровням
        queue.push(root); // Добавляем корень в очередь

        while (!queue.empty()) {
            AVLTreeNode<T>* current = queue.front(); // Получаем текущий узел
            queue.pop(); // Удаляем его из очереди
            std::cout << current->n_data << " "; // Выводим данные текущего узла

            // Добавляем левого дочернего узла в очередь
            if (current->n_left) {
                queue.push(static_cast<AVLTreeNode<T>*>(current->n_left));
            }
            // Добавляем правого дочернего узла в очередь
            if (current->n_right) {
                queue.push(static_cast<AVLTreeNode<T>*>(current->n_right));
            }
        }
    }

    /// <summary>
    /// Получение максимальной глубины поддерева
    /// </summary>
    /// <param name="node">Указатель на узел, с которого начинается вычисление глубины</param>
    /// <returns>Максимальная глубина поддерева</returns>
    int maxDepth(AVLTreeNode<T>* node) {
        if (!node) {
            return 0; // Если узел пустой, глубина 0
        }

        // Рекурсивно получаем глубину левого и правого поддеревьев
        int leftDepth = maxDepth(static_cast<AVLTreeNode<T>*>(node->n_left));
        int rightDepth = maxDepth(static_cast<AVLTreeNode<T>*>(node->n_right));

        // Возвращаем максимальную глубину + 1 для текущего узла
        return std::max(leftDepth, rightDepth) + 1;
    }

    /// <summary>
    /// Вставка элемента в AVL-дерево
    /// </summary>
    /// <param name="node">Указатель на узел, с которого начинается вставка</param>
    /// <param name="data">Данные, которые нужно вставить</param>
    /// <returns>Указатель на новый корень поддерева</returns>
    AVLTreeNode<T>* insert(AVLTreeNode<T>* node, const T& data) {
        if (!node) return new AVLTreeNode<T>(data); // Если узел пустой, создаем новый

        // Вставляем данные в левое или правое поддерево
        if (data < node->n_data) {
            node->n_left = insert(static_cast<AVLTreeNode<T>*>(node->n_left), data);
        }
        else if (data > node->n_data) {
            node->n_right = insert(static_cast<AVLTreeNode<T>*>(node->n_right), data);
        }
        else {
            return node; // Дубликаты не допускаются
        }

        updateHeight(node); // Обновляем высоту узла
        int balance = getBalance(node); // Получаем коэффициент баланса

        // Проверяем, нужно ли выполнять поворот
        if (balance > 1 && data < static_cast<AVLTreeNode<T>*>(node->n_left)->n_data)
            return rightRotate(node); // Правый поворот

        if (balance < -1 && data > static_cast<AVLTreeNode<T>*>(node->n_right)->n_data)
            return leftRotate(node); // Левый поворот

        if (balance > 1 && data > static_cast<AVLTreeNode<T>*>(node->n_left)->n_data) {
            node->n_left = leftRotate(static_cast<AVLTreeNode<T>*>(node->n_left)); // Левый поворот на левом дочернем узле
            return rightRotate(node); // Правый поворот
        }

        if (balance < -1 && data < static_cast<AVLTreeNode<T>*>(node->n_right)->n_data) {
            node->n_right = rightRotate(static_cast<AVLTreeNode<T>*>(node->n_right)); // Правый поворот на правом дочернем узле
            return leftRotate(node); // Левый поворот
        }

        return node; // Возвращаем (возможно) изменённый узел
    }


    /// <summary>
    /// Поиск элемента в AVL-дереве
    /// </summary>
    /// <param name="node">Указатель на узел, с которого начинается поиск</param>
    /// <param name="data">Данные, которые нужно найти</param>
    /// <returns>True, если элемент найден, иначе False</returns>
    bool search(AVLTreeNode<T>* node, const T& data) {
        if (!node) return false; // Если узел пустой, элемент не найден
        if (data == node->n_data) return true; // Если данные совпадают, элемент найден
        if (data < node->n_data) return search(static_cast<AVLTreeNode<T>*>(node->n_left), data); // Ищем в левом поддереве
        return search(static_cast<AVLTreeNode<T>*>(node->n_right), data); // Ищем в правом поддереве
    }

    /// <summary>
    /// Получение узла с минимальным значением в поддереве
    /// </summary>
    /// <param name="node">Указатель на узел, с которого начинается поиск</param>
    /// <returns>Указатель на узел с минимальным значением</returns>
    AVLTreeNode<T>* getMinNode(AVLTreeNode<T>* node) {
        while (node && node->n_left) {
            node = static_cast<AVLTreeNode<T>*>(node->n_left); // Ищем самый левый узел
        }
        return node; // Возвращаем узел с минимальным значением
    }

    /// <summary>
    /// Удаление элемента из AVL-дерева
    /// </summary>
    /// <param name="node">Указатель на узел, с которого начинается удаление</param>
    /// <param name="data">Данные, которые нужно удалить</param>
    /// <returns>Указатель на новый корень поддерева</returns>
    AVLTreeNode<T>* remove(AVLTreeNode<T>* node, const T& data) {
        if (!node) return node; // Если узел пустой, выходим

        // Удаляем элемент из левого или правого поддерева
        if (data < node->n_data) {
            node->n_left = remove(static_cast<AVLTreeNode<T>*>(node->n_left), data);
        }
        else if (data > node->n_data) {
            node->n_right = remove(static_cast<AVLTreeNode<T>*>(node->n_right), data);
        }
        else {
            // Узел с одним или нулевым дочерним узлом
            if (!node->n_left || !node->n_right) {
                AVLTreeNode<T>* temp = node->n_left ? static_cast<AVLTreeNode<T>*>(node->n_left) : static_cast<AVLTreeNode<T>*>(node->n_right);
                if (!temp) {
                    delete node; // Если узел - лист, освобождаем память
                    return nullptr; // Возвращаем nullptr
                }
                else {
                    *node = *temp; // Копируем данные из дочернего узла
                    delete temp; // Освобождаем память
                }
            }
            else {
                // Узел с двумя дочерними узлами
                AVLTreeNode<T>* temp = getMinNode(static_cast<AVLTreeNode<T>*>(node->n_right)); // Находим минимальный узел в правом поддереве
                node->n_data = temp->n_data; // Копируем данные
                node->n_right = remove(static_cast<AVLTreeNode<T>*>(node->n_right), temp->n_data); // Удаляем минимальный узел
            }
        }

        updateHeight(node); // Обновляем высоту узла
        int balance = getBalance(node); // Получаем коэффициент баланса

        // Проверяем, нужно ли выполнять поворот
        if (balance > 1 && getBalance(static_cast<AVLTreeNode<T>*>(node->n_left)) >= 0)
            return rightRotate(node); // Правый поворот

        if (balance > 1 && getBalance(static_cast<AVLTreeNode<T>*>(node->n_left)) < 0) {
            node->n_left = leftRotate(static_cast<AVLTreeNode<T>*>(node->n_left)); // Левый поворот на левом дочернем узле
            return rightRotate(node); // Правый поворот
        }

        if (balance < -1 && getBalance(static_cast<AVLTreeNode<T>*>(node->n_right)) <= 0)
            return leftRotate(node); // Левый поворот

        if (balance < -1 && getBalance(static_cast<AVLTreeNode<T>*>(node->n_right)) > 0) {
            node->n_right = rightRotate(static_cast<AVLTreeNode<T>*>(node->n_right)); // Правый поворот на правом дочернем узле
            return leftRotate(node); // Левый поворот
        }

        return node; // Возвращаем изменённый узел
    }



    /// <summary>
    /// Итератор для AVL-дерева
    /// </summary>
    class AVLTreeIterator {
    private:
        std::stack<AVLTreeNode<T>*> nodeStack; // Стек для хранения узлов

        /// <summary>
        /// Добавляет все левые узлы в стек
        /// </summary>
        /// <param name="node">Указатель на узел, с которого начинается добавление</param>
        void pushLeft(AVLTreeNode<T>* node) {
            while (node) {
                nodeStack.push(node); // Добавляем узел в стек
                node = static_cast<AVLTreeNode<T>*>(node->n_left); // Переходим к левому дочернему узлу
            }
        }

    public:
        /// <summary>
        /// Конструктор итератора
        /// </summary>
        /// <param name="root">Указатель на корень дерева</param>
        AVLTreeIterator(AVLTreeNode<T>* root) {
            pushLeft(root); // Заполняем стек
        }

        /// <summary>
        /// Оператор инкремента
        /// </summary>
        void operator++() {
            if (nodeStack.empty()) return; // Если стек пустой, выходим

            AVLTreeNode<T>* node = nodeStack.top(); // Получаем верхний узел стека
            nodeStack.pop(); // Удаляем его из стека
            pushLeft(static_cast<AVLTreeNode<T>*>(node->n_right)); // Добавляем левые узлы правого поддерева
        }

        /// <summary>
        /// Проверка неравенства итераторов
        /// </summary>
        /// <param name="other">Другой итератор</param>
        /// <returns>True, если итераторы не равны</returns>
        bool operator!=(const AVLTreeIterator& other) const {
            return !nodeStack.empty() || !other.nodeStack.empty(); // Сравниваем состояние стеков
        }

        /// <summary>
        /// Оператор разыменования
        /// </summary>
        /// <returns>Данные текущего узла</returns>
        T operator*() const {
            return nodeStack.top()->n_data; // Возвращаем данные верхнего узла стека
        }

    };


public:
    // Конструктор для инициализации пустого дерева
    AVLTree() : root(nullptr) {};
    
    // Метод для получения корня дерева, доступный извне
    AVLTreeNode<T>* getRoot() const {
        return root;
    }

    /// <summary>
    /// Устанавливает новый корень дерева
    /// </summary>
    /// <param name="newRoot">Указатель на новый корень</param>
    void setRoot(AVLTreeNode<T>* newRoot) {
        root = newRoot;  // Обновляем корень дерева
    }

    /// <summary>
    /// Правый поворот вокруг узла y
    /// </summary>
    /// <param name="y">Указатель на узел, вокруг которого выполняется поворот</param>
    /// <returns>Новый корень поддерева после поворота</returns>
    AVLTreeNode<T>* rightRotate(AVLTreeNode<T>* y) {
        AVLTreeNode<T>* x = static_cast<AVLTreeNode<T>*>(y->n_left); // Сохраняем левый дочерний узел
        AVLTreeNode<T>* T2 = static_cast<AVLTreeNode<T>*>(x->n_right); // Сохраняем правый дочерний узел x
        x->n_right = y; // Поворачиваем y вправо
        y->n_left = T2; // Присоединяем правого дочернего узла x к y
        updateHeight(y); // Обновляем высоту y
        updateHeight(x); // Обновляем высоту x
        return x; // Возвращаем новый корень
    }



    /// <summary>
    /// Левый поворот вокруг узла x
    /// </summary>
    /// <param name="x">Указатель на узел, вокруг которого выполняется поворот</param>
    /// <returns>Новый корень поддерева после поворота</returns>
    AVLTreeNode<T>* leftRotate(AVLTreeNode<T>* x) {
        AVLTreeNode<T>* y = static_cast<AVLTreeNode<T>*>(x->n_right); // Сохраняем правый дочерний узел
        AVLTreeNode<T>* T2 = static_cast<AVLTreeNode<T>*>(y->n_left); // Сохраняем левый дочерний узел y
        y->n_left = x; // Поворачиваем x влево
        x->n_right = T2; // Присоединяем левого дочернего узла y к x
        updateHeight(x); // Обновляем высоту x
        updateHeight(y); // Обновляем высоту y
        return y; // Возвращаем новый корень
    }


    // Метод для получения значения корня дерева
    T getRootValue() const {
        if (root != nullptr) {
            return root->n_data; // Возвращаем значение корневого узла
        }
        throw std::runtime_error("Дерево пустое"); // Исключение, если дерево пустое
    }

    int getHeight(AVLTreeNode<T>* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLTreeNode<T>* node) {
        return node ? getHeight(static_cast<AVLTreeNode<T>*>(node->n_left)) - getHeight(static_cast<AVLTreeNode<T>*>(node->n_right)) : 0;
    }

    /// <summary>
    /// Вставка элемента в AVL-дерево
    /// </summary>
    /// <param name="data">Данные, которые нужно вставить</param>
    void insert(const T& data) {
        root = insert(root, data); // Вставляем данные и обновляем корень
    }

    /// <summary>
    /// Поиск элемента в AVL-дереве
    /// </summary>
    /// <param name="data">Данные, которые нужно найти</param>
    /// <returns>True, если элемент найден, иначе False</returns>
    bool search(const T& data) {
        return search(root, data); // Ищем элемент в дереве
    }

    /// <summary>
    /// Удаление элемента из AVL-дерева
    /// </summary>
    /// <param name="data">Данные, которые нужно удалить</param>
    void remove(const T& data) {
        root = remove(root, data); // Удаляем данные и обновляем корень
    }

    /// <summary>
    /// Обход дерева в префиксном порядке (pre-order)
    /// </summary>
    void preOrderTraversal() {
        preOrderTraversal(root); // Запускаем обход с корня
        std::cout << std::endl; // Переводим строку после завершения обхода
    }

    /// <summary>
    /// Обход дерева в симметричном порядке (in-order)
    /// </summary>
    void inOrderTraversal() {
        inOrderTraversal(root); // Запускаем обход с корня
        std::cout << std::endl; // Переводим строку после завершения обхода
    }

    /// <summary>
    /// Обход дерева в постфиксном порядке (post-order)
    /// </summary>
    void postOrderTraversal() {
        postOrderTraversal(root); // Запускаем обход с корня
        std::cout << std::endl; // Переводим строку после завершения обхода
    }

    /// <summary>
    /// Обход дерева в ширину (breadth-first)
    /// </summary>
    void breadthFirstTraversal() {
        breadthFirstTraversal(root); // Запускаем обход с корня
        std::cout << std::endl; // Переводим строку после завершения обхода
    }

    /// <summary>
    /// Получение максимальной глубины дерева
    /// </summary>
    /// <returns>Максимальная глубина дерева</returns>
    int getMaxDepth() {
        return maxDepth(root); // Возвращаем максимальную глубину
    }
};



/// <summary>
/// Функция для тестирования работы AVL-дерева
/// </summary>
void testAVLTree() {
    AVLTree<int> tree; // Создание экземпляра AVL-дерева для хранения целых чисел

    // Вставка элементов и проверка их наличия
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    assert(tree.search(10) == true);
    assert(tree.search(20) == true);
    assert(tree.search(5) == true);

    // Проверка структуры дерева после вставки (обход)
    std::cout << "Проверка in-order обхода после вставок: ";
    tree.inOrderTraversal(); // Ожидается: 5 10 20

    // Проверка глубины дерева
    assert(tree.getMaxDepth() == 2);

    // Вставка дополнительных элементов
    tree.insert(15);
    tree.insert(25);
    tree.insert(1);
    assert(tree.search(15) == true);
    assert(tree.search(25) == true);
    assert(tree.search(1) == true);

    // Проверка глубины после добавления новых элементов
    assert(tree.getMaxDepth() == 3);

    // Проверка обхода после дополнительных вставок
    std::cout << "Проверка pre-order обхода после новых вставок: ";
    tree.preOrderTraversal();

    // Проверка баланса и высоты после вставки нового элемента
    tree.insert(30);
    assert(tree.getBalance(tree.getRoot()) == -1); // Проверка баланса корня
    assert(tree.getHeight(tree.getRoot()) == 4);

    // Проверка правого поворота
    AVLTree<int> rightRotateTree;
    rightRotateTree.insert(30);
    rightRotateTree.insert(20);
    rightRotateTree.insert(10); // Вставка элементов для правого поворота
    assert(rightRotateTree.getRootValue() == 20); // После правого поворота корень должен быть 20


    // Проверка левого поворота
    AVLTree<int> leftRotateTree;
    leftRotateTree.insert(10);
    leftRotateTree.insert(20);
    leftRotateTree.insert(30); // Вставка элементов для левого поворота
    assert(leftRotateTree.getRootValue() == 20); // После левого поворота корень должен быть 20

    // Проверка удаления элементов
    tree.remove(10);
    assert(tree.search(10) == false);
    assert(tree.getMaxDepth() == 3);

    tree.remove(1);
    assert(tree.search(1) == false);

    // Проверка повторного удаления несуществующего элемента
    tree.remove(30);
    assert(tree.search(30) == false);

    // Проверка оставшихся элементов после удаления
    std::cout << "Проверка in-order обхода после удалений: ";
    tree.inOrderTraversal();

    // Дополнительные тесты для широкого обхода
    std::cout << "Проверка широкого обхода: ";
    tree.breadthFirstTraversal();
}

/// <summary>
/// Тестирование поворотов
/// </summary>
void testRotations() {
    AVLTree<int> tree;

    // Тест правого поворота
    AVLTreeNode<int>* root = new AVLTreeNode<int>(30);
    root->n_left = new AVLTreeNode<int>(20);
    root->n_left->n_left = new AVLTreeNode<int>(10);

    root = tree.rightRotate(root);  // Обновляем корень после поворота
    tree.setRoot(root);  // Устанавливаем новый корень в дереве

    // Проверяем правильность изменений после правого поворота
    assert(tree.getRootValue() == 20);  // Новый корень должен быть 20

    // Тест левого поворота
    AVLTreeNode<int>* root2 = new AVLTreeNode<int>(40);
    root2->n_right = new AVLTreeNode<int>(50);
    root2->n_right->n_right = new AVLTreeNode<int>(60);

    root2 = tree.leftRotate(root2);  // Обновляем корень после поворота
    tree.setRoot(root2);  // Устанавливаем новый корень в дереве

    // Проверяем правильность изменений после левого поворота
    assert(tree.getRootValue() == 50);  // Новый корень должен быть 20

    std::cout << "Все тесты пройдены!" << std::endl;
}


