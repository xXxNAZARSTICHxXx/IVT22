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


    // �����������
    Stack() : elements() {}

    // ����������
    ~Stack() {
        elements.clear(); // ������� ��������� �����
    }

    // ��������: ���� ����?
    bool isEmpty() const {
        return elements.empty(); // ���������� true, ���� ������ ����, ����� false
    }

    // �������� �������� ��������
    T pop() {
        if (isEmpty()) {
            throw out_of_range("���� ����"); // ����������� ����������, ���� ���� ����
        }
        T topElement = elements.back(); // �������� ������� �������
        elements.pop_back(); // ������� ������� ������� �� ������
        return topElement; // ���������� ������� �������
    }

    // ���������� ��������
    void push(const T& element) {
        elements.push_back(element); // ��������� ������� � ����� ������
    }

    // �������� �������
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("���� ����"); // ����������� ����������, ���� ���� ����
        }
        return elements.back(); // ���������� ������� ������� ��� ��� ��������
    }

    // ������� �����
    void clear() {
        elements.clear(); // ������� ������, ������ ��� ��������
    }
};

void assertCheckA() {
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

    stack.push(20);
    stack.push(25);
    stack.clear();
    assert(stack.isEmpty());
}
