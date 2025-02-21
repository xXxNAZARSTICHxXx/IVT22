#include <iostream>
#include <string>
#include "DynamicMatrix.h"

int main() {
    setlocale(LC_ALL, "Russian");                                                                   //Изменение кодировки
    const std::string fname = "matrix.txt";                                                         //Создание постоянного имени файла
    const std::string ffname = "matrix2.txt"; 
    int rowsA, colsA, rowsB, colsB;                                                                                 //rows - строки/cols - столбцы
    int contr = 0;
    DynamicMatrix matrixA, matrixB;

    
    do {
        if (contr == 1) {
            std::cout << "Введите значения строк матрицы A: ";
            std::cin >> rowsA;
            std::cout << "Введите значения столбцов матрицы A: ";
            std::cin >> colsA;
            matrixA = DynamicMatrix(rowsA, colsA);
            for (int i = 0; i < rowsA; ++i) {
                for (int j = 0; j < colsA; ++j) {
                    int value;
                    std::cout << "Введите значение для matrixA[" << i << "][" << j << "]: ";
                    std::cin >> value;
                    matrixA.setElement(i, j, value);
                }
            }
            std::cout << "Введите число для использования команды" << std::endl;
            std::cin >> contr;
        }


        if (contr == 2) {
            std::cout << "Введите значения строк матрицы A: ";
            std::cin >> rowsB;
            std::cout << "Введите значения столбцов матрицы A: ";
            std::cin >> colsB;
            matrixB = DynamicMatrix(rowsB, colsB);
            for (int i = 0; i < rowsB; ++i) {
                for (int j = 0; j < colsB; ++j) {
                    int value;
                    std::cout << "Введите значение для matrixA[" << i << "][" << j << "]: ";
                    std::cin >> value;
                    matrixB.setElement(i, j, value);
                }
            }
            std::cout << "Введите число для использования команды" << std::endl;
            std::cin >> contr;
        }

    if (contr == 3){

    std::cout << "Введите число для использования команды" << std::endl;
    std::cin >> contr;
    }

    if (contr == 4){

    std::cout << "Введите число для использования команды" << std::endl;
    std::cin >> contr;
    }

    if (contr == 5){
    matrixA.printMatrix();
    std::cout << "Введите число для использования команды" << std::endl;
    std::cin >> contr;
    }

    if (contr == 6){
    matrixB.printMatrix();
    std::cout << "Введите число для использования команды" << std::endl;
    std::cin >> contr;
    }

    if (contr == 0){

    std::cout << "Введите число для использования команды" << std::endl;
    std::cin >> contr;
    }

    }while(contr!=999);
    std::cout << "Программа завершила работу!" << std::endl;
    return 0;
}