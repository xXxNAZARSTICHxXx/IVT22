#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

//TODO Комментарии - аргументирование


/// <summary>
/// Приводит строку к нижнему регистру
/// </summary>
/// <param name="str">Строка, которую нужно преобразовать</param>
/// <returns>Строка, приведённая к нижнему регистру</returns>
std::string toLowerCase(const std::string& str) {
    std::string result = str; // Копируем исходную строку в переменную result
    //TODO?? Комментирование+ Начало иттератора
    //result.begin() - Начало текста
    //result.end() - Конец теста
    //result.begin() - Начало строки куда будет записываться
    //::tolower - по нижнему регистру
    std::transform(result.begin(), result.end(), result.begin(), ::tolower); // Преобразуем каждый символ строки в нижний регистр 
    return result; // Возвращаем преобразованную строку
}

/// <summary>
/// Обрабатывает текст из файла, подсчитывая частоту каждого слова
/// </summary>
/// <param name="filename">Имя файла, содержащего текст</param>
/// <returns>Словарь с частотой встречаемости слов</returns>
std::map<std::string, int> processFile(const std::string& filename) {
    std::ifstream file(filename); // Открываем файл для чтения
    std::map<std::string, int> wordCount; // Создаём словарь для подсчёта частоты слов
    std::string word; // Переменная для хранения текущего слова
    //TODO?? Комментирование+
    //Это поток, который считывает все слова подряд, если там будет пробел, то начнется новое слово
    while (file >> word) { // Читаем файл слово за словом
        word = toLowerCase(word); // Приводим слово к нижнему регистру
        wordCount[word]++; // Увеличиваем счётчик частоты для данного слова
    }

    return wordCount; // Возвращаем словарь с частотой слов
}

/// <summary>
/// Применяет закон Ципфа, сортируя слова по частоте их использования
/// </summary>
/// <param name="wordCount">Словарь с частотой встречаемости слов</param>
/// <returns>Вектор пар "слово - частота", отсортированный по убыванию частоты</returns>
std::vector<std::pair<std::string, int>> applyZipfLaw(const std::map<std::string, int>& wordCount) {
    std::vector<std::pair<std::string, int>> sortedWords(wordCount.begin(), wordCount.end()); // Копируем содержимое словаря в вектор пар
    //TODO?? Комментирование+ (С парами фокус уточнить)
    std::sort(sortedWords.begin(), sortedWords.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second; // Сортируем пары по убыванию частоты
        });
        
    return sortedWords; // Возвращаем отсортированный вектор
}

/// <summary>
/// Сохраняет результаты в файл в формате "частота слово"
/// </summary>
/// <param name="sortedWords">Вектор пар "слово - частота", отсортированный по убыванию частоты</param>
/// <param name="outputFile">Имя файла, куда будут сохранены результаты</param>
void saveToFile(const std::vector<std::pair<std::string, int>>& sortedWords, const std::string& outputFile) {
    std::ofstream outFile(outputFile); // Открываем файл для записи
    for (const auto& pair : sortedWords) { // Проходим по всем парам вектора
        outFile << pair.second << "\t" << pair.first << "\n"; // Записываем частоту и слово в файл
    }
}

/// <summary>
/// Главная функция программы, выполняющая обработку текстового файла, сортировку слов по частоте и сохранение результатов
/// </summary>
/// <returns>0, если программа завершилась успешно, или 1, если произошла ошибка</returns>
int main() {
    setlocale(LC_ALL, "russian"); // Устанавливаем локаль для поддержки русского языка

    // Запрашиваем у пользователя название файла
    std::string inputFilename; // Переменная для имени файла
    std::cout << "Введите имя файла (без расширения): "; // Сообщение для пользователя
    std::cin >> inputFilename; // Читаем имя файла с клавиатуры

    // Формируем полное имя файла
    std::string inputFile = inputFilename + ".txt"; // Добавляем расширение .txt к имени файла

    // Открываем файл
    std::ifstream file(inputFile); // Пробуем открыть файл для проверки существования
    if (!file) { // Если файл не удалось открыть
        std::cerr << "Не удалось открыть файл: " << inputFile << std::endl; // Сообщаем об ошибке
        return 1; // Завершаем программу с кодом ошибки
    }

    // Обработка файла
    std::map<std::string, int> wordCount = processFile(inputFile); // Подсчитываем частоту слов в файле

    // Применение закона Ципфа (сортировка по частоте)
    std::vector<std::pair<std::string, int>> sortedWords = applyZipfLaw(wordCount); // Сортируем слова по частоте

    // Формируем имя выходного файла
    std::string outputFile = "CsiphfA_" + inputFilename + ".txt"; // Формируем имя выходного файла с префиксом

    // Сохраняем результаты в новый файл
    saveToFile(sortedWords, outputFile); // Сохраняем отсортированные данные в файл
    std::cout << "Результаты сохранены в файл: " << outputFile << std::endl; // Сообщаем об успешном завершении

    return 0; // Завершаем выполнение программы
}
