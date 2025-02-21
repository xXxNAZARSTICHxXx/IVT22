

//Выполнил Стич Назар ИВТ-22
///Список всех функций с модуля ArrayMODULE.cpp
#include <string>		///Подключение библиотеки string, для работы с путем хранения файла
using namespace std;	///Подключение пространства std, чтобы сократить код

///Собственное пространство имен ArrayFuncs - функций массива
namespace ArrayFuncs{
///Функция заполнения массива СЛУЧАЙНЫМИ числами
///n - количество элементов в массиве; a - максимальный диапазон; b - минимальный диапазон; massive - переменная массива; i - переменная прокрутки цикла
template <typename T>							//создание шаблона T-integer/float
void FillArrayRandom(T a, T b, vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {               //цикл прохода по массиву
        arr[i] = 1.0 * rand() / RAND_MAX * (b - a) + a;     //присвоение случайных чисел в собственных указаных диапазонах A и B //RAND_MAX - константа - максимальное значени rand
    }
}	

///Функция заполнения массива СВОИМИ числами - руками
///arr - массив vector;	
template <typename M>                           //создание шаблона M-integer/float
void FillArrayWithHands(vector<M>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {               //цикл прохода по массиву
        cin >> arr[i];                                      //ввод числа в массив
    }
}

///Функция для вывода массива		
///arr - массив vector;		
template <typename C>				
void ShowArrayOfNumbers(const vector<C>& arr) {             //создание шаблона C-integer/float
    for (const float& value : arr) {                        //цикл прохода по массиву
        cout << value << " ";                               //простановка пробелов между числами
    }
}	

///Функция подсчета суммы всех элементов массива	
///arr - массив vector;					
template <typename D>   	                                //создание шаблона D-integer/float
float SumArray(const vector<D>& arr) {                               
    float sum = 0;                                          //объявление локальной переменной sum - сумматора
    for (const float& value : arr) {                        //цикл прохода по массиву
        sum = sum + value;                                  //суммирование чисел массива
    }
    return sum;                                             //возвращаем сумму всех чисел
}


///Функция проверка на дурака (feat. Владимир Александрович Соловьев)							
int input(); 																	

///Функция записи числа типа float в бинарный файл
///filename - название бинарного файла; arr - массив vector;
template <typename A>                                       //создание шаблона D-integer/float
void writeBinaryFile(const string& filename, const vector<A>& arr) {
    ofstream out(filename, ios::binary | ios::out);                                     //открываем бинарный файл на запись
    if (!out) {                                                                         //если данный файл не открыт...
        throw runtime_error("Oops... Something went wrong, file doesn't open");         //генерируем исключение
    }
    out.write(reinterpret_cast<const char*>(arr.data()), sizeof(A) * arr.size());   //записываем все числа в файл
    out.close();
}

///Функция чтения данных из бинарного файла
///filename - название бинарного файла; n - количество элементов в массиве
vector<float> readBinaryFile(const string& filename, size_t &n);

///Функция чистки бинарного файла
///filename - название бинарного файла;
void clearBinaryFile(const string& filename);
}
