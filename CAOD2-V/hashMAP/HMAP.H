#include <iostream>
#include <list>
#include <vector>
#include <cassert>
#include <string>
#include "HTable.H"

// ����� ��������� �� ������ ���-�������
template <typename T>
class Set {
public:
    // ������� HashTable ��������� ��� ������� � ������
    class HashTable {
    public:
        // ���������� ��������� ��� �������� ������
        std::vector<std::list<T>> hashTable;
        size_t size; // ������ �������

        // �����������
        HashTable(size_t tableSize) : size(tableSize) {
            hashTable.resize(tableSize);
        }

        // ���-������� ��� ����������� �������
        size_t hashFunction(const T& key) const {
            return std::hash<T>()(key) % size;
        }

        // ����� ���������� ��������
        void insert(const T& value) {
            size_t index = hashFunction(value);
            hashTable[index].push_back(value);
        }

        // ����� ��� ������ ��������
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

        // ����� ��� �������� ��������
        void remove(const T& value) {
            size_t index = hashFunction(value);
            auto& bucket = hashTable[index];
            bucket.remove(value);
        }

        // �������� ��� ������ ��������� ���-�������
        class Iterator {
        public:
            Iterator(HashTable& table, size_t bucketIndex, typename std::list<T>::iterator listIter)
                : table(table), bucketIndex(bucketIndex), listIterator(listIter) {}

            // �������� ����������
            Iterator& operator++() {
                ++listIterator;
                // ���� ����� �� ����� �������� ������, ��������� � ���������� ������
                while (bucketIndex < table.hashTable.size() && listIterator == table.hashTable[bucketIndex].end()) {
                    ++bucketIndex;
                    if (bucketIndex < table.hashTable.size()) {
                        listIterator = table.hashTable[bucketIndex].begin();
                    }
                }
                return *this;
            }

            // �������� �������������
            T& operator*() {
                return *listIterator;
            }

            // �������� �����������
            bool operator!=(const Iterator& other) const {
                return bucketIndex != other.bucketIndex || listIterator != other.listIterator;
            }

        private:
            HashTable& table;
            size_t bucketIndex;
            typename std::list<T>::iterator listIterator;
        };


        /// <summary>
        /// ���������� �������� �� ������ �������.
        /// </summary>
        /// <returns>�������� �� ������ ���� ����-��������.</returns>
        Iterator begin() const {
            return Iterator(hashTable.begin()); // ���������� �������� �� ������ ���-�������
        }

        // ����� ��� ��������� ��������� �� �����
        Iterator end() {
            return Iterator(*this, hashTable.size(), {}); // �������� �� ��������� ���������� ��������
        }
    };

    HashTable hashTable;

public:
    // ����������� ���������
    Set(size_t size) : hashTable(size) {}

    // ������� ��������
    void insert(const T& value) {
        hashTable.insert(value);
    }

    // ����� ��������
    bool contains(const T& value) const {
        return hashTable.find(value);
    }

    // �������� ��������
    void erase(const T& value) {
        hashTable.remove(value);
    }

    // ������ ����������� ���������
    void print() const {
        for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
            std::cout << *it << " ";  // ������� ��������
        }
        std::cout << std::endl;
    }
};

// �������� ������� ��� �������� ��������� ����� assert
void testSet() {
    Set<int> mySet(10);

    // ��������� �������� � ���������
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(2); // ������� �������� ��������

    // ���������, ��� �������� ������������ � ���������
    assert(mySet.contains(1)); // 1 ������ ���� � ���������
    assert(mySet.contains(2)); // 2 ������ ���� � ���������
    assert(mySet.contains(3)); // 3 ������ ���� � ���������

    // ���������, ��� ����������� ������� 4
    assert(!mySet.contains(4)); // 4 �� ������ ���� � ���������

    // ������� ������� 2
    mySet.erase(2);
    assert(!mySet.contains(2)); // 2 ������ ���� �����

    // ������������ ��������

    // ��������� ��� �������� � ���������� ���-���������
    // ��� ������������, ����� hash(15) � hash(25) ����� ���������� ������
    mySet.insert(15);
    mySet.insert(25);

    // ���������, ��� ��� �������� ������������ � ���������, �������� �� ��������
    assert(mySet.contains(15)); // 15 ������ ���� � ���������
    assert(mySet.contains(25)); // 25 ������ ���� � ���������

    // ������� ���� �� ���������
    mySet.erase(15);
    assert(!mySet.contains(15)); // 15 ������ ���� �����
    assert(mySet.contains(25)); // 25 ������ ��������
}

// �������� ������� ��� �������� ��������� ����� assert � �������������� ���������
void testSetIterator() {
    Set<int> mySet(10);

    // ��������� �������� � ���������
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    // ��������� ����� ��������, ��� �������� ������������ � ���������
    auto it = mySet.hashTable.begin();

    // �������, ��� �������� ����� 1, 2 � 3 � ����� �������
    bool found1 = false, found2 = false, found3 = false;
    while (it != mySet.hashTable.end()) {
        if (*it == 1) found1 = true;
        if (*it == 2) found2 = true;
        if (*it == 3) found3 = true;
        ++it;
    }

    // ���������, ��� ��� �������� �������
    assert(found1); // 1 ������ ���� � ���������
    assert(found2); // 2 ������ ���� � ���������
    assert(found3); // 3 ������ ���� � ���������
}



