///���� ����� �������� ���-22
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <functional>
#include <cassert>
#include <stack>


template<typename T>
struct TreeNode {
    T n_data;              // ������, ���������� � ����
    TreeNode<T>* n_left;   // ��������� �� ����� ���������
    TreeNode<T>* n_right;  // ��������� �� ������ ���������

    // ����������� ���� ��� ����������
    TreeNode() : n_data(T()), n_left(nullptr), n_right(nullptr) {
        // ������������� �� ���������: ������ ��������� �� ���������� � �������� �� ��������� ��� ������
    }

    // ����������� � �������������� ������
    TreeNode(const T& data) : n_data(data), n_left(nullptr), n_right(nullptr) {
        // �������������� ���� � ��������� ������� � ������� ����������� �� ����������
    }

    // ����������� � ����������� �� ����� � ������ ����������
    TreeNode(const T& data, TreeNode<T>* left, TreeNode<T>* right)
        : n_data(data), n_left(left), n_right(right) {
        // ������������� ���� � ������� � ����������� �� �������� ����
    }
    /*
    // ���������� ��� ������� ������
    ~TreeNode() {
        delete n_left;  // ������� ����� ���������
        delete n_right; // ������� ������ ���������
    }*/

    // ����������� �����������
    TreeNode(const TreeNode& other)
        : n_data(other.n_data), n_left(nullptr), n_right(nullptr) {
        // ����������� ������ � �������� ����� �����������, ���� ��� ����
        if (other.n_left) n_left = new TreeNode(*other.n_left);   // ����������� ����������� ������ ���������
        if (other.n_right) n_right = new TreeNode(*other.n_right); // ����������� ����������� ������� ���������
    }

    // �������� ������������ ������������
    TreeNode& operator=(const TreeNode& other) {
        if (this == &other) return *this; // ������ �� ����������������
        delete n_left;  // �������� ������� �����������
        delete n_right;
        n_data = other.n_data; // ����������� ������
        n_left = other.n_left ? new TreeNode(*other.n_left) : nullptr; // ����������� �����������, ���� ��� ����������
        n_right = other.n_right ? new TreeNode(*other.n_right) : nullptr;

        return *this;
    }

    // ����������� �����������
    TreeNode(TreeNode&& other) noexcept
        : n_data(std::move(other.n_data)), n_left(other.n_left), n_right(other.n_right) {
        // �������� ������ � ��������� �� ���������� �� ������� �������, �������� ��� ������
        other.n_left = nullptr;
        other.n_right = nullptr;
    }

    // �������� ������������ ������������
    TreeNode& operator=(TreeNode&& other) noexcept {
        if (this == &other) return *this; // ������ �� ����������������
        delete n_left;  // �������� ������� �����������
        delete n_right;
        
        n_data = std::move(other.n_data); // ����������� ������ � ���������� �� ����������
        n_left = other.n_left;
        n_right = other.n_right;

        other.n_left = nullptr; // ������� ������������ ������
        other.n_right = nullptr;

        return *this;
    }
};


//Big(O)- �� �������, ��������, ������� ����� O(n)
/// <summary>
/// ����� ������ ����� ���� (������ �������).
/// </summary>
/// <typeparam name="T">��� ������, ���������� � ����� ������.</typeparam>
/// <param name="root">��������� �� ������ ������ (����).</param>
template<typename T>
void iterativePreOrderSTACK(TreeNode<T>* root) {
    if (!root) return;  // ���� ������ ������, �������.

    std::stack<TreeNode<T>*> stack;  // ���������� ���� ��� �������� �����.
    stack.push(root);  // �������� � ��������� ����.

    while (!stack.empty()) {
        TreeNode<T>* current = stack.top();  // ����� ������� ����.
        stack.pop();  // ������� ��� �� �����.

        //std::cout << current->n_data << " ";  // ������������ ������� ����.

        // ������� ��������� ������� �������, ����� ����� ��� ��������� ������.
        if (current->n_right) stack.push(current->n_right);  // ����� ������� .get()
        if (current->n_left) stack.push(current->n_left);    // ����� ������� .get()
    }
}


/// <summary>
/// /// ��������� ��������� ���� ��������� ������ � �������������� �� ������� ����
/// </summary>
template<typename T>
class BinTree {
public:
    T n_data;              // ������, ���������� � ����
    BinTree<T>* n_left;   // ��������� �� ����� ���������
    BinTree<T>* n_right;  // ��������� �� ������ ���������

    /// ����������� �� ���������
    BinTree() : n_data(T()), n_left(nullptr), n_right(nullptr) {}

    /// ����������� � ���������� ��� ������������� ����
    BinTree(const T& data) : n_data(data), n_left(nullptr), n_right(nullptr) {}

    /// ����������� � ������� � ����������� �� ����� � ������ ����������
    BinTree(const T& data, BinTree<T>* left, BinTree<T>* right)
        : n_data(data), n_left(left), n_right(right) {}

    /// ����������
    ~BinTree() {
        delete n_left;
        delete n_right;
    }

    /// ����������� �����������
    BinTree(const BinTree& other)
        : n_data(other.n_data), n_left(nullptr), n_right(nullptr) {
        if (other.n_left != nullptr) {
            n_left = new BinTree(*other.n_left);  // �������� �����������
        }
        if (other.n_right != nullptr) {
            n_right = new BinTree(*other.n_right);  // �������� �����������
        }
    }

    /// �������� ������������ ������������
    BinTree& operator=(const BinTree& other) {
        if (this == &other) return *this;  // �������� ����������������

        // ������� ������� ������
        delete n_left;
        delete n_right;

        n_data = other.n_data;
        n_left = other.n_left ? new BinTree(*other.n_left) : nullptr;
        n_right = other.n_right ? new BinTree(*other.n_right) : nullptr;

        return *this;
    }

    /// ����������� �����������
    BinTree(BinTree&& other) noexcept
        : n_data(std::move(other.n_data)), n_left(other.n_left), n_right(other.n_right) {
        other.n_left = nullptr;
        other.n_right = nullptr;
    }

