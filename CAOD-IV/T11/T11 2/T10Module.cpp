#include <iostream>
#include <stdexcept>
#include <cassert>
#include "T8Module.cpp"

using namespace std;

// Определение класса Stack
template<typename T>
class Stack {
private:
    DynamicArray<T> elements;   // Использование класса DynamicArray для хранения элементов стека
    int topIndex;               // Индекс вершины стека
    int capacity;               // Вместимость стека


    // Метод для изменения размера стека
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



    // Конструктор
    Stack() : elements(), topIndex(-1), capacity(10) {}

    // Деструктор
    ~Stack() {
        elements.resize(0); // Очистка элементов стека
    }

    // Проверка: стек пуст?
    bool isEmpty() const {
        return topIndex == -1;  // Возвращает true, если topIndex равен -1, иначе false
    }

    // Удаление верхнего элемента
    T pop() {
        if (isEmpty()) {
            throw out_of_range("Стек пуст");   // Выбрасывает исключение, если стек пуст
        }
        return elements[topIndex--];   // Возвращает верхний элемент и уменьшает topIndex
    }

    // Добавление элемента
    void push(const T& element) {
        if (topIndex == capacity - 1) {
            elements.increaseCapacity(); // Увеличиваем емкость, если массив заполнен
            ++topIndex; // Увеличиваем индекс верхнего элемента
        }
        else {
            ++topIndex; // Увеличиваем индекс верхнего элемента перед добавлением нового элемента
        }
        elements.push_back(element); // Добавляем элемент в конец DynamicArray
    }

    // Просмотр вершины
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Стек пуст");   // Выбрасывает исключение, если стек пуст
        }
        return elements[topIndex];  // Возвращает верхний элемент без его удаления
    }

    // Очистка стека
    void clear() {
        topIndex = -1;  // Устанавливает topIndex в -1, что эквивалентно удалению всех элементов
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
