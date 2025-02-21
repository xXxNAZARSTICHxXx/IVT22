using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace BinaryTree // Определение пространства имен для текущего проекта
{
    /// <summary>
    /// Класс, представляющий узел бинарного дерева
    /// </summary>
    public class BinaryTreeNode
    {
        /// <summary>
        /// Данные, хранящиеся в узле
        /// </summary>
        public int Data { get; set; }

        /// <summary>
        /// Левый дочерний узел
        /// </summary>
        public BinaryTreeNode Left { get; set; }

        /// <summary>
        /// Правый дочерний узел
        /// </summary>
        public BinaryTreeNode Right { get; set; }

        /// <summary>
        /// Конструктор класса BinaryTreeNode, инициализирующий данные
        /// </summary>
        /// <param name="data">Данные узла</param>
        public BinaryTreeNode(int data)
        {
            Data = data; // Установка данных узла
            Left = null; // Инициализация левого дочернего узла
            Right = null; // Инициализация правого дочернего узла
        }
    }

    /// <summary>
    /// Класс, представляющий бинарное дерево
    /// </summary>
    public class BinaryTree
    {
        /// <summary>
        /// Корневой узел дерева
        /// </summary>
        public BinaryTreeNode Root { get; private set; }

        /// <summary>
        /// Конструктор класса BinaryTree, создающий дерево с корневым узлом
        /// </summary>
        public BinaryTree()
        {
            Root = null; // Инициализация корневого узла
        }

        /// <summary>
        /// Метод для добавления узла в бинарное дерево
        /// </summary>
        /// <param name="value">Значение узла</param>
        public void Add(int value)
        {
            Root = AddRecursive(Root, value); // Добавляем узел рекурсивно
        }

        /// <summary>
        /// Рекурсивный метод для добавления узла
        /// </summary>
        /// <param name="node">Текущий узел</param>
        /// <param name="value">Значение узла</param>
        /// <returns>Возвращает обновлённый узел</returns>
        private BinaryTreeNode AddRecursive(BinaryTreeNode node, int value)
        {
            if (node == null)
            {
                return new BinaryTreeNode(value); // Создаем новый узел, если текущий null
            }

            // Добавляем по порядку
            if (value < node.Data)
            {
                node.Left = AddRecursive(node.Left, value); // Добавляем в левое поддерево
            }
            else if (value > node.Data)
            {
                node.Right = AddRecursive(node.Right, value); // Добавляем в правое поддерево
            }

            return node; // Возвращаем текущий узел
        }

        /// <summary>
        /// Метод для получения всех узлов дерева в порядке возрастания
        /// </summary>
        /// <returns>Возвращает список узлов в порядке возрастания</returns>
        public List<int> InOrderTraversal()
        {
            var result = new List<int>();
            InOrderTraversalRecursive(Root, result); // Начинаем обход с корневого узла
            return result;
        }

        /// <summary>
        /// Рекурсивный метод для обхода дерева в порядке возрастания
        /// </summary>
        /// <param name="node">Текущий узел</param>
        /// <param name="result">Список для хранения значений узлов</param>
        private void InOrderTraversalRecursive(BinaryTreeNode node, List<int> result)
        {
            if (node == null) return;

            InOrderTraversalRecursive(node.Left, result); // Обходим левое поддерево
            result.Add(node.Data); // Добавляем данные текущего узла
            InOrderTraversalRecursive(node.Right, result); // Обходим правое поддерево
        }


    }


    /// <summary>
    /// Класс для тестирования бинарного дерева
    /// </summary>
    public class BinaryTreeTest
    {
        /// <summary>
        /// Тестовая функция для проверки работы бинарного дерева
        /// </summary>
        public static void AssertCheck()
        {
            var tree = new BinaryTree(); // Создание бинарного дерева

            // Добавление узлов от 0 до 62
            for (int i = 0; i <= 62; i++)
            {
                tree.Add(i); // Добавляем узлы по порядку
            }

            // Проверка обхода дерева
            var inOrder = tree.InOrderTraversal(); // Получаем данные в порядке возрастания
            Debug.Assert(inOrder.Count == 63); // Проверяем, что добавлено 63 узла
            Debug.Assert(inOrder[0] == 0); // Проверяем, что первый элемент 0
            Debug.Assert(inOrder[62] == 62); // Проверяем, что последний элемент 62
        }
    }
}