    /// �������� ������������ ������������
    BinTree& operator=(BinTree&& other) noexcept {
        if (this == &other) return *this;  // �������� ����������������

        // ������� ������� �������
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
/// �������� ��������� ������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"> �������� ���������� � ����� </param>
/// <returns></returns>
template<typename T>
TreeNode<T>* createTree(const std::vector<T>& data) {
    if (data.empty()) return nullptr; // ���� ������� ������ ����, ���������� nullptr (������ �� ��������)

    TreeNode<T>* root = new TreeNode<T>(data[0]); // ������ �������� ���� ������ � ������ ��������� �������
    for (size_t i = 1; i < data.size(); ++i) { // ���������� ���������� �������� ������� ������� � ������� 1
        insertIntoTree(root, data[i]); // ��������� ������ ������� � ������
    }

    return root; // ���������� ��������� �� ������ ������
}

/// <summary>
/// ������� ���� � ������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> ���� ������ </param>
/// <param name="value"> �������� � ������ </param>
template<typename T>
void insertIntoTree(TreeNode<T>*& node, const T& value) {
    if (!node) { // ���� ������� ���� ������, ������ ����� ����
        node = new TreeNode<T>(value);
        return; // ��������� ���������� ���������� ����� �������
    }
    if (value < node->n_data) { // ���� �������� ������ �������� ����, ��������� � ����� ���������
        insertIntoTree(node->n_left, value); // ���������� ��������� � ����� ���������
    }
    else { // ����� ��������� � ������ ���������
        insertIntoTree(node->n_right, value); // ���������� ��������� � ������ ���������
    }
}



/// /// ��������� ����� ��� ���������� ��������� ������ ������
template<typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;  // ������ ������

public:

    ///*****///

    // �������� ��� ������������� (in-order) ������ ������ RNL
    class Iterator {
    private:
        std::stack<TreeNode<T>*> stack; // ���� ��� �������� �����, ������� ����� ������
        TreeNode<T>* current; // ��������� �� ������� ���� (�� ����������� ��� ���������)

        // ����� ��� ������ � ������ ������ ���� ������
        void pushLeft(TreeNode<T>* node) {
            while (node) { // ���� ���� ����
                stack.push(node); // ��������� ���� � ����
                node = node->n_left; // ��������� � ������ �������
            }
        }

    public:
        // ����������� ��������� ������ ������ � �������������� ��������
        Iterator(TreeNode<T>* root) : current(nullptr) {
            pushLeft(root); // �������� � ����� � �������� � ������ ������ ����
        }

        // �������� ������������� ���������� ������ �������� ���� (���� �� ������� �����)
        T& operator*() {
            return stack.top()->n_data; // ���������� ������ ����, ������������ �� ������� �����
        }

        // ���������� �������� ���������� ��� �������� � ���������� ���� � ������
        Iterator& operator++() {
            TreeNode<T>* node = stack.top(); // �������� ���� � ������� �����
            stack.pop(); // ������� ���� �� ����� (��������� � ���������� ����)
            if (node->n_right) { // ���� � ���� ���� ������ �������
                pushLeft(node->n_right); // ��������� � ������ ������ ���� � ������ ���������
            }
            return *this; // ���������� �������� ��� ����������� ����������� ������
        }

        // �������� != ��� ��������� ���������� (��������, �� ��������� �� ����� ������)
        bool operator!=(const Iterator& other) const {
            return !stack.empty(); // ���������� true, ���� ���� �� ���� (�� ����, ���� ��� ���� ��� ������)
        }
    };

    // �������, ������������ �������� �� ������ ������
    Iterator begin() {
        return Iterator(root); // ���������� ��������, ���������� � ����� ������
    }

    // �������, ������������ �������� �� ����� ������ (������ ��������)
    Iterator end() {
        return Iterator(nullptr); // �������� �� nullptr, ��������������� �� ��������� ������
    }

    template<typename Iterator, typename Func>
    /// <summary>
    /// ��������� ������� �� ���� ��������� ���������
    /// </summary>
    /// <param name="begin">�������� �� ������ ���������</param>
    /// <param name="end">�������� �� ����� ���������</param>
    /// <param name="func">�������, ����������� � ������� ��������</param>
    void my_for_each(Iterator begin, Iterator end, Func func) {
        while (begin != end) {
            func(*begin); // ��������� ������� � �������� ��������
            ++begin; // ��������� � ���������� ��������
        }
    }


    template<typename Iterator, typename Predicate>
    /// <summary>
    /// ���������, ������������� �� ���� �� ���� ������� ���������
    /// </summary>
    /// <param name="begin">�������� �� ������ ���������</param>
    /// <param name="end">�������� �� ����� ���������</param>
    /// <param name="pred">��������, ����������� � ���������</param>
    /// <returns>���������� true, ���� ���� �� ���� ������� ������������� ���������</returns>
    bool my_any_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // ���� ���� �� ���� ������� ������������� ���������
                return true; // ���������� true
            }
            ++begin; // ��������� � ���������� ��������
        }
        return false; // �� ���� ������� �� ������������� ���������
    }

    template<typename Iterator, typename Predicate>
    /// <summary>
    /// ���������, ������������� �� ��� �������� ���������
    /// </summary>
    /// <param name="begin">�������� �� ������ ���������</param>
    /// <param name="end">�������� �� ����� ���������</param>
    /// <param name="pred">��������, ����������� � ���������</param>
    /// <returns>���������� true, ���� ��� �������� ������������� ���������</returns>
    bool my_all_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (!pred(*begin)) { // ���� ���� �� ���� ������� �� ������������� ���������
                return false; // ���������� false
            }
            ++begin; // ��������� � ���������� ��������
        }
        return true; // ��� �������� ������������� ���������
    }


    template<typename Iterator, typename Predicate>
    /// <summary>
    /// ���������, ��� �� ���� ������� �� ������������� ���������
    /// </summary>
    /// <param name="begin">�������� �� ������ ���������</param>
    /// <param name="end">�������� �� ����� ���������</param>
    /// <param name="pred">��������, ����������� � ���������</param>
    /// <returns>���������� true, ���� �� ���� ������� �� ������������� ���������</returns>
    bool my_none_of(Iterator begin, Iterator end, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // ���� ���� �� ���� ������� ������������� ���������
                return false; // ���������� false
            }
            ++begin; // ��������� � ���������� ��������
        }
        return true; // �� ���� ������� �� ������������� ���������
    }


    template<typename InputIterator, typename OutputIterator, typename Func>
    /// <summary>
    /// ����������� �������� � ������� ������� � ���������� ��������� � ������ ��������
    /// </summary>
    /// <param name="begin">�������� �� ������ ��������� ���������</param>
    /// <param name="end">�������� �� ����� ��������� ���������</param>
    /// <param name="out">�������� �� ������ �������� ���������</param>
    /// <param name="func">�������, ����������� � ������� ��������</param>
    void my_transform(InputIterator begin, InputIterator end, OutputIterator out, Func func) {
        while (begin != end) {
            *out = func(*begin); // ��������� ������� � ���������� ���������
            ++begin; // ��������� � ���������� �������� ��������� ���������
            ++out; // ��������� � ���������� �������� �������� ���������
        }
    }


    template<typename InputIterator, typename OutputIterator, typename Predicate>
    /// <summary>
    /// �������� ��������, ��������������� ���������, � ������ ��������
    /// </summary>
    /// <param name="begin">�������� �� ������ ��������� ���������</param>
    /// <param name="end">�������� �� ����� ��������� ���������</param>
    /// <param name="out">�������� �� ������ �������� ���������</param>
    /// <param name="pred">��������, ����������� � ���������</param>
    void my_copy_if(InputIterator begin, InputIterator end, OutputIterator out, Predicate pred) {
        while (begin != end) {
            if (pred(*begin)) { // ���� ������� ������������� ���������
                *out = *begin; // �������� ��� � ������� ��������
                ++out; // ��������� � ���������� �������� �������� ���������
            }
            ++begin; // ��������� � ���������� �������� ��������� ���������
        }
    }


    ///*****///

    // ����� ��� ��������� ����������� ������
    BinarySearchTree<T> copyTree() {
        BinarySearchTree<T> newTree;
        copyTreeRecursive(root.get(), newTree);
        return newTree;
    }

    //todo ������������� ��������� ��� ������

    /// <summary>
    /// ����������� �� ���������
    /// </summary>
    BinarySearchTree() : root(nullptr) {} // ����������� �������������� ������ � ������ ������

    /// <summary>
    /// ����������
    /// </summary>
    ~BinarySearchTree() {
        delete root; // ���������� ������� �������� ���� � ��� ��� ����������
    }

                    
                    
    //Big(O) - O(log n)
    /// <summary>
    /// ������� ������� ������ ���� � ������
    /// </summary>
    /// <param name="value"> �������� � ���� </param>
    void insert(const T& value) {
        root = insertRec(root, value); // ��������� ����� ���� � ������, ������� � �����
    }

    /// <summary>
    /// ����� ��� ��������� ����� ������
    /// </summary>
    TreeNode<T>* getRoot() const {
        return root; // ���������� ��������� �� ������ ������
    }


        


    /// <summary>
    /// ����������� ������� ������� ���� � �������� ������ ������ (BST)
    /// </summary>
    /// <param name="node">������� ���� ������</param>
    /// <param name="value">��������, ������� ����� ��������</param>
    /// <returns>��������� �� ������� ���� ������ (������ ���������)</returns>
    TreeNode<T>* insertRec(TreeNode<T>* node, const T& value) {
        // ���� ������� ���� ������, ������ ����� ���� � �������� ���������
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }

        // ���� �������� ������ �������� ����, ���� � ����� ���������
        if (value < node->n_data) {
            node->n_left = insertRec(node->n_left, value);
        }
        // ���� �������� ������ �������� ����, ���� � ������ ���������
        else if (value > node->n_data) {
            node->n_right = insertRec(node->n_right, value);
        }

        // ���������� ������� ���� ����� �������
        return node;
    }


    /// <summary>
    /// ����� ���� � ������
    /// </summary>
    /// <param name="value"> �������� � ����</param>
    /// <returns></returns>
    bool search(const T& value) {
        return searchRec(root, value); // ���� ��������, ������� � �����
    }

    /// <summary>
    /// ����������� ������� ������ ���� ///TODO ����������� (������� ��������� �� ���� ��� nullptr)
    /// </summary>
    /// <param name="node">������� ����</param>
    /// <param name="value">������������� ��������</param>
    /// <returns>���������� ���� ��� nullptr</returns>
    bool searchRec(TreeNode<T>* node, const T& value) {
        if (node == nullptr) return false;  // ���� �� ������
        if (node->n_data == value) return true;  // ���� ������
        if (value < node->n_data) {
            return searchRec(node->n_left, value);  // ����� � ����� ���������
        }
        return searchRec(node->n_right, value);  // ����� � ������ ���������
    }

    /// <summary>
    /// �������� ���� ����� ������ 
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="node">������� ����</param>
    template<typename T>
    void deleteTree(TreeNode<T>* node) {
        if (node) {
            deleteTree(node->n_left); // ������� ����� ���������
            deleteTree(node->n_right); // ������� ������ ���������
            delete node; // ������� ��� ����
        }
    }


    /// <summary>
    /// �������� ���� � �������� ���������
    /// </summary>
    /// <param name="node">������� ����</param>
    /// <param name="value">������������� ��������</param>
    /// <returns>���������� ���������� ���� ��� nullptr</returns>
    TreeNode<T>* removeNode(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            return node; // ���� �� ������
        }

        // ����������� ����� ���� ��� ��������
        if (value < node->n_data) {
            node->n_left = removeNode(node->n_left, value);
        }
        else if (value > node->n_data) {
            node->n_right = removeNode(node->n_right, value);
        }
        else {

            // ���� ���: ���� ��� �����
            if (node->n_left == nullptr && node->n_right == nullptr) {
                delete node; // ������� ����
                return nullptr; // ���������� nullptr, ����� ������� ���� �� ������
            }

            // ���� ���: ���� � ����� ��������
            if (node->n_left == nullptr) {
                TreeNode<T>* temp = node->n_right; // ��������� ������ ���������
                delete node; // ������� ����
                return temp; // ���������� ������ ���������
            }
            else if (node->n_right == nullptr) {
                TreeNode<T>* temp = node->n_left; // ��������� ����� ���������
                delete node; // ������� ����
                return temp; // ���������� ����� ���������
            }

            // ���� ���: ���� � ����� ������
            // ������� ����������� ���� � ������ ���������
            TreeNode<T>* minNode = findMin(node->n_right);
            node->n_data = minNode->n_data; // �������� ������ ������������ ����
            node->n_right = removeRec(node->n_right, minNode->n_data); // ������� ����������� ����
        }
        return node;
    }





    /// �������� ����������� ������ NLR (todo: ������� ������� � ��������)
    template<typename T>
    void copyTreeRecursive(TreeNode<T>* node, BinarySearchTree<T>& tree) {
        if (node != nullptr) {
            tree.insert(node->n_data); // ��������� ������ ���� � ����� ������
            copyTreeRecursive(node->n_left, tree); // ���������� �������� ����� ���������
            copyTreeRecursive(node->n_right, tree); // ���������� �������� ������ ���������
        }
    }

    /// <summary>
    /// ����������� ����� ����
    /// </summary>
    /// <typeparam name="T">��� ������ � ���� ������</typeparam>
    /// <param name="node">������� ���� ��� ������</param>
    /// <param name="value">�������� ��� ������</param>
    /// <returns>��������� �� ��������� ���� ��� nullptr, ���� ���� �� ������</returns>
    template<typename T>
    TreeNode<T>* searchRecursive(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            return nullptr; // ���� ���� �� ������, ���������� nullptr
        }

        if (node->n_data == value) {
            return node; // ���� ����� ����, ���������� ��������� �� ����
        }
        else if (value < node->n_data) {
            return searchRecursive(node->n_left, value); // ���� � ����� ���������
        }
        else {
            return searchRecursive(node->n_right, value); // ���� � ������ ���������
        }
    }

    /// <summary>
    /// ����� ������ (��������, ������������ ������� LNR)
    /// </summary>
    void printTree() {
        std::vector<T> result;
        inorderTraversal(root, result); // �������� ������������ ����� (LNR) ��� ��������� ��������������� ������
        for (const auto& val : result) {
            std::cout << val << " "; // �������� �������� ������� ����
        }
        std::cout << std::endl; // ������� �� ����� ������
    }

    /// <summary>
    /// ������������ (LNR) ����� ������
    /// </summary>
    /// <typeparam name="T">��� ������ � ���� ������</typeparam>
    /// <param name="node">������� ����</param>
    /// <param name="result">��������� ��� �������� �������� �����</param>
    void inorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        inorderTraversal(node->n_left, result);  // ����� ���������
        result.push_back(node->n_data);          // ������� ����
        inorderTraversal(node->n_right, result);  // ������ ���������
    }

    /// <summary>
    /// ������������ (RNL) ����� ������
    /// </summary>
    /// <typeparam name="T">��� ������ � ���� ������</typeparam>
    /// <param name="node">������� ����</param>
    /// <param name="result">��������� ��� �������� �������� �����</param>
    template<typename T>
    void reverseInorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        reverseInorderTraversal(node->n_right, result);  // ������ ���������
        result.push_back(node->n_data);                  // ������
        reverseInorderTraversal(node->n_left, result);   // ����� ���������
    }

    /// <summary>
    /// ������ (NLR) ����� ������
    /// </summary>
    /// <typeparam name="T">��� ������ � ���� ������</typeparam>
    /// <param name="node">������� ����</param>
    /// <param name="result">��������� ��� �������� �������� �����</param>
    template<typename T>
    void preorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        result.push_back(node->n_data);            // ������
        preorderTraversal(node->n_left, result);   // ����� ���������
        preorderTraversal(node->n_right, result);  // ������ ���������
    }

    /// <summary>
    /// ������ (NRL) ����� ������
    /// </summary>
    /// <typeparam name="T">��� ������ � ���� ������</typeparam>
    /// <param name="node">������� ����</param>
    /// <param name="result">��������� ��� �������� �������� �����</param>
    template<typename T>
    void reversePreorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        result.push_back(node->n_data);            // ������
        reversePreorderTraversal(node->n_right, result);  // ������ ���������
        reversePreorderTraversal(node->n_left, result);   // ����� ���������
    }

    /// <summary>
    /// �������� (LRN) ����� ������
    /// </summary>
    /// <typeparam name="T">��� ������ � ���� ������</typeparam>
    /// <param name="node">������� ����</param>
    /// <param name="result">��������� ��� �������� �������� �����</param>
    template<typename T>
    void postorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        postorderTraversal(node->n_left, result);   // ����� ���������
        postorderTraversal(node->n_right, result);  // ������ ���������
        result.push_back(node->n_data);             // ������
    }

    /// <summary>
    /// �������� (RLN) ����� ������
    /// </summary>
    /// <typeparam name="T">��� ������ � ���� ������</typeparam>
    /// <param name="node">������� ����</param>
    /// <param name="result">��������� ��� �������� �������� �����</param>
    template<typename T>
    void reversePostorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
        if (node == nullptr) return;
        reversePostorderTraversal(node->n_right, result);  // ������ ���������
        reversePostorderTraversal(node->n_left, result);   // ����� ���������
        result.push_back(node->n_data);                    // ������
    }

    /// <summary>
