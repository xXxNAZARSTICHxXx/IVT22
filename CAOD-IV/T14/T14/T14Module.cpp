#include <deque>
#include <stdexcept>
#include "T12Module.cpp"

template<typename T>
class QueueFromDeque {
private:
    deque<T> elements; 

public:
    // Добавление элемента в конец очереди
    void enqueue(const T& element) {
        elements.push_back(element);
    }

    // Извлечение элемента из конца очереди
    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("очередь пустая");
        }
        T backItem = elements.back();
        elements.pop_back();
        return backItem;
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return elements.empty();
    }

    // Возвращает элемент из начала очереди без его извлечения
    T peek_fr() const {
        if (isEmpty()) {
            throw out_of_range("очередь пустая");
        }
        return elements.front();
    }

    // Возвращает элемент из конца очереди без его извлечения
    T peek_bk() const {
        if (isEmpty()) {
            throw std::out_of_range("очередь пустая");
        }
        return elements.back();
    }
};

void assertCheckE() {
    QueueFromDeque<int> queue;

    // Проверка на пустоту
    assert(queue.isEmpty());

    // Добавление элементов и извлечение из конца очереди
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    assert(queue.peek_bk() == 3); // Проверка peek_bk
    assert(queue.dequeue() == 3);
    assert(queue.peek_bk() == 2); // Проверка peek_bk после извлечения первого элемента

    assert(queue.dequeue() == 2);
    assert(queue.dequeue() == 1);

    // Проверка на пустоту после извлечения всех элементов
    assert(queue.isEmpty());

    // Попытка извлечь из пустой очереди
    try {
        queue.dequeue();
        // Если удалось извлечь элемент из пустой очереди, что является ошибкой
        assert(false);
    }
    catch (const out_of_range& e) {
        // Если выброшено исключение о пустой очереди, то тест пройден успешно
    }
}

