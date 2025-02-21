//���� ����� �������� ���-22
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
    /// ����� time � ������� ���������� ��� ������ � �������, ��������� ��� ������ ���������
    /// </summary>
    public class Time
    {  
        /// <summary>
        /// years - ���������� ����������, ������� ����� ��� �������� ������������ ���������� ������� � �����������, �������� ����
        /// </summary>
        public long years;
        /// <summary>
        /// seconds - ���������� ����������, ������� ����� ��� �������� ������������ ���������� ������� � �����������, �������� �������
        /// </summary>
        public long seconds;
        /// <summary>
        /// hours - ���������� ����������, ������� ����� ��� �������� ������������ ���������� ������� � �����������, �������� ����
        /// </summary>
        public int hours;
        /// <summary>
        /// minutes - ���������� ����������, ������� ����� ��� �������� ������������ ���������� ������� � �����������, �������� ������
        /// </summary>
        public int minutes;
        /// <summary>
        /// days - ���������� ����������, ������� ����� ��� �������� ������������ ���������� ������� � �����������, �������� ���
        /// </summary>
        public short days;
        /// <summary>
        /// microseconds - ���������� ����������, ������� ����� ��� �������� ������������ ���������� ������� � �����������, �������� ������������
        /// </summary>
        public short microseconds;

        //todo: ������� ����� �������� �� ���. �������� �����
        /// <summary>
        ///����������� - ����� �������� ������� y-��� d-���� h-��� m-������ s-������� � ������������� �� ���. ��������
        /// </summary>
        public Time(long y = 0, short d = 0, int h = 0, int m = 0, long s = 0, short ms = 0)
        {

            this.setYears(y);                                 //�������� �� ������������� �������� � ��������� �������� ����� set���
            this.setDays(d);
            this.setHours(h);
            this.setMinutes(m);
            this.setSeconds(s);
            this.setMicroseconds(ms);
        }

        /// <summary>
        ///������������ ������� � �������
        /// </summary>
        public void equate()
        {
            seconds += microseconds / 1000;                   // ���������� ������ ������ � �������������
            microseconds %= 1000;                             // ���������� ������������

            minutes += (int)(seconds / 60);                   // ���������� ������ ����� � ��������
            seconds %= 60;                                    // ���������� �������

            hours += minutes / 60;                            // ���������� ������ ����� � �������
            minutes %= 60;                                    // ���������� ������

            days += (short)(hours / 24);                      // ���������� ������ ���� � �����
            hours %= 24;                                      // ���������� ����

            years += days / 365;                              // ���������� ������ ��� � ����
            days %= 365;                                      // ���������� ���
        }

        /// <summary>
        ///������������ ������� � ����������
        /// </summary>
        public void equateMinus()
        {
            if (years < 0) { years = 0; };
            if (days < 0) { days = 0; };
            if (hours < 0) { hours = 0; };
            if (minutes < 0) { minutes = 0; };
            if (seconds < 0) { seconds = 0; };
            if (microseconds < 0) { microseconds = 0; };


            if (seconds > 0)                                  //���� ������ ������ 0
            {
                seconds -= 1;                                 //��������� ����� �������
                microseconds += 1000;                         //����������� 1000 �����������
            }

            if (minutes > 0)                                  //���� ����� ������ 1
            {
                minutes -= 1;                                 //��������� ����� ������
                seconds += 60;                                //����������� 60 ������
            }
            if (hours > 0)                                    //���� ����� ������ 1
            {
                hours -= 1;                                   //��������� ������ ����
                minutes += 60;                                //����������� 60 �����
            }
            if (days > 0)                                     //���� ���� ������ 1
            {
                days -= 1;                                    //��������� ������ ���
                hours += 24;                                  //����������� 24 �����
            }
            if (years > 0)                                    //���� ��� ������ 1
            {
                years -= 1;                                   //��������� ������ ����
                days += 365;                                  //����������� 365 ����
            }
            equate();
        }

        /// <summary>
        ///����� ���������� �������
        /// </summary>
        public void AddTime(Time t)
        {
            addYears((int)t.years);                           //������ �������� �����
            addDays(t.days);                                  //������ �������� ���� � ��������� � ����
            addHours(t.hours);                                //������ �������� ����� � ��������� � ���
            addMinutes(t.minutes);                            //������ �������� ����� � ��������� � ����
            addSeconds((int)t.seconds);                       //������ �������� ������ � ��������� � ������
            addMicroseconds(t.microseconds);                  //������ �������� ����������� � ��������� � �������
            equate();                                         //������������ �������� � �������
        }

        /// <summary>
        ///����� ��������� �������
        /// </summary>
        public void subtractTime(Time t)
        {
            subtractYears((int)t.years);                      //��������� �����
            subtractDays(t.days);                             //��������� ����
            subtractHours(t.hours);                           //��������� �����
            subtractMinutes(t.minutes);                       //��������� �����
            subtractSeconds((int)t.seconds);                  //��������� ������
            subtractMicroseconds(t.microseconds);             //��������� �����������
            equateMinus();                                    //������������ �������� � �������
        }

        /// <summary>
        ///����� ���������� �������� �� �����; y-���
        /// </summary>
        public void addYears(int y)
        {
            years += y;                                       //���������� ����
        }

        /// <summary>
        ///����� ���������� �������� �� ����; d-����
        /// </summary>
        public void addDays(int d)
        {
            days += (short)(d);                               //���������� ���                         
            equate();                                         //���������� �������� ������� (�� �������)
        }

        /// <summary>
        ///����� ���������� �������� �� �����; h-���
        /// </summary>
        public void addHours(int h)
        {
            hours += h;                                       //���������� ����
            equate();                                         //���������� �������� ������� (�� �������)
        }

        /// <summary>
        ///����� ���������� �������� �� �������; m-������
        /// </summary>
        public void addMinutes(int m)
        {
            minutes += m;                                     //���������� ������
            equate();                                         //���������� �������� ������� (�� �������)
        }

        /// <summary>
        ///����� ���������� �������� �� ��������; s-�������
        /// </summary>
        public void addSeconds(int s)
        {
            seconds += s;                                     //���������� �������
            equate();                                         //���������� �������� ������� (�� �������)
        }

        /// <summary>
        ///����� ���������� �������� �� �������������; ms-������������
        /// </summary>
        public void addMicroseconds(int ms)
        {
            microseconds += (short)(ms);                      //���������� ������������
            equate();                                         //���������� �������� ������� (�� �������)
        }

        /// <summary>
        ///����� ��������� ���
        /// </summary>
        public void subtractYears(int y)
        {
            years -= y;                                       //�������� ����
        }

        /// <summary>
        ///����� ��������� ����;
        /// </summary>
        public void subtractDays(int d)
        {
            days -= (short)(d);                               //�������� ���
            equateMinus();                                    //���������� �������� ������� (��� ����������) 
        }

        /// <summary>
        ///����� ��������� �����;
        /// </summary>
        public void subtractHours(int h)
        {
            hours -= h;                                       //�������� ����
            equateMinus();                                    //���������� �������� ������� (��� ����������) 
        }

        /// <summary>
        ///����� ��������� �����;
        /// </summary>
        public void subtractMinutes(int m)
        {
            minutes -= m;                                     //�������� ������
            equateMinus();                                    //���������� �������� ������� (��� ����������) 
        }

        /// <summary>
        ///����� ��������� ������; 
        /// </summary>
        public void subtractSeconds(int s)
        {
            seconds -= s;                                     //�������� �������
            equateMinus();                                    //���������� �������� ������� (��� ����������) 
        }

        /// <summary>
        ///����� ��������� �����������; 
        /// </summary>
        public void subtractMicroseconds(int ms)
        {
            microseconds -= (short)(ms);                      //�������� ������������
            equateMinus();                                    //���������� �������� ������� (��� ����������) 
        }

        /// <summary>
        ///����� ��������� ���
        /// </summary>
        public long getYears()
        {
            return years;                                     //������� ���
        }

        /// <summary>
        ///����� ��������� ����
        /// </summary>
        public short getDays()
        {
            return days;                                      //������� ����
        }

        /// <summary>
        ///����� ��������� �����
        /// </summary>
        public long getHours()
        {
            return hours;                                     //������� �����
        }

        /// <summary>
        ///����� ��������� �����
        /// </summary>
        public long getMinutes()
        {
            return minutes;                                   //������� �����
        }

        /// <summary>
        ///����� ��������� ������
        /// </summary>
        public long getSeconds()
        {
            return (int)(seconds);                            //������� ������
        }

        /// <summary>
        ///����� ��������� �����������
        /// </summary>
        public long getMicroseconds()
        {
            return microseconds;                              //������� �����������
        }

        //todo: � ����� �������� �� - //%%%

        /// <summary>
        ///����� ��������� ���
        /// </summary>
        public void setYears(long y)
        {
                                                              //���������� ��� �
            if (y >= 0) { years = y; };                        //�������� �� ���. ��������
        }

        /// <summary>
        ///����� ��������� ����
        /// </summary>
        public void setDays(short d)
        {                                                      //���������� ���� �
            if (d >= 0) { days = d; };                         //�������� �� ���. ��������
        }

        /// <summary>
        ///����� ��������� �����
        /// </summary>
        public void setHours(int h)
        {
                                                               //���������� ����� � 
            if (h >= 0) { hours = h; };                        //�������� �� ���. ��������
        }

        /// <summary>
        ///����� ��������� �����
        /// </summary>
        public void setMinutes(int m)
        {
                                                               //���������� ����� �
            if (m >= 0) { minutes = m; };                      //�������� �� ���. ��������
        }

        /// <summary>
        ///����� ��������� ������
        /// </summary>
        public void setSeconds(long s)
        {
                                                               //���������� ������ �
            if (s >= 0) { seconds = s; };                      //�������� �� ���. ��������
        }

        /// <summary>
        ///����� ��������� �����������
        /// </summary>
        public void setMicroseconds(short ms)
        {
                                                                //���������� ����������� �
            if (ms >= 0) { microseconds = ms; };                //�������� �� ���. ��������
        }

        /// <summary>
        ///����� �������������� ���� �������� � ������������
        /// </summary>
        public long toMicroseconds()
        {
            return years * 31536000000L + days * 86400000L + hours * 3600000L + minutes * 60000L + seconds * 1000L + microseconds;  //������� �������� � ������������
        }

        /// <summary>
        ///����� �������������� ���� �������� � �������
        /// </summary>
        public long toSeconds()
        {
            return years * 31536000 + days * 86400 + hours * 3600 + minutes * 60 + seconds; //������� �������� � �������
        }

        /// <summary>
        ///����� �������������� ���� �������� � ������
        /// </summary>
        public long toMinutes()
        {
            return years * 525600 + days * 1440 + hours * 60 + minutes; //������� �������� � ������
        }

        /// <summary>
        ///����� �������������� ���� �������� � ����
        /// </summary>
        public long toHours()
        {
            return years * 8760 + days * 24 + hours;          //������� �������� � ����
        }

        /// <summary>
        ///����� �������������� ���� �������� � ���
        /// </summary>
        public long toDays()
        {
            return years * 365 + days;                        //������� �������� � ���
        }

        /// <summary>
        ///����� �������������� ���� �������� � ����
        /// </summary>
        public long toYears()
        {
            return years;                                     //������� �������� � ����
        }

        /// <summary>
        ///����� ������ �������� �������� ������� � ��������� ������
        /// </summary>
        public override string ToString()                                                     //��������������� ToString �� �������� ������ Object
        {
            return $"Y{years}: D{days}: H{hours}: M{minutes}: S{seconds}: MS{microseconds}";  //������� ���� �������� � ������
        }

        /// <summary>
        ///����� ������ ��������� ������� � �������� � 1970 ����
        /// </summary>
        public static long REALTime()
        {
            DateTime currentTime = DateTime.Now;              //����� ���������� �������
            long unixTime = ((DateTimeOffset)currentTime).ToUnixTimeSeconds();  //����� ���������� ������� � ��������*
            return unixTime;                                  //������� ������� � ��������
        }

        /// <summary>
        ///����� �������� ������� � ���������� �����������
        /// </summary>
        public static Time[] createDynamicArray(int size)     
        {
            Time[] timeArray = new Time[size];                //�������� ���������� �������
            for (int i = 0; i < size; i++)                    //����, ������� �������������� i-���-�� ���
            {
                timeArray[i] = new Time();                    //��������� ������ time
            }
            return timeArray;                                 //������� ���������� �������
        }

        /// <summary>
        ///����� ������ � ���������� ����� ���� �������� 
        /// </summary>
        public static void readTwoObjectsFromFile(Time t1, Time t2, string filename)
        {
            try                                               //����������...
            {
                using (StreamReader inFile = new StreamReader(filename))  //������ �����
                {
                    string line1 = inFile.ReadLine();         //���������� ����� (������ ������)
                    if (line1 == null)                        //���� ������ ������ �������
                    {
                        MessageBox.Show("���� ���� ��� �� �������� ���������� ������.");  //����� ���������� ���������
                        return;                               //������� (���������)
                    }

                    var data1 = line1.Split(' ');             //����������� ���������� ������ ������
                    long y, s;                                //y - ���������� ���; s - ���������� ������;
                    int h, m;                                 //h - ���������� �����; m - ���������� �����;
                    short d, ms;                              //d - ���������� ����; ms - ���������� �����������;

                    y = long.Parse(data1[0]);                 //������ �������� � ������ ������ � ������� �����
                    d = short.Parse(data1[1]);                //������ �������� � ������ ������ � ������� �����
                    h = int.Parse(data1[2]);                  //������ �������� � ������ ������ � �������� �����
                    m = int.Parse(data1[3]);                  //������ �������� � ������ ������ � ���������� �����
                    s = long.Parse(data1[4]);                 //������ �������� � ������ ������ � ������ �����
                    ms = short.Parse(data1[5]);               //������ �������� � ������ ������ � ������� �����
                    t1.setTime(y, d, h, m, s, ms);            //�������� ���������� �������� ������� � ������ ������

                    string line2 = inFile.ReadLine();         //���������� ����� (������ ������)
                    if (line2 == null)                        //���� ������ ������ �������
                    {
                        throw new ArgumentException();  //����� ���������� ���������
                    }
                    var data2 = line2.Split(' ');             //����������� ���������� ������ ������

                    y = long.Parse(data2[0]);                 //������ �������� � ������ ������ � ������� �����
                    d = short.Parse(data2[1]);                //������ �������� � ������ ������ � ������� �����
                    h = int.Parse(data2[2]);                  //������ �������� � ������ ������ � �������� �����
                    m = int.Parse(data2[3]);                  //������ �������� � ������ ������ � ���������� �����
                    s = long.Parse(data2[4]);                 //������ �������� � ������ ������ � ������ �����
                    ms = short.Parse(data2[5]);               //������ �������� � ������ ������ � ������� �����
                    t2.setTime(y, d, h, m, s, ms);            //�������� ���������� �������� ������� � ������ ������
                }
            }
            catch (Exception)                              //��� �������...
            {
                throw new ArgumentException(); //%%%
            }
        }

        /// <summary>
        ///����� ������ � ���������� ����� ������ �������
        /// </summary>
        public static void readOneObjectFromFile(Time t1, string filename)
        {
            try                                               //����������...
            {
                using (StreamReader inFile = new StreamReader(filename))  //������ �����
                {
                    string line1 = inFile.ReadLine();         //���������� ����� (������ ������)
                    if (line1 == null)                        //���� ������ ������ �������
                    {
                        MessageBox.Show("���� ���� ��� �� �������� ���������� ������.");  //����� ���������� ���������
                        return;                               //������� (���������)
                    }

                    var data1 = line1.Split(' ');             //����������� ���������� ������ ������
                    long y, s;                                //y - ���������� ���; s - ���������� ������;
                    int h, m;                                 //h - ���������� �����; m - ���������� �����;
                    short d, ms;                              //d - ���������� ����; ms - ���������� �����������;

                    y = long.Parse(data1[0]);                 //������ �������� � ������ ������ � ������� �����
                    d = short.Parse(data1[1]);                //������ �������� � ������ ������ � ������� �����
                    h = int.Parse(data1[2]);                  //������ �������� � ������ ������ � �������� �����
                    m = int.Parse(data1[3]);                  //������ �������� � ������ ������ � ���������� �����
                    s = long.Parse(data1[4]);                 //������ �������� � ������ ������ � ������ �����
                    ms = short.Parse(data1[5]);               //������ �������� � ������ ������ � ������� �����
                    t1.setTime(y, d, h, m, s, ms);            //�������� ���������� �������� ������� � ������ ������
                }
            }
            catch (Exception)                              //��� �������...
            {
                throw new ArgumentException(); //%%%
            }
        }

        //todo 1 ��������
        /// <summary>
        ///����� ���������� � ���������� ����� ���� �������� 
        /// </summary>
        public static void writeTwoObjectsToFile(Time t1, Time t2, string filename)
        {
            try                                               //����������...
            {
                using (StreamWriter outFile = new StreamWriter(filename))  //������ �����
                {
                    long y, s;                                //y - ���������� ���; s - ���������� ������;
                    int h, m;                                 //h - ���������� �����; m - ���������� �����;
                    short d, ms;                              //d - ���������� ����; ms - ���������� �����������;

                    t1.getTime(out y, out d, out h, out m, out s, out ms);  //��������� �������� � �������
                    outFile.WriteLine($"{y} {d} {h} {m} {s} {ms}");  //����� ������ ������ �� ���������� � ���� 

                    t2.getTime(out y, out d, out h, out m, out s, out ms);  //��������� �������� � �������
                    outFile.Write($"{y} {d} {h} {m} {s} {ms}");  //����� ������ ������ �� ���������� � ����
                }
            }
            catch (Exception)                              //����������...
            {
                throw new ArgumentException(); //%%%
            }
        }

        /// <summary>
        ///����� ���������� � ���������� ����� ������ �������
        /// </summary>
        public static void writeOneObjectToFile(Time t1, string filename)
        {
            try                                               //����������...
            {
                using (StreamWriter outFile = new StreamWriter(filename))  //������ �����
                {
                    long y, s;                                //y - ���������� ���; s - ���������� ������;
                    int h, m;                                 //h - ���������� �����; m - ���������� �����;
                    short d, ms;                              //d - ���������� ����; ms - ���������� �����������;

                    t1.getTime(out y, out d, out h, out m, out s, out ms);  //��������� �������� � �������
                    outFile.WriteLine($"{y} {d} {h} {m} {s} {ms}");  //����� ������ ������ �� ���������� � ���� 
                }
            }
            catch (Exception)                              //����������...
            {
                throw new ArgumentException(); //%%%
            }
        }

        /// <summary>
        ///����� �������������� ���� �������� �� ��������� ������
        /// </summary>
        public void setTime(long y, short d, int h, int m, long s, short ms)  
        {
            this.setYears(y);                                 //�������� �� ������������� �������� � ��������� �������� ����� set���
            this.setDays(d);
            this.setHours(h);
            this.setMinutes(m);
            this.setSeconds(s);
            this.setMicroseconds(ms);
        }

        /// <summary>
        ///����� ������������� ���� �������� �� ���������� �������
        /// </summary>
        public void getTime(out long y, out short d, out int h, out int m, out long s, out short ms)  
        {
            y = years;                                        //��������� ������� ��� ��������� ������ 
            d = days;                                         //��������� ������� ���� ��������� ������ 
            h = hours;                                        //��������� ������� ����� ��������� ������ 
            m = minutes;                                      //��������� ������� ����� ��������� ������ 
            s = seconds;                                      //��������� ������� ������ ��������� ������ 
            ms = microseconds;                                //��������� ������� ����������� ��������� ������ 
            equateMinus();                                    //�������� �� ������������� ��������
        }

        //todo ������� ��������
        /// <summary>
        ///�����-assert ��� �������� ������� �������������
        /// </summary>
        public static void AssertMethods()                           //Assert �������� - ��� �������� ������� �������
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