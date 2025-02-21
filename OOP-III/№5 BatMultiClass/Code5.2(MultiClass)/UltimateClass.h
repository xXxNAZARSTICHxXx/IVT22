///Стич Назар Иванович ИВТ-22
///Файл мультикласса
#ifndef ULTIMATECLASS_H
#define ULTIMATECLASS_H

#include <iostream>                                                                                           //Подключение библиотеки iosteam
#include <string>                                                                                             //Подключение библиотеки string
#include <cassert>                                                                                            //Подключение библиотеки cassert

class Bat {                                                                                                   ///Класс летучих мышей

public:                                                                                                       ///Открытая зона класса

Bat() : IdBat(0), Name(""), FlightTime(0), Birthday(""), NumberOfMeals(0),                                    //Пустой шаблон летучей мыши без аргументов
        NumberOfSleepCycles(0), Gender(false), WinterHibernation(0),
        Nickname(""), sSize(0.0), Type(""), FoodWeight(0.0) { }
                                                                                                            
Bat(int id, const std::string& name, int flightTime, const std::string& birthday,                             //Пустой шаблон летучей мыши с аргументами
    int numberOfMeals, int NumberOfSleepCycles, bool gender, int winterHibernation, 
    const std::string& nickname, double size, const std::string& type, double foodWeight)
    : IdBat(id), Name(name), FlightTime(flightTime), Birthday(birthday), 
      NumberOfMeals(numberOfMeals), NumberOfSleepCycles(NumberOfSleepCycles), Gender(gender), 
      WinterHibernation(winterHibernation), Nickname(nickname), 
      sSize(size), Type(type), FoodWeight(foodWeight)
{ }



    
    int getIdBat() const;                                                                                     ///Метод получения ID летучей мыши
    std::string getName() const;                                                                              ///Метод получения имени летучей мыши
    int getFlightTime() const;                                                                                ///Метод получения длины полета летучей мыши в метрах
    std::string getBirthday() const;                                                                          ///Метод получения даты для рождения летучей мыши
    int getNumberOfMeals() const;                                                                             ///Метод получения кол-ва приемов пищи
    int getNumberOfSleepCycles() const;                                                                       ///Метод получения кол-ва циклов сна за день
    std::string getGender() const;                                                                            ///Метод получения пола летчей мыши
    int getWinterHibernation() const;                                                                         ///Метод получения длины зимней спячки в днях
    std::string getNickname() const;                                                                          ///Метод получения клички летучей мыши
    double getsSize() const;                                                                                  ///Метод получения размера летучей мыши
    std::string getType() const;                                                                              ///Метод получения типа вида летучей мыши
    double getFoodWeight() const;                                                                             ///Метод получения веса съеденой еды

    void setIdBat( int newIdBat);                                                                             ///Метод заполения ID летучей мыши
    void setName( std::string newName);                                                                       ///Метод заполения имени летучей мыши
    void setFlightTime( int newFlightTime);                                                                   ///Метод заполения длины полета летучей мыши в метрах
    void setBirthday( std::string newBirthday);                                                               ///Метод заполения даты для рождения летучей мыши
    void setNumberOfMeals( int newNumberOfMeals);                                                             ///Метод заполения кол-ва приемов пищи
    void setNumberOfSleepCycles( int newNumberOfSleepCycles);                                                 ///Метод заполения кол-ва циклов сна за день
    void setGender( bool newGender);                                                                          ///Метод заполения пола летчей мыши
    void setWinterHibernation( int newWinterHibernation);                                                     ///Метод заполения длины зимней спячки в днях
    void setNickname( std::string newNickname);                                                               ///Метод заполения клички летучей мыши
    void setsSize( double newsSize);                                                                          ///Метод заполения размера летучей мыши
    void setType( std::string newType);                                                                       ///Метод заполения типа вида летучей мыши
    void setFoodWeight( double newFoodWeight);                                                                ///Метод заполения веса съеденой еды

