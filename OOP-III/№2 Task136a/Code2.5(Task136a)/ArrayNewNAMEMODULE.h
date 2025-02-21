

//Выполнил Стич Назар ИВТ-22
///Список всех функций с модуля ArrayMODULE.cpp
#include <string>		///Подключение библиотеки string, для работы с путем хранения файла
using namespace std;	///Подключение пространства std, чтобы сократить код

///Собственное пространство имен ArrayFuncs - функций массива
namespace ArrayNewFuncs{
///Функция подсчета суммы всех элементов массива	
///n - количество элементов в массиве; massive - переменная массива;						
float SumArray(int n, float* massive);	
void TestArray1();	//Текстовый массив 1
void TestArray2();	//Текстовый массив 2
void TestArray3();	//Текстовый массив 3
void TestArray4();	//Текстовый массив 4
void TestArray5();	//Текстовый массив 5
void TestArray6();	//Текстовый массив 6
void TestArray7();	//Текстовый массив 7
void TestArray8();	//Текстовый массив 8
void TestArray9();	//Текстовый массив 9
void TestArray10(); //Текстовый массив 10
void RunAllTests(); // Проверка всех assert функции через одну функцию
}
