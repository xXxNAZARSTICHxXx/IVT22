#ifndef NTREECOR_H
#define NTREECOR_H

#include <vector>  // Подключаем библиотеку для работы с векторами
#include <iostream>  // Подключаем библиотеку для ввода-вывода
#include <cassert>  // Подключаем библиотеку для утверждений (assert)
using namespace std;  // Используем пространство имен std для упрощения кода

namespace NTree {  // Начало пространства имен для нашего дерева

    /// Структура для представления узла дерева
    template<typename T>  // Шаблон для универсальности типов данных
    struct NaryTreeNodeStruct {
        T data;  // Данные узла
        std::vector<NaryTreeNodeStruct<T>*> children;  // Список дочерних узлов

        /// Конструктор для инициализации узла
        NaryTreeNodeStruct(const T& value) : data(value) {
            assert(this != nullptr);  // Проверка, что узел успешно создан
        }
    };

    /// Класс для представления дерева
    template<typename T>
    class NaryTree {
    public:
        NaryTreeNodeStruct<T>* root;  // Указатель на корневой узел

        /// Конструктор, создающий дерево с корневым узлом
        NaryTree(const T& rootData) {
            root = new NaryTreeNodeStruct<T>(rootData);  // Создаем корневой узел
            assert(root != nullptr);  // Проверяем, что корневой узел создан
        }

        /// Конструктор копирования дерева
        NaryTree(const NaryTree& other) {
            root = copyNode(other.root);  // Копируем корневой узел
            assert(root != nullptr);  // Проверка успешного копирования
        }

        /// Оператор присваивания копированием
        NaryTree& operator=(const NaryTree& other) {
            if (this != &other) {  // Проверяем, что это не тот же объект
                deleteAllNodes(root);  // Удаляем текущее дерево
                root = copyNode(other.root);  // Копируем дерево
            }
            assert(root != nullptr);  // Проверка успешного копирования
            return *this;  // Возвращаем текущий объект
        }

        /// Конструктор перемещения дерева
        NaryTree(NaryTree&& other) noexcept : root(other.root) {
            assert(root != nullptr);  // Проверяем корректность перемещаемого объекта
            other.root = nullptr;  // Обнуляем исходный объект
        }

        /// Оператор присваивания перемещением
        NaryTree& operator=(NaryTree&& other) noexcept {
            if (this != &other) {  // Проверка, что это не тот же объект
                deleteAllNodes(root);  // Удаляем текущее дерево
                root = other.root;  // Перемещаем дерево
                assert(root != nullptr);  // Проверка корректности перемещения
                other.root = nullptr;  // Обнуляем исходное дерево
            }
            return *this;  // Возвращаем текущий объект
        }

        /// Деструктор для удаления дерева
        ~NaryTree() {
            deleteAllNodes(root);  // Удаляем все узлы
        }

        /// Добавление дочернего узла
        void addChild(NaryTreeNodeStruct<T>* parent, const T& childData) {
            assert(parent != nullptr);  // Проверяем, что родительский узел существует
            NaryTreeNodeStruct<T>* child = new NaryTreeNodeStruct<T>(childData);  // Создаем дочерний узел
            assert(child != nullptr);  // Проверка создания дочернего узла
            parent->children.push_back(child);  // Добавляем дочерний узел в список детей родителя
        }

        /// Вывод узла и его дочерних узлов на экран
        void printNode(const NaryTreeNodeStruct<T>* node, int level = 0) const {
            if (!node) return;  // Если узел пуст, ничего не делаем

            for (int i = 0; i < level; ++i) {  // Выводим отступ для уровней
                std::cout << "  ";
            }
            std::cout << node->data << std::endl;  // Выводим данные узла

            assert(level >= 0);  // Проверка, что уровень не отрицательный

            for (const auto& child : node->children) {  // Рекурсивный вывод детей
                assert(child != nullptr);  // Проверка, что узел не пустой
                printNode(child, level + 1);  // Увеличиваем уровень для дочерних узлов
            }
        }

        /// Поиск узла по значению
        NaryTreeNodeStruct<T>* findNode(NaryTreeNodeStruct<T>* node, const T& value) {
            assert(node != nullptr);  // Проверка, что узел существует
            if (node->data == value) return node;  // Если данные совпадают, возвращаем узел

            for (auto* child : node->children) {  // Ищем узел среди детей
                assert(child != nullptr);  // Проверяем, что дочерний узел существует
                NaryTreeNodeStruct<T>* result = findNode(child, value);  // Рекурсивно ищем
                if (result) return result;  // Если нашли, возвращаем узел
            }
            return nullptr;  // Узел не найден
        }

