//Стич Назар Иванович ИВТ-22
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Diagnostics;
using TimeModule;


namespace TimeModule
{
    /// <summary>
    /// Класс time в котором содержатся все методы и функции, требуемые для работы программы
    /// </summary>
    public class Time
    {  
        /// <summary>
        /// years - глобальная переменная, которая нужна для создания конструктора времянного массива с параметрами, хранящая годы
        /// </summary>
        public long years;
        /// <summary>
        /// seconds - глобальная переменная, которая нужна для создания конструктора времянного массива с параметрами, хранящая секунды
        /// </summary>
        public long seconds;
        /// <summary>
        /// hours - глобальная переменная, которая нужна для создания конструктора времянного массива с параметрами, хранящая часы
        /// </summary>
        public int hours;
        /// <summary>
        /// minutes - глобальная переменная, которая нужна для создания конструктора времянного массива с параметрами, хранящая минуты
        /// </summary>
        public int minutes;
        /// <summary>
        /// days - глобальная переменная, которая нужна для создания конструктора времянного массива с параметрами, хранящая дни
        /// </summary>
        public short days;
        /// <summary>
        /// microseconds - глобальная переменная, которая нужна для создания конструктора времянного массива с параметрами, хранящая микросекунды
        /// </summary>
        public short microseconds;

        //todo: сделать здесь проверку на отр. значение ВЕЗДЕ
        /// <summary>
        ///Конструктор - набор значений времени y-год d-день h-час m-минуты s-секунды С АВТОПРОВЕРКОЙ НА ОТР. ЗНАЧЕНИЕ
        /// </summary>
        public Time(long y = 0, short d = 0, int h = 0, int m = 0, long s = 0, short ms = 0)
        {

            this.setYears(y);                                 //Проверки на отрицательные значения и установку значений через setеры
            this.setDays(d);
            this.setHours(h);
            this.setMinutes(m);
            this.setSeconds(s);
            this.setMicroseconds(ms);
        }

        /// <summary>
        ///Выравнивание времени в избытке
        /// </summary>
        public void equate()
        {
            seconds += microseconds / 1000;                   // Количество полных секунд в микросекундах
            microseconds %= 1000;                             // Оставшиеся микросекунды

            minutes += (int)(seconds / 60);                   // Количество полных минут в секундах
            seconds %= 60;                                    // Оставшиеся секунды

            hours += minutes / 60;                            // Количество полных часов в минутах
            minutes %= 60;                                    // Оставшиеся минуты

            days += (short)(hours / 24);                      // Количество полных дней в часах
            hours %= 24;                                      // Оставшиеся часы

            years += days / 365;                              // Количество полных лет в днях
            days %= 365;                                      // Оставшиеся дни
        }

        /// <summary>
        ///Выравнивание времени в недостатке
        /// </summary>
        public void equateMinus()
        {
            if (years < 0) { years = 0; };
            if (days < 0) { days = 0; };
            if (hours < 0) { hours = 0; };
            if (minutes < 0) { minutes = 0; };
            if (seconds < 0) { seconds = 0; };
            if (microseconds < 0) { microseconds = 0; };


            if (seconds > 0)                                  //Если секунд больше 0
            {
                seconds -= 1;                                 //Вычитание одной секунды
                microseconds += 1000;                         //Прибавление 1000 микросекунд
            }

            if (minutes > 0)                                  //Если минут больше 1
            {
                minutes -= 1;                                 //Вычитание одной минуты
                seconds += 60;                                //Прибавление 60 секунд
            }
            if (hours > 0)                                    //Если часов больше 1
            {
                hours -= 1;                                   //Вычитание одного часа
                minutes += 60;                                //Прибавление 60 минут
            }
            if (days > 0)                                     //Если дней больше 1
            {
                days -= 1;                                    //Вычитание одного дня
                hours += 24;                                  //Прибавление 24 часов
            }
            if (years > 0)                                    //Если лет больше 1
            {
                years -= 1;                                   //Вычитание одного года
                days += 365;                                  //Прибавление 365 дней
            }
            equate();
        }

