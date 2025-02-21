#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include "TREE_H.h" // �����������, ��� ���� ��������� ��������� ���������� TreeNode

/// <summary>
/// ���� AVL-������
/// </summary>
template <typename T>
struct AVLTreeNode : public TreeNode<T> {
    signed char height; // ������ ���� //TODO ������ ������

    
    /// <summary>
    /// ����������� �� ���������
    /// </summary>
    AVLTreeNode() : TreeNode<T>(), height(1) {}

    /// <summary>
    /// ����������� � �������
    /// </summary>
    /// <param name="data">������, ������� ����� ��������� � ����</param>
    AVLTreeNode(const T& data) : TreeNode<T>(data), height(1) {}

    /// <summary>
    /// ����������� � ������� � ��������� ������
    /// </summary>
    /// <param name="data">������, ������� ����� ��������� � ����</param>
    /// <param name="left">��������� �� ����� �������� ����</param>
    /// <param name="right">��������� �� ������ �������� ����</param>
    AVLTreeNode(const T& data, AVLTreeNode<T>* left, AVLTreeNode<T>* right)
        : TreeNode<T>(data, left, right), height(1) {}




    T data; // ��� ����� ���� ��� ������, ���������� � ����
    AVLTreeNode<T>* left;
    AVLTreeNode<T>* right;
};

/// <summary>
/// ����� AVL-������
/// </summary>
template <typename T>
class AVLTree {

private:
    AVLTreeNode<T>* root; // ������ ������


    /// <summary>
    /// ���������� ������ ����
    /// </summary>
    /// <param name="node">��������� �� ����</param>
    void updateHeight(AVLTreeNode<T>* node) {
        if (node) {
            // ������ ���� ����� ������������ ������ ��� �������� ����� + 1
            node->height = std::max(getHeight(static_cast<AVLTreeNode<T>*>(node->n_left)),
                getHeight(static_cast<AVLTreeNode<T>*>(node->n_right))) + 1;
        }
    }


    /// <summary>
    /// �����-������ �������
    /// </summary>
    /// <param name="node">��������� �� ����, ��� �������� ����������� �������</param>
    /// <returns>����� ������ ��������� ����� ��������</returns>
    AVLTreeNode<T>* leftRightRotate(AVLTreeNode<T>* node) {
        node->n_left = leftRotate(static_cast<AVLTreeNode<T>*>(node->n_left)); // ������� ����� �������
        return rightRotate(node); // ����� ������ �������
    }

    /// <summary>
    /// ��������� ������ ����
    /// </summary>
    int getHeight(AVLTreeNode<T>* node) const {
        return node ? node->height : 0;
    }

    /// <summary>
    /// ������-����� �������
    /// </summary>
    /// <param name="node">��������� �� ����, ��� �������� ����������� �������</param>
    /// <returns>����� ������ ��������� ����� ��������</returns>
    AVLTreeNode<T>* rightLeftRotate(AVLTreeNode<T>* node) {
        node->n_right = rightRotate(static_cast<AVLTreeNode<T>*>(node->n_right)); // ������� ������ �������
        return leftRotate(node); // ����� ����� �������
    }

    /// <summary>
    /// ������ ����� ������
    /// </summary>
    /// <param name="node">��������� �� ����, � �������� ���������� �����</param>
    void preOrderTraversal(AVLTreeNode<T>* node) {
        if (node) {
            std::cout << node->n_data << " "; // ������� ������ ����
            preOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_left)); // ���������� ������� ����� ���������
            preOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_right)); // ���������� ������� ������ ���������
        }
    }

    /// <summary>
    /// ������������ ����� ������
    /// </summary>
    /// <param name="node">��������� �� ����, � �������� ���������� �����</param>
    void inOrderTraversal(AVLTreeNode<T>* node) {
        if (node) {
            inOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_left)); // ���������� ������� ����� ���������
            std::cout << node->n_data << " "; // ������� ������ ����
            inOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_right)); // ���������� ������� ������ ���������
        }
    }

    /// <summary>
    /// �������� ����� ������
    /// </summary>
    /// <param name="node">��������� �� ����, � �������� ���������� �����</param>
    void postOrderTraversal(AVLTreeNode<T>* node) {
        if (node) {
            postOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_left)); // ���������� ������� ����� ���������
            postOrderTraversal(static_cast<AVLTreeNode<T>*>(node->n_right)); // ���������� ������� ������ ���������
            std::cout << node->n_data << " "; // ������� ������ ����
        }
    }