/// ������� 500 ��������� � ������, � ������, ������ ������������ ��������
/// </summary>
    TreeNode<int>* create500ElementsTree() {
        BinarySearchTree<int> tree;  // ������ ��������� ������

        // �������� ����������� �������� ��� ������
        int mid = 5000 / 2;
        tree.insert(mid);  // ��������� ����������� ������� ��� ������

        // ��������� ��������� ��������
        for (int i = 0; i < 5000; ++i) {
            if (i != mid) {
                tree.insert(i);  // ��������� ��������� ��������
            }
        }

        return tree.getRoot();  // ��������������, ��� �� �������� ����� getRoot() � ����� BinarySearchTree
    }

    TreeNode<int>* create1000ElementsTree() {
        BinarySearchTree<int> tree;
        int mid = 1000 / 2;
        tree.insert(mid);  // ��������� ����������� ������� ��� ������

        for (int i = 0; i < 1000; ++i) {
            if (i != mid) {
                tree.insert(i);  // ��������� ��������� ��������
            }
        }

        return tree.getRoot();
    }

    TreeNode<int>* create5000ElementsTree() {
        BinarySearchTree<int> tree;
        int mid = 5000 / 2;
        tree.insert(mid);  // ��������� ����������� ������� ��� ������

        for (int i = 0; i < 5000; ++i) {
            if (i != mid) {
                tree.insert(i);  // ��������� ��������� ��������
            }
        }

        return tree.getRoot();
    }

    TreeNode<int>* create10000ElementsTree() {
        BinarySearchTree<int> tree;
        int mid = 10000 / 2;
        tree.insert(mid);  // ��������� ����������� ������� ��� ������

        for (int i = 0; i < 10000; ++i) {
            if (i != mid) {
                tree.insert(i);  // ��������� ��������� ��������
            }
        }

        return tree.getRoot();
    }

    TreeNode<int>* create25000ElementsTree() {
        BinarySearchTree<int> tree;
        int mid = 25000 / 2;
        tree.insert(mid);  // ��������� ����������� ������� ��� ������

        for (int i = 0; i < 25000; ++i) {
            if (i != mid) {
                tree.insert(i);  // ��������� ��������� ��������
            }
        }

        return tree.getRoot();
    }


    /// <summary>
    /// �������� �������� ��������� ������ � ����������������� ����������
    /// </summary>
    /// <returns>��������� �� ������ ������</returns>
    TreeNode<int>* createBinBigTree() {
        insert(16); // ��������� �������� ���� �� ��������� 16
        insert(8);  // ��������� ���� �� ��������� 8 (����� ������� �� 16)
        insert(24); // ��������� ���� �� ��������� 24 (������ ������� �� 16)
        insert(4);  // ��������� ���� �� ��������� 4 (����� ������� �� 8)
        insert(12); // ��������� ���� �� ��������� 12 (������ ������� �� 8)
        insert(20); // ��������� ���� �� ��������� 20 (����� ������� �� 24)
        insert(28); // ��������� ���� �� ��������� 28 (������ ������� �� 24)
        insert(2);  // ��������� ���� �� ��������� 2 (����� ������� �� 4)
        insert(6);  // ��������� ���� �� ��������� 6 (������ ������� �� 4)
        insert(10); // ��������� ���� �� ��������� 10 (����� ������� �� 12)
        insert(14); // ��������� ���� �� ��������� 14 (������ ������� �� 12)
        insert(18); // ��������� ���� �� ��������� 18 (����� ������� �� 20)
        insert(22); // ��������� ���� �� ��������� 22 (������ ������� �� 20)
        insert(26); // ��������� ���� �� ��������� 26 (����� ������� �� 28)
        insert(30); // ��������� ���� �� ��������� 30 (������ ������� �� 28)

        return root; // ���������� ��������� �� ������ �������� ������
    }

    

};



