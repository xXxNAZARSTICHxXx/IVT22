#include <deque>
#include <stdexcept>
#include "T12Module.cpp"

template<typename T>
class QueueFromDeque {
private:
    deque<T> elements; 

public:
    // ���������� �������� � ����� �������
    void enqueue(const T& element) {
        elements.push_back(element);
    }

    // ���������� �������� �� ����� �������
    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("������� ������");
        }
        T backItem = elements.back();
        elements.pop_back();
        return backItem;
    }

    // �������� �� �������
    bool isEmpty() const {
        return elements.empty();
    }

    // ���������� ������� �� ������ ������� ��� ��� ����������
    T peek_fr() const {
        if (isEmpty()) {
            throw out_of_range("������� ������");
        }
        return elements.front();
    }

    // ���������� ������� �� ����� ������� ��� ��� ����������
    T peek_bk() const {
        if (isEmpty()) {
            throw std::out_of_range("������� ������");
        }
        return elements.back();
    }
};

void assertCheckE() {
    QueueFromDeque<int> queue;

    // �������� �� �������
    assert(queue.isEmpty());

    // ���������� ��������� � ���������� �� ����� �������
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    assert(queue.peek_bk() == 3); // �������� peek_bk
    assert(queue.dequeue() == 3);
    assert(queue.peek_bk() == 2); // �������� peek_bk ����� ���������� ������� ��������

    assert(queue.dequeue() == 2);
    assert(queue.dequeue() == 1);

    // �������� �� ������� ����� ���������� ���� ���������
    assert(queue.isEmpty());

    // ������� ������� �� ������ �������
    try {
        queue.dequeue();
        // ���� ������� ������� ������� �� ������ �������, ��� �������� �������
        assert(false);
    }
    catch (const out_of_range& e) {
        // ���� ��������� ���������� � ������ �������, �� ���� ������� �������
    }
}

