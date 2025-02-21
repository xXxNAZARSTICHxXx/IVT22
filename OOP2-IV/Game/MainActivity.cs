using System;
using Android.App;
using Android.Content.PM;
using Android.Runtime;
using Android.OS;
using Android.Content;
using Xamarin.Forms;
using SkiaSharp;
using SkiaSharp.Views.Forms;
using Android.Views.InputMethods;
using Android.Views;
using Xamarin.Forms.PlatformConfiguration;
using static Android.Graphics.BlurMaskFilter;
using Android.Bluetooth;
using Java.Lang;
using Java.Security.Cert;
using static Android.InputMethodServices.Keyboard;
using Android.Hardware.Lights;
using static Android.Icu.Text.ListFormatter;
using System.Collections.Generic;
using System.Linq;
using Android.Widget;
using Xamarin.Essentials;
using static Android.Security.Identity.CredentialDataResult;

///Пространство SudokuEXE 
namespace SudokuEXE
{
    /// <summary>
    /// Класс инициализации
    /// </summary>
    [Activity(Label = "SudokuEXE", Icon = "@mipmap/icon", Theme = "@style/MainTheme", MainLauncher = true, ConfigurationChanges = ConfigChanges.ScreenSize | ConfigChanges.Orientation | ConfigChanges.UiMode | ConfigChanges.ScreenLayout | ConfigChanges.SmallestScreenSize, ScreenOrientation = ScreenOrientation.Portrait)]
    public class MainActivity : global::Xamarin.Forms.Platform.Android.FormsAppCompatActivity
    {
        /// <summary>
        /// Метод инициализации
        /// </summary>
        /// <param name="savedInstanceState"></param>
        protected override void OnCreate(Bundle savedInstanceState)
        {

            base.OnCreate(savedInstanceState);

            Xamarin.Essentials.Platform.Init(this, savedInstanceState);
            global::Xamarin.Forms.Forms.Init(this, savedInstanceState);
            LoadApplication(new App());

            // Создаем экземпляр ContentX
            var contentPage = new ContentX();
            
            // Устанавливаем ContentX как главную страницу
            Xamarin.Forms.Application.Current.MainPage = contentPage;
        }
    }

    /// <summary>
    /// Класс содержащий все и всея
    /// </summary>
    public partial class ContentX : ContentPage
    {
        /// <summary>
        /// ContentXElements - создает набор элементов для интерфейса
        /// </summary>
        private ContentXElements elements;