/// <summary>
/// �������� ��������� ������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns> ���� �� ������ </returns>
template<typename T>
TreeNode<T>* createTree() {
    T value;
    std::cout << "������� ������ ��� �����: ";
    std::cin >> value;
    return new TreeNode<T>(value);
}

//Big(O) - O(n)
/// <summary>
/// �������� ��������� ������ 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"></param>
template<typename T>
void deleteTree(TreeNode<T>* root) {
    if (root == nullptr) return;  // ���� ������ ������, ������ �� ������
    deleteTree(root->n_left); // ���������� ������� ����� ���������
    deleteTree(root->n_right); // ���������� ������� ������ ���������
    delete root; // ������� ������� ���� (������)
}





//Big(O)- �� �������, ��������, ������� ������ ����� O(n)
/// <summary>
/// ������ ����� (NLR)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> ���� �� ������ ������ </param>
/// <param name="result"> �������������� ������ </param>
template<typename T>
void preorder(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    result.push_back(root->n_data);
    preorder(root->n_left, result);
    preorder(root->n_right, result);
}

//Big(O)- �� �������, ��������, ������� ������ ����� O(n)
/// <summary>
/// ������������ ����� (LNR)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> ���� �� ������ ������ </param>
/// <param name="result"> �������������� ������ </param>
template<typename T>
void inorder(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    inorder(root->n_left, result);
    result.push_back(root->n_data);
    inorder(root->n_right, result);
}

//Big(O)- �� �������, ��������, ������� ������ ����� O(n), ���� ������ ��������������, �� O(log n)
/// <summary>
/// �������� ����� (LRN)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> ���� �� ������ ������ </param>
/// <param name="result"> �������������� ������ </param>
template<typename T>
void postorder(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    postorder(root->n_left, result);
    postorder(root->n_right, result);
    result.push_back(root->n_data);
}

//Big(O)- �� �������, ��������, ������� ������ ����� O(n), ���� ������ ��������������, �� O(log n)
/// <summary>
/// �������� ����� (RLN)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> ���� �� ������ ������ </param>
/// <param name="result"> �������������� ������ </param>
template<typename T>
void rln(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    rln(root->n_right, result);   // ������ ���������
    rln(root->n_left, result);    // ����� ���������
    result.push_back(root->n_data); // ������� ����
}

//Big(O)- �� �������, ��������, ������� ������ ����� O(n), ���� ������ ��������������, �� O(log n)
/// <summary>
/// ������������ ����� (RNL)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> ���� �� ������ ������ </param>
/// <param name="result"> �������������� ������ </param>
template<typename T>
void rnl(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    rnl(root->n_right, result);   // ������ ���������
    result.push_back(root->n_data); // ������� ����
    rnl(root->n_left, result);    // ����� ���������
}

//Big(O)- �� �������, ��������, ������� ������ ����� O(n), ���� ������ ��������������, �� O(log n)
/// <summary>
/// �������� ����� (NRL)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> ���� �� ������ ������ </param>
/// <param name="result"> �������������� ������ </param>
template<typename T>
void nrl(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    result.push_back(root->n_data); // ������� ����
    nrl(root->n_right, result);   // ������ ���������
    nrl(root->n_left, result);    // ����� ���������
}



/// <summary>
/// ���������� ������� �� ���� ����� NLR
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> ���� �� ������ ������ </param>
/// <param name="func"> ������ �������, ������� ��������� ������ �� ��������� ��������, ������� ������ �� ����������</param>
template<typename T>
void applyFunction(TreeNode<T>* node, const std::function<void(T&)>& func) {
    if (node == nullptr) return;  // ���� ���� ������ (��� ����), ������������ �� ������� (������� ������ ��������)
    func(node->n_data); // ��������� ���������� ������� func � ������ �������� ����;
    applyFunction(node->n_left, func); // ���������� �������� ������� ��� ������ ��������� (������ NLR � ������� ������������ ����� ���������)
    applyFunction(node->n_right, func); // ���������� �������� ������� ��� ������� ��������� (����� ��������� ������ ��������� ������������ ������)
}


/// <summary>
/// ������ NRL ���������� �������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> ���� �� ������ ������ </param>
/// <param name="func">  ����� �������  </param>
template<typename T>
void applyPreorder(TreeNode<T>* node, const std::function<void(T&)>& func) {
    if (node == nullptr) return;  // ���� ���� ������, ������� �� �������
    func(node->n_data);  // ��������� ������� � ������ �������� ����
    applyPreorder(node->n_left, func);  // ���������� ��������� ������� � ������ ���������
    applyPreorder(node->n_right, func); // ���������� ��������� ������� � ������� ���������
}

/// <summary>
/// ������������ NLR ���������� �������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> ���� �� ������ ������ </param>
/// <param name="func">  ����� �������  </param>
template<typename T>
void applyInorder(TreeNode<T>* node, const std::function<void(T&)>& func) {
    if (node == nullptr) return;  // ���� ���� ������, ������� �� �������
    applyInorder(node->n_left, func);  // ���������� ��������� ������� � ������ ���������
    func(node->n_data);  // ��������� ������� � ������ �������� ����
    applyInorder(node->n_right, func); // ���������� ��������� ������� � ������� ���������
}

/// <summary>
/// �������� LRN ���������� �������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> ���� �� ������ ������ </param>
/// <param name="func">  ����� �������  </param>
template<typename T>
void applyPostorder(TreeNode<T>* node, const std::function<void(T&)>& func) {
    if (node == nullptr) return;  // ���� ���� ������, ������� �� �������
    applyPostorder(node->n_left, func);  // ���������� ��������� ������� � ������ ���������
    applyPostorder(node->n_right, func); // ���������� ��������� ������� � ������� ���������
    func(node->n_data);  // ��������� ������� � ������ �������� ����
}


