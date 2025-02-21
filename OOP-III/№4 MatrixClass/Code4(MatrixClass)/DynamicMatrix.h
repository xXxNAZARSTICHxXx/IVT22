#ifndef DYNAMIC_MATRIX_H
#define DYNAMIC_MATRIX_H

class DynamicMatrix {
private:
    int** data;

public:
    int rows;
    int cols;

    DynamicMatrix();
    // Конструктор
    DynamicMatrix(int rows, int cols);

    // Деструктор
    ~DynamicMatrix();

    DynamicMatrix(const DynamicMatrix& other);
    DynamicMatrix& operator=(const DynamicMatrix& other);
    // Метод для вывода матрицы
    void printMatrix() const;

    // Метод для установки значения в ячейке матрицы
    void setElement(int row, int col, int value);
};

#endif