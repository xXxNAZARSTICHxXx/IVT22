///Стич Назар Иванович ИВТ-22 (КЛАССЫ)
///Модульный файл - хранит все методы реализации класса
#include <string>                                   //Подключение библиотеки строк
#include <fstream>
#include <iostream>
#include <cassert>
#include <chrono>
#include "MethodNames.h"                      //Подключение собственноого заголовочного файла классов

void Time::equate(){    
    seconds += microseconds / 1000;                   // Количество полных секунд в микросекундах
    microseconds %= 1000;                             // Оставшиеся микросекунды

    minutes += seconds / 60;                        // Количество полных минут в секундах
    seconds %= 60;                                  // Оставшиеся секунды

    hours += minutes / 60;                          // Количество полных часов в минутах
    minutes %= 60;                                  // Оставшиеся минуты

    days += hours / 24;                             // Количество полных дней в часах
    hours %= 24;                                    // Оставшиеся часы

    years += days / 365;                            // Количество полных лет в днях
    days %= 365;                                    // Оставшиеся дни
}

///Метод сложения переменных по парно; t - переменная обращения (сложение например минут одного набора и минут другого набора)
void Time::addTime(const Time& t) {                 
    addYears(t.years);                              //Парное сложение годов
    addDays(t.days);                                //Парное сложение дней с переходом в года
    addHours(t.hours);                              //Парное сложение часов с переходом в дни
    addMinutes(t.minutes);                          //Парное сложение минут с переходом в часы
    addSeconds(t.seconds);                          //Парное сложение секунд с переходом в минуты

    equate();
}

///Метод вычитания переменных по парно; t - переменная обращения (вычитание например дней одного набора и дней другого набора) ((если второй набор будет больше, то значение станет отрицательным))
void Time::subtractTime(const Time& t) {        
    subtractYears(t.years);                               //Вычитание годов
    subtractDays(t.days);                                 //Вычитание дней
    subtractHours(t.hours);                               //Вычитание часов
    subtractMinutes(t.minutes);                           //Вычитание минут
    subtractSeconds(t.seconds);                           //Вычитание секунд

    equate();

}

///Метод добавления просчета по годам; y-год
void Time::addYears(int y) {
    years += y;                                     //Складываем года
}

///Метод добавления просчета по дням; d-день
void Time::addDays(int d) {
    days += d;                                      //Складываем дни                         
    equate();
}

///Метод добавления просчета по часам; h-час
void Time::addHours(int h) {
    hours += h;                                     //Складываем часы
    equate();
}

///Метод добавления просчета по минутам; m-минуты
void Time::addMinutes(int m) {                  
    minutes += m;                                   //Складываем минуты
    equate();
}

///Метод добавления просчета по секундам; s-секунды
void Time::addSeconds(int s) {
    seconds += s;                                   //Складываем секунды
    equate();
}

///Метод добавления просчета по микросекундам; ms-микросекунды
void Time::addMicroseconds(int ms) {
    microseconds += ms;                                   //Складываем микросекунды
    equate();
}

///
void Time::subtractYears(int y) {
    years -= y;
}

///Метод вычитания дней;
void Time::subtractDays(int d) {
    days -= d;
    equate();
}

///Метод вычитания часов;
void Time::subtractHours(int h) {
    hours -= h;
    equate();
}

///Метод вычитания минут;
void Time::subtractMinutes(int m) {
    minutes -= m;
    equate();
}

///Метод вычитания секунд; 
void Time::subtractSeconds(int s) {
    seconds -= s;
    equate();
}