    virtual void inputBatData() {                                                                             ///Виртуальный метод для ввода всех классов полей для летучей мыши (n-ого) класса с проверкой некторых полей на отрицательное значение     
        std::cout << "Input of ID-Number bat: " << std::endl;                                                 //Вывод строки                                                        
        std::cin >> IdBat;                                                                                    //Ввод IdBat
        std::cout << "Input of name bat: " << std::endl;                                                      //Вывод строки 
        std::cin >> Name;                                                                                     //Ввод Name
        std::cout << "Input of flight time in meters bat: " << std::endl;                                     //Вывод строки 
        do
        std::cin >> FlightTime;                                                                               //Ввод FlightTime
        while (FlightTime<=0);                                                                                //Цикл с постусловием на проверку меньше или равно 0
        std::cout << "Input of date of birth bat: " << std::endl;                                             //Вывод строки 
        std::cin >> Birthday;                                                                                 //Ввод Birthday
        std::cout << "Input of number meals bat: " << std::endl;                                              //Вывод строки 
        do
        std::cin >> NumberOfMeals;                                                                            //Ввод NumberOfMeals
        while (NumberOfMeals<=0);                                                                             //Цикл с постусловием на проверку меньше или равно 0
        std::cout << "Input of number of sleep cycles bat: " << std::endl;                                    //Вывод строки 
        do
        std::cin >> NumberOfSleepCycles;                                                                      //Ввод NumberOfSleepCycles
        while (NumberOfMeals<=0);                                                                             //Цикл с постусловием на проверку меньше или равно 0
        std::cout << "Input of gender bat (1 - male, 0 - female): " << std::endl;                             //Вывод строки 
        std::cin >> Gender;                                                                                   //Ввод Gender
        std::cout << "Input count of winter hibernation cycles bat: " << std::endl;                           //Вывод строки 
        do
        std::cin >> WinterHibernation;                                                                        //Ввод WinterHibernation
        while (WinterHibernation<0);                                                                          //Цикл с постусловием на проверку меньше или равно 0
        std::cout << "Input of nickname bat: " << std::endl;                                                  //Вывод строки 
        std::cin >> Nickname;                                                                                 //Ввод Nickname
        std::cout << "Input size of bat in cm: " << std::endl;                                                //Вывод строки 
        do
        std::cin >> sSize;                                                                                    //Ввод sSize
        while (sSize<=0);                                                                                     //Цикл с постусловием на проверку меньше или равно 0
        std::cout << "Input type of bat: " << std::endl;                                                      //Вывод строки 
        std::cin >> Type;                                                                                     //Ввод Type
        std::cout << "Input food weight which bat eated: " << std::endl;                                      //Вывод строки 
        do
        std::cin >> FoodWeight;                                                                               //Ввод FoodWeight
        while (FoodWeight<=0);                                                                                //Цикл с постусловием на проверку меньше или равно 0
    }

