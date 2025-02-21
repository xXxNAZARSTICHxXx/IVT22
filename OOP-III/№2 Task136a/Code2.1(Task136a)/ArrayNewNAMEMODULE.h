

//Выполнил Стич Назар ИВТ-22
///Список всех функций с модуля ArrayMODULE.cpp
#include <string>		///Подключение библиотеки string, для работы с путем хранения файла
using namespace std;	///Подключение пространства std, чтобы сократить код

///Собственное пространство имен ArrayFuncs - функций массива
namespace ArrayNewFuncs{
///Функция заполнения массива СЛУЧАЙНЫМИ числами
///n - количество элементов в массиве; a - максимальный диапазон; b - минимальный диапазон; massive - переменная массива;
void FillArrayRandom(int n, int a, int b, float* massive);	

///Функция заполнения массива СВОИМИ числами - руками
///n - количество элементов в массиве; massive - переменная массива;	
void FillArrayWithHands(int n, float* massive);

///Функция для вывода массива		
///n - количество элементов в массиве; massive - переменная массива;						
void ShowArrayOfNumbers(int n, float* massive);	

///Функция подсчета суммы всех элементов массива	
///n - количество элементов в массиве; massive - переменная массива;						
float SumArray(int n, float* massive);	

///Функция проверка на дурака (feat. Владимир Александрович Соловьев)							
int input(); 																	

///Функция записи числа типа float в бинарный файл
///filename - название бинарного файла; massive - переменная массива; n - количество элементов в массиве
void writeBinaryFile(const string& filename, float* massive, size_t n);

///Функция чтения данных из бинарного файла
///filename - название бинарного файла; n - количество элементов в массиве
float* readBinaryFile(const string& filename, size_t &n);

///Функция чистки бинарного файла
///filename - название бинарного файла;
void clearBinaryFile(const string& filename);
}
