using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using Newtonsoft.Json;
using System.Windows;
using System.Windows.Controls;
using System.Net.Http;
using System.Xml;
using HtmlAgilityPack;
using System.Windows.Media.Imaging;
using System.Windows.Documents;
using System.Windows.Media;
using Newtonsoft.Json.Linq;
using System.Security.Policy;
using System.Windows.Media.Media3D;
using System.Net.Sockets;
using System.Windows.Markup;
using System.Diagnostics;
using ChatBot;
#pragma warning disable CS4014


namespace ChatBot
{

    // dynamic указывает на то, что тип переменной будет определен во время выполнения программы
    // (или во время компиляции с использованием dynamic), в отличие от статической типизации,
    // где тип переменной определяется во время компиляции.

    //REGDynamicModule - класс на регулярные выражения
    public class REGDynamicModule
    {
        public static void UpdateElements(ref StackPanel allPanel, ref Canvas canvaA, ref TextBlock textA, ref TextBlock textB, ref Canvas canvaB, double plus)
        {
            allPanel.Height += plus;
            canvaA.Height += plus;
            textA.Height += plus;
            textB.Height += plus;
            canvaB.Height += plus;
        }


        //Разделить файл по MVC ~ Не передавать все сразу и вообще сделать только текст




        /// <summary>
        /// GetImagePath - получение пути расположения изображения
        /// </summary>
        /// <param name="image"> - картинка </param>
        /// <returns></returns>
        /// m
        public static string GetImagePath(Image image)
        {
            if (image.Source is BitmapImage bitmapImage && bitmapImage.UriSource != null) //Проверяем, что источник изображения является BitmapImage и имеет непустой UriSource
            {
                string imagePath = bitmapImage.UriSource.ToString(); //Получаем строковое представление UriSource изображения
                return imagePath; //Возвращаем полученный путь к изображению
            }
            else
            {
                return null; //Возвращаем null, если путь к изображению не может быть получен
            }
        }




        /// <summary>
        /// CountLines - подсчет кол-ва строк в текстбоксе
        /// </summary>
        /// <param name="textBlock"> textBlock - используемый текстблок </param>
        /// <returns></returns>
        /// m
        public static int CountLines(TextBlock textBlock)
        {
            char[] newLineChars = { '\r', '\n' }; //Разделители строк
            string text = textBlock.Text; //Получаем текст из TextBlock
            string[] lines = text.Split(newLineChars, StringSplitOptions.RemoveEmptyEntries); //Разделяем текст на строки
            return lines.Length; //Возвращаем количество строк
        }

        /// <summary>
        /// GetCurrentTemperature - функция парсинга температуры
        /// </summary>
        /// <returns></returns>
        /// m
        public static string GetCurrentTemperature()
        {
            try
            {
                using (HttpClient client = new HttpClient()) // Создаем экземпляр HttpClient для выполнения HTTP-запросов
                {
                    HttpResponseMessage response = client.GetAsync("https://www.gismeteo.ru/weather-chita-4797/now/").Result; //Отправляем GET-запрос по указанному URL и получаем ответ
                    response.EnsureSuccessStatusCode(); //Проверяем, успешно ли выполнен запрос
                    string responseBody = response.Content.ReadAsStringAsync().Result; //Получаем тело ответа в виде строки
                    HtmlDocument document = new HtmlDocument(); //Создаем новый объект HtmlDocument для парсинга HTML
                    document.LoadHtml(responseBody); //Загружаем HTML-код страницы в HtmlDocument
                    HtmlNode temperatureNode = document.DocumentNode.SelectSingleNode("//span[contains(@class, 'unit unit_temperature_c')]"); //Ищем узел, содержащий температуру, с помощью XPath
                    if (temperatureNode != null) //Проверяем, удалось ли найти узел с температурой
                    {
                        return temperatureNode.InnerText.Trim(); //Возвращаем текстовое содержимое узла с температурой (температура в градусах Цельсия)
                    }
                    else
                    {
                        return "X"; //Если узел с температурой не найден, возвращаем символ "X" для обозначения ошибки
                    }
                }
            }
            catch (HttpRequestException ex) //Обрабатываем исключение, если произошла ошибка при выполнении HTTP-запроса
            {
                Console.WriteLine("Ошибка при запросе:", ex.Message); //Выводим сообщение об ошибке в консоль
                return "Ошибка при запросе"; //Возвращаем строку с сообщением об ошибке
            }
        }


