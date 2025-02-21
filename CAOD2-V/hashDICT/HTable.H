#pragma once
// Стич Назар Иванович ИВТ-22
#include <iostream>
#include <list>
#include <vector>
#include <cassert>
#include <string>

/// <summary>
/// Шаблонный класс HashTable реализует хэш-таблицу с использованием цепочек для разрешения коллизий.
/// </summary>
/// <typeparam name="T">Тип данных, который будет храниться в хэш-таблице.</typeparam>
template <typename T>
class HashTable {
private:

    /// <summary>
    /// Вектор списков для хранения элементов в хэш-таблице.
    /// Каждый элемент таблицы — это список для разрешения коллизий.
    /// </summary>
    std::vector<std::list<T>> table;

    /// <summary>
    /// Емкость хэш-таблицы — максимальное количество бакетов.
    /// </summary>
    size_t capacity;

    /// <summary>
    /// Хэш-функция для вычисления индекса бакета на основе ключа.
    /// </summary>
    /// <param name="key">Ключ для хэширования.</param>
    /// <returns>Индекс бакета в пределах таблицы.</returns>
    size_t hashFunction(const T& key) const {
        std::hash<T> hasher; // Используем стандартную хэш-функцию
        return hasher(key) % capacity; // Возвращаем индекс, ограниченный емкостью
    }






public:

    /// <summary>
    /// Конструктор, создающий хэш-таблицу с заданным размером.
    /// </summary>
    /// <param name="size">Размер хэш-таблицы (количество бакетов).</param>
    explicit HashTable(size_t size) : capacity(size) {
        table.resize(size); // Инициализация таблицы с пустыми списками
    }

    /// <summary>
    /// Вставляет элемент в хэш-таблицу, избегая дублирования.
    /// </summary>
    /// <param name="key">Ключ, который необходимо добавить.</param>
    void insert(const T& key) {
        size_t index = hashFunction(key); // Вычисляем индекс бакета
        for (const auto& existingKey : table[index]) { // Проверяем на наличие дубликатов
            if (existingKey == key)
                return; // Не добавляем, если ключ уже существует
        }
        table[index].push_back(key); // Добавляем ключ в соответствующий список
    }

    /// <summary>
    /// Проверяет, содержится ли элемент в хэш-таблице.
    /// </summary>
    /// <param name="key">Ключ для поиска.</param>
    /// <returns>true, если элемент найден; иначе false.</returns>
    bool find(const T& key) const {
        size_t index = hashFunction(key); // Вычисляем индекс бакета
        for (const auto& existingKey : table[index]) { // Ищем ключ в списке
            if (existingKey == key)
                return true; // Ключ найден
        }
        return false; // Ключ не найден
    }

    /// <summary>
    /// Удаляет элемент из хэш-таблицы.
    /// </summary>
    /// <param name="key">Ключ, который необходимо удалить.</param>
    void remove(const T& key) {
        size_t index = hashFunction(key); // Вычисляем индекс бакета
        table[index].remove(key); // Удаляем ключ из списка
    }

    /// <summary>
    /// Печатает содержимое хэш-таблицы по индексам бакетов.
    /// </summary>
    void print() const {
        for (size_t i = 0; i < capacity; ++i) { // Проходим по всем бакетам
            std::cout << "Индекс " << i << ": "; // Выводим индекс бакета
            for (const auto& key : table[i]) { // Перебираем элементы списка
                std::cout << key << " "; // Выводим элемент
            }
            std::cout << std::endl; // Завершаем строку
        }
    }

    /// <summary>
    /// Возвращает элемент по ключу, если он существует в хэш-таблице.
    /// </summary>
    /// <param name="key">Ключ для поиска.</param>
    /// <returns>Найденный элемент.</returns>
    /// <exception cref="std::runtime_error">Если элемент не найден, выбрасывается исключение.</exception>
    T get(const T& key) const {
        size_t index = hashFunction(key); // Вычисляем индекс бакета
        for (const auto& existingKey : table[index]) { // Перебираем список в бакете
            if (existingKey == key) {
                return existingKey; // Возвращаем найденный элемент
            }
        }
        throw std::runtime_error("Ключ не найден"); // Если элемент не найден, выбрасываем исключение
    }

