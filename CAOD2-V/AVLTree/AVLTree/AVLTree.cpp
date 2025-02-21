#include <iostream>
#include <algorithm>
#include <cassert>
#include "AVL.h"

int main() {
    setlocale(LC_ALL, "russian");

    // Выполнение тестов
    testAVLTree();
    testRotations();

    // Пример использования AVL дерева
    AVLTree<int> tree;

    // Вставляем элементы
    tree.insert(15);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(12);
    tree.insert(17);
    tree.insert(25);

    // Удаление элемента
    std::cout << "Удаляем элемент 10." << std::endl;
    tree.remove(10);

    std::cout << "Удаляем элемент 20." << std::endl;
    tree.remove(20);

    return 0;
}