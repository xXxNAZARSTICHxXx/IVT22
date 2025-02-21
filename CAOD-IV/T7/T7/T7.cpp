#include <iostream>
#include <algorithm>
#include "T7MODULE.h"
using namespace std;

int main(int argc, char* argv[]) {                 //Начало программы
    setlocale(LC_ALL, "russian");                  //Установление русской локали
    assertCheck();                                 //Assert провека
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";            //Делаем пропуск строки
    int amount = atoi(argv[1]);                                     //Определение сдачи - amount ВВОД С АРГУМЕНТА
    int nominal[] = { 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    const size_t size = sizeof(nominal) / sizeof(nominal[0]); //size_t size - для определения размера массива
    int change[size] = { 0 }; // Массив для хранения количества использованных купюр/монет
    int comparisons = findChange(amount, nominal, size, change); //Нахождение массива сдачи

    // Вывод количества использованных купюр/монет
    cout << "Количество использованных купюр/монет:" << endl; //Выводит "Количество использованных купюр/монет:"
    for (size_t i = 0; i < size; i++) { //
        if (change[i] > 0) { //
            cout << "Номинал " << nominal[i] << ": " << change[i] << endl; //Вывод номиналов
        }
    }

    cout << "\nКоличество сравнений: " << comparisons << endl; //Вывод кол-ва сравнений

    return 0;
}