//TODO SOLID ������� �����������

    /// <summary>
    /// ������� ����� ������ (�� �������)
    /// </summary>
    /// <param name="root">��������� �� ������ ������</param>
    void breadthFirstTraversal(AVLTreeNode<T>* root) {
        if (!root) return; // ���� ������ ������, �������

        std::queue<AVLTreeNode<T>*> queue; // ������� ������� ��� ������ �� �������
        queue.push(root); // ��������� ������ � �������

        while (!queue.empty()) {
            AVLTreeNode<T>* current = queue.front(); // �������� ������� ����
            queue.pop(); // ������� ��� �� �������
            std::cout << current->n_data << " "; // ������� ������ �������� ����

            // ��������� ������ ��������� ���� � �������
            if (current->n_left) {
                queue.push(static_cast<AVLTreeNode<T>*>(current->n_left));
            }
            // ��������� ������� ��������� ���� � �������
            if (current->n_right) {
                queue.push(static_cast<AVLTreeNode<T>*>(current->n_right));
            }
        }
    }

    /// <summary>
    /// ��������� ������������ ������� ���������
    /// </summary>
    /// <param name="node">��������� �� ����, � �������� ���������� ���������� �������</param>
    /// <returns>������������ ������� ���������</returns>
    int maxDepth(AVLTreeNode<T>* node) {
        if (!node) {
            return 0; // ���� ���� ������, ������� 0
        }

        // ���������� �������� ������� ������ � ������� �����������
        int leftDepth = maxDepth(static_cast<AVLTreeNode<T>*>(node->n_left));
        int rightDepth = maxDepth(static_cast<AVLTreeNode<T>*>(node->n_right));

        // ���������� ������������ ������� + 1 ��� �������� ����
        return std::max(leftDepth, rightDepth) + 1;
    }

    /// <summary>
    /// ������� �������� � AVL-������
    /// </summary>
    /// <param name="node">��������� �� ����, � �������� ���������� �������</param>
    /// <param name="data">������, ������� ����� ��������</param>
    /// <returns>��������� �� ����� ������ ���������</returns>
    AVLTreeNode<T>* insert(AVLTreeNode<T>* node, const T& data) {
        if (!node) return new AVLTreeNode<T>(data); // ���� ���� ������, ������� �����

        // ��������� ������ � ����� ��� ������ ���������
        if (data < node->n_data) {
            node->n_left = insert(static_cast<AVLTreeNode<T>*>(node->n_left), data);
        }
        else if (data > node->n_data) {
            node->n_right = insert(static_cast<AVLTreeNode<T>*>(node->n_right), data);
        }
        else {
            return node; // ��������� �� �����������
        }

        updateHeight(node); // ��������� ������ ����
        int balance = getBalance(node); // �������� ����������� �������

        // ���������, ����� �� ��������� �������
        if (balance > 1 && data < static_cast<AVLTreeNode<T>*>(node->n_left)->n_data)
            return rightRotate(node); // ������ �������

        if (balance < -1 && data > static_cast<AVLTreeNode<T>*>(node->n_right)->n_data)
            return leftRotate(node); // ����� �������

        if (balance > 1 && data > static_cast<AVLTreeNode<T>*>(node->n_left)->n_data) {
            node->n_left = leftRotate(static_cast<AVLTreeNode<T>*>(node->n_left)); // ����� ������� �� ����� �������� ����
            return rightRotate(node); // ������ �������
        }

        if (balance < -1 && data < static_cast<AVLTreeNode<T>*>(node->n_right)->n_data) {
            node->n_right = rightRotate(static_cast<AVLTreeNode<T>*>(node->n_right)); // ������ ������� �� ������ �������� ����
            return leftRotate(node); // ����� �������
        }

        return node; // ���������� (��������) ��������� ����
    }


    /// <summary>
    /// ����� �������� � AVL-������
    /// </summary>
    /// <param name="node">��������� �� ����, � �������� ���������� �����</param>
    /// <param name="data">������, ������� ����� �����</param>
    /// <returns>True, ���� ������� ������, ����� False</returns>
    bool search(AVLTreeNode<T>* node, const T& data) {
        if (!node) return false; // ���� ���� ������, ������� �� ������
        if (data == node->n_data) return true; // ���� ������ ���������, ������� ������
        if (data < node->n_data) return search(static_cast<AVLTreeNode<T>*>(node->n_left), data); // ���� � ����� ���������
        return search(static_cast<AVLTreeNode<T>*>(node->n_right), data); // ���� � ������ ���������
    }

    /// <summary>
    /// ��������� ���� � ����������� ��������� � ���������
    /// </summary>
    /// <param name="node">��������� �� ����, � �������� ���������� �����</param>
    /// <returns>��������� �� ���� � ����������� ���������</returns>
    AVLTreeNode<T>* getMinNode(AVLTreeNode<T>* node) {
        while (node && node->n_left) {
            node = static_cast<AVLTreeNode<T>*>(node->n_left); // ���� ����� ����� ����
        }
        return node; // ���������� ���� � ����������� ���������
    }

    /// <summary>
    /// �������� �������� �� AVL-������
    /// </summary>
    /// <param name="node">��������� �� ����, � �������� ���������� ��������</param>
    /// <param name="data">������, ������� ����� �������</param>
    /// <returns>��������� �� ����� ������ ���������</returns>
    AVLTreeNode<T>* remove(AVLTreeNode<T>* node, const T& data) {
        if (!node) return node; // ���� ���� ������, �������

        // ������� ������� �� ������ ��� ������� ���������
        if (data < node->n_data) {
            node->n_left = remove(static_cast<AVLTreeNode<T>*>(node->n_left), data);
        }
        else if (data > node->n_data) {
            node->n_right = remove(static_cast<AVLTreeNode<T>*>(node->n_right), data);
        }
        else {
            // ���� � ����� ��� ������� �������� �����
            if (!node->n_left || !node->n_right) {
                AVLTreeNode<T>* temp = node->n_left ? static_cast<AVLTreeNode<T>*>(node->n_left) : static_cast<AVLTreeNode<T>*>(node->n_right);
                if (!temp) {
                    delete node; // ���� ���� - ����, ����������� ������
                    return nullptr; // ���������� nullptr
                }
                else {
                    *node = *temp; // �������� ������ �� ��������� ����
                    delete temp; // ����������� ������
                }
            }
            else {
                // ���� � ����� ��������� ������
                AVLTreeNode<T>* temp = getMinNode(static_cast<AVLTreeNode<T>*>(node->n_right)); // ������� ����������� ���� � ������ ���������
                node->n_data = temp->n_data; // �������� ������
                node->n_right = remove(static_cast<AVLTreeNode<T>*>(node->n_right), temp->n_data); // ������� ����������� ����
            }
        }

        updateHeight(node); // ��������� ������ ����
        int balance = getBalance(node); // �������� ����������� �������

        // ���������, ����� �� ��������� �������
        if (balance > 1 && getBalance(static_cast<AVLTreeNode<T>*>(node->n_left)) >= 0)
            return rightRotate(node); // ������ �������

        if (balance > 1 && getBalance(static_cast<AVLTreeNode<T>*>(node->n_left)) < 0) {
            node->n_left = leftRotate(static_cast<AVLTreeNode<T>*>(node->n_left)); // ����� ������� �� ����� �������� ����
            return rightRotate(node); // ������ �������
        }

        if (balance < -1 && getBalance(static_cast<AVLTreeNode<T>*>(node->n_right)) <= 0)
            return leftRotate(node); // ����� �������

        if (balance < -1 && getBalance(static_cast<AVLTreeNode<T>*>(node->n_right)) > 0) {
            node->n_right = rightRotate(static_cast<AVLTreeNode<T>*>(node->n_right)); // ������ ������� �� ������ �������� ����
            return leftRotate(node); // ����� �������
        }

        return node; // ���������� ��������� ����
    }



    /// <summary>
    /// �������� ��� AVL-������
    /// </summary>
    class AVLTreeIterator {
    private:
        std::stack<AVLTreeNode<T>*> nodeStack; // ���� ��� �������� �����

        /// <summary>
        /// ��������� ��� ����� ���� � ����
        /// </summary>
        /// <param name="node">��������� �� ����, � �������� ���������� ����������</param>
        void pushLeft(AVLTreeNode<T>* node) {
            while (node) {
                nodeStack.push(node); // ��������� ���� � ����
                node = static_cast<AVLTreeNode<T>*>(node->n_left); // ��������� � ������ ��������� ����
            }
        }

    public:
        /// <summary>
        /// ����������� ���������
        /// </summary>
        /// <param name="root">��������� �� ������ ������</param>
        AVLTreeIterator(AVLTreeNode<T>* root) {
            pushLeft(root); // ��������� ����
        }

        /// <summary>
        /// �������� ����������
        /// </summary>
        void operator++() {
            if (nodeStack.empty()) return; // ���� ���� ������, �������

            AVLTreeNode<T>* node = nodeStack.top(); // �������� ������� ���� �����
            nodeStack.pop(); // ������� ��� �� �����
            pushLeft(static_cast<AVLTreeNode<T>*>(node->n_right)); // ��������� ����� ���� ������� ���������
        }

        /// <summary>
        /// �������� ����������� ����������
        /// </summary>
        /// <param name="other">������ ��������</param>
        /// <returns>True, ���� ��������� �� �����</returns>
        bool operator!=(const AVLTreeIterator& other) const {
            return !nodeStack.empty() || !other.nodeStack.empty(); // ���������� ��������� ������
        }

        /// <summary>
        /// �������� �������������
        /// </summary>
        /// <returns>������ �������� ����</returns>
        T operator*() const {
            return nodeStack.top()->n_data; // ���������� ������ �������� ���� �����
        }

    };


