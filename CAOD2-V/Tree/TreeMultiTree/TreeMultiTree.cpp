///Стич Назар Иванович ИВТ-22
#include <iostream>                                                                         
#include <fstream>                                                                                 
#include <clocale>                                                                                 
#include <time.h>                                                                                
#include <stdlib.h>                                                                               
#include <cstdlib>
#include <fstream> 
#include <ctime>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <functional> 
#include <vector>
#include "tree_h.h"


// Главный модуль
int main() {
    // Включение русской локали
    setlocale(LC_ALL, "russian");

    std::cout << "Assert проверки:" << std::endl;
    // Тестирование многих функций
    testTreeFunctions();
    testTreeFunctions2();
    testTreeFunctions3();
    testTreeFunctions4();
    testBSTFunctions();
    runAllBinaryTreeTests();
    runSingleNodeTreeTest();
    runDegenerateTreeTest();
    runEmptyTreeTest();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Главное выполнение кода по бинарному дереву:" << std::endl;
    // Создание дерева с 5 уровнями
    TreeNode<int>* root = createBigTree<int>();
    std::cout << std::endl;
    // Прямой обход (NLR)
    std::vector<int> result;
    preorder(root, result);
    std::cout << "Прямой обход (NLR): ";
    printVector(result);
    std::cout << std::endl;
    // Симметричный обход (LNR)
    result.clear();
    inorder(root, result);
    std::cout << "Симметричный обход (LNR): ";
    printVector(result);
    std::cout << std::endl;
    // Обратный обход (LRN)
    result.clear();
    postorder(root, result);
    std::cout << "Обратный обход (LRN): ";
    printVector(result);
    std::cout << std::endl;
    // Подсчёт количества узлов
    std::cout << "Количество узлов: " << countNodes(root) << std::endl;
    std::cout << std::endl;
    // Глубина дерева
    std::cout << "Глубина дерева: " << treeDepth(root) << std::endl;
    std::cout << std::endl;
    // Печать дерева
    std::cout << "Дерево:" << std::endl;
    printTree(root);
    // Печать в случайном порядке
    std::cout << "Произвольный порядок: ";
    printRandomOrder(root);
    std::cout << std::endl;
    // Удаление дерева
    deleteTree(root);
    root = nullptr;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`" << std::endl;
    std::cout << "Assert проверки:" << std::endl;

    std::cout << "Главное выполнение кода по бинарному дереву поиска:" << std::endl;

    BinarySearchTree<int> bst;
    BinarySearchTree<int> bstT;
    TreeNode<int>* binroot = bst.createBinBigTree();  // Получаем корень дерева
    
    std::cout << "Прямой обход (NLR): ";
    result.clear();
    preorder(binroot, result);
    for (int val : result) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Симметричный обход (LNR): ";
    result.clear();
    inorder(binroot, result);
    for (int val : result) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Обратный обход (LRN): ";
    result.clear();
    postorder(binroot, result);
    for (int val : result) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Количество узлов: " << countNodes(binroot) << std::endl;
    std::cout << "Глубина дерева: " << treeDepth(binroot) << std::endl;

    std::cout << "Случайный порядок обхода: ";
    printRandomOrder(binroot);

    // Печать дерева
    std::cout << "Бинарное дерево:" << std::endl;
    printTree(binroot);

    
        /*srand(time(nullptr));  // Инициализация генератора псевдослучайных чисел

        // Создание бинарного дерева из 1 000 000 элементов
        TreeNode<long>* binrootLarge = bstT.create10000000000ElementsTree();  // Получаем корень дерева

        int iterations = 500;  // Количество запусков поиска
        long long totalTime = 0;  // Суммарное время поиска

        for (int i = 0; i < iterations; ++i) {
            int randomValue = rand() % 1000000;  // Генерация случайного числа для поиска в диапазоне от 0 до 999999

            auto start_time = std::chrono::high_resolution_clock::now();  // Замер времени начала поиска
            bstT.search(randomValue);  // Поиск случайного числа в дереве
            auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time;  // Замер времени окончания

            totalTime += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();  // Добавляем время поиска
        }

        long long averageTime = totalTime / iterations;  // Рассчитываем среднее время поиска

        std::cout << "Среднее время поиска в дереве из 1 000 000 элементов за " << iterations << " итераций: "
            << averageTime << "ns\n";
    */
    return 0;
}
/*  Дерево бинарное пятиуровневое совершенное фото в цвете:


                                                        _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  1  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
                                                        |                                                                                                 |
                                                        |                                                                                                 |
                                                        |                                                                                                 |
                                                        |                                                                                                 |
                                  _ _ _ _ _ _ _ _ _ _ _ 2 _ _ _ _ _ _ _ _ _ _ _                                                     _ _ _ _ _ _ _ _ _ _ _ 3 _ _ _ _ _ _ _ _ _ _ _
                                 |                                             |                                                   |                                             |
                      _ _ _ _ _ _4_ _ _ _ _ _                       _ _ _ _ _ _5_ _ _ _ _ _                             _ _ _ _ _ _6_ _ _ _ _ _                       _ _ _ _ _ _7_ _ _ _ _ _
                      |                     |                       |                     |                             |                     |                       |                     |
                 _ _ _8_ _ _           _ _ _9_ _ _            _ _ _10_ _ _           _ _ _11_ _ _                 _ _ _12_ _ _           _ _ _13_ _ _           _ _ _14_ _ _           _ _ _15_ _ _
                 |         |           |         |            |          |           |          |                 |          |           |          |           |          |           |          |
                16         17         18         19          20          21         22          23               24          25         26          27         28          29         30          31

*/