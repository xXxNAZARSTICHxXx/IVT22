#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <cassert>
#include <utility> 
#include "HTable.H"

/// <summary>
/// ����� Dictionary ��������� ������� �� ������ ���-�������.
/// </summary>
/// <typeparam name="Key">��� �����.</typeparam>
/// <typeparam name="Value">��� ��������.</typeparam>
template <typename Key, typename Value>
class Dictionary {
private:
    /// ��� ��������, ����������� � ������� � ���� ����-��������.
    using Pair = std::pair<Key, Value>;

    size_t hashFunction(const Key& key) const {
        return std::hash<Key>{}(key);
    }

    /// ���������� ���-������� ��� �������� ��� ����-��������.
    HashTable<Pair> hashTable;

public:
    /// <summary>
    /// �����������, ��������� ������� � �������� ��������.
    /// </summary>
    /// <param name="size">������ ������� (���������� �������).</param>
    explicit Dictionary(size_t size) : hashTable(size) {}

    /// <summary>
    /// ��������� ���� ����-�������� � �������.
    /// </summary>
    /// <param name="key">����.</param>
    /// <param name="value">��������.</param>
    void insert(const Key& key, const Value& value) {
        Pair newPair = std::make_pair(key, value); // ������� ���� ����-��������
        hashTable.insert(newPair); // ��������� � ���-�������
    }

    /// <summary>
    /// �������� �������� �� �����.
    /// </summary>
    /// <param name="key">���� ��� ������.</param>
    /// <returns>��������, ��������� � ������.</returns>
    Value get(const Key& key) const {
        for (const auto& pair : hashTable) { // �������� �� ���� ����� � �������
            if (pair.first == key) // ���� ���� ������
                return pair.second; // ���������� ��������
        }
        throw std::runtime_error("���� �� ������"); // ���� �� ������
    }

    /// <summary>
    /// ������� ������� �� �����.
    /// </summary>
    /// <param name="key">���� ��� ��������.</param>
    void remove(const Key& key) {
        for (const auto& pair : hashTable) { // �������� �� ���� �����
            if (pair.first == key) { // ���� ���� ������
                hashTable.remove(pair); // ������� ����
                return;
            }
        }
    }

    /// <summary>
    /// ���������, ���������� �� ���� � �������.
    /// </summary>
    /// <param name="key">���� ��� ��������.</param>
    /// <returns>true, ���� ���� ������; ����� false.</returns>
    bool contains(const Key& key) const {
        return hashTable.contains(std::make_pair(key, Value())); // ��������� ������� ���� � ������
    }




    /// <summary>
    /// �������� ���������� �������.
    /// </summary>
    void print() const {
        for (const auto& pair : hashTable) { // ���������� ��� ����
            std::cout << pair.first << ": " << pair.second << std::endl; // ������� ���� � ��������
        }
    }





    /// <summary>
    /// ���� ������� �� ����� � ���������� ��������.
    /// </summary>
    /// <param name="key">���� ��� ������.</param>
    /// <returns>��������, ��������� � ������, ���� ���� ������.</returns>
    /// <exception cref="std::runtime_error">���� ���� �� ������, ������������� ����������.</exception>
    Value find(const Key& key) const {
        size_t index = hashFunction(key); // �������� ������ � ������� ���-�������
        for (const auto& pair : hashTable) { // �������� �� ���� ��������� ���-�������
            if (pair.first == key) {
                return pair.second; // ���������� ��������, ���� ���� ������
            }
        }
        throw std::runtime_error("���� �� ������"); // ���� �� ������
    }


    /// <summary>
    /// ����� Iterator ������������� �������� ��� ��� ����-�������� � �������.
    /// </summary>
    class Iterator {
    private:
        typename HashTable<Pair>::Iterator it; // �������� ��� ���-�������

    public:
        /// <summary>
        /// ����������� ���������.
        /// </summary>
        Iterator(typename HashTable<Pair>::Iterator iterator) : it(iterator) {}