        /// <summary>
        /// ImageHelper - класс для взаимодействия 
        /// </summary>
        /// m
        public class ImageHelper
        {
            /// <summary>
            /// ChangeImageSource - изменение картинки
            /// </summary>
            /// <param name="image"> - картинка </param>
            /// <param name="imagePath"> - картинка с полем </param>
            public static void ChangeImageSource(Image image, string imagePath)
            {
                try
                {
                    BitmapImage bitmap = new BitmapImage(); //Создаем новый объект BitmapImage для загрузки изображения
                    bitmap.BeginInit(); //Начинаем инициализацию BitmapImage
                    bitmap.UriSource = new Uri(imagePath, UriKind.RelativeOrAbsolute); //Устанавливаем источник изображения для BitmapImage с помощью переданного пути к изображению
                    bitmap.EndInit(); //Завершаем инициализацию BitmapImage
                    image.Source = bitmap; //Устанавливаем источник изображения для элемента Image
                }
                catch (Exception ex) //Обрабатываем исключение, если произошла ошибка при изменении изображения
                {
                    Console.WriteLine("Ошибка при изменении изображения: " + ex.Message); //Выводим сообщение об ошибке в консоль
                }
            }

        }
        /// <summary>
        /// CreateImage - функция создания картинки
        /// </summary>
        /// <param name="imagePath"> - ссылка картинки </param>
        /// <param name="refCanvas"> - канва с изобржениями </param>
        /// <param name="width"> - ширина </param>
        /// <param name="height"> - высота </param>
        /// <param name="left"> - отступ слева </param>
        /// <param name="top"> - отступ сверху </param>
        /// m
        public static void CreateImage(string imagePath, ref Canvas refCanvas, double width, double height, double left, double top)
        {
            Image image = new Image(); //Создаем новый объект Image        
            BitmapImage bitmap = new BitmapImage(new Uri(imagePath, UriKind.Relative)); //Создаем новый объект BitmapImage, который будет представлять изображение            
            image.Source = bitmap; //Устанавливаем свойство Source объекта Image         
            image.Width = width; //Устанавливаем размер изображения - ширина
            image.Height = height; //Устанавливаем размер изображения - высота
            image.Stretch = Stretch.Fill; //Устанавливаем растягивание изображения на всю доступную область
            Canvas.SetLeft(image, left); //Устанавливаем позицию изображения на Canvas
            Canvas.SetTop(image, top); //Устанавливаем позицию изображения на Canvas
            refCanvas.Children.Add(image); //Добавляем изображение на Canvas
        }

        /// <summary>
        /// CreateImageUrl - функция создания картинки с парсинга сайта
        /// </summary>
        /// <param name="imageUrl"> - ссылка с парсингвыми изображениями </param>
        /// <param name="canvas"> - канва с парсингвыми изображениями  </param>
        /// <param name="width"> - ширина </param>
        /// <param name="height"> - высота </param>
        /// <param name="left"> - отступ слева </param>
        /// <param name="top"> - отступ сверху </param>
        /// m
        public static void CreateImageUrl(string imageUrl, Canvas canvas, double width, double height, double left, double top)
        {
            try
            {
                Image image = new Image(); //Создаем новый объект Image
                BitmapImage bitmap = new BitmapImage(new Uri(imageUrl)); // Создаем новый объект BitmapImage, который будет представлять изображение
                image.Source = bitmap; //Устанавливаем свойство Source объекта Image
                image.Width = 700; //Устанавливаем размер изображения - ширина
                image.Height = 700; //Устанавливаем размер изображения - высота
                image.Stretch = Stretch.Fill; //Устанавливаем растягивание изображения на всю доступную область
                Canvas.SetLeft(image, left); //Устанавливаем позицию изображения на Canvas
                Canvas.SetTop(image, top); //Устанавливаем позицию изображения на Canvas
                canvas.Children.Add(image); //Добавляем изображение на Canvas
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка при создании изображения: {ex.Message}", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error); // Вывод ошибки на экран
            }
        }

