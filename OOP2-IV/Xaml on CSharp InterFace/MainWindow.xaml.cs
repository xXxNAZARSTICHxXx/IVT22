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


namespace TimeTimeTime                                                              //Пространство имен для класса
{

    public partial class MainWindow : Window                                        //Класс "окна" - контроллер для взаимодействия с пользователем и интерфейсовм
                                                                                    //Часть программы шаблона проектирования MVC
    {

        

        public MainWindow()                                                         //Подкласс "окна"
        {
            Time.AssertMethods();
            
            InitializeComponent();                                                  //Установка и определение компонентов
        }

        const string ftime = "time.txt";                                            //Константноя файловая переменная ftime     
        long LLSeconds;                                                             //Переменная для хранения секунд с 1 января 1970 года
        public Time timeMain1 = new Time();                                         //Создание классового массива переменных для первого времянного массива
        public Time timeMain2 = new Time();                                         //Создание классового массива переменных для первого времянного массива

        private void BuploadXTime_Click(object sender, RoutedEventArgs e)           //Функция вызывающая обработчик событий при нажатии на кнопку ""
        {
            int inp;                                                                //Переменная для хранения/передачи числа - времени inp
            ALERT.Visibility = Visibility.Hidden;                                   //снятие ошибки с экрана
            if ((int.TryParse(XY.Text, out inp) && inp >= 0) &&                     //Передача с текстового поля лет в первый времянной массив через imp переменную
               (int.TryParse(XD.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля дней в первый времянной массив через imp переменную
               (int.TryParse(XH.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля часов в первый времянной массив через imp переменную
               (int.TryParse(XM.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля минут в первый времянной массив через imp переменную
               (int.TryParse(XS.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля секунд в первый времянной массив через imp переменную
               (int.TryParse(XMS.Text, out inp) && inp >= 0))                       //Передача с текстового поля микросекунд в первый времянной массив через imp переменную
            {
                timeMain1.setYears(int.Parse(XY.Text));                             //Установка лет с текстового поля
                timeMain1.setDays(short.Parse(XD.Text));                            //Установка дней с текстового поля
                timeMain1.setHours(int.Parse(XH.Text));                             //Установка часов с текстового поля
                timeMain1.setMinutes(int.Parse(XM.Text));                           //Установка минут с текстового поля
                timeMain1.setSeconds(int.Parse(XS.Text));                           //Установка секунд с текстового поля
                timeMain1.setMicroseconds(short.Parse(XMS.Text));                   //Установка микросекунд с текстового поля
            }
            else                                                                    //Иначе...
            {
                //Написать в программе вместо окна %%%
                ALERT.Visibility = Visibility.Visible;                              //Вывод ошибки на экран в виде текста
            }
            timeMain1.equate();                                                     //Уравнеие времени - если есть излишек в первом врянном массиве
            LXYears.Content = Convert.ToString(timeMain1.getYears());               //Перевод значения лет в строку и запись в label первой линии массива
            LXDays.Content = Convert.ToString(timeMain1.getDays());                 //Перевод значения дней в строку и запись в label первой линии массива
            LXHours.Content = Convert.ToString(timeMain1.getHours());               //Перевод значения часов в строку и запись в label первой линии массива
            LXMinutes.Content = Convert.ToString(timeMain1.getMinutes());           //Перевод значения минут в строку и запись в label первой линии массива
            LXSeconds.Content = Convert.ToString(timeMain1.getSeconds());           //Перевод значения секунд в строку и запись в label первой линии массива
            LXMicroseconds.Content = Convert.ToString(timeMain1.getMicroseconds()); //Перевод значения микросекунд в строку и запись в label первой линии массива
        }

        private void NowX_Click(object sender, RoutedEventArgs e)                   //Функция вызывающая обработчик событий при нажатии на кнопку ""
        {
            timeMain1.setYears(0);                                                  //Обнуление лет в первом массове
            timeMain1.setDays(0);                                                   //Обнуление дней в первом массове
            timeMain1.setHours(0);                                                  //Обнуление часов в первом массове
            timeMain1.setMinutes(0);                                                //Обнуление минут в первом массове
            timeMain1.setSeconds(0);                                                //Обнуление секунд в первом массове
            timeMain1.setMicroseconds(0);                                           //Обнуление микросекунд в первом массове

            LLSeconds = Time.REALTime();                                            //Взятие системного времени и запись в переменную LLSeconds
            timeMain1.addSeconds((int)LLSeconds);                                   //Добавление системного-нного времени в секундах в первый массив
            timeMain1.equate();                                                     //Уравнение времени
            timeMain1.addYears(1970);                                               //Добавление 1970 лет к первому массиву
            timeMain1.subtractDays(14);                                             //Вычитание 14 дней у первого массива
            timeMain1.addHours(9);                                                  //Добавление 9 часов к первому массиву
            LXYears.Content = Convert.ToString(timeMain1.getYears());               //Перевод значения лет из массива в строку через getter и запись его в label
            LXDays.Content = Convert.ToString(timeMain1.getDays());                 //Перевод значения дней из массива в строку через getter и запись его в label
            LXHours.Content = Convert.ToString(timeMain1.getHours());               //Перевод значения часов из массива в строку через getter и запись его в label
            LXMinutes.Content = Convert.ToString(timeMain1.getMinutes());           //Перевод значения минут из массива в строку через getter и запись его в label
            LXSeconds.Content = Convert.ToString(timeMain1.getSeconds());           //Перевод значения секунд из массива в строку через getter и запись его в label
            LXMicroseconds.Content = Convert.ToString(timeMain1.getMicroseconds()); //Перевод значения микросекунд из массива в строку через getter и запись его в label
        }

        private void Bplus1_Click(object sender, RoutedEventArgs e)                 //Функция вызывающая обработчик событий при нажатии на кнопку ""
        {
            ALERT.Visibility = Visibility.Hidden;                                   //снятие ошибки с экрана
            int inp;                                                                //Переменная для хранения/передачи числа - времени inp
            if ((int.TryParse(XY.Text, out inp) && inp >= 0) &&                     //Передача с текстового поля лет в первый времянной массив через imp переменную
               (int.TryParse(XD.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля дней в первый времянной массив через imp переменную
               (int.TryParse(XH.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля часов в первый времянной массив через imp переменную
               (int.TryParse(XM.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля минут в первый времянной массив через imp переменную
               (int.TryParse(XS.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля секунд в первый времянной массив через imp переменную
               (int.TryParse(XMS.Text, out inp) && inp >= 0))                       //Передача с текстового поля микросекунд в первый времянной массив через imp переменную
            {
                timeMain1.addYears(int.Parse(XY.Text));                             //Добавление лет с текстового поля 
                timeMain1.addDays(short.Parse(XD.Text));                            //Добавление дней с текстового поля 
                timeMain1.addHours(int.Parse(XH.Text));                             //Добавление часов с текстового поля 
                timeMain1.addMinutes(int.Parse(XM.Text));                           //Добавление минут с текстового поля 
                timeMain1.addSeconds(int.Parse(XS.Text));                           //Добавление секунд с текстового поля 
                timeMain1.addMicroseconds(short.Parse(XMS.Text));                   //Добавление микросекунд с текстового поля 
            }
            else                                                                    //Иначе...
            {
                ALERT.Visibility = Visibility.Visible;                              //Вывод ошибки на экран в виде текста
            }
            timeMain1.equate();                                                     //Уравнеие времени - если есть излишек в первом врянном массиве
            LXYears.Content = Convert.ToString(timeMain1.getYears());               //Перевод значения лет из массива в строку через getter и запись его в label
            LXDays.Content = Convert.ToString(timeMain1.getDays());                 //Перевод значения дней из массива в строку через getter и запись его в label
            LXHours.Content = Convert.ToString(timeMain1.getHours());               //Перевод значения часов из массива в строку через getter и запись его в label
            LXMinutes.Content = Convert.ToString(timeMain1.getMinutes());           //Перевод значения минут из массива в строку через getter и запись его в label
            LXSeconds.Content = Convert.ToString(timeMain1.getSeconds());           //Перевод значения секунд из массива в строку через getter и запись его в label
            LXMicroseconds.Content = Convert.ToString(timeMain1.getMicroseconds()); //Перевод значения микросекунд из массива в строку через getter и запись его в label
        }

        private void Bminus1_Click(object sender, RoutedEventArgs e)                //Функция вызывающая обработчик событий при нажатии на кнопку ""
        {
            int inp;                                                                //Переменная для хранения/передачи числа - времени inp
            if ((int.TryParse(XY.Text, out inp) && inp >= 0) &&                     //Передача с текстового поля лет в первый времянной массив через inp переменную
               (int.TryParse(XD.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля дней в первый времянной массив через inp переменную
               (int.TryParse(XH.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля часов в первый времянной массив через inp переменную
               (int.TryParse(XM.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля минут в первый времянной массив через inp переменную
               (int.TryParse(XS.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля секунд в первый времянной массив через inp переменную
               (int.TryParse(XMS.Text, out inp) && inp >= 0))                       //Передача с текстового поля микросекунд в первый времянной массив через inp переменную
            {
                timeMain1.subtractYears(int.Parse(XY.Text));                        //Вычитание лет с первого массива
                timeMain1.subtractDays(short.Parse(XD.Text));                       //Вычитание дней с первого массива
                timeMain1.subtractHours(int.Parse(XH.Text));                        //Вычитание часов с первого массива
                timeMain1.subtractMinutes(int.Parse(XM.Text));                      //Вычитание минут с первого массива
                timeMain1.subtractSeconds(int.Parse(XS.Text));                      //Вычитание секунд с первого массива
                timeMain1.subtractMicroseconds(short.Parse(XMS.Text));              //Вычитание микросекунд с первого массива
            }
            timeMain1.equateMinus();                                                //Уравнеие времени - если есть недостаток в первом врянном массиве

            if (timeMain1.getYears() < 0) { timeMain1.setYears(0); };               //Если в массиве в области лет отрицательное значение, то обнулить
            if (timeMain1.getDays() < 0) { timeMain1.setDays(0); };                 //Если в массиве в области дней отрицательное значение, то обнулить
            if (timeMain1.getHours() < 0) { timeMain1.setHours(0); };               //Если в массиве в области часов отрицательное значение, то обнулить
            if (timeMain1.getMinutes() < 0) { timeMain1.setMinutes(0); };           //Если в массиве в области минут отрицательное значение, то обнулить
            if (timeMain1.getSeconds() < 0) { timeMain1.setSeconds(0); };           //Если в массиве в области секунд отрицательное значение, то обнулить
            if (timeMain1.getMicroseconds() < 0) { timeMain1.setMicroseconds(0); }; //Если в массиве в области лет отрицательное значение, то обнулить

            LXYears.Content = Convert.ToString(timeMain1.getYears());               //Перевод значения лет из массива в строку через getter и запись его в label
            LXDays.Content = Convert.ToString(timeMain1.getDays());                 //Перевод значения дней из массива в строку через getter и запись его в label
            LXHours.Content = Convert.ToString(timeMain1.getHours());               //Перевод значения часов из массива в строку через getter и запись его в label
            LXMinutes.Content = Convert.ToString(timeMain1.getMinutes());           //Перевод значения минут из массива в строку через getter и запись его в label
            LXSeconds.Content = Convert.ToString(timeMain1.getSeconds());           //Перевод значения секунд из массива в строку через getter и запись его в label
            LXMicroseconds.Content = Convert.ToString(timeMain1.getMicroseconds()); //Перевод значения микросекунд из массива в строку через getter и запись его в label
        }

        private void SaveTime_Click(object sender, RoutedEventArgs e)               //Функция вызывающая обработчик событий при нажатии на кнопку ""
        {
            Time.writeTwoObjectsToFile(timeMain1, timeMain2, ftime);                //Запись массивов в текстовый файл (сохранение)
        }

        private void NowY_Click(object sender, RoutedEventArgs e)                   //Функция вызывающая обработчик событий при нажатии на кнопку ""
        {
            timeMain2.setYears(0);                                                  //Обнуление лет во втором массиве
            timeMain2.setDays(0);                                                   //Обнуление дней во втором массиве
            timeMain2.setHours(0);                                                  //Обнуление часов во втором массиве
            timeMain2.setMinutes(0);                                                //Обнуление минут во втором массиве
            timeMain2.setSeconds(0);                                                //Обнуление секунд во втором массиве
            timeMain2.setMicroseconds(0);                                           //Обнуление микросекунд во втором массиве

            LLSeconds = Time.REALTime();                                            //Взятие системного времени в переменную LLSeconds
            timeMain2.addSeconds((int)LLSeconds);                                   //Добавление системного-нного времени в секундах в первый массив
            timeMain2.equate();                                                     //Уравнение времени
            timeMain2.addYears(1970);                                               //Добавление 1970 лет к первому массиву
            timeMain2.subtractDays(14);                                             //Вычитание 14 дней у первого массива
            timeMain2.addHours(9);                                                  //Добавление 9 часов к первому массиву

            LYYears.Content = Convert.ToString(timeMain2.getYears());               //Перевод значения лет из массива в строку через getter и запись его в label
            LYDays.Content = Convert.ToString(timeMain2.getDays());                 //Перевод значения дней из массива в строку через getter и запись его в label
            LYHours.Content = Convert.ToString(timeMain2.getHours());               //Перевод значения часов из массива в строку через getter и запись его в label
            LYMinutes.Content = Convert.ToString(timeMain2.getMinutes());           //Перевод значения минут из массива в строку через getter и запись его в label
            LYSeconds.Content = Convert.ToString(timeMain2.getSeconds());           //Перевод значения секунд из массива в строку через getter и запись его в label
            LYMicroseconds.Content = Convert.ToString(timeMain2.getMicroseconds()); //Перевод значения микросекунд из массива в строку через getter и запись его в label
        }

        private void Bplus2_Click(object sender, RoutedEventArgs e)                 //Функция вызывающая обработчик событий при нажатии на кнопку ""
        {
            int inp;                                                                //Переменная для хранения/передачи числа - времени inp

            ALERT.Visibility = Visibility.Hidden;                                   //снятие ошибки с экрана

            if ((int.TryParse(YY.Text, out inp) && inp >= 0) &&                     //Передача с текстового поля лет во второй времянной массив через inp переменную
               (int.TryParse(YD.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля дней во второй времянной массив через inp переменную
               (int.TryParse(YH.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля часов во второй времянной массив через inp переменную
               (int.TryParse(YM.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля минут во второй времянной массив через inp переменную
               (int.TryParse(YS.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля секунд во второй времянной массив через inp переменную
               (int.TryParse(YMS.Text, out inp) && inp >= 0))                       //Передача с текстового поля микросекунд во второй времянной массив через inp переменную
            {
                timeMain2.addYears(int.Parse(YY.Text));                             //Добавление лет с текстового поля во второй времянного массива
                timeMain2.addDays(short.Parse(YD.Text));                            //Добавление дней с текстового поля во второй времянного массива
                timeMain2.addHours(int.Parse(YH.Text));                             //Добавление часов с текстового поля во второй времянного массива
                timeMain2.addMinutes(int.Parse(YM.Text));                           //Добавление минут с текстового поля во второй времянного массива
                timeMain2.addSeconds(int.Parse(YS.Text));                           //Добавление секунд с текстового поля во второй времянного массива
                timeMain2.addMicroseconds(short.Parse(YMS.Text));                   //Добавление микросекунд с текстового поля во второй времянного массива
            }
            else                                                                    //Иначе...
            {
                
                ALERT.Visibility = Visibility.Visible;
            }
            timeMain2.equate();                                                     //Уравнеие времени - если есть излишек в первом врянном массиве
            LYYears.Content = Convert.ToString(timeMain2.getYears());               //Перевод значения лет из массива в строку через getter и запись его в label
            LYDays.Content = Convert.ToString(timeMain2.getDays());                 //Перевод значения дней из массива в строку через getter и запись его в label
            LYHours.Content = Convert.ToString(timeMain2.getHours());               //Перевод значения часов из массива в строку через getter и запись его в label
            LYMinutes.Content = Convert.ToString(timeMain2.getMinutes());           //Перевод значения минут из массива в строку через getter и запись его в label
            LYSeconds.Content = Convert.ToString(timeMain2.getSeconds());           //Перевод значения секунд из массива в строку через getter и запись его в label
            LYMicroseconds.Content = Convert.ToString(timeMain2.getMicroseconds()); //Перевод значения микросекунд из массива в строку через getter и запись его в label
        }

        private void Bminus2_Click(object sender, RoutedEventArgs e)                //Функция вызывающая обработчик событий при нажатии на кнопку ""
        {
            int inp;                                                                //Переменная для хранения/передачи числа - времени inp
            ALERT.Visibility = Visibility.Hidden;                                   //снятие ошибки с экрана
            if ((int.TryParse(YY.Text, out inp) && inp >= 0) &&                     //Передача с текстового поля лет во второй времянной массив через inp переменную
               (int.TryParse(YD.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля дней во второй времянной массив через inp переменную
               (int.TryParse(YH.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля часов во второй времянной массив через inp переменную
               (int.TryParse(YM.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля минут во второй времянной массив через inp переменную
               (int.TryParse(YS.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля секунд во второй времянной массив через inp переменную
               (int.TryParse(YMS.Text, out inp) && inp >= 0))                       //Передача с текстового поля микросекунд во второй времянной массив через inp переменную
            {
                timeMain2.subtractYears(int.Parse(YY.Text));                        //Вычитание лет с второго вреянного массива с текстового поля
                timeMain2.subtractDays(short.Parse(YD.Text));                       //Вычитание дней с второго вреянного массива с текстового поля
                timeMain2.subtractHours(int.Parse(YH.Text));                        //Вычитание часов с второго вреянного массива с текстового поля
                timeMain2.subtractMinutes(int.Parse(YM.Text));                      //Вычитание минут с второго вреянного массива с текстового поля
                timeMain2.subtractSeconds(int.Parse(YS.Text));                      //Вычитание секунд с второго вреянного массива с текстового поля
                timeMain2.subtractMicroseconds(short.Parse(YMS.Text));              //Вычитание микросекунд с второго вреянного массива с текстового поля
            }
            else                                                                    //Иначе...
            {

                ALERT.Visibility = Visibility.Visible;                              //Вывод ошибки на экран в виде текста
            }
            timeMain1.equateMinus();                                                //Уравнеие времени - если есть недостаток в первом врянном массиве

            if (timeMain2.getYears() < 0) { timeMain2.setYears(0); };               //Если в массиве в области лет отрицательное значение, то обнулить
            if (timeMain2.getDays() < 0) { timeMain2.setDays(0); };                 //Если в массиве в области дней отрицательное значение, то обнулить
            if (timeMain2.getHours() < 0) { timeMain2.setHours(0); };               //Если в массиве в области часов отрицательное значение, то обнулить
            if (timeMain2.getMinutes() < 0) { timeMain2.setMinutes(0); };           //Если в массиве в области минут отрицательное значение, то обнулить
            if (timeMain2.getSeconds() < 0) { timeMain2.setSeconds(0); };           //Если в массиве в области секунд отрицательное значение, то обнулить
            if (timeMain2.getMicroseconds() < 0) { timeMain2.setMicroseconds(0); }; //Если в массиве в области лет отрицательное значение, то обнулить

            LXYears.Content = Convert.ToString(timeMain1.getYears());               //Перевод значения лет из массива в строку через getter и запись его в label
            LXDays.Content = Convert.ToString(timeMain1.getDays());                 //Перевод значения дней из массива в строку через getter и запись его в label
            LXHours.Content = Convert.ToString(timeMain1.getHours());               //Перевод значения часов из массива в строку через getter и запись его в label
            LXMinutes.Content = Convert.ToString(timeMain1.getMinutes());           //Перевод значения минут из массива в строку через getter и запись его в label
            LXSeconds.Content = Convert.ToString(timeMain1.getSeconds());           //Перевод значения секунд из массива в строку через getter и запись его в label
            LXMicroseconds.Content = Convert.ToString(timeMain1.getMicroseconds()); //Перевод значения микросекунд из массива в строку через getter и запись его в label
        }

        private void OpenTime_Click(object sender, RoutedEventArgs e)               //Функция вызывающая обработчик событий при нажатии на кнопку ""
        {
            Time.readTwoObjectsFromFile(timeMain1, timeMain2, ftime);               //Открытие времянных массивов с файла

            timeMain1.equate();                                                     //Уравнеие времени - если есть недостаток в первом врянном массиве
            timeMain2.equate();                                                     //Уравнеие времени - если есть недостаток в первом врянном массиве

            LXYears.Content = Convert.ToString(timeMain1.getYears());               //Перевод значения лет из массива в строку через getter и запись его в label
            LXDays.Content = Convert.ToString(timeMain1.getDays());                 //Перевод значения дней из массива в строку через getter и запись его в label
            LXHours.Content = Convert.ToString(timeMain1.getHours());               //Перевод значения часов из массива в строку через getter и запись его в label
            LXMinutes.Content = Convert.ToString(timeMain1.getMinutes());           //Перевод значения минут из массива в строку через getter и запись его в label
            LXSeconds.Content = Convert.ToString(timeMain1.getSeconds());           //Перевод значения секунд из массива в строку через getter и запись его в label
            LXMicroseconds.Content = Convert.ToString(timeMain1.getMicroseconds()); //Перевод значения микросекунд из массива в строку через getter и запись его в label

            LYYears.Content = Convert.ToString(timeMain2.getYears());               //Перевод значения лет из массива в строку через getter и запись его в label
            LYDays.Content = Convert.ToString(timeMain2.getDays());                 //Перевод значения дней из массива в строку через getter и запись его в label
            LYHours.Content = Convert.ToString(timeMain2.getHours());               //Перевод значения часов из массива в строку через getter и запись его в label
            LYMinutes.Content = Convert.ToString(timeMain2.getMinutes());           //Перевод значения минут из массива в строку через getter и запись его в label
            LYSeconds.Content = Convert.ToString(timeMain2.getSeconds());           //Перевод значения секунд из массива в строку через getter и запись его в label
            LYMicroseconds.Content = Convert.ToString(timeMain2.getMicroseconds()); //Перевод значения микросекунд из массива в строку через getter и запись его в label
        }

        private void BuploadYTime1_Click(object sender, RoutedEventArgs e)          //Функция вызывающая обработчик событий при нажатии на кнопку ""
        {

            ALERT.Visibility = Visibility.Hidden;                                   //Вывод ошибки на экран в виде текста
            int inp;                                                                //Переменная для хранения/передачи числа - времени inp

            if ((int.TryParse(YY.Text, out inp) && inp >= 0) &&                     //Передача с текстового поля лет во второй времянной массив через inp переменную
               (int.TryParse(YD.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля дней во второй времянной массив через inp переменную
               (int.TryParse(YH.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля часов во второй времянной массив через inp переменную
               (int.TryParse(YM.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля минут во второй времянной массив через inp переменную
               (int.TryParse(YS.Text, out inp) && inp >= 0) &&                      //Передача с текстового поля секунд во второй времянной массив через inp переменную
               (int.TryParse(YMS.Text, out inp) && inp >= 0))                       //Передача с текстового поля микросекунд во второй времянной массив через inp переменную
            {
                timeMain2.setYears(int.Parse(YY.Text));                             //Установка лет во второй временной массив
                timeMain2.setDays(short.Parse(YD.Text));                            //Установка дней во второй временной массив
                timeMain2.setHours(int.Parse(YH.Text));                             //Установка часов во второй временной массив
                timeMain2.setMinutes(int.Parse(YM.Text));                           //Установка минут во второй временной массив
                timeMain2.setSeconds(int.Parse(YS.Text));                           //Установка секунд во второй временной массив
                timeMain2.setMicroseconds(short.Parse(YMS.Text));                   //Установка микросекунд во второй временной массив
            }
            else                                                                    //Иначе...
            {
                
                ALERT.Visibility = Visibility.Visible;                              //Вывод ошибки на экран в виде текста
            }

            timeMain2.equate();                                                     //Уравнеие времени - если есть недостаток в первом врянном массиве
            LYYears.Content = Convert.ToString(timeMain2.getYears());               //Перевод значения лет из массива в строку через getter и запись его в label
            LYDays.Content = Convert.ToString(timeMain2.getDays());                 //Перевод значения дней из массива в строку через getter и запись его в label
            LYHours.Content = Convert.ToString(timeMain2.getHours());               //Перевод значения часов из массива в строку через getter и запись его в label
            LYMinutes.Content = Convert.ToString(timeMain2.getMinutes());           //Перевод значения минут из массива в строку через getter и запись его в label
            LYSeconds.Content = Convert.ToString(timeMain2.getSeconds());           //Перевод значения секунд из массива в строку через getter и запись его в label
            LYMicroseconds.Content = Convert.ToString(timeMain2.getMicroseconds()); //Перевод значения микросекунд из массива в строку через getter и запись его в label
        }
    }
}