    // todo2: to string assert
    virtual std::string toString() const {                                                                      ///Виртуальный метод для вывода всех классов полей для летучей мыши (n-ого) класса
        return "\nID: " + std::to_string(IdBat) +                                                               //Создание строки с полем ID и его значением                         
               "\nName: " + Name +                                                                              //Создание строки с полем Name и его значением и соединение с предыдущей строкой
               "\nFlightTime: " + std::to_string(FlightTime) +                                                  //Создание строки с полем FlightTime и его значением и соединение с предыдущей строкой
               "\nBirthday: " + Birthday +                                                                      //Создание строки с полем Birthday и его значением и соединение с предыдущей строкой
               "\nNumberOfMeals: " + std::to_string(NumberOfMeals) +                                            //Создание строки с полем NumberOfMeals и его значением и соединение с предыдущей строкой
               "\nNumberOfSleepCycles: " + std::to_string(NumberOfSleepCycles) +                                //Создание строки с полем NumberOfSleepCycles и его значением и соединение с предыдущей строкой
               "\nGender: " + (Gender ? "Male" : "Female") +                                                    //Создание строки с полем Gender и его значением и соединение с предыдущей строкой
               "\nWinterHibernation: " + std::to_string(WinterHibernation) +                                    //Создание строки с полем WinterHibernation и его значением и соединение с предыдущей строкой
               "\nNickname: " + Nickname +                                                                      //Создание строки с полем Nickname и его значением и соединение с предыдущей строкой
               "\nSize: " + std::to_string(sSize) +                                                             //Создание строки с полем Size и его значением и соединение с предыдущей строкой
               "\nType: " + Type +                                                                              //Создание строки с полем Type и его значением и соединение с предыдущей строкой
               "\nFoodWeight: " + std::to_string(FoodWeight);                                                   //Создание строки с полем FoodWeight и его значением и соединение с предыдущей строкой
    }


private:                                                                                                         ///Закрытое поле класса с полями
    int IdBat;                                                                                                   ///Поле - id летучей мыши
    std::string Name;                                                                                            ///Поле - имени летучей мыши
    int FlightTime;                                                                                              ///Поле - длины полета летучей мыши
    std::string Birthday;                                                                                        ///Поле - день рождения летучей мыши
    int NumberOfMeals;                                                                                           ///Поле - количество приемеов еды за день
    int NumberOfSleepCycles;                                                                                     ///Поле - количество циклов сна за день
    bool Gender;                                                                                                 ///Поле - пол летучей мыши
    int WinterHibernation;                                                                                       ///Поле - количество дней, когда летучая мышь находится в спячке
    std::string Nickname;                                                                                        ///Поле - кличка летучей мыши
    double sSize;                                                                                                ///Поле - размер летучей мыши
    std::string Type;                                                                                            ///Поле - вид летучей мыши
    double FoodWeight;                                                                                           ///Поле - веса съеденой еды
};


//todo переименовать подклассы по смыслу!!
class InsectBat : public Bat {                                                                                   ///Подкласс насекомоядных летучих мышей                                                     
public:

    InsectBat() : Bat(0, "", 0, "", 0, 0, false, 0, "", 0.0, "", 0.0), TypeInsectFood(""), AmountOfInsect(0) {}  ///Пустой шаблон насекомоядной летучей мыши без аргументов

    InsectBat(int id, const std::string& name, int flightTime, const std::string& birthday,                      ///Пустой шаблон насекомоядной летучей мыши с аргументами
              int numberOfMeals, int NumberOfSleepCycles, bool gender, int winterHibernation,
              const std::string& nickname, double size, const std::string& type, double foodWeight,
              const std::string& typeInsectFood, int amountOfInsect)
        :Bat(id, name, flightTime, birthday, numberOfMeals, NumberOfSleepCycles, gender, winterHibernation,nickname, size, type, foodWeight),
        TypeInsectFood(typeInsectFood),AmountOfInsect(amountOfInsect) {}



    std::string getTypeInsectFood() const;                                                                       ///Метод получения типа еды, которую ест насекомоядная летучая мышь
    int getAmountOfInsect() const;                                                                               ///Метод получения кол-ва еды, едениц, которые съест летучая мышь за один прием пищи
    void setTypeInsectFood(const std::string& newTypeInsectFood);                                                ///Метод присвоения типа еды, которую ест насекомоядная летучая мышь
    void setAmountOfInsect(int newAmountOfInsect);                                                               ///Метод присвоения кол-ва еды, едениц, которые съест летучая мышь за один прием пищи

    void inputBatData() override {                                                                               ///Перегруженный метод ввода полей подкласса с классом насекомоядной летучей мыши с проверкой некторых полей на отрицательное значение
        Bat::inputBatData();                                                                                     //Наследование класса летучих мышей 
        std::cout << "Input type of insect food: " << std::endl;                                                 //Вывод строки "Input type of insect food: "
        std::cin >> TypeInsectFood;                                                                              //Ввод TypeInsectFood
        std::cout << "Input count of insects: " << std::endl;                                                    //Вывод строки "Input count of insects: "
        do {            
            std::cin >> AmountOfInsect;                                                                          //Ввод AmountOfInsect
        } while (AmountOfInsect < 0);                                                                            //Цикл с постусловием на проверку меньше или равно 0
    }