///Метод вычитания микросекунд; 
void Time::subtractMicroseconds(int ms) {
    microseconds -= ms;
    equate();
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
int Time::getHours() const {
    return hours;
}

///Метод получения минут
int Time::getMinutes() const {
    return minutes;
}

///Метод получения секунд
long Time::getSeconds() const {
    return seconds;
}

///Метод получения микросекунд
short Time::getMicroseconds() const {
    return microseconds;
}

///Метод установки лет
long Time::setYears(long y) {
    years = y;
    return years;
}

///Метод установки дней
short Time::setDays(short d) {
    days = d;
    return days;
}

///Метод установки часов
int Time::setHours(int h) {
    hours = h;
    return hours;
}

///Метод установки минут
int Time::setMinutes(int m) {
    minutes = m;
    return minutes;
}

///Метод установки секунд
long Time::setSeconds(long s) {
    seconds = s;
    return seconds;
}

///Метод установки секунд
short Time::setMicroseconds(short ms) {
    seconds = ms;
    return microseconds;
}

///Метод соединения кол-ва ВСЕХ микросекунд
long Time::toMicroseconds() const {
    //Объндиняем секунды
    return years * 31536000000 + days * 86400000 + hours * 3600000 + minutes * 60000 + seconds * 1000 + microseconds;
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
    return "Y" + std::to_string(years) + ": D" + std::to_string(days) + ": H" + std::to_string(hours) + ": M" + std::to_string(minutes) + ": S" + std::to_string(seconds) + ": MS" + std::to_string(microseconds);
}

///Метод отправки значений времени
void Time::setTime(long y, short d, int h, int m, long s, short ms) {
        years = y;          //установка годов
        days = d;           //установка дней
        hours = h;          //установка часов
        minutes = m;        //установка минут
        seconds = s;        //установка секунд
        microseconds = ms;  //установка микросекунд
}

///Метод получения значений времени
void Time::getTime(long &y, short &d, int &h, int &m, long &s, short &ms) const{
        y = years;          //взятие годов
        d = days;           //взятие дней
        h = hours;          //взятие часов
        m = minutes;        //взятие минут
        s = seconds;        //взятие секунд
        ms = microseconds;  //взятие микросекунд
}

///Метод вывода системного времени в массив
void Time::REALTime(long s){
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::chrono::seconds seconds_since_epoch = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
    s = seconds_since_epoch.count();
    seconds = s;        //установка секунд
}

/// Метод для саздания массива объектов Time
Time** Time::createDynamicArray(int size) {
        Time** timeArray = new Time*[size];
        for (int i = 0; i < size; i++) {
            timeArray[i] = new Time;
        }
        return timeArray;
}

/// Метод для освобождения массива объектов Time
void Time::deleteDynamicArray(Time** timeArray, int size) {
        for (int i = 0; i < size; i++) {
            delete timeArray[i];
        }
        delete[] timeArray;
}

void Time::fillTimeArray(Time** timeArray, int size, long years, short days, int hours, int minutes, long seconds, short microseconds) {
    for (int i = 0; i < size; i++) {
        switch (i) {
            case 0: timeArray[i]->setYears(years); 
            break;
            case 1: timeArray[i]->setDays(days); 
            break;
            case 2: timeArray[i]->setHours(hours); 
            break;
            case 3: timeArray[i]->setMinutes(minutes); 
            break;
            case 4: timeArray[i]->setSeconds(seconds); 
            break;
            case 5: timeArray[i]->setMicroseconds(microseconds); 
            break;
        }
    }
}

///Функция чтения с файла
void readTwoObjectsInFile(Time& t1, Time& t2, const std::string& filename) {
    std::ifstream inFile(filename);                                                           //Открытие файла НА ЧТЕНИЕ

    if (!inFile) {                                                                            //Если файл не открыт
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;                  
        return;
    }

    long y,s;                                                                               //Переменные лет и секунд   
    int h, m;                                                                               //Переменные часов и минут
    short d, ms;                                                                            //Переменные времени, дни, микросекунды соответственно
    
    inFile >> y >> d >> h >> m >> s >> ms;                                                          //Чтение первой группы чисел
    t1.setTime(y, d, h, m, s, ms);                                                                //Передача в 1 массив
    inFile >> y >> d >> h >> m >> s >> ms;                                                          //Чтение второй группы чисел
    t2.setTime(y, d, h, m, s, ms);                                                                //Передача в 2 массив
    inFile.close();                                                                           //Закрытие файла
}

///Функция записи в файл
void writeTwoObjectsInFile(const Time& t1, const Time& t2, const std::string& filename) {
    std::ofstream outFile(filename);                                                          //Открытие файла НА ЗАПИСЬ

    if (!outFile) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;                      //Если файл не открыт
        return;
    }

    long y,s;                                                                               //Переменные лет и секунд   
    int h, m;                                                                               //Переменные часов и минут
    short d, ms;                                                                            //Переменные времени, дни, микросекунды соответственно
    
    t1.getTime(y, d, h, m, s, ms);                                                                //Взятие первой группы чисел
    outFile << y << " " << d << " " << h << " " << m << " " << s << " " << ms << std::endl;                //Запись в файл с пробелами

    t2.getTime(y, d, h, m, s, ms);                                                                //Взятие второй группы чисел
    outFile << y << " " << d << " " << h << " " << m << " " << s << " " << ms;                             //Запись в файл с пробелами

    outFile.close();                                                                          //Закрытие файла
}



/*Функция включения assert'ов 

void assertCheck(Time assertA, Time assertB) {
Time assertC;                                         //Первый дополнительный массив времени
Time assertD;                                         //Второй дополнительный массив времени
assertA.setTime(15, 45, 6, 20, 25);                   //задание значений времени первому assertA массиву
assertB.setTime(13, 773, 54, 18, 145);                //задание значений времени второму assertB массиву
assertC.setTime(0, 0, 0, 0, 0);                       //задание значений времени первому дополнительному assertC массиву
assertD.setTime(30, 90, 12, 40, 50);                  //задание значений времени второму дополнительному assertD массиву
assertB.equate();                                     //выравнивание значений второго массива
assert(assertA.toString() == assertB.toString());     //проверка через assert на совпадение ответов
//todo строка с строкой ~ tostring и числа
assertA.addTime(assertB);                             //Прибавка времени к А массиву
assert(assertA.toString() == assertD.toString());     //проверка через assert на совпадение ответов

assertA.subtractTime(assertB);                        //Убавка у А массива
assertA.subtractTime(assertB);                        //Убавка у А массива //Используется здесь одна переменная класса, чтобы сделать вычитание, из сложения, надо два раза отнять
assert(assertA.toString() == assertC.toString());     //проверка через assert на совпадение ответов
}
*/