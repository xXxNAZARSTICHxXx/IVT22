using System.Windows.Forms;
using System;
using System.IO;
namespace TimeCalc
{
    public class Time
    {

        public long years;
        public long seconds; //Закрытая зона объявлений                                                                          
        public int hours;
        public int minutes; //Переменные для конструктора, с которыми пользователь взаимодейстровать не может
        public short days;
        public short microseconds;

        public Time(long y = 0, short d = 0, int h = 0, int m = 0, long s = 0, short ms = 0)
        {
            years = y;
            days = d;
            hours = h;
            minutes = m;
            seconds = s;
            microseconds = ms;
        }

        public void equate()
        {
            seconds += microseconds / 1000;                   // Количество полных секунд в микросекундах
            microseconds %= 1000;                             // Оставшиеся микросекунды

            minutes += (int)(seconds / 60);                        // Количество полных минут в секундах
            seconds %= 60;                                  // Оставшиеся секунды

            hours += minutes / 60;                          // Количество полных часов в минутах
            minutes %= 60;                                  // Оставшиеся минуты

            days += (short)(hours / 24);                             // Количество полных дней в часах
            hours %= 24;                                    // Оставшиеся часы

            years += days / 365;                            // Количество полных лет в днях
            days %= 365;                                    // Оставшиеся дни
        }

        public void equateMinus()
        {
            if (seconds > 0)
            {
                seconds -= 1;                   // Количество полных секунд в микросекундах
                microseconds += 1000;                             // Оставшиеся микросекунды
            }

            if (minutes > 0)
            {
                minutes -= 1;                        // Количество полных минут в секундах
                seconds += 60;                                  // Оставшиеся секунды
            }
            if (hours > 0)
            {
                hours -= 1;                          // Количество полных часов в минутах
                minutes += 60;                                  // Оставшиеся минуты
            }
            if (days > 0)
            {
                days -= 1;                             // Количество полных дней в часах
                hours += 24;                                    // Оставшиеся часы
            }
            if (years > 0)
            {
                years -= 1;                            // Количество полных лет в днях
                days += 365;                                    // Оставшиеся дни
            }
            equate();
        }

        public void AddTime(Time t)
        {
            addYears((int)t.years);                              //Парное сложение годов
            addDays(t.days);                                //Парное сложение дней с переходом в года
            addHours(t.hours);                              //Парное сложение часов с переходом в дни
            addMinutes(t.minutes);                          //Парное сложение минут с переходом в часы
            addSeconds((int)t.seconds);                          //Парное сложение секунд с переходом в минуты
            addMicroseconds(t.microseconds);                //Парное сложение микросекунд с переходом в секунды
            equate();                                       //Выравнивание значений в массиве
        }

        public void subtractTime(Time t)
        {
            subtractYears((int)t.years);                         //Вычитание годов
            subtractDays(t.days);                           //Вычитание дней
            subtractHours(t.hours);                         //Вычитание часов
            subtractMinutes(t.minutes);                     //Вычитание минут
            subtractSeconds((int)t.seconds);                     //Вычитание секунд
            subtractMicroseconds(t.microseconds);           //Вычитание микросекунд
            equateMinus();                                       //Выравнивание значений в массиве
        }

        ///Метод добавления просчета по годам; y-год
        public void addYears(int y)
        {
            years += y;                                     //Складываем года
        }

        ///Метод добавления просчета по дням; d-день
        public void addDays(int d)
        {
            days += (short)(d);                                      //Складываем дни                         
            equate();
        }

        ///Метод добавления просчета по часам; h-час
        public void addHours(int h)
        {
            hours += h;                                     //Складываем часы
            equate();
        }

        ///Метод добавления просчета по минутам; m-минуты
        public void addMinutes(int m)
        {
            minutes += m;                                   //Складываем минуты
            equate();
        }

        ///Метод добавления просчета по секундам; s-секунды
        public void addSeconds(int s)
        {
            seconds += s;                                   //Складываем секунды
            equate();
        }