    std::string toString() const override {                                                                      ///Перегруженный метод вывода полей подкласса с классом насекомоядной летучей мыши
        return "InsectBat: " + Bat::toString() +                                                                 //Создание строки с началом "InsectBat: " с конструкцией Bat
               "\nTypeInsectFood: " + TypeInsectFood +                                                           //Создание строки с полем TypeInsectFood и его значением и соединение с предыдущей строкой
               "\nAmountOfInsect: " + std::to_string(AmountOfInsect);                                            //Создание строки с полем AmountOfInsect и его значением и соединение с предыдущей строкой
    }

    bool operator==(const InsectBat& other) const {                                                              ///Перегруженный оператор присваивания ==                      
    return getIdBat() == other.getIdBat() &&                                                                     //Возвращает IdBat через перегркженный оператор
           getName() == other.getName() &&                                                                       //Возвращает Name через перегркженный оператор
           getFlightTime() == other.getFlightTime() &&                                                           //Возвращает FlightTime через перегркженный оператор
           getBirthday() == other.getBirthday() &&                                                               //Возвращает Birthday через перегркженный оператор
           getNumberOfMeals() == other.getNumberOfMeals() &&                                                     //Возвращает NumberOfMeals через перегркженный оператор
           getNumberOfSleepCycles() == other.getNumberOfSleepCycles() &&                                         //Возвращает NumberOfSleepCycles через перегркженный оператор
           getGender() == other.getGender() &&                                                                   //Возвращает Gender через перегркженный оператор
           getWinterHibernation() == other.getWinterHibernation() &&                                             //Возвращает WinterHibernation через перегркженный оператор
           getNickname() == other.getNickname() &&                                                               //Возвращает Nickname через перегркженный оператор
           getsSize() == other.getsSize() &&                                                                     //Возвращает sSize через перегркженный оператор
           getType() == other.getType() &&                                                                       //Возвращает Type через перегркженный оператор
           getFoodWeight() == other.getFoodWeight() &&                                                           //Возвращает FoodWeight через перегркженный оператор
           TypeInsectFood == other.getTypeInsectFood() &&                                                        //Возвращает TypeInsectFood через перегркженный оператор
           AmountOfInsect == other.getAmountOfInsect();                                                          //Возвращает AmountOfInsect через перегркженный оператор
}

private:                                                                                                         ///Закрытое поле класса
    std::string TypeInsectFood;                                                                                  ///Поле - тип(вид) насекомых
    int AmountOfInsect;                                                                                          ///Поле - кол-ва еды, едениц, которые съест летучая мышь за один прием пищи 
};


class FruitsBat : public Bat {                                                                                   ///Подкласс фруктовых летучих мышей
public:                                                                                                          ///Открытое поле класса
    FruitsBat() : Bat(), TypeFruitFood(""), AmountOfFruits(0) {}                                                 ///Пустой фруктовой насекомоядной летучей мыши без аргументов

    std::string getTypeFruitFood() const;                                                                        ///Метод получения типа еды, которую ест фруктовая летучая мышь
    int getAmountOfFruits() const;                                                                               ///Метод получения кол-ва еды, едениц, которые съест фруктовая летучая мышь за один прием пищи
    void setTypeFruitFood(const std::string& newTypeFruitFood);                                                  ///Метод присвоения типа еды, которую ест фруктовая летучая мышь
    void setAmountOfFruits(int newAmountOfFruits);                                                               ///Метод присвоения кол-ва еды, едениц, которые съест фруктовая летучая мышь за один прием пищи

    void inputBatData() override {                                                                               ///Перегруженный метод ввода полей подкласса с классом фруктовой летучей мыши с проверкой некторых полей на отрицательное значение
        Bat::inputBatData();                                                                                     //Наследование класса летучих мышей                                                                     
        std::cout << "Input type of fruit food: " << std::endl;                                                  //Вывод строки "Input type of fruit food: "
        std::cin >> TypeFruitFood;                                                                               //Ввод TypeFruitFood
        std::cout << "Input count of fruits: " << std::endl;                                                     //Вывод строки "Input count of fruits: "
        do
        std::cin >> AmountOfFruits;                                                                              //Ввод AmountOfFruits
        while (AmountOfFruits<=0);                                                                               //Цикл с постусловием на проверку меньше или равно 0
    }

