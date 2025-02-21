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



    
    int getIdBat();                                                                                           ///Метод получения ID летучей мыши
    std::string getName();                                                                                    ///Метод получения имени летучей мыши
    int getFlightTime();                                                                                      ///Метод получения длины полета летучей мыши в метрах
    std::string getBirthday();                                                                                ///Метод получения даты для рождения летучей мыши
    int getNumberOfMeals();                                                                                   ///Метод получения кол-ва приемов пищи
    int getNumberOfSleepCycles();                                                                             ///Метод получения кол-ва циклов сна за день
    std::string getGender();                                                                                  ///Метод получения пола летчей мыши
    int getWinterHibernation();                                                                               ///Метод получения длины зимней спячки в днях
    std::string getNickname();                                                                                ///Метод получения клички летучей мыши
    double getsSize();                                                                                        ///Метод получения размера летучей мыши
    std::string getType();                                                                                    ///Метод получения типа вида летучей мыши
    double getFoodWeight();                                                                                   ///Метод получения веса съеденой еды

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

    virtual void inputBatData() {                                                                             ///Виртуальный метод для ввода всех классов полей для летучей мыши (n-ого) класса
        std::cout << "Input of ID-Number bat: " << std::endl;                                                 //С проверкой некторых полей на отрицательное значение                                               
        std::cin >> IdBat;                                                                                   
        std::cout << "Input of name bat: " << std::endl;                                                      
        std::cin >> Name;                                                                                     
        std::cout << "Input of flight time in meters bat: " << std::endl;
        do
        std::cin >> FlightTime;
        while (FlightTime<=0);
        std::cout << "Input of date of birth bat: " << std::endl;
        std::cin >> Birthday;
        std::cout << "Input of number meals bat: " << std::endl;
        do
        std::cin >> NumberOfMeals;
        while (NumberOfMeals<=0);
        std::cout << "Input of number of sleep cycles bat: " << std::endl;
        do
        std::cin >> NumberOfSleepCycles;
        while (NumberOfMeals<=0);
        std::cout << "Input of gender bat (1 - male, 0 - female): " << std::endl;
        std::cin >> Gender;
        std::cout << "Input count of winter hibernation cycles bat: " << std::endl;
        do
        std::cin >> WinterHibernation;
        while (WinterHibernation<0);
        std::cout << "Input of nickname bat: " << std::endl;
        std::cin >> Nickname;
        std::cout << "Input size of bat in cm: " << std::endl;
        do
        std::cin >> sSize;
        while (sSize<=0);
        std::cout << "Input type of bat: " << std::endl;
        std::cin >> Type;
        std::cout << "Input food weight which bat eated: " << std::endl;
        do
        std::cin >> FoodWeight;
        while (FoodWeight<=0);
    }

    // todo2: to string assert
    virtual std::string toString() const {                                                                      ///Виртуальный метод для вывода всех классов полей для летучей мыши (n-ого) класса
        return "\nID: " + std::to_string(IdBat) +                                                               
               "\nName: " + Name +
               "\nFlightTime: " + std::to_string(FlightTime) +
               "\nBirthday: " + Birthday +
               "\nNumberOfMeals: " + std::to_string(NumberOfMeals) +
               "\nNumberOfSleepCycles: " + std::to_string(NumberOfSleepCycles) +
               "\nGender: " + (Gender ? "Male" : "Female") +
               "\nWinterHibernation: " + std::to_string(WinterHibernation) +
               "\nNickname: " + Nickname +
               "\nSize: " + std::to_string(sSize) +
               "\nType: " + Type +
               "\nFoodWeight: " + std::to_string(FoodWeight);
    }

const int& getIdBat() const { return IdBat; }                                                                    ///Возврат константных ссылок - для того, чтобы объект остался без изменений
const std::string& getName() const { return Name; }
int getFlightTime() const { return FlightTime; }
const std::string& getBirthday() const { return Birthday; }
int getNumberOfMeals() const { return NumberOfMeals; }
int getNumberOfSleepCycles() const { return NumberOfSleepCycles; }
const bool getGender() const { return Gender; }
int getWinterHibernation() const { return WinterHibernation; }
const std::string& getNickname() const { return Nickname; }
double getsSize() const { return sSize; }
const std::string& getType() const { return Type; }
double getFoodWeight() const { return FoodWeight; }

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

    void inputBatData() override {                                                                               ///Перегруженный метод ввода полей подкласса с классом насекомоядной летучей мыши
        Bat::inputBatData();                                                                                     //С проверкой некторых полей на отрицательное значение 
        std::cout << "Input type of insect food: " << std::endl;
        std::cin >> TypeInsectFood;
        std::cout << "Input count of insects: " << std::endl;
        do {
            std::cin >> AmountOfInsect;
        } while (AmountOfInsect < 0);
    }

    std::string toString() const override {                                                                      ///Перегруженный метод вывода полей подкласса с классом насекомоядной летучей мыши
        return "InsectBat: " + Bat::toString() +
               "\nTypeInsectFood: " + TypeInsectFood +
               "\nAmountOfInsect: " + std::to_string(AmountOfInsect);
    }

    bool operator==(const InsectBat& other) const {                                                              ///Перегруженный оператор присваивания ==                      
    return getIdBat() == other.getIdBat() &&
           getName() == other.getName() &&
           getFlightTime() == other.getFlightTime() &&
           getBirthday() == other.getBirthday() &&
           getNumberOfMeals() == other.getNumberOfMeals() &&
           getNumberOfSleepCycles() == other.getNumberOfSleepCycles() &&
           getGender() == other.getGender() &&
           getWinterHibernation() == other.getWinterHibernation() &&
           getNickname() == other.getNickname() &&
           getsSize() == other.getsSize() &&
           getType() == other.getType() &&
           getFoodWeight() == other.getFoodWeight() &&
           TypeInsectFood == other.getTypeInsectFood() &&
           AmountOfInsect == other.getAmountOfInsect();
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

    void inputBatData() override {                                                                               ///Перегруженный метод ввода полей подкласса с классом фруктовой летучей мыши
        Bat::inputBatData();                                                                                     //С проверкой некторых полей на отрицательное значение                                                                     
        std::cout << "Input type of fruit food: " << std::endl;                                                 
        std::cin >> TypeFruitFood;
        std::cout << "Input count of fruits: " << std::endl;
        do
        std::cin >> AmountOfFruits;
        while (AmountOfFruits<=0);
    }

    std::string toString() const override {                                                                      ///Перегруженный метод вывода полей подкласса с классом фруктовой летучей мыши
        return "FruitsBat: " + Bat::toString() +
               "\nTypeFruitFood: " + TypeFruitFood +
               "\nAmountOfFruits: " + std::to_string(AmountOfFruits);
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
        std::cout << "Input type of blood: " << std::endl;
        std::cin >> TypeBlood;
        std::cout << "Input amount of blood: " << std::endl;
        do
        std::cin >> AmountOfBlood;
        while (AmountOfBlood<=0);
    }

    std::string toString() const override {                                                                      ///Перегруженный метод вывода полей подкласса с классом кровососущей летучей мыши
        return "BloodBat: " + Bat::toString() +
               "\nTypeBlood: " + TypeBlood +
               "\nAmountOfBlood: " + std::to_string(AmountOfBlood);
    }

private:                                                                                                         ///Закрытое поле класса
    std::string TypeBlood;                                                                                       ///Поле - типа крови
    double AmountOfBlood;                                                                                        ///Поле - объема употребленной крови
};

void assertInsectCheck(Bat* InsBat);                                                                             ///Функция assert-проверки ввода данных

#endif
