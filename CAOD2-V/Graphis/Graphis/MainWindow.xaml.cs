using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace GraphDrawingApp // Определение пространства имен для организации кода
{
    public partial class MainWindow : Window // Класс MainWindow, представляющий главное окно приложения
    {
        private Ellipse selectedNode = null; // Переменная для хранения выбранного узла (если он есть)
        private bool isDragging = false; // Флаг, указывающий на то, осуществляется ли перетаскивание узла
        private Point clickPosition; // Точка, в которой был сделан клик для начала перетаскивания
        private List<GraphNode> graphNodes = new List<GraphNode>(); // Список узлов графа
        private int nodeIdCounter = 0; // Счетчик для генерации уникальных идентификаторов узлов
        private Graph graph;

        // <summary>
        // Конструктор для инициализации компонента окна.
        // </summary>
        public MainWindow()
        {

            InitializeComponent(); // Инициализация компонентов окна
            GraphCanvas.Loaded += OnCanvasLoaded; // Добавляем обработчик для события Loaded канвы
            graph = new Graph(); // Создание экземпляра графа
        }

        // <summary>
        // Обработчик события Loaded для канвы. Отображает граф при загрузке.
        // </summary>
        private void OnCanvasLoaded(object sender, RoutedEventArgs e)
        {
            DrawGraph(); // Вызов метода для отрисовки графа
        }

        // <summary>
        // Метод для отрисовки графа
        // </summary>
        private void DrawGraph()
        {
            // Пустая реализация, сюда добавляется логика рисования графа
        }

        // <summary>
        // Метод для создания узла на канве.
        // </summary>
        // <param name="labelText">Текст метки узла.</param>
        // <param name="left">Координата слева для расположения узла.</param>
        // <param name="top">Координата сверху для расположения узла.</param>
        private void CreateNode(string labelText, double left, double top)
        {
            // Создаем эллипс для узла
            Ellipse nodeShape = new Ellipse
            {
                Width = 50, // Ширина узла
                Height = 50, // Высота узла
                Fill = Brushes.Gold, // Золотой цвет узла
                Stroke = Brushes.White, // Белая обводка узла
                StrokeThickness = 2 // Толщина обводки
            };

            // Устанавливаем положение узла на канве
            Canvas.SetLeft(nodeShape, left); // Устанавливаем позицию слева
            Canvas.SetTop(nodeShape, top); // Устанавливаем позицию сверху
            GraphCanvas.Children.Add(nodeShape); // Добавляем узел на канву

            // Создаем текстовую метку для узла
            TextBlock label = new TextBlock
            {
                Text = labelText, // Текст метки
                Foreground = Brushes.White, // Цвет текста — белый
                FontWeight = FontWeights.Bold, // Жирное начертание текста
                HorizontalAlignment = HorizontalAlignment.Center, // Горизонтальное выравнивание текста по центру
                VerticalAlignment = VerticalAlignment.Center // Вертикальное выравнивание текста по центру
            };

            // Устанавливаем положение метки над узлом
            Canvas.SetLeft(label, left + (nodeShape.Width - label.ActualWidth) / 2); // Позиция метки слева
            Canvas.SetTop(label, top + (nodeShape.Height - label.ActualHeight) / 2); // Позиция метки сверху
            GraphCanvas.Children.Add(label); // Добавляем метку на канву

            // Добавляем узел и его метку в список узлов графа
            graphNodes.Add(new GraphNode { NodeShape = nodeShape, Label = label }); // Добавление узла в список
        }

        /// <summary>
        /// Обработчик события для кнопки добавления узла.
        /// </summary>
        private void AddNodeButton_Click(object sender, RoutedEventArgs e)
        {
            string firstLabel = FirstNodeTextBox.Text.ToUpper(); // Получение текста первого поля и приведение к верхнему регистру
            string secondLabel = SecondNodeTextBox.Text.ToUpper(); // Получение текста второго поля и приведение к верхнему регистру

            // Проверка, что оба текстовых поля заполнены
            if (!string.IsNullOrEmpty(firstLabel) && !string.IsNullOrEmpty(secondLabel))
            {
                if (firstLabel != secondLabel) // Проверка, что метки не совпадают
                {
                    // Поиск узлов с указанными метками
                    var firstNode = graphNodes.FirstOrDefault(n => n.Label.Text == firstLabel); // Первый узел
                    var secondNode = graphNodes.FirstOrDefault(n => n.Label.Text == secondLabel); // Второй узел

                    if (firstNode != null && secondNode != null) // Проверка, что оба узла найдены
                    {
                        // Проверка, существует ли уже дуга между узлами
                        bool edgeExists = firstNode.ConnectedLines.Any(edge => edge.EndNode == secondNode) ||
                                          secondNode.ConnectedLines.Any(edge => edge.EndNode == firstNode);

                        if (edgeExists) // Если дуга существует, выводим сообщение
                        {
                            MessageBox.Show("Дуга между этими узлами уже существует в одном из направлений", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Warning);
                            return; // Прерываем выполнение
                        }

                        // Добавляем рёбер между узлами
                        graph.AddEdge(firstLabel, secondLabel);

                        // Рисуем линию между узлами
                        DrawEdge(firstNode, secondNode);
                    }
                    else
                    {
                        // Если один или оба узла не найдены, выводим сообщение
                        MessageBox.Show("Один или оба узла с указанными метками не найдены", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Warning);
                    }
                }
                else
                {
                    // Проверка, существует ли узел с меткой firstLabel
                    var existingNode = graphNodes.FirstOrDefault(n => n.Label.Text == firstLabel);
                    if (existingNode != null) // Если узел найден
                    {
                        MessageBox.Show("Узел с такой меткой уже существует", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Warning);
                        return; // Прерываем выполнение
                    }

                    // Создаем новый узел с меткой firstLabel
                    var newNode = DrawNode(graphNodes.Count, firstLabel);

                    // Поиск узла с меткой secondLabel
                    var connectedNode = graphNodes.FirstOrDefault(n => n.Label.Text == secondLabel);

                    if (connectedNode != null) // Если узел найден, соединяем его с новым узлом
                    {
                        //graph.AddEdge(firstLabel, secondLabel);
                    }
                    else
                    {
                        // Если узел не найден, выводим предупреждение
                        MessageBox.Show("Узел с меткой второго узла не найден", "Предупреждение", MessageBoxButton.OK, MessageBoxImage.Warning);
                    }
                }
            }
            else
            {
                // Вывод предупреждения, если поля не заполнены
                MessageBox.Show("Заполните оба текстовых поля", "Предупреждение", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }



        // <summary>
        // Метод для вычисления позиции узла на окружности.
        // </summary>
        // <param name="nodeIndex">Индекс узла.</param>
        // <param name="totalNodes">Общее количество узлов.</param>
        // <param name="centerX">Координата X центра окружности.</param>
        // <param name="centerY">Координата Y центра окружности.</param>
        // <param name="baseRadius">Радиус окружности.</param>
        // <returns>Координаты позиции узла в виде объекта Point.</returns>
        private Point CalculateNodePosition(int nodeIndex, int totalNodes, double centerX, double centerY, double baseRadius)
        {
            if (nodeIndex == 0) // Если узел первый, помещаем его в центр
            {
                return new Point(centerX, centerY); // Возвращаем координаты центра
            }

            double angleStep = 2 * Math.PI / (totalNodes - 1); // Шаг угла для остальных узлов
            double currentAngle = (nodeIndex - 1) * angleStep; // Текущий угол для вычисления координат

            double x = centerX + baseRadius * Math.Cos(currentAngle); // Вычисление координаты X
            double y = centerY + baseRadius * Math.Sin(currentAngle); // Вычисление координаты Y

            return new Point(x, y); // Возвращаем вычисленные координаты
        }

        /// <summary>
        /// Создает и отображает новый узел на канве с заданной меткой.
        /// </summary>
        /// <param name="nodeIndex">Индекс узла, определяющий его расположение.</param>
        /// <param name="label">Текстовая метка, отображаемая на узле.</param>
        /// <returns>Созданный объект GraphNode.</returns>
        private GraphNode DrawNode(int nodeIndex, string label)
        {
            // Вычисление позиции узла
            double centerX = GraphCanvas.ActualWidth / 2;
            double centerY = GraphCanvas.ActualHeight / 2;
            double baseRadius = 100;
            Point position = CalculateNodePosition(nodeIndex, graphNodes.Count + 1, centerX, centerY, baseRadius);

            // Создание узла
            Ellipse node = new Ellipse
            {
                Width = 30,
                Height = 30,
                Fill = Brushes.Gold,
                Stroke = Brushes.White,
                StrokeThickness = 2
            };

            node.MouseLeftButtonDown += Node_MouseLeftButtonDown;
            node.MouseMove += Node_MouseMove;
            node.MouseLeftButtonUp += Node_MouseLeftButtonUp;

            Canvas.SetLeft(node, position.X - node.Width / 2);
            Canvas.SetTop(node, position.Y - node.Height / 2);
            GraphCanvas.Children.Add(node);

            // Создание метки
            TextBlock text = new TextBlock
            {
                Text = label,
                FontWeight = FontWeights.Bold,
                Foreground = Brushes.White
            };

            GraphCanvas.Children.Add(text);
            Canvas.SetLeft(text, position.X - text.ActualWidth / 2 - 5);
            Canvas.SetTop(text, position.Y - text.ActualHeight / 2 - 8);

            // Создание объекта GraphNode
            var graphNode = new GraphNode
            {
                Id = nodeIdCounter++,
                NodeShape = node,
                Label = text,
                ConnectedLines = new List<GraphEdge>()
            };

            graphNodes.Add(graphNode);

            return graphNode;
        }


        /// <summary>
        /// Удаляет узел из графа по указанной текстовой метке.
        /// </summary>
        /// <param name="label">Текст метки узла, который нужно удалить.</param>
        private void RemoveNode(string label)
        {
            // Поиск узла по метке
            var nodeToRemove = graphNodes.FirstOrDefault(n => n.Label.Text == label); // Ищем узел с заданной меткой

            if (nodeToRemove != null) // Проверяем, найден ли узел
            {
                // Удаление всех линий, связанных с узлом
                foreach (var edge in nodeToRemove.ConnectedLines.ToList()) // Проходим по всем связанным линиям
                {
                    GraphCanvas.Children.Remove(edge.Line); // Удаляем линию с канвы
                                                            // Поиск узла, связанного с этой линией
                    var connectedNode = graphNodes.FirstOrDefault(n => n.ConnectedLines.Contains(edge)); // Ищем узел, у которого есть эта линия
                    if (connectedNode != null) // Если узел найден
                    {
                        connectedNode.ConnectedLines.Remove(edge); // Удаляем связь с линией
                    }
                }
                graph.RemoveNode(label);
                // Удаление узла и его метки с канвы
                GraphCanvas.Children.Remove(nodeToRemove.NodeShape); // Удаляем узел с канвы
                GraphCanvas.Children.Remove(nodeToRemove.Label); // Удаляем метку с канвы
                graphNodes.Remove(nodeToRemove); // Удаляем узел из списка узлов
            }
        }

        /// <summary>
        /// Удаляет ребро между двумя узлами по заданным меткам.
        /// </summary>
        /// <param name="firstLabel">Метка первого узла.</param>
        /// <param name="secondLabel">Метка второго узла.</param>
        private void RemoveEdge(string firstLabel, string secondLabel)
        {
            // Поиск узлов по меткам
            var node1 = graphNodes.FirstOrDefault(n => n.Label.Text == firstLabel); // Ищем первый узел
            var node2 = graphNodes.FirstOrDefault(n => n.Label.Text == secondLabel); // Ищем второй узел

            if (node1 != null && node2 != null) // Проверяем, что оба узла найдены
            {
                // Поиск линии между узлами
                var edgeToRemove = node1.ConnectedLines.FirstOrDefault(e => e.IsStart && graphNodes.Any(n => n.ConnectedLines.Contains(e))); // Ищем линию между узлами
                if (edgeToRemove != null) // Если линия найдена
                {
                    graph.RemoveEdge(firstLabel, secondLabel);
                    GraphCanvas.Children.Remove(edgeToRemove.Line); // Удаляем линию с канвы
                    node1.ConnectedLines.Remove(edgeToRemove); // Удаляем связь из первого узла
                    node2.ConnectedLines.Remove(edgeToRemove); // Удаляем связь из второго узла
                }
            }
        }

        /// <summary>
        /// Рисует ребро между двумя узлами и добавляет его на канву.
        /// </summary>
        /// <param name="node1">Первый узел.</param>
        /// <param name="node2">Второй узел.</param>
        private void DrawEdge(GraphNode firstNode, GraphNode secondNode)
        {
            // Создаём линию
            Line edgeLine = new Line
            {
                X1 = Canvas.GetLeft(firstNode.Label) + firstNode.Label.ActualWidth / 2,
                Y1 = Canvas.GetTop(firstNode.Label) + firstNode.Label.ActualHeight / 2,
                X2 = Canvas.GetLeft(secondNode.Label) + secondNode.Label.ActualWidth / 2,
                Y2 = Canvas.GetTop(secondNode.Label) + secondNode.Label.ActualHeight / 2,
                Stroke = Brushes.White,
                StrokeThickness = 2
            };

            // Устанавливаем Z-индекс линии ниже узлов
            Panel.SetZIndex(edgeLine, -1);

            // Добавляем линию на Canvas
            GraphCanvas.Children.Add(edgeLine);

            // Обновляем информацию о соединении для первого узла
            firstNode.ConnectedLines.Add(new GraphEdge(firstNode, secondNode, edgeLine));

            // Обновляем информацию о соединении для второго узла
            secondNode.ConnectedLines.Add(new GraphEdge(secondNode, firstNode, edgeLine));
        }




        /// <summary>
        /// Обработчик события нажатия левой кнопкой мыши на узел.
        /// </summary>
        /// <param name="sender">Объект-источник события.</param>
        /// <param name="e">Аргументы события.</param>
        private void Node_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            selectedNode = sender as Ellipse; // Сохраняем выбранный узел
            isDragging = true; // Активируем режим перетаскивания
            clickPosition = e.GetPosition(GraphCanvas); // Запоминаем позицию клика на канве
            selectedNode.CaptureMouse(); // Захватываем мышь для текущего узла
        }

        /// <summary>
        /// Обработчик события перемещения мыши при удержании узла.
        /// </summary>
        /// <param name="sender">Объект-источник события.</param>
        /// <param name="e">Аргументы события.</param>
        private void Node_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDragging && selectedNode != null)
            {
                Point currentPosition = e.GetPosition(GraphCanvas);
                double offsetX = currentPosition.X - clickPosition.X;
                double offsetY = currentPosition.Y - clickPosition.Y;

                double newX = Canvas.GetLeft(selectedNode) + offsetX;
                double newY = Canvas.GetTop(selectedNode) + offsetY;

                // Ограничение координат
                double canvasWidth = GraphCanvas.ActualWidth;
                double canvasHeight = GraphCanvas.ActualHeight;
                double nodeWidth = selectedNode.Width;
                double nodeHeight = selectedNode.Height;

                if (newX < 5) newX = 5;
                else if (newX + nodeWidth > canvasWidth - 5) newX = canvasWidth - nodeWidth - 5;

                if (newY < 5) newY = 5;
                else if (newY + nodeHeight > canvasHeight - 5) newY = canvasHeight - nodeHeight - 5;

                // Устанавливаем новую позицию узла
                Canvas.SetLeft(selectedNode, newX);
                Canvas.SetTop(selectedNode, newY);

                // Обновляем связанные линии
                UpdateConnectedElements(selectedNode, newX, newY);

                clickPosition = currentPosition;
            }
        }





        /// <summary>
        /// Обработчик события отпускания левой кнопки мыши на узле.
        /// </summary>
        /// <param name="sender">Объект-источник события.</param>
        /// <param name="e">Аргументы события.</param>
        private void Node_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            if (isDragging) // Проверяем, активен ли режим перетаскивания
            {
                isDragging = false; // Деактивируем режим перетаскивания
                selectedNode.ReleaseMouseCapture(); // Освобождаем захват мыши

                // Получаем текущие координаты узла после его перемещения
                double newX = Canvas.GetLeft(selectedNode);
                double newY = Canvas.GetTop(selectedNode);

                // Обновляем связанные с узлом элементы
                UpdateConnectedElements(selectedNode, newX, newY);

                selectedNode = null; // Сбрасываем выбранный узел
            }
        }


        /// <summary>
        /// Обновляет положение узла и всех связанных с ним элементов на канве.
        /// </summary>
        /// <param name="node">Узел, который нужно обновить.</param>
        /// <param name="newX">Новое значение координаты X для узла.</param>
        /// <param name="newY">Новое значение координаты Y для узла.</param>
        private void UpdateConnectedElements(Ellipse node, double newX, double newY)
        {
            // Перебираем все узлы графа
            foreach (var graphNode in graphNodes)
            {
                // Проверяем, совпадает ли узел с переданным
                if (graphNode.NodeShape == node)
                {


                    // Обновление положения текстовой метки
                    Canvas.SetLeft(graphNode.Label, newX + node.Width / 2 - graphNode.Label.ActualWidth / 2);
                    Canvas.SetTop(graphNode.Label, newY + node.Height / 2 - graphNode.Label.ActualHeight / 2);

                    // Обновление положения концов линий
                    foreach (var edge in graphNode.ConnectedLines)
                    {
                        if (edge.IsStart) // Если линия начинается с данного узла
                        {
                            edge.Line.X1 = newX + node.Width / 2; // Обновление X1
                            edge.Line.Y1 = newY + node.Height / 2; // Обновление Y1
                        }
                        else // Если линия заканчивается на данном узле
                        {
                            edge.Line.X2 = newX + node.Width / 2; // Обновление X2
                            edge.Line.Y2 = newY + node.Height / 2; // Обновление Y2
                        }
                    }
                    break; // Выход из цикла после обновления
                }
            }
        }

        /// <summary>
        /// Обработчик нажатия кнопки для удаления узла или ребра между узлами.
        /// </summary>
        /// <param name="sender">Источник события.</param>
        /// <param name="eventArgs">Аргументы события.</param>
        private void DeleteNodeButton_Click(object sender, RoutedEventArgs eventArgs)
        {
            // Получение названий узлов из текстовых полей
            string firstLabel = FirstNodeTextBox.Text.ToUpper(); // Первая метка
            string secondLabel = SecondNodeTextBox.Text.ToUpper(); // Вторая метка

            // Проверка, что хотя бы одно поле заполнено
            if (!string.IsNullOrEmpty(firstLabel) && !string.IsNullOrEmpty(secondLabel))
            {
                if (firstLabel == secondLabel) // Если метки совпадают — удаляем узел
                {
                    // Удаление узла через объект класса Graph
                   // graph.RemoveNode(firstLabel);
                    MessageBox.Show($"Узел '{firstLabel}' успешно удалён.", "Информация", MessageBoxButton.OK, MessageBoxImage.Information);
                }
                else // Если метки не совпадают — удаляем ребро
                {
                    // Удаление ребра между двумя узлами
                   // graph.RemoveEdge(firstLabel, secondLabel);
                    MessageBox.Show($"Ребро между '{firstLabel}' и '{secondLabel}' успешно удалено.", "Информация", MessageBoxButton.OK, MessageBoxImage.Information);
                }
            }
            else
            {
                MessageBox.Show("Заполните оба текстовых поля.", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
        }



        /// <summary>
        /// Сохраняет содержимое канвы в изображение.
        /// </summary>
        /// <param name="canvas">Канва, содержимое которой нужно сохранить.</param>
        /// <param name="filePath">Путь к файлу, где будет сохранено изображение.</param>
        private void SaveCanvasAsImage(Canvas canvas, string filePath)
        {
            // Определяем размер канвы
            var width = (int)canvas.ActualWidth;   // Получаем ширину канвы
            var height = (int)canvas.ActualHeight; // Получаем высоту канвы

            // Создаем объект RenderTargetBitmap для отрисовки содержимого канвы
            var renderTargetBitmap = new RenderTargetBitmap(width+372, height, 96, 96, PixelFormats.Pbgra32); // Создаем RenderTargetBitmap

            // Отрисовываем содержимое канвы в bitmap
            renderTargetBitmap.Render(canvas);   // Отрисовка содержимого канвы

            // Создаем объект для сохранения изображения в формате JPG
            var jpegEncoder = new JpegBitmapEncoder
            {
                QualityLevel = 90 // Устанавливаем качество изображения (0-100)
            };
            jpegEncoder.Frames.Add(BitmapFrame.Create(renderTargetBitmap)); // Добавляем кадр с отрисованной канвой

            // Сохраняем изображение в файл
            using (var fileStream = new FileStream(filePath, FileMode.Create)) // Открываем поток для записи
            {
                jpegEncoder.Save(fileStream); // Сохраняем файл
            }
        }

        /// <summary>
        /// Обработчик нажатия кнопки для сохранения канвы как изображение.
        /// </summary>
        /// <param name="sender">Источник события.</param>
        /// <param name="e">Аргументы события.</param>
        private void SaveButton_Click(object sender, RoutedEventArgs e)
        {
            SaveCanvasAsImage(GraphCanvas, "GRAPH_DALV.png"); // Сохранение канвы в файл
        }

        /// <summary>
        /// Представляет узел графа.
        /// </summary>
        public class GraphNode
        {
            public int Id { get; set; } // Идентификатор узла
            public Ellipse NodeShape { get; set; } // Форма узла
            public TextBlock Label { get; set; } // Текстовая метка узла
            public List<GraphEdge> ConnectedLines { get; set; } // Список связанных рёбер
        }

        /// <summary>
        /// Представляет ребро графа.
        /// </summary>
        public class GraphEdge
        {
            public GraphNode StartNode { get; set; } // Начальный узел ребра
            public GraphNode EndNode { get; set; } // Конечный узел ребра
            public Line Line { get; set; } // Линия, представляющая ребро
            public bool IsStart { get; set; } // Флаг, указывающий, является ли данный узел началом ребра

            /// <summary>
            /// Конструктор класса GraphEdge.
            /// </summary>
            /// <param name="startNode">Начальный узел.</param>
            /// <param name="endNode">Конечный узел.</param>
            /// <param name="line">Линия, представляющая ребро.</param>
            public GraphEdge(GraphNode startNode, GraphNode endNode, Line line)
            {
                StartNode = startNode; // Инициализация начального узла
                EndNode = endNode; // Инициализация конечного узла
                Line = line; // Инициализация линии
            }
        }



    }
}
