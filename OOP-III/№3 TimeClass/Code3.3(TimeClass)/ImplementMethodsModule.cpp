///Стич Назар Иванович ИВТ-22 (КЛАССЫ)
///Модульный файл - хранит все методы реализации класса
#include <string>                                   //Подключение библиотеки строк
#include <fstream>
#include <iostream>
#include "MethodNames.h"                      //Подключение собственноого заголовочного файла классов

///Метод сложения переменных по парно; t - переменная обращения (сложение например минут одного набора и минут другого набора)
void Time::addTime(const Time& t) {                 
    addYears(t.years);                              //Парное сложение годов
    addDays(t.days);                                //Парное сложение дней с переходом в года
    addHours(t.hours);                              //Парное сложение часов с переходом в дни
    addMinutes(t.minutes);                          //Парное сложение минут с переходом в часы
    addSeconds(t.seconds);                          //Парное сложение секунд с переходом в минуты

    if (seconds > 59) {                              //Если секунд много
        seconds -= 60;                              //Вычитаеи 60...
        minutes++;                                  //...добпаляем минуту
    }
    if (minutes > 59) {                              //Если минуты кончились
        minutes -= 60;                              //Берем еще 60...
        hours++;                                    //...из нового часа, которого вычитаем
    }
    if (hours > 23) {                                //Если часы кончились
        hours -= 24;                                //Берем еще 24...
        days++;                                     //...из нового дня, которого вычитаем
    }
    if (days >364) {                                  //Если дни кончились
        days -= 365;                                //Берем еще 365...
        years++;                                    //...из нового года, которого вычитаем
    }
}

///Метод вычитания переменных по парно; t - переменная обращения (вычитание например дней одного набора и дней другого набора) ((если второй набор будет больше, то значение станет отрицательным))
void Time::subtractTime(const Time& t) {        
    subtractYears(t.years);                               //Вычитание годов
    subtractDays(t.days);                                 //Вычитание дней
    subtractHours(t.hours);                               //Вычитание часов
    subtractMinutes(t.minutes);                           //Вычитание минут
    subtractSeconds(t.seconds);                           //Вычитание секунд

    if (seconds < 0) {                              //Если секунды кончились
        seconds += 60;                              //Берем еще 60...
        minutes--;                                  //...из новой минуты, которую вычитаем
    }
    if (minutes < 0) {                              //Если минуты кончились
        minutes += 60;                              //Берем еще 60...
        hours--;                                    //...из нового часа, которого вычитаем
    }
    if (hours < 0) {                                //Если часы кончились
        hours += 24;                                //Берем еще 24...
        days--;                                     //...из нового дня, которого вычитаем
    }
    if (days< 0) {                                  //Если дни кончились
        days += 365;                                //Берем еще 365...
        years--;                                    //...из нового года, которого вычитаем
    }

}

///Метод добавления просчета по годам; y-год
void Time::addYears(int y) {
    years += y;                                     //Складываем года
}

///Метод добавления просчета по дням; d-день
void Time::addDays(int d) {
    days += d;                                      //Складываем дни                         
    years += days / 365;                            // Количество полных лет в днях
    days %= 365;                                    // Оставшиеся дни
}

///Метод добавления просчета по часам; h-час
void Time::addHours(int h) {
    hours += h;                                     //Складываем часы
                                    
    days += hours / 24;                             // Количество полных дней в часах
    hours %= 24;                                    // Оставшиеся часы

    years += days / 365;                            // Количество полных лет в днях
    days %= 365;                                    // Оставшиеся дни
}

///Метод добавления просчета по минутам; m-минуты
void Time::addMinutes(int m) {                  
    minutes += m;                                   //Складываем минуты

    hours += minutes / 60;                          // Количество полных часов в минутах
    minutes %= 60;                                  // Оставшиеся минуты
    
    days += hours / 24;                             // Количество полных дней в часах
    hours %= 24;                                    // Оставшиеся часы

    years += days / 365;                            // Количество полных лет в днях
    days %= 365;                                    // Оставшиеся дни
}

///Метод добавления просчета по секундам; s-секунды
void Time::addSeconds(int s) {
    seconds += s;                                   //Складываем секунды

    minutes += seconds / 60;                        // Количество полных минут в секундах
    seconds %= 60;                                  // Оставшиеся секундах

    hours += minutes / 60;                          // Количество полных часов в минутах
    minutes %= 60;                                  // Оставшиеся минуты

    days += hours / 24;                             // Количество полных дней в часах
    hours %= 24;                                    // Оставшиеся часы

    years += days / 365;                            // Количество полных лет в днях
    days %= 365;                                    // Оставшиеся дни
}

///
void Time::subtractYears(int y) {
    years -= y;
}

///Метод вычитания дней;
void Time::subtractDays(int d) {
    days -= d;
    if (days < 0) {
        days += 365;
        years--;
    }
}

///Метод вычитания часов;
void Time::subtractHours(int h) {
    hours -= h;
    while (hours < 0) {
        hours += 24;
        days--;
    }
    if (days < 0) {
        days += 365;
        years--;
    }
}

///Метод вычитания минут;
void Time::subtractMinutes(int m) {
    minutes -= m;
    while (minutes < 0) {
        minutes += 60;
        hours--;
    }
    while (hours < 0) {
        hours += 24;
        days--;
    }
    if (days < 0) {
        days += 365;
        years--;
    }
}

