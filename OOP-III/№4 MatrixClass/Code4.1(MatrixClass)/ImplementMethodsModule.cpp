///Стич Назар Иванович ИВТ-22 (КЛАССЫ)
///Модульный файл - хранит все методы реализации класса                
#include <iostream>                                                                                 //Подключение библиотеки для ввода и вывода
#include <fstream>                                                                                  //Подключение библиотеки для ввода и вывода, а также работы с файлом
#include <clocale>                                                                                  //Подключение библиотеки для изменения кодировки текста
#include "DynamicMatrix.h"                                                                          //Подключение собственноого заголовочного файла~Класса для работы с кодом  

DynamicMatrix::DynamicMatrix() : rows(0), cols(0), matrix(nullptr) {}                               ///Метод инициализации матрицы

DynamicMatrix::DynamicMatrix(int rows, int cols) : rows(rows), cols(cols) {                         ///Метод инициализации пустой матрицы
    matrix = new double*[rows];                                                                     //Выделение памяти под матрицу по строкого
    for (int i = 0; i < rows; i++) {                                                                //Проход по строкам
        matrix[i] = new double[cols];                                                               //Выделение памяти под матрицу по столбцам
    }
    for (int i = 0; i < rows; i++) {                                                                //Проход по строкам
        for (int j = 0; j < cols; j++) {                                                            //Проход по столбцам
            matrix[i][j] = 0;                                                                       //Инициализация ячейки
        }
    }
}

DynamicMatrix::DynamicMatrix(const DynamicMatrix& other) : rows(other.rows), cols(other.cols) {     ///Метод инициализации копированного конструктора матрицы
    matrix = new double*[rows];                                                                     //Выделение памяти под матрицу по строкого
    for (int i = 0; i < rows; i++) {                                                                //Проход по строкам
        matrix[i] = new double[cols];                                                               //Выделение памяти под матрицу по столбцам
    }
    for (int i = 0; i < rows; i++) {                                                                //Проход по строкам
        for (int j = 0; j < cols; j++) {                                                            //Проход по столбцам
            matrix[i][j] = other.matrix[i][j];                                                      //Инициализация ячейки

        }
        // memcpy
    }
}

DynamicMatrix& DynamicMatrix::operator=(const DynamicMatrix& other) {                               ///Метод присвоения матрицы
    if (this != &other) {                                                                           //Если вторая матрица отсутствует
        for (int i = 0; i < rows; i++) {                                                            //Проход по строкам
            delete[] matrix[i];                                                                     //Освобождение матрицы по строкого
        }
        delete[] matrix;                                                                            //Освобождение матрицы
        rows = other.rows;                                                                          //Присвоение кол-ва строк другой матрице
        cols = other.cols;                                                                          //Присвоение кол-ва строк другому столбцу
        matrix = new double*[rows];                                                                 //Инициализация памяти по строкам
        for (int i = 0; i < rows; i++) {                                                            //Проход по столбцам
            matrix[i] = new double[cols];                                                           //Инициализация памяти по столбцам
        }
        for (int i = 0; i < rows; i++) {                                                            //Проход по строкам
            for (int j = 0; j < cols; j++) {                                                        //Проход по столбцам
                matrix[i][j] = other.matrix[i][j];                                                  //Инициализация ячейки
            }
            // memcpy
        }
    }
    return *this;                                                                                   //Возврат ЭТОГО - матрицы
}

void DynamicMatrix::setElement(int row, int col, int value)                             ///Метод замены отдельного числа в матрице
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {                             //Проверка на правильное введение позиций в диапазоне
        matrix[row][col] = value;                                                       //Присвоение значения
    } 
    else {
        std::cout << "Неправильно введенное кол-во строк или столбцов" << std::endl;    //Вывод строки "Неправильно введенное кол-во строк или столбцов"
    }
}

int DynamicMatrix::getElement(int row, int col)                                         ///Метод получения элемента из матрицы
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {                             //Проверка на правильное введение позиций в диапазоне
        return matrix[row][col];                                                        //Возврат значения
    } 
    else {
        std::cout << "Неправильно введенное кол-во строк или столбцов" << std::endl;    //Вывод строки "Неправильно введенное кол-во строк или столбцов"
        return 0;                                                                       //Возврат 0 - т.к. функция принимает значение int
    }
}