        /// <summary>
        /// DownloadImageAsync - функция парсинга картинки
        /// </summary>
        /// <param name="imageUrl"> - ссылка на картинку</param>
        /// <returns></returns>
        /// <exception cref="Exception"></exception>
        /// m
        public static async Task<string> DownloadImageAsync(string imageUrl)
        {
            try
            {
                using (var httpClient = new HttpClient()) //Создаем экземпляр HttpClient для загрузки изображения с веб-сервера
                {
                    var response = await httpClient.GetAsync(imageUrl); //Выполняем GET-запрос по указанному URL-адресу изображения
                    response.EnsureSuccessStatusCode(); //Проверяем, что ответ успешен
                    byte[] imageBytes = await response.Content.ReadAsByteArrayAsync(); //Читаем содержимое ответа в виде массива байтов
                    string tempImagePath = Path.Combine(Path.GetTempPath(), Path.GetRandomFileName()); //Генерируем путь к временному файлу для изображения
                    File.WriteAllBytes(tempImagePath, imageBytes); //Записываем массив байтов в временный файл
                    return tempImagePath; //Возвращаем путь к временному файлу с загруженным изображением
                }
            }
            catch (Exception ex) //Обрабатываем исключение, если произошла ошибка при загрузке изображения
            {
                throw new Exception($"Ошибка при загрузке изображения '{imageUrl}': {ex.Message}"); //Генерируем исключение с сообщением об ошибке
            }
        }


        /// <summary>
        /// LoadImagesAsync - предпарсинговая передача
        /// </summary>
        /// <param name="canvaB"> - канва с парсингвыми изображениями </param>
        /// <returns></returns>
        /// 
        public static async Task LoadImagesAsync(Canvas canvaB)
        {
            try
            {
                var httpClient = new HttpClient(); //Создаем экземпляр HttpClient для выполнения HTTP-запросов
                var html = await httpClient.GetStringAsync("https://undertaleyellow.fandom.com/wiki/Decibat"); //Получаем HTML-код страницы для парсинга
                var htmlDocument = new HtmlDocument(); //Создаем новый объект для работы с HTML-документом
                htmlDocument.LoadHtml(html); //Загружаем HTML-код страницы в объект HtmlDocument
                var imageUrls = new List<string>(); //Создаем список для хранения ссылок на изображения
                var imageNodes = htmlDocument.DocumentNode.SelectNodes("//*[@id=\"mw-content-text\"]/div/aside[1]/section[1]/div[1]/div[5]/figure/a/img"); //Ищем узлы с изображениями на странице
                if (imageNodes != null) //Проверяем, найдены ли узлы с изображениями
                {
                    foreach (var imageNode in imageNodes) //Проходимся по каждому узлу с изображением
                    {
                        string imageUrl = imageNode.Attributes["src"].Value; //Получаем URL изображения из атрибута src
                        imageUrls.Add(imageUrl); //Добавляем URL изображения в список
                    }
                    foreach (var imageUrl in imageUrls) //Проходимся по каждому URL изображения в списке
                    {
                        string localImagePath = await DownloadImageAsync(imageUrl); //Загружаем изображение по URL и получаем путь к локальному временному файлу
                        CreateImageUrl(localImagePath, canvaB, 700, 700, 0, canvaB.Height - 700); //Создаем изображение на панели и добавляем его
                    }
                }
            }
            catch (Exception ex) //Обрабатываем исключение, если произошла ошибка
            {
                MessageBox.Show($"Ошибка при загрузке изображений: {ex.Message}", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error); //Выводим сообщение об ошибке
            }
        }

