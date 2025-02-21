using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace BinaryTree // ����������� ������������ ���� ��� �������� �������
{
    /// <summary>
    /// �����, �������������� ���� ��������� ������
    /// </summary>
    public class BinaryTreeNode
    {
        /// <summary>
        /// ������, ���������� � ����
        /// </summary>
        public int Data { get; set; }

        /// <summary>
        /// ����� �������� ����
        /// </summary>
        public BinaryTreeNode Left { get; set; }

        /// <summary>
        /// ������ �������� ����
        /// </summary>
        public BinaryTreeNode Right { get; set; }

        /// <summary>
        /// ����������� ������ BinaryTreeNode, ���������������� ������
        /// </summary>
        /// <param name="data">������ ����</param>
        public BinaryTreeNode(int data)
        {
            Data = data; // ��������� ������ ����
            Left = null; // ������������� ������ ��������� ����
            Right = null; // ������������� ������� ��������� ����
        }
    }

    /// <summary>
    /// �����, �������������� �������� ������
    /// </summary>
    public class BinaryTree
    {
        /// <summary>
        /// �������� ���� ������
        /// </summary>
        public BinaryTreeNode Root { get; private set; }

        /// <summary>
        /// ����������� ������ BinaryTree, ��������� ������ � �������� �����
        /// </summary>
        public BinaryTree()
        {
            Root = null; // ������������� ��������� ����
        }

        /// <summary>
        /// ����� ��� ���������� ���� � �������� ������
        /// </summary>
        /// <param name="value">�������� ����</param>
        public void Add(int value)
        {
            Root = AddRecursive(Root, value); // ��������� ���� ����������
        }

        /// <summary>
        /// ����������� ����� ��� ���������� ����
        /// </summary>
        /// <param name="node">������� ����</param>
        /// <param name="value">�������� ����</param>
        /// <returns>���������� ���������� ����</returns>
        private BinaryTreeNode AddRecursive(BinaryTreeNode node, int value)
        {
            if (node == null)
            {
                return new BinaryTreeNode(value); // ������� ����� ����, ���� ������� null
            }

            // ��������� �� �������
            if (value < node.Data)
            {
                node.Left = AddRecursive(node.Left, value); // ��������� � ����� ���������
            }
            else if (value > node.Data)
            {
                node.Right = AddRecursive(node.Right, value); // ��������� � ������ ���������
            }

            return node; // ���������� ������� ����
        }

        /// <summary>
        /// ����� ��� ��������� ���� ����� ������ � ������� �����������
        /// </summary>
        /// <returns>���������� ������ ����� � ������� �����������</returns>
        public List<int> InOrderTraversal()
        {
            var result = new List<int>();
            InOrderTraversalRecursive(Root, result); // �������� ����� � ��������� ����
            return result;
        }

        /// <summary>
        /// ����������� ����� ��� ������ ������ � ������� �����������
        /// </summary>
        /// <param name="node">������� ����</param>
        /// <param name="result">������ ��� �������� �������� �����</param>
        private void InOrderTraversalRecursive(BinaryTreeNode node, List<int> result)
        {
            if (node == null) return;

            InOrderTraversalRecursive(node.Left, result); // ������� ����� ���������
            result.Add(node.Data); // ��������� ������ �������� ����
            InOrderTraversalRecursive(node.Right, result); // ������� ������ ���������
        }


    }


    /// <summary>
    /// ����� ��� ������������ ��������� ������
    /// </summary>
    public class BinaryTreeTest
    {
        /// <summary>
        /// �������� ������� ��� �������� ������ ��������� ������
        /// </summary>
        public static void AssertCheck()
        {
            var tree = new BinaryTree(); // �������� ��������� ������

            // ���������� ����� �� 0 �� 62
            for (int i = 0; i <= 62; i++)
            {
                tree.Add(i); // ��������� ���� �� �������
            }

            // �������� ������ ������
            var inOrder = tree.InOrderTraversal(); // �������� ������ � ������� �����������
            Debug.Assert(inOrder.Count == 63); // ���������, ��� ��������� 63 ����
            Debug.Assert(inOrder[0] == 0); // ���������, ��� ������ ������� 0
            Debug.Assert(inOrder[62] == 62); // ���������, ��� ��������� ������� 62
        }
    }
}
