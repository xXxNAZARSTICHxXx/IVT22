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
using ChatBot;
using System.Diagnostics;




/// <summary>
/// REGResponse - класс на выдаваемые выражения
/// </summary>
public class REGResponse
{

    /// <summary>
    /// REGHello - регулярное выражение принимающее "приветоподобные" выражения
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGHello(string input)
    {
        string REG = "(привет|здравству|здрас)"; // Регулярное выражение "привет"
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) // Проверка на регулярное выражение
        {
            Random random = new Random(); // Генератор случайного числа
            int randomNumber = random.Next(1, 5); // Генерация случайного ответа
            string[] responses = { "Привет", "Здравствуй", "Здравствуйте", "Приветствую" }; // Массив случайных ответов
            string randomResponse = randomNumber > 0 && randomNumber <= responses.Length ? responses[randomNumber - 1] : ""; // Выбор случайного ответа из массива
            return randomResponse; // Возвращаем случайный ответ
        }
        else return ""; // Возвращаем пустую строку
    }

    /// <summary>
    /// REGHowAreYou - регулярное выражение принимающее "как делашные" выражения
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGHowAreYou(string input)
    {
        string REG = @"(Как у тебя дела|Как дела|Как настроение|Как делишки)"; //Регулярные выражения "как дела"
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //Проверка на регулярноре выражение, если оно есть
        {
            Random random = new Random(); //Генератор случайного числа
            int randomNumber = random.Next(1, 7);
            string[] responses = { "У меня все хорошо", "Все путем", "У меня все классно", "У меня все ОК", "Все нормально", "Не скажу :}" }; // Массив случайных ответов
            string randomResponse = randomNumber > 0 && randomNumber <= responses.Length ? responses[randomNumber - 1] : ""; // Выбор случайного ответа из массива
            return randomResponse; // Возвращаем случайный ответ
        }
        else return ""; // Возвращаем пустую строку
    }
    //todo case или массив
    /// <summary>
    /// REGLewd - регулярное выражение принимающее матерные выражения
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGLewd(string input)
    {
        string REG = @"((^|(\b))бля)|(хуй|пизд|ебан|ебат|пидр|пидор|залуп|ебёш|ёбан|ебёт|ёпта|ебет|еби|мудил|мудак|еба|охуе|ахуе|минет|хуя)"; //Регулярные выражения матерных слов
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase))
        {   //todo case или массив
            Random random = new Random(); //Генератор случайного числа
            int randomNumber = random.Next(1, 6); //Генерация случайного ответа
            string[] responses = { "Можно без этого?", "Не матерись, блять", "Не матерись", "Можно без матов", "Фу, как нкультурно" }; // Массив случайных ответов
            string randomResponse = randomNumber > 0 && randomNumber <= responses.Length ? responses[randomNumber - 1] : ""; // Выбор случайного ответа из массива
            return randomResponse; // Возвращаем случайный ответ
        }
        else return "";  //Вернуть пустую строку
    }

    /// <summary>
    /// REGGoodbye - регулярное выражение принимающее "покашные" выражения
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGGoodbye(string input)
    {
        string REG = @"(Пока|До свидания|До скорой встречи|Покеда|Чао|Бай-бай)";  //Регулярные выражения "пока"
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //Проверка на регулярноре выражение, если оно есть
        {
            Random random = new Random(); //Генератор случайного числа
            int randomNumber = random.Next(1, 5); //Генерация случайного ответа
            string[] responses = { "До свидания", "Пока", "До скорой встречи", "Бай-бай" }; // Массив случайных ответов
            string randomResponse = randomNumber > 0 && randomNumber <= responses.Length ? responses[randomNumber - 1] : ""; // Выбор случайного ответа из массива
            return randomResponse; // Возвращаем случайный ответ
        }
        return "";  //Вернуть пустую строку
    }

    /// <summary>
    /// REGImage - регулярное выражение принимающее "картиночные" выражения
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGImage(string input)
    {
        string REG = @"(Карт|Картинка)"; //Регулярные выражения картинок
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //Проверка на регулярноре выражение, если оно есть
        {
            return " "; //То вернуть пробел - НЕ ПУСТУЮ строку
        }
        return ""; //Иначе вернуть пустую строку
    }

    /// <summary>
    /// REGMultiply - регулярное выражение принимающее умножение
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGMultiply(string input)
    {
        string REG = @"(\d+)\s*\*\s*(\d+)"; //Регулярное выражение для поиска операции умножения

        Match match = Regex.Match(input, REG, RegexOptions.IgnoreCase); //Проводм поиск внезависимости от регистра
        if (match.Success) //Если нашлось совпадение
        {
            double num1 = double.Parse(match.Groups[1].Value); //Извлекаем число из соответствующих групп
            double num2 = double.Parse(match.Groups[2].Value); //Извлекаем число из соответствующих групп            
            double result = num1 * num2; //Выполняем операцию умножения
            return $"{num1} * {num2} = {result}"; //Возвращаем результат
        }
        else
        {
            return ""; //Иначе вернуть пустую строку
        }
    }

    /// <summary>
    /// REGPlus - регулярное выражение принимающее сложение
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGPlus(string input)
    {
        string REG = @"(\d+)\s*\+\s*(\d+)"; //Регулярное выражение для поиска операции сложения
        Match match = Regex.Match(input, REG, RegexOptions.IgnoreCase); //Проводм поиск внезависимости от регистра
        if (match.Success) //Если нашлось совпадение
        {
            int num1 = int.Parse(match.Groups[1].Value); //Извлекаем числа из соответствующих групп
            int num2 = int.Parse(match.Groups[2].Value); //Извлекаем числа из соответствующих групп
            int result = num1 + num2; //Выполняем операцию умножения
            return $"{num1} + {num2} = {result}"; //Возвращаем результат
        }
        else
        {
            return ""; //Иначе вернуть пустую строку
        }
    }

    /// <summary>
    /// REGMinus - регулярное выражение принимающее минус
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGMinus(string input)
    {
        string REG = @"(\d+)\s*-\s*(\d+)"; //Регулярное выражение для поиска операции вычитания
        Match match = Regex.Match(input, REG, RegexOptions.IgnoreCase); //Проводм поиск внезависимости от регистра
        if (match.Success) //Если нашлось совпадение
        {
            int num1 = int.Parse(match.Groups[1].Value); //Извлекаем числа из соответствующих групп
            int num2 = int.Parse(match.Groups[2].Value); //Извлекаем числа из соответствующих групп             
            int result = num1 - num2; //Выполняем операцию умножения
            return $"{num1} - {num2} = {result}"; //Возвращаем результат
        }
        else
        {
            return ""; //Иначе вернуть пустую строку
        }
    }

    /// <summary>
    /// REGDivision - регулярное выражение принимающее деление
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGDivision(string input)
    {
        string REG = @"(\d+)\s*/\s*(\d+)"; //Регулярное выражение для поиска операции деления
        Match match = Regex.Match(input, REG, RegexOptions.IgnoreCase); //Проводм поиск внезависимости от регистра
        if (match.Success) //Если нашлось совпадение
        {
            int num1 = int.Parse(match.Groups[1].Value); //Извлекаем числа из соответствующих групп
            int num2 = int.Parse(match.Groups[2].Value); //Извлекаем числа из соответствующих групп
            double result = num1 / num2; //Выполняем операцию умножения
            return $"{num1} / {num2} = {result}"; //Возвращаем результат
        }
        else
        {
            return ""; //Иначе вернуть пустую строку
        }
    }

    /// <summary>
    /// REGTime - регулярное выражение принимающее "времянные" выражения
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGTime(string input)
    {
        string REG = @"(Который час|Сколько время|Скажи время|Время)"; //Регулярное выражение для поиска времени
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //Проверка на регулярноре выражение, если оно есть
        {
            DateTime currentTime = DateTime.Now; //Получаем текущее время
            string formattedTime = currentTime.ToString("HH:mm:ss"); //Форматируем время в строку в удобном формате
            return formattedTime; //Возвращаем форматированное время
        }
        return ""; //Иначе вернуть пустую строку
    }

    /// <summary>
    /// REGData - регулярное выражение принимающее "датные" выражения
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGData(string input)
    {
        string REG = @"(Какое сегодня число|Дата|Сегодняшняя дата)"; //Регулярное выражение для поиска даты
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //Проверка на регулярноре выражение, если оно есть
        {
            DateTime currentDate = DateTime.Today; //Получаем сегодняшнюю дату  
            string formattedDate = currentDate.ToString("dd.MM.yyyy"); //Форматируем дату в строку в удобном формате
            return formattedDate; //Возвращаем форматированную дату
        }
        return ""; //Иначе вернуть пустую строку
    }

    /// <summary>
    /// REGTemperature - регулярное выражение принимающее "температурные" выражения с парсингом температуры
    /// </summary>
    /// <param name="input"> input - ввод выражения </param>
    /// <returns></returns>
    public string REGTemperature(string input)
    {
        string REG = @"(Температура в Чите|Температура воздуха|Температура|x)"; //Регулярное выражение для поиска температуры воздуха в городе Чите
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //Проверка на регулярноре выражение, если оно есть
        {
            string answ = REGDynamicModule.GetCurrentTemperature(); //Парсинг температуры в строку
            if (answ.Contains("&minus;")) //Если там объявлен "&minus;"
            {
                answ = answ.Replace("&minus;", "-"); //Заменить на минус
                return ("в Чите: " + answ); //Вернуть результат температуры воздуха
            }
            return ("в Чите: " + REGDynamicModule.GetCurrentTemperature()); //Вернуть результат температуры воздуха
        }
        return ""; //Иначе вернуть пустую строку
    }

    public string REGCalc(string input)
    {
        string REG = @"(Калькулятор|Калк)"; //Регулярное выражение для поиска температуры воздуха в городе Чите
        if (Regex.IsMatch(input, REG, RegexOptions.IgnoreCase)) //Проверка на регулярноре выражение, если оно есть
        {
            return ("Открываю..."); //Вернуть результат температуры воздуха
        }
        return ""; //Иначе вернуть пустую строку
    }

}