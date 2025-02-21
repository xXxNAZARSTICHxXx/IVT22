//Выполнил Стич Назар ИВТ-22
#include <iostream>                 //Подключение базовой библиотеки для вывода в командную строку строк
#include <time.h>                   //Подключение библиотеки time для будущего рандомайзера
#include <fstream>                  //Подключение библиотеки для работы с файлами
#include <string>                   //Подключение библиотеки string, для работы с путем хранения файла
#include <vector>                           //Подключение vector для работы с массивом

using namespace std;                //Подключение пространства std, чтобы сократить код

///Модуль для работы программы (Task136a.cpp) задания 136а

///Собственное пространство имен ArrayFuncs - функций массива
namespace ArrayFuncs{

///Функция заполнения массива СЛУЧАЙНЫМИ числами
///n - количество элементов в массиве; a - максимальный диапазон; b - минимальный диапазон; massive - переменная массива; i - переменная прокрутки цикла
void FillArrayRandom(int a, int b, vector<float>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {               //цикл прохода по массиву
        arr[i] = 1.0 * rand() / RAND_MAX * (b - a) + a;     //присвоение случайных чисел в собственных указаных диапазонах A и B //RAND_MAX - константа - максимальное значени rand
    }
}

///Функция заполнения массива СВОИМИ числами - руками
///arr - массив vector;
void FillArrayWithHands(vector<float>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {               //цикл прохода по массиву
        cin >> arr[i];                                      //ввод числа в массив
    }
}

///Функция для вывода массива       
///arr - массив vector;
void ShowArrayOfNumbers(const vector<float>& arr) {
    for (const float& value : arr) {                        //цикл прохода по массиву
        cout << value << " ";                               //простановка пробелов между числами
    }
}

///Функция подсчета суммы всех элементов массива    
///arr - массив vector;
float SumArray(const vector<float>& arr) {                               
    float sum = 0;                                          //объявление локальной переменной sum - сумматора
    for (const float& value : arr) {                        //цикл прохода по массиву
        sum = sum + value;                                  //суммирование чисел массива
    }
    return sum;                                             //возвращаем сумму всех чисел
}

///Функция проверка на дурака (feat. Владимир Александрович Соловьев)
///g - переменная ввода числа 1 или 2
int input(){
    int g;
    do{                               
    cin >> g;                           //ввод ответа на вопрос
    }while(g<1||g>2);                   //проверка, что введено либо 1, либо 2
    return g;                           //подтверженный ответ
}

///Функция записи числа типа float в бинарный файл
///filename - название бинарного файла; arr - массив vector;
void writeBinaryFile(const string& filename, const vector<float>& arr) {
    ofstream out(filename, ios::binary | ios::out);                                     //открываем бинарный файл на запись
    if (!out) {                                                                         //если данный файл не открыт...
        throw runtime_error("Oops... Something went wrong, file doesn't open");         //генерируем исключение
    }
    out.write(reinterpret_cast<const char*>(arr.data()), sizeof(float) * arr.size());   //записываем все числа в файл
    out.close();
}

///Функция чтения данных из бинарного файла
///filename - название бинарного файла; n - количество элементов в массиве
vector<float> readBinaryFile(const string& filename, size_t &n) {
    ifstream in(filename, ios::binary | ios::ate);                                  //открываем бинарный файл на чтение
    if (!in) {                                                                      //если данный файл не открыт...
        throw runtime_error("Oops... Something went wrong, file doesn't open");     //генерируем исключение
    }
    size_t fileSize = in.tellg();                                                   //обращаемся к информации считывая ее            
    size_t arraySize = fileSize / sizeof(float);                                    //считываем кол-во переменных
    in.seekg(0, ios::beg);                                                          //возвращаемя к началу файла
    
    vector<float> arr(arraySize);                                                   //создание массива    
    in.read(reinterpret_cast<char*>(arr.data()), fileSize);                         //В чтении файла(in.read) - происходит преобразование типов "кастинг", для использования метода необходимо, чтобы первый аргумент был char
    in.close();                                                                     //закрываем файл
    return arr;                                                                     //возврат массива
}

///Функция чистки бинарного файла
///filename - название бинарного файла;
void clearBinaryFile(const string& filename) {                                      
    ofstream out(filename, ios::binary | ios::trunc);                               //открываем бинарный файл на запись
    if (!out) {                                                                     //если данный файл не открыт...
        throw runtime_error("Oops... Something went wrong, file doesn't open");     //генерируем исключение
    }
    out.close();                                                                    //закрываем файл
} 

}