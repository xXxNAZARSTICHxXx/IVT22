///Стич Назар Иванович ИВТ-22
///Основной файл с кодом
#include <iostream>                                                                                 //Подключение библиотеки iostream для взаимодействия с консолью
#include "UltimateClass.h"                                                                          //Подключение собственной библиотеки класса UltimateClass.h

int main() {   

    short contr = 0;                                                                                 //Пульт управления в коде

    Bat* myInsectBat1 = new InsectBat();                                                            //Создане пустой формы для фруктовой летучей мыши
    Bat* myFruitBat1 = new FruitsBat();                                                             //Создане пустой формы для насекомоядной летучей мыши
    Bat* myBloodBat1 = new BloodBat();                                                              //Создане пустой формы для кровососущей летучей мыши

    void VirtualCheck();

    do{
    if (contr == 0){                                                                                //Если подается 0, то выводится список команд и ввод команды
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;               //Вывод строки "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
    std::cout << "~~~~~~~~~~~~~~~~Commands in prorgam~~~~~~~~~~~~~~~~~" << std::endl;               //Вывод строки "~~~~~~~~~~~~~~~~Commands in prorgam~~~~~~~~~~~~~~~~~"
    std::cout << "0: list of commands" << std::endl;                                                //Вывод строки "0: list of commands"
    std::cout << "1: input form of fruit bat" << std::endl;                                         //Вывод строки "1: input form of fruit bat"
    std::cout << "2: input form of insect bat" << std::endl;                                        //Вывод строки "2: input form of insect bat"
    std::cout << "3: input form of blood bat" << std::endl;                                         //Вывод строки "3: input form of blood bat" 
    std::cout << "4: output form of fruit bat" << std::endl;                                        //Вывод строки "4: output form of fruit bat"
    std::cout << "5: output form of insect bat" << std::endl;                                       //Вывод строки "5: output form of insect bat"
    std::cout << "6: output form of blood bat" << std::endl;                                        //Вывод строки "6: output form of blood bat"
    std::cout << "7: checking for data entry" << std::endl;
    std::cout << "8: exit" << std::endl;                                                            //Вывод строки "7: exit"
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;               //Вывод строки "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
    
    std::cout << "Input number of interaction: " << std::endl;                                      //Вывод строки "Input number of interaction: "
    std::cin >> contr;                                                                              //Ввод команды управления
    }

    if (contr == 1){                                                                                //Если подается 1, то начинается процесс заполения каждого поля формы фруктовй летучей мыши и ввод команды
    myFruitBat1->inputBatData();                                                                    //Ввод формы фруктовой летучей мыши
    std::cout << "Input number of interaction: " << std::endl;                                      //Вывод строки "Input number of interaction: "
    std::cin >> contr;                                                                              //Ввод команды управления
    }

    if (contr == 2){                                                                                //Если подается 2, то начинается процесс заполения каждого поля формы насекомоядной летучей мыши и ввод команды
    myInsectBat1->inputBatData();                                                                   //Ввод формы насекомоядной летучей мыши
    assertInsectCheck(myInsectBat1);                                                                //Проверка ввода данных по шаблону
    std::cout << "Input number of interaction: " << std::endl;                                      //Вывод строки "Input number of interaction: "
    std::cin >> contr;                                                                              //Ввод команды управления
    }

    if (contr == 3){                                                                                //Если подается 1, то начинается процесс заполения каждого поля формы кровососущей летучей мыши и ввод команды
    myBloodBat1->inputBatData();                                                                    //Ввод формы кровососущей летучей мыши
    std::cout << "Input number of interaction: " << std::endl;                                      //Вывод строки "Input number of interaction: "
    std::cin >> contr;                                                                              //Ввод команды управления
    }
    //Поиск по таблице виртуальных методов подходящего метода под тип на котооый указывает myFruitBat1
    if (contr == 4){                                                                                //Если подается 4, то выводится каждое оформленное поле формы фруктовй летучей мыши и ввод команды
    std::cout << myFruitBat1->toString() << std::endl;                                              //Вывод формы фруктовой летучей мыши
    std::cout << "Input number of interaction: " << std::endl;                                      //Вывод строки "Input number of interaction: "
    std::cin >> contr;                                                                              //Ввод команды управления
    }
    //Поиск по таблице виртуальных методов подходящего метода под тип на котооый указывает myInsectBat1
    if (contr == 5){                                                                                //Если подается 5, то выводится каждое оформленное поле формы насекомоядной летучей мыши и ввод команды
    std::cout << myInsectBat1->toString() << std::endl;                                             //Вывод формы насекомоядной летучей мыши
    std::cout << "Input number of interaction: " << std::endl;                                      //Вывод строки "Input number of interaction: "
    std::cin >> contr;                                                                              //Ввод команды управления
    }
    //Поиск по таблице виртуальных методов подходящего метода под тип на котооый указывает myBloodBat1
    if (contr == 6){                                                                                //Если подается 6, то выводится каждое оформленное поле формы фруктовй летучей мыши и ввод команды
    std::cout << myBloodBat1->toString() << std::endl;                                              //Вывод формы кровососущей летучей мыши
    std::cout << "Input number of interaction: " << std::endl;                                      //Вывод строки "Input number of interaction: "
    std::cin >> contr;                                                                              //Ввод команды управления
    }

    if (contr == 7){
    VirtualCheck();                                                                            //Проверка на вызов виртуального метода без указателей и с указателями (по желанию)    
    std::cout << "Input number of interaction: " << std::endl;                                      //Вывод строки "Input number of interaction: "
    std::cin >> contr;                                                                              //Ввод команды управления
    }

}while (contr != 8);                                                                                //Если подается 8, то программа завершается
    std::cout << "PROGRAM ENDED" << std::endl;
    delete myFruitBat1;                                                                             //Освобождение памяти шаблона myFruitBat1
    delete myInsectBat1;                                                                            //Освобождение памяти шаблона myInsectBat1
    delete myBloodBat1;                                                                             //Освобождение памяти шаблона myBloodBat1

    assertInsectBatCheck();                                                                         //Assert проверка InsectBat
    assertFruitBatCheck();                                                                          //Assert проверка FruitBat
    assertBloodBatCheck();                                                                          //Assert проверка BloodBat

    return 0;                                                                                       //Конец главного кода
}
