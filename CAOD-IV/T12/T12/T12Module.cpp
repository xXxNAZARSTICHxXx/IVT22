#include <iostream>
#include <stack>
#include <stdexcept>
#include "T10Module.cpp"
#include <queue>

using namespace std;

//Класс Очереди
template<typename T>
class QueueFromStack {
private:
    stack<T> inbox;   // Стек для добавления элементов (enqueue)
    stack<T> outbox;  // Стек для извлечения элементов (dequeue)

public:
    // Добавление элемента в очередь
    // const T& Xelement - элемент
    void enqueue(const T& Xelement) {
        inbox.push(Xelement);  // Добавление элемента в стек для добавления
    }

    // Извлечение элемента из очереди
    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("очередь пустая");  // Если очередь пуста, выбрасываем исключение
        }
        // Если стек для извлечения пуст, переносим все элементы из стека для добавления
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        T frontItem = outbox.top();  // Извлекаем верхний элемент из стека для извлечения
        outbox.pop();                // Удаляем его из стека
        return frontItem;
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return inbox.empty() && outbox.empty();
    }
    //todo size - peek для очереди

    // Возвращает текущий размер очереди
    size_t size() const {
        return inbox.size() + outbox.size();
    }

    // Возвращает элемент, находящийся в начале очереди, без его извлечения
    T peek() {
        if (isEmpty()) {
            throw out_of_range("очередь пустая");
        }
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        return outbox.top();
    }


};

void assertCheckC() {
    QueueFromStack<int> queueT;
    queueT.enqueue(1);
    queueT.enqueue(2);
    assert(queueT.peek() == 1);
    queueT.enqueue(3);
    assert(queueT.size() == 3); 
    assert(queueT.dequeue() == 1);
    assert(queueT.dequeue() == 2);
    assert(queueT.dequeue() == 3);
    assert(queueT.isEmpty() == true);
    //todo проверить из пустой очереди...

    // Проверка на пустую очередь
    try {
        queueT.dequeue();
        assert(false); 
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}