void DynamicMatrix::saveToFile(const std::string& filename)                             ///Метод загрузки матрицы в файл
{
    std::ofstream file(filename);                                                       //Открытие файла на запись
    if (file.is_open()) {                                                               //Если файл открыт
        file << rows << " " << cols << "\n";                                            //Запись кол-во строк и столбцов
        for (int i = 0; i < rows; i++) {                                                //Проход по строкам
            for (int j = 0; j < cols; j++) {                                            //Проход по столбцам
                file << matrix[i][j] << " ";                                            //Запись матрицы
            }
            file << "\n";                                                               //Переход на следующую строку
        }
        file.close();                                                                   //Закрытие файла
    } 
    else {
        std::cout << "Файл не может быть открыт" << std::endl;                          //Вывод строки "Файл не может быть открыт"
    }
}

// no rows, cols
// this->rows, cols to private
void DynamicMatrix::loadFromFile(const std::string& filename, int& rows, int& cols) {   ///Метод загрузки матрицы из файла
    std::ifstream file(filename);                                                       //Открытие файла на чтение
    if (!file.is_open()) {                                                              //Если файл не открыт
        std::cout << "Ошибка открытия файла" << std::endl;                              //Вывод строки "Ошибка открытия файла"
        return;                                                                         //Выход из метода
    }
    if (!(file >> this->rows >> cols)) {                                                      //Если чтение размерности не удалось
        std::cout << "Ошибка считывания размерности матрицы" << std::endl;              //Вывод строки "Ошибка считывания размерности матрицы"
        file.close();                                                                   //Закрытие файла
        return;                                                                         //Выход из метода
    }
    matrix = new double*[rows];                                                         //Инициализация памяти по строкам
    for (int i = 0; i < rows; i++) {                                                    //Проход по строкам
        matrix[i] = new double[cols];                                                   //Инициализация памяти по столбцам
        for (int j = 0; j < cols; j++) {                                                //Проход по столбцам
            if (!(file >> matrix[i][j])) {                                              //Если чтение элемента массива не удалось
                std::cout << "Ошибка считывания элемента матрицы" << std::endl;         //Вывод строки "Ошибка считывания элемента матрицы"
                file.close();                                                           //Закрытие файла
                return;                                                                 //Выход из метода
            }
        }
    }
    file.close();                                                                       //Закрытие файла
    std::cout << "Матрица успешно загружена из файла" << std::endl;                     //Вывод строки 
}

DynamicMatrix DynamicMatrix::add(const DynamicMatrix& other) const {                    ///Метод сложения матрицы из матрицы
    if (rows != other.rows || cols != other.cols) {                                     //Если размерность не совпадает
        std::cout << "Невозможно сложить матрицы разных размерностей" << std::endl;     //Вывод строки "Невозможно вычесть матрицы разных размерностей"
        return DynamicMatrix(0, 0);                                                     //Возврат нулевой матрицы
    }
    DynamicMatrix result(rows, cols);                                                   //Считывание кол-ва строк и столбцов у матрицы
    for (int i = 0; i < rows; i++) {                                                    //Проход по строкам
        for (int j = 0; j < cols; j++) {                                                //Проход по столбцам
            result.setElement(i, j, matrix[i][j] + other.matrix[i][j]);                 //Установка и сложнеие элементов матрицы
        }
    }
    return result;                                                                      //Возврат сложенной матрицы
}

DynamicMatrix DynamicMatrix::subtract(const DynamicMatrix& other) const {               ///Метод вычтания матрицы из матрицы
    if (rows != other.rows || cols != other.cols) {                                     //Если размерность не совпадает
        std::cout << "Невозможно вычесть матрицы разных размерностей" << std::endl;     //Вывод строки "Невозможно вычесть матрицы разных размерностей"
        return DynamicMatrix(0, 0);                                                     //Возврат нулевой матрицы
    }
    DynamicMatrix result(rows, cols);                                                   //Считывание кол-ва строк и столбцов у матрицы
    for (int i = 0; i < rows; i++) {                                                    //Проход по строкам
        for (int j = 0; j < cols; j++) {                                                //Проход по столбцам
            result.setElement(i, j, matrix[i][j] + other.matrix[i][j]);                 //Установка и вычитание элементов матрицы
        }
    }
    return result;                                                                      //Возврат вычтеной матриц
}

void DynamicMatrix::multiplyByScalar(int scalar) {                                      ///Метод умножения матрицы на число
    for (int i = 0; i < rows; i++) {                                                    //Проход по строкам
        for (int j = 0; j < cols; j++) {                                                //Проход по столбцам
            matrix[i][j] *= scalar;                                                     //Умножение каждой ячейки на число
        }
    }
}

