#ifndef NTREECOR_H
#define NTREECOR_H

#include <vector>  // ���������� ���������� ��� ������ � ���������
#include <iostream>  // ���������� ���������� ��� �����-������
#include <cassert>  // ���������� ���������� ��� ����������� (assert)
using namespace std;  // ���������� ������������ ���� std ��� ��������� ����

namespace NTree {  // ������ ������������ ���� ��� ������ ������

    /// ��������� ��� ������������� ���� ������
    template<typename T>  // ������ ��� ��������������� ����� ������
    struct NaryTreeNodeStruct {
        T data;  // ������ ����
        std::vector<NaryTreeNodeStruct<T>*> children;  // ������ �������� �����

        /// ����������� ��� ������������� ����
        NaryTreeNodeStruct(const T& value) : data(value) {
            assert(this != nullptr);  // ��������, ��� ���� ������� ������
        }
    };

    /// ����� ��� ������������� ������
    template<typename T>
    class NaryTree {
    public:
        NaryTreeNodeStruct<T>* root;  // ��������� �� �������� ����

        /// �����������, ��������� ������ � �������� �����
        NaryTree(const T& rootData) {
            root = new NaryTreeNodeStruct<T>(rootData);  // ������� �������� ����
            assert(root != nullptr);  // ���������, ��� �������� ���� ������
        }

        /// ����������� ����������� ������
        NaryTree(const NaryTree& other) {
            root = copyNode(other.root);  // �������� �������� ����
            assert(root != nullptr);  // �������� ��������� �����������
        }

        /// �������� ������������ ������������
        NaryTree& operator=(const NaryTree& other) {
            if (this != &other) {  // ���������, ��� ��� �� ��� �� ������
                deleteAllNodes(root);  // ������� ������� ������
                root = copyNode(other.root);  // �������� ������
            }
            assert(root != nullptr);  // �������� ��������� �����������
            return *this;  // ���������� ������� ������
        }

        /// ����������� ����������� ������
        NaryTree(NaryTree&& other) noexcept : root(other.root) {
            assert(root != nullptr);  // ��������� ������������ ������������� �������
            other.root = nullptr;  // �������� �������� ������
        }

        /// �������� ������������ ������������
        NaryTree& operator=(NaryTree&& other) noexcept {
            if (this != &other) {  // ��������, ��� ��� �� ��� �� ������
                deleteAllNodes(root);  // ������� ������� ������
                root = other.root;  // ���������� ������
                assert(root != nullptr);  // �������� ������������ �����������
                other.root = nullptr;  // �������� �������� ������
            }
            return *this;  // ���������� ������� ������
        }

        /// ���������� ��� �������� ������
        ~NaryTree() {
            deleteAllNodes(root);  // ������� ��� ����
        }

        /// ���������� ��������� ����
        void addChild(NaryTreeNodeStruct<T>* parent, const T& childData) {
            assert(parent != nullptr);  // ���������, ��� ������������ ���� ����������
            NaryTreeNodeStruct<T>* child = new NaryTreeNodeStruct<T>(childData);  // ������� �������� ����
            assert(child != nullptr);  // �������� �������� ��������� ����
            parent->children.push_back(child);  // ��������� �������� ���� � ������ ����� ��������
        }

        /// ����� ���� � ��� �������� ����� �� �����
        void printNode(const NaryTreeNodeStruct<T>* node, int level = 0) const {
            if (!node) return;  // ���� ���� ����, ������ �� ������

            for (int i = 0; i < level; ++i) {  // ������� ������ ��� �������
                std::cout << "  ";
            }
            std::cout << node->data << std::endl;  // ������� ������ ����

            assert(level >= 0);  // ��������, ��� ������� �� �������������

            for (const auto& child : node->children) {  // ����������� ����� �����
                assert(child != nullptr);  // ��������, ��� ���� �� ������
                printNode(child, level + 1);  // ����������� ������� ��� �������� �����
            }
        }

        /// ����� ���� �� ��������
        NaryTreeNodeStruct<T>* findNode(NaryTreeNodeStruct<T>* node, const T& value) {
            assert(node != nullptr);  // ��������, ��� ���� ����������
            if (node->data == value) return node;  // ���� ������ ���������, ���������� ����

            for (auto* child : node->children) {  // ���� ���� ����� �����
                assert(child != nullptr);  // ���������, ��� �������� ���� ����������
                NaryTreeNodeStruct<T>* result = findNode(child, value);  // ���������� ����
                if (result) return result;  // ���� �����, ���������� ����
            }
            return nullptr;  // ���� �� ������
        }

        /// ������� ���������� ������� � ������
        int countLevels(const NaryTreeNodeStruct<T>* node) const {
            if (!node) return 0;  // ���� ���� ����, ������� ���

            int maxDepth = 0;  // �������������� ������������ �������
            for (const auto& child : node->children) {  // �������� �� �����
                assert(child != nullptr);  // ��������, ��� �������� ���� ����������
                maxDepth = std::max(maxDepth, countLevels(child));  // ������� ������� ����������
            }
            return maxDepth + 1;  // ���������� ������� + 1 ��� �������� ����
        }