//Big(O) - O(log n)
/// <summary>
/// ����� ���������� ����������� �������� //todo ���������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="current"> ���� �� ������ ������ </param>
/// <param name="value"> ������������� �������� </param>
/// <returns>���������� ��������� ���� ��� nullptr</returns>
template<typename T>
TreeNode<T>* searchSucc(TreeNode<T>* current, const T& value) {
    TreeNode<T>* prev = nullptr; // prev ����� ������� ���������� ���� (�������������� � �������� ������)
    while (current != nullptr) { // ���� ������������, ���� current �� ��������� �� ������ ����
        if (current->n_data == value) { // ���� ������� ���� �������� ������������� ��������
            break;  // �� ����� ������ ������� � ����� ���������� �����
        }
        else if (value < current->n_data) { // ���� �������� ������, ��� ������ � ������� ����
            prev = current;         // ��������� ������� ���� ��� ���������������
            current = current->n_left;  // ���� � ����� ��������� (��� �������� ������)
        }
        else { // ���� �������� ������, ��� ������ � ������� ����
            prev = current;         // ��������� ������� ���� ��� ���������������
            current = current->n_right; // ���� � ������ ��������� (��� �������� ������)
        }
    }
    if (current == nullptr) return nullptr; // ���� �� ����� �� ����� ������ (�������� �� �������), ���������� nullptr
    if (current->n_right != nullptr) { // ���� ������ ��������� �� ������, �� ��������� ���������� ������� ����� � ������ ���������
        current = current->n_right;  // ���� � ������ ���������
        while (current->n_left != nullptr) { // ������� ����� ����� ���� � ������ ��������� (����� ��������� ���� � ������ ���������)
            current = current->n_left;
        }
        return current;  // ���������� ���� ����� ����� ����
    }  
    return prev ? prev : nullptr; // ���� ������� ��������� ���, �� ���������� ���������� ���� (��������������)
}

//Big(O) - O(log n)
/// <summary>
/// ����������� ����� ��� ������ ���� � �������� ���������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node">�������� ����</param>
/// <param name="value">������������� ��������</param>
/// <returns>���������� ��������� ���� ��� nullptr</returns>
template<typename T>
TreeNode<T>* findBST(std::shared_ptr<TreeNode<T>> node, const T& value) {
    // ������� ������: ���� ���� ��� ������ �������
    if (node == nullptr || node->data == value) {
        return node;
    }
    // ���� ������� �������� ������ ������ �������� ����, ���� �����
    if (value < node->data) {
        return search(node->left, value);
    }
    // ���� ������� �������� ������ ������ �������� ����, ���� ������
    return search(node->right, value);
}



/// <summary>
/// ������� ��� ��������� ����������� ��������� ������
/// </summary>
/// <typeparam name="T"> ��� ������, ���������� � ����� ������ </typeparam>
/// <param name="node"> ��������� �� ���� (������) ��������� ������ </param>
/// <returns> ��������� �� ������ ������ (��������������) ������ </returns>
template<typename T>
TreeNode<T>* deepCopy(TreeNode<T>* node) {
    // ���� ������� ���� ������ (null), ���������� nullptr
    // ��� ������� ������ �������� � ����� ������ ������ ��� ����� �� ����� �����
    if (node == nullptr) {
        return nullptr;
    }
    TreeNode<T>* newNode = new TreeNode<T>(node->n_data); // ������� ����� ����, ������� ������ �������� ���� (node->n_data)
    newNode->n_left = deepCopy(node->n_left); // ���������� �������� ����� ��������� �������� ����
    newNode->n_right = deepCopy(node->n_right); // ���������� �������� ������ ��������� �������� ����
    return newNode; // ���������� ����� ����, ������� �������� ������ ������ ��������� (��� ������)
}




/// <summary>
/// ����� ����������� ��������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="current"> ���� ������, � �������� ���������� ����� </param>
/// <returns> ���������� ���� � ���������� ��������� </returns>
template<typename T>
TreeNode<T>* searchMin(TreeNode<T>* current) {
    if (current == nullptr) return nullptr;  // ���� ������ ������, ���������� nullptr

    // ���� �����, ���� ���� ��������
    while (current->n_left != nullptr) {
        current = current->n_left; // ������������ � ����� ���������
    }

    return current;  // ���������� ���� � ���������� ���������
}

/// <summary>
/// ����� ����������� ��������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="current"> ���� ������, � �������� ���������� ����� </param>
/// <returns> ���������� ���� � ���������� ��������� </returns>
template<typename T>
TreeNode<T>* searchMax(TreeNode<T>* current) {
    if (current == nullptr) return nullptr;  // ���� ������ ������, ���������� nullptr

    // ���� ������, ���� ���� ��������
    while (current->n_right != nullptr) {
        current = current->n_right; // ������������ � ������ ���������
    }

    return current;  // ���������� ���� � ���������� ���������
}

//Big(O) - O(n)
/// <summary>
/// ����������� �������� ����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> ���� ������, � �������� ���������� �������� </param>
/// <param name="value"> ��������, ������� ����� ������� </param>
template<typename T>
void deleteNodeRecursive(TreeNode<T>** node, const T& value) {
    if (*node == nullptr) return; // ���� ���� �� ������, ������ �� ������

    if (value < (*node)->n_data) {  // ���� �������� ������ �������� ����
        deleteNodeRecursive(&(*node)->n_left, value);  // ���� � ����� ���������
    }
    else if (value > (*node)->n_data) {  // ���� �������� ������ �������� ����
        deleteNodeRecursive(&(*node)->n_right, value);  // ���� � ������ ���������
    }
    else {  // �������� �������, ������� ����
        TreeNode<T>* nodeToDelete = *node;  // ��������� ��������� �� ���� ��� ��������

        if ((*node)->n_left == nullptr && (*node)->n_right == nullptr) {  // ���� � ���� ��� �����
            *node = nullptr;  // ������������� ���� ��� nullptr
            delete nodeToDelete;  // ������� ����
        }
        else if ((*node)->n_left != nullptr && (*node)->n_right == nullptr) {  // ���� ���� ������ ����� �������
            *node = (*node)->n_left;  // ���������� ��������� �� ������ �������
            delete nodeToDelete;  // ������� ����
        }
        else if ((*node)->n_left == nullptr && (*node)->n_right != nullptr) {  // ���� ���� ������ ������ �������
            *node = (*node)->n_right;  // ���������� ��������� �� ������� �������
            delete nodeToDelete;  // ������� ����
        }
        else {  // � ���� ���� ��� �������
            TreeNode<T>* nextLargest = searchSucc(*node, (*node)->n_data);  // ������� ���������
            (*node)->n_data = nextLargest->n_data;  // �������� ������ ��������� � ������� ����
            deleteNodeRecursive(&(*node)->n_right, nextLargest->n_data);  // ������� ��������� �� ������� ���������
        }
    }
}

/// <summary>
/// ����� ����������� �������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="result"> ������ ��������, ������� ����� ������� </param>
template<typename T>
void printVector(const std::vector<T>& result) {
    for (const auto& val : result) {
        std::cout << val << " ";  // �������� ������ �������� ����� ������
    }
    std::cout << std::endl;  // ������� �� ����� ������
}

/// <summary>
/// ������� ���������� ����� � ������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> ���� ������, � �������� ���������� ������� </param>
/// <returns> ���������� ����� � ������ </returns>
template<typename T>
int countNodes(TreeNode<T>* root) {
    if (root == nullptr) return 0;  // ���� ���� ������, ���������� 0
    return 1 + countNodes(root->n_left) + countNodes(root->n_right);  // ������������ ���� � ����� � ������ �����������
}

/// <summary>
/// ����������� ������� ������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> ���� ������, � �������� ���������� ������� ������� </param>
/// <returns> ������� ������ </returns>
template<typename T>
int treeDepth(TreeNode<T>* root) {
    if (root == nullptr) return 0;  // ���� ���� ������, ���������� 0
    return 1 + std::max(treeDepth(root->n_left), treeDepth(root->n_right));  // ���������� ������������ ������� ����� �����������
}

/// <summary>
/// ����������� ������ ������ � ���� ���������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> ���� ������, ������� ����� ����������� </param>
/// <param name="space"> ������� ������� �������� ��� ��������� ������ </param>
/// <param name="height"> ������ ������� ����� �������� ������ </param>
template<typename T>
void printTree(TreeNode<T>* root, int space = 0, int height = 10) {
    if (root == nullptr) return;  // ���� ���� ������, �������
    space += height;  // ����������� ������� ��� ���������� ������
    printTree(root->n_right, space);  // �������� ������ ���������
    std::cout << std::endl;
    for (int i = height; i < space; i++) std::cout << " ";  // ��������� �������
    std::cout << root->n_data << std::endl;  // �������� ������ �������� ����
    printTree(root->n_left, space);  // �������� ����� ���������
}