    /// <summary>
    /// Проверяет, существует ли элемент в хэш-таблице.
    /// </summary>
    /// <param name="key">Ключ для поиска.</param>
    /// <returns>True, если элемент найден; иначе False.</returns>
    bool contains(const T& key) const {
        size_t index = hashFunction(key); // Вычисляем индекс бакета
        for (const auto& existingKey : table[index]) { // Перебираем список в бакете
            if (existingKey == key) {
                return true; // Элемент найден
            }
        }
        return false; // Элемент не найден
    }




    /// <summary>
    /// Класс Iterator предоставляет итератор для элементов хэш-таблицы.
    /// </summary>
    class Iterator {
    private:
        const std::vector<std::list<T>>& table; // Ссылка на хэш-таблицу
        size_t bucketIndex; // Текущий индекс бакета
        typename std::list<T>::const_iterator chainIterator; // Итератор списка

        /// <summary>
        /// Переходит к следующему непустому бакету.
        /// </summary>
        void moveToNextNonEmptyBucket() {
            while (bucketIndex < table.size() && chainIterator == table[bucketIndex].end()) { // Пока бакет пустой
                ++bucketIndex; // Переходим к следующему бакету
                if (bucketIndex < table.size()) // Проверяем, что не вышли за пределы
                    chainIterator = table[bucketIndex].begin(); // Инициализируем итератор списка
            }
        }

    public:
        /// <summary>
        /// Конструктор итератора.
        /// </summary>
        /// <param name="table">Ссылка на таблицу.</param>
        /// <param name="index">Начальный индекс бакета.</param>
        Iterator(const std::vector<std::list<T>>& table, size_t index)
            : table(table), bucketIndex(index),
            chainIterator(index < table.size() && !table[index].empty() ? table[index].begin() : typename std::list<T>::const_iterator()) {
            moveToNextNonEmptyBucket(); // Переходим к первому непустому бакету
        }

        /// <summary>
        /// Разыменовывает итератор для доступа к текущему элементу.
        /// </summary>
        /// <returns>Ссылка на текущий элемент.</returns>
        const T& operator*() const {
            return *chainIterator; // Возвращаем элемент из списка
        }

        /// <summary>
        /// Переход к следующему элементу таблицы.
        /// </summary>
        /// <returns>Ссылка на текущий итератор.</returns>
        Iterator& operator++() {
            ++chainIterator; // Переходим к следующему элементу списка
            moveToNextNonEmptyBucket(); // Если список окончен, переходим к следующему бакету
            return *this; // Возвращаем текущий итератор
        }

        /// <summary>
        /// Проверяет неравенство двух итераторов.
        /// </summary>
        /// <param name="other">Другой итератор.</param>
        /// <returns>true, если итераторы различаются; иначе false.</returns>
        bool operator!=(const Iterator& other) const {
            return bucketIndex != other.bucketIndex || // Проверяем индекс бакета
                (bucketIndex < table.size() && chainIterator != other.chainIterator); // Проверяем итератор списка
        }
    };

    /// <summary>
    /// Возвращает итератор на начало таблицы.
    /// </summary>
    /// <returns>Итератор на первый элемент.</returns>
    Iterator begin() const {
        return Iterator(table, 0); // Начинаем с первого бакета
    }

    /// <summary>
    /// Возвращает итератор, указывающий на конец таблицы.
    /// </summary>
    /// <returns>Итератор на позицию после последнего элемента.</returns>
    Iterator end() const {
        return Iterator(table, table.size()); // Индекс за последним бакетом
    }
};