        /// <summary>
        /// �������������� �������� ��� ������� � ������� ���� ����-��������.
        /// </summary>
        /// <returns>������ �� ������� ���� ����-��������.</returns>
        const Pair& operator*() const {
            return *it; // �������������� �������� ���-�������
        }

        /// <summary>
        /// ������� � ���������� ��������.
        /// </summary>
        /// <returns>������ �� ������� ��������.</returns>
        Iterator& operator++() {
            ++it; // ��������� � ���������� �������� � ���-�������
            return *this;
        }

        /// <summary>
        /// ��������� ����������� ���� ����������.
        /// </summary>
        bool operator!=(const Iterator& other) const {
            return it != other.it; // ���������� ���������
        }
    };

    /// <summary>
    /// ���������� �������� �� ������ �������.
    /// </summary>
    /// <returns>�������� �� ������ ���� ����-��������.</returns>
    Iterator begin() const {
        return Iterator(hashTable.begin()); // ���������� �������� �� ������ ���-�������
    }

    /// <summary>
    /// ���������� ��������, ����������� �� ����� �������.
    /// </summary>
    /// <returns>�������� �� ������� ����� ���������� ��������.</returns>
    Iterator end() const {
        return Iterator(hashTable.end()); // ���������� �������� �� ����� ���-�������
    }
};

// ������� ��� �������� ������ ������� � �������������� assert
void testDictionary() {
    // ������� ������� � ������� ���� int � ���������� ���� std::string
    Dictionary<int, std::string> dict(10);

    // ��������� ��������
    dict.insert(1, "one");
    dict.insert(2, "two");
    dict.insert(3, "three");

    // ��������� ������� ������ � ��������
    assert(dict.contains(1));
    assert(dict.contains(2));
    assert(dict.contains(3));
    assert(!dict.contains(4)); // ���� 4 �����������

    // ��������� �������� �� ������
    assert(dict.get(1) == "one");
    assert(dict.get(2) == "two");
    assert(dict.get(3) == "three");

    // ������� ����
    dict.remove(2);
    assert(!dict.contains(2)); // ��������, ��� ���� ������

    // �������� ��������
    // ��� ������������ �������� ������� ��� �������� � ���������� ���-���������
    // � ������ ������� ������������, ��� ���-������� ����� ������ ���������� ��� ��� ������ 10 � 20
    dict.insert(10, "ten");  // ��������� ���� 10
    dict.insert(20, "twenty"); // ��������� ���� 20, ������� �������� �������� � ������ 10

    // ���������, ��� ��� ����� ���������� � �������
    assert(dict.contains(10));
    assert(dict.contains(20));
    assert(dict.get(10) == "ten");
    assert(dict.get(20) == "twenty");

    // �������� ���������� ��� ��������� � ��������������� �����
    try {
        dict.get(2); // ��������� ����������
        assert(false); // ���� �� ����� �����, ������ ������
    }
    catch (const std::runtime_error& e) {
        std::cout << "���������� �������: " << e.what() << std::endl;
    }

    try {
        std::string value = dict.find(1); // �������� ����� ���� 1
        std::cout << "������� �������� ��� ����� 1: " << value << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "������: " << e.what() << std::endl;
    }

    // ������ ����������� ������� 
    std::cout << "���������� ������� ����� ������:" << std::endl;
    dict.print();
}


/// <summary>
/// ������� ��� ������������ ��������� ������� � �������������� assert.
/// </summary>
void testDictionary2() {
    // ������� ������� � ������� ���� int � ���������� ���� std::string
    Dictionary<int, std::string> dict(10);

    // ��������� ��������
    dict.insert(1, "one");
    dict.insert(2, "two");
    dict.insert(3, "three");

    // �������� ���������: ������� ���� ���������
    int index = 1;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        // �������������� �������� � ��������� ���� � ��������
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

    // ������ ����������� ������� (��� �������)
    std::cout << "���������� ������� ����� ������ ���������:" << std::endl;
    dict.print();
}