/// <summary>
/// LNR ����� (������������ �����)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> �������� ���� ������ </param>
/// <param name="result"> ������ ��� �������� ���������� ������ </param>
template<typename T>
void printInorder(TreeNode<T>* root, std::vector<T>& result) {
    inorderTraversal(root, result);  // �������� ������������ �����
    std::cout << "LNR �����:" << std::endl;  // �������� � ���� ������
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";  // ������� ������ ������� �������
    }
    std::cout << std::endl;  // ������� �� ����� ������
}

/// <summary>
/// LRN ����� (�������� ������������ �����)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> �������� ���� ������ </param>
/// <param name="result"> ������ ��� �������� ���������� ������ </param>
template<typename T>
void printPostorder(TreeNode<T>* root, std::vector<T>& result) {
    postorderTraversal(root, result);  // �������� �������� �����
    std::cout << "LRN �����:" << std::endl;  // �������� � ���� ������
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";  // ������� ������ ������� �������
    }
    std::cout << std::endl;  // ������� �� ����� ������
}

/// <summary>
/// NLR ����� (������ �����)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> �������� ���� ������ </param>
/// <param name="result"> ������ ��� �������� ���������� ������ </param>
template<typename T>
void printPreorder(TreeNode<T>* root, std::vector<T>& result) {
    preorderTraversal(root, result);  // �������� ������ �����
    std::cout << "NLR �����:" << std::endl;  // �������� � ���� ������
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";  // ������� ������ ������� �������
    }
    std::cout << std::endl;  // ������� �� ����� ������
}

/// <summary>
/// ������������ (LNR) ����� ������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> ���� ������ </param>
/// <param name="result"> ������ ��� �������� ���������� ������ </param>
template<typename T>
void inorderTraversal(TreeNode<T>* node, std::vector<T>& result) {
    if (node == nullptr) return;  // ���� ���� ������, �������
    inorderTraversal(node->n_left, result);  // ���������� ������� ����� ���������
    result.push_back(node->n_data);  // ��������� ������ �������� ���� � ���������
    inorderTraversal(node->n_right, result);  // ���������� ������� ������ ���������
}

/// <summary>
/// ������ ������ � ��������� �������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"> �������� ���� ������ </param>
template<typename T>
void printRandomOrder(TreeNode<T>* root) {
    if (root == nullptr) return;  // ���� ������ ������, �������
    std::vector<T> result;
    inorderTraversal(root, result);  // �������� ������������ ����� ������
    std::random_shuffle(result.begin(), result.end());  // ������������ ��������
    for (const auto& val : result) {
        std::cout << val << " ";  // ������� �������� ������������ ��������
    }
    std::cout << std::endl;  // ������� �� ����� ������
}


/// <summary>
/// ������� ��� �������� ��������� ������ � ������� �� 1 �� 31
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>�������� ���� ������</returns>
template<typename T>
TreeNode<T>* createBigTree() {
    TreeNode<T>* root = new TreeNode<T>(1);  // ������� �������� ���� � ������� 1
    root->n_left = new TreeNode<T>(2);       // ����� ������� � ������� 2
    root->n_right = new TreeNode<T>(3);      // ������ ������� � ������� 3

    root->n_left->n_left = new TreeNode<T>(4);   // ����� ������� 2
    root->n_left->n_right = new TreeNode<T>(5);  // ������ ������� 2
    root->n_right->n_left = new TreeNode<T>(6);  // ����� ������� 3
    root->n_right->n_right = new TreeNode<T>(7); // ������ ������� 3

    root->n_left->n_left->n_left = new TreeNode<T>(8);   // ����� ������� 4
    root->n_left->n_left->n_right = new TreeNode<T>(9);  // ������ ������� 4
    root->n_left->n_right->n_left = new TreeNode<T>(10); // ����� ������� 5
    root->n_left->n_right->n_right = new TreeNode<T>(11);// ������ ������� 5

    root->n_right->n_left->n_left = new TreeNode<T>(12);  // ����� ������� 6
    root->n_right->n_left->n_right = new TreeNode<T>(13); // ������ ������� 6
    root->n_right->n_right->n_left = new TreeNode<T>(14); // ����� ������� 7
    root->n_right->n_right->n_right = new TreeNode<T>(15);// ������ ������� 7

    root->n_left->n_left->n_left->n_left = new TreeNode<T>(16);  // ����� ������� 8
    root->n_left->n_left->n_left->n_right = new TreeNode<T>(17); // ������ ������� 8
    root->n_left->n_left->n_right->n_left = new TreeNode<T>(18); // ����� ������� 9
    root->n_left->n_left->n_right->n_right = new TreeNode<T>(19);// ������ ������� 9

    root->n_left->n_right->n_left->n_left = new TreeNode<T>(20);  // ����� ������� 10
    root->n_left->n_right->n_left->n_right = new TreeNode<T>(21); // ������ ������� 10
    root->n_left->n_right->n_right->n_left = new TreeNode<T>(22); // ����� ������� 11
    root->n_left->n_right->n_right->n_right = new TreeNode<T>(23);// ������ ������� 11

    root->n_right->n_left->n_left->n_left = new TreeNode<T>(24);  // ����� ������� 12
    root->n_right->n_left->n_left->n_right = new TreeNode<T>(25); // ������ ������� 12
    root->n_right->n_left->n_right->n_left = new TreeNode<T>(26); // ����� ������� 13
    root->n_right->n_left->n_right->n_right = new TreeNode<T>(27);// ������ ������� 13

    root->n_right->n_right->n_left->n_left = new TreeNode<T>(28);  // ����� ������� 14
    root->n_right->n_right->n_left->n_right = new TreeNode<T>(29); // ������ ������� 14
    root->n_right->n_right->n_right->n_left = new TreeNode<T>(30); // ����� ������� 15
    root->n_right->n_right->n_right->n_right = new TreeNode<T>(31);// ������ ������� 15

    return root;  // ���������� �������� ���� ������
}

/// <summary>
/// ������� ��� �������� ��������� ������ � ������� �� 1 �� 7 ��� ������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>�������� ���� ������</returns>
template<typename T>
TreeNode<T>* createSampleTree() {
    TreeNode<T>* root = new TreeNode<T>(1);  // ������� �������� ���� � ������� 1
    root->n_left = new TreeNode<T>(2);       // ����� ������� � ������� 2
    root->n_right = new TreeNode<T>(3);      // ������ ������� � ������� 3

    root->n_left->n_left = new TreeNode<T>(4);   // ����� ������� 2
    root->n_left->n_right = new TreeNode<T>(5);  // ������ ������� 2
    root->n_right->n_left = new TreeNode<T>(6);  // ����� ������� 3
    root->n_right->n_right = new TreeNode<T>(7); // ������ ������� 3

    return root;  // ���������� �������� ���� ������
}

/// <summary>
/// ������� ��� �������� ��������� ������ � ������������ ����� � ������� 5 ��� ������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>�������� ���� ������</returns>
template<typename T>
TreeNode<T>* createSampleTree2() {
    TreeNode<T>* root = new TreeNode<T>(5);  // ������� �������� ���� � ������� 5
    return root;  // ���������� �������� ���� ������
}

/// <summary>
/// ������� ��� �������� ��������� ������ � ������� �� 1 �� 6 (����������� ������)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>�������� ���� ������</returns>
template<typename T>
TreeNode<T>* createSampleTree3() {
    TreeNode<T>* root = new TreeNode<T>(1);  // ������� �������� ���� � ������� 1
    root->n_left = new TreeNode<T>(2);       // ����� ������� 1
    root->n_left->n_left = new TreeNode<T>(3);      // ����� ������� 2

    root->n_left->n_left->n_left = new TreeNode<T>(4);  // ����� ������� 3
    root->n_left->n_left->n_left->n_left = new TreeNode<T>(5); // ����� ������� 4
    root->n_left->n_left->n_left->n_left->n_left = new TreeNode<T>(6); // ����� ������� 5

    return root;  // ���������� �������� ���� ������
}

/// <summary>
/// ������� ��� �������� ��������� ������ ��� ������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>��������� �� ������ ������</returns>
template<typename T>
TreeNode<T>* createSampleTree4() {
    return nullptr;  // ���������� ��������� �� ������ ������
}

