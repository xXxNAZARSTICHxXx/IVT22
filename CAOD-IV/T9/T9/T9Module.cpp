#include <iostream>
#include <algorithm>
#include <ctime>
#include <time.h>
#include <cassert>

using namespace std;


//узел списка


//DoubleList - класс списка
template <typename T>
class DoubleList {
private:
    struct Node {
        T data;      // Данные, хранимые в узле
        Node* prev;  // Указатель на предыдущий узел
        Node* next;  // Указатель на следующий узел

        // Конструктор узла
        // newData - данные, хранимые в узле
        // newPrev - указатель на предыдущий узел (по умолчанию nullptr)
        // newNext - указатель на следующий узел (по умолчанию nullptr)
        Node(const T& newData, Node* newPrev = nullptr, Node* newNext = nullptr)
            : data(newData), prev(newPrev), next(newNext) {}
    };

    Node* head;   // Указатель на первый элемент списка
    Node* tail;   // Указатель на последний элемент списка
    size_t size;  // Текущий размер списка

    
public:




    //Todo Правило пяти
    //Деструктор
    //Конструктор копирования
    //Оператор присваивания
    //Конструктор перемещения
    //Оператор перемещения


    // Конструктор по умолчанию
    // head(nullptr): Инициализирует указатель head значением nullptr, что указывает на то, что список пуст
    // tail(nullptr) : Инициализирует указатель tail значением nullptr, также указывая на пустоту списка
    // size(0) : Устанавливает размер списка в ноль, потому что список инициализируется пустым
    DoubleList() : head(nullptr), tail(nullptr), size(0) {}

