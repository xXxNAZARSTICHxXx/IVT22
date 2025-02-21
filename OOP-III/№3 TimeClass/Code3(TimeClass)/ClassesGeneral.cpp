///Стич Назар Иванович ИВТ-22 (КЛАССЫ)
///Основной файл - исполнитель кода
#include <iostream>                                         //Подключение библиотеки для ввода вывода через консоль
#include <string>                                           //Подключение библиотеки строк

#include "ClassesNAMEMODULE.h"                              //Подключение собственноого заголовочного файла классов

int main() {                                                //Главная функция - исполнитель

    int x1,x2,x3,x4,x5;                                     //Аргументы вводимые внутри программы x1-года x2-дни x3-часы x4-минуты x5-секунды
    std::cout << "Input year's value:" << std::endl;        //Вывод строки "Input year's value:"
    std::cin >> x1;                                         //Ввод х1
    std::cout << "Input day's value:" << std::endl;         //Вывод строки "Input day's value:"
    std::cin >> x2;                                         //Ввод х2
    std::cout << "Input hour's value:" << std::endl;        //Вывод строки "Input hour's value:"
    std::cin >> x3;                                         //Ввод х3
    std::cout << "Input minute's value:" << std::endl;      //Вывод строки "Input minute's value:"
    std::cin >> x4;                                         //Ввод х4
    std::cout << "Input second's value:" << std::endl;      //Вывод строки "Input second's value:"
    std::cin >> x5;                                         //Ввод х5
    std::cout << "First info-time:" << std::endl;           //Вывод строки "First info-time:"
    Time t1(x1, x2, x3, x4, x5);                            //Подача аргументов для преобразования и рассчетов (конструктор)
    std::cout << t1.toString() << std::endl;                //Преобразование и вывод строкой

    std::cout << "Input year's value:" << std::endl;        //Вывод строки "Input year's value:"
    std::cin >> x1;                                         //Ввод х1
    std::cout << "Input day's value:" << std::endl;         //Вывод строки "Input day's value:"
    std::cin >> x2;                                         //Ввод х2
    std::cout << "Input hour's value:" << std::endl;        //Вывод строки "Input hour's value:"
    std::cin >> x3;                                         //Ввод х3
    std::cout << "Input minute's value:" << std::endl;      //Вывод строки "Input minute's value:"
    std::cin >> x4;                                         //Ввод х4
    std::cout << "Input second's value:" << std::endl;      //Вывод строки "Input second's value:"
    std::cin >> x5;                                         //Ввод х5
    std::cout << "Second info-time:" << std::endl;          //Вывод строки "Second info-time:"
    Time t2(x1, x2, x3, x4, x5);                            //Подача аргументов для преобразования и рассчетов (конструктор)
    std::cout << t1.toString() << std::endl;                //Преобразование и вывод строкой


    std::cout << "AddTime function:" << std::endl;          //Вывод строки "AddTime function:"
    t1.addTime(t2);                                         //Сложение каждого значения друг с дружкой
    std::cout << t1.toString() << std::endl;                //Преобразование и вывод строкой


    std::cout << "SubTractTime function:" << std::endl;     //Вывод строки "SubTractTime function:"
    t1.subtractTime(t2);                                    //Вычитание каждого значения друг с дружкой
    std::cout << t1.toString() << std::endl;                //Преобразование и вывод строкой

    return 0;                                               //Завершение главной функции
}