        /// <summary>
        /// ReadDataFromJson - чтение всех данных с json файла
        /// </summary>
        /// <param name="imagePath"> - путь переменной</param>
        /// <param name="fileName"> - имя файла </param>
        /// <param name="textBlock1"> - текстовый блок 1 </param>
        /// <param name="textBlock2"> - текстовый блок 2 </param>
        /// <param name="canvasA"> - канва 1 </param>
        /// <param name="canvasB"> - канва 2 </param>
        /// c
        public static async Task ReadDataFromJson(string imagePath, string fileName, TextBlock textBlock1, TextBlock textBlock2, Canvas canvasA, Canvas canvasB)
        {
            if (!File.Exists(fileName)) //Проверяем, существует ли файл с заданным именем
            {
                File.WriteAllText(fileName, "{}"); //Если файл не существует, создаем новый пустой файл
                return; //Завершаем выполнение метода
            }

            string json = File.ReadAllText(fileName); //Считываем содержимое файла в формате JSON
            dynamic data = JObject.Parse(json); //Преобразуем JSON-строку в динамический объект

            textBlock1.Text = data.TextBox1Text; //Восстанавливаем текст для TextBlock1 из данных JSON
            textBlock2.Text = data.TextBox2Text; //Восстанавливаем текст для TextBlock2 из данных JSON

            canvasA.Children.Clear(); //Очищаем элементы на CanvasA перед добавлением новых
            canvasB.Children.Clear(); //Очищаем элементы на CanvasB перед добавлением новых

            if (data.Images != null) //Проверяем наличие информации о изображениях в данных JSON
            {
                foreach (var imageData in data.Images) //Итерируемся по каждому элементу в списке изображений
                {
                    double left = (double)imageData.Left; //Получаем координату X (left) из данных JSON
                    double top = (double)imageData.Top; //Получаем координату Y (top) из данных JSON
                    double width = 500; //Задаем ширину изображения (в данном случае постоянное значение)
                    double height = 40; //Задаем высоту изображения (в данном случае постоянное значение)
                    if (imageData.ImagePath != null) //Проверяем, является ли изображение локальным (путь к изображению указан)
                    {
                        string localImagePath = imageData.ImagePath; //Получаем путь к локальному изображению из данных JSON
                        REGDynamicModule.CreateImage(localImagePath, ref canvasA, width, height, left, top); //Создаем изображение на CanvasA
                    }
                    else if (imageData.ImageUrl != null) //Проверяем, является ли изображение удаленным (путь к изображению URL указан)
                    {
                        string imageUrl = imageData.ImageUrl; //Получаем URL удаленного изображения из данных JSON
                        string localImagePath = imageData.LocalImagePath; //Получаем путь к временному файлу с изображением из данных JSON
                        REGDynamicModule.CreateImageUrl(imageUrl, canvasB, width, height, left, top); //Создаем изображение на CanvasB
                    }
                }
            }
        }

        /// <summary>
        /// ReadTextFromJson - метод который считывает текст в файле и записывает их в переменные
        /// </summary>
        /// <param name="fileName"> файловая переменная </param>
        /// <param name="text1st"> первая текстовая переменная </param>
        /// <param name="text2st"> первая текстовая переменная</param>
        /// <returns></returns>
        public static void ReadTextFromJson(string fileName, ref string text1st, ref string text2st)
        {
            text1st = ""; // Инициализируем переменную text1
            text2st = ""; // Инициализируем переменную text2

            if (!File.Exists(fileName))
            {
                File.WriteAllText(fileName, ""); // Создаем пустой файл, если его не существует
            }

            string[] lines = File.ReadAllLines(fileName); // Считываем все строки из файла

            if (lines.Length >= 2)
            {
                text1st = lines[1]; // Присваиваем первую строку переменной text1
                text2st = lines[2]; // Присваиваем вторую строку переменной text2
            }
            else if (lines.Length == 1)
            {
                text1st = lines[1]; // Если есть только одна строка, присваиваем ее обеим переменным
                text2st = lines[1];
            }
            // Если файл пустой или не содержит строк, переменные останутся пустыми
        }

        /// <summary>
        /// RefreshTextBoxDataFromJson - очистка файла
        /// </summary>
        /// <param name="fileName"> - файловая переменная </param>
        /// <param name="textBlock1"> - первый текстблок </param>
        /// <param name="textBlock2"> - второй текстблок </param>
        /// <param name="Canva"> - первая канва (отвечает за красивый вывод текста) </param>
        /// <param name="Canva2"> - вторая канва (отвечает за красивый вывод текста) </param>
        /// c
        public static void RefreshTextBoxDataFromJson(string fileName, ref TextBlock textBlock1, ref TextBlock textBlock2, ref Canvas Canva, ref Canvas Canva2)
        {
            File.WriteAllText(fileName, "{}"); //Сброс файла пользователя

            Canva.Children.Clear(); //Очистка канвы с текстовыми прямогульниками
            Canva2.Children.Clear(); //Очистка канвы с парсинговыми изображениями
            textBlock1.Text = string.Empty; //Очистка текстбокса 1 
            textBlock2.Text = string.Empty; //Очистка текстбокса 2
        }

