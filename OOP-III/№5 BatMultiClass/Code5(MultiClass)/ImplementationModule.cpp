///Стич Назар Иванович ИВТ-22
///Файл содержащий реализации методов мультикласса
#include <iostream>                                 //Подключение библиотеки iostream для взаимодействия с консолью
#include "UltimateClass.h"                          //Подключение собственной библиотеки класса UltimateClass.h

    int Bat::getIdBat() const {                                                     ///Метод получения ID летучей мыши
        return IdBat;                                                               //Возвращает IdBat
    }

    std::string Bat::getName() const {                                              ///Метод получения имени летучей мыши
        return Name;                                                                //Возвращает Name
    }

    int Bat::getFlightTime() const {                                                ///Метод получения длины полета летучей мыши в метрах
        return FlightTime;                                                          //Возвращает FlightTime
    }

    std::string Bat::getBirthday() const {                                          ///Метод получения даты для рождения летучей мыши
        return Birthday;                                                            //Возвращает Birthday
    }

    short Bat::getNumberOfMeals() const {                                           ///Метод получения кол-ва приемов пищи
        return NumberOfMeals;                                                       //Возвращает NumberOfMeals
    }

    short Bat::getNumberOfSleepCycles() const {                                     ///Метод получения кол-ва циклов сна за день
        return NumberOfSleepCycles;                                                 //Возвращает NumberOfSleepCycles
    }

    std::string Bat::getGender() const {                                            ///Метод получения пола летчей мыши
        if (Gender == true){                                                        //Если значение gender = 1
            return "Male";                                                          //Возвращает сторку "Male"
        }
        else{                                                                       //Иначе
        return "Female";                                                            //Возвращает сторку "Female"
        }
    }

    short Bat::getWinterHibernation() const {                                       ///Метод получения длины зимней спячки в днях
        return WinterHibernation;                                                   //Возвращает WinterHibernation
    }

    std::string Bat::getNickname() const {                                          ///Метод получения клички летучей мыши
        return Nickname;                                                            //Возвращает Nickname
    }

    float Bat::getsSize() const {                                                   ///Метод получения размера летучей мыши
        return sSize;                                                               //Возвращает sSize
    }

    std::string Bat::getType() const {                                              ///Метод получения типа вида летучей мыши
        return Type;                                                                //Возвращает Type
    }

    float Bat::getFoodWeight() const {                                              ///Метод получения веса съеденой еды
        return FoodWeight;                                                          //Возвращает FoodWeight
    }



    void Bat::setIdBat(const int& newIdBat) {                                       ///Метод заполения ID летучей мыши
        IdBat = newIdBat;                                                           //Присваевает newIdBat к IdBat
    }

    void Bat::setName(const std::string& newName) {                                 ///Метод заполения имени летучей мыши
        Name = newName;                                                             //Присваевает newName к Name
    }

    void Bat::setFlightTime(const int& newFlightTime) {                             ///Метод заполения длины полета летучей мыши в метрах
        //todo убрать ВЕЗДЕ ссылки и const И сделать проверку на отрицательное значение
        FlightTime = newFlightTime;                                                 //Присваевает newFlightTime к FlightTime
    }

    void Bat::setBirthday(const std::string& newBirthday) {                         ///Метод заполения даты для рождения летучей мыши
        Birthday = newBirthday;                                                     //Присваевает newBirthday к Birthday
    }

    void Bat::setNumberOfMeals(const short& newNumberOfMeals) {                     ///Метод заполения кол-ва приемов пищи
        NumberOfMeals = newNumberOfMeals;                                           //Присваевает newNumberOfMeals к NumberOfMeals
    }

    void Bat::setNumberOfSleepCycles(const short& newNumberOfSleepCycles) {         ///Метод заполения кол-ва циклов сна за день
        NumberOfSleepCycles = newNumberOfSleepCycles;                               //Присваевает newNumberOfSleepCycles к NumberOfSleepCycles
    }

    void Bat::setGender(const bool& newGender) {                                    ///Метод заполения пола летчей мыши
        Gender = newGender;                                                         //Присваевает newGender к Gender
    }

    void Bat::setWinterHibernation(const short& newWinterHibernation) {             ///Метод заполения длины зимней спячки в днях
        WinterHibernation = newWinterHibernation;                                   //Присваевает newWinterHibernation к WinterHibernation
    }

    void Bat::setNickname(const std::string& newNickname) {                         ///Метод заполения клички летучей мыши
        Nickname = newNickname;                                                     //Присваевает newNickname к Nickname
    }

    void Bat::setsSize(const float& newsSize) {                                     ///Метод заполения размера летучей мыши
        sSize = newsSize;                                                           //Присваевает newsSize к sSize
    }

    void Bat::setType(const std::string& newType) {                                 ///Метод заполения типа вида летучей мыши
        Type = newType;                                                             //Присваевает newType к Type

    void Bat::setFoodWeight(const float& newFoodWeight) {                           ///Метод заполения веса съеденой еды
        FoodWeight = newFoodWeight;                                                 //Присваевает newFoodWeight к FoodWeight
    }

    std::string Insect::getTypeInsectFood() const {                                 ///Метод получения видов насекомых употребляемых в пищу
        return TypeInsectFood;                                                      //Возвращает TypeInsectFood
    }

    short Insect::getAmountOfInsect() const {                                       ///Метод получения кол-во насекомых употребляемых в пищу
        return AmountOfInsect;                                                      //Возвращает AmountOfInsect
    }

    void Insect::setTypeInsectFood(const std::string& newTypeInsectFood) {          ///Метод заполнения видов насекомых употребляемых в пищу
        TypeInsectFood = newTypeInsectFood;                                         //Присваевает newTypeInsectFood к TypeInsectFood
    }

    void Insect::setAmountOfInsect(const short& newAmountOfInsect) {                ///Метод заполнения кол-во насекомых употребляемых в пищу
        AmountOfInsect = newAmountOfInsect;                                         //Присваевает newAmountOfInsect к AmountOfInsect
    }

    std::string Fruits::getTypeFruitFood() const {                                  ///Метод получения видов фруктов употребляемых в пищу
        return TypeFruitFood;                                                       //Возвращает TypeFruitFood
    }

    short Fruits::getAmountOfFruits() const {                                       ///Метод получения кол-во фруктов употребляемых в пищу
        return AmountOfFruits;                                                      //Возвращает AmountOfFruits
    }

    void Fruits::setTypeFruitFood(const std::string& newTypeFruitFood) {            ///Метод заполнения видов фруктов употребляемых в пищу
        TypeFruitFood = newTypeFruitFood;                                           //Присваевает newTypeFruitFood к TypeFruitFood
    }

    void Fruits::setAmountOfFruits(const short& newAmountOfFruits) {                ///Метод заполнения кол-во фруктов употребляемых в пищу
        AmountOfFruits = newAmountOfFruits;                                         //Присваевает newAmountOfFruits к AmountOfFruits
    }

    std::string Blood::getTypeBlood() const {                                       ///Метод получения видов крови употребляемой в пищу
        return TypeBlood;                                                           //Возвращает TypeBlood
    }

    float Blood::getAmountOfBlood() const {                                         ///Метод получения кол-во крови употребляемой в пищу
        return AmountOfBlood;                                                       //Возвращает AmountOfBlood
    }

    void Blood::setTypeBlood(const std::string& newTypeBlood) {                     ///Метод заполнения видов крови употребляемой в пищу
        TypeBlood = newTypeBlood;                                                   //Присваевает newTypeBlood к TypeBlood
    }

    void Blood::setAmountOfBlood(const float& newAmountOfBlood) {                   ///Метод заполнения кол-во крови употребляемой в пищу
        AmountOfBlood = newAmountOfBlood;                                           //Присваевает newAmountOfBlood к AmountOfBlood
    }