        /// <summary>
        /// Инициализатор
        /// </summary>
        public ContentX()
        {
            elements = new ContentXElements();
            InitializeElements();
            InitializeLayout();
        }
        /// <summary>
        /// Инициализация всех элементов интерфейса
        /// </summary>
        private void InitializeElements()
        {

            // Создаем абсолютный макет
            elements.AbsoluteLayout = new Xamarin.Forms.AbsoluteLayout();

            ScreenOrientation orientation = ScreenOrientation.Portrait;
            //DeviceDisplay.MainDisplayInfo.RequestOrientation(orientation);

            // Создаем рамку
            elements.Label1 = new Label
            {
                Text = "SudokU",
                FontFamily = Device.RuntimePlatform == Device.Android ? "serif" : "Times New Roman", // Для Android используется "serif"
                FontAttributes = FontAttributes.Bold | FontAttributes.Italic, // Устанавливаем жирное и курсивное начертание
                HorizontalTextAlignment = Xamarin.Forms.TextAlignment.Center,
                TextColor = Color.SkyBlue,
                FontSize = 36
            };

            elements.Frame1 = new Frame
            {
                BackgroundColor = Color.Transparent,
                Content = elements.Label1
            };

            elements.Label2 = new Label
            {
                Text = "You WIN",
                FontFamily = Device.RuntimePlatform == Device.Android ? "serif" : "Times New Roman", // Для Android используется "serif"
                FontAttributes = FontAttributes.Bold | FontAttributes.Italic, // Устанавливаем жирное и курсивное начертание
                HorizontalTextAlignment = Xamarin.Forms.TextAlignment.Center,
                TextColor = Color.Transparent,
                FontSize = 72
            };

            elements.Frame2 = new Frame
            {
                BackgroundColor = Color.Transparent,
                Content = elements.Label2
            };

            // Создаем SKCanvasView и добавляем его на страницу
            elements.CanvasView = new SKCanvasView();
            elements.CanvasView.PaintSurface += OnCanvasViewPaintSurface;

            // Создаем клавиатуру и редактируемую сетку
            elements.KeyboardGrid = CreateKeyboardGrid();
            elements.EditableGrid = EditableGridView(); // Инициализируем EditableGrid здесь

            // Инициализируем DataGrid после создания EditableGrid
            elements.DataGrid = elements.EditableGrid;
        }
        /// <summary>
        /// Инициализация приложения всего и всея
        /// </summary>
        private void InitializeLayout()
        {
            // Добавляем рамку в абсолютный макет
            Xamarin.Forms.AbsoluteLayout.SetLayoutBounds(elements.Frame1, new Rectangle(0.5, -0.025, 0.8, 0.5));
            Xamarin.Forms.AbsoluteLayout.SetLayoutFlags(elements.Frame1, AbsoluteLayoutFlags.All);
            elements.AbsoluteLayout.Children.Add(elements.Frame1);

            Xamarin.Forms.AbsoluteLayout.SetLayoutBounds(elements.Frame2, new Rectangle(0.5, 1, 1, 0.5));
            Xamarin.Forms.AbsoluteLayout.SetLayoutFlags(elements.Frame2, AbsoluteLayoutFlags.All);
            elements.AbsoluteLayout.Children.Add(elements.Frame2);

            // Создаем SKCanvasView и добавляем его на страницу
            Xamarin.Forms.AbsoluteLayout.SetLayoutBounds(elements.CanvasView, new Rectangle(0, 0, 1, 1));
            Xamarin.Forms.AbsoluteLayout.SetLayoutFlags(elements.CanvasView, AbsoluteLayoutFlags.All);
            elements.AbsoluteLayout.Children.Add(elements.CanvasView);

            // Задаем координаты и размеры для клавиатуры
            Xamarin.Forms.AbsoluteLayout.SetLayoutBounds(elements.KeyboardGrid, new Rectangle(0, 1, 1, 0.5));
            Xamarin.Forms.AbsoluteLayout.SetLayoutFlags(elements.KeyboardGrid, AbsoluteLayoutFlags.All);

            // Задаем координаты и размеры для редактируемой сетки
            Xamarin.Forms.AbsoluteLayout.SetLayoutBounds(elements.EditableGrid, new Rectangle(0.49, 0.165, 0.8, 0.4));
            Xamarin.Forms.AbsoluteLayout.SetLayoutFlags(elements.EditableGrid, AbsoluteLayoutFlags.All);

            // Добавляем клавиатуру и редактируемую сетку на макет
            elements.AbsoluteLayout.Children.Add(elements.KeyboardGrid);
            elements.AbsoluteLayout.Children.Add(elements.EditableGrid);

            Content = elements.AbsoluteLayout;
        }

        /// <summary>
        /// Создание сборки полей Grid
        /// </summary>
        private Entry[,] entries;

        /// <summary>
        /// Метод создания полей в Grid
        /// </summary>
        /// <returns></returns>
        private Grid EditableGridView()
        {
            var dataGrid = new Grid();
            elements.Entries = new Entry[9, 9]; // Инициализация массива в классе ContentXElements

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    var entry = new Entry
                    {
                        Text = "",
                        HorizontalOptions = LayoutOptions.FillAndExpand,
                        VerticalOptions = LayoutOptions.FillAndExpand,
                        Keyboard = Keyboard.Numeric,
                        Margin = new Thickness(-6),
                        IsTextPredictionEnabled = false,
                        MaxLength = 1,
                        HorizontalTextAlignment = Xamarin.Forms.TextAlignment.Center,
                        VerticalTextAlignment = Xamarin.Forms.TextAlignment.Center,
                        TextColor = Color.White,
                        BackgroundColor = Color.Transparent,
                        PlaceholderColor = Color.Transparent
                    };

                    elements.Entries[i, j] = entry; // Сохранение ссылки на Entry в массиве

                    // Устанавливаем события для обработки фокуса и снятия фокуса
                    entry.Focused += Entry_Focused;
                    entry.Unfocused += Entry_Unfocused;

                    dataGrid.Children.Add(entry, j, i);
                }
            }

