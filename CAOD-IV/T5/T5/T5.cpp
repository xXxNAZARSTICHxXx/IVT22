#include <iostream>                                                                         
#include <fstream>                                                                                 
#include <clocale>                                                                                 
#include <time.h>                                                                                
#include <stdlib.h>                                                                               
#include <cstdlib>
#include <fstream> 
#include <ctime>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <functional> 

#include "T5Names.h"


using namespace std;

// ГЛАВНАЯ ФУНКЦИЯ
//todo AUTOR через аргумент
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "russian");  // Преобразование русского языка
    assert_run();  // Функция проверки сортировок через assert
    int n = atoi(argv[1]); //длина первого массива
    int min = atoi(argv[2]); //Минимальное значение первого диапазона первого массива
    int max = atoi(argv[3]); //Максимальное значение второго диапазона первого массива
    int n2 = atoi(argv[4]); //длина второго массива
    int min2 = atoi(argv[5]); //Минимальное значение первого диапазона второго массива
    int max2 = atoi(argv[6]); //Максимальное значение второго диапазона второго массива
    int contr2 = atoi(argv[7]); //Способ сортировки первого массива
    int contr3 = atoi(argv[8]); //Способ сортировки второго массива
    //1)Пузырьком
    //2)Коктельная(встряхиванием)
    //3)Вставками
    //4)Через библиотеку (БЫСТРЫЙ)
    //5)СУПЕРБыстрая сортировка (БЫСТРЫЙ)
    int cycle = atoi(argv[9]); //Кол-во запусков
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    
    int timeA = 0; // Временная переменная для замера времени
    float timeB = 0; // Временная переменная для замера I сортировки
    float timeC = 0; // Временная переменная для замера II сортировки
    float timeD = 0; // Временная переменная для замера слияния
    for (int i = 0; i < cycle; i++) {
        srand(time(nullptr));  // Создание генератора псевдослучайных чисел
        int* arr = new int[n];  // Создание массива
        int* arr2 = new int[n2];  // Создание массива2
        int* arr3 = new int[n * 2];
        function<bool(int&, int&)> isEqual = [](int x, int y) {return (x == y); };

        auto start_time = chrono::high_resolution_clock::now();  // Общий объект времени для всех измерений
        filling_array<int>(n, min, max, arr);  // Создание массива и его заполнение
        //cout << "Время создания массива: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";



        start_time = chrono::high_resolution_clock::now(); // Объявление счетчика микросекунд
        filling_array<int>(n2, min2, max2, arr2);  // Создание массива и его заполнение
        //cout << "Время создания массива: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";

        //cout << "Введите способ сортировки:\n1)Пузырьком\n2)Коктельная(встряхиванием)\n3)Вставками\n4)Через библиотеку (БЫСТРЫЙ)\n5)СУПЕРБыстрая сортировка (БЫСТРЫЙ)\n";
        
        //cout << "Выбран способ: " << contr2 << endl;
        start_time = chrono::high_resolution_clock::now();
        if (contr2 == 1) {
            bubble_sort<int>(n, arr); //Последовательная сортировка
        }
        else if (contr2 == 2) {
            cocktail_sort<int>(n, arr); //Бинарная сортировка
        }
        else if (contr2 == 3) {
            insertion_sort<int>(n, arr); //Интерполяционнная сортировка
        }
        else if (contr2 == 4) {
            algoritm_sort_array<int>(n, arr); //Через библиотеку сортировка
        }
        else if (contr2 == 5) {
            quickSort(arr, 0, n - 1); //Через СУПЕРбыструю сортировка
        }
        else if (contr3 == 6) {
            shellSort<int>(arr, n - 1); //Через сортировку Шелла  
        }
        else if (contr3 == 7) {
            heapSort<int>(arr, n - 1); //Через пирамидную сортировку
        }
        timeA = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
        //cout << "Время сортировки массива: " << timeA << "ms\n";
        timeB += timeA;
        //cout << "Введите способ сортировки:\n1)Пузырьком\n2)Коктельная(встряхиванием)\n3)Вставками\n4)Через библиотеку (БЫСТРЫЙ)\n5)СУПЕРБыстрая сортировка (БЫСТРЫЙ)\n";
        //cout << "Выбран способ: " << contr3 << endl;
        start_time = chrono::high_resolution_clock::now();
        if (contr3 == 1) {
            bubble_sort<int>(n2, arr2); //Последовательная сортировка
        }
        else if (contr3 == 2) {
            cocktail_sort<int>(n2, arr2); //Бинарная сортировка
        }
        else if (contr3 == 3) {
            insertion_sort<int>(n2, arr2); //Интерполяционнная сортировка
        }
        else if (contr3 == 4) {
            algoritm_sort_array<int>(n2, arr2); //Через библиотеку сортировка
        }
        else if (contr3 == 5) {
            quickSort(arr2, 0, n2 - 1); //Через СУПЕРбыструю сортировка  
        }
        else if (contr3 == 6) {
            shellSort<int>(arr2, n2 - 1); //Через сортировку Шелла
        }
        else if (contr3 == 7) {
            heapSort<int>(arr, n - 1); //Через пирамидную сортировку
        }
        timeA = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
        //cout << "Время сортировки массива: " << timeA << "ms\n";
        timeC += timeA;

        start_time = chrono::high_resolution_clock::now();
        mergeSort(arr3, n + n2);
        timeA = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start_time).count();

        //cout << "Время слияния массива: " << timeA << "ms\n";
        timeD += timeA;
    }

    cout << "Среднее время первой сортировки: " << timeB / cycle << "ms\n";
    cout << "Среднее время второй сортировки: " << timeC / cycle << "ms\n";
    //cout << "Среднее время слияния: " << timeD / cycle << "ms\n";
    cout << "Программа завершилась" << "\n"; 									//Вывод: "Программа завершилась"
    return 0;
}