void DynamicMatrix::multiplyByMatrix(const DynamicMatrix& otherMatrix) {                ///Метод умножения матрицы на матрицу
    if (cols != otherMatrix.rows) {                                                     //Ксли идет несовпадение строк первой матрицы и столбцов другой матрицы
        std::cout << "Невозможно умножить матрицы: число столбцов первой матрицы не равно числу строк второй матрицы" << std::endl;         //Вывод строки "Невозможно умножить матрицы: число столбцов первой матрицы не равно числу строк второй матрицы"
        return;                                                                         //Выход из метода
    }
    DynamicMatrix result(rows, otherMatrix.cols);                                       //Считывание строк первой матрицы и столбцов другой матрицы
    for (int i = 0; i < rows; i++) {                                                    //Проход по строкам матрицы
        for (int j = 0; j < otherMatrix.cols; j++) {                                    //Проход по столбцам другой матрицы
            for (int k = 0; k < cols; k++) {                                            //Проход по столбцам матрицы
                result.matrix[i][j] += matrix[i][k] * otherMatrix.matrix[k][j];         //Умножение позиций
            }
        }
    }
    *this = result;                                                                     //Возврат матрицы
}

void DynamicMatrix::transpose() {                                                       ///Метод транспонирования матрицы
    DynamicMatrix result(cols, rows);                                                   //Считывание кол-ва строк и столбцов у матрицы
    for (int i = 0; i < rows; i++) {                                                    //Проход по строкам
        for (int j = 0; j < cols; j++) {                                                //Проход по столбцам
            result.matrix[j][i] = matrix[i][j];                                         //Переприсвоение значение ячейки
        }
    }
    *this = result;                                                                     //Возврат матрицы
}

//todo asserts
int DynamicMatrix::Determinant() {                                                      ///Метод нахождения определителя
    if (rows == cols) {                                                                 //Если матрица квадратная
        DynamicMatrix temp(*this);                                                      //Запоминание матрицы

        //Нахождение определителя
        int det = 1;                                                                    //Задание 1 для определителя для умножений         
        for (int i = 0; i < rows - 1; i++) {                                        
            for (int j = i + 1; j < rows; j++) {                                    
                int factor = temp.matrix[j][i] / temp.matrix[i][i];                 
                for (int k = 0; k < cols; k++) {                                     
                    temp.matrix[j][k] -= factor * temp.matrix[i][k];                   
                }
            }
        }
        for (int i = 0; i < rows; i++) {                                              
            det *= temp.matrix[i][i];                                                  
        }

        return det;                                                                     //Возврат определителя                                                              
    } else {
        std::cout << "Невозможно вычислить определитель: матрица не квадратная" << std::endl;      //Вывод строки Невозможно вычислить определитель: матрица не квадратная
        return 0;                                                                       //Выход из метода
    }
}

void DynamicMatrix::invertToDiagonal() {                                                ///Метод нахождения диагональной матрицы
    // Проверяем, что матрица квадратная (число строк равно числу столбцов)
    if (rows != cols) {
        std::cerr << "Ошибка: Матрица не квадратная. Невозможно преобразовать в диагональную" << std::endl;
        return;
    }

    // Применяем метод Гаусса
    for (int i = 0; i < rows; i++) {
        //Находим максимальный элемент в текущем столбце
        int maxRowIndex = i;
        for (int k = i + 1; k < rows; k++) {
            if (abs(matrix[k][i]) > abs(matrix[maxRowIndex][i])) {
                maxRowIndex = k;
            }
        }

        //Обмениваем текущую строку с строкой, содержащей максимальный элемент
        for (int k = 0; k < cols; k++) {
            std::swap(matrix[i][k], matrix[maxRowIndex][k]);
        }

        //Приводим текущую строку к единичному виду
        double divisor = matrix[i][i];
        for (int k = 0; k < cols; k++) {
            matrix[i][k] /= divisor;
        }

        //Обнуляем все элементы, находящиеся выше и ниже текущей строки
        for (int k = 0; k < rows; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < cols; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }


    //Приведение матрицы к диагональному виду
    for (int i = rows - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            int factor = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < cols; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    //Нормализация диагонали
    for (int i = 0; i < rows; i++) {
        int factor = matrix[i][i];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] /= factor;
        }
    }
}

DynamicMatrix::~DynamicMatrix()                                                         //Деструктор матрицы
{
    for (int i = 0; i < rows; i++) {                                                    //Проход по строкам
        delete[] matrix[i];                                                             //Освобождение памяти по строкам
    }
    delete[] matrix;                                                                    //Освобождение памяти
}  

void DynamicMatrix::printMatrix() const {                                               ///Метод вывода матрицы
    for (int i = 0; i < rows; i++) {                                                    //Проход по строкам
        for (int j = 0; j < cols; j++) {                                                //Проход по столбцам
            std::cout << matrix[i][j] << " ";                                           //Вывод элемента матрицы
        }
        std::cout << std::endl;                                                         //Переход на следующую строку
    }
}