/// <summary>
/// �������� �������� ��������� ������ ������ � ������� �� 1 �� 7
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>�������� ���� ������</returns>
template<typename T>
TreeNode<T>* createBST() {
    TreeNode<T>* root = new TreeNode<T>(4);  // �������� ���� � ������� 4
    root->n_left = new TreeNode<T>(2);       // ����� ������� 4
    root->n_right = new TreeNode<T>(6);      // ������ ������� 4

    root->n_left->n_left = new TreeNode<T>(1);  // ����� ������� 2
    root->n_left->n_right = new TreeNode<T>(3); // ������ ������� 2
    root->n_right->n_left = new TreeNode<T>(5); // ����� ������� 6
    root->n_right->n_right = new TreeNode<T>(7);// ������ ������� 6

    return root;  // ���������� �������� ���� ������
}


/// <summary>
/// �������� ������� ������ (��� ��������� ������)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"> ������ ������, ������ </param>
template<typename T>
void deleteAllTree(TreeNode<T>* node) {
    if (node == nullptr) return;  // ���� ���� ����, ������ �� ������

    // ���������� ������� ����� � ������ ����������
    deleteAllTree(node->n_left);
    deleteAllTree(node->n_right);

    // ������� ������� ����
    delete node;
}

///*ASSERT ��������*///
///*ASSERT ��������*///
///*ASSERT ��������*///
///*ASSERT ��������*///
///*ASSERT ��������*///

/// <1.0.0>
/// ������� ��� ������������ ������ ������
//Todo -1 ������ 0 ������
void testTreeFunctions() {
    TreeNode<int>* root = createSampleTree<int>();  // ������� �������� ������
    assert(countNodes(root) == 7);  // �������� �� ���������� �����
    assert(treeDepth(root) == 3);   // �������� �� ������� ������

    std::vector<int> result;
    preorder(root, result);  // ������ �����
    std::vector<int> expectedPreorder = { 1, 2, 4, 5, 3, 6, 7 };
    assert(result == expectedPreorder);

    result.clear();
    inorder(root, result);  // ������������ �����
    std::vector<int> expectedInorder = { 4, 2, 5, 1, 6, 3, 7 };
    assert(result == expectedInorder);

    result.clear();
    postorder(root, result);  // �������� �����
    std::vector<int> expectedPostorder = { 4, 5, 2, 6, 7, 3, 1 };
    assert(result == expectedPostorder);

    result.clear();
    printRandomOrder(root);  // �������� ������ � ��������� �������
}


/// <1.0.1>
/// ������� ��� ������������ ������ ������
void testTreeFunctions2() {
    TreeNode<int>* root = createSampleTree2<int>();
    assert(countNodes(root) == 1);  // �������� �� ���������� �����
    assert(treeDepth(root) == 1);   // �������� �� ������� ������

    std::vector<int> result;
    preorder(root, result);  // ������ �����
    std::vector<int> expectedPreorder = { 5 };
    assert(result == expectedPreorder);

    result.clear();
    inorder(root, result);  // ������������ �����
    std::vector<int> expectedInorder = { 5 };
    assert(result == expectedInorder);

    result.clear();
    postorder(root, result);  // �������� �����
    std::vector<int> expectedPostorder = { 5 };
    assert(result == expectedPostorder);

    result.clear();
    printRandomOrder(root);
}
/// <1.0.1>
/// ������� ��� ������������ ������ ������
void testTreeFunctions3() {
    TreeNode<int>* root = createSampleTree3<int>();
    assert(countNodes(root) == 6);  // �������� �� ���������� �����
    assert(treeDepth(root) == 6);   // �������� �� ������� ������

    std::vector<int> result;
    preorder(root, result);  // ������ �����
    std::vector<int> expectedPreorder = { 1, 2, 3, 4, 5, 6 };
    assert(result == expectedPreorder);

    result.clear();
    inorder(root, result);  // ������������ �����
    std::vector<int> expectedInorder = { 6, 5, 4, 3, 2, 1 };
    assert(result == expectedInorder);

    result.clear();
    postorder(root, result);  // �������� �����
    std::vector<int> expectedPostorder = { 6, 5, 4, 3, 2, 1 };
    assert(result == expectedPostorder);

    result.clear();
    printRandomOrder(root);
}

/// ������� ��� ������������ ������ ������
void testTreeFunctions4() {
    TreeNode<int>* root = createSampleTree4<int>();  // ������ ������

    assert(countNodes(root) == 0);  // �������� �� ���������� �����
    assert(treeDepth(root) == 0);   // �������� �� ������� ������

    std::vector<int> result;
    preorder(root, result);  // ������ �����
    std::vector<int> expectedPreorder = {};
    assert(result == expectedPreorder);

    result.clear();
    inorder(root, result);  // ������������ �����
    std::vector<int> expectedInorder = {};
    assert(result == expectedInorder);

    result.clear();
    postorder(root, result);  // �������� �����
    std::vector<int> expectedPostorder = {};
    assert(result == expectedPostorder);

    result.clear();
    printRandomOrder(root);  // ������ ������
}

/// ������� ��� ������������ ������ � �������� ������� ������ (BST)
void testBSTFunctions() {
    BinarySearchTree<int> bst;

    // ��������� �������� � ������ � �������������� ���������� ������ insert
    std::vector<int> values = { 4, 2, 6, 1, 3, 5, 7 };
    for (const int& val : values) {
        bst.insert(val);  // ��������� ������� � ������
    }

    // �������� ��������� ������
    auto testBSTStructure = [&](TreeNode<int>* root) {
        // �������� ���������� �����
        assert(countNodes(root) == 7);

        // �������� ������� ������
        assert(treeDepth(root) == 3);

        // �������� ������������ ��������
        TreeNode<int>* minNode = searchMin(root);
        assert(minNode != nullptr && minNode->n_data == 1);

        // �������� ������������� ��������
        TreeNode<int>* maxNode = searchMax(root);
        assert(maxNode != nullptr && maxNode->n_data == 7);
        };

    // ���� �������
    auto testBSTTraversals = [&](TreeNode<int>* root) {
        std::vector<int> result;

        // ������������ (inorder) �����
        inorderTraversal(root, result);
        std::vector<int> expectedInorder = { 1, 2, 3, 4, 5, 6, 7 };
        assert(result == expectedInorder);

        result.clear();
        // �������� ������������ (rnl) �����
        rnl(root, result);
        std::vector<int> expectedRNL = { 7, 6, 5, 4, 3, 2, 1 };
        assert(result == expectedRNL);
        };

    // ���� �������� �����
    auto testBSTDeletion = [&](TreeNode<int>*& root) {
        // �������� �������� 4 (������)
        deleteNodeRecursive(&root, 4);
        std::vector<int> result;
        inorderTraversal(root, result);
        std::vector<int> expectedAfterDeletion = { 1, 2, 3, 5, 6, 7 };
        assert(result == expectedAfterDeletion);

        // �������� ����� ������
        deleteAllTree(root);
        assert(root == nullptr);
        };

    // ���� ���������� ������� � ����� ������
    auto testApplyFunction = [&](TreeNode<int>* root) {
        std::vector<int> result;
        inorderTraversal(root, result);
        std::vector<int> expectedModified = { 2, 4, 6, 8, 10, 12, 14 };
        assert(result == expectedModified);
        };

    // ����������� ������
    auto testTreeCopy = [&](TreeNode<int>* root) {
        BinarySearchTree<int> copiedTree;

        std::vector<int> resultOriginal;
        std::vector<int> resultCopy;
        inorderTraversal(root, resultOriginal);
        assert(resultOriginal == resultCopy);
        };

}


