#include <iostream>
#include <stdexcept>
#include <cassert>
#include "T9Module.cpp"

using namespace std;

template<typename T>
class Stack {
private:
    DoubleList<T> elements; // Использование класса DoubleList для хранения элементов стека

public:


    // Конструктор
    Stack() : elements() {}

    // Деструктор
    ~Stack() {
        elements.clear(); // Очистка элементов стека
    }

    // Проверка: стек пуст?
    bool isEmpty() const {
        return elements.empty(); // Возвращает true, если список пуст, иначе false
    }

    // Удаление верхнего элемента
    T pop() {
        if (isEmpty()) {
            throw out_of_range("Стек пуст"); // Выбрасывает исключение, если стек пуст
        }
        T topElement = elements.back(); // Получаем верхний элемент
        elements.pop_back(); // Удаляем верхний элемент из списка
        return topElement; // Возвращаем верхний элемент
    }

    // Добавление элемента
    void push(const T& element) {
        elements.push_back(element); // Добавляем элемент в конец списка
    }

    // Просмотр вершины
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Стек пуст"); // Выбрасывает исключение, если стек пуст
        }
        return elements.back(); // Возвращает верхний элемент без его удаления
    }

    // Очистка стека
    void clear() {
        elements.clear(); // Очищает список, удаляя все элементы
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
