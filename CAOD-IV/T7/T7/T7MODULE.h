#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

//findchange - находение номиналов сдачи
//amount - введенная сдача; nominal - массивы с номиналами; size - размер массива с номиналами; change - массив со сдачей 
findChange(int amount, int nominal[], size_t size, int change[]) {
    sort(nominal, nominal + size, greater<int>()); // Сортировка номиналов по убыванию
    int comparisons = 0;            // Счетчик сравнений
    int num = 0;
    int index = 0; // Индекс для заполнения массива change
    for (int i = 0; i < size; i++) { // Циклическая проверка на все номиналы
        while (amount >= nominal[i]) {     // Жадная проверка на кол-во операций/пока значение сдачи >= 0
            amount -= nominal[i];          // Вычитание определенного номинала
            num++;                         // Засчитываем банкноту
            comparisons++;                 // Засчитываем сравнение
        }
        if (num > 0) {
            change[index++] = num; // Записываем количество использованных купюр/монет в массив
            num = 0; // Обнуляем счетчик
        }
        else {
            index++; //Если значение получилось отрицательное
        }
    }
    return comparisons; // Возвращаем количество сравнений
}

//assert-проверка для программистов
void assertCheck() {
    int nominal[] = { 1, 2, 5, 10 ,50, 100, 200, 500, 1000, 2000, 5000 }; // Номиналы купюр/монет
    const size_t size = sizeof(nominal) / sizeof(nominal[0]);                   //size_t size - для определения размера массива
    int change[size] = { 0 };                                                   // Массив для хранения количества использованных купюр/монет
    assert((findChange(7500, nominal, size, change)) == 3);                      // Проверка при проверке, что жадный алгоритм сделает проверку 3 раза
    assert((findChange(900, nominal, size, change)) == 3);                       // Проверка при проверке, что жадный алгоритм сделает проверку 3 раза
    assert((findChange(45, nominal, size, change)) == 5);                        // Проверка при проверке, что жадный алгоритм сделает проверку 5 раза
}
