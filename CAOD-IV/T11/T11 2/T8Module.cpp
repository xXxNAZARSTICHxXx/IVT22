#include <iostream>
#include <algorithm>
#include <ctime>
#include <time.h>
#include <cassert>
#include <cstddef> 

using namespace std;

template <typename T>
//Сам динамический массив
class DynamicArray {
private:
    T* data; // указатель на динамический массив
    size_t capacity; // текущая емкость массива
    size_t size; // текущий размер массива

public:

    void increaseCapacity() {
        // Увеличиваем емкость массива в два раза
        capacity *= 2;

        // Выделяем новый блок памяти
        T* newData = new T[capacity];

        // Копируем данные из старого массива в новый
        std::copy(data, data + size, newData);

        // Освобождаем старую память
        delete[] data;

        // Устанавливаем указатель на новый массив данных
        data = newData;
    }


    // Уменьшение емкости массива (выделяемая память)
    void decreaseCapacity() {
        // Проверяем, если заполненность массива упала ниже половины его текущей емкости
        if (size < capacity / 2) {
            // Вычисляем новую емкость как максимум между 2 и величиной, необходимой для хранения size элементов.
            // Это гарантирует, что новая емкость не будет меньше, чем size.
            size_t newCapacity = max(size, capacity / 2);
            // Создаем новый массив с новой емкостью
            T* newData = new T[newCapacity];
            // Копируем элементы из старого массива в новый
            copy(data, data + size, newData);
            // Удаляем старый массив
            delete[] data;
            // Обновляем указатель на данные и емкость
            data = newData;
            capacity = newCapacity;
        }
    }

    //Правило пяти
    //Деструктор
    //Конструктор копирования
    //Оператор присваивания
    //Конструктор перемещения
    //Оператор перемещения

    // Конструктор по умолчанию
    // Имеет data устанавливается в nullptr, что указывает на то, что память не выделен; 
    // capacity - выделяемая память (далее емкость); 
    // size размер массива ~ они 0, т.к пустые
    DynamicArray() : data(nullptr), capacity(0), size(0) {}

    // Конструктор с заданной начальной емкостью
    // initialCapacity - это количество элементов, на которое должен быть выделен массив data.
    // data выделяется с помощью оператора new, чтобы создать массив указанной начальной емкости.
    // capacity устанавливается равным initialCapacity.
    // size инициализируется нулем, потому что массив пока пустой, и ни один элемент не был добавлен.
    explicit DynamicArray(size_t initialCapacity) : data(new T[initialCapacity]), capacity(initialCapacity), size(0) {}

    // Деструктор //todo проверка на nullptr
    ~DynamicArray() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    // Добавление элемента в конец массива
    // element - вводимый элемент
    void push_back(const T& element) {
        if (size == capacity) {
            increaseCapacity();
        }
        data[size++] = element;
    }

    T* getData() const {
        return data;
    }

    // Удаление последнего элемента
    void pop_back() {
        if (size > 0) {
            size--;
            decreaseCapacity();
        }
    }

    // Просмотр элемента на определенной позиции
    // index - позиция элемента
    const T& at(size_t index) const {
        if (index >= size) {
            throw out_of_range("Индекс находится за пределами массива, для инфомацмм о массиве, введите 5");
        }
        return data[index];
    }


    // Доступ по индексу для чтения
    // index - позиция элемента
    const T& operator[](size_t index) const {
        if (index >= size) {
            throw out_of_range("Индекс находится за пределами массива, для инфомацмм о массиве, введите 5");
        }
        return data[index];
    }

