///Стич Назар Иванович ИВТ-22
///Основной файл с кодом
#include <iostream>                                 //Подключение библиотеки iostream для взаимодействия с консолью
#include "UltimateClass.h"                          //Подключение собственной библиотеки класса UltimateClass.h

int main() {
    Fruits myFruitBat1(0, "0", 0, "0", 0, 0, 0, 0, "0", 0.0, "0", 0.0, "0", 0);                     //Создане пустой формы для фруктовой летучей мыши
    Insect myInsectBat1(0, "0", 0, "0", 0, 0, 0, 0, "0", 0.0, "0", 0.0, "0", 0);                    //Создане пустой формы для насекомоядной летучей мыши   
    Blood myBloodBat1(0, "0", 0, "0", 0, 0, 0, 0, "0", 0.0, "0", 0.0, "0", 0);                      //Создане пустой формы для кровососущей летучей мыши

    short contr = 0;                                                                                //Пульт управления в коде
    std::string inputword;                                                                          //Переменная для заполнения форма - строка
    int inputint;                                                                                   //Переменная для заполнения форма - число
    bool inputboolean;                                                                              //Переменная для заполнения форма - булевское число (0 или 1)
    float inputfloat;                                                                               //Переменная для заполнения форма - дробное число


    do{
    if (contr == 0){                                                                                //Если подается 0, то выводится список команд и ввод команды
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~Commands in prorgam~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "0: list of commands" << std::endl;
    std::cout << "1: input form of fruit bat" << std::endl;
    std::cout << "2: input form of insect bat" << std::endl;
    std::cout << "3: input form of blood bat" << std::endl;
    std::cout << "4: output form of fruit bat" << std::endl;
    std::cout << "5: output form of insect bat" << std::endl;
    std::cout << "6: output form of blood bat" << std::endl;
    std::cout << "7: exit" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    
    std::cout << "Input number of interaction: " << std::endl;
    std::cin >> contr;
    }

    if (contr == 1){                                                                                //Если подается 1, то начинается процесс заполения каждого поля формы фруктовй летучей мыши и ввод команды
    std::cout << "Input of ID-Number fruit bat: " << std::endl;
    std::cin >> inputint;
    myFruitBat1.setIdBat(inputint);
    std::cout << "Input of name fruit bat: " << std::endl;
    std::cin >> inputword;
    myFruitBat1.setName(inputword); 
    std::cout << "Input of flight time in meters fruit bat: " << std::endl;
    std::cin >> inputint;
    myFruitBat1.setFlightTime(inputint); 
    std::cout << "Input of date of birth fruit bat: " << std::endl;
    std::cin >> inputword;
    myFruitBat1.setBirthday(inputword); 
    std::cout << "Input of number meals fruit bat: " << std::endl;
    std::cin >> inputint;
    myFruitBat1.setNumberOfMeals(inputint); 
    std::cout << "Input of number of sleep cycles fruit bat: " << std::endl;
    std::cin >> inputint;
    myFruitBat1.setNumberOfSleepCycles(inputint); 
    std::cout << "Input of gender fruit bat (1 - male, 0 - female): " << std::endl;
    std::cin >> inputboolean;
    myFruitBat1.setGender(inputboolean); 
    std::cout << "Input count of winter hibernation cycles fruit bat: " << std::endl;
    std::cin >> inputint;
    myFruitBat1.setWinterHibernation(inputint); 
    std::cout << "Input of nickname fruit bat: " << std::endl;
    std::cin >> inputword;
    myFruitBat1.setNickname(inputword); 
    std::cout << "Input size of fruit bat in cm: " << std::endl;
    std::cin >> inputfloat;
    myFruitBat1.setsSize(inputfloat); 
    std::cout << "Input type of fruit bat: " << std::endl;
    std::cin >> inputword;
    myFruitBat1.setType(inputword); 
    std::cout << "Input food weight which fruit bat eated: " << std::endl;
    std::cin >> inputfloat;
    myFruitBat1.setFoodWeight(inputfloat); 
    std::cout << "Input type of food which fruit bat eated: " << std::endl;
    std::cin >> inputword;
    myFruitBat1.setTypeFruitFood(inputword); 
    std::cout << "Input cound of food which fruit bat eated: " << std::endl;
    std::cin >> inputfloat;
    myFruitBat1.setAmountOfFruits(inputfloat); 
    std::cout << "\n" << std::endl;
    std::cout << "Input number of interaction: " << std::endl;
    std::cin >> contr;
    }

    if (contr == 2){                                                                                //Если подается 2, то начинается процесс заполения каждого поля формы насекомоядной летучей мыши и ввод команды
    std::cout << "Input of ID-Number insect bat: " << std::endl;
    std::cin >> inputint;
    myInsectBat1.setIdBat(inputint);
    std::cout << "Input of name insect bat: " << std::endl;
    std::cin >> inputword;
    myInsectBat1.setName(inputword); 
    std::cout << "Input of flight time in meters insect bat: " << std::endl;
    std::cin >> inputint;
    myInsectBat1.setFlightTime(inputint); 
    std::cout << "Input of date of birth insect bat: " << std::endl;
    std::cin >> inputword;
    myInsectBat1.setBirthday(inputword); 
    std::cout << "Input of number meals insect bat: " << std::endl;
    std::cin >> inputint;
    myInsectBat1.setNumberOfMeals(inputint); 
    std::cout << "Input of number of sleep cycles insect bat: " << std::endl;
    std::cin >> inputint;
    myInsectBat1.setNumberOfSleepCycles(inputint); 
    std::cout << "Input of gender insect bat (1 - male, 0 - female): " << std::endl;
    std::cin >> inputboolean;
    myInsectBat1.setGender(inputboolean); 
    std::cout << "Input count of winter hibernation cycles insect bat: " << std::endl;
    std::cin >> inputint;
    myInsectBat1.setWinterHibernation(inputint); 
    std::cout << "Input of nickname insect bat: " << std::endl;
    std::cin >> inputword;
    myInsectBat1.setNickname(inputword); 
    std::cout << "Input size of insect bat in cm: " << std::endl;
    std::cin >> inputfloat;
    myInsectBat1.setsSize(inputfloat); 
    std::cout << "Input type of insect bat: " << std::endl;
    std::cin >> inputword;
    myInsectBat1.setType(inputword); 
    std::cout << "Input food weight which insect bat eated: " << std::endl;
    std::cin >> inputfloat;
    myInsectBat1.setFoodWeight(inputfloat); 
    std::cout << "Input type of food which insect bat eated: " << std::endl;
    std::cin >> inputword;
    myInsectBat1.setTypeInsectFood(inputword); 
    std::cout << "Input cound of food which insect bat eated: " << std::endl;
    std::cin >> inputfloat;
    myInsectBat1.setAmountOfInsect(inputfloat); 
    std::cout << "\n" << std::endl;
    std::cout << "Input number of interaction: " << std::endl;
    std::cin >> contr;
    }
    if (contr == 3){                                                                                   //Если подается 1, то начинается процесс заполения каждого поля формы кровососущей летучей мыши и ввод команды
    std::cout << "Input of ID-Number blood bat: " << std::endl;
    std::cin >> inputint;
    myBloodBat1.setIdBat(inputint);
    std::cout << "Input of name blood bat: " << std::endl;
    std::cin >> inputword;
    myBloodBat1.setName(inputword); 
    std::cout << "Input of flight time in meters blood bat: " << std::endl;
    std::cin >> inputint;
    myBloodBat1.setFlightTime(inputint); 
    std::cout << "Input of date of birth blood bat: " << std::endl;
    std::cin >> inputword;
    myBloodBat1.setBirthday(inputword); 
    std::cout << "Input of number meals blood bat: " << std::endl;
    std::cin >> inputint;
    myBloodBat1.setNumberOfMeals(inputint); 
    std::cout << "Input of number of sleep cycles blood bat: " << std::endl;
    std::cin >> inputint;
    myBloodBat1.setNumberOfSleepCycles(inputint); 
    std::cout << "Input of gender blood bat (1 - male, 0 - female): " << std::endl;
    std::cin >> inputboolean;
    myBloodBat1.setGender(inputboolean); 
    std::cout << "Input count of winter hibernation cycles blood bat: " << std::endl;
    std::cin >> inputint;
    myBloodBat1.setWinterHibernation(inputint); 
    std::cout << "Input of nickname blood bat: " << std::endl;
    std::cin >> inputword;
    myBloodBat1.setNickname(inputword); 
    std::cout << "Input size of blood bat in cm: " << std::endl;
    std::cin >> inputfloat;
    myBloodBat1.setsSize(inputfloat); 
    std::cout << "Input type of blood bat: " << std::endl;
    std::cin >> inputword;
    myBloodBat1.setType(inputword); 
    std::cout << "Input food weight which blood bat eated: " << std::endl;
    std::cin >> inputfloat;
    myBloodBat1.setFoodWeight(inputfloat); 
    std::cout << "Input type of food which blood bat eated: " << std::endl;
    std::cin >> inputword;
    myBloodBat1.setTypeBlood(inputword); 
    std::cout << "Input cound of food which blood bat eated: " << std::endl;
    std::cin >> inputfloat;
    myBloodBat1.setAmountOfBlood(inputfloat); 
    std::cout << "\n" << std::endl;
    std::cout << "Input number of interaction: " << std::endl;
    std::cin >> contr;
    }

    if (contr == 4){                                                                                //Если подается 4, то выводится каждое оформленное поле формы фруктовй летучей мыши и ввод команды
    std::cout << "~~~~~~~~~~~~~~~FRUIT BAT~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "ID-Number of bat: " << myFruitBat1.getIdBat() << std::endl;
    std::cout << "Name: " << myFruitBat1.getName() << std::endl;
    std::cout << "Flight time in meters: " << myFruitBat1.getFlightTime() << std::endl;
    std::cout << "Birthday of bat: " << myFruitBat1.getBirthday() << std::endl;
    std::cout << "Number of meals per day: " << myFruitBat1.getNumberOfMeals() << std::endl;
    std::cout << "Number of sleep cycles per day: " << myFruitBat1.getNumberOfSleepCycles() << std::endl;
    std::cout << "Gender of bat: " << myFruitBat1.getGender() << std::endl;
    std::cout << "Length of winter hibernation: " << myFruitBat1.getWinterHibernation() << std::endl;
    std::cout << "Nickname: " << myFruitBat1.getNickname() << std::endl;
    std::cout << "Bat size in centimeters: " << myFruitBat1.getsSize() << std::endl;
    std::cout << "Type of bat: " << myFruitBat1.getType() << std::endl;
    std::cout << "Food weight: " << myFruitBat1.getFoodWeight() << std::endl;
    std::cout << "Type fruit food: " << myFruitBat1.getTypeFruitFood() << std::endl;
    std::cout << "Amount fruits: " << myFruitBat1.getAmountOfFruits() << std::endl;

    std::cout << "Input number of interaction: " << std::endl;
    std::cin >> contr;
    }

    if (contr == 5){                                                                                //Если подается 5, то выводится каждое оформленное поле формы насекомоядной летучей мыши и ввод команды
    std::cout << "~~~~~~~~~~~~~~~INSECT BAT~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "ID-Number of bat: " << myInsectBat1.getIdBat() << std::endl;
    std::cout << "Name: " << myInsectBat1.getName() << std::endl;
    std::cout << "Flight time in meters: " << myInsectBat1.getFlightTime() << std::endl;
    std::cout << "Birthday of bat: " << myInsectBat1.getBirthday() << std::endl;
    std::cout << "Number of meals per day: " << myInsectBat1.getNumberOfMeals() << std::endl;
    std::cout << "Number of sleep cycles per day: " << myInsectBat1.getNumberOfSleepCycles() << std::endl;
    std::cout << "Gender of bat: " << myInsectBat1.getGender() << std::endl;
    std::cout << "Length of winter hibernation: " << myInsectBat1.getWinterHibernation() << std::endl;
    std::cout << "Nickname: " << myInsectBat1.getNickname() << std::endl;
    std::cout << "Bat size in centimeters: " << myInsectBat1.getsSize() << std::endl;
    std::cout << "Type of bat: " << myInsectBat1.getType() << std::endl;
    std::cout << "Food weight: " << myInsectBat1.getFoodWeight() << std::endl;
    std::cout << "Type insect food: " << myInsectBat1.getTypeInsectFood() << std::endl;
    std::cout << "Amount insects: " << myInsectBat1.getAmountOfInsect() << std::endl;
    
    std::cout << "Input number of interaction: " << std::endl;
    std::cin >> contr;
    }

    if (contr == 6){                                                                                //Если подается 6, то выводится каждое оформленное поле формы фруктовй летучей мыши и ввод команды
    std::cout << "~~~~~~~~~~~~~~~BLOOD BAT~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "ID-Number of bat: " << myBloodBat1.getIdBat() << std::endl;
    std::cout << "Name: " << myBloodBat1.getName() << std::endl;
    std::cout << "Flight time in meters: " << myBloodBat1.getFlightTime() << std::endl;
    std::cout << "Birthday of bat: " << myBloodBat1.getBirthday() << std::endl;
    std::cout << "Number of meals per day: " << myBloodBat1.getNumberOfMeals() << std::endl;
    std::cout << "Number of sleep cycles per day: " << myBloodBat1.getNumberOfSleepCycles() << std::endl;
    std::cout << "Gender of bat: " << myBloodBat1.getGender() << std::endl;
    std::cout << "Length of winter hibernation: " << myBloodBat1.getWinterHibernation() << std::endl;
    std::cout << "Nickname: " << myBloodBat1.getNickname() << std::endl;
    std::cout << "Bat size in centimeters: " << myBloodBat1.getsSize() << std::endl;
    std::cout << "Type of bat: " << myBloodBat1.getType() << std::endl;
    std::cout << "Food weight: " << myBloodBat1.getFoodWeight() << std::endl;
    std::cout << "Type blood: " << myBloodBat1.getTypeBlood() << std::endl;
    std::cout << "Amount blood (in ml): " << myBloodBat1.getAmountOfBlood() << std::endl;
   
    std::cout << "Input number of interaction: " << std::endl;
    std::cin >> contr;
    }
}while (contr != 7);                                                                                //Если подается 7, то программа завершается
    std::cout << "PROGRAM ENDED" << std::endl;
    return 0;
}