        /// <summary>
        ///Метод добавления времени
        /// </summary>
        public void AddTime(Time t)
        {
            addYears((int)t.years);                           //Парное сложение годов
            addDays(t.days);                                  //Парное сложение дней с переходом в года
            addHours(t.hours);                                //Парное сложение часов с переходом в дни
            addMinutes(t.minutes);                            //Парное сложение минут с переходом в часы
            addSeconds((int)t.seconds);                       //Парное сложение секунд с переходом в минуты
            addMicroseconds(t.microseconds);                  //Парное сложение микросекунд с переходом в секунды
            equate();                                         //Выравнивание значений в массиве
        }

        /// <summary>
        ///Метод вычитания времени
        /// </summary>
        public void subtractTime(Time t)
        {
            subtractYears((int)t.years);                      //Вычитание годов
            subtractDays(t.days);                             //Вычитание дней
            subtractHours(t.hours);                           //Вычитание часов
            subtractMinutes(t.minutes);                       //Вычитание минут
            subtractSeconds((int)t.seconds);                  //Вычитание секунд
            subtractMicroseconds(t.microseconds);             //Вычитание микросекунд
            equateMinus();                                    //Выравнивание значений в массиве
        }

        /// <summary>
        ///Метод добавления просчета по годам; y-год
        /// </summary>
        public void addYears(int y)
        {
            years += y;                                       //Складываем года
        }

        /// <summary>
        ///Метод добавления просчета по дням; d-день
        /// </summary>
        public void addDays(int d)
        {
            days += (short)(d);                               //Складываем дни                         
            equate();                                         //Округление значений времени (от избытка)
        }

        /// <summary>
        ///Метод добавления просчета по часам; h-час
        /// </summary>
        public void addHours(int h)
        {
            hours += h;                                       //Складываем часы
            equate();                                         //Округление значений времени (от избытка)
        }

        /// <summary>
        ///Метод добавления просчета по минутам; m-минуты
        /// </summary>
        public void addMinutes(int m)
        {
            minutes += m;                                     //Складываем минуты
            equate();                                         //Округление значений времени (от избытка)
        }

        /// <summary>
        ///Метод добавления просчета по секундам; s-секунды
        /// </summary>
        public void addSeconds(int s)
        {
            seconds += s;                                     //Складываем секунды
            equate();                                         //Округление значений времени (от избытка)
        }

        /// <summary>
        ///Метод добавления просчета по микросекундам; ms-микросекунды
        /// </summary>
        public void addMicroseconds(int ms)
        {
            microseconds += (short)(ms);                      //Складываем микросекунды
            equate();                                         //Округление значений времени (от избытка)
        }

        /// <summary>
        ///Метод вычитания лет
        /// </summary>
        public void subtractYears(int y)
        {
            years -= y;                                       //Вычитаем года
        }

        /// <summary>
        ///Метод вычитания дней;
        /// </summary>
        public void subtractDays(int d)
        {
            days -= (short)(d);                               //Вычитаем дни
            equateMinus();                                    //Округление значений времени (при недостатке) 
        }

        /// <summary>
        ///Метод вычитания часов;
        /// </summary>
        public void subtractHours(int h)
        {
            hours -= h;                                       //Вычитаем часы
            equateMinus();                                    //Округление значений времени (при недостатке) 
        }

        /// <summary>
        ///Метод вычитания минут;
        /// </summary>
        public void subtractMinutes(int m)
        {
            minutes -= m;                                     //Вычитаем минуты
            equateMinus();                                    //Округление значений времени (при недостатке) 
        }

        /// <summary>
        ///Метод вычитания секунд; 
        /// </summary>
        public void subtractSeconds(int s)
        {
            seconds -= s;                                     //Вычитаем секунжы
            equateMinus();                                    //Округление значений времени (при недостатке) 
        }

        /// <summary>
        ///Метод вычитания микросекунд; 
        /// </summary>
        public void subtractMicroseconds(int ms)
        {
            microseconds -= (short)(ms);                      //Вычитаем микросекунды
            equateMinus();                                    //Округление значений времени (при недостатке) 
        }

        /// <summary>
        ///Метод получения лет
        /// </summary>
        public long getYears()
        {
            return years;                                     //Возврат лет
        }

        /// <summary>
        ///Метод получения дней
        /// </summary>
        public short getDays()
        {
            return days;                                      //Возврат дней
        }

        /// <summary>
        ///Метод получения часов
        /// </summary>
        public long getHours()
        {
            return hours;                                     //Возврат часов
        }

