using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace NTreeGraphic
{
    public partial class MainWindow : Window
    {
        // Переменные для хранения последнего выделенного узла и поля для редактирования
        private TextBox _lastEditBox;
        private BinaryTree _tree;

        private TextBlock _lastSelectedNode; // Поле для хранения последнего выделенного узла

        /// <summary>
        /// Конструктор MainWindow, инициализирующий дерево и вызывающий метод отрисовки
        /// </summary>
        public MainWindow()
        {
            InitializeComponent();
            _tree = new BinaryTree();
            _tree.CreateTree(37); // Создание дерева с 64 узлами
            DrawTree(_tree.Root, 450, 1000, 525, 0.38); // Центрирование и установка начальной позиции с большим размахом
        }

        /// <summary>
        /// Метод для отрисовки дерева
        /// </summary>
        /// <param name="node">Текущий узел дерева</param>
        /// <param name="x">X-координата для узла</param>
        /// <param name="y">Y-координата для узла</param>
        /// <param name="offset">Горизонтальный сдвиг для отрисовки дочерних узлов</param>
        /// <param name="angleFactor">Фактор для изменения угла отклонения ветвей</param>
        private void DrawTree(BinaryTreeNode node, double x, double y, double offset, double angleFactor)
        {
            if (node == null) return;

            // Создание метки для текущего узла
            var textBlock = new TextBlock
            {
                Text = node.Value.ToString(),
                FontSize = 30,
                Foreground = Brushes.White,
                TextAlignment = TextAlignment.Center,
                Background = Brushes.Red,
                FontWeight = FontWeights.Bold
            };

            // Установка позиции для текстового блока (центрирование)
            Canvas.SetLeft(textBlock, x - 10); // Устанавливаем X позицию для текстового блока
            Canvas.SetTop(textBlock, y - 30);  // Устанавливаем Y позицию для текстового блока
            canvas.Children.Add(textBlock);    // Добавляем текстовый блок на канву

            // Создание поля для редактирования (TextBox)
            var editBox = new TextBox
            {
                Width = 80,  // Увеличенная ширина поля
                Height = 40,  // Увеличенная высота поля
                FontSize = 28,  // Увеличенный размер шрифта для удобства ввода
                Visibility = Visibility.Collapsed,  // По умолчанию скрыто
                HorizontalContentAlignment = HorizontalAlignment.Center
            };

            // Установка позиции для поля редактирования (совпадает с текстовым блоком)
            Canvas.SetLeft(editBox, x - 40);  // Центрирование с учётом увеличенного поля
            Canvas.SetTop(editBox, y - 40);   // Сдвиг для корректного размещения
            canvas.Children.Add(editBox);     // Добавляем поле для ввода на канву

            // Добавляем событие для клика по узлу
            textBlock.MouseLeftButtonDown += (s, e) =>
            {
                // Если узел уже выделен
                if (_lastSelectedNode == textBlock)
                {
                    // Отображаем поле ввода и заполняем его текущим значением узла
                    editBox.Text = node.Value.ToString(); // Заполняем TextBox значением узла
                    editBox.Visibility = Visibility.Visible; // Отображаем TextBox
                    editBox.Focus();  // Фокус на поле ввода
                    return; // Выходим, не меняя выделение
                }

                // Если ранее был выделен узел, сбрасываем его цвет и скрываем поле ввода
                if (_lastSelectedNode != null)
                {
                    _lastSelectedNode.Background = Brushes.Red; // Возвращаем цвет к красному
                    _lastEditBox.Visibility = Visibility.Collapsed; // Скрываем предыдущее поле ввода
                }

                // Изменяем цвет фона текущего узла
                textBlock.Background = Brushes.Green; // Выделяем текущий узел зеленым

                // Отображаем поле ввода и заполняем его текущим значением узла
                editBox.Text = node.Value.ToString(); // Заполняем TextBox значением узла
                editBox.Visibility = Visibility.Visible; // Отображаем TextBox
                editBox.Focus();  // Фокус на поле ввода

                // Обновляем ссылку на последний выделенный узел и поле ввода
                _lastSelectedNode = textBlock; // Запоминаем текущий узел как последний выделенный
                _lastEditBox = editBox;        // Сохраняем текущее поле ввода как последнее активное
            };

            // Добавляем событие для завершения редактирования при нажатии "Enter"
            editBox.KeyDown += (s, e) =>
            {
                if (e.Key == Key.Enter)
                {
                    // Попытка преобразования введённого текста в число
                    if (int.TryParse(editBox.Text, out int newValue))
                    {
                        // Обновляем значение узла и текстовый блок
                        node.Value = newValue;      // Присваиваем новое значение узлу
                        textBlock.Text = newValue.ToString(); // Обновляем текст в TextBlock
                    }

                    // Скрываем поле ввода после завершения редактирования
                    editBox.Visibility = Visibility.Collapsed; // Прячем TextBox
                }
            };

            // Рисование линий к дочерним узлам
            if (node.Left != null)
            {
                var line = new Line
                {
                    X1 = x,                          // Начальная X координата линии
                    Y1 = y - 15,                     // Начальная Y координата линии
                    X2 = x - offset,                 // Конечная X координата линии
                    Y2 = y - 140,                    // Конечная Y координата линии
                    Stroke = Brushes.Red,            // Цвет линии
                    StrokeThickness = 2              // Толщина линии
                };
                canvas.Children.Add(line);            // Добавляем линию на канву
                DrawTree(node.Left, x - offset, y - 140, offset * angleFactor, angleFactor + 0.05); // Рисуем левый дочерний узел
            }

            if (node.Right != null)
            {
                var line = new Line
                {
                    X1 = x,                          // Начальная X координата линии
                    Y1 = y - 15,                     // Начальная Y координата линии
                    X2 = x + offset,                 // Конечная X координата линии
                    Y2 = y - 140,                    // Конечная Y координата линии
                    Stroke = Brushes.Red,            // Цвет линии
                    StrokeThickness = 2              // Толщина линии
                };
                canvas.Children.Add(line);            // Добавляем линию на канву
                DrawTree(node.Right, x + offset, y - 140, offset * angleFactor, angleFactor + 0.05); // Рисуем правый дочерний узел
            }
        }

        /// <summary>
        /// Сохраняет текущее дерево, нарисованное на канве, как изображение в формате PNG
        /// </summary>
        /// <param name="canvas">Канва с нарисованным деревом</param>
        /// <param name="filePath">Путь к файлу для сохранения изображения</param>
        private void SaveCanvasAsImage(Canvas canvas, string filePath)
        {
            // Определяем размер канвы
            var width = (int)imgg.ActualWidth;   // Получаем ширину канвы
            var height = (int)imgg.ActualHeight; // Получаем высоту канвы

            // Создаем объект RenderTargetBitmap для отрисовки содержимого канвы
            var renderTargetBitmap = new RenderTargetBitmap(width, height, 96, 96, PixelFormats.Pbgra32); // Создаем RenderTargetBitmap

            // Отрисовываем содержимое канвы в bitmap
            renderTargetBitmap.Render(canvas);   // Отрисовка содержимого канвы

            // Создаем объект для сохранения изображения
            var pngEncoder = new PngBitmapEncoder(); // Создаем PngBitmapEncoder
            pngEncoder.Frames.Add(BitmapFrame.Create(renderTargetBitmap)); // Добавляем кадр с отрисованной канвой

            // Сохраняем изображение в файл
            using (var fileStream = new FileStream(filePath, FileMode.Create)) // Открываем поток для записи
            {
                pngEncoder.Save(fileStream); // Сохраняем файл
            }
        }

        private void FullScreenPanel_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            // Сбрасываем цвет всех узлов дерева на красный
            ResetTreeColors(_tree.Root); // Восстанавливаем цвет всех узлов

            // Если поле ввода активно, скрываем его
            if (_lastEditBox != null)
            {
                _lastEditBox.Visibility = Visibility.Collapsed; // Скрываем активное поле ввода
                _lastEditBox = null; // Сбрасываем ссылку на активное поле
            }

            // Сбрасываем последнее выделение
            _lastSelectedNode = null; // Сбрасываем ссылку на последний выделенный узел
        }

        /// <summary>
        /// Сбрасывает цвет фона всех узлов дерева на красный
        /// </summary>
        /// <param name="node">Текущий узел дерева</param>
        private void ResetTreeColors(BinaryTreeNode node)
        {
            if (node == null) return;

            // Перебираем все дочерние узлы дерева
            foreach (var element in canvas.Children)
            {
                if (element is TextBlock textBlock)
                {
                    textBlock.Background = Brushes.Red; // Сбрасываем цвет на красный
                }
            }

            ResetTreeColors(node.Left);  // Сбрасываем цвета для левого поддерева
            ResetTreeColors(node.Right); // Сбрасываем цвета для правого поддерева
        }


        /// <summary>
        /// Метод для поиска TextBlock, соответствующего узлу дерева
        /// </summary>
        /// <param name="node">Текущий узел дерева</param>
        /// <returns>TextBlock, если найден, иначе null</returns>
        private TextBlock FindTextBlockByNode(BinaryTreeNode node)
        {
            // Проходим через все элементы канвы
            foreach (var child in canvas.Children)
            {
                // Если текущий элемент является текстовым блоком и его текст совпадает с значением узла
                if (child is TextBlock textBlock && textBlock.Text == node.Value.ToString())
                {
                    return textBlock; // Возвращаем найденный текстовый блок
                }
            }
            return null; // Если текстовый блок не найден, возвращаем null
        }

        /// <summary>
        /// Обработчик события для кнопки создания дерева
        /// </summary>
        /// <param name="sender">Объект отправитель</param>
        /// <param name="e">Аргументы события</param>
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            // Очищаем все элементы на канве
            canvas.Children.Clear();

            // Пробуем преобразовать введённый текст в число
            if (int.TryParse(NodeCount.Text, out int nodeCount))
            {
                // Создаём новое дерево с указанным количеством узлов
                _tree.CreateTree(nodeCount);

                // Рисуем дерево, начиная с корневого узла, используя заданные координаты и параметры
                DrawTree(_tree.Root, 450, 1000, 525, 0.38);

                // Очищаем поле для ввода количества узлов
                NodeCount.Text = "";
            }
            else
            {
                // Если введённое значение не является числом, очищаем поле
                NodeCount.Text = "";
            }
        }

        /// <summary>
        /// Обработчик события для кнопки сохранения изображения дерева
        /// </summary>
        /// <param name="sender">Объект отправитель</param>
        /// <param name="e">Аргументы события</param>
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            // Вызываем функцию для сохранения содержимого канвы как изображения
            SaveCanvasAsImage(canvas, "tree_image.png");
        }

    }

    /// <summary>
    /// Класс BinaryTreeNode, представляющий узел бинарного дерева
    /// </summary>
    public class BinaryTreeNode
    {
        /// <summary>
        /// Значение узла
        /// </summary>
        public int Value { get; set; }

        /// <summary>
        /// Левый дочерний узел
        /// </summary>
        public BinaryTreeNode Left { get; set; }

        /// <summary>
        /// Правый дочерний узел
        /// </summary>
        public BinaryTreeNode Right { get; set; }

        /// <summary>
        /// Конструктор BinaryTreeNode
        /// </summary>
        /// <param name="value">Значение узла</param>
        public BinaryTreeNode(int value)
        {
            Value = value;
        }
    }

    /// <summary>
    /// Класс BinaryTree, представляющий бинарное дерево
    /// </summary>
    public class BinaryTree
    {
        /// <summary>
        /// Корневой узел дерева
        /// </summary>
        public BinaryTreeNode Root { get; private set; }

        /// <summary>
        /// Метод для создания бинарного дерева
        /// </summary>
        /// <param name="max">Максимальное количество узлов</param>
        public void CreateTree(int max)
        {
            Root = CreateNode(0, max); // Создаем корневой узел с значением 0
        }

        /// <summary>
        /// Рекурсивный метод для создания дерева
        /// </summary>
        /// <param name="value">Текущее значение узла</param>
        /// <param name="max">Максимальное значение узла</param>
        /// <returns>Возвращает созданный узел</returns>
        private BinaryTreeNode CreateNode(int value, int max)
        {
            if (value >= max) return null; // Остановка рекурсии при достижении максимума

            var node = new BinaryTreeNode(value); // Создание узла
            node.Left = CreateNode(2 * value + 1, max); // Создание левого дочернего узла
            node.Right = CreateNode(2 * value + 2, max); // Создание правого дочернего узла

            return node; // Возвращаем созданный узел
        }
    }
}
