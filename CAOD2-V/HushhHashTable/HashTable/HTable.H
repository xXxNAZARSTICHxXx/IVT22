// ���� ����� �������� ���-22
#include <iostream>
#include <list>
#include <vector>
#include <cassert>
#include <string>

/// <summary>
/// ��������� ����� HashTable ��������� ���-������� � �������������� ������� ��� ���������� ��������.
/// </summary>
/// <typeparam name="T">��� ������, ������� ����� ��������� � ���-�������.</typeparam>
template <typename T>
class HashTable {
private:
    /// <summary>
    /// ������ ������� ��� �������� ��������� � ���-�������.
    /// ������ ������� ������� � ��� ������ ��� ���������� ��������.
    /// </summary>
    std::vector<std::list<T>> table;

    /// <summary>
    /// ������� ���-������� � ������������ ���������� �������.
    /// </summary>
    size_t capacity;

    /// <summary>
    /// ���-������� ��� ���������� ������� ������ �� ������ �����.
    /// </summary>
    /// <param name="key">���� ��� �����������.</param>
    /// <returns>������ ������ � �������� �������.</returns>
    size_t hashFunction(const T& key) const {
        std::hash<T> hasher; // ���������� ����������� ���-�������
        return hasher(key) % capacity; // ���������� ������, ������������ ��������
    }

public:
    /// <summary>
    /// �����������, ��������� ���-������� � �������� ��������.
    /// </summary>
    /// <param name="size">������ ���-������� (���������� �������).</param>
    explicit HashTable(size_t size) : capacity(size) {
        table.resize(size); // ������������� ������� � ������� ��������
    }

    /// <summary>
    /// ��������� ������� � ���-�������, ������� ������������.
    /// </summary>
    /// <param name="key">����, ������� ���������� ��������.</param>
    void insert(const T& key) {
        size_t index = hashFunction(key); // ��������� ������ ������
        for (const auto& existingKey : table[index]) { // ��������� �� ������� ����������
            if (existingKey == key)
                return; // �� ���������, ���� ���� ��� ����������
        }
        table[index].push_back(key); // ��������� ���� � ��������������� ������
    }

    //����� ������� ��������
    /*
    
            for (const auto& existingKey : table[index]) { // ���� ���� � ������
            if (existingKey == key)
                return true; // ���� ������

            ���� ������������ ����... ���� ������, �� �� ��������� �������... 
    */

    /// <summary>
    /// ���������, ���������� �� ������� � ���-�������.
    /// </summary>
    /// <param name="key">���� ��� ������.</param>
    /// <returns>true, ���� ������� ������; ����� false.</returns>
    bool find(const T& key) const {
        size_t index = hashFunction(key); // ��������� ������ ������
        for (const auto& existingKey : table[index]) { // ���� ���� � ������
            if (existingKey == key)
                return true; // ���� ������
        }
        return false; // ���� �� ������
    }

    /// <summary>
    /// ������� ������� �� ���-�������.
    /// </summary>
    /// <param name="key">����, ������� ���������� �������.</param>
    void remove(const T& key) {
        size_t index = hashFunction(key); // ��������� ������ ������
        table[index].remove(key); // ������� ���� �� ������
    }

    /// <summary>
    /// �������� ���������� ���-������� �� �������� �������.
    /// </summary>
    void print() const {
        for (size_t i = 0; i < capacity; ++i) { // �������� �� ���� �������
            std::cout << "������ " << i << ": "; // ������� ������ ������
            for (const auto& key : table[i]) { // ���������� �������� ������
                std::cout << key << " "; // ������� �������
            }
            std::cout << std::endl; // ��������� ������
        }
    }

    /// <summary>
    /// ����� Iterator ������������� �������� ��� ��������� ���-�������.
    /// </summary>
    class Iterator {
    private:
        const std::vector<std::list<T>>& table; // ������ �� ���-�������
        size_t bucketIndex; // ������� ������ ������
        typename std::list<T>::const_iterator chainIterator; // �������� ������

        /// <summary>
        /// ��������� � ���������� ��������� ������.
        /// </summary>
        void moveToNextNonEmptyBucket() {
            while (bucketIndex < table.size() && chainIterator == table[bucketIndex].end()) { // ���� ����� ������
                ++bucketIndex; // ��������� � ���������� ������
                if (bucketIndex < table.size()) // ���������, ��� �� ����� �� �������
                    chainIterator = table[bucketIndex].begin(); // �������������� �������� ������
            }
        }