    // Конструктор копирования
    // head(nullptr): Инициализирует указатель head значением nullptr, так как новый список начинается пустым
    // tail(nullptr) : Инициализирует указатель tail значением nullptr, аналогично head
    // size(0) : Устанавливает размер нового списка в ноль, так как его еще не заполнили
    DoubleList(const DoubleList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head; // Используйте просто Node, а не Node<T>
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;      // Сохраняем указатель на текущий узел
            head = head->next;      // Перемещаем указатель head на следующий узел
            delete temp;            // Удаляем текущий узел
        }
        tail = nullptr;            // Устанавливаем указатель tail в nullptr
        size = 0;                   // Устанавливаем размер списка в ноль
    }

    // Деструктор
    ~DoubleList() {
        clear();
    }

    // Оператор присваивания
    DoubleList& operator=(const DoubleList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head; // Укажите тип данных Node<T>
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // Конструктор присваивания перемещением
    DoubleList(DoubleList&& other) noexcept : head(other.head), tail(other.tail), size(other.size) {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    // Оператор пприсваивания перемещением
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




    // Функция добавления элемента в конец списка
    // const T& value - этот аргумент функции указывает на значение, которое нужно добавить в конец списка
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

    // Метод для добавления элемента в начало списка
    // const T& value - это ссылка на значение, которое нужно добавить в начало списка
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

    // Метод для вставки элемента в указанную позицию списка
    // index - позиция для вставки, value - значение элемента
    template<typename T>
    void insert(size_t index, const T& value) {
        if (index > size) {
            throw out_of_range("Индекс находится за границей списка");
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

    // Метод для удаления элемента из начала списка
    void pop_front() {
        if (empty()) {
            throw out_of_range("Список пустой");
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

    // Метод для удаления элемента из конца списка
    void pop_back() {
        if (empty()) {
            throw out_of_range("Список пустой");
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

    // Метод для удаления элемента из указанной позиции списка
    // size_t index - это индекс позиции элемента, который нужно удалить из списка
    void erase(size_t index) {
        if (index >= size) {
            throw out_of_range("Индекс находится за границей списка");
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

    // todo номер элемента
    // Метод для поиска элемента в списке
    // const T& value - это значение элемента, которое нужно найти в списке
    template<typename T>
    long long find(const T& value) const {
        Node* current = head;
        long long index = 0; // Номер текущего элемента
        while (current) {
            if (current->data == value) {
                return index; // Возвращаем позицию элемента
            }
            current = current->next;
            index++; // Увеличиваем номер элемента
        }
        return -1; // Элемент не найден
    }

    // Метод для объединения (конкатенации) двух списков
    // const DoubleList& other - это ссылка на список, который нужно объединить с текущим списком
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

    // Метод для вывода списка в стандартный поток вывода
    // ostream os - это ссылка на поток вывода, в который нужно напечатать элементы списка
    template<typename T>
    void print(ostream& os) const {
        Node* current = head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        os << endl;
    }

    // Метод для удаления всех элементов списка
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

    // Метод для получения размера списка
    size_t getSize() const {
        return size;
    }

    // Метод для проверки, пуст ли список
    bool empty() const {
        return size == 0;
    }

    // Метод сортировки по возрастанию списка вставками
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


    // Метод суммы элементов списка в определенном интервале
    // start - начало списка; end - конец списка;
    T sum_subset(size_t start, size_t end) const {
        if (start >= size || end >= size || start > end) {
            throw out_of_range("Неправильные параметры для сложения набора элементов");
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

    // Метод для сложения всех элементов в списке
    T sum_all() const {
        Node* current = head;
        T sum = T();

        while (current) {
            sum += current->data;
            current = current->next;
        }

        return sum;
    }

    // Метод для суммирования определенных элементов списка
    // indices - массив с позиционными обозначениями списка; count - количество элементов в списке;
    T sum_specific(const int* indices, size_t count) const {
        T sum = T();

        for (size_t i = 0; i < count; i++) {
            int index = indices[i];
            if (index >= size) {
                throw out_of_range("Индекс находится за пределами списка");
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

    // Метод разности элементов списка в определенном интервале
    // start - начало списка; end - конец списка;
    T sub_subset(size_t start, size_t end) const {
        if (start >= size || end >= size || start > end) {
            throw out_of_range("Неправильные параметры для сложения набора элементов");
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

    // Метод для вычитания всех элементов в списке
    T sub_all() const {
        Node* current = head;
        T sum = T();

        while (current) {
            sum -= current->data;
            current = current->next;
        }

        return sum;
    }

    // Метод для вычитания определенных элементов списка
    // indices - массив с позиционными обозначениями списка; count - количество элементов в списке;
    T sub_specific(const int* indices, size_t count) const {
        T sum = T();

        for (size_t i = 0; i < count; i++) {
            int index = indices[i];
            if (index >= size) {
                throw out_of_range("Индекс находится за пределами списка");
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

    // Метод перемножения определенного диапазона массива
    // start - начало списка; end - конец списка;
    T mul_subset(size_t start, size_t end) const {
        if (start >= size || end >= size || start > end) {
            throw out_of_range("Неправильные параметры для перемножения набора элементов");
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


    // Метод для суммирования всех элементов в списке
    T num_all() const {
        T sum = T();
        Node* current = head;
        while (current) {
            sum += current->data;
            current = current->next;
        }
        return sum;
    }

    // Метод для перемножения определенных элементов списка
    // indices - массив с позиционными обозначениями списка; count - кол-во элементов в спмске;
    T mul_specific(const int* indices, size_t count) const {
        T product = T();

        for (size_t i = 0; i < count; i++) {
            int index = indices[i];
            if (index >= size) {
                throw out_of_range("Индекс находится за пределами списка");
            }

            // Укажите шаблонные аргументы для класса Node
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
    // Тесты для конструктора по умолчанию
    DoubleList<int> list1;
    assert(list1.getSize() == 0);
    assert(list1.empty());

    // Тесты для метода push_back
    list1.push_back(10);
    list1.push_back(20);
    assert(list1.getSize() == 2);

    // Тесты для метода push_front
    list1.push_front(5);
    assert(list1.getSize() == 3);
    assert(list1.find(5) == 0); 

    // Тесты для метода pop_back
    list1. pop_back();
    assert(list1.getSize() == 2);

    // Тесты для метода pop_front
    list1.pop_front();
    assert(list1.getSize() == 1);
    assert(list1.empty() == false);

    // Тесты для метода insert
    list1.insert(0, 15);
    assert(list1.getSize() == 2);
    assert(list1.find(15) == 0); 

    // Тесты для метода erase
    list1.erase(0);
    assert(list1.getSize() == 1);
    assert(list1.empty() == false);

    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);
    list1.push_back(40);

    // Тест для конструктора копирования
    DoubleList<int> list2(list1);

    assert(list2.getSize() == list1.getSize());
    
    // Тест для оператора присваивания
    DoubleList<int> list3;
    list3 = list1;
    assert(list3.getSize() == list1.getSize());

    // Тест для конструктора перемещения
    DoubleList<int> list4(move(list1));
    assert(list4.getSize() == 5);
    assert(list1.empty());

    list1.clear();
    assert(list1.empty());

    // Тест для оператора перемещения
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