public:
    // ����������� ��� ������������� ������� ������
    AVLTree() : root(nullptr) {};
    
    // ����� ��� ��������� ����� ������, ��������� �����
    AVLTreeNode<T>* getRoot() const {
        return root;
    }

    /// <summary>
    /// ������������� ����� ������ ������
    /// </summary>
    /// <param name="newRoot">��������� �� ����� ������</param>
    void setRoot(AVLTreeNode<T>* newRoot) {
        root = newRoot;  // ��������� ������ ������
    }

    /// <summary>
    /// ������ ������� ������ ���� y
    /// </summary>
    /// <param name="y">��������� �� ����, ������ �������� ����������� �������</param>
    /// <returns>����� ������ ��������� ����� ��������</returns>
    AVLTreeNode<T>* rightRotate(AVLTreeNode<T>* y) {
        AVLTreeNode<T>* x = static_cast<AVLTreeNode<T>*>(y->n_left); // ��������� ����� �������� ����
        AVLTreeNode<T>* T2 = static_cast<AVLTreeNode<T>*>(x->n_right); // ��������� ������ �������� ���� x
        x->n_right = y; // ������������ y ������
        y->n_left = T2; // ������������ ������� ��������� ���� x � y
        updateHeight(y); // ��������� ������ y
        updateHeight(x); // ��������� ������ x
        return x; // ���������� ����� ������
    }



    /// <summary>
    /// ����� ������� ������ ���� x
    /// </summary>
    /// <param name="x">��������� �� ����, ������ �������� ����������� �������</param>
    /// <returns>����� ������ ��������� ����� ��������</returns>
    AVLTreeNode<T>* leftRotate(AVLTreeNode<T>* x) {
        AVLTreeNode<T>* y = static_cast<AVLTreeNode<T>*>(x->n_right); // ��������� ������ �������� ����
        AVLTreeNode<T>* T2 = static_cast<AVLTreeNode<T>*>(y->n_left); // ��������� ����� �������� ���� y
        y->n_left = x; // ������������ x �����
        x->n_right = T2; // ������������ ������ ��������� ���� y � x
        updateHeight(x); // ��������� ������ x
        updateHeight(y); // ��������� ������ y
        return y; // ���������� ����� ������
    }


    // ����� ��� ��������� �������� ����� ������
    T getRootValue() const {
        if (root != nullptr) {
            return root->n_data; // ���������� �������� ��������� ����
        }
        throw std::runtime_error("������ ������"); // ����������, ���� ������ ������
    }

    int getHeight(AVLTreeNode<T>* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLTreeNode<T>* node) {
        return node ? getHeight(static_cast<AVLTreeNode<T>*>(node->n_left)) - getHeight(static_cast<AVLTreeNode<T>*>(node->n_right)) : 0;
    }

    /// <summary>
    /// ������� �������� � AVL-������
    /// </summary>
    /// <param name="data">������, ������� ����� ��������</param>
    void insert(const T& data) {
        root = insert(root, data); // ��������� ������ � ��������� ������
    }

    /// <summary>
    /// ����� �������� � AVL-������
    /// </summary>
    /// <param name="data">������, ������� ����� �����</param>
    /// <returns>True, ���� ������� ������, ����� False</returns>
    bool search(const T& data) {
        return search(root, data); // ���� ������� � ������
    }

    /// <summary>
    /// �������� �������� �� AVL-������
    /// </summary>
    /// <param name="data">������, ������� ����� �������</param>
    void remove(const T& data) {
        root = remove(root, data); // ������� ������ � ��������� ������
    }

    /// <summary>
    /// ����� ������ � ���������� ������� (pre-order)
    /// </summary>
    void preOrderTraversal() {
        preOrderTraversal(root); // ��������� ����� � �����
        std::cout << std::endl; // ��������� ������ ����� ���������� ������
    }

    /// <summary>
    /// ����� ������ � ������������ ������� (in-order)
    /// </summary>
    void inOrderTraversal() {
        inOrderTraversal(root); // ��������� ����� � �����
        std::cout << std::endl; // ��������� ������ ����� ���������� ������
    }

    /// <summary>
    /// ����� ������ � ����������� ������� (post-order)
    /// </summary>
    void postOrderTraversal() {
        postOrderTraversal(root); // ��������� ����� � �����
        std::cout << std::endl; // ��������� ������ ����� ���������� ������
    }

    /// <summary>
    /// ����� ������ � ������ (breadth-first)
    /// </summary>
    void breadthFirstTraversal() {
        breadthFirstTraversal(root); // ��������� ����� � �����
        std::cout << std::endl; // ��������� ������ ����� ���������� ������
    }

    /// <summary>
    /// ��������� ������������ ������� ������
    /// </summary>
    /// <returns>������������ ������� ������</returns>
    int getMaxDepth() {
        return maxDepth(root); // ���������� ������������ �������
    }
};



