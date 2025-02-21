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
//todo AUTOR через аргумент
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "russian");  // Преобразование русского языка
    assert_run();  // Функция проверки сортировок через assert
    int n = atoi(argv[1]); //длина массива
    int min = atoi(argv[2]); //Минимальное значение диапазона
    int max = atoi(argv[3]); //Максимальное значение диапазона
    int contr = atoi(argv[4]); //Тип поиска
    int num_searches = atoi(argv[5]); //Кол-во поисков
    int save_save = atoi(argv[6]); //Требуется ли сохранение (Если требуется несколько запусков - поставить 0)
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    const string first_array = "before_array.txt";  // Имя файла для сохранения массива до сортировок
    const string second_array = "after_array.txt";  // Имя файла для сохранения массива после сортировок
    const string first_bin_array = "before_bin_array.txt";  // Имя бинарного файла для сохранения массива до сортировки
    const string second_bin_array = "after_bin_array.txt";  // Имя бинарного файла для сохранения массива после сортировки
    srand(time(nullptr));  // Создание генератора псевдослучайных чисел
    int* arr = new int[n];  // Создание массива
    function<bool(int&, int&)> isEqual = [](int x, int y) {return (x == y); };



    auto start_time = chrono::high_resolution_clock::now();  // Общий объект времени для всех измерений
    filling_array<int>(n, min, max, arr);  // Создание массива и его заполнение
    cout << "Время создания массива: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    
    
    
    start_time = chrono::high_resolution_clock::now(); // Объявление счетчика микросекунд
    
    
    if (save_save == 1) {
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
    }
    
    
    //cout << "Введите запрашиваемое число для поиска его в массиве: ";
    int x;  // Инициализация X - числа для поиска его в массиве
    x = randomX<int>(min, max);
    seek_run<int>(n, arr, x); //Последовательный поиск числа X в массиве
    cout << "Время поиска числа: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    
    
    
    int contr2 = 0; //Тип сортировки
    //cout << "Введите способ сортировки:\n1)Пузырьком\n2)Коктельная(встряхиванием)\n3)Вставками\n4)Через библиотеку (БЫСТРЫЙ)\n";
    contr2 = 4;
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
    cout << "Время сортировки массива: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";


    double average_time = 0; //Время поисков/Среднее время поиска
    //cout << "Введите способ поиска:\n1)Последовательный\n2)Бинарный\n3)Интерполяционный\n";
    //start_time = chrono::high_resolution_clock::now();
    if (contr == 1) {
        for (int i = 1; i <= num_searches; i++) {
            x = randomX<int>(min, max);
            start_time = chrono::high_resolution_clock::now();
            //todo подставить предикат
            //seek_run<int>(n, arr, x); //Последовательный поиск числа X в массиве
            if (sequence_predicat_search(arr, n, isEqual, x) == true) {
                average_time += chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
            }
        }
    }
    else if (contr == 2) {
        for (int i = 1; i <= num_searches; i++) {
            x = randomX<int>(min, max);
            start_time = chrono::high_resolution_clock::now();
            binary_search<int>(arr, n, x); //Бинарный поиск числа X в массиве
            average_time += chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
        }
    }
    else if (contr == 3) {
        for (int i = 1; i <= num_searches; i++) {
            x = randomX<int>(min, max);
            start_time = chrono::high_resolution_clock::now();
            interpolation_search<int>(arr, n, x); //Интерполяционный поиск числа X в массиве
            average_time += average_time + chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
        }
    }
    cout << "Общее время поиска выбранного типа поиска: " << average_time << " ms\n" << endl;
    average_time /= num_searches;
    cout << "Среднее время поиска выбранного типа поиска: " << average_time << " ms\n" << endl;
    
    if (save_save == 1) {
        start_time = chrono::high_resolution_clock::now();
        try {
            save_in_file<int>(n, arr, second_array);  // Сохранение отсортированного массива в файл
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
        cout << "Время сохранения отсортированного массива в текстовый файл: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";



        start_time = chrono::high_resolution_clock::now();
        try {
            save_in_binary_file<int>(n, arr, second_bin_array);  // Сохранение первичного массива в файл
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
        cout << "Время сохранения отсортированного массива в бинарный файл: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count() << "ms\n";
    }
    cout << "Программа завершилась" << "\n"; 									//Вывод: "Программа завершилась"

    //Три цикла случайного числа
}