    std::string toString() const override {                                                                      ///Перегруженный метод вывода полей подкласса с классом фруктовой летучей мыши
        return "FruitsBat: " + Bat::toString() +                                                                 //Создание строки с началом "InsectBat: " с конструкцией Bat
               "\nTypeFruitFood: " + TypeFruitFood +                                                             //Создание строки с полем TypeFruitFood и его значением и соединение с предыдущей строкой
               "\nAmountOfFruits: " + std::to_string(AmountOfFruits);                                            //Создание строки с полем AmountOfFruits и его значением и соединение с предыдущей строкой
    }

private:                                                                                                         ///Закрытое поле класса
    std::string TypeFruitFood;                                                                                   ///Поле - тип(вид) фруктов
    int AmountOfFruits;                                                                                          ///Поле - кол-ва еды, едениц, которые съест фруктовая летучая мышь за один прием пищи
};


class BloodBat : public Bat {                                                                                    ///Подкласс кровососущих летучих мышей
public:                                                                                                          ///Открытое поле класса
    BloodBat() : Bat(), TypeBlood(""), AmountOfBlood(0.0) {}                                                     ///Пустой фруктовой кровососущей летучей мыши без аргументов

    std::string getTypeBlood() const;                                                                            ///Метод получения типа крови, которую употребляет кровососущая летучая мышь
    double getAmountOfBlood() const;                                                                             ///Метод получения объема употребленной крови кровососущей летучей мыши
    void setTypeBlood(const std::string& newTypeBlood);                                                          ///Метод присвоения типа крови, которую употребляет кровососущая летучая мышь
    void setAmountOfBlood(double newAmountOfBlood);                                                              ///Метод присвоения объема употребленной крови кровососущей летучей мыши

    void inputBatData() override {                                                                               ///Перегруженный метод ввода полей подкласса с классом кровососущей летучей мыши
        Bat::inputBatData();                                                                                     //С проверкой некторых полей на отрицательное значение   
        std::cout << "Input type of blood: " << std::endl;                                                       //Вывод строки "Input type of blood: "
        std::cin >> TypeBlood;                                                                                   //Ввод TypeBlood
        std::cout << "Input amount of blood: " << std::endl;                                                     //Вывод строки "Input amount of blood: "
        do
        std::cin >> AmountOfBlood;                                                                               //Ввод AmountOfBlood
        while (AmountOfBlood<=0);                                                                                //Цикл с постусловием на проверку меньше или равно 0
    }

    std::string toString() const override {                                                                      ///Перегруженный метод вывода полей подкласса с классом кровососущей летучей мыши
        return "BloodBat: " + Bat::toString() +                                                                  //Создание строки с началом "InsectBat: " с конструкцией Bat
               "\nTypeBlood: " + TypeBlood +                                                                     //Создание строки с полем TypeBlood и его значением и соединение с предыдущей строкой
               "\nAmountOfBlood: " + std::to_string(AmountOfBlood);                                              //Создание строки с полем AmountOfBlood и его значением и соединение с предыдущей строкой
    }

private:                                                                                                         ///Закрытое поле класса
    std::string TypeBlood;                                                                                       ///Поле - типа крови
    double AmountOfBlood;                                                                                        ///Поле - объема употребленной крови
};

void assertInsectCheck(Bat* InsBat);                                                                             ///Функция assert-проверки ввода данных по заполненному шаблону Insect Bat
void assertInsectBatCheck();                                                                                     //Функция assert-проверки ввода данных по полям шаблона Insect Bat
void assertFruitBatCheck();                                                                                      //Функция assert-проверки ввода данных по полям шаблона Fruit Bat
void assertBloodBatCheck();                                                                                      //Функция assert-проверки ввода данных по полям шаблона Blood Bat
void VirtualCheck();
#endif
