#include <iostream>
#include <algorithm>
#include <ctime>
#include <time.h>
#include <cassert>

using namespace std;


//���� ������


//DoubleList - ����� ������
template <typename T>
class DoubleList {
private:
    struct Node {
        T data;      // ������, �������� � ����
        Node* prev;  // ��������� �� ���������� ����
        Node* next;  // ��������� �� ��������� ����

        // ����������� ����
        // newData - ������, �������� � ����
        // newPrev - ��������� �� ���������� ���� (�� ��������� nullptr)
        // newNext - ��������� �� ��������� ���� (�� ��������� nullptr)
        Node(const T& newData, Node* newPrev = nullptr, Node* newNext = nullptr)
            : data(newData), prev(newPrev), next(newNext) {}
    };

    Node* head;   // ��������� �� ������ ������� ������
    Node* tail;   // ��������� �� ��������� ������� ������
    size_t size;  // ������� ������ ������

    
public:




    //Todo ������� ����
    //����������
    //����������� �����������
    //�������� ������������
    //����������� �����������
    //�������� �����������


    // ����������� �� ���������
    // head(nullptr): �������������� ��������� head ��������� nullptr, ��� ��������� �� ��, ��� ������ ����
    // tail(nullptr) : �������������� ��������� tail ��������� nullptr, ����� �������� �� ������� ������
    // size(0) : ������������� ������ ������ � ����, ������ ��� ������ ���������������� ������
    DoubleList() : head(nullptr), tail(nullptr), size(0) {}