/// <summary>
/// ������� ��� ������������ ������ AVL-������
/// </summary>
void testAVLTree() {
    AVLTree<int> tree; // �������� ���������� AVL-������ ��� �������� ����� �����

    // ������� ��������� � �������� �� �������
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    assert(tree.search(10) == true);
    assert(tree.search(20) == true);
    assert(tree.search(5) == true);

    // �������� ��������� ������ ����� ������� (�����)
    std::cout << "�������� in-order ������ ����� �������: ";
    tree.inOrderTraversal(); // ���������: 5 10 20

    // �������� ������� ������
    assert(tree.getMaxDepth() == 2);

    // ������� �������������� ���������
    tree.insert(15);
    tree.insert(25);
    tree.insert(1);
    assert(tree.search(15) == true);
    assert(tree.search(25) == true);
    assert(tree.search(1) == true);

    // �������� ������� ����� ���������� ����� ���������
    assert(tree.getMaxDepth() == 3);

    // �������� ������ ����� �������������� �������
    std::cout << "�������� pre-order ������ ����� ����� �������: ";
    tree.preOrderTraversal();

    // �������� ������� � ������ ����� ������� ������ ��������
    tree.insert(30);
    assert(tree.getBalance(tree.getRoot()) == -1); // �������� ������� �����
    assert(tree.getHeight(tree.getRoot()) == 4);

    // �������� ������� ��������
    AVLTree<int> rightRotateTree;
    rightRotateTree.insert(30);
    rightRotateTree.insert(20);
    rightRotateTree.insert(10); // ������� ��������� ��� ������� ��������
    assert(rightRotateTree.getRootValue() == 20); // ����� ������� �������� ������ ������ ���� 20


    // �������� ������ ��������
    AVLTree<int> leftRotateTree;
    leftRotateTree.insert(10);
    leftRotateTree.insert(20);
    leftRotateTree.insert(30); // ������� ��������� ��� ������ ��������
    assert(leftRotateTree.getRootValue() == 20); // ����� ������ �������� ������ ������ ���� 20

    // �������� �������� ���������
    tree.remove(10);
    assert(tree.search(10) == false);
    assert(tree.getMaxDepth() == 3);

    tree.remove(1);
    assert(tree.search(1) == false);

    // �������� ���������� �������� ��������������� ��������
    tree.remove(30);
    assert(tree.search(30) == false);

    // �������� ���������� ��������� ����� ��������
    std::cout << "�������� in-order ������ ����� ��������: ";
    tree.inOrderTraversal();

    // �������������� ����� ��� �������� ������
    std::cout << "�������� �������� ������: ";
    tree.breadthFirstTraversal();
}

/// <summary>
/// ������������ ���������
/// </summary>
void testRotations() {
    AVLTree<int> tree;

    // ���� ������� ��������
    AVLTreeNode<int>* root = new AVLTreeNode<int>(30);
    root->n_left = new AVLTreeNode<int>(20);
    root->n_left->n_left = new AVLTreeNode<int>(10);

    root = tree.rightRotate(root);  // ��������� ������ ����� ��������
    tree.setRoot(root);  // ������������� ����� ������ � ������

    // ��������� ������������ ��������� ����� ������� ��������
    assert(tree.getRootValue() == 20);  // ����� ������ ������ ���� 20

    // ���� ������ ��������
    AVLTreeNode<int>* root2 = new AVLTreeNode<int>(40);
    root2->n_right = new AVLTreeNode<int>(50);
    root2->n_right->n_right = new AVLTreeNode<int>(60);

    root2 = tree.leftRotate(root2);  // ��������� ������ ����� ��������
    tree.setRoot(root2);  // ������������� ����� ������ � ������

    // ��������� ������������ ��������� ����� ������ ��������
    assert(tree.getRootValue() == 50);  // ����� ������ ������ ���� 20

    std::cout << "��� ����� ��������!" << std::endl;
}