            // Заблокируем определенные ячейки
            BlockCells(dataGrid);
            Placefication(elements.Entries);
            return dataGrid;
        }

        // Метод для блокировки определенных ячеек
        private void BlockCells(Grid grid)
        {
            int[] blockedPositions = { 1, 2, 4, 5, 6, 8, 9, 10, 18, 20, 23, 26, 29, 30, 31, 33, 34, 35, 38, 39, 43, 44, 47, 48, 49, 51, 52, 53, 56, 59, 62, 64, 72, 73, 74, 76, 77, 78, 80, 81 };
            foreach (int position in blockedPositions)
            {
                int row = (position - 1) / 9;
                int column = (position - 1) % 9;
                if (grid.Children[row * 9 + column] is Entry entry)
                {
                    entry.InputTransparent = true;
                }
            }
        }

        // Обработчик события для фокуса
        private void Entry_Focused(object sender, FocusEventArgs e)
        {
            if (sender is Entry entry)
            {
                YellowFocusChecked();
                entry.TextColor = Color.Yellow; // Цвет текста при фокусе
                entry.Unfocus();

            }
        }
        
        /// <summary>
        /// Метод проверки на желтое поле
        /// </summary>
        private void YellowFocusChecked()
        {
            Entry[,] entries = elements.Entries; // Инициализируем массив entries
            foreach (Entry entry in entries)
            {
                // Получаем текущую позицию ячейки
                int row = Grid.GetRow(entry);
                int col = Grid.GetColumn(entry);

                if (entry.TextColor == Color.Yellow  && !entry.InputTransparent)
                {
                    entry.TextColor = Color.SkyBlue;
                    RedProcessGridElements();
                }
                else if (entry.TextColor == Color.Yellow && entry.InputTransparent)
                {
                    entry.TextColor = Color.White;
                    RedProcessGridElements();
                }
            }
        }

        /// <summary>
        /// // Обработчик события для потери фокуса
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Entry_Unfocused(object sender, FocusEventArgs e)
        {
            
        }

        /// <summary>
        /// Метод расстановки цифр на поле в судоку
        /// </summary>
        /// <param name="entries"></param>
        private void Placefication(Entry[,] entries)
        {
            SudokuGenerator generator = new SudokuGenerator();
            int[,] sudoku = generator.Generate();

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    Entry entry = entries[i, j]; // Получаем доступ к элементу массива Entry

                    if (entry != null && entry.InputTransparent)
                    {
                        entry.Text = sudoku[i, j].ToString();
                    }
                }
            }
        }

        /// <summary>
        /// Метод проверки на неправильные значения 
        /// </summary>
        private void RedProcessGridElements()
        {
            int number;
            Entry[,] entries = elements.Entries; // Инициализируем массив entries
            foreach (Entry entry in entries)
            {
                // Получаем текущую позицию ячейки
                int row = Grid.GetRow(entry);
                int col = Grid.GetColumn(entry);

                if ((entry.TextColor == Color.LightCoral || entry.TextColor == Color.SkyBlue) && !entry.InputTransparent)
                {
                    if (int.TryParse(entry.Text, out number))
                    {
                        // Проверяем, есть ли уже такое число в квадрате, строке и столбце
                        if (!IsNumberValid(entries, row, col, number))
                        {
                            entry.TextColor = Color.LightCoral; // Выделение красным цветом
                        }
                        else
                        {
                            entry.TextColor = Color.SkyBlue;
                        }
                    }

                }
                else
                {
                    if (int.TryParse(entry.Text, out number))
                    {
                        // Проверяем, есть ли уже такое число в квадрате, строке и столбце
                        if (!IsNumberValid(entries, row, col, number))
                        {
                            entry.TextColor = Color.Red; // Выделение красным цветом
                        }
                        else
                        {
                            entry.TextColor = Color.White;
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Иетод выйгрыша в судоку
        /// </summary>
        private void Win()
        {
            bool allCellsFilled = true;
            bool allCellsValid = true;

            Entry[,] entries = elements.Entries; // Инициализируем массив entries

            foreach (Entry entry in entries)
            {
                // Проверяем, заполнены ли все ячейки
                if (string.IsNullOrEmpty(entry.Text) && !entry.InputTransparent)
                {
                    allCellsFilled = false;
                }

                // Проверяем, все ли числа валидны
                if (entry.TextColor == Color.LightCoral || entry.TextColor == Color.Yellow)
                {
                    allCellsValid = false;
                }
            }

            // Если все ячейки заполнены и все числа валидны, меняем цвет Label2 на зеленый
            if (allCellsFilled && allCellsValid)
            {
                elements.Label2.TextColor = Color.LightGreen;
            }
        }


        /// <summary>
        /// Метод для проверки наличия числа в квадрате, строке и столбце
        /// </summary>
        /// <param name="entries"></param>
        /// <param name="row"></param>
        /// <param name="col"></param>
        /// <param name="number"></param>
        /// <returns></returns>
        private bool IsNumberValid(Entry[,] entries, int row, int col, int number)
        {
            // Проверка наличия числа в квадрате
            int startRow = row - row % 3;
            int startCol = col - col % 3;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (entries[startRow + i, startCol + j] != null && !entries[startRow + i, startCol + j].Equals(entries[row, col]) && int.TryParse(entries[startRow + i, startCol + j].Text, out int value) && value == number)
                    {
                        return false;
                    }
                }
            }

            // Проверка наличия числа в строке
            for (int i = 0; i < 9; i++)
            {
                if (entries[row, i] != null && !entries[row, i].Equals(entries[row, col]) && int.TryParse(entries[row, i].Text, out int value) && value == number)
                {
                    return false;
                }
            }

            // Проверка наличия числа в столбце
            for (int i = 0; i < 9; i++)
            {
                if (entries[i, col] != null && !entries[i, col].Equals(entries[row, col]) && int.TryParse(entries[i, col].Text, out int value) && value == number)
                {
                    return false;
                }
            }

            return true;
        }

        /// <summary>
        /// Создание кнопок
        /// </summary>
        /// <returns></returns>
        private Grid CreateKeyboardGrid()
        {
            var grid = new Grid
            {
                RowSpacing = 5,
                ColumnSpacing = 5
            };

            // Добавляем строки с процентным размером
            grid.RowDefinitions.Add(new RowDefinition { Height = new GridLength(80, GridUnitType.Star) });
            grid.RowDefinitions.Add(new RowDefinition { Height = new GridLength(20, GridUnitType.Star) });
            // Кнопки
            var buttonsRow = new Grid
            {
                RowSpacing = 0,
                ColumnSpacing = 5
            };

            for (int i = 1; i <= 9; i++)
            {
                Xamarin.Forms.Button button = new Xamarin.Forms.Button
                {
                    Text = i.ToString(),
                    FontSize = 20,
                    BorderWidth = 1,
                    BorderColor = Xamarin.Forms.Color.Black
                };

                // Добавляем обработчик события Clicked для каждой кнопки
                button.Clicked += (sender, args) =>
                {
                    
                    // Проходим по всем элементам Entry в DataGrid
                    foreach (var child in elements.DataGrid.Children)
                    {
                        if (child is Entry entry && entry.TextColor == Xamarin.Forms.Color.Yellow)
                        {
                            // Заменяем текст Entry на текст кнопки
                            entry.Text = ((Xamarin.Forms.Button)sender).Text;
                            entry.TextColor = Color.SkyBlue;
                            break; // Выходим из цикла после замены первого встреченного желтого Entry
                        }
                    }
                    RedProcessGridElements();
                    Win();
                };

                buttonsRow.Children.Add(button, i - 1, 4);
            }

            grid.Children.Add(buttonsRow, 0, 0); // Добавляем ряд кнопок на главный грид
            Grid.SetColumnSpan(buttonsRow, 3); // Распространяем кнопки на все три столбца

            // Кнопка "Начать заново"
            Xamarin.Forms.Button startButton = new Xamarin.Forms.Button
            {
                Text = "Начать заново",
                FontSize = 14,
                BorderWidth = 1,
                BorderColor = Xamarin.Forms.Color.Black

            };
            // Связываем метод StartButtonClicked с обработчиком событий Clicked кнопки "Начать заново"
            startButton.Clicked += StartButtonClicked;

            grid.Children.Add(startButton, 0, 1); // Добавляем кнопку "Начать заново" на вторую строку главного грида, первый столбец
            Grid.SetColumnSpan(startButton, 1); // Распространяем кнопку "Начать заново" на один столбец

            // Кнопка "Стереть число"
            Xamarin.Forms.Button eraseButton = new Xamarin.Forms.Button
            {
                Text = "Стереть число",
                FontSize = 22,
                BorderWidth = 1,
                BorderColor = Xamarin.Forms.Color.Black
            };
            // Связываем метод StartButtonClicked с обработчиком событий Clicked кнопки "Начать заново"
            eraseButton.Clicked += EraseButtonClicked;

            grid.Children.Add(eraseButton, 1, 1); // Добавляем кнопку "Стереть число" на вторую строку главного грида, второй столбец
            Grid.SetColumnSpan(eraseButton, 2); // Распространяем кнопку "Стереть число" на два столбца

            Content = grid;
            return grid; // Возвращаем созданную сетку
        }

        /// <summary>
        /// Метод кнопки начать сначала
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void StartButtonClicked(object sender, EventArgs e)
        {
            // Получаем доступ к массиву Entry
            Entry[,] entries = elements.Entries;

            

            // Очищаем текст в каждой ячейке Entry, если текстовый цвет равен Color.Yellow
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    Entry entry = entries[i, j]; // Получаем доступ к элементу массива Entry

                    if (entry != null)
                    {
                        entry.Text = ""; // Очищаем текст в ячейке
                    }
                }
            }

            // Передаем массив Entry в метод Placefication
            Placefication(entries);
            RedProcessGridElements();
            elements.Label2.TextColor = Color.Transparent; 
        }

        /// <summary>
        /// Метод кнопки удаления
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void EraseButtonClicked(object sender, EventArgs e)
        {
            // Получаем доступ к массиву Entry
            Entry[,] entries = elements.Entries;

            // Очищаем текст в каждой ячейке Entry, если текстовый цвет равен Color.Yellow
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    Entry entry = entries[i, j]; // Получаем доступ к элементу массива Entry

                    if (entry != null && entry.TextColor == Color.Yellow)
                    {
                        entry.Text = ""; // Очищаем текст в ячейке
                    }
                }
            }
            RedProcessGridElements();
        }


        /// <summary>
        /// Метод рисования поля судоку
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="args"></param>
        private void OnCanvasViewPaintSurface(object sender, SKPaintSurfaceEventArgs args)
        {
            SKCanvas canvas = args.Surface.Canvas;
            SKImageInfo info = args.Info;
            SKPaint paint = new SKPaint
            {
                Style = SKPaintStyle.Stroke,
                Color = SKColors.White,
                StrokeWidth = 2
            };

            float StandardWidth = info.Width / 11;
            float StandardHeight = info.Height / 11 / 2;

            // Рисуем вертикальные линии
            for (int i = 1; i <= 8; i++)
            {
                float x = StandardWidth + StandardWidth * i;
                canvas.DrawLine(x, StandardHeight*2, x, info.Height / 2, paint);
            }

            // Рисуем горизонтальные линии
            for (int i = 1; i <= 8; i++)
            {
                float y = StandardHeight *3 + StandardHeight * i;
                canvas.DrawLine(StandardWidth, y, info.Width - StandardWidth, y, paint);
            }

            SKPaint paint2 = new SKPaint
            {
                Style = SKPaintStyle.Fill, // Установка стиля заполнения
                Color = SKColors.White // Установка цвета
            };

            canvas.DrawRect(StandardWidth * 4 - 8, StandardHeight * 2, 16, StandardHeight * 9 + StandardHeight / 10, paint2);
            canvas.DrawRect(StandardWidth * 7 - 8, StandardHeight * 2, 16, StandardHeight * 9 + StandardHeight / 10, paint2);

            canvas.DrawRect(StandardWidth - 16, StandardHeight * 2, 20, StandardHeight * 9 + StandardHeight / 10, paint2);
            canvas.DrawRect(StandardWidth * 10 - 16, StandardHeight * 2, 20, StandardHeight * 9 + StandardHeight / 10, paint2);
            canvas.DrawRect(StandardWidth, StandardHeight * 2, StandardWidth * 9 + StandardWidth / 50, 16, paint2);
            canvas.DrawRect(StandardWidth, StandardHeight * 11 - 6, StandardWidth * 9 + StandardWidth / 50, 16, paint2);

            canvas.DrawRect(StandardWidth, StandardHeight * 5 - 8, StandardWidth * 9 + StandardWidth / 50, 16, paint2);
            canvas.DrawRect(StandardWidth, StandardHeight * 8 - 8, StandardWidth * 9 + StandardWidth / 50, 16, paint2);
        }


    }
}