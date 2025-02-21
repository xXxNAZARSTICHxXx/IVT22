// Стич Назар Иванович ИВТ-22
#include <iostream>
#include <string>
//#include "HTable.h" // Убедитесь, что файл назван корректно
#include "HMAP.H"

/// <summary>
/// Тестирование работы хэш-таблицы
/// </summary>
/// <returns>0 в случае успешного завершения</returns>
int main() {
    setlocale(LC_ALL, "russian");
    testHashTable();
    testHashTableWithIterator();
    //testSet();
    //testSetIterator();
    
    // Тестирование с шаблоном int
    HashTable<int> ht(10); // Создаем хэш-таблицу на 10 элементов

    ht.insert(1); // Добавляем ключ 1
    ht.insert(2); // Добавляем ключ 2
    ht.insert(12); // Добавляем ключ 12 (попадет в ту же цепочку, что и 2)
    ht.insert(2); // Дубликат, должен быть проигнорирован

    std::cout << "Содержимое хэш-таблицы:" << std::endl;
    ht.print(); // Выводим содержимое таблицы

    std::cout << "Поиск ключа 1: " << (ht.find(1) ? "Существует" : "Не существует") << std::endl;
    std::cout << "Поиск ключа 3: " << (ht.find(3) ? "Существует" : "Не существует") << std::endl;

    ht.remove(12); // Удаляем ключ 12
    std::cout << "После удаления ключа 12:" << std::endl;
    ht.print(); // Выводим содержимое таблицы после удаления

    return 0;
}