        /// <summary>
        ///Метод получения минут
        /// </summary>
        public long getMinutes()
        {
            return minutes;                                   //Возврат минут
        }

        /// <summary>
        ///Метод получения секунд
        /// </summary>
        public long getSeconds()
        {
            return (int)(seconds);                            //Возврат секунд
        }

        /// <summary>
        ///Метод получения микросекунд
        /// </summary>
        public long getMicroseconds()
        {
            return microseconds;                              //Возврат микросекунд
        }

        //todo: и здесь проверка на - //%%%

        /// <summary>
        ///Метод установки лет
        /// </summary>
        public void setYears(long y)
        {
                                                              //Присвоение лет и
            if (y >= 0) { years = y; };                        //Проверка на отр. значение
        }

        /// <summary>
        ///Метод установки дней
        /// </summary>
        public void setDays(short d)
        {                                                      //Присвоение дней и
            if (d >= 0) { days = d; };                         //Проверка на отр. значение
        }

        /// <summary>
        ///Метод установки часов
        /// </summary>
        public void setHours(int h)
        {
                                                               //Присвоение часов и 
            if (h >= 0) { hours = h; };                        //Проверка на отр. значение
        }

        /// <summary>
        ///Метод установки минут
        /// </summary>
        public void setMinutes(int m)
        {
                                                               //Присвоение минут и
            if (m >= 0) { minutes = m; };                      //Проверка на отр. значение
        }

        /// <summary>
        ///Метод установки секунд
        /// </summary>
        public void setSeconds(long s)
        {
                                                               //Присвоение секунд и
            if (s >= 0) { seconds = s; };                      //Проверка на отр. значение
        }

        /// <summary>
        ///Метод установки микросекунд
        /// </summary>
        public void setMicroseconds(short ms)
        {
                                                                //Присвоение микросекунд и
            if (ms >= 0) { microseconds = ms; };                //Проверка на отр. значение
        }

        /// <summary>
        ///Метод преобразования всех значений в микросекунды
        /// </summary>
        public long toMicroseconds()
        {
            return years * 31536000000L + days * 86400000L + hours * 3600000L + minutes * 60000L + seconds * 1000L + microseconds;  //Перевод значения в микросекунды
        }

        /// <summary>
        ///Метод преобразования всех значений в секунды
        /// </summary>
        public long toSeconds()
        {
            return years * 31536000 + days * 86400 + hours * 3600 + minutes * 60 + seconds; //Перевод значения в секунды
        }

        /// <summary>
        ///Метод преобразования всех значений в минуты
        /// </summary>
        public long toMinutes()
        {
            return years * 525600 + days * 1440 + hours * 60 + minutes; //Перевод значения в минуты
        }

        /// <summary>
        ///Метод преобразования всех значений в часы
        /// </summary>
        public long toHours()
        {
            return years * 8760 + days * 24 + hours;          //Перевод значения в часы
        }

        /// <summary>
        ///Метод преобразования всех значений в дни
        /// </summary>
        public long toDays()
        {
            return years * 365 + days;                        //Перевод значения в дни
        }

        /// <summary>
        ///Метод преобразования всех значений в года
        /// </summary>
        public long toYears()
        {
            return years;                                     //Перевод значения в года
        }

        /// <summary>
        ///Метод вывода значений значений массива в текстовую строку
        /// </summary>
        public override string ToString()                                                     //Переопределение ToString из базового класса Object
        {
            return $"Y{years}: D{days}: H{hours}: M{minutes}: S{seconds}: MS{microseconds}";  //Перевод всех значений в строку
        }

        /// <summary>
        ///Метод вывода реального времени в секундах с 1970 года
        /// </summary>
        public static long REALTime()
        {
            DateTime currentTime = DateTime.Now;              //Забор системного времени
            long unixTime = ((DateTimeOffset)currentTime).ToUnixTimeSeconds();  //Забор системного времени в секундах*
            return unixTime;                                  //Возврат времени в секундах
        }

        /// <summary>
        ///Метод создания массива с времянными переменными
        /// </summary>
        public static Time[] createDynamicArray(int size)     
        {
            Time[] timeArray = new Time[size];                //Создание времянного массива
            for (int i = 0; i < size; i++)                    //Цикл, который прокручивается i-кол-во раз
            {
                timeArray[i] = new Time();                    //Выделение памяти time
            }
            return timeArray;                                 //Возврат времянного массива
        }

