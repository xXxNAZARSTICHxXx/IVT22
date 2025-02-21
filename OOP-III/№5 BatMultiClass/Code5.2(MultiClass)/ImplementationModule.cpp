///Стич Назар Иванович ИВТ-22
///Файл содержащий реализации методов мультикласса
#include <iostream>                                 //Подключение библиотеки iostream для взаимодействия с консолью
#include "UltimateClass.h"                          //Подключение собственной библиотеки класса UltimateClass.h
#include <cassert>                                                                                            //Подключение библиотеки cassert
    //const методы не меняют поля класса
    int Bat::getIdBat() const {                                                           ///Метод получения ID летучей мыши
        return IdBat;                                                               //Возвращает IdBat
    }

    std::string Bat::getName() const {                                                    ///Метод получения имени летучей мыши
        return Name;                                                                //Возвращает Name
    }

    int Bat::getFlightTime() const {                                                      ///Метод получения длины полета летучей мыши в метрах
        return FlightTime;                                                          //Возвращает FlightTime
    }

    std::string Bat::getBirthday() const {                                                ///Метод получения даты для рождения летучей мыши
        return Birthday;                                                            //Возвращает Birthday
    }

    int Bat::getNumberOfMeals() const {                                                   ///Метод получения кол-ва приемов пищи
        return NumberOfMeals;                                                       //Возвращает NumberOfMeals
    }

    int Bat::getNumberOfSleepCycles() const {                                             ///Метод получения кол-ва циклов сна за день
        return NumberOfSleepCycles;                                                 //Возвращает NumberOfSleepCycles
    }

    std::string Bat::getGender() const {                                                  ///Метод получения пола летчей мыши
        if (Gender == true){                                                        //Если значение gender = 1
            return "Male";                                                          //Возвращает сторку "Male"
        }
        else{                                                                       //Иначе
        return "Female";                                                            //Возвращает сторку "Female"
        }
    }

    int Bat::getWinterHibernation() const {                                               ///Метод получения длины зимней спячки в днях
        return WinterHibernation;                                                   //Возвращает WinterHibernation
    }

    std::string Bat::getNickname() const {                                                ///Метод получения клички летучей мыши
        return Nickname;                                                            //Возвращает Nickname
    }

    double Bat::getsSize() const {                                                        ///Метод получения размера летучей мыши
        return sSize;                                                               //Возвращает sSize
    }

    std::string Bat::getType() const {                                                    ///Метод получения типа вида летучей мыши
        return Type;                                                                //Возвращает Type
    }

    double Bat::getFoodWeight() const {                                                   ///Метод получения веса съеденой еды
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

    void assertInsectBatCheck() {                                                   //Проверка assert на ввод данных InsectBat
    InsectBat* CheckInsectBat = new InsectBat;                                      //Создание CheckInsectBat формы

    CheckInsectBat->setIdBat(10000);                                                //Заполнение поля CheckInsectBat формы - IdBat                        
    CheckInsectBat->setName("LavaWing");                                            //Заполнение поля CheckInsectBat формы - Name                        
    CheckInsectBat->setFlightTime(5000);                                            //Заполнение поля CheckInsectBat формы - FlightTime                  
    CheckInsectBat->setBirthday("04.08.1998");                                      //Заполнение поля CheckInsectBat формы - Birthday                   
    CheckInsectBat->setNumberOfMeals(4);                                            //Заполнение поля CheckInsectBat формы - NumberOfMeals             
    CheckInsectBat->setNumberOfSleepCycles(1);                                      //Заполнение поля CheckInsectBat формы - NumberOfSleepCycles     
    CheckInsectBat->setGender(true);                                                //Заполнение поля CheckInsectBat формы - Gender                        
    CheckInsectBat->setWinterHibernation(105);                                      //Заполнение поля CheckInsectBat формы - WinterHibernation 
    CheckInsectBat->setNickname("LavaLava");                                        //Заполнение поля CheckInsectBat формы - Nickname         
    CheckInsectBat->setsSize(42.5);                                                 //Заполнение поля CheckInsectBat формы - sSize        
    CheckInsectBat->setType("LongEared");                                           //Заполнение поля CheckInsectBat формы - Type                        
    CheckInsectBat->setFoodWeight(25.0);                                            //Заполнение поля CheckInsectBat формы - FoodWeight
    CheckInsectBat->setTypeInsectFood("Mosquitoes");                                //Заполнение поля CheckInsectBat формы - TypeInsectFood
    CheckInsectBat->setAmountOfInsect(80);                                          //Заполнение поля CheckInsectBat формы - AmountOfInsect

    assert(CheckInsectBat->getIdBat()==10000);                                      //Проверка поля CheckInsectBat формы на вводимость данных - IdBat
    assert(CheckInsectBat->getName()=="LavaWing");                                  //Проверка поля CheckInsectBat формы на вводимость данных - Name
    assert(CheckInsectBat->getFlightTime()==5000);                                  //Проверка поля CheckInsectBat формы на вводимость данных - FlightTime                        
    assert(CheckInsectBat->getBirthday()=="04.08.1998");                            //Проверка поля CheckInsectBat формы на вводимость данных - Birthday
    assert(CheckInsectBat->getNumberOfMeals()==4);                                  //Проверка поля CheckInsectBat формы на вводимость данных - NumberOfMeals
    assert(CheckInsectBat->getNumberOfSleepCycles()==1);                            //Проверка поля CheckInsectBat формы на вводимость данных - NumberOfSleepCycles
    assert(CheckInsectBat->getGender()=="Male");                                    //Проверка поля CheckInsectBat формы на вводимость данных - Gender
    assert(CheckInsectBat->getWinterHibernation()==105);                            //Проверка поля CheckInsectBat формы на вводимость данных - WinterHibernation
    assert(CheckInsectBat->getNickname()=="LavaLava");                              //Проверка поля CheckInsectBat формы на вводимость данных - Nickname
    assert(CheckInsectBat->getsSize()==42.5);                                       //Проверка поля CheckInsectBat формы на вводимость данных - sSize
    assert(CheckInsectBat->getType()=="LongEared");                                 //Проверка поля CheckInsectBat формы на вводимость данных - Type
    assert(CheckInsectBat->getFoodWeight()==25.0);                                  //Проверка поля CheckInsectBat формы на вводимость данных - FoodWeight
    assert(CheckInsectBat->getTypeInsectFood()=="Mosquitoes");                      //Проверка поля CheckInsectBat формы на вводимость данных - TypeInsectFood
    assert(CheckInsectBat->getAmountOfInsect()==80);                                //Проверка поля CheckInsectBat формы на вводимость данных - AmountOfInsect
    assert((CheckInsectBat->toString()) == "InsectBat:\nID: 10000\nName: LavaWing\nFlightTime: 5000\nBirthday: 04.08.1998\nNumberOfMeals: 4\nNumberOfSleepCycles: 1\nGender: Male\nWinterHibernation: 105\nNickname: LavaLava\nSize: 42.5\nType: LongEared\nFoodWeight: 25.0\nTypeInsectFood: Mosquitoes\nAmountOfInsect: 80");

    
    delete CheckInsectBat;                                                          //Освобождение памяти CheckInsectBat
    }

    void assertFruitBatCheck() {                                                    //Проверка assert на ввод данных FruitBat
    FruitsBat* CheckFruitBat = new FruitsBat;                                       //Создание CheckFruitBat формы

    CheckFruitBat->setIdBat(26432);                                                 //Заполнение поля CheckFruitBat формы - IdBat                                                                 
    CheckFruitBat->setName("SweetFruit");                                           //Заполнение поля CheckFruitBat формы - Name                        
    CheckFruitBat->setFlightTime(8400);                                             //Заполнение поля CheckFruitBat формы - FlightTime                 
    CheckFruitBat->setBirthday("16.09.2001");                                       //Заполнение поля CheckFruitBat формы - Birthday                 
    CheckFruitBat->setNumberOfMeals(3);                                             //Заполнение поля CheckFruitBat формы - NumberOfMeals           
    CheckFruitBat->setNumberOfSleepCycles(2);                                       //Заполнение поля CheckFruitBat формы - NumberOfSleepCycles   
    CheckFruitBat->setGender(false);                                                //Заполнение поля CheckFruitBat формы - Gender                       
    CheckFruitBat->setWinterHibernation(105);                                       //Заполнение поля CheckFruitBat формы - WinterHibernation
    CheckFruitBat->setNickname("Fruti");                                            //Заполнение поля CheckFruitBat формы - Nickname    
    CheckFruitBat->setsSize(42.5);                                                  //Заполнение поля CheckFruitBat формы - sSize      
    CheckFruitBat->setType("BlackEyes");                                            //Заполнение поля CheckFruitBat формы - Type                       
    CheckFruitBat->setFoodWeight(45.5);                                             //Заполнение поля CheckFruitBat формы - FoodWeight
    CheckFruitBat->setTypeFruitFood("Apples/Bananas/Oranges");                      //Заполнение поля CheckFruitBat формы - TypeFruitFood
    CheckFruitBat->setAmountOfFruits(12);                                           //Заполнение поля CheckFruitBat формы - AmountOfFruits

    assert(CheckFruitBat->getIdBat()==26432);                                       //Проверка поля CheckFruitBat формы на вводимость данных - IdBat
    assert(CheckFruitBat->getName()=="SweetFruit");                                 //Проверка поля CheckFruitBat формы на вводимость данных - Name
    assert(CheckFruitBat->getFlightTime()==8400);                                   //Проверка поля CheckFruitBat формы на вводимость данных - FlightTime                    
    assert(CheckFruitBat->getBirthday()=="16.09.2001");                             //Проверка поля CheckFruitBat формы на вводимость данных - Birthday
    assert(CheckFruitBat->getNumberOfMeals()==3);                                   //Проверка поля CheckFruitBat формы на вводимость данных - NumberOfMeals
    assert(CheckFruitBat->getNumberOfSleepCycles()==2);                             //Проверка поля CheckFruitBat формы на вводимость данных - NumberOfSleepCycles
    assert(CheckFruitBat->getGender()=="Female");                                   //Проверка поля CheckFruitBat формы на вводимость данных - Gender
    assert(CheckFruitBat->getWinterHibernation()==105);                             //Проверка поля CheckFruitBat формы на вводимость данных - WinterHibernation 
    assert(CheckFruitBat->getNickname()=="Fruti");                                  //Проверка поля CheckFruitBat формы на вводимость данных - Nickname
    assert(CheckFruitBat->getsSize()==42.5);                                        //Проверка поля CheckFruitBat формы на вводимость данных - sSize
    assert(CheckFruitBat->getType()=="BlackEyes");                                  //Проверка поля CheckFruitBat формы на вводимость данных - Type
    assert(CheckFruitBat->getFoodWeight()==45.5);                                   //Проверка поля CheckFruitBat формы на вводимость данных - FoodWeight
    assert(CheckFruitBat->getTypeFruitFood()=="Apples/Bananas/Oranges");            //Проверка поля CheckFruitBat формы на вводимость данных - TypeFruitFood
    assert(CheckFruitBat->getAmountOfFruits()==12);                                 //Проверка поля CheckFruitBat формы на вводимость данных - AmountOfFruits
    assert((CheckFruitBat->toString()) == "InsectBat:\nID: 26432\nName: SweetFruit\nFlightTime: 8400\nBirthday: 16.09.2001\nNumberOfMeals: 3\nNumberOfSleepCycles: 2\nGender: Female\nWinterHibernation: 105\nNickname: Fruti\nSize: 42.5\nType: BlackEyes\nFoodWeight: 45.5\nTypeInsectFood: Apples/Bananas/Oranges\nAmountOfInsect: 12");


    delete CheckFruitBat;                                                           //Очистка памяти CheckFruitBat
    }

    void assertBloodBatCheck() {                                                    //Проверка assert на ввод данных BloodBat
    BloodBat* CheckBloodBat = new BloodBat;                                         //Создание CheckBloodBat формы

    CheckBloodBat->setIdBat(253212);                                                //Заполнение поля CheckBloodBat формы - IdBat                          
    CheckBloodBat->setName("Decibat");                                              //Заполнение поля CheckBloodBat формы - Name                      
    CheckBloodBat->setFlightTime(999999);                                           //Заполнение поля CheckBloodBat формы - FlightTime                   
    CheckBloodBat->setBirthday("07.02.2016");                                       //Заполнение поля CheckBloodBat формы - Birthday                  
    CheckBloodBat->setNumberOfMeals(3);                                             //Заполнение поля CheckBloodBat формы - NumberOfMeals            
    CheckBloodBat->setNumberOfSleepCycles(3);                                       //Заполнение поля CheckBloodBat формы - NumberOfSleepCycles    
    CheckBloodBat->setGender(true);                                                 //Заполнение поля CheckBloodBat формы - Gender                       
    CheckBloodBat->setWinterHibernation(0);                                         //Заполнение поля CheckBloodBat формы - WinterHibernation
    CheckBloodBat->setNickname("Deci");                                             //Заполнение поля CheckBloodBat формы - Nickname    
    CheckBloodBat->setsSize(125);                                                   //Заполнение поля CheckBloodBat формы - sSize      
    CheckBloodBat->setType("LongEared");                                            //Заполнение поля CheckBloodBat формы - Type                       
    CheckBloodBat->setFoodWeight(150);                                              //Заполнение поля CheckBloodBat формы - FoodWeight
    CheckBloodBat->setTypeBlood("Animal/Human");                                    //Заполнение поля CheckBloodBat формы - TypeBlood
    CheckBloodBat->setAmountOfBlood(150);                                           //Заполнение поля CheckBloodBat формы - AmountOfBlood

    assert(CheckBloodBat->getIdBat()==253212);                                      //Проверка поля CheckBloodBat формы на вводимость данных - IdBat
    assert(CheckBloodBat->getName()=="Decibat");                                    //Проверка поля CheckBloodBat формы на вводимость данных - Name
    assert(CheckBloodBat->getFlightTime()==999999);                                 //Проверка поля CheckBloodBat формы на вводимость данных - FlightTime                     
    assert(CheckBloodBat->getBirthday()=="07.02.2016");                             //Проверка поля CheckBloodBat формы на вводимость данных - Birthday
    assert(CheckBloodBat->getNumberOfMeals()==3);                                   //Проверка поля CheckBloodBat формы на вводимость данных - NumberOfMeals
    assert(CheckBloodBat->getNumberOfSleepCycles()==3);                             //Проверка поля CheckBloodBat формы на вводимость данных - NumberOfSleepCycles
    assert(CheckBloodBat->getGender()=="Male");                                     //Проверка поля CheckBloodBat формы на вводимость данных - Gender
    assert(CheckBloodBat->getWinterHibernation()==0);                               //Проверка поля CheckBloodBat формы на вводимость данных - WinterHibernation
    assert(CheckBloodBat->getNickname()=="Deci");                                   //Проверка поля CheckBloodBat формы на вводимость данных - Nickname
    assert(CheckBloodBat->getsSize()==125);                                         //Проверка поля CheckBloodBat формы на вводимость данных - sSize
    assert(CheckBloodBat->getType()=="LongEared");                                  //Проверка поля CheckBloodBat формы на вводимость данных - Type
    assert(CheckBloodBat->getFoodWeight()==150);                                    //Проверка поля CheckBloodBat формы на вводимость данных - FoodWeight
    assert(CheckBloodBat->getTypeBlood()=="Animal/Human");                          //Проверка поля CheckBloodBat формы на вводимость данных - TypeBlood
    assert(CheckBloodBat->getAmountOfBlood()==150);                                 //Проверка поля CheckBloodBat формы на вводимость данных - AmountOfBlood
    assert((CheckBloodBat->toString()) == "BloodBat:\nID: 253212\nName: Decibat\nFlightTime: 999999\nBirthday: 07.02.2016\nNumberOfMeals: 3\nNumberOfSleepCycles: 3\nGender: Male\nWinterHibernation: 0\nNickname: Deci\nSize: 125\nType: LongEared\nFoodWeight: 150\nTypeInsectFood: Animal/Human\nAmountOfInsect: 80");


    delete CheckBloodBat;                                                           //Очистка памяти CheckBloodBat
    }


    void VirtualCheck() {
    ///Если не будет указателей, то не будет преобразование базового класса из производного

    //Будет приведение типов из насекомоядных летучих мышей в просто летучую мышь: Bat myInsectBat1 =  InsectBat();
    std::cout << "~~~~~~~~~~~~"<< std::endl;
    Bat myInsectBat1 = InsectBat(10000, "LavaWing", 5000, "04.08.1998", 4, 1, true, 105, "LavaLava", 42.5d, "LongEared", 25.0d, "Mosquitoes", 80);                                              //Проверка на вызов виртуального метода без указателей и с указателями (по желанию)                                                   //Вывод цельной строки myInsectBat1
    std::cout << myInsectBat1.toString() << std::endl;      //Вывод цельной строки myInsectBat2 из класса Bat
    std::cout << "~~~~~~~~~~~~"<< std::endl;
    //Не будет преобразование типа: Bat* myInsectBat1 = new InsectBat();
    Bat* myInsectBat2 = new InsectBat(10000, "LavaWing", 5000, "04.08.1998", 4, 1, true, 105, "LavaLava", 42.5d, "LongEared", 25.0d, "Mosquitoes", 80);
    std::cout << myInsectBat2->toString() << std::endl;     //Вывод цельной строки myInsectBat2 из класса InsectBat
    std::cout << "~~~~~~~~~~~~"<< std::endl;

    InsectBat* myInsectBat2_1 = dynamic_cast<InsectBat*>(myInsectBat2);     
    //Переопределение указателя, который указывал на Bat, который будет указывать на InsectBat
    //для взаимодействия с переопределенными методами override

    std::cout << myInsectBat2_1->getTypeInsectFood() << std::endl;          //Переопределенный вывод поля myInsectBat2_

    delete myInsectBat2;
    //Полиморфизм работает с указателями, а не с объектами
    }
    