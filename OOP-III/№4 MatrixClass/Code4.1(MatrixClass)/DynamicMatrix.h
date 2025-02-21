///Стич Назар Иванович ИВТ-22 (КЛАССЫ)
///Заголовочный файл - файл хранящий класс МАТРИЦЫ
#include <string>                                                               //Подключение библиотеки для работы с строками

class DynamicMatrix                                                             ///Класс матрицы
{                     
private:
    double **matrix;                                                            ///Матрица, которую нельзя напрямую изменить
public:
    int rows;                                                                   ///Открытое поле для доступа к числу строк
    int cols;                                                                   ///Открытое поле для доступа к числу столбцов
    DynamicMatrix();                                                            ///Метод инициализации матрицы
    DynamicMatrix(int rows, int cols);                                          ///Метод инициализации пустой матрицы
    DynamicMatrix(const DynamicMatrix& other);                                  ///Метод инициализации копированного конструктора матрицы
    DynamicMatrix& operator=(const DynamicMatrix& other);                       ///Метод присвоения матрицы
    double** getMatrix() const {                                                ///Метод получения матриы
    return matrix;                                                              //Возврат матрицы
    }
    void setElement(int row, int col, int value);                               ///Метод замены отдельного числа в матрице
    int getElement(int row, int col);                                           ///Метод получения элемента из матрицы
    void saveToFile(const std::string& filename);                               ///Метод загрузки матрицы в файл
    void loadFromFile(const std::string& filename, int& rows, int& cols);       ///Метод загрузки матрицы из файла
    DynamicMatrix add(const DynamicMatrix& other) const;                        ///Метод сложения матрицы из матрицы
    // DynamicMatrix operator + (const DynamicMatrix& other) const;                        ///Метод сложения матрицы из матрицы
    // m3 = m1 + m2;
    DynamicMatrix subtract(const DynamicMatrix& other) const;                   ///Метод вычтания матрицы из матрицы
    void multiplyByScalar(int scalar);                                          ///Метод умножения матрицы на число
    void multiplyByMatrix(const DynamicMatrix& otherMatrix);                    ///Метод умножения матрицы на матрицу

    void transpose();                                                           ///Метод транспонирования матрицы
    int Determinant();                                                          ///Метод нахождения определителя
    void invertToDiagonal();                                                    ///Метод нахождения диагональной матрицы
    
    ~DynamicMatrix();                                                           ///Деструктор матрицы
    
    void printMatrix() const;                                                   ///Метод вывода матрицы
};