        /// <summary>
        ///Метод чтения с текстового файла двух массивов 
        /// </summary>
        public static void readTwoObjectsFromFile(Time t1, Time t2, string filename)
        {
            try                                               //Попытаться...
            {
                using (StreamReader inFile = new StreamReader(filename))  //Чтение файла
                {
                    string line1 = inFile.ReadLine();         //Считывание файла (первой строки)
                    if (line1 == null)                        //Если первая строка нулевая
                    {
                        MessageBox.Show("Файл пуст или не содержит достаточно данных.");  //Вывод системного сообщения
                        return;                               //Вернуть (завершить)
                    }

                    var data1 = line1.Split(' ');             //Формироание переменной первой строки
                    long y, s;                                //y - переменная лет; s - переменная секунд;
                    int h, m;                                 //h - переменная часов; m - переменная минут;
                    short d, ms;                              //d - переменная дней; ms - переменная микросекунд;

                    y = long.Parse(data1[0]);                 //Взятие значения с первой строки с первого числа
                    d = short.Parse(data1[1]);                //Взятие значения с первой строки с второго числа
                    h = int.Parse(data1[2]);                  //Взятие значения с первой строки с третьего числа
                    m = int.Parse(data1[3]);                  //Взятие значения с первой строки с четвертого числа
                    s = long.Parse(data1[4]);                 //Взятие значения с первой строки с пятого числа
                    ms = short.Parse(data1[5]);               //Взятие значения с первой строки с шестого числа
                    t1.setTime(y, d, h, m, s, ms);            //Массовое присвоение значений массива с первой строки

                    string line2 = inFile.ReadLine();         //Считывание файла (второй строки)
                    if (line2 == null)                        //Если вторая строка нулевая
                    {
                        throw new ArgumentException();  //Вывод системного сообщения
                    }
                    var data2 = line2.Split(' ');             //Формироание переменной второй строки

                    y = long.Parse(data2[0]);                 //Взятие значения с второй строки с первого числа
                    d = short.Parse(data2[1]);                //Взятие значения с второй строки с второго числа
                    h = int.Parse(data2[2]);                  //Взятие значения с второй строки с третьего числа
                    m = int.Parse(data2[3]);                  //Взятие значения с второй строки с четвертого числа
                    s = long.Parse(data2[4]);                 //Взятие значения с второй строки с пятого числа
                    ms = short.Parse(data2[5]);               //Взятие значения с второй строки с шестого числа
                    t2.setTime(y, d, h, m, s, ms);            //Массовое присвоение значений массива с второй строки
                }
            }
            catch (Exception)                              //При неудаче...
            {
                throw new ArgumentException(); //%%%
            }
        }

        /// <summary>
        ///Метод чтения с текстового файла одного массива
        /// </summary>
        public static void readOneObjectFromFile(Time t1, string filename)
        {
            try                                               //Попытаться...
            {
                using (StreamReader inFile = new StreamReader(filename))  //Чтение файла
                {
                    string line1 = inFile.ReadLine();         //Считывание файла (первой строки)
                    if (line1 == null)                        //Если первая строка нулевая
                    {
                        MessageBox.Show("Файл пуст или не содержит достаточно данных.");  //Вывод системного сообщения
                        return;                               //Вернуть (завершить)
                    }

                    var data1 = line1.Split(' ');             //Формироание переменной первой строки
                    long y, s;                                //y - переменная лет; s - переменная секунд;
                    int h, m;                                 //h - переменная часов; m - переменная минут;
                    short d, ms;                              //d - переменная дней; ms - переменная микросекунд;

                    y = long.Parse(data1[0]);                 //Взятие значения с первой строки с первого числа
                    d = short.Parse(data1[1]);                //Взятие значения с первой строки с второго числа
                    h = int.Parse(data1[2]);                  //Взятие значения с первой строки с третьего числа
                    m = int.Parse(data1[3]);                  //Взятие значения с первой строки с четвертого числа
                    s = long.Parse(data1[4]);                 //Взятие значения с первой строки с пятого числа
                    ms = short.Parse(data1[5]);               //Взятие значения с первой строки с шестого числа
                    t1.setTime(y, d, h, m, s, ms);            //Массовое присвоение значений массива с первой строки
                }
            }
            catch (Exception)                              //При неудаче...
            {
                throw new ArgumentException(); //%%%
            }
        }

