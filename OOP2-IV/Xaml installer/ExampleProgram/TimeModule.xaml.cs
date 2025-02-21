using System.Windows.Forms;
using System;
using System.IO;
namespace TimeCalc
{
    public class Time
    {

        public long years;
        public long seconds; //�������� ���� ����������                                                                          
        public int hours;
        public int minutes; //���������� ��� ������������, � �������� ������������ ����������������� �� �����
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
            seconds += microseconds / 1000;                   // ���������� ������ ������ � �������������
            microseconds %= 1000;                             // ���������� ������������

            minutes += (int)(seconds / 60);                        // ���������� ������ ����� � ��������
            seconds %= 60;                                  // ���������� �������

            hours += minutes / 60;                          // ���������� ������ ����� � �������
            minutes %= 60;                                  // ���������� ������

            days += (short)(hours / 24);                             // ���������� ������ ���� � �����
            hours %= 24;                                    // ���������� ����

            years += days / 365;                            // ���������� ������ ��� � ����
            days %= 365;                                    // ���������� ���
        }

        public void equateMinus()
        {
            if (seconds > 0)
            {
                seconds -= 1;                   // ���������� ������ ������ � �������������
                microseconds += 1000;                             // ���������� ������������
            }

            if (minutes > 0)
            {
                minutes -= 1;                        // ���������� ������ ����� � ��������
                seconds += 60;                                  // ���������� �������
            }
            if (hours > 0)
            {
                hours -= 1;                          // ���������� ������ ����� � �������
                minutes += 60;                                  // ���������� ������
            }
            if (days > 0)
            {
                days -= 1;                             // ���������� ������ ���� � �����
                hours += 24;                                    // ���������� ����
            }
            if (years > 0)
            {
                years -= 1;                            // ���������� ������ ��� � ����
                days += 365;                                    // ���������� ���
            }
            equate();
        }

        public void AddTime(Time t)
        {
            addYears((int)t.years);                              //������ �������� �����
            addDays(t.days);                                //������ �������� ���� � ��������� � ����
            addHours(t.hours);                              //������ �������� ����� � ��������� � ���
            addMinutes(t.minutes);                          //������ �������� ����� � ��������� � ����
            addSeconds((int)t.seconds);                          //������ �������� ������ � ��������� � ������
            addMicroseconds(t.microseconds);                //������ �������� ����������� � ��������� � �������
            equate();                                       //������������ �������� � �������
        }

        public void subtractTime(Time t)
        {
            subtractYears((int)t.years);                         //��������� �����
            subtractDays(t.days);                           //��������� ����
            subtractHours(t.hours);                         //��������� �����
            subtractMinutes(t.minutes);                     //��������� �����
            subtractSeconds((int)t.seconds);                     //��������� ������
            subtractMicroseconds(t.microseconds);           //��������� �����������
            equateMinus();                                       //������������ �������� � �������
        }

        ///����� ���������� �������� �� �����; y-���
        public void addYears(int y)
        {
            years += y;                                     //���������� ����
        }

        ///����� ���������� �������� �� ����; d-����
        public void addDays(int d)
        {
            days += (short)(d);                                      //���������� ���                         
            equate();
        }

        ///����� ���������� �������� �� �����; h-���
        public void addHours(int h)
        {
            hours += h;                                     //���������� ����
            equate();
        }

        ///����� ���������� �������� �� �������; m-������
        public void addMinutes(int m)
        {
            minutes += m;                                   //���������� ������
            equate();
        }

        ///����� ���������� �������� �� ��������; s-�������
        public void addSeconds(int s)
        {
            seconds += s;                                   //���������� �������
            equate();
        }

        ///����� ���������� �������� �� �������������; ms-������������
        public void addMicroseconds(int ms)
        {
            microseconds += (short)(ms);                                   //���������� ������������
            equate();
        }

        ///����� ��������� ���
        public void subtractYears(int y)
        {
            years -= y;
        }

        ///����� ��������� ����;
        public void subtractDays(int d)
        {
            days -= (short)(d);
            equateMinus();
        }

        ///����� ��������� �����;
        public void subtractHours(int h)
        {
            hours -= h;
            equateMinus();
        }

        ///����� ��������� �����;
        public void subtractMinutes(int m)
        {
            minutes -= m;
            equateMinus();
        }

        ///����� ��������� ������; 
        public void subtractSeconds(int s)
        {
            seconds -= s;
            equateMinus();
        }

        ///����� ��������� �����������; 
        public void subtractMicroseconds(int ms)
        {
            microseconds -= (short)(ms);
            equateMinus();
        }

        ///����� ��������� ���
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
                    Console.WriteLine("�� ������� ������� ���� ��� ������.");
                    return;
                }

                // ������ ������ ������ �� ����� � ���������� �� �����
                string line1 = inFile.ReadLine();
                if (line1 == null)
                {
                    Console.WriteLine("���� ���� ��� �� �������� ���������� ������.");
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
                    Console.WriteLine("���� �������� ������ ���� ������ ��� �� �������� ���������� ������.");
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
                    Console.WriteLine("�� ������� ������� ���� ��� ������.");
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
            // ����������� ������ � ������ JSON � ���������� � ����
            string json = JsonSerializer.Serialize(time);
            File.WriteAllText(filename, json);
        }

        public static Time LoadTimeFromFile(string filename)
        {
            // ������ ������ �� ����� � ������������� �� �� ������� JSON � ������ Time
            string json = File.ReadAllText(filename);
            return JsonSerializer.Deserialize<Time>(json);
        }*/


        // ������� ����� ToString() ��� ������ Time ��� �������� ������ ��������
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

        //�������� ���������� ��� ������ ��������
        //Time t1, t2;                                             //����������� ���� ����� ������� 
        //Time.assertCheck(t1, t2);                                   //�������� ��� ������������� -assert
    }
}