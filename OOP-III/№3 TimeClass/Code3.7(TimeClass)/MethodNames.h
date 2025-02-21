///Стич Назар Иванович ИВТ-22 (КЛАССЫ)
///Заголовочный файл - файл хранящий класс ВРЕМЕНИ и функции чтения и записи в файл

#ifndef METHODNAMES_H
#define METHODNAMES_H

#include <string>                                   //Подключение библиотеки строк
#include <iostream>                                 //Подключение библиотеки для ввода вывода через консоль
#include <string>                                   //Подключение библиотеки строк

/// Собственный класс ВРЕМЕНИ переменных и методов реализаций
class Time {                                        
private:                                            //Закрытая зона объявлений
    long years, seconds;                            //Переменные для конструктора, с которыми пользователь взаимодейстровать не может
    int hours, minutes;
    short days, microseconds;                        //Данные год, дни, часы, минуты, секунды, микросекунды                  

public:                                             //Открытая зона объявлений
    ///Конструктор - набор значений времени y-год d-день h-час m-минуты s-секунды
    Time(long y = 0, short d = 0, int h = 0, int m = 0, long s = 0, short ms = 0) : years(y), days(d), hours(h), minutes(m), seconds(s), microseconds(ms) {}

    ///Методы для работы с набором значений
    void equate();                                  ///Метод нормализации массива
    void addTime(const Time& t);                    ///Метод сложения переменных по парно (сложение например минут одного набора и минут другого набора)
    void subtractTime(const Time& t);               ///Метод вычитания переменных по парно (вычитание например дней одного набора и дней другого набора) ((если второй набор будет больше, то значение станет отрицательным))
    void addYears(int y);                           ///Метод добавления просчета по годам; y-год
    void addDays(int d);                            ///Метод добавления просчета по дням; d-день
    void addHours(int h);                           ///Метод добавления просчета по часам; h-час
    void addMinutes(int m);                         ///Метод добавления просчета по минутам; m-минуты
    void addSeconds(int s);                         ///Метод добавления просчета по секундам; s-секунды
    void addMicroseconds(int ms);                   ///Метод добавления просчета по микросекундам; ms-микросекунды
    void subtractYears(int y);                      ///Метод вычитания просчета по годам; y-год
    void subtractDays(int d);                       ///Метод вычитания просчета по дням; d-день
    void subtractHours(int h);                      ///Метод вычитания просчета по часам; h-час
    void subtractMinutes(int m);                    ///Метод вычитания просчета по минутам; m-минуты
    void subtractSeconds(int s);                    ///Метод вычитания просчета по секундам; s-секунды
    void subtractMicroseconds(int ms);              ///Метод вычитания просчета по годам; ms-микросекунды
    long getYears() const;                          ///Метод получения лет
    short getDays() const;                          ///Метод получения дней
    int getHours() const;                           ///Метод получения часов
    int getMinutes() const;                         ///Метод получения минут
    long getSeconds() const;                        ///Метод получения секунд
    short getMicroseconds() const;                  ///Метод получения микросекунд
    long setYears(long y);                          ///Метод установки лет
    short setDays(short d);                         ///Метод установки дней
    int setHours(int h);                            ///Метод установки часов
    int setMinutes(int m);                          ///Метод установки минут
    long setSeconds(long s);                        ///Метод установки секунд
    short setMicroseconds(short ms);                ///Метод установки микросекунд
    long toMicroseconds() const;                    ///Метод соединения кол-ва ВСЕХ микросекунд
    int toSeconds() const;                          ///Метод соединения кол-ва ВСЕХ секунд
    int toMinutes() const;                          ///Метод соединения кол-ва ВСЕХ минут
    int toHours() const;                            ///Метод соединения кол-ва ВСЕХ часов
    int toDays() const;                             ///Метод соединения кол-ва ВСЕХ дней
    int toYears() const;                            ///Метод соединения кол-ва лет
    std::string toString() const;                   ///Метод компановки строки
    void setTime(long y, short d, int h, int m, long s, short ms);                 ///Метод отправки значений времени
    void getTime(long &y, short &d, int &h, int &m, long &s, short &ms) const;     ///Метод получения значений времени
    void REALTime(long s);                          ///Метод вывода системного времени в массив
    Time** createDynamicArray(int size);            ///Метод создания ВРЕМЯННОГО массива 
    void deleteDynamicArray(Time** timeArray, int size);                            ///Метод удаления ВРЕМЯННОГО массива                                                                           
    void fillTimeArray(Time** timeArray, int size, long years, short days, int hours, int minutes, long seconds, short microseconds);   ///Метод записи значений в массив 

};
    void readTwoObjectsInFile(Time& t1, Time& t2, const std::string& filename);                ///Функция чтения с файла
    void writeTwoObjectsInFile(const Time& t1, const Time& t2, const std::string& filename);   ///Функция записи в файл
    void assertCheck(Time assertA, Time assertB);                                              ///Проверки для программиста -assert


#endif