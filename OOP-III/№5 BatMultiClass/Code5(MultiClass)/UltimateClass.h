///Стич Назар Иванович ИВТ-22
///Файл мультикласса
class Bat {                                                                                                         ///Класс летучих мышей

public:                                                                                                             ///Открытая зона класса
    Bat(const int& IdBat, const std::string& Name, const int& FlightTime,                                           ///Описание полей - конструкции Bat
        const std::string& Birthday, const short& NumberOfMeals, const short& NumberOfSleepCycles,
        const bool& Gender, const short& WinterHibernation, const std::string& Nickname,
        const float& sSize, const std::string& Type, const float& FoodWeight) 
        : IdBat(IdBat), Name(Name), FlightTime(FlightTime), Birthday(Birthday), NumberOfMeals(NumberOfMeals), 
        NumberOfSleepCycles(NumberOfSleepCycles), Gender(Gender), WinterHibernation(WinterHibernation), 
        Nickname(Nickname), sSize(sSize), Type(Type), FoodWeight(FoodWeight) {}
    int getIdBat() const;                                                                                           ///Метод получения ID летучей мыши
    std::string getName() const;                                                                                    ///Метод получения имени летучей мыши
    int getFlightTime() const;                                                                                      ///Метод получения длины полета летучей мыши в метрах
    std::string getBirthday() const;                                                                                ///Метод получения даты для рождения летучей мыши
    short getNumberOfMeals() const;                                                                                 ///Метод получения кол-ва приемов пищи
    short getNumberOfSleepCycles() const;                                                                           ///Метод получения кол-ва циклов сна за день
    std::string getGender() const;                                                                                  ///Метод получения пола летчей мыши
    short getWinterHibernation() const;                                                                             ///Метод получения длины зимней спячки в днях
    std::string getNickname() const;                                                                                ///Метод получения клички летучей мыши
    float getsSize() const;                                                                                         ///Метод получения размера летучей мыши
    std::string getType() const;                                                                                    ///Метод получения типа вида летучей мыши
    float getFoodWeight() const;                                                                                    ///Метод получения веса съеденой еды

    void setIdBat(const int& newIdBat);                                                                             ///Метод заполения ID летучей мыши
    void setName(const std::string& newName);                                                                       ///Метод заполения имени летучей мыши
    void setFlightTime(const int& newFlightTime);                                                                   ///Метод заполения длины полета летучей мыши в метрах
    void setBirthday(const std::string& newBirthday);                                                               ///Метод заполения даты для рождения летучей мыши
    void setNumberOfMeals(const short& newNumberOfMeals);                                                           ///Метод заполения кол-ва приемов пищи
    void setNumberOfSleepCycles(const short& newNumberOfSleepCycles);                                               ///Метод заполения кол-ва циклов сна за день
    void setGender(const bool& newGender);                                                                          ///Метод заполения пола летчей мыши
    void setWinterHibernation(const short& newWinterHibernation);                                                   ///Метод заполения длины зимней спячки в днях
    void setNickname(const std::string& newNickname);                                                               ///Метод заполения клички летучей мыши
    void setsSize(const float& newsSize);                                                                           ///Метод заполения размера летучей мыши
    void setType(const std::string& newType);                                                                       ///Метод заполения типа вида летучей мыши
    void setFoodWeight(const float& newFoodWeight);                                                                 ///Метод заполения веса съеденой еды

    // todo: to string

protected:                                                                                                          ///Защищенное поле класса
    int IdBat;                                                                                                      ///Поле - ID летучей мыши
    std::string Name;                                                                                               ///Поле - имени летучей мыши
    int FlightTime;                                                                                                 ///Поле - длины полета летучей мыши в метрах
    std::string Birthday;                                                                                           ///Поле - даты для рождения летучей мыши
    short NumberOfMeals;                                                                                            ///Поле - кол-ва приемов пищи
    short NumberOfSleepCycles;                                                                                      ///Поле - кол-ва циклов сна за день
    bool Gender;                                                                                                    ///Поле - пола летчей мыши
    short WinterHibernation;                                                                                        ///Поле - длины зимней спячки в днях
    std::string Nickname;                                                                                           ///Поле - клички летучей мыши
    float sSize;                                                                                                    ///Поле - размера летучей мыши
    std::string Type;                                                                                               ///Поле - типа вида летучей мыши
    float FoodWeight;                                                                                               ///Поле - веса съеденой еды
};


