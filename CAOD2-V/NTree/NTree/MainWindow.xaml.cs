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
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Xml.Linq;

namespace NTree // Определение пространства имен для текущего проекта
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window // Класс для главного окна приложения
    {
        private NaryTree<string> companyTree; // Переменная для хранения дерева компании

        public MainWindow() // Конструктор класса MainWindow
        {
            InitializeComponent(); // Инициализация компонентов окна
            // Создаем дерево и инициализируем его структурой
            companyTree = new NaryTree<string>("Генеральный директор"); // Создание дерева с корневым узлом
            NaryTreeTest.CreateCompanyStructure(companyTree, s => s); // Создание структуры компании
        }

        private void Button_Click(object sender, RoutedEventArgs e) // Обработчик события нажатия кнопки
        {
            // Массив названий узлов для поиска
            string[] nodeNames = {
                "Генеральный директор", // Label L0
                "Начальник охраны труда", // Label L0
                "Бухгалтерия", // Label L2
                "Заместитель по производственной части", // Label L3
                "Менеджер по работе с клиентами", // Label L4
                "Менеджеры по закупкам", // Label L5
                "Заместитель по административным вопросам", // Label L6
                "Служба безопасности", // Label L7
                "Элеватор", // Label L8
                "Цех прессования", // Label L9
                "Цех рафинации", // Label L10
                "Лаборатория", // Label L11
                "Цех розлива", // Label L12
                "Автоподразделение", // Label L13
                "Инженерно-технический отдел", // Label L14
                "Строительное подразделение", // Label L15
                "Отдел кадров" // Label L16
            };

            // Список элементов управления для вывода данных
            Label[] labels = { L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, L16, L17 }; // Массив меток для отображения узлов

            // Проходим по всем названиям узлов
            for (int i = 0; i < nodeNames.Length; i++)
            {
                // Поиск узла по названию
                var targetNode = companyTree.FindNode(companyTree.Root, nodeNames[i]); // Поиск узла в дереве

                // Проверка, найден ли узел
                if (targetNode != null) // Если узел найден
                {
                    labels[i].Content = targetNode.Data; // Устанавливаем контент метки
                }
                else // Если узел не найден
                {
                    labels[i].Content = "Узел не найден"; // Указываем, что узел не найден
                }
            }
        }
    }
}