    public:
        /// <summary>
        /// ����������� ���������.
        /// </summary>
        /// <param name="table">������ �� �������.</param>
        /// <param name="index">��������� ������ ������.</param>
        Iterator(const std::vector<std::list<T>>& table, size_t index)
            : table(table), bucketIndex(index),
            chainIterator(index < table.size() && !table[index].empty() ? table[index].begin() : typename std::list<T>::const_iterator()) {
            moveToNextNonEmptyBucket(); // ��������� � ������� ��������� ������
        }

        /// <summary>
        /// �������������� �������� ��� ������� � �������� ��������.
        /// </summary>
        /// <returns>������ �� ������� �������.</returns>
        const T& operator*() const {
            return *chainIterator; // ���������� ������� �� ������
        }

        /// <summary>
        /// ������� � ���������� �������� �������.
        /// </summary>
        /// <returns>������ �� ������� ��������.</returns>
        Iterator& operator++() {
            ++chainIterator; // ��������� � ���������� �������� ������
            moveToNextNonEmptyBucket(); // ���� ������ �������, ��������� � ���������� ������
            return *this; // ���������� ������� ��������
        }

        /// <summary>
        /// ��������� ����������� ���� ����������.
        /// </summary>
        /// <param name="other">������ ��������.</param>
        /// <returns>true, ���� ��������� �����������; ����� false.</returns>
        bool operator!=(const Iterator& other) const {
            return bucketIndex != other.bucketIndex || // ��������� ������ ������
                (bucketIndex < table.size() && chainIterator != other.chainIterator); // ��������� �������� ������
        }
    };

    /// <summary>
    /// ���������� �������� �� ������ �������.
    /// </summary>
    /// <returns>�������� �� ������ �������.</returns>
    Iterator begin() const {
        return Iterator(table, 0); // �������� � ������� ������
    }

    /// <summary>
    /// ���������� ��������, ����������� �� ����� �������.
    /// </summary>
    /// <returns>�������� �� ������� ����� ���������� ��������.</returns>
    Iterator end() const {
        return Iterator(table, table.size()); // ������ �� ��������� �������
    }
};

/// <summary>
/// �������� ������� ��� ������������ ������ ���-������� � ����������.
/// </summary>
void testHashTableWithIterator() {
    HashTable<int> ht(5); // ������� ������� � 5 ��������

    ht.insert(1);
    ht.insert(2);
    ht.insert(6);
    ht.insert(11);
    ht.insert(3);

    std::cout << "���������� ������� � �������������� ���������:" << std::endl;
    for (const auto& key : ht) { // ���������� �������� ��� �������� ���������
        std::cout << key << " "; // ������� ������ �������
    }
    std::cout << std::endl;
}


/// <summary>
/// ������� ��� �������� ���� ������� ������ HashTable
/// </summary>
void testHashTable() {
    HashTable<int> ht(10);

    ht.insert(1);
    ht.insert(2);
    ht.insert(12);
    ht.insert(3);
    assert(ht.find(1));
    assert(ht.find(2));
    assert(ht.find(12));
    assert(ht.find(3));
    assert(!ht.find(5));

    ht.insert(2);
    ht.insert(12);
    ht.insert(3);
    assert(ht.find(2));
    assert(ht.find(12));
    assert(ht.find(3));

    ht.remove(12);
    assert(!ht.find(12));
    ht.remove(3);
    assert(!ht.find(3));
    ht.remove(5);
    assert(!ht.find(5));

    ht.insert(5);
    assert(ht.find(5));
    ht.remove(5);
    assert(!ht.find(5));

    HashTable<int> collisionTest(5);
    collisionTest.insert(1);
    collisionTest.insert(6);
    collisionTest.insert(11);

    assert(collisionTest.find(1));
    assert(collisionTest.find(6));
    assert(collisionTest.find(11));

    collisionTest.remove(6);
    assert(collisionTest.find(1));
    assert(!collisionTest.find(6));
    assert(collisionTest.find(11));

    collisionTest.insert(6);
    assert(collisionTest.find(6));

    collisionTest.print();
    std::cout << "��� ����� �������� �������." << std::endl;
}

