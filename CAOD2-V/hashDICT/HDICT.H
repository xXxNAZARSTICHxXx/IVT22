#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <cassert>
#include <utility> 
#include "HTable.H"

/// <summary>
/// Класс Dictionary реализует словарь на основе хэш-таблицы.
/// </summary>
/// <typeparam name="Key">Тип ключа.</typeparam>
/// <typeparam name="Value">Тип значения.</typeparam>
template <typename Key, typename Value>
class Dictionary {
private:
    /// Тип элемента, хранящегося в словаре — пара ключ-значение.
    using Pair = std::pair<Key, Value>;

    size_t hashFunction(const Key& key) const {
        return std::hash<Key>{}(key);
    }

    /// Внутренняя хэш-таблица для хранения пар ключ-значение.
    HashTable<Pair> hashTable;

public:
    /// <summary>
    /// Конструктор, создающий словарь с заданной емкостью.
    /// </summary>
    /// <param name="size">Размер словаря (количество бакетов).</param>
    explicit Dictionary(size_t size) : hashTable(size) {}

    /// <summary>
    /// Добавляет пару ключ-значение в словарь.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <param name="value">Значение.</param>
    void insert(const Key& key, const Value& value) {
        Pair newPair = std::make_pair(key, value); // Создаем пару ключ-значение
        hashTable.insert(newPair); // Вставляем в хэш-таблицу
    }

    /// <summary>
    /// Получает значение по ключу.
    /// </summary>
    /// <param name="key">Ключ для поиска.</param>
    /// <returns>Значение, связанное с ключом.</returns>
    Value get(const Key& key) const {
        for (const auto& pair : hashTable) { // Проходим по всем парам в таблице
            if (pair.first == key) // Если ключ найден
                return pair.second; // Возвращаем значение
        }
        throw std::runtime_error("Ключ не найден"); // Ключ не найден
    }

    /// <summary>
    /// Удаляет элемент по ключу.
    /// </summary>
    /// <param name="key">Ключ для удаления.</param>
    void remove(const Key& key) {
        for (const auto& pair : hashTable) { // Проходим по всем парам
            if (pair.first == key) { // Если ключ найден
                hashTable.remove(pair); // Удаляем пару
                return;
            }
        }
    }

    /// <summary>
    /// Проверяет, содержится ли ключ в словаре.
    /// </summary>
    /// <param name="key">Ключ для проверки.</param>
    /// <returns>true, если ключ найден; иначе false.</returns>
    bool contains(const Key& key) const {
        return hashTable.contains(std::make_pair(key, Value())); // Проверяем наличие пары с ключом
    }




    /// <summary>
    /// Печатает содержимое словаря.
    /// </summary>
    void print() const {
        for (const auto& pair : hashTable) { // Перебираем все пары
            std::cout << pair.first << ": " << pair.second << std::endl; // Выводим ключ и значение
        }
    }





    /// <summary>
    /// Ищет элемент по ключу и возвращает значение.
    /// </summary>
    /// <param name="key">Ключ для поиска.</param>
    /// <returns>Значение, связанное с ключом, если ключ найден.</returns>
    /// <exception cref="std::runtime_error">Если ключ не найден, выбрасывается исключение.</exception>
    Value find(const Key& key) const {
        size_t index = hashFunction(key); // Получаем индекс с помощью хэш-функции
        for (const auto& pair : hashTable) { // Проходим по всем элементам хэш-таблицы
            if (pair.first == key) {
                return pair.second; // Возвращаем значение, если ключ найден
            }
        }
        throw std::runtime_error("Ключ не найден"); // Ключ не найден
    }


    /// <summary>
    /// Класс Iterator предоставляет итератор для пар ключ-значение в словаре.
    /// </summary>
    class Iterator {
    private:
        typename HashTable<Pair>::Iterator it; // Итератор для хэш-таблицы

    public:
        /// <summary>
        /// Конструктор итератора.
        /// </summary>
        Iterator(typename HashTable<Pair>::Iterator iterator) : it(iterator) {}

