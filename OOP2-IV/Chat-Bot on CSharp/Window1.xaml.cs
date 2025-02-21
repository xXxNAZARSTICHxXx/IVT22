using System;
using System.Collections.Generic;
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
using System.Windows.Shapes;


namespace ChatBot
{
    /// <summary>
    /// Логика взаимодействия для Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {

        public static Window1 firstWindow; // Ссылка на первое окно
        public static MainWindow secondWindow; // Ссылка на второе окно
        public string activeColor; // Активный цвет

        /// <summary>
        /// Инициализация окна
        /// </summary>
        public Window1()
        {
            REGDynamicModule.assertCheck();
            InitializeComponent(); // Инициализация компонентов окна
            secondWindow = new MainWindow(); // Создание экземпляра второго окна
            firstWindow = this; // Присваивание текущего окна к первому окну
            secondWindow.Hide(); // Скрытие второго окна
            this.Show(); // Отображение текущего окна
            activeColor = "ForMessagesPURPLE.png"; // Установка начального активного цвета
        }

        /// <summary>
        /// Изменение цвета во втором окне
        /// </summary>
        /// <param name="newColor"></param>
        private void ChangeColorVia(string newColor)
        {
            activeColor = newColor; // Изменение активного цвета
            secondWindow.ChangeColor(activeColor); // Обновление активного цвета во втором окне
        }

        /// <summary>
        /// Изменение глобального цвета на фиолетовый
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Color1_Click(object sender, RoutedEventArgs e)
        {

            REGDynamicModule.ImageHelper.ChangeImageSource(BGlogin, "BG_Purple.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(loginBG, "ForOptionsPURPLE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(loginBUTTON, "MARK_PURPLE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(CaptionCHAT, "ForOptionsPURPLE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(StilisationBG, "FramePURPLE.png"); //Изменение изображений в зависимости от выбранного цвета
            activeColor = "ForMessagesPURPLE.png"; //Установка активного цвета
            secondWindow.Stilisation1(); //Применение стиля во втором окне
        }

        /// <summary>
        /// Изменение глобального цвета на зеленого
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Color2_Click(object sender, RoutedEventArgs e)
        {
            REGDynamicModule.ImageHelper.ChangeImageSource(BGlogin, "BG_Green.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(loginBG, "ForOptionsGREEN.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(loginBUTTON, "MARK_GREEN.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(CaptionCHAT, "ForOptionsGREEN.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(StilisationBG, "FrameGREEN.png"); //Изменение изображений в зависимости от выбранного цвета
            activeColor = "ForMessagesGREEN.png"; //Установка активного цвета
            secondWindow.Stilisation2(); //Применение стиля во втором окне
        }

        /// <summary>
        /// Изменение глобального цвета на синий
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Color3_Click(object sender, RoutedEventArgs e)
        {
            REGDynamicModule.ImageHelper.ChangeImageSource(BGlogin, "BG_Blue.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(loginBG, "ForOptionsBULE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(loginBUTTON, "MARK_BLUE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(CaptionCHAT, "ForOptionsBULE.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(StilisationBG, "FrameBLUE.png"); //Изменение изображений в зависимости от выбранного цвета
            activeColor = "ForMessagesBLUE.png"; //Установка активного цвета
            secondWindow.Stilisation3(); //Применение стиля во втором окне
        }

        /// <summary>
        /// Изменение глобального цвета на желтый
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Color4_Click(object sender, RoutedEventArgs e)
        {
            REGDynamicModule.ImageHelper.ChangeImageSource(BGlogin, "BG_Yellow.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(loginBG, "ForOptionsYELLOW.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(loginBUTTON, "MARK_YELLOW.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(CaptionCHAT, "ForOptionsYELLOW.png"); //Изменение изображений в зависимости от выбранного цвета
            REGDynamicModule.ImageHelper.ChangeImageSource(StilisationBG, "FrameYELLOW.png"); //Изменение изображений в зависимости от выбранного цвета
            activeColor = "ForMessagesYELLOW.png"; //Установка активного цвета
            secondWindow.Stilisation4(); //Применение стиля во втором окне
        }

        /// <summary>
        /// Кнопка входа в чат
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void LOGINin_Click(object sender, RoutedEventArgs e)
        {
            secondWindow.CanvaA.Children.Clear(); // Очистка CanvasA во втором окне
            await REGDynamicModule.ReadDataFromJson(activeColor, LoginTextBox.Text + ".Json", secondWindow.TEXTA, secondWindow.TEXTB, secondWindow.CanvaA, secondWindow.CanvaB); // Чтение данных из JSON файла
            secondWindow.NameBLOCK.Text = LoginTextBox.Text; // Установка имени пользователя
            this.Hide(); // Скрытие текущего окна
            secondWindow.Show(); // Отображение второго окна
            ChangeColorVia(activeColor); // Изменение активного цвета
        }

        /// <summary>
        /// Метод закрытия окна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            Application.Current.Shutdown(); // Закрытие приложения при закрытии окна
        }
    }
}