        //todo 1 параметр
        /// <summary>
        ///Метод сохранения с текстового файла двух массивов 
        /// </summary>
        public static void writeTwoObjectsToFile(Time t1, Time t2, string filename)
        {
            try                                               //Попытаться...
            {
                using (StreamWriter outFile = new StreamWriter(filename))  //Запись файла
                {
                    long y, s;                                //y - переменная лет; s - переменная секунд;
                    int h, m;                                 //h - переменная часов; m - переменная минут;
                    short d, ms;                              //d - переменная дней; ms - переменная микросекунд;

                    t1.getTime(out y, out d, out h, out m, out s, out ms);  //Получение значений с массива
                    outFile.WriteLine($"{y} {d} {h} {m} {s} {ms}");  //Вывод первой строки со значениями в файл 

                    t2.getTime(out y, out d, out h, out m, out s, out ms);  //Получение значений с массива
                    outFile.Write($"{y} {d} {h} {m} {s} {ms}");  //Вывод второй строки со значениями в файл
                }
            }
            catch (Exception)                              //Попытаться...
            {
                throw new ArgumentException(); //%%%
            }
        }

        /// <summary>
        ///Метод сохранения с текстового файла одного массива
        /// </summary>
        public static void writeOneObjectToFile(Time t1, string filename)
        {
            try                                               //Попытаться...
            {
                using (StreamWriter outFile = new StreamWriter(filename))  //Запись файла
                {
                    long y, s;                                //y - переменная лет; s - переменная секунд;
                    int h, m;                                 //h - переменная часов; m - переменная минут;
                    short d, ms;                              //d - переменная дней; ms - переменная микросекунд;

                    t1.getTime(out y, out d, out h, out m, out s, out ms);  //Получение значений с массива
                    outFile.WriteLine($"{y} {d} {h} {m} {s} {ms}");  //Вывод первой строки со значениями в файл 
                }
            }
            catch (Exception)                              //Попытаться...
            {
                throw new ArgumentException(); //%%%
            }
        }

        /// <summary>
        ///Метод переприсвоения всех значений во времянной массив
        /// </summary>
        public void setTime(long y, short d, int h, int m, long s, short ms)  
        {
            this.setYears(y);                                 //Проверки на отрицательные значения и установку значений через setеры
            this.setDays(d);
            this.setHours(h);
            this.setMinutes(m);
            this.setSeconds(s);
            this.setMicroseconds(ms);
        }

        /// <summary>
        ///Метод переполучения всех значений из времянного массива
        /// </summary>
        public void getTime(out long y, out short d, out int h, out int m, out long s, out short ms)  
        {
            y = years;                                        //Получение времени лет массовому гетеру 
            d = days;                                         //Получение времени дней массовому гетеру 
            h = hours;                                        //Получение времени часов массовому гетеру 
            m = minutes;                                      //Получение времени минут массовому гетеру 
            s = seconds;                                      //Получение времени секунд массовому гетеру 
            ms = microseconds;                                //Получение времени микросекунд массовому гетеру 
            equateMinus();                                    //Проверка на отрицательное значение
        }