//todo переименовать подклассы по смыслу!!
class Insect : public Bat {                                                                                         ///Подкласс летучих мышей - насекомояные
public:                                                                                                             ///Открытая зона подкласса
    Insect(const int& IdBat, const std::string& Name, const int& FlightTime,                                        ///Описание полей - с наследованной конструкции Bat и с новыми полями (с фруктами)
        const std::string& Birthday, const short& NumberOfMeals, const short& NumberOfSleepCycles, 
        const bool& Gender, const short& WinterHibernation, const std::string& Nickname, 
        const float& sSize, const std::string& Type, const float& FoodWeight, const std::string& 
        TypeInsectFood, const short& AmountOfInsect) : Bat(IdBat, Name, FlightTime, Birthday, 
        NumberOfMeals, NumberOfSleepCycles, Gender, WinterHibernation, Nickname, sSize, Type, FoodWeight), 
        TypeInsectFood(TypeInsectFood), AmountOfInsect(AmountOfInsect) {}

    std::string getTypeInsectFood() const;                                                                          ///Метод получения видов насекомых употребляемых в пищу
    short getAmountOfInsect() const;                                                                                ///Метод получения кол-во насекомых употребляемых в пищу
    void setTypeInsectFood(const std::string& newTypeInsectFood);                                                   ///Метод заполнения видов насекомых употребляемых в пищу
    void setAmountOfInsect(const short& newAmountOfInsect);                                                         ///Метод заполнения кол-во насекомых употребляемых в пищу
private:                                                                                                            ///Закрытая зона подкласса
    std::string TypeInsectFood;                                                                                     ///Поле виды насекомых употребляемых в пищу
    short AmountOfInsect;                                                                                           ///Поле кол-во насекомых употребляемых в пищу
};



class Fruits : public Bat {                                                                                         ///Подкласс летучих мышей - фруктовые
public:                                                                                                             ///Открытая зона подкласса
    Fruits(const int& IdBat, const std::string& Name, const int& FlightTime,                                        ///Описание полей - с наследованной конструкции Bat и с новыми полями (с фруктами)
        const std::string& Birthday, const short& NumberOfMeals, const short& NumberOfSleepCycles, 
        const bool& Gender, const short& WinterHibernation, const std::string& Nickname, 
        const float& sSize, const std::string& Type, const float& FoodWeight, const std::string& 
        TypeFruitFood, const short& AmountOfFruits) : Bat(IdBat, Name, FlightTime, Birthday, 
        NumberOfMeals, NumberOfSleepCycles, Gender, WinterHibernation, Nickname, sSize, Type, FoodWeight), 
        TypeFruitFood(TypeFruitFood), AmountOfFruits(AmountOfFruits) {}

    std::string getTypeFruitFood() const;                                                                           ///Метод получения видов фруктов употребляемых в пищу
    short getAmountOfFruits() const;                                                                                ///Метод получения кол-во фруктов употребляемых в пищу
    void setTypeFruitFood(const std::string& newTypeFruitFood);                                                     ///Метод заполнения видов фруктов употребляемых в пищу
    void setAmountOfFruits(const short& newAmountOfFruits);                                                         ///Метод заполнения кол-во фруктов употребляемых в пищу
     
private:                                                                                                            ///Закрытая зона подкласса
    std::string TypeFruitFood;                                                                                      ///Поле виды фруктов употребляемых в пищу
    short AmountOfFruits;                                                                                           ///Поле кол-во фруктов употребляемых в пищу
};



class Blood : public Bat {                                                                                          ///Подкласс летучих мышей - кровососущие
public:                                                                                                             ///Открытая зона подкласса
    Blood(const int& IdBat, const std::string& Name, const int& FlightTime,                                         ///Описание полей - с наследованной конструкции Bat и с новыми полями (с кровью)
        const std::string& Birthday, const short& NumberOfMeals, const short& NumberOfSleepCycles, 
        const bool& Gender, const short& WinterHibernation, const std::string& Nickname, 
        const float& sSize, const std::string& Type, const float& FoodWeight, const std::string& 
        TypeBlood, const float& AmountOfBlood) : Bat(IdBat, Name, FlightTime, Birthday, 
        NumberOfMeals, NumberOfSleepCycles, Gender, WinterHibernation, Nickname, sSize, Type, FoodWeight), 
        TypeBlood(TypeBlood), AmountOfBlood(AmountOfBlood) {}

    std::string getTypeBlood() const;                                                                               ///Метод получения видов крови употребляемой в пищу
    float getAmountOfBlood() const;                                                                                 ///Метод получения кол-во крови употребляемой в пищу
    void setTypeBlood(const std::string& newTypeBlood);                                                             ///Метод заполнения видов крови употребляемой в пищу
    void setAmountOfBlood(const float& newAmountOfBlood);                                                           ///Метод заполнения кол-во крови употребляемой в пищу

private:                                                                                                            ///Закрытая зона подкласса
    std::string TypeBlood;                                                                                          ///Поле видов крови употребляемой в пищу
    float AmountOfBlood;                                                                                            ///Поле кол-во крови употребляемой в пищу
};