        /// Подсчет количества уровней в дереве
        int countLevels(const NaryTreeNodeStruct<T>* node) const {
            if (!node) return 0;  // Если узел пуст, уровней нет

            int maxDepth = 0;  // Инициализируем максимальную глубину
            for (const auto& child : node->children) {  // Проходим по детям
                assert(child != nullptr);  // Проверка, что дочерний узел существует
                maxDepth = std::max(maxDepth, countLevels(child));  // Считаем глубину рекурсивно
            }
            return maxDepth + 1;  // Возвращаем глубину + 1 для текущего узла
        }

        /// Подсчет количества узлов в дереве
        int countNodes(const NaryTreeNodeStruct<T>* node) const {
            if (!node) return 0;  // Если узел пуст, узлов нет

            int totalNodes = 1;  // Начинаем счет с текущего узла
            for (const auto& child : node->children) {  // Проходим по детям
                assert(child != nullptr);  // Проверка, что дочерний узел существует
                totalNodes += countNodes(child);  // Рекурсивно добавляем количество узлов
            }
            return totalNodes;  // Возвращаем общее количество узлов
        }

        /// Удаление узла по значению
        bool deleteNode(NaryTreeNodeStruct<T>* parent, const T& value) {
            assert(parent != nullptr);  // Проверка, что родительский узел существует

            for (auto it = parent->children.begin(); it != parent->children.end(); ++it) {
                if ((*it)->data == value) {  // Если нашли узел с нужным значением
                    deleteAllNodes(*it);  // Удаляем все дочерние узлы
                    delete* it;  // Удаляем сам узел
                    parent->children.erase(it);  // Удаляем указатель на узел из списка детей
                    return true;  // Узел успешно удален
                }

                if (deleteNode(*it, value)) {  // Рекурсивно ищем узел для удаления
                    return true;  // Узел найден и удален
                }
            }
            return false;  // Узел не найден
        }

        /// Удаление всех узлов в дереве
        void deleteAllNodes(NaryTreeNodeStruct<T>* node) {
            if (!node) return;  // Если узел пуст, ничего не делаем
            for (auto* child : node->children) {  // Проходим по детям
                assert(child != nullptr);  // Проверяем, что дочерний узел не пуст
                deleteAllNodes(child);  // Рекурсивно удаляем все дочерние узлы
                delete child;  // Удаляем узел
            }
            node->children.clear();  // Очищаем список детей узла
        }

    };

    // Тестовая функция
    void AssertCheck() {
        // Создание корневого узла и дерева
        NaryTree<int> tree(0);  // Корневой узел с данными 0
        NaryTreeNodeStruct<int>* root = tree.root;  // Получаем указатель на корневой узел

        assert(root != nullptr);  // Проверка успешного создания корневого узла

        // Добавление дочерних узлов к корневому узлу
        tree.addChild(root, 1);  // Добавляем узел с данными 1
        tree.addChild(root, 2);  // Добавляем узел с данными 2
        tree.addChild(root, 3);  // Добавляем узел с данными 3

        // Поиск узлов по их значениям
        NaryTreeNodeStruct<int>* node1 = tree.findNode(root, 1);  // Поиск узла с данными 1
        NaryTreeNodeStruct<int>* node2 = tree.findNode(root, 2);  // Поиск узла с данными 2
        NaryTreeNodeStruct<int>* node3 = tree.findNode(root, 3);  // Поиск узла с данными 3

        // Проверка, что узлы найдены
        assert(node1 != nullptr && "Ошибка: узел 1 не найден");  // Убедитесь, что узел 1 существует
        assert(node2 != nullptr && "Ошибка: узел 2 не найден");  // Убедитесь, что узел 2 существует
        assert(node3 != nullptr && "Ошибка: узел 3 не найден");  // Убедитесь, что узел 3 существует

        // Добавление дочерних узлов для узла с данными 1
        tree.addChild(node1, 4);  // Добавляем дочерний узел с данными 4
        tree.addChild(node1, 5);  // Добавляем дочерний узел с данными 5

        // Проверка поиска узла с данными 5
        NaryTreeNodeStruct<int>* foundNode = tree.findNode(root, 5);  // Поиск узла с данными 5
        assert(foundNode != nullptr && foundNode->data == 5 && "Ошибка: узел 5 не найден или данные не совпадают");  // Убедитесь, что узел найден и данные совпадают

        // Проверка подсчета уровней дерева
        int levels = tree.countLevels(root);  // Получаем количество уровней дерева
        assert(levels == 3 && "Ошибка: неправильное количество уровней в дереве");  // Проверка, что количество уровней равно ожидаемому

        // Проверка подсчета узлов в дереве
        int nodeCount = tree.countNodes(root);  // Получаем общее количество узлов в дереве
        assert(nodeCount == 6 && "Ошибка: неправильное количество узлов в дереве");  // Проверка, что количество узлов равно ожидаемому

        // Удаление всех узлов и проверка состояния дерева
        tree.deleteAllNodes(root);  // Удаляем все узлы дерева
        assert(root->children.empty() && "Ошибка: дерево не удалено полностью");  // Проверка, что список детей корневого узла пуст, что подтверждает удаление
    }
}

#endif