        /// ������� ���������� ����� � ������
        int countNodes(const NaryTreeNodeStruct<T>* node) const {
            if (!node) return 0;  // ���� ���� ����, ����� ���

            int totalNodes = 1;  // �������� ���� � �������� ����
            for (const auto& child : node->children) {  // �������� �� �����
                assert(child != nullptr);  // ��������, ��� �������� ���� ����������
                totalNodes += countNodes(child);  // ���������� ��������� ���������� �����
            }
            return totalNodes;  // ���������� ����� ���������� �����
        }

        /// �������� ���� �� ��������
        bool deleteNode(NaryTreeNodeStruct<T>* parent, const T& value) {
            assert(parent != nullptr);  // ��������, ��� ������������ ���� ����������

            for (auto it = parent->children.begin(); it != parent->children.end(); ++it) {
                if ((*it)->data == value) {  // ���� ����� ���� � ������ ���������
                    deleteAllNodes(*it);  // ������� ��� �������� ����
                    delete* it;  // ������� ��� ����
                    parent->children.erase(it);  // ������� ��������� �� ���� �� ������ �����
                    return true;  // ���� ������� ������
                }

                if (deleteNode(*it, value)) {  // ���������� ���� ���� ��� ��������
                    return true;  // ���� ������ � ������
                }
            }
            return false;  // ���� �� ������
        }

        /// �������� ���� ����� � ������
        void deleteAllNodes(NaryTreeNodeStruct<T>* node) {
            if (!node) return;  // ���� ���� ����, ������ �� ������
            for (auto* child : node->children) {  // �������� �� �����
                assert(child != nullptr);  // ���������, ��� �������� ���� �� ����
                deleteAllNodes(child);  // ���������� ������� ��� �������� ����
                delete child;  // ������� ����
            }
            node->children.clear();  // ������� ������ ����� ����
        }

    };

    // �������� �������
    void AssertCheck() {
        // �������� ��������� ���� � ������
        NaryTree<int> tree(0);  // �������� ���� � ������� 0
        NaryTreeNodeStruct<int>* root = tree.root;  // �������� ��������� �� �������� ����

        assert(root != nullptr);  // �������� ��������� �������� ��������� ����

        // ���������� �������� ����� � ��������� ����
        tree.addChild(root, 1);  // ��������� ���� � ������� 1
        tree.addChild(root, 2);  // ��������� ���� � ������� 2
        tree.addChild(root, 3);  // ��������� ���� � ������� 3

        // ����� ����� �� �� ���������
        NaryTreeNodeStruct<int>* node1 = tree.findNode(root, 1);  // ����� ���� � ������� 1
        NaryTreeNodeStruct<int>* node2 = tree.findNode(root, 2);  // ����� ���� � ������� 2
        NaryTreeNodeStruct<int>* node3 = tree.findNode(root, 3);  // ����� ���� � ������� 3

        // ��������, ��� ���� �������
        assert(node1 != nullptr && "������: ���� 1 �� ������");  // ���������, ��� ���� 1 ����������
        assert(node2 != nullptr && "������: ���� 2 �� ������");  // ���������, ��� ���� 2 ����������
        assert(node3 != nullptr && "������: ���� 3 �� ������");  // ���������, ��� ���� 3 ����������

        // ���������� �������� ����� ��� ���� � ������� 1
        tree.addChild(node1, 4);  // ��������� �������� ���� � ������� 4
        tree.addChild(node1, 5);  // ��������� �������� ���� � ������� 5

        // �������� ������ ���� � ������� 5
        NaryTreeNodeStruct<int>* foundNode = tree.findNode(root, 5);  // ����� ���� � ������� 5
        assert(foundNode != nullptr && foundNode->data == 5 && "������: ���� 5 �� ������ ��� ������ �� ���������");  // ���������, ��� ���� ������ � ������ ���������

        // �������� �������� ������� ������
        int levels = tree.countLevels(root);  // �������� ���������� ������� ������
        assert(levels == 3 && "������: ������������ ���������� ������� � ������");  // ��������, ��� ���������� ������� ����� ����������

        // �������� �������� ����� � ������
        int nodeCount = tree.countNodes(root);  // �������� ����� ���������� ����� � ������
        assert(nodeCount == 6 && "������: ������������ ���������� ����� � ������");  // ��������, ��� ���������� ����� ����� ����������

        // �������� ���� ����� � �������� ��������� ������
        tree.deleteAllNodes(root);  // ������� ��� ���� ������
        assert(root->children.empty() && "������: ������ �� ������� ���������");  // ��������, ��� ������ ����� ��������� ���� ����, ��� ������������ ��������
    }
}

#endif


