//���� ����� �������� ���-22 
#include <iostream>
#include <stdexcept>
#include <cassert>
#include "T9Module.cpp"

using namespace std;

template<typename T>
class Stack {
private:
    DoubleList<T> elements; // ������������� ������ DoubleList ��� �������� ��������� �����

public:
    // ����������� �� ���������
    Stack() : elements() {}

    // ����������
    ~Stack() = default;

    // ����������� �����������
    Stack(const Stack& other) : elements(other.elements) {}

    // �������� ������������
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            elements = other.elements;
        }
        return *this;
    }

    // ����������� �����������
    Stack(Stack&& other) noexcept : elements(std::move(other.elements)) {}

    // �������� �����������
    Stack& operator=(Stack&& other) noexcept {
        if (this != &other) {
            elements = std::move(other.elements);
        }
        return *this;
    }

    // ��������: ���� ����?
    bool isEmpty() const {
        return elements.empty();
    }

    // �������� �������� ��������
    T pop() {
        if (isEmpty()) {
            throw out_of_range("���� ����");
        }
        T topElement = elements.peek();
        elements.pop_back();
        return topElement;
    }

    // ���������� ��������
    void push(const T& element) {
        elements.push_back(element);
    }

    T peek() const {
        if (isEmpty()) {
            throw out_of_range("���� ����");
        }
        // �������� ������� ������� �����
        return elements.peek();
    }



    // ������� �����
    void clear() {
        elements.clear();
    }
};

void assertCheckA() {
    // �������� ������������ �� ���������, ������� push � pop
    Stack<int> stack;
    assert(stack.isEmpty());

    stack.push(5);
    stack.push(10);
    stack.push(15);

    assert(stack.peek() == 15);
    assert(stack.pop() == 15);
    assert(stack.pop() == 10);
    assert(stack.pop() == 5);
    assert(stack.isEmpty());

    // �������� ������������ �����������, ��������� ������������ � �����������
    Stack<int> stack2(stack);
    assert(stack2.peek() == 0); // ���� ������� ���� �������� ���������, ������� ������� ����� ����� 0
    stack2.push(100);
    assert(stack.peek() == 0); // ���������, ��� ������������ ���� �� ���������

    stack2 = stack; // ���� ��������� ������������
    assert(stack2.peek() == 0); // ���������, ��� ������� ������� ����� ����� ������������ ������� ����������

    stack.clear(); // ������� ������������� �����
    assert(stack2.peek() == 0); // ���������, ��� ������� ������� ����� ����� ������� ������� ����������

    // �������� ������������� ������������ � ��������� ������������
    Stack<int> stack3(move(stack2)); // ���������� ���� stack2 � stack3
    assert(stack3.peek() == 0); // ���������, ��� ������� ������� ����� �� ��������� ����� �����������

    stack3.push(200);
    assert(stack3.peek() == 200); // ���������, ��� ������� ������� ����� ��������� ����� ���������� ��������

    stack2 = std::move(stack3); // ���������� ���� stack3 ������� � stack2
    assert(stack2.peek() == 200); // ���������, ��� ������� ������� ����� ��������� ����� �����������
}
