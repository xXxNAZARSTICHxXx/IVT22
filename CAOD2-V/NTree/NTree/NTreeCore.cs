using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace NTree // Определение пространства имен для текущего проекта
{
    // Класс, представляющий узел N-арного дерева
    public class NaryTreeNode<T>
    {
        public T Data { get; set; } // Данные, хранящиеся в узле
        public List<NaryTreeNode<T>> Children { get; set; } // Список дочерних узлов

        // Конструктор класса NaryTreeNode, инициализирующий данные и список дочерних узлов
        public NaryTreeNode(T data)
        {
            Data = data; // Установка данных узла
            Children = new List<NaryTreeNode<T>>(); // Инициализация списка дочерних узлов
        }

        // Метод для добавления дочернего узла
        public void AddChild(NaryTreeNode<T> child)
        {
            Children.Add(child); // Добавляем дочерний узел в список
        }
    }

    // Класс, представляющий N-арное дерево
    public class NaryTree<T>
    {
        public NaryTreeNode<T> Root { get; private set; } // Корневой узел дерева

        // Конструктор класса NaryTree, создающий дерево с корневым узлом
        public NaryTree(T rootData)
        {
            Root = new NaryTreeNode<T>(rootData); // Инициализация корневого узла
        }

        // Функция для создания конкретного N-арного дерева с заданной структурой
        public static void CreateCompanyStructure<T>(NaryTree<T> tree, Func<string, T> converter)
        {
            // Используем корневой узел
            var root = tree.Root; // Получаем корневой узел дерева

            // Создаем дочерние узлы и добавляем их к корню
            var node1 = new NaryTreeNode<T>(converter("Начальник охраны труда"));
            var node2 = new NaryTreeNode<T>(converter("Бухгалтерия"));
            var node3 = new NaryTreeNode<T>(converter("Заместитель по производственной части"));
            var node4 = new NaryTreeNode<T>(converter("Менеджер по работе с клиентами"));
            var node5 = new NaryTreeNode<T>(converter("Менеджеры по закупкам"));
            var node6 = new NaryTreeNode<T>(converter("Заместитель по административным вопросам"));
            var node7 = new NaryTreeNode<T>(converter("Секретарь"));
            var node8 = new NaryTreeNode<T>(converter("Служба безопасности"));

            // Добавляем дочерние узлы к корню
            root.AddChild(node1);
            root.AddChild(node2);
            root.AddChild(node3);
            root.AddChild(node4);
            root.AddChild(node5);
            root.AddChild(node6);
            root.AddChild(node7);
            root.AddChild(node8);

            // Добавляем дочерние узлы к узлу "Заместитель по производственной части"
            var node3_1 = new NaryTreeNode<T>(converter("Элеватор"));
            var node3_2 = new NaryTreeNode<T>(converter("Цех прессования"));
            var node3_3 = new NaryTreeNode<T>(converter("Цех рафинации"));
            var node3_4 = new NaryTreeNode<T>(converter("Лаборатория"));
            var node3_5 = new NaryTreeNode<T>(converter("Цех розлива"));
            var node3_6 = new NaryTreeNode<T>(converter("Автоподразделение"));

            // Добавляем дочерние узлы к узлу "Заместитель по производственной части"
            node3.AddChild(node3_1);
            node3.AddChild(node3_2);
            node3.AddChild(node3_3);
            node3.AddChild(node3_4);
            node3.AddChild(node3_5);
            node3.AddChild(node3_6);

            // Добавляем дочерние узлы к узлу "Заместитель по административным вопросам"
            var node6_1 = new NaryTreeNode<T>(converter("Отдел кадров"));
            var node6_2 = new NaryTreeNode<T>(converter("Строительное подразделение"));
            var node6_3 = new NaryTreeNode<T>(converter("Инженерно-технический отдел"));

            // Добавляем дочерние узлы к узлу "Заместитель по административным вопросам"
            node6.AddChild(node6_1);
            node6.AddChild(node6_2);
            node6.AddChild(node6_3);
        }

        // Метод для добавления дочернего узла к указанному родительскому узлу
        public void AddChild(NaryTreeNode<T> parent, T childData)
        {
            var child = new NaryTreeNode<T>(childData); // Создаем новый дочерний узел
            parent.Children.Add(child); // Добавляем дочерний узел к родительскому
        }

        // Метод для поиска узла по значению
        public NaryTreeNode<T> FindNode(NaryTreeNode<T> node, T value)
        {
            if (node.Data.Equals(value)) return node; // Если данные узла совпадают с искомыми, возвращаем узел

            // Проходим по всем дочерним узлам
            foreach (var child in node.Children)
            {
                var result = FindNode(child, value); // Рекурсивно ищем в дочерних узлах
                if (result != null) return result; // Если узел найден, возвращаем его
            }
            return null; // Если узел не найден, возвращаем null
        }

        // Метод для подсчета уровней дерева
        public int CountLevels(NaryTreeNode<T> node)
        {
            if (node == null) return 0; // Если узел null, возвращаем 0

            int maxDepth = 0; // Переменная для хранения максимальной глубины
            // Проходим по всем дочерним узлам
            foreach (var child in node.Children)
            {
                maxDepth = Math.Max(maxDepth, CountLevels(child)); // Обновляем максимальную глубину
            }
            return maxDepth + 1; // Возвращаем максимальную глубину + 1 (для текущего узла)
        }

        // Метод для подсчета общего количества узлов в дереве
        public int CountNodes(NaryTreeNode<T> node)
        {
            if (node == null) return 0; // Если узел null, возвращаем 0

            int totalNodes = 1; // Учитываем текущий узел
            // Проходим по всем дочерним узлам
            foreach (var child in node.Children)
            {
                totalNodes += CountNodes(child); // Добавляем количество узлов дочерних узлов
            }
            return totalNodes; // Возвращаем общее количество узлов
        }

        // Метод для удаления узла из дерева
        public bool DeleteNode(NaryTreeNode<T> parent, T value)
        {
            // Проходим по всем дочерним узлам
            for (int i = 0; i < parent.Children.Count; i++)
            {
                if (parent.Children[i].Data.Equals(value)) // Если найден узел
                {
                    parent.Children.RemoveAt(i); // Удаляем узел
                    return true; // Возвращаем true, если узел был удален
                }
                // Рекурсивно ищем в дочерних узлах
                if (DeleteNode(parent.Children[i], value))
                {
                    return true; // Если узел был удален, возвращаем true
                }
            }
            return false; // Если узел не найден, возвращаем false
        }
    }

    // Класс для тестирования N-арного дерева
    public class NaryTreeTest
    {
        // Тестовая функция
        public static void AssertCheck()
        {
            // Создание корневого узла и дерева
            var tree = new NaryTree<string>("Корень"); // Корневой узел с данными "Корень"
            var root = tree.Root; // Получаем указатель на корневой узел

            // Создание структуры компании
            CreateCompanyStructure(tree, s => s); // Передаем экземпляр дерева и конвертер (s => s)

            // Добавление дочерних узлов к корневому узлу
            tree.AddChild(root, "Дополнительный узел"); // Добавляем дополнительный узел

            // Поиск узлов по их значениям
            var node1 = tree.FindNode(root, "Начальник охраны труда");
            Debug.Assert(node1 != null); // Убедитесь, что узел 1 существует

            // Проверка подсчета уровней дерева
            int levels = tree.CountLevels(root); // Получаем количество уровней дерева
            Debug.Assert(levels > 0); // Проверка, что количество уровней больше 0

            // Проверка подсчета узлов в дереве
            int nodeCount = tree.CountNodes(root); // Получаем общее количество узлов в дереве
            Debug.Assert(nodeCount > 0); // Проверка, что количество узлов больше 0
        }

        // Шаблонная функция для создания структуры компании
        public static void CreateCompanyStructure<T>(NaryTree<T> tree, Func<string, T> converter)
        {
            // Используем корневой узел
            var root = tree.Root; // Получаем корневой узел дерева

            // Создаем дочерние узлы и добавляем их к корню
            var node1 = new NaryTreeNode<T>(converter("Начальник охраны труда"));
            var node2 = new NaryTreeNode<T>(converter("Бухгалтерия"));
            var node3 = new NaryTreeNode<T>(converter("Заместитель по производственной части"));
            var node4 = new NaryTreeNode<T>(converter("Менеджер по работе с клиентами"));
            var node5 = new NaryTreeNode<T>(converter("Менеджеры по закупкам"));
            var node6 = new NaryTreeNode<T>(converter("Заместитель по административным вопросам"));
            var node7 = new NaryTreeNode<T>(converter("Секретарь"));
            var node8 = new NaryTreeNode<T>(converter("Служба безопасности"));

            // Добавляем дочерние узлы к корню
            root.AddChild(node1);
            root.AddChild(node2);
            root.AddChild(node3);
            root.AddChild(node4);
            root.AddChild(node5);
            root.AddChild(node6);
            root.AddChild(node7);
            root.AddChild(node8);

            // Добавляем дочерние узлы к узлу "Заместитель по производственной части"
            var node3_1 = new NaryTreeNode<T>(converter("Элеватор"));
            var node3_2 = new NaryTreeNode<T>(converter("Цех прессования"));
            var node3_3 = new NaryTreeNode<T>(converter("Цех рафинации"));
            var node3_4 = new NaryTreeNode<T>(converter("Лаборатория"));
            var node3_5 = new NaryTreeNode<T>(converter("Цех розлива"));
            var node3_6 = new NaryTreeNode<T>(converter("Автоподразделение"));

            // Добавляем дочерние узлы к узлу "Заместитель по производственной части"
            node3.AddChild(node3_1);
            node3.AddChild(node3_2);
            node3.AddChild(node3_3);
            node3.AddChild(node3_4);
            node3.AddChild(node3_5);
            node3.AddChild(node3_6);

            // Добавляем дочерние узлы к узлу "Заместитель по административным вопросам"
            var node6_1 = new NaryTreeNode<T>(converter("Отдел кадров"));
            var node6_2 = new NaryTreeNode<T>(converter("Строительное подразделение"));
            var node6_3 = new NaryTreeNode<T>(converter("Инженерно-технический отдел"));

            // Добавляем дочерние узлы к узлу "Заместитель по административным вопросам"
            node6.AddChild(node6_1);
            node6.AddChild(node6_2);
            node6.AddChild(node6_3);
        }
    }
}
