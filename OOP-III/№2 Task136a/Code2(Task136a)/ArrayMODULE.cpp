//Выполнил Стич Назар ИВТ-22
#include <iostream>                 //Подключение базовой библиотеки для вывода в командную строку строк
#include <time.h>                   //Подключение библиотеки time для будущего рандомайзера
#include <fstream>                  //Подключение библиотеки для работы с файлами
#include <string>                   //Подключение библиотеки string, для работы с путем хранения файла

using namespace std;                //Подключение пространства std, чтобы сократить код

///Модуль для работы программы (Task136a.cpp) задания 136а

///Собственное пространство имен ArrayFuncs - функций массива
namespace ArrayFuncs{
///Функция заполнения массива СЛУЧАЙНЫМИ числами
///n - количество элементов в массиве; a - максимальный диапазон; b - минимальный диапазон; massive - переменная массива; i - переменная прокрутки цикла
void FillArrayRandom(int n, int a, int b, float* massive)
{

    for (int i = 0; i < n; i++) {   //цикл прохода по массиву
        massive[i] = 1.0 * rand() / RAND_MAX * (b - a) + a;     //присвоение случайных чисел в собственных указаных диапазонах A и B //RAND_MAX - константа - максимальное значени rand

    }
}

///Функция заполнения массива СВОИМИ числами - руками ; 
///n - количество элементов в массиве; massive - переменная массива; i - переменная прокрутки цикла
void FillArrayWithHands(int n, float* massive)
{
    for (int i = 0; i < n; i++) {   //цикл прохода по массиву
        cin >> massive[i];              //ввод числа в массив
    }
}

///Функция для вывода массива
///n - количество элементов в массиве; massive - переменная массива; i - переменная прокрутки цикла
void ShowArrayOfNumbers(int n, float* massive)
{
    for (int i = 0; i < n; i++) {   //цикл прохода по массиву
        cout << massive[i] << " ";      //простановка пробелов между числами
    }
}

///Функция подсчета суммы всех элементов массива
///n - количество элементов в массиве; massive - переменная массива; sum - переменная, хранящая сумму всех чисел из массива; i - переменная прокрутки цикла
float SumArray(int n, float* massive)                       
{   
    float sum = 0;                  //объявление локальной переменной sum - сумматора
    for (int i = 0; i < n; i++) {   //цикл прохода по массиву
        sum=sum+massive[i];             //суммирование чисел массива
    }
    return sum;
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
///filename - название бинарного файла; massive - переменная массива; n - количество элементов в массиве
void writeBinaryFile(const string& filename, float* massive, size_t n) {
    ofstream out(filename, ios::binary | ios::out);                         //открываем бинарный файл на запись
    if (!out) {                                                             //если данный файл не открыт...
        throw runtime_error("Oops... Something went wrong, file dosen't open");                                              //генерируем исключение
    }

    out.write(static_cast<char*>(static_cast<void*>(massive)), sizeof(float) * n);   //записываем все числа в файл
    out.close();                                                            //закрываем файл
}

///Функция чтения данных из бинарного файла
///filename - название бинарного файла; n - количество элементов в массиве
float* readBinaryFile(const string& filename, size_t &n) {
    ifstream in(filename, ios::binary | ios::ate);          //открываем бинарный файл на чтение
    if (!in) {                                                             //если данный файл не открыт...
        throw runtime_error("Oops... Something went wrong, file dosen't open");              //генерируем исключение
    }
    size_t fileSize = in.tellg();                           //обращаемся к информации считывая ее
    n = fileSize / sizeof(float);                           //считываем кол-во переменных
    in.seekg(0, ios::beg);                                  //возвращаемя к началу файла

    float* massive = new float[n];                          //создание массива
    in.read(static_cast<char*>(static_cast<void*>(massive)), fileSize);         //В чтении файла(in.read) - происходит двойное преобразование типов "кастинг", для использования метода необходимо, чтобы первый аргумент был char
    in.close();                                             //закрываем файл

    return massive;                                         //возврат массива
}

///Функция чистки бинарного файла
///filename - название бинарного файла;
void clearBinaryFile(const string& filename) {              
    ofstream out(filename, ios::binary | ios::trunc);       //открываем бинарный файл на запись
    if (!out) {                                                             //если данный файл не открыт...
        throw runtime_error("Oops... Something went wrong, file dosen't open");               //генерируем исключение
    }

    out.close();                                            //закрываем файл
    return;                                                 //вылетаем из функции
}   
}