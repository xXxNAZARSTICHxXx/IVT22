#include <iostream>
#include <stack>
#include <stdexcept>
#include "T10Module.cpp"
#include <queue>

using namespace std;

//����� �������
template<typename T>
class QueueFromStack {
private:
    stack<T> inbox;   // ���� ��� ���������� ��������� (enqueue)
    stack<T> outbox;  // ���� ��� ���������� ��������� (dequeue)

public:
    // ���������� �������� � �������
    // const T& Xelement - �������
    void enqueue(const T& Xelement) {
        inbox.push(Xelement);  // ���������� �������� � ���� ��� ����������
    }

    // ���������� �������� �� �������
    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("������� ������");  // ���� ������� �����, ����������� ����������
        }
        // ���� ���� ��� ���������� ����, ��������� ��� �������� �� ����� ��� ����������
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        T frontItem = outbox.top();  // ��������� ������� ������� �� ����� ��� ����������
        outbox.pop();                // ������� ��� �� �����
        return frontItem;
    }

    // �������� �� �������
    bool isEmpty() const {
        return inbox.empty() && outbox.empty();
    }
    //todo size - peek ��� �������

    // ���������� ������� ������ �������
    size_t size() const {
        return inbox.size() + outbox.size();
    }

    // ���������� �������, ����������� � ������ �������, ��� ��� ����������
    T peek() {
        if (isEmpty()) {
            throw out_of_range("������� ������");
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
    //todo ��������� �� ������ �������...

    // �������� �� ������ �������
    try {
        queueT.dequeue();
        assert(false); 
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}