///Метод вычитания секунд; 
void Time::subtractSeconds(int s) {
    seconds -= s;
    while (seconds < 0) {
        seconds += 60;
        minutes--;
    }
    while (minutes < 0) {
        minutes += 60;
        hours--;
    }
    while (hours < 0) {
        hours += 24;
        days--;
    }
    if (days < 0) {
        days += 365;
        years--;
    }
}

///Метод получения лет
long Time::getYears() const {
    return years;
}

///Метод получения дней
short Time::getDays() const {
    return days;
}

///Метод получения часов
short Time::getHours() const {
    return hours;
}

///Метод получения минут
short Time::getMinutes() const {
    return minutes;
}

///Метод получения секунд
short Time::getSeconds() const {
    return seconds;
}

///Метод установки лет
void Time::setYears(long y) {
    years = y;
}

///Метод установки дней
void Time::setDays(short d) {
    days = d;
}

///Метод установки часов
void Time::setHours(short h) {
    hours = h;
}

///Метод установки минут
void Time::setMinutes(short m) {
    minutes = m;
}

///Метод установки секунд
void Time::setSeconds(short s) {
    seconds = s;
}

void Time::equate(){                        
    minutes += seconds / 60;                        // Количество полных минут в секундах
    seconds %= 60;                                  // Оставшиеся секундах

    hours += minutes / 60;                          // Количество полных часов в минутах
    minutes %= 60;                                  // Оставшиеся минуты

    days += hours / 24;                             // Количество полных дней в часах
    hours %= 24;                                    // Оставшиеся часы

    years += days / 365;                            // Количество полных лет в днях
    days %= 365;                                    // Оставшиеся дни
}

///Метод соединения кол-ва ВСЕХ секунд
int Time::toSeconds() const {
    //Объндиняем секунды
    return years * 31536000 + days * 86400 + hours * 3600 + minutes * 60 + seconds;
}

///Метод соединения кол-ва ВСЕХ минут
int Time::toMinutes() const {
    //Объндиняем минуты
    return years * 525600 + days * 1440 + hours * 60 + minutes;
}

///Метод соединения кол-ва ВСЕХ часов
int Time::toHours() const {
    //Объндиняем часы
    return years * 8760 + days * 24 + hours;
}

///Метод соединения кол-ва ВСЕХ дней
int Time::toDays() const {
    //Объндиняем дни
    return years * 365 + days;
}

///Метод соединения кол-ва лет
int Time::toYears() const {
    //Возвращаем года
    return years;
}

///Метод компановки строки
std::string Time::toString() const {
    //Компановка строки
    return "Y" + std::to_string(years) + ": D" + std::to_string(days) + ": H" + std::to_string(hours) + ": M" + std::to_string(minutes) + ": S" + std::to_string(seconds);
}

///Метод отправки значений времени
void Time::setTime(long y, short d, short h, short m, short s) {
        getYears(y);          //установка годов
        getDays(d);           //установка дней
        getHours(h);          //установка часов
        getMinutes(m);        //установка минут
        getSeconds(s);        //установка секунд
}

///Метод получения значений времени
void Time::getTime(long &y, short &d, short &h, short &m, short &s) const {
        setYears(y);          //взятие годов
        setDays(d);           //взятие дней
        setHours(h);          //взятие часов
        setMinutes(m);        //взятие минут
        setSeconds(s);        //взятие секунд
}

///Функция чтения с файла
void readTwoObjectsInFile(Time& t1, Time& t2, const std::string& filename) {
    std::ifstream inFile(filename);                                                           //Открытие файла НА ЧТЕНИЕ

    if (!inFile) {                                                                            //Если файл не открыт
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;                  
        return;
    }

    long y;                                                                                   //Переменная лет         
    short d, h, m, s;                                                                         //Переменные остального времени, дни, часы, минуты, секунды соответственно
    
    inFile >> y >> d >> h >> m >> s;                                                          //Чтение первой группы чисел
    t1.setTime(y, d, h, m, s);                                                                //Передача в 1 массив
    inFile >> y >> d >> h >> m >> s;                                                          //Чтение второй группы чисел
    t2.setTime(y, d, h, m, s);                                                                //Передача в 2 массив
    inFile.close();                                                                           //Закрытие файла
}

///Функция записи в файл
void writeTwoObjectsInFile(const Time& t1, const Time& t2, const std::string& filename) {
    std::ofstream outFile(filename);                                                          //Открытие файла НА ЗАПИСЬ

    if (!outFile) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;                      //Если файл не открыт
        return;
    }

    long y;                                                                                   //Переменная лет  
    short d, h, m, s;                                                                         //Переменные остального времени, дни, часы, минуты, секунды соответственно
    
    t1.getTime(y, d, h, m, s);                                                                //Взятие первой группы чисел
    outFile << y << " " << d << " " << h << " " << m << " " << s << std::endl;                //Запись в файл с пробелами

    t2.getTime(y, d, h, m, s);                                                                //Взятие второй группы чисел
    outFile << y << " " << d << " " << h << " " << m << " " << s;                             //Запись в файл с пробелами

    outFile.close();                                                                          //Закрытие файла
}