        ///Метод добавления просчета по микросекундам; ms-микросекунды
        public void addMicroseconds(int ms)
        {
            microseconds += (short)(ms);                                   //Складываем микросекунды
            equate();
        }

        ///Метод вычитания лет
        public void subtractYears(int y)
        {
            years -= y;
        }

        ///Метод вычитания дней;
        public void subtractDays(int d)
        {
            days -= (short)(d);
            equateMinus();
        }

        ///Метод вычитания часов;
        public void subtractHours(int h)
        {
            hours -= h;
            equateMinus();
        }

        ///Метод вычитания минут;
        public void subtractMinutes(int m)
        {
            minutes -= m;
            equateMinus();
        }

        ///Метод вычитания секунд; 
        public void subtractSeconds(int s)
        {
            seconds -= s;
            equateMinus();
        }

        ///Метод вычитания микросекунд; 
        public void subtractMicroseconds(int ms)
        {
            microseconds -= (short)(ms);
            equateMinus();
        }

        ///Метод получения лет
        public long getYears()
        {
            return years;
        }

        public short getDays()
        {
            return days;
        }

        public long getHours()
        {
            return hours;
        }

        public long getMinutes()
        {
            return minutes;
        }

        public long getSeconds()
        {
            return (int)(seconds);
        }

        public long getMicroseconds()
        {
            return microseconds;
        }

        public void setYears(long y)
        {
            years = y;
        }

        public void setDays(short d)
        {
            days = d;
        }

        public void setHours(int h)
        {
            hours = h;
        }

        public void setMinutes(int m)
        {
            minutes = m;
        }

        public void setSeconds(long s)
        {
            seconds = s;
        }

        public void setMicroseconds(short ms)
        {
            microseconds = ms;
        }

        public long toMicroseconds()
        {
            return years * 31536000000L + days * 86400000L + hours * 3600000L + minutes * 60000L + seconds * 1000L + microseconds;
        }

        public long toSeconds()
        {
            return years * 31536000 + days * 86400 + hours * 3600 + minutes * 60 + seconds;
        }

        public long toMinutes()
        {
            return years * 525600 + days * 1440 + hours * 60 + minutes;
        }

        public long toHours()
        {
            return years * 8760 + days * 24 + hours;
        }

        public long ToDays()
        {
            return years * 365 + days;
        }

        public long toYears()
        {
            return years;
        }

        public string toString()
        {
            return $"Y{years}: D{days}: H{hours}: M{minutes}: S{seconds}: MS{microseconds}";
        }

        public static long REALTime()
        {
            DateTime currentTime = DateTime.Now;
            long unixTime = ((DateTimeOffset)currentTime).ToUnixTimeSeconds();
            return unixTime;
        }

        public static Time[] createDynamicArray(int size)
        {
            Time[] timeArray = new Time[size];
            for (int i = 0; i < size; i++)
            {
                timeArray[i] = new Time();
            }
            return timeArray;
        }

        public static void readTwoObjectsInFile(Time t1, Time t2, string filename)
        {
            using (StreamReader inFile = new StreamReader(filename))
            {
                if (inFile == null)
                {
                    Console.WriteLine("Не удалось открыть файл для чтения.");
                    return;
                }

                // Чтение первой строки из файла и разделение на части
                string line1 = inFile.ReadLine();
                if (line1 == null)
                {
                    Console.WriteLine("Файл пуст или не содержит достаточно данных.");
                    return;
                }
                var data1 = line1.Split(' ');
                long y, s;
                int h, m;
                short d, ms;

                y = long.Parse(data1[0]);
                d = short.Parse(data1[1]);
                h = int.Parse(data1[2]);
                m = int.Parse(data1[3]);
                s = long.Parse(data1[4]);
                ms = short.Parse(data1[5]);
                t1.setTime(y, d, h, m, s, ms);

                string line2 = inFile.ReadLine();
                if (line2 == null)
                {
                    Console.WriteLine("Файл содержит только одну строку или не содержит достаточно данных.");
                    return;
                }
                var data2 = line2.Split(' ');

                y = long.Parse(data2[0]);
                d = short.Parse(data2[1]);
                h = int.Parse(data2[2]);
                m = int.Parse(data2[3]);
                s = long.Parse(data2[4]);
                ms = short.Parse(data2[5]);
                t2.setTime(y, d, h, m, s, ms);
            }
        }