        //todo сделать функцией
        /// <summary>
        ///Метод-assert для проверки функции разработчиком
        /// </summary>
        public static void AssertMethods()                           //Assert проверка - для проверки базовых функций
        {
            const string fname = "Assertfile.txt";
            Time assertA = new Time();
            Time assertB = new Time();
            Time assertC = new Time();

            assertA.setTime(13, 773, 54, 18, 145, 200);
            assertB.setTime(4, 4, 4, 4, 4, 4);
            assertC.setTime(0, 0, -18, 0, 0, 0);

            assertA.equate();

            assertA.setYears(15);
            assertA.setDays(45);
            assertA.setHours(6);
            assertA.setMinutes(20);
            assertA.setSeconds(25);
            assertA.setMicroseconds(200);

            Debug.Assert(assertA.getYears() == 15);
            Debug.Assert(assertA.getDays() == 45);
            Debug.Assert(assertA.getHours() == 6);
            Debug.Assert(assertA.getMinutes() == 20);
            Debug.Assert(assertA.getSeconds() == 25);
            Debug.Assert(assertA.getMicroseconds() == 200);

            Debug.Assert(assertB.toYears() == 4);
            Debug.Assert(assertB.toDays() == 1464);
            Debug.Assert(assertB.toHours() == 35140);
            Debug.Assert(assertB.toMinutes() == 2108404);
            Debug.Assert(assertB.toSeconds() == 126504244);
            Debug.Assert(assertB.toMicroseconds() == 126504244004);

            assertB.addYears(2);
            assertB.addDays(2);
            assertB.addHours(2);
            assertB.addMinutes(2);
            assertB.addSeconds(2);
            assertB.addMicroseconds(2);

            Debug.Assert(assertB.getYears() == 6);
            Debug.Assert(assertB.getDays() == 6);
            Debug.Assert(assertB.getHours() == 6);
            Debug.Assert(assertB.getMinutes() == 6);
            Debug.Assert(assertB.getSeconds() == 6);
            Debug.Assert(assertB.getMicroseconds() == 6);

            assertB.subtractYears(3);
            assertB.subtractDays(3);
            assertB.subtractHours(3);
            assertB.subtractMinutes(3);
            assertB.subtractSeconds(3);
            assertB.subtractMicroseconds(3);

            Debug.Assert(assertB.getYears() == 3);
            Debug.Assert(assertB.getDays() == 3);
            Debug.Assert(assertB.getHours() == 3);
            Debug.Assert(assertB.getMinutes() == 3);
            Debug.Assert(assertB.getSeconds() == 3);
            Debug.Assert(assertB.getMicroseconds() == 3);

            assertC.equateMinus();
            assertB = assertC;
            Debug.Assert(assertB.getYears() == 0);
            Debug.Assert(assertB.getDays() == 0);
            Debug.Assert(assertB.getHours() == 0);
            Debug.Assert(assertB.getMinutes() == 0);
            Debug.Assert(assertB.getSeconds() == 0);
            Debug.Assert(assertB.getMicroseconds() == 0);

            //todo ToString %%%
            string assertingSTR = "Y15: D45: H6: M20: S25: MS200";
            Debug.Assert(assertingSTR == assertA.ToString());

            assertB.setYears(15);
            assertB.setDays(45);
            assertB.setHours(6);
            assertB.setMinutes(20);
            assertB.setSeconds(25);
            assertB.setMicroseconds(200);

            assertC.setYears(15);
            assertC.setDays(45);
            assertC.setHours(6);
            assertC.setMinutes(20);
            assertC.setSeconds(25);
            assertC.setMicroseconds(200);

            writeOneObjectToFile(assertA, fname);

            assertA.setYears(0);
            assertA.setDays(0);
            assertA.setHours(0);
            assertA.setMinutes(0);
            assertA.setSeconds(0);
            assertA.setMicroseconds(0);

            readOneObjectFromFile(assertA, fname);

            Debug.Assert(assertA.getYears() == assertB.getYears());
            Debug.Assert(assertA.getDays() == assertB.getDays());
            Debug.Assert(assertA.getHours() == assertB.getHours());
            Debug.Assert(assertA.getMinutes() == assertB.getMinutes());
            Debug.Assert(assertA.getSeconds() == assertB.getSeconds());
            Debug.Assert(assertA.getMicroseconds() == assertB.getMicroseconds());

            writeTwoObjectsToFile(assertA, assertB, fname);


            readTwoObjectsFromFile(assertA, assertB, fname);

            Debug.Assert(assertA.getYears() == assertB.getYears());
            Debug.Assert(assertA.getDays() == assertB.getDays());
            Debug.Assert(assertA.getHours() == assertB.getHours());
            Debug.Assert(assertA.getMinutes() == assertB.getMinutes());
            Debug.Assert(assertA.getSeconds() == assertB.getSeconds());
            Debug.Assert(assertA.getMicroseconds() == assertB.getMicroseconds());

            Debug.Assert(assertC.getYears() == assertB.getYears());
            Debug.Assert(assertC.getDays() == assertB.getDays());
            Debug.Assert(assertC.getHours() == assertB.getHours());
            Debug.Assert(assertC.getMinutes() == assertB.getMinutes());
            Debug.Assert(assertC.getSeconds() == assertB.getSeconds());
            Debug.Assert(assertC.getMicroseconds() == assertB.getMicroseconds());
        }
    }
}