        /// <summary>
        /// SaveDataToJson - Соохранение истории переписки в Json файл
        /// </summary>
        /// <param name="fileName"> - файловая переменная </param>
        /// <param name="text1"> - первый textbox </param>
        /// <param name="text2"> - второй textbox </param>
        /// <param name="canvasA"> - первый canvas </param>
        /// <param name="canvasB"> - второй canvas </param>
        /// <returns></returns>
        /// c
        //todo хранение в структуре
        public static async Task SaveDataToJson(string fileName, string text1, string text2, Canvas canvasA, Canvas canvasB)
        {
            var data = new //Создаем объект для хранения данных из TextBox'ов и картинок на Canvas
            {
                TextBox1Text = text1, //Сохраняем текст из первого TextBox
                TextBox2Text = text2, //Сохраняем текст из второго TextBox
                Images = new List<dynamic>() //Создаем список для хранения информации о изображениях
            };
            foreach (Image image in canvasA.Children) //Итерируемся по каждому элементу в коллекции изображений на CanvasA
            {
                double left = Canvas.GetLeft(image); //Получаем значение координаты X (left) изображения на CanvasA
                double top = Canvas.GetTop(image); //Получаем значение координаты Y (top) изображения на CanvasA
                string imagePath = REGDynamicModule.GetImagePath(image); //Получаем путь к изображению на CanvasA

                data.Images.Add(new //Добавляем информацию о текущем изображении в список
                {
                    ImagePath = imagePath, //Сохраняем путь к изображению
                    Left = left, //Сохраняем значение координаты X (left) изображения
                    Top = top //Сохраняем значение координаты Y (top) изображения
                });
            }
            foreach (Image image in canvasB.Children) //Итерируемся по каждому элементу в коллекции изображений на CanvasB
            {
                double left = Canvas.GetLeft(image); //Получаем значение координаты X (left) изображения на CanvasB
                double top = Canvas.GetTop(image); //Получаем значение координаты Y (top) изображения на CanvasB
                string imageUrl = ((BitmapImage)image.Source)?.UriSource?.AbsoluteUri; //Получаем URL изображения на CanvasB

                if (!string.IsNullOrEmpty(imageUrl)) //Проверяем, что URL изображения не пустой
                {
                    data.Images.Add(new //Добавляем информацию о текущем изображении в список
                    {
                        ImageUrl = imageUrl, //Сохраняем URL изображения
                        Left = left, //Сохраняем значение координаты X (left) изображения
                        Top = top //Сохраняем значение координаты Y (top) изображения
                    });
                }
                else //Если URL изображения пустой
                {
                    Console.WriteLine("Не удалось получить URL изображения"); //Выводим сообщение об ошибке в консоль
                }
            }
            string json = JsonConvert.SerializeObject(data, Newtonsoft.Json.Formatting.Indented); //Преобразуем объект в формат JSON
            File.WriteAllText(fileName, json); // Записываем JSON в файл
        }

        /// <summary>
        /// m
        /// </summary>
        public static void assertCheck()
        {
            string fileName = "fileName.Json";
            string txtA = "";
            string txtB = "";
            ReadTextFromJson(fileName, ref txtA, ref txtB);

            Debug.Assert(File.Exists(fileName), "File does not exist: " + fileName);
            Debug.Assert(txtA == "  \"TextBox1Text\": \"Привет\\r\\n\\r\\nПока\\r\\n\\r\\n\",");
            Debug.Assert(txtB == "  \"TextBox2Text\": \"\\r\\nПривет\\r\\n\\r\\nБай-бай\\r\\n\",");
            //Тестовый файл с сообщениями, и правильно ли они загрузились? - это и будет являться проверкой
        }








        
    }

}