        public static void writeTwoObjectsInFile(Time t1, Time t2, string filename)
        {
            using (StreamWriter outFile = new StreamWriter(filename))
            {
                if (outFile == null)
                {
                    Console.WriteLine("Не удалось открыть файл для записи.");
                    return;
                }

                long y, s;
                int h, m;
                short d, ms;

                t1.getTime(out y, out d, out h, out m, out s, out ms);
                outFile.WriteLine($"{y} {d} {h} {m} {s} {ms}");

                t2.getTime(out y, out d, out h, out m, out s, out ms);
                outFile.Write($"{y} {d} {h} {m} {s} {ms}");
            }
        }

        public void setTime(long y, short d, int h, int m, long s, short ms)
        {
            years = y;
            days = d;
            hours = h;
            minutes = m;
            seconds = s;
            microseconds = ms;
        }

        public void getTime(out long y, out short d, out int h, out int m, out long s, out short ms)
        {
            y = years;
            d = days;
            h = hours;
            m = minutes;
            s = seconds;
            ms = microseconds;
        }

        /*public static void SaveTimeToFile(string filename, Time time)
        {
            // Сериализуем объект в формат JSON и записываем в файл
            string json = JsonSerializer.Serialize(time);
            File.WriteAllText(filename, json);
        }

        public static Time LoadTimeFromFile(string filename)
        {
            // Читаем данные из файла и десериализуем их из формата JSON в объект Time
            string json = File.ReadAllText(filename);
            return JsonSerializer.Deserialize<Time>(json);
        }*/


        // Добавлю метод ToString() для класса Time для удобного вывода значений
        //public override string ToString()
        //{
        //    return $"Y{years}: D{days}: H{hours}: M{minutes}: S{seconds}: MS{microseconds}";
        //}

        /*public void AssertMethods()
        {
                Time assertA = new Time();
                Time assertB = new Time();

                assertA.setTime(13, 773, 54, 18, 145, 200);
                assertB.setTime(4, 4, 4, 4, 4, 4);

                assertA.equate();
                Assert.AreEqual(assertA.ToString(), "Y15: D45: H6: M20: S25: MS200");

                assertA.addTime(assertA);
                Assert.AreEqual(assertA.ToString(), "Y30: D90: H12: M40: S50: MS400");

                assertA.subtractTime(assertB);
                Assert.AreEqual(assertA.ToString(), "Y26: D86: H8: M36: S46: MS396");

                Assert.AreEqual(assertA.getYears(), 26);
                Assert.AreEqual(assertA.getDays(), 86);
                Assert.AreEqual(assertA.getHours(), 8);
                Assert.AreEqual(assertA.getMinutes(), 36);
                Assert.AreEqual(assertA.getSeconds(), 46);
                Assert.AreEqual(assertA.getMicroseconds(), 396);

                Assert.AreEqual(assertB.toYears(), 4);
                Assert.AreEqual(assertB.toDays(), 1464);
                Assert.AreEqual(assertB.toHours(), 35140);
                Assert.AreEqual(assertB.toMinutes(), 2108404);
                Assert.AreEqual(assertB.toSeconds(), 126504244);
                Assert.AreEqual(assertB.toMicroseconds(), 1950192420);

        }*/

        //Создание переменных для взятия значений
        //Time t1, t2;                                             //определение двух групп времени 
        //Time.assertCheck(t1, t2);                                   //Проверка для программистов -assert
    }
}