    // ����������� �����������
    // head(nullptr): �������������� ��������� head ��������� nullptr, ��� ��� ����� ������ ���������� ������
    // tail(nullptr) : �������������� ��������� tail ��������� nullptr, ���������� head
    // size(0) : ������������� ������ ������ ������ � ����, ��� ��� ��� ��� �� ���������
    DoubleList(const DoubleList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head; // ����������� ������ Node, � �� Node<T>
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;      // ��������� ��������� �� ������� ����
            head = head->next;      // ���������� ��������� head �� ��������� ����
            delete temp;            // ������� ������� ����
        }
        tail = nullptr;            // ������������� ��������� tail � nullptr
        size = 0;                   // ������������� ������ ������ � ����
    }

    // ����������
    ~DoubleList() {
        clear();
    }

    // �������� ������������
    DoubleList& operator=(const DoubleList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head; // ������� ��� ������ Node<T>
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // ����������� ������������ ������������
    DoubleList(DoubleList&& other) noexcept : head(other.head), tail(other.tail), size(other.size) {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    // �������� ������������� ������������
    DoubleList& operator=(DoubleList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            size = other.size;
            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }
        return *this;
    }




    // ������� ���������� �������� � ����� ������
    // const T& value - ���� �������� ������� ��������� �� ��������, ������� ����� �������� � ����� ������
    template<typename T>
    void push_back(const T& value) {
        if (!head) {
            head = tail = new Node(value);
        }
        else {
            tail->next = new Node(value, tail);
            tail = tail->next;
        }
        size++;
    }

    // ����� ��� ���������� �������� � ������ ������
    // const T& value - ��� ������ �� ��������, ������� ����� �������� � ������ ������
    template<typename T>
    void push_front(const T& value) {
        if (!head) {
            head = tail = new Node(value);
        }
        else {
            head->prev = new Node(value, nullptr, head);
            head = head->prev;
        }
        size++;
    }

    // ����� ��� ������� �������� � ��������� ������� ������
    // index - ������� ��� �������, value - �������� ��������
    template<typename T>
    void insert(size_t index, const T& value) {
        if (index > size) {
            throw out_of_range("������ ��������� �� �������� ������");
        }
        if (index == 0) {
            push_front(value);
        }
        else if (index == size) {
            push_back(value);
        }
        else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* newNode = new Node(value, current, current->next);
            current->next->prev = newNode;
            current->next = newNode;
            size++;
        }
    }

    // ����� ��� �������� �������� �� ������ ������
    void pop_front() {
        if (empty()) {
            throw out_of_range("������ ������");
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    // ����� ��� �������� �������� �� ����� ������
    void pop_back() {
        if (empty()) {
            throw out_of_range("������ ������");
        }
        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        size--;
    }

    // ����� ��� �������� �������� �� ��������� ������� ������
    // size_t index - ��� ������ ������� ��������, ������� ����� ������� �� ������
    void erase(size_t index) {
        if (index >= size) {
            throw out_of_range("������ ��������� �� �������� ������");
        }
        if (index == 0) {
            pop_front();
        }
        else if (index == size - 1) {
            pop_back();
        }
        else {
            Node* current = head;
            for (size_t i = 0; i < index; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            size--;
        }
    }

    // todo ����� ��������
    // ����� ��� ������ �������� � ������
    // const T& value - ��� �������� ��������, ������� ����� ����� � ������
    template<typename T>
    long long find(const T& value) const {
        Node* current = head;
        long long index = 0; // ����� �������� ��������
        while (current) {
            if (current->data == value) {
                return index; // ���������� ������� ��������
            }
            current = current->next;
            index++; // ����������� ����� ��������
        }
        return -1; // ������� �� ������
    }

    // ����� ��� ����������� (������������) ���� �������
    // const DoubleList& other - ��� ������ �� ������, ������� ����� ���������� � ������� �������
    template<typename T>
    void concatenate(const DoubleList& other) {
        if (other.empty()) {
            return;
        }
        if (empty()) {
            head = other.head;
            tail = other.tail;
        }
        else {
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
        }
        size += other.size;
    }

    // ����� ��� ������ ������ � ����������� ����� ������
    // ostream os - ��� ������ �� ����� ������, � ������� ����� ���������� �������� ������
    template<typename T>
    void print(ostream& os) const {
        Node* current = head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        os << endl;
    }

    // ����� ��� �������� ���� ��������� ������
    template<typename T>
    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    // ����� ��� ��������� ������� ������
    size_t getSize() const {
        return size;
    }

    // ����� ��� ��������, ���� �� ������
    bool empty() const {
        return size == 0;
    }

    // ����� ���������� �� ����������� ������ ���������
    // Big(O) - O(n)
    void insertionSort() {
        if (size <= 1) {
            return;
        }

        Node* sorted = nullptr;

        for (Node* current = head; current != nullptr; ) {
            Node* next = current->next;

            if (sorted == nullptr || current->data < sorted->data) {
                current->next = sorted;
                current->prev = nullptr;
                if (sorted) {
                    sorted->prev = current;
                }
                sorted = current;
            }
            else {
                Node* search = sorted;
                while (search->next != nullptr && search->next->data < current->data) {
                    search = search->next;
                }

                current->prev = search;
                current->next = search->next;
                if (search->next) {
                    search->next->prev = current;
                }
                search->next = current;
            }

            current = next;
        }

        head = sorted;

        tail = sorted;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
    }


    // ����� ����� ��������� ������ � ������������ ���������
    // start - ������ ������; end - ����� ������;
    T sum_subset(size_t start, size_t end) const {
        if (start >= size || end >= size || start > end) {
            throw out_of_range("������������ ��������� ��� �������� ������ ���������");
        }

        Node* current = head;
        size_t index = 0;
        T sum = T();

        while (current) {
            if (index >= start && index <= end) {
                sum += current->data;
            }
            current = current->next;
            index++;
        }

        return sum;
    }

    // ����� ��� �������� ���� ��������� � ������
    T sum_all() const {
        Node* current = head;
        T sum = T();

        while (current) {
            sum += current->data;
            current = current->next;
        }

        return sum;
    }

    // ����� ��� ������������ ������������ ��������� ������
    // indices - ������ � ������������ ������������� ������; count - ���������� ��������� � ������;
    T sum_specific(const int* indices, size_t count) const {
        T sum = T();

        for (size_t i = 0; i < count; i++) {
            int index = indices[i];
            if (index >= size) {
                throw out_of_range("������ ��������� �� ��������� ������");
            }

            Node* current = head;
            size_t j = 0;

            while (current) {
                if (j == index) {
                    sum += current->data;
                    break;
                }
                current = current->next;
                j++;
            }
        }

        return sum;
    }

    // ����� �������� ��������� ������ � ������������ ���������
    // start - ������ ������; end - ����� ������;
    T sub_subset(size_t start, size_t end) const {
        if (start >= size || end >= size || start > end) {
            throw out_of_range("������������ ��������� ��� �������� ������ ���������");
        }

        Node* current = head;
        size_t index = 0;
        T sum = T();

        while (current) {
            if (index >= start && index <= end) {
                sum -= current->data;
            }
            current = current->next;
            index++;
        }

        return sum;
    }

    // ����� ��� ��������� ���� ��������� � ������
    T sub_all() const {
        Node* current = head;
        T sum = T();

        while (current) {
            sum -= current->data;
            current = current->next;
        }

        return sum;
    }

    // ����� ��� ��������� ������������ ��������� ������
    // indices - ������ � ������������ ������������� ������; count - ���������� ��������� � ������;
    T sub_specific(const int* indices, size_t count) const {
        T sum = T();

        for (size_t i = 0; i < count; i++) {
            int index = indices[i];
            if (index >= size) {
                throw out_of_range("������ ��������� �� ��������� ������");
            }

            Node* current = head;
            size_t j = 0;

            while (current) {
                if (j == index) {
                    sum -= current->data;
                    break;
                }
                current = current->next;
                j++;
            }
        }

        return sum;
    }

    // ����� ������������ ������������� ��������� �������
    // start - ������ ������; end - ����� ������;
    T mul_subset(size_t start, size_t end) const {
        if (start >= size || end >= size || start > end) {
            throw out_of_range("������������ ��������� ��� ������������ ������ ���������");
        }

        Node* current = head;
        size_t index = 0;
        T product = T();

        while (current) {
            if (index >= start && index <= end) {
                product *= current->data;
            }
            current = current->next;
            index++;
        }

        return product;
    }


    // ����� ��� ������������ ���� ��������� � ������
    T num_all() const {
        T sum = T();
        Node* current = head;
        while (current) {
            sum += current->data;
            current = current->next;
        }
        return sum;
    }

    // ����� ��� ������������ ������������ ��������� ������
    // indices - ������ � ������������ ������������� ������; count - ���-�� ��������� � ������;
    T mul_specific(const int* indices, size_t count) const {
        T product = T();

        for (size_t i = 0; i < count; i++) {
            int index = indices[i];
            if (index >= size) {
                throw out_of_range("������ ��������� �� ��������� ������");
            }

            // ������� ��������� ��������� ��� ������ Node
            Node* current = head;

            size_t j = 0;

            while (current) {
                if (j == index) {
                    product *= current->data;
                    break;
                }
                current = current->next;
                j++;
            }
        }

        return product;
    }

};

void assertCheck() {
    // ����� ��� ������������ �� ���������
    DoubleList<int> list1;
    assert(list1.getSize() == 0);
    assert(list1.empty());

    // ����� ��� ������ push_back
    list1.push_back(10);
    list1.push_back(20);
    assert(list1.getSize() == 2);

    // ����� ��� ������ push_front
    list1.push_front(5);
    assert(list1.getSize() == 3);
    assert(list1.find(5) == 0); 

    // ����� ��� ������ pop_back
    list1. pop_back();
    assert(list1.getSize() == 2);

    // ����� ��� ������ pop_front
    list1.pop_front();
    assert(list1.getSize() == 1);
    assert(list1.empty() == false);

    // ����� ��� ������ insert
    list1.insert(0, 15);
    assert(list1.getSize() == 2);
    assert(list1.find(15) == 0); 

    // ����� ��� ������ erase
    list1.erase(0);
    assert(list1.getSize() == 1);
    assert(list1.empty() == false);

    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);
    list1.push_back(40);

    // ���� ��� ������������ �����������
    DoubleList<int> list2(list1);

    assert(list2.getSize() == list1.getSize());
    
    // ���� ��� ��������� ������������
    DoubleList<int> list3;
    list3 = list1;
    assert(list3.getSize() == list1.getSize());

    // ���� ��� ������������ �����������
    DoubleList<int> list4(move(list1));
    assert(list4.getSize() == 5);
    assert(list1.empty());

    list1.clear();
    assert(list1.empty());

    // ���� ��� ��������� �����������
    DoubleList<int> list5;
    list5 = move(list2);
    assert(list5.getSize() == 5);
    assert(list2.empty());

    try {
        list2.erase(0);
        assert(false);
    }
    catch (const out_of_range& e) {
        cout << e.what();
    }
}
