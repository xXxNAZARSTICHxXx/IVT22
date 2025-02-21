//Стич Назар Иванович ИВТ-22 
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
    // Конструктор по умолчанию
    Stack() : elements() {}

    // Деструктор
    ~Stack() = default;

    // Конструктор копирования
    Stack(const Stack& other) : elements(other.elements) {}

    // Оператор присваивания
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            elements = other.elements;
        }
        return *this;
    }

    // Конструктор перемещения
    Stack(Stack&& other) noexcept : elements(std::move(other.elements)) {}

    // Оператор перемещения
    Stack& operator=(Stack&& other) noexcept {
        if (this != &other) {
            elements = std::move(other.elements);
        }
        return *this;
    }

    // Проверка: стек пуст?
    bool isEmpty() const {
        return elements.empty();
    }

    // Удаление верхнего элемента
    T pop() {
        if (isEmpty()) {
            throw out_of_range("Стек пуст");
        }
        T topElement = elements.peek();
        elements.pop_back();
        return topElement;
    }

    // Добавление элемента
    void push(const T& element) {
        elements.push_back(element);
    }

    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Стек пуст");
        }
        // Получаем верхний элемент стека
        return elements.peek();
    }



    // Очистка стека
    void clear() {
        elements.clear();
    }
};

void assertCheckA() {
    // Проверка конструктора по умолчанию, методов push и pop
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

    // Проверка конструктора копирования, оператора присваивания и деструктора
    Stack<int> stack2(stack);
    assert(stack2.peek() == 0); // Если правило пяти работает корректно, верхний элемент будет равен 0
    stack2.push(100);
    assert(stack.peek() == 0); // Проверяем, что оригинальный стек не изменился

    stack2 = stack; // Тест оператора присваивания
    assert(stack2.peek() == 0); // Проверяем, что верхний элемент стека после присваивания остался неизменным

    stack.clear(); // Очистка оригинального стека
    assert(stack2.peek() == 0); // Проверяем, что верхний элемент стека после очистки остался неизменным

    // Проверка перемещающего конструктора и оператора присваивания
    Stack<int> stack3(move(stack2)); // Перемещаем стек stack2 в stack3
    assert(stack3.peek() == 0); // Проверяем, что верхний элемент стека не изменился после перемещения

    stack3.push(200);
    assert(stack3.peek() == 200); // Проверяем, что верхний элемент стека изменился после добавления элемента

    stack2 = std::move(stack3); // Перемещаем стек stack3 обратно в stack2
    assert(stack2.peek() == 200); // Проверяем, что верхний элемент стека изменился после перемещения
}
