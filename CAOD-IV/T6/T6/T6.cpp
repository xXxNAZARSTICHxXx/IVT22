#include <iostream>
#include "T6Module.cpp"

using namespace std;                            //Использование пространства имен std

//НАЧАЛО ПРОГРАММЫ
int main() {
    const string inpFILE = "INPUT.TXT";         //Файловая переменная для принятия кол-ва иттерации
    const string outFILE = "OUTPUT.TXT";        //Файловая переменная для вывода треугольника Паскаля
    setlocale(LC_ALL, "russian");               //Установка руссской Локали
    assertCheck();                              //Assert-проверка
    int n = readValueFromFile(inpFILE);         //Чтение кол-ва итерации для треугольника паскаля
    if (n < 1) {                              
        return 1;                               //Возврат 1 если значение отрицательное или нклевое
    }
    printPascalTriangleToFile(n, outFILE);      //Вывод треугольника в файл
    return 0;                                   //Конец программы
}
