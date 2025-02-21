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

#include "T1Names.h"


using namespace std;

// ГЛАВНАЯ ФУНКЦИЯ
int main()
{
    setlocale(LC_ALL, "russian");  // Преобразование русского языка
    assert_run();  // Функция проверки сортировок через assert
    const string first_array = "before_array.txt";  // Имя файла для сохранения массива до сортировок
    const string second_array = "after_array.txt";  // Имя файла для сохранения массива после сортировок
    const string first_bin_array = "before_bin_array.txt";  // Имя бинарного файла для сохранения массива до сортировки
    const string second_bin_array = "after_bin_array.txt";  // Имя бинарного файла для сохранения массива после сортировки
    srand(time(nullptr));  // Создание генератора псевдослучайных чисел
    int n;  // n - длина массива
    n = array_size();  // Определение длины массива
    int min = 1, max = 10000;  // min, max - минимальный и максимальный диапазоны случайных чисел
    int* arr = new int[n];  // Создание массива
    random_diaposon(min, max);  // Указание диапазонов случайных чисел
    auto start_time = chrono::high_resolution_clock::now();  // Общий объект времени для всех измерений
    filling_array<int>(n, min, max, arr);  // Создание массива и его заполнение
    cout << "Время создания массива: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    try {
        save_in_file<int>(n, arr, first_array);  // Сохранение первичного массива в файл
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    cout << "Время сохранения массива в текстовый файл: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    try {
        save_in_binary_file<int>(n, arr, first_bin_array);  // Сохранение первичного массива в файл
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    cout << "Время сохранения массива в бинарный файл: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    cout << "Введите запрашиваемое число для поиска его в массиве: ";
    int x;  // Инициализация X - числа для поиска его в массиве
    cin >> x;  // Ввод числа X
    cout << seek_run<int>(n, arr, x) << endl;  // Поиск числа X в массиве
    cout << "Время поиска числа: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    algoritm_sort_array<int>(n, arr);  // Сортировка вставками
    cout << "Время сортировки массива: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    cout << seek_run<int>(n, arr, x) << endl;  // Поиск числа X в массиве
    cout << "Время поиска числа: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    try {
        save_in_file<int>(n, arr, second_array);  // Сохранение отсортированного массива в файл
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    cout << "Время сохранения отсортированного массива в текстовый файл: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    try {
        save_in_binary_file<int>(n, arr, second_bin_array);  // Сохранение первичного массива в файл
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    cout << "Время сохранения отсортированного массива в бинарный файл: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    cout << "Программа завершилась" << "\n"; 									//Вывод: "Программа завершилась"
}
