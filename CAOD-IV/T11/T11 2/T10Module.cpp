#include <iostream>
#include <stdexcept>
#include <cassert>
#include "T8Module.cpp"

using namespace std;

// ����������� ������ Stack
template<typename T>
class Stack {
private:
    DynamicArray<T> elements;   // ������������� ������ DynamicArray ��� �������� ��������� �����
    int topIndex;               // ������ ������� �����
    int capacity;               // ����������� �����


    // ����� ��� ��������� ������� �����
    void resize(int newCapacity) {
        T* newElements = new T[newCapacity];
        for (int i = 0; i <= topIndex; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }



public:



    // �����������
    Stack() : elements(), topIndex(-1), capacity(10) {}

    // ����������
    ~Stack() {
        elements.resize(0); // ������� ��������� �����
    }

    // ��������: ���� ����?
    bool isEmpty() const {
        return topIndex == -1;  // ���������� true, ���� topIndex ����� -1, ����� false
    }

    // �������� �������� ��������
    T pop() {
        if (isEmpty()) {
            throw out_of_range("���� ����");   // ����������� ����������, ���� ���� ����
        }
        return elements[topIndex--];   // ���������� ������� ������� � ��������� topIndex
    }

    // ���������� ��������
    void push(const T& element) {
        if (topIndex == capacity - 1) {
            elements.increaseCapacity(); // ����������� �������, ���� ������ ��������
            ++topIndex; // ����������� ������ �������� ��������
        }
        else {
            ++topIndex; // ����������� ������ �������� �������� ����� ����������� ������ ��������
        }
        elements.push_back(element); // ��������� ������� � ����� DynamicArray
    }

    // �������� �������
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("���� ����");   // ����������� ����������, ���� ���� ����
        }
        return elements[topIndex];  // ���������� ������� ������� ��� ��� ��������
    }

    // ������� �����
    void clear() {
        topIndex = -1;  // ������������� topIndex � -1, ��� ������������ �������� ���� ���������
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