        /// <summary>
        /// Разыменовывает итератор для доступа к текущей паре ключ-значение.
        /// </summary>
        /// <returns>Ссылка на текущую пару ключ-значение.</returns>
        const Pair& operator*() const {
            return *it; // Разыменовываем итератор хэш-таблицы
        }

        /// <summary>
        /// Переход к следующему элементу.
        /// </summary>
        /// <returns>Ссылка на текущий итератор.</returns>
        Iterator& operator++() {
            ++it; // Переходим к следующему элементу в хэш-таблице
            return *this;
        }

        /// <summary>
        /// Проверяет неравенство двух итераторов.
        /// </summary>
        bool operator!=(const Iterator& other) const {
            return it != other.it; // Сравниваем итераторы
        }
    };

    /// <summary>
    /// Возвращает итератор на начало словаря.
    /// </summary>
    /// <returns>Итератор на первую пару ключ-значение.</returns>
    Iterator begin() const {
        return Iterator(hashTable.begin()); // Возвращаем итератор на начало хэш-таблицы
    }

    /// <summary>
    /// Возвращает итератор, указывающий на конец словаря.
    /// </summary>
    /// <returns>Итератор на позицию после последнего элемента.</returns>
    Iterator end() const {
        return Iterator(hashTable.end()); // Возвращаем итератор на конец хэш-таблицы
    }
};

// Функция для проверки работы словаря с использованием assert
void testDictionary() {
    // Создаем словарь с ключами типа int и значениями типа std::string
    Dictionary<int, std::string> dict(10);

    // Добавляем элементы
    dict.insert(1, "one");
    dict.insert(2, "two");
    dict.insert(3, "three");

    // Проверяем наличие ключей и значения
    assert(dict.contains(1));
    assert(dict.contains(2));
    assert(dict.contains(3));
    assert(!dict.contains(4)); // Ключ 4 отсутствует

    // Проверяем значения по ключам
    assert(dict.get(1) == "one");
    assert(dict.get(2) == "two");
    assert(dict.get(3) == "three");

    // Удаляем ключ
    dict.remove(2);
    assert(!dict.contains(2)); // Убедимся, что ключ удален

    // Проверка коллизии
    // Для демонстрации коллизии вставим два элемента с одинаковым хэш-значением
    // В данном примере предполагаем, что хэш-функция будет давать одинаковый хэш для ключей 10 и 20
    dict.insert(10, "ten");  // Вставляем ключ 10
    dict.insert(20, "twenty"); // Вставляем ключ 20, который вызывает коллизию с ключом 10

    // Проверяем, что оба ключа содержатся в таблице
    assert(dict.contains(10));
    assert(dict.contains(20));
    assert(dict.get(10) == "ten");
    assert(dict.get(20) == "twenty");

    // Проверка исключений при обращении к несуществующему ключу
    try {
        dict.get(2); // Ожидается исключение
        assert(false); // Если до этого дошло, значит ошибка
    }
    catch (const std::runtime_error& e) {
        std::cout << "Исключение поймано: " << e.what() << std::endl;
    }

    try {
        std::string value = dict.find(1); // Пытаемся найти ключ 1
        std::cout << "Найдено значение для ключа 1: " << value << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    // Печать содержимого словаря 
    std::cout << "Содержимое словаря после тестов:" << std::endl;
    dict.print();
}


/// <summary>
/// Функция для тестирования итератора словаря с использованием assert.
/// </summary>
void testDictionary2() {
    // Создаем словарь с ключами типа int и значениями типа std::string
    Dictionary<int, std::string> dict(10);

    // Добавляем элементы
    dict.insert(1, "one");
    dict.insert(2, "two");
    dict.insert(3, "three");

    // Проверка итератора: перебор всех элементов
    int index = 1;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        // Разыменовываем итератор и проверяем ключ и значение
        if (index == 1) {
            assert((*it).first == 1 && (*it).second == "one");
        }
        else if (index == 2) {
            assert((*it).first == 2 && (*it).second == "two");
        }
        else if (index == 3) {
            assert((*it).first == 3 && (*it).second == "three");
        }
        ++index;
    }

    // Печать содержимого словаря (для отладки)
    std::cout << "Содержимое словаря после тестов итератора:" << std::endl;
    dict.print();
}