void runAllBinaryTreeTests() {
    // ������� ������ � ������� insertIntoTree
    std::vector<int> data = { 4, 2, 6, 1, 3, 5, 7 };
    TreeNode<int>* root = nullptr;
    for (const int& val : data) {
        insertIntoTree(root, val);
    }

    // �������� ��������� ������
    auto testTreeStructure = [&](TreeNode<int>* root) {
        // �������� ���������� �����
        assert(countNodes(root) == 7);

        // �������� ������� ������
        assert(treeDepth(root) == 3);

        // �������� ������������ � ������������� ��������
        TreeNode<int>* minNode = searchMin(root);
        assert(minNode != nullptr && minNode->n_data == 1);

        TreeNode<int>* maxNode = searchMax(root);
        assert(maxNode != nullptr && maxNode->n_data == 7);
        };

    // ���� �������
    auto testTraversals = [&](TreeNode<int>* root) {
        std::vector<int> result;

        // ������������ �����
        inorder(root, result);
        std::vector<int> expectedInorder = { 1, 2, 3, 4, 5, 6, 7 };
        assert(result == expectedInorder);

        result.clear();
        // ������ �����
        preorder(root, result);
        std::vector<int> expectedPreorder = { 4, 2, 1, 3, 6, 5, 7 };
        assert(result == expectedPreorder);

        result.clear();
        // �������� �����
        postorder(root, result);
        std::vector<int> expectedPostorder = { 1, 3, 2, 5, 7, 6, 4 };
        assert(result == expectedPostorder);

        result.clear();
        // ������ ����� � �������������� �����
        iterativePreOrderSTACK(root);
        preorder(root, result);
        assert(result == expectedPreorder);
        };

    // ���� �������� ���� � ������
    auto testNodeDeletion = [&](TreeNode<int>*& root) {
        // �������� ���� 4
        deleteNodeRecursive(&root, 4);
        std::vector<int> result;
        inorder(root, result);
        std::vector<int> expectedAfterDeletion = { 2, 3, 5, 6, 7 };
        assert(result == expectedAfterDeletion);

        // �������� ����� ������
        deleteAllTree(root);
        assert(root == nullptr);
        };

}

void runSingleNodeTreeTest() {
    // ������� ������ � ����� �����
    TreeNode<int>* root = new TreeNode<int>(5);  // ������-���� � ������������ �����

    // �������� ��������� ������
    auto testTreeStructure = [&](TreeNode<int>* root) {
        // �������� ���������� �����
        assert(countNodes(root) == 1);

        // �������� ������� ������
        assert(treeDepth(root) == 1);

        // �������� ������������ � ������������� ��������
        TreeNode<int>* minNode = searchMin(root);
        assert(minNode != nullptr && minNode->n_data == 5);

        TreeNode<int>* maxNode = searchMax(root);
        assert(maxNode != nullptr && maxNode->n_data == 5);
        };

    // ���� �������
    auto testTraversals = [&](TreeNode<int>* root) {
        std::vector<int> result;

        // ������������ �����
        inorder(root, result);
        std::vector<int> expectedInorder = { 5 };
        assert(result == expectedInorder);

        result.clear();
        // ������ �����
        preorder(root, result);
        std::vector<int> expectedPreorder = { 5 };
        assert(result == expectedPreorder);

        result.clear();
        // �������� �����
        postorder(root, result);
        std::vector<int> expectedPostorder = { 5 };
        assert(result == expectedPostorder);

        result.clear();
        // ������ ����� � �������������� �����
        iterativePreOrderSTACK(root);
        preorder(root, result);
        assert(result == expectedPreorder);
        };

    // ���� �������� ���� � ������
    auto testNodeDeletion = [&](TreeNode<int>*& root) {
        // �������� ���� 5 (������������� ����)
        deleteNodeRecursive(&root, 5);
        std::vector<int> result;
        inorder(root, result);
        std::vector<int> expectedAfterDeletion = {};  // ������ ������ ����� ��������
        assert(result == expectedAfterDeletion);

        // �������� ����� ������ (���� ������ ��� �����)
        deleteAllTree(root);
        assert(root == nullptr);
        };
}

void runDegenerateTreeTest() {
    // ������� ����������� ������ � 6 ������ (�������� ������)
    TreeNode<int>* root = nullptr;
    std::vector<int> data = { 1, 2, 3, 4, 5, 6 };
    
    for (const int& val : data) {
        insertIntoTree(root, val);
    }

    // �������� ��������� ������
    auto testTreeStructure = [&](TreeNode<int>* root) {
        // �������� ���������� �����
        assert(countNodes(root) == 6);

        // �������� ������� ������ (������� ����� ���������� ����� � ����������� ������)
        assert(treeDepth(root) == 6);

        // �������� ������������ � ������������� ��������
        TreeNode<int>* minNode = searchMin(root);
        assert(minNode != nullptr && minNode->n_data == 1);

        TreeNode<int>* maxNode = searchMax(root);
        assert(maxNode != nullptr && maxNode->n_data == 6);
    };

    // ���� �������
    auto testTraversals = [&](TreeNode<int>* root) {
        std::vector<int> result;

        // ������������ ����� (inorder) ��� ��������� ������: [1, 2, 3, 4, 5, 6]
        inorder(root, result);
        std::vector<int> expectedInorder = { 1, 2, 3, 4, 5, 6 };
        assert(result == expectedInorder);

        result.clear();
        // ������ ����� (preorder): [1, 2, 3, 4, 5, 6] (������� �����)
        preorder(root, result);
        std::vector<int> expectedPreorder = { 1, 2, 3, 4, 5, 6 };
        assert(result == expectedPreorder);

        result.clear();
        // �������� ����� (postorder): [6, 5, 4, 3, 2, 1] (�������� �������)
        postorder(root, result);
        std::vector<int> expectedPostorder = { 6, 5, 4, 3, 2, 1 };
        assert(result == expectedPostorder);

        result.clear();
        // ������ ����� � �������������� �����
        iterativePreOrderSTACK(root);
        preorder(root, result);
        assert(result == expectedPreorder);
    };

    // ���� �������� ���� � ������
    auto testNodeDeletion = [&](TreeNode<int>*& root) {
        // �������� ���� 4
        deleteNodeRecursive(&root, 4);
        std::vector<int> result;
        inorder(root, result);
        std::vector<int> expectedAfterDeletion = { 1, 2, 3, 5, 6 };
        assert(result == expectedAfterDeletion);

        // �������� ����� ������
        deleteAllTree(root);
        assert(root == nullptr);
    };
}

void runEmptyTreeTest() {
    // ������� ������ ������ (root = nullptr)
    TreeNode<int>* root = nullptr;

    // �������� ��������� ������� ������
    
        // ���������� ����� ������ ���� 0
        assert(countNodes(root) == 0);

        // ������� ������ ������ ���� 0
        assert(treeDepth(root) == 0);

        // ����� ������������ � ������������� �������� ������ ������� nullptr
        TreeNode<int>* minNode = searchMin(root);
        assert(minNode == nullptr);

        TreeNode<int>* maxNode = searchMax(root);
        assert(maxNode == nullptr);
    

    // ���� ������� ��� ������� ������
    auto testEmptyTreeTraversals = [&](TreeNode<int>* root) {
        std::vector<int> result;

        // ������������ ����� (������ ������� ������ ���������)
        inorder(root, result);
        std::vector<int> expectedInorder = {};
        assert(result == expectedInorder);

        result.clear();
        // ������ ����� (preorder)
        preorder(root, result);
        std::vector<int> expectedPreorder = {};
        assert(result == expectedPreorder);

        result.clear();
        // �������� ����� (postorder)
        postorder(root, result);
        std::vector<int> expectedPostorder = {};
        assert(result == expectedPostorder);
        };

    // ���� �������� ����� � ������ (�� ������ ������)
    auto testEmptyTreeDeletion = [&](TreeNode<int>*& root) {
        // ������� �������� ���� � ������ ������
        deleteNodeRecursive(&root, 4);
        assert(root == nullptr);  // ������ �������� ������

        // �������� ����� ������ (�������� �� ������ ������)
        deleteAllTree(root);
        assert(root == nullptr);
        };
    }

///*ASSERT ��������*///
///*ASSERT ��������*///
///*ASSERT ��������*///
///*ASSERT ��������*///
///*ASSERT ��������*///

/// <summary>
/// ������������� �������� <
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="lhs"> 1 ������� </param>
/// <param name="rhs"> 2 ������� </param>
/// <returns></returns>
template<typename T>
bool operator<(const TreeNode<T>& lhs, const TreeNode<T>& rhs) {
    return lhs.n_data < rhs.n_data;
}

/// <summary>
/// ������������� �������� >
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="lhs"> 1 ������� </param>
/// <param name="rhs"> 2 ������� </param>
/// <returns></returns>
template<typename T>
bool operator>(const TreeNode<T>& lhs, const TreeNode<T>& rhs) {
    return lhs.n_data > rhs.n_data;
}


#endif
