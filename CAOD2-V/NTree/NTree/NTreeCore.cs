using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace NTree // ����������� ������������ ���� ��� �������� �������
{
    // �����, �������������� ���� N-������ ������
    public class NaryTreeNode<T>
    {
        public T Data { get; set; } // ������, ���������� � ����
        public List<NaryTreeNode<T>> Children { get; set; } // ������ �������� �����

        // ����������� ������ NaryTreeNode, ���������������� ������ � ������ �������� �����
        public NaryTreeNode(T data)
        {
            Data = data; // ��������� ������ ����
            Children = new List<NaryTreeNode<T>>(); // ������������� ������ �������� �����
        }

        // ����� ��� ���������� ��������� ����
        public void AddChild(NaryTreeNode<T> child)
        {
            Children.Add(child); // ��������� �������� ���� � ������
        }
    }

    // �����, �������������� N-����� ������
    public class NaryTree<T>
    {
        public NaryTreeNode<T> Root { get; private set; } // �������� ���� ������

        // ����������� ������ NaryTree, ��������� ������ � �������� �����
        public NaryTree(T rootData)
        {
            Root = new NaryTreeNode<T>(rootData); // ������������� ��������� ����
        }

        // ������� ��� �������� ����������� N-������ ������ � �������� ����������
        public static void CreateCompanyStructure<T>(NaryTree<T> tree, Func<string, T> converter)
        {
            // ���������� �������� ����
            var root = tree.Root; // �������� �������� ���� ������

            // ������� �������� ���� � ��������� �� � �����
            var node1 = new NaryTreeNode<T>(converter("��������� ������ �����"));
            var node2 = new NaryTreeNode<T>(converter("�����������"));
            var node3 = new NaryTreeNode<T>(converter("����������� �� ���������������� �����"));
            var node4 = new NaryTreeNode<T>(converter("�������� �� ������ � ���������"));
            var node5 = new NaryTreeNode<T>(converter("��������� �� ��������"));
            var node6 = new NaryTreeNode<T>(converter("����������� �� ���������������� ��������"));
            var node7 = new NaryTreeNode<T>(converter("���������"));
            var node8 = new NaryTreeNode<T>(converter("������ ������������"));

            // ��������� �������� ���� � �����
            root.AddChild(node1);
            root.AddChild(node2);
            root.AddChild(node3);
            root.AddChild(node4);
            root.AddChild(node5);
            root.AddChild(node6);
            root.AddChild(node7);
            root.AddChild(node8);

            // ��������� �������� ���� � ���� "����������� �� ���������������� �����"
            var node3_1 = new NaryTreeNode<T>(converter("��������"));
            var node3_2 = new NaryTreeNode<T>(converter("��� �����������"));
            var node3_3 = new NaryTreeNode<T>(converter("��� ���������"));
            var node3_4 = new NaryTreeNode<T>(converter("�����������"));
            var node3_5 = new NaryTreeNode<T>(converter("��� �������"));
            var node3_6 = new NaryTreeNode<T>(converter("�����������������"));

            // ��������� �������� ���� � ���� "����������� �� ���������������� �����"
            node3.AddChild(node3_1);
            node3.AddChild(node3_2);
            node3.AddChild(node3_3);
            node3.AddChild(node3_4);
            node3.AddChild(node3_5);
            node3.AddChild(node3_6);

            // ��������� �������� ���� � ���� "����������� �� ���������������� ��������"
            var node6_1 = new NaryTreeNode<T>(converter("����� ������"));
            var node6_2 = new NaryTreeNode<T>(converter("������������ �������������"));
            var node6_3 = new NaryTreeNode<T>(converter("���������-����������� �����"));

            // ��������� �������� ���� � ���� "����������� �� ���������������� ��������"
            node6.AddChild(node6_1);
            node6.AddChild(node6_2);
            node6.AddChild(node6_3);
        }

        // ����� ��� ���������� ��������� ���� � ���������� ������������� ����
        public void AddChild(NaryTreeNode<T> parent, T childData)
        {
            var child = new NaryTreeNode<T>(childData); // ������� ����� �������� ����
            parent.Children.Add(child); // ��������� �������� ���� � �������������
        }

        // ����� ��� ������ ���� �� ��������
        public NaryTreeNode<T> FindNode(NaryTreeNode<T> node, T value)
        {
            if (node.Data.Equals(value)) return node; // ���� ������ ���� ��������� � ��������, ���������� ����

            // �������� �� ���� �������� �����
            foreach (var child in node.Children)
            {
                var result = FindNode(child, value); // ���������� ���� � �������� �����
                if (result != null) return result; // ���� ���� ������, ���������� ���
            }
            return null; // ���� ���� �� ������, ���������� null
        }

        // ����� ��� �������� ������� ������
        public int CountLevels(NaryTreeNode<T> node)
        {
            if (node == null) return 0; // ���� ���� null, ���������� 0

            int maxDepth = 0; // ���������� ��� �������� ������������ �������
            // �������� �� ���� �������� �����
            foreach (var child in node.Children)
            {
                maxDepth = Math.Max(maxDepth, CountLevels(child)); // ��������� ������������ �������
            }
            return maxDepth + 1; // ���������� ������������ ������� + 1 (��� �������� ����)
        }

        // ����� ��� �������� ������ ���������� ����� � ������
        public int CountNodes(NaryTreeNode<T> node)
        {
            if (node == null) return 0; // ���� ���� null, ���������� 0

            int totalNodes = 1; // ��������� ������� ����
            // �������� �� ���� �������� �����
            foreach (var child in node.Children)
            {
                totalNodes += CountNodes(child); // ��������� ���������� ����� �������� �����
            }
            return totalNodes; // ���������� ����� ���������� �����
        }

        // ����� ��� �������� ���� �� ������
        public bool DeleteNode(NaryTreeNode<T> parent, T value)
        {
            // �������� �� ���� �������� �����
            for (int i = 0; i < parent.Children.Count; i++)
            {
                if (parent.Children[i].Data.Equals(value)) // ���� ������ ����
                {
                    parent.Children.RemoveAt(i); // ������� ����
                    return true; // ���������� true, ���� ���� ��� ������
                }
                // ���������� ���� � �������� �����
                if (DeleteNode(parent.Children[i], value))
                {
                    return true; // ���� ���� ��� ������, ���������� true
                }
            }
            return false; // ���� ���� �� ������, ���������� false
        }
    }

    // ����� ��� ������������ N-������ ������
    public class NaryTreeTest
    {
        // �������� �������
        public static void AssertCheck()
        {
            // �������� ��������� ���� � ������
            var tree = new NaryTree<string>("������"); // �������� ���� � ������� "������"
            var root = tree.Root; // �������� ��������� �� �������� ����

            // �������� ��������� ��������
            CreateCompanyStructure(tree, s => s); // �������� ��������� ������ � ��������� (s => s)

            // ���������� �������� ����� � ��������� ����
            tree.AddChild(root, "�������������� ����"); // ��������� �������������� ����

            // ����� ����� �� �� ���������
            var node1 = tree.FindNode(root, "��������� ������ �����");
            Debug.Assert(node1 != null); // ���������, ��� ���� 1 ����������

            // �������� �������� ������� ������
            int levels = tree.CountLevels(root); // �������� ���������� ������� ������
            Debug.Assert(levels > 0); // ��������, ��� ���������� ������� ������ 0

            // �������� �������� ����� � ������
            int nodeCount = tree.CountNodes(root); // �������� ����� ���������� ����� � ������
            Debug.Assert(nodeCount > 0); // ��������, ��� ���������� ����� ������ 0
        }

        // ��������� ������� ��� �������� ��������� ��������
        public static void CreateCompanyStructure<T>(NaryTree<T> tree, Func<string, T> converter)
        {
            // ���������� �������� ����
            var root = tree.Root; // �������� �������� ���� ������

            // ������� �������� ���� � ��������� �� � �����
            var node1 = new NaryTreeNode<T>(converter("��������� ������ �����"));
            var node2 = new NaryTreeNode<T>(converter("�����������"));
            var node3 = new NaryTreeNode<T>(converter("����������� �� ���������������� �����"));
            var node4 = new NaryTreeNode<T>(converter("�������� �� ������ � ���������"));
            var node5 = new NaryTreeNode<T>(converter("��������� �� ��������"));
            var node6 = new NaryTreeNode<T>(converter("����������� �� ���������������� ��������"));
            var node7 = new NaryTreeNode<T>(converter("���������"));
            var node8 = new NaryTreeNode<T>(converter("������ ������������"));

            // ��������� �������� ���� � �����
            root.AddChild(node1);
            root.AddChild(node2);
            root.AddChild(node3);
            root.AddChild(node4);
            root.AddChild(node5);
            root.AddChild(node6);
            root.AddChild(node7);
            root.AddChild(node8);

            // ��������� �������� ���� � ���� "����������� �� ���������������� �����"
            var node3_1 = new NaryTreeNode<T>(converter("��������"));
            var node3_2 = new NaryTreeNode<T>(converter("��� �����������"));
            var node3_3 = new NaryTreeNode<T>(converter("��� ���������"));
            var node3_4 = new NaryTreeNode<T>(converter("�����������"));
            var node3_5 = new NaryTreeNode<T>(converter("��� �������"));
            var node3_6 = new NaryTreeNode<T>(converter("�����������������"));

            // ��������� �������� ���� � ���� "����������� �� ���������������� �����"
            node3.AddChild(node3_1);
            node3.AddChild(node3_2);
            node3.AddChild(node3_3);
            node3.AddChild(node3_4);
            node3.AddChild(node3_5);
            node3.AddChild(node3_6);

            // ��������� �������� ���� � ���� "����������� �� ���������������� ��������"
            var node6_1 = new NaryTreeNode<T>(converter("����� ������"));
            var node6_2 = new NaryTreeNode<T>(converter("������������ �������������"));
            var node6_3 = new NaryTreeNode<T>(converter("���������-����������� �����"));

            // ��������� �������� ���� � ���� "����������� �� ���������������� ��������"
            node6.AddChild(node6_1);
            node6.AddChild(node6_2);
            node6.AddChild(node6_3);
        }
    }
}
