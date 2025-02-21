#include "DynamicMatrix.h"
#include <iostream>

DynamicMatrix::DynamicMatrix() : rows(0), cols(0), data(nullptr) {}

// Конструктор постройки
DynamicMatrix::DynamicMatrix(int rows, int cols) : rows(rows), cols(cols) {
    // Выделение памяти под матрицу
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
    }

    // Инициализация значений матрицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0;
        }
    }
}

// Деструктор
DynamicMatrix::~DynamicMatrix() {
    // Освобождение памяти
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

// Конструктор копирования
DynamicMatrix::DynamicMatrix(const DynamicMatrix& other) : rows(other.rows), cols(other.cols) {
    // Выделение памяти под матрицу
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
    }

    // Копирование значений из другой матрицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Оператор присваивания
DynamicMatrix& DynamicMatrix::operator=(const DynamicMatrix& other) {
    if (this != &other) {
        // Освобождение памяти текущей матрицы
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        // Копирование значений из другой матрицы
        rows = other.rows;
        cols = other.cols;

        // Выделение памяти под матрицу
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }

        // Копирование значений из другой матрицы
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}




// Метод для вывода матрицы
void DynamicMatrix::printMatrix() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Метод для установки значения в ячейке матрицы
void DynamicMatrix::setElement(int row, int col, int value) {
    setlocale(LC_ALL, "Russian");
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        data[row][col] = value;
    } else {
        std::cerr << "Ошибка: Недопустимые индексы ячейки." << std::endl;
    }
}