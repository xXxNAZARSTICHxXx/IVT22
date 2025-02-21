using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
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
using System.Windows.Media.Media3D;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Xml.Linq;
using static System.Net.Mime.MediaTypeNames;

namespace ChatBot
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        REGResponse regModule = new REGResponse(); //Создание экземпляра класса для взаимодействия с динамическим классом
        /// <summary>
        /// Зона автозапуска
        /// </summary>
        public MainWindow()
        {
            InitializeComponent(); //Инициализация компонентов окна
            Loaded += MainWindow_Loaded; //Подписка на событие загрузки окна
            Closing += MainWindow_Closing; //Подписка на событие закрытия окна
           
        }

        const int fullUP = 72; //Константа для полного подъема
        const int halfUP = 36; //Константа для половинного подъема
        int UP_DOWN = 0; //Переменная для хранения шага калибровки

        /// <summary>
        /// Метод изменения активного цвета
        /// </summary>
        /// <param name="color"></param>
        public void ChangeColor(string color)
        {
            Window1.firstWindow.activeColor = color; //Изменение активного цвета в первом окне
        }

        /// <summary>
        /// Методы стилизации цвета фиолетого
        /// </summary>
        public void Stilisation1()
        {
            REGDynamicModule.ImageHelper.ChangeImageSource(BGb, "BG_Purple.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(messageIN, "ForMessagesPURPLE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(sendIN, "SendIN_PURPLE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(BACK_NAME, "FramePURPLE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(BackIMAGE, "MARK_PURPLE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(deleteIMAGE, "deletePURPLE.png"); //Изменение изображений в зависимости от выбранного цвета
        }

        /// <summary>
        /// Методы стилизации цвета зеленого
        /// </summary>
        public void Stilisation2()
        {
            REGDynamicModule.ImageHelper.ChangeImageSource(BGb, "BG_Green.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(messageIN, "ForMessagesGREEN.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(sendIN, "SendIN_GREEN.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(BACK_NAME, "FrameGREEN.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(BackIMAGE, "MARK_GREEN.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(deleteIMAGE, "deleteGREEN.png"); //Изменение изображений в зависимости от выбранного цвета

        }

        /// <summary>
        /// Методы стилизации цвета синего
        /// </summary>
        public void Stilisation3()
        {
            REGDynamicModule.ImageHelper.ChangeImageSource(BGb, "BG_Blue.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(messageIN, "ForMessagesBLUE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(sendIN, "SendIN_BLUE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(BACK_NAME, "FrameBLUE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(BackIMAGE, "MARK_BLUE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(deleteIMAGE, "deleteBLUE.png"); //Изменение изображений в зависимости от выбранного цвета

        }

        /// <summary>
        /// Методы стилизации цвета желтого
        /// </summary>
        public void Stilisation4()
        {
            REGDynamicModule.ImageHelper.ChangeImageSource(BGb, "BG_Yellow.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(messageIN, "ForMessagesYELLOW.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(sendIN, "SendIN_YELLOW.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(BACK_NAME, "FrameYELLOW.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(BackIMAGE, "MARK_YELLOW.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(deleteIMAGE, "deleteYELLOW.png"); //Изменение изображений в зависимости от выбранного цвета

        }

        /// <summary>
        /// Метод изменения текста
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        /// <summary>
        /// Метод кнопки отправки сообщения
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void MainWindow_Loaded(object sender, RoutedEventArgs e)
        {
            REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, halfUP);
            await REGDynamicModule.ReadDataFromJson(Window1.firstWindow.activeColor, Window1.firstWindow.LoginTextBox.Text + ".Json", TEXTA, TEXTB, CanvaA, CanvaB); //Чтение данных с Json файла
            int lenga = REGDynamicModule.CountLines(TEXTA); //Считывание кол-ва строк
            ALLpanel.Height = ALLpanel.Height + fullUP * lenga; //Калибровка размера
            TEXTA.Height = ALLpanel.Height + fullUP * lenga; //Калибровка размера
            TEXTB.Height = ALLpanel.Height + fullUP * lenga; //Калибровка размера          
            foreach (UIElement child in CanvaA.Children) //Получаем все дочерние элементы Canvas
            {
                if (child is System.Windows.Controls.Image image) //Проверяем, является ли текущий элемент изображением
                { 
                    BitmapImage newBitmap = new BitmapImage(new Uri(Window1.firstWindow.activeColor, UriKind.Relative)); //Устанавливаем новое изображение для изображения
                    image.Source = newBitmap; //Размещаеи новое изображение
                }
            }

        }

        /// <summary>
        /// Зона автовыхода
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void  MainWindow_Closing(object sender, CancelEventArgs e)
        {
            await REGDynamicModule.SaveDataToJson(Window1.firstWindow.LoginTextBox.Text + ".Json", TEXTA.Text, TEXTB.Text, CanvaA, CanvaB); //Сохранение переписки в Json файл
        }

        /// <summary>
        /// Синхронный метод отправки сообщения по кнопке
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void SendBUTTON_Click_1(object sender, RoutedEventArgs e)
        {
            //сократить через метод
            string inputspace = INPUT.Text; //Перевод введенного текста в переменную
            switch (inputspace)
            {
                case var s when regModule.REGHello(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGHello(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGHowAreYou(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGHowAreYou(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGLewd(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGLewd(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGGoodbye(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGGoodbye(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGData(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGData(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGTime(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGTemperature(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGPlus(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGPlus(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGMinus(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGMinus(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGMultiply(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGMultiply(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGDivision(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGDivision(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGImage(s) != "":
                    ALLpanel.Height += 704 + fullUP * 3; //Увеличение высоты панели с элементами
                    TEXTA.Height += 704 + fullUP * 2; //Увеличение высоты текстбокста A
                    TEXTB.Height += 704 + fullUP * 2; //Увеличение высоты текстбокста B
                    CanvaA.Height += 704 + fullUP * 2; //Увеличение высоты канвы с текстовыми прямоугольниками
                    CanvaB.Height += 704; //Увеличение высоты канвы с парсинговыми изображениями
                    await REGDynamicModule.LoadImagesAsync(CanvaB); //Пасинг изображения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание иображения в определенной точке и координатах
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine; //Отступы строк у изображения
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine + Environment.NewLine; //Отступы строк у изображения
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += 718 + fullUP + halfUP; //Калибровка размера
                    CanvaB.Height += 718; //Увеличение высоты канвы с парсинговыми изображениями
                    break;

                case var s when regModule.REGTemperature(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGTemperature(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                case var s when regModule.REGCalc(s) != "":
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + regModule.REGCalc(inputspace) + Environment.NewLine; //Вывод результат регулярного выражения
                    Process.Start("calc.exe");
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание текстого прямоугольника
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод пользовательской введенной строки
                    UP_DOWN += halfUP; //Калибровка размера
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 1020 - 500, UP_DOWN - 4); //Создание текстого прямоугольника
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;

                default:
                    REGDynamicModule.UpdateElements(ref ALLpanel, ref CanvaA, ref TEXTA, ref TEXTB, ref CanvaB, fullUP);
                    REGDynamicModule.CreateImage(Window1.firstWindow.activeColor, ref CanvaA, 500, halfUP + 8, 0, UP_DOWN - 4); //Создание иображения в определенной точке и координатах
                    UP_DOWN += halfUP; //Калибровка размера
                    TEXTA.Text = TEXTA.Text + inputspace + Environment.NewLine + Environment.NewLine; //Вывод строки пользователя
                    TEXTB.Text = TEXTB.Text + Environment.NewLine + Environment.NewLine; //Вывод пустой строки регулярного выражения
                    INPUT.Text = ""; //Сброс строки ввода
                    UP_DOWN += halfUP; //Калибровка размера
                    CanvaB.Height += halfUP * 2 + 8; //Калибровка размера
                    break;
            }
        }

        /// <summary>
        /// Метод возврата кнопки назад
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void Back_BUTTION_Click(object sender, RoutedEventArgs e)
        {
            await REGDynamicModule.SaveDataToJson(Window1.firstWindow.LoginTextBox.Text + ".Json", TEXTA.Text, TEXTB.Text, CanvaA, CanvaB); //Сохранение данных в Json файл
            //REGModule.RefreshTextBoxDataFromJson(Window1.firstWindow.LoginTextBox.Text + ".Json", ref TEXTA, ref TEXTB, ref CanvaA, ref CanvaB); //Очистка файла и сброс всех панелей
            CanvaA.Children.Clear(); //Очистка канвы с текстовыми прямогульниками
            CanvaB.Children.Clear(); //Очистка канвы с парсинговыми изображениями
            TEXTA.Text = string.Empty; //Очистка текстбокса 1 
            TEXTB.Text = string.Empty; //Очистка текстбокса 2
            this.Hide(); //Закрытие этого окна
            Window1.firstWindow.Show(); //Показ первого окна
        }

        /// <summary>
        /// Метод удаления кнопки
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void delete_BUTTON_Click(object sender, RoutedEventArgs e)
        {
            REGDynamicModule.RefreshTextBoxDataFromJson(Window1.firstWindow.LoginTextBox.Text + ".Json", ref TEXTA, ref TEXTB, ref CanvaA, ref CanvaB); //Очистка файла и сброс всех панелей
            TEXTA.Text = string.Empty; //Очистка текстбокса 1 
            TEXTA.Text = string.Empty; //Очистка текстбокса 2
            ALLpanel.Height = halfUP; //Возвращение панели в начальное состояние
            TEXTA.Height = halfUP; //Возвращение текстового бокса А в начальное состояние
            TEXTB.Height = halfUP; //Возвращение текстового бокса В в начальное состояние
            CanvaA.Height = halfUP; //Возвращение канвы с текстовыми прямоугольниками в начальное состояние
            CanvaB.Height = 710; //Возвращение канвы с парсинговыми изображениями в начальное состояние
            UP_DOWN = 0; //Переменная для хранения шага калибровки
        }

        /// <summary>
        /// Синхронный метод внезапного закрытия окна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void Window_Closing2(object sender, System.ComponentModel.CancelEventArgs e)
        {
            await REGDynamicModule.SaveDataToJson(Window1.firstWindow.LoginTextBox.Text + ".Json", TEXTA.Text, TEXTB.Text, CanvaA, CanvaB); //Сохранение данных в Json файл
            System.Windows.Application.Current.Shutdown(); //Выключение программы
        }
    }
}
