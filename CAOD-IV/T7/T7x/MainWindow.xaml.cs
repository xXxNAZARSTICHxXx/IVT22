using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace T7x
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
        }

        public void RadioButton_Checked(object sender, RoutedEventArgs e)
        {
            RadioButton radioButton = sender as RadioButton;

            if (radioButton.IsChecked == true)
            {
                // Делайте что-то при выборе каждого RadioButton
                switch (radioButton.Name)
                {
                    case "RUBrb":
                        // Делайте что-то при выборе RUB
                        break;
                    case "USDrb":
                        // Делайте что-то при выборе USD
                        break;
                    case "EURrb":
                        // Делайте что-то при выборе EUR
                        break;
                    case "UANrb":
                        // Делайте что-то при выборе UAN
                        break;
                }
            }
        }

    }
}
