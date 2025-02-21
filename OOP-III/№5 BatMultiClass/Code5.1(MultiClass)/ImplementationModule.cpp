///Стич Назар Иванович ИВТ-22
///Файл содержащий реализации методов мультикласса
#include <iostream>                                 //Подключение библиотеки iostream для взаимодействия с консолью
#include "UltimateClass.h"                          //Подключение собственной библиотеки класса UltimateClass.h

    int Bat::getIdBat() {                                                           ///Метод получения ID летучей мыши
        return IdBat;                                                               //Возвращает IdBat
    }

    std::string Bat::getName() {                                                    ///Метод получения имени летучей мыши
        return Name;                                                                //Возвращает Name
    }

    int Bat::getFlightTime() {                                                      ///Метод получения длины полета летучей мыши в метрах
        return FlightTime;                                                          //Возвращает FlightTime
    }

    std::string Bat::getBirthday() {                                                ///Метод получения даты для рождения летучей мыши
        return Birthday;                                                            //Возвращает Birthday
    }

    int Bat::getNumberOfMeals() {                                                   ///Метод получения кол-ва приемов пищи
        return NumberOfMeals;                                                       //Возвращает NumberOfMeals
    }

    int Bat::getNumberOfSleepCycles() {                                             ///Метод получения кол-ва циклов сна за день
        return NumberOfSleepCycles;                                                 //Возвращает NumberOfSleepCycles
    }

    std::string Bat::getGender() {                                                  ///Метод получения пола летчей мыши
        if (Gender == true){                                                        //Если значение gender = 1
            return "Male";                                                          //Возвращает сторку "Male"
        }
        else{                                                                       //Иначе
        return "Female";                                                            //Возвращает сторку "Female"
        }
    }

    int Bat::getWinterHibernation() {                                               ///Метод получения длины зимней спячки в днях
        return WinterHibernation;                                                   //Возвращает WinterHibernation
    }

    std::string Bat::getNickname() {                                                ///Метод получения клички летучей мыши
        return Nickname;                                                            //Возвращает Nickname
    }

    double Bat::getsSize() {                                                        ///Метод получения размера летучей мыши
        return sSize;                                                               //Возвращает sSize
    }

    std::string Bat::getType() {                                                    ///Метод получения типа вида летучей мыши
        return Type;                                                                //Возвращает Type
    }

    double Bat::getFoodWeight() {                                                   ///Метод получения веса съеденой еды
        return FoodWeight;                                                          //Возвращает FoodWeight
    }



    void Bat::setIdBat(int newIdBat) {                                              ///Метод заполения ID летучей мыши
        IdBat = newIdBat;                                                           //Присваевает newIdBat к IdBat
    }

    void Bat::setName(std::string newName) {                                        ///Метод заполения имени летучей мыши
        Name = newName;                                                             //Присваевает newName к Name
    }

    void Bat::setFlightTime(int newFlightTime) {                                    ///Метод заполения длины полета летучей мыши в метрах
        //todo убрать ВЕЗДЕ ссылки и const И сделать проверку на отрицательное значение
        FlightTime = newFlightTime;                                                 //Присваевает newFlightTime к FlightTime
    }

    void Bat::setBirthday(std::string newBirthday) {                                ///Метод заполения даты для рождения летучей мыши
        Birthday = newBirthday;                                                     //Присваевает newBirthday к Birthday
    }

    void Bat::setNumberOfMeals(int newNumberOfMeals) {                              ///Метод заполения кол-ва приемов пищи
        NumberOfMeals = newNumberOfMeals;                                           //Присваевает newNumberOfMeals к NumberOfMeals
    }

    void Bat::setNumberOfSleepCycles(int newNumberOfSleepCycles) {                  ///Метод заполения кол-ва циклов сна за день
        NumberOfSleepCycles = newNumberOfSleepCycles;                               //Присваевает newNumberOfSleepCycles к NumberOfSleepCycles
    }

    void Bat::setGender(bool newGender) {                                           ///Метод заполения пола летчей мыши
        Gender = newGender;                                                         //Присваевает newGender к Gender
    }

    void Bat::setWinterHibernation(int newWinterHibernation) {                      ///Метод заполения длины зимней спячки в днях
        WinterHibernation = newWinterHibernation;                                   //Присваевает newWinterHibernation к WinterHibernation
    }

    void Bat::setNickname(std::string newNickname) {                                ///Метод заполения клички летучей мыши
        Nickname = newNickname;                                                     //Присваевает newNickname к Nickname
    }

    void Bat::setsSize(double newsSize) {                                           ///Метод заполения размера летучей мыши
        sSize = newsSize;                                                           //Присваевает newsSize к sSize
    }

    void Bat::setType(std::string newType) {                                        ///Метод заполения типа вида летучей мыши
        Type = newType;                                                             //Присваевает newType к Type
    }
    void Bat::setFoodWeight(double newFoodWeight) {                                 ///Метод заполения веса съеденой еды
        FoodWeight = newFoodWeight;                                                 //Присваевает newFoodWeight к FoodWeight
    }

    std::string InsectBat::getTypeInsectFood() const {                              ///Метод получения видов насекомых употребляемых в пищу
        return TypeInsectFood;                                                      //Возвращает TypeInsectFood
    }

    int InsectBat::getAmountOfInsect() const {                                      ///Метод получения кол-во насекомых употребляемых в пищу
        return AmountOfInsect;                                                      //Возвращает AmountOfInsect
    }

    void InsectBat::setTypeInsectFood(const std::string& newTypeInsectFood) {       ///Метод заполнения видов насекомых употребляемых в пищу
        TypeInsectFood = newTypeInsectFood;                                         //Присваевает newTypeInsectFood к TypeInsectFood
    }

    void InsectBat::setAmountOfInsect(const int newAmountOfInsect) {                ///Метод заполнения кол-во насекомых употребляемых в пищу
        AmountOfInsect = newAmountOfInsect;                                         //Присваевает newAmountOfInsect к AmountOfInsect
    }

    std::string FruitsBat::getTypeFruitFood() const {                               ///Метод получения видов фруктов употребляемых в пищу
        return TypeFruitFood;                                                       //Возвращает TypeFruitFood
    }

    int FruitsBat::getAmountOfFruits() const {                                      ///Метод получения кол-во фруктов употребляемых в пищу
        return AmountOfFruits;                                                      //Возвращает AmountOfFruits
    }

    void FruitsBat::setTypeFruitFood(const std::string& newTypeFruitFood) {         ///Метод заполнения видов фруктов употребляемых в пищу
        TypeFruitFood = newTypeFruitFood;                                           //Присваевает newTypeFruitFood к TypeFruitFood
    }

    void FruitsBat::setAmountOfFruits(const int newAmountOfFruits) {                ///Метод заполнения кол-во фруктов употребляемых в пищу
        AmountOfFruits = newAmountOfFruits;                                         //Присваевает newAmountOfFruits к AmountOfFruits
    }

    std::string BloodBat::getTypeBlood() const {                                    ///Метод получения видов крови употребляемой в пищу
        return TypeBlood;                                                           //Возвращает TypeBlood
    }

    double BloodBat::getAmountOfBlood() const {                                     ///Метод получения кол-во крови употребляемой в пищу
        return AmountOfBlood;                                                       //Возвращает AmountOfBlood
    }

    void BloodBat::setTypeBlood(const std::string& newTypeBlood) {                  ///Метод заполнения видов крови употребляемой в пищу
        TypeBlood = newTypeBlood;                                                   //Присваевает newTypeBlood к TypeBlood
    }

    void BloodBat::setAmountOfBlood(const double newAmountOfBlood) {                ///Метод заполнения кол-во крови употребляемой в пищу
        AmountOfBlood = newAmountOfBlood;                                           //Присваевает newAmountOfBlood к AmountOfBlood
    }


    void assertInsectCheck(Bat* InsBat) {                                           ///Функция проверки ввода данных
    InsectBat* CheckInsectBat = new InsectBat(10000, "LavaWing", 5000, "04.08.1998", 4, 1, true, 105, "LavaLava", 42.5, "LongEared", 25.0, "Mosquitoes", 80);       //Заданный шаблон введенных данных
    assert(*static_cast<InsectBat*>(InsBat) == *CheckInsectBat);                    //Сравнение одинаковых шаблонов через статическое преобразование
    delete CheckInsectBat;                                                          //Освобождение памяти от CheckInsectBat
    }
