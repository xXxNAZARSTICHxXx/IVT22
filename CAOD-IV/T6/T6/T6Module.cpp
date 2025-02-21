#include <iostream>
#include <cassert>
#include <fstream>
#include <stdexcept>
#include <vector> 
#include <algorithm>
using namespace std;

//Глобальный массив для хранения строк треугольника Паскаля
vector<vector<long long>> pascalTriangle;

//Функция для вычисления значения элемента треугольника Паскаля
//row - хранение сторк, col - хранение столбцов
long long pascalValue(int row, int col) {
    if (col == 0 || col == row)
        return 1;
    else
        return pascalValue(row - 1, col - 1) + pascalValue(row - 1, col);
}

//Функция для открытия файла и чтения значения из него
//filename - файловая переменная
int readValueFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw runtime_error("Невозможно открыть файл " + filename + " для чтения");
    }
    int value;
    inputFile >> value;
    inputFile.close();

    return value;
}

//Функция для заполнения массива строк треугольника Паскаля
//n - размер массива
void fillPascalTriangle(int n) {
    pascalTriangle.clear(); 
    for (int i = 0; i < n; i++) {
        vector<long long> row;
        for (int j = 0; j <= i; j++) {
            row.push_back(pascalValue(i, j));
        }
        pascalTriangle.push_back(row);
    }
}

//Функция для вывода треугольника Паскаля в файл
//n - размер массива, filename - файловая переменная
void printPascalTriangleToFile(int n, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        throw runtime_error("Невозможно открыть файл для записи.");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            outputFile << pascalValue(i, j) << " ";
        }
        outputFile << endl;
    }
    outputFile.close();
}

//Assert-функция для проверки функций
void assertCheck() {
    assert(pascalValue(3, 3) == 1);
    assert(pascalValue(5, 4) == 5);
    assert(pascalValue(7, 5) == 21);
}

