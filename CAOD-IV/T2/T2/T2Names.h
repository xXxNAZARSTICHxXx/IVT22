#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <clocale> 
using namespace std;

// Функция вывода массива на экран
//n - размер массива; arr - массив;
void show_array(size_t n, int arr[]){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
// Функция создание массива м заполнения его случайными числами
//n - размер массива; arr - массив, min - минимальное max - максимальное значение;
void filling_array(size_t n, int min, int max, int arr[]) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

// Функция ввода размерности массива
int array_size() {
	int n;
	cout << "Введите размерность массива: ";
	cin >> n;
	return n;
}

//Функция ввода диапазона случайных чисел
//min - минимальный диапазон случайных чисел; max - максимальный диапазон случайных чисел ;
void random_diaposon(int& min, int& max){
	cout << "Введите диапазон случайных чисел для заполнения массива MIN, MAX: ";
	cin >> min;
	cin >> max;
}
// Функция сохранения массива в файл
//n - размер массива; arr - массив; Название файла - constant переменная fname
void save_in_file(int n, int arr[], const string& filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		throw runtime_error("Ошибка открытия файла для записи");
	}

	for (int i = 0; i < n; i++) {
		if (i % 21 == 20) {
			outfile << "\n";
		}
		outfile << arr[i] << " ";
	}
	outfile.close();
	cout << "\nМассив успешно записан в файл" << endl;
}

// Функция для определения того, превышает ли количество элементов, больших среднего; количество элементов, меньших среднего, или наоборот
//arr - массив, n - размер массива, average - серединное число
int compareCounts(int* arr, size_t n, double average) {
    int aboveCount = 0;                                                         //Переменная для хранения кол-ва чисел превышающих среднее число
    int belowCount = 0;                                                         //Переменная для хранения кол-ва чисел не превышающих среднее число
    int simmilarCount = 0;
    int m = n / 2;
    for (size_t i = 0; i < n; i++) {                                               //Подсчет сравнений
        if (arr[i] > average) {
            aboveCount++;
        }
        else if (arr[i] < average) {
            belowCount++;
        }
        if (arr[1] == arr[i]) {
            simmilarCount++;
        }
    }

    if (simmilarCount == n){                                                                         //Создание вывода
        return 4;
    }
    else if (aboveCount < belowCount) {
        return 2;
    }
    else if (aboveCount == belowCount) {
        return 3;
    }
    if (aboveCount > belowCount) {
        return 1;
    }

}

//Функция, которая принимает все параметры для создания отчета
//arr - массив, n - размер массива, average - среднее число, filrname - размер файла, answ - результат отчета функции проверки на условие задачи
void answerReport(int* arr, size_t n, double average, const string& filename, int answ) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw runtime_error("Unable to open output file!");                     // Бросаем исключение в случае ошибки открытия файла
    }
    if (answ == 1) {
        outFile << ">>> Число элементов, превышающих среднее, больше числа элементов, меньших среднего" << endl;
        outFile << ">>> Серединное число: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("Ошибка открытия файла для записи");
        }
        show_array(n, arr);
    }
    else if (answ == 2) {
        outFile << ">>> Число элементов, превышающих среднее, меньше числа элементов, меньших среднего" << endl;
        outFile << ">>> Серединное число: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("Ошибка открытия файла для записи");
        }
        show_array(n, arr);
    }
    else if (answ == 3) {
        outFile << ">>> Число элементов, превышающих среднее, равно числу элементов, меньших среднего" << endl;
        outFile << ">>> Серединное число: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("Ошибка открытия файла для записи");
        }
        show_array(n, arr);
    }
    else if (answ == 4) {
        outFile << ">>> Все элементы в массиве равны" << endl;
        outFile << ">>> Серединное число: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("Ошибка открытия файла для записи");
        }
        show_array(n, arr);
    }
    outFile.close();
}

//Добавить условие, если оно будет равное {2 2 2 2 2 2 2 2 2 2}%%%
//Функция, которая проверяет функции через assert
void assertcheck(){
    int answ = 0;
    int n = 10;
    int arr2[] = {1,2,3,4,5,6,7,8,9,9}; //average = 5.4
    float sum = 0;                                                              //Переменная для подсчета суммы для нахождения среднего числа
    for (size_t i = 0; i < n; i++) {                                               //Вычисление среднего значения
        sum += arr2[i];
    }
    float average = sum / n;
    assert (compareCounts(arr2, n, average) == 3);
    int arr3[] = {1,2,3,4,7,6,7,8,7,9};
    assert(compareCounts(arr3, n, average) == 1);
    int arr4[] = {4,2,5,4,4,4,7,8,7,9};
    assert(compareCounts(arr4, n, average) == 2);
    int arr5[] = {2,2,2,2,2,2,2,2,2,2};
    assert(compareCounts(arr5, n, average) == 4);
}