    // Доступ по индексу для изменения
    // index - позиция элемента
    T& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Индекс находится за пределами массива, для инфомацмм о массиве, введите 5");
        }
        return data[index];
    }

    // Конструктор копирования
    // capacity: это емкость (или размер) выделенной памяти для хранения элементов массива, он инициализируется значением емкости массива other
    // size: это текущий размер массива, то есть количество элементов, которые фактически содержатся в массиве, он инициализируется значением размера массива other
    // data: это указатель на динамически выделенный массив элементов типа T, который будет хранить данные
    DynamicArray(const DynamicArray& other) : capacity(other.capacity), size(other.size), data(new T[other.capacity]) {
        copy(other.data, other.data + size, data);
    }

    // Оператор присваивания копирования
    // todo случай при nullptr
    // other - Ссылка на динамический массив
    DynamicArray& operator=(const DynamicArray& other) {
        if (other.data == nullptr) {
        }
        else if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new T[other.capacity];
            copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // Конструктор перемещения
    // other - Ссылка на динамический массив
    // other: это ссылка на объект DynamicArray, из которого мы хотим переместить ресурсы (данные, емкость и размер) в новый объект
    // data: это указатель на массив данных типа T. В конструкторе перемещения он инициализируется значением указателя other.data, то есть указывает на тот же массив данных, что и other
    // capacity: это емкость (или размер) выделенной памяти для хранения элементов массива. Он инициализируется значением емкости массива other
    // size: это текущий размер массива, то есть количество элементов, которые фактически содержатся в массиве. Он инициализируется значением размера массива other
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), capacity(other.capacity), size(other.size) {
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }

    // Оператор перемещения
    // todo все тот же nullptr
    // other - Ссылка на динамический массив
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (other.data == nullptr) {
        }
        else if (this != &other) {
            delete[] data;
            data = other.data;
            capacity = other.capacity;
            size = other.size;
            other.data = nullptr;
            other.capacity = 0;
            other.size = 0;
        }
        return *this;
    }

    // Получение текущего размера массива
    size_t getSize() const {
        return size;
    }

    // Получение текущей емкости массива
    size_t getCapacity() const {
        return capacity;
    }

    // Добавление элемента в массив по позиции
    // index - позиция элемента; element - значение элемента
    void insert(size_t index, const T& element) {
        if (index > size) {
            throw out_of_range("Индекс находится за пределами массива, для информации о массиве, введите 5");
        }

        if (size == capacity) {
            increaseCapacity(); 
        }

        for (size_t i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = element;
        size++;
    }

    // Удаление элемента из массива по позиции
    // index - позиция элемента
    void erase(size_t index) {
        if (index >= size) {
            throw out_of_range("Индекс находится за пределами массива, для инфомацмм о массиве, введите 5");
        }
        for (size_t i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        decreaseCapacity();
    }
    
    // Поиск элемента в массиве
    // element - значение элемента
    int contains(const T& element) const {
        auto it = find(data, data + size, element);
        if (it != data + size) {
            cout << "Элемент найден на позиции: " << (it - data) << endl;
            return it - data; 
        }
        else {
            cout << "Элемент не найден." << endl;
            return -1; 
        }
    }

    // Сортировка массива
    void sort_n() {
        sort(data, data + size);
    }

    // Метод для изменения размера массива
    // newSize - Новый размер 
    void resize(size_t newSize) {
        if (newSize == size) {
            return; // Нет необходимости изменять размер, если он не изменился
        }

        if (newSize < size) {         
            size = newSize; // Если новый размер меньше текущего размера, уменьшаем размер
        }
        else {
            if (newSize > capacity) { // Если новый размер больше текущего размера, увеличиваем размер и, если необходимо, выделяем дополнительную память
                reserve(newSize); // Выделение дополнительной памяти, если необходимо
            }
            for (size_t i = size; i < newSize; i++) { // Заполняем новые элементы значением по умолчанию
                data[i] = T(); // Значение по умолчанию для типа T
            }
            size = newSize; // Обновляем размер массива
        }
    }

    // Добавление n элементов в конец массива
    // element - значение элемента, n - кол-во элементов
    void push_back_n(const T& element, size_t n) {
        size_t newSize = size + n;
        resize(newSize); // Изменение размера массива до нового размера
        // Добавление элементов в конец массива
        for (size_t i = size - n; i < size; ++i) {
            data[i] = element;
        }
    }

    // Удаление n элементов с конца массива
    // n - кол-во элементов
    void pop_back_n(size_t n) {
        if (n >= size) {
            size = 0;
        }
        else {
            size -= n;
        }
        decreaseCapacity();
    }

    // Добавление n элементов в определенную позицию массива
    // index - позиция элемента, element - значение элемента, n - кол-во элементов
    void insert_n(size_t index, const T& element, size_t n) {
        if (index > size) {
            throw out_of_range("Индекс находится за пределами массива, для инфомацмм о массиве, введите 5");
        }
        if (size + n > capacity) {
            capacity = max(capacity * 2, size + n);
            T* newData = new T[capacity];
            copy(data, data + index, newData);
            fill_n(newData + index, n, element);
            copy(data + index, data + size, newData + index + n);
            delete[] data;
            data = newData;
        }
        else {
            copy_backward(data + index, data + size, data + size + n);
            fill_n(data + index, n, element);
        }
        size += n;
    }

    // Удаление n элементов начиная с указанной позиции массива
    // index - позиция элемента, n - кол-во элементов
    void erase_n(size_t index, size_t n) {
        if (index >= size) {
            throw out_of_range("Индекс находится за пределами массива, для инфомацмм о массиве, введите 5");
        }
        size_t newSize = size - n;

        if (index + n >= size) {
            size = index;
        }
        else {
            copy(data + index + n, data + size, data + index);
            size = newSize; 
        }
        decreaseCapacity();
    }

    // Вывод массива в консоль
    void print() const {
        cout << "Array: [";
        if (size > 0) {
            cout << data[0];
            for (size_t i = 1; i < size; i++) {
                cout << ", " << data[i];
            }
        }
        cout << "]" << endl;
    }

    // Заполнение массива случайными числами
    // min, max - минимальное максимальные соответственно значения диапазона масссива
    void fill_random(T min, T max) {
        srand(static_cast<unsigned int>(time(nullptr)));
        double range = static_cast<double>(max) - min;
        for (size_t i = 0; i < size; i++) {
            data[i] = min + static_cast<T>(rand() / (RAND_MAX + 1.0) * range);
        }
    }



    // Функция поиска числа в массиве по указанной позиции
    // n - размер массива; arr - массив;
    // pos - позиция, на которой нужно искать элемент; x - число, с которым сравнивается элемент массива
    // Если элемент найден, возвращается позиция, в противном случае возвращается -1
    long long seek_at_position(size_t n, const int* arr, size_t pos, int x) {
        if (pos >= n) {
            return -1; // Позиция находится за пределами массива
        }
        if (arr[pos] == x) {
            return pos; // Элемент найден на указанной позиции
        }
        return -1; // Элемент не найден на указанной позиции
    }

    // Метод конкатенации двух динамических массивов
    // other - Ссылка на динамический массив
    void concatenate(const DynamicArray& other) {
        if (other.size == 0) {
            return; // Если второй массив пуст, нет необходимости в конкатенации
        }
        reserve(size + other.size); // Выделение дополнительной памяти для увеличения емкости исходного массива
        copy(other.data, other.data + other.size, data + size); // Копирование элементов второго массива в конец первого массива
        size += other.size; // Обновление размера исходного массива
    }

    // Метод для выделения памяти для хранения заданного количества элементов
    void reserve(size_t newCapacity) {
        if (newCapacity <= capacity) {
            return; // Нет необходимости изменять емкость, если новая емкость меньше или равна текущей
        }

        T* newData = new T[newCapacity]; // Выделение новой памяти с новой емкостью

        // Копирование существующих элементов в новую память
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data; // Освобождение старой памяти
        data = newData; // Переназначение указателя на новую память
        capacity = newCapacity; // Обновление значения емкости
    }

};

//assert проверка для программиста
void assertCheck() {
    DynamicArray<int> testarr;
    testarr.push_back_n(3, 3);
    for (int i = 0; i < 2; i++) {
        assert(testarr[i] == 3);
    }

    assert(testarr.seek_at_position(3, testarr.getData(), 0, 3) == 0);
    assert(testarr.seek_at_position(3, testarr.getData(), 1, 3) == 1);
    assert(testarr.seek_at_position(3, testarr.getData(), 2, 3) == 2);

    testarr.pop_back_n(1);
    assert(testarr.getSize() == 2);

    assert(testarr.seek_at_position(3, testarr.getData(), 0, 3) == 0);
    assert(testarr.seek_at_position(3, testarr.getData(), 1, 3) == 1);

    testarr.insert_n(2,3,3);
    for (int i = 0; i < 5; i++) {
        assert(testarr[i] == 3);
    }

    assert(testarr.getSize() == 5);

    assert(testarr.seek_at_position(5, testarr.getData(), 0, 3) == 0);
    assert(testarr.seek_at_position(5, testarr.getData(), 1, 3) == 1);
    assert(testarr.seek_at_position(5, testarr.getData(), 2, 3) == 2);
    assert(testarr.seek_at_position(5, testarr.getData(), 3, 3) == 3);
    assert(testarr.seek_at_position(5, testarr.getData(), 4, 3) == 4);

    testarr.push_back_n(3, 3);
    for (int i = 0; i < 8; i++) {
        assert(testarr[i] == 3);
    }
    assert(testarr.getSize() == 8);
    testarr.erase_n(2, 2);
    assert(testarr.getSize() == 6);
    testarr.insert_n(1, 7, 12);
    //todo проверка тестами НА ВСЕ ЭЛЕМЕНТЫ КАЖДЫЙ РАЗ
    assert(testarr.getSize() == 18);

    assert(testarr.seek_at_position(18, testarr.getData(), 0, 3) == 0);
    assert(testarr.seek_at_position(18, testarr.getData(), 1, 7) == 1);
    assert(testarr.seek_at_position(18, testarr.getData(), 2, 7) == 2);
    assert(testarr.seek_at_position(18, testarr.getData(), 3, 7) == 3);
    assert(testarr.seek_at_position(18, testarr.getData(), 4, 7) == 4);
    assert(testarr.seek_at_position(18, testarr.getData(), 5, 7) == 5);
    assert(testarr.seek_at_position(18, testarr.getData(), 6, 7) == 6);
    assert(testarr.seek_at_position(18, testarr.getData(), 7, 7) == 7);
    assert(testarr.seek_at_position(18, testarr.getData(), 8, 7) == 8);
    assert(testarr.seek_at_position(18, testarr.getData(), 9, 7) == 9);
    assert(testarr.seek_at_position(18, testarr.getData(), 10, 7) == 10);
    assert(testarr.seek_at_position(18, testarr.getData(), 11, 7) == 11);
    assert(testarr.seek_at_position(18, testarr.getData(), 12, 7) == 12);
    assert(testarr.seek_at_position(18, testarr.getData(), 13, 3) == 13);
    assert(testarr.seek_at_position(18, testarr.getData(), 14, 3) == 14);
    assert(testarr.seek_at_position(18, testarr.getData(), 15, 3) == 15);
    assert(testarr.seek_at_position(18, testarr.getData(), 16, 3) == 16);
    assert(testarr.seek_at_position(18, testarr.getData(), 17, 3) == 17);

    //Правило пяти todo в assert

    // Проверка resize
    testarr.resize(6);
    assert(testarr.getSize() == 6);
    assert(testarr.getCapacity() >= 6);

    // Проверка конструктора копирования
    DynamicArray<int> testarr_copy(testarr);
    assert(testarr_copy.getSize() == testarr.getSize());
    for (size_t i = 0; i < testarr.getSize(); ++i) {
        assert(testarr_copy[i] == testarr[i]);
    }

    // Проверка оператора присваивания
    DynamicArray<int> testarr_assign;
    testarr_assign = testarr;
    assert(testarr_assign.getSize() == testarr.getSize());
    for (size_t i = 0; i < testarr.getSize(); ++i) {
        assert(testarr_assign[i] == testarr[i]);
    }

    // Проверка конструктора перемещения
    DynamicArray<int> testarr_move(std::move(testarr));
    assert(testarr_move.getSize() == 6); 
    assert(testarr.getSize() == 0); 

    // Проверка оператора перемещения
    DynamicArray<int> testarr_move_assign;
    testarr_move_assign = std::move(testarr_move);
    assert(testarr_move_assign.getSize() == 6); 
    assert(testarr_move.getSize() == 0); 

    // Проверка деструктора
    testarr.~DynamicArray();
    assert(testarr.getSize() == 0);
    assert(testarr.getCapacity() == 0);
    assert(testarr.getData() == nullptr);
}
