

//Выполнил Стич Назар ИВТ-22
///Список всех функций с модуля ArrayMODULE.cpp
#include <string>		///Подключение библиотеки string, для работы с путем хранения файла
using namespace std;	///Подключение пространства std, чтобы сократить код

///Собственное пространство имен ArrayFuncs - функций массива
namespace ArrayFuncs{
///Функция заполнения массива СЛУЧАЙНЫМИ числами
///n - количество элементов в массиве; a - максимальный диапазон; b - минимальный диапазон; massive - переменная массива;
void FillArrayRandom(int a, int b, vector<float>& arr);	

///Функция заполнения массива СВОИМИ числами - руками
///arr - массив vector;	
void FillArrayWithHands(vector<float>& arr);

///Функция для вывода массива		
///arr - массив vector;						
void ShowArrayOfNumbers(const vector<float>& arr);	

///Функция подсчета суммы всех элементов массива	
///arr - массив vector;						
float SumArray(const vector<float>& arr) ;	

///Функция проверка на дурака (feat. Владимир Александрович Соловьев)							
int input(); 																	

///Функция записи числа типа float в бинарный файл
///filename - название бинарного файла; arr - массив vector;
void writeBinaryFile(const string& filename, const vector<float>& arr);

///Функция чтения данных из бинарного файла
///filename - название бинарного файла; n - количество элементов в массиве
vector<float> readBinaryFile(const string& filename, size_t &n);

///Функция чистки бинарного файла
///filename - название бинарного файла;
void clearBinaryFile(const string& filename);
}
