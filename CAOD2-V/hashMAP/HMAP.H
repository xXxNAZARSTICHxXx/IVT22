#include <iostream>
#include <list>
#include <vector>
#include <cassert>
#include <string>
#include "HTable.H"

// Класс множества на основе хэш-таблицы
template <typename T>
class Set {
public:
    // Сделаем HashTable публичным для доступа в тестах
    class HashTable {
    public:
        // Внутренний контейнер для хранения данных
        std::vector<std::list<T>> hashTable;
        size_t size; // Размер таблицы

        // Конструктор
        HashTable(size_t tableSize) : size(tableSize) {
            hashTable.resize(tableSize);
        }

        // Хеш-функция для определения индекса
        size_t hashFunction(const T& key) const {
            return std::hash<T>()(key) % size;
        }

        // Метод добавления элемента
        void insert(const T& value) {
            size_t index = hashFunction(value);
            hashTable[index].push_back(value);
        }

        // Метод для поиска элемента
        bool find(const T& value) const {
            size_t index = hashFunction(value);
            const auto& bucket = hashTable[index];
            for (const auto& elem : bucket) {
                if (elem == value) {
                    return true;
                }
            }
            return false;
        }

        // Метод для удаления элемента
        void remove(const T& value) {
            size_t index = hashFunction(value);
            auto& bucket = hashTable[index];
            bucket.remove(value);
        }

        // Итератор для обхода элементов хеш-таблицы
        class Iterator {
        public:
            Iterator(HashTable& table, size_t bucketIndex, typename std::list<T>::iterator listIter)
                : table(table), bucketIndex(bucketIndex), listIterator(listIter) {}

            // Операция инкремента
            Iterator& operator++() {
                ++listIterator;
                // Если дошли до конца текущего списка, переходим к следующему бакету
                while (bucketIndex < table.hashTable.size() && listIterator == table.hashTable[bucketIndex].end()) {
                    ++bucketIndex;
                    if (bucketIndex < table.hashTable.size()) {
                        listIterator = table.hashTable[bucketIndex].begin();
                    }
                }
                return *this;
            }

            // Операция разыменования
            T& operator*() {
                return *listIterator;
            }

            // Операция неравенства
            bool operator!=(const Iterator& other) const {
                return bucketIndex != other.bucketIndex || listIterator != other.listIterator;
            }

        private:
            HashTable& table;
            size_t bucketIndex;
            typename std::list<T>::iterator listIterator;
        };


        /// <summary>
        /// Возвращает итератор на начало словаря.
        /// </summary>
        /// <returns>Итератор на первую пару ключ-значение.</returns>
        Iterator begin() const {
            return Iterator(hashTable.begin()); // Возвращаем итератор на начало хэш-таблицы
        }

        // Метод для получения итератора на конец
        Iterator end() {
            return Iterator(*this, hashTable.size(), {}); // Итератор за пределами последнего элемента
        }
    };

    HashTable hashTable;

public:
    // Конструктор множества
    Set(size_t size) : hashTable(size) {}

    // Вставка элемента
    void insert(const T& value) {
        hashTable.insert(value);
    }

    // Поиск элемента
    bool contains(const T& value) const {
        return hashTable.find(value);
    }

    // Удаление элемента
    void erase(const T& value) {
        hashTable.remove(value);
    }

    // Печать содержимого множества
    void print() const {
        for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
            std::cout << *it << " ";  // выводим значение
        }
        std::cout << std::endl;
    }
};

// Тестовая функция для проверки множества через assert
void testSet() {
    Set<int> mySet(10);

    // Вставляем элементы в множество
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(2); // Попытка вставить дубликат

    // Проверяем, что элементы присутствуют в множестве
    assert(mySet.contains(1)); // 1 должен быть в множестве
    assert(mySet.contains(2)); // 2 должен быть в множестве
    assert(mySet.contains(3)); // 3 должен быть в множестве

    // Проверяем, что отсутствует элемент 4
    assert(!mySet.contains(4)); // 4 не должен быть в множестве

    // Удаляем элемент 2
    mySet.erase(2);
    assert(!mySet.contains(2)); // 2 должен быть удалён

    // Тестирование коллизии

    // Вставляем два элемента с одинаковым хеш-значением
    // Для демонстрации, пусть hash(15) и hash(25) дадут одинаковый индекс
    mySet.insert(15);
    mySet.insert(25);

    // Проверяем, что оба элемента присутствуют в множестве, несмотря на коллизию
    assert(mySet.contains(15)); // 15 должен быть в множестве
    assert(mySet.contains(25)); // 25 должен быть в множестве

    // Удаляем один из элементов
    mySet.erase(15);
    assert(!mySet.contains(15)); // 15 должен быть удалён
    assert(mySet.contains(25)); // 25 должен остаться
}

// Тестовая функция для проверки множества через assert с использованием итератора
void testSetIterator() {
    Set<int> mySet(10);

    // Вставляем элементы в множество
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    // Проверяем через итератор, что элементы присутствуют в множестве
    auto it = mySet.hashTable.begin();

    // Ожидаем, что элементы будут 1, 2 и 3 в любом порядке
    bool found1 = false, found2 = false, found3 = false;
    while (it != mySet.hashTable.end()) {
        if (*it == 1) found1 = true;
        if (*it == 2) found2 = true;
        if (*it == 3) found3 = true;
        ++it;
    }

    // Проверяем, что все элементы найдены
    assert(found1); // 1 должен быть в множестве
    assert(found2); // 2 должен быть в множестве
    assert(found3); // 3 должен быть в множестве
}



