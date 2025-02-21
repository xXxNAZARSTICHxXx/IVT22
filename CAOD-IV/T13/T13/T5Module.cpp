#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <clocale> 
#include <functional> 
#include <chrono>
#define T5NAMES_H

using namespace std;


//template <typename A> требуется для того, чтобы запускать функцию в другом режиме

//todo size_t описать везде, где используется

// Функция поиска числа в массиве
//n - размер массива; arr - массив; //x - число, которое сравнивается с элементом массива
//size_t - это беззнаковый целый тип для представления размера объекта в памяти
//Если числа нету вернется -1
template <typename A>
long long seek_run(size_t n, A arr[], A x) {
	for (size_t i = 0; i < n; i++)
		if (arr[i] == x) {
			//cout << "\nПервое число " << x << " располагается на " << i << " позиции в массиве" << endl;
			return i;
			break;
		}	
	return -1;
}
//todo: Индекс массива

//Предикат для поиска значения
//sh_num - искомое значение
//num - значение массива
bool is_more_not_less(int sh_num, int num) {
	return sh_num > num;
}



// Функция сортировки вставками
//n - размер массива; arr - массив;
//size_t - это беззнаковый целый тип для представления размера объекта в памяти
//Сортирует по возрастанию
template <typename A>
void insertion_sort(size_t n, A arr[]) {
	for (size_t i = 1; i < n; i++) {
		A key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Функция сортировки встряхиванирем
//n - размер массива; arr - массив;
//size_t - это беззнаковый целый тип для представления размера объекта в памяти
//Сортирует по возрастанию
template <typename A>
void cocktail_sort(size_t n, A arr[]) {
	bool swapped = true;
	int start = 0;
	int end = n - 1;
	while (swapped) {
		swapped = false;
		for (int i = start; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) break; 
		swapped = false;
		end--;
		for (int i = end - 1; i >= start; i--) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		start++;
	}
}

//Функция вывода массива в ТЕКСТОВЫЙ файл 
//n - размер массива; arr - массив; filename - имя файла
//size_t - это беззнаковый целый тип для представления размера объекта в памяти
template <typename A>
void save_in_file(size_t n, A arr[], const string& filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		throw runtime_error("Ошибка открытия файла для записи");
	}

	for (size_t i = 0; i < n; i++) {
		if (i % 21 == 20) {
			outfile << "\n";
		}
		outfile << arr[i] << " ";
	}
	outfile.close();
	cout << "\nМассив успешно записан в файл" << endl;
}

//Функция вывода массива БИНАРНЫЙ файл 
//n - размер массива; arr - массив; filename - имя файла
//size_t - это беззнаковый целый тип для представления размера объекта в памяти
template <typename A>
void save_in_binary_file(size_t n, A arr[], const string& filename) {
	ofstream outfile(filename, ios::binary);
	if (!outfile.is_open()) {
		throw runtime_error("Ошибка открытия файла для записи");
	}

	outfile.write(reinterpret_cast<char*>(&n), sizeof(n)); 

	outfile.write(reinterpret_cast<char*>(arr), n * sizeof(A));

	outfile.close();
	cout << "\nМассив успешно записан в бинарный файл" << endl;
}


// Функция сортировки через библиотеку C++
//n - размер массива; arr - массив;
//size_t - это беззнаковый целый тип для представления размера объекта в памяти
template <typename A>
void algoritm_sort_array(size_t n, A arr[]) {
	sort(arr, arr + n);
}

// Функция сортировки пузырьком
//n - размер массива; arr - массив;
//size_t - это беззнаковый целый тип для представления размера объекта в памяти
template <typename A>
void bubble_sort(size_t n, A arr[]) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// Функция вывода массива на экран (НЕ ИСПОЛЬЗУЕТСЯ)
//n - размер массива; arr - массив;
template <typename A>
void show_array(int n, A arr[]) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

// Функция создание массива м заполнения его случайными числами
//n - размер массива; arr - массив; //min - минимальный диапазон случайных чисел; max - максимальный диапазон случайных чисел;
//size_t - это беззнаковый целый тип для представления размера объекта в памяти
template <typename A>
float filling_array(size_t n, A min, A max, A arr[]) {
	for (size_t i = 0; i < n; i++) {
		arr[i] = 1.0 * rand() / RAND_MAX * (max - min) + min;
	}
	return *arr;
}

template <typename A>
float randomX(A min, A max) {
	float randX = 1.0 * rand() / RAND_MAX * (max - min) + min;
	return randX;
}
// Функция ввода размерности массива (НЕ ИСПОЛЬЗУЕТСЯ ИЗ-ЗА АРГУМЕНТОВ)
int array_size() {
	int n;
	cout << "Введите размерность массива: ";
	cin >> n;
	return n;
}

// Функция ввода диапазона случайных чисел (НЕ ИСПОЛЬЗУЕТСЯ ИЗ-ЗА АРГУМЕНТОВ)
//min - минимальный диапазон случайных чисел; max - максимальный диапазон случайных чисел ;
void random_diaposon(int& min, int& max) {
	cout << "Введите диапазон случайных чисел для заполнения массива MIN, MAX: ";
	cin >> min;
	cin >> max;
}

//Перегруженный оператор сортировки - тестирующий массив по убыванию
//n - размер массива; arr - массив;
//size_t - это беззнаковый целый тип для представления размера объекта в памяти
template <typename A>
bool is_sorted_less_to_more(size_t n, A arr[]) {
	for (size_t i = 0; i > n - 1; i++) {
		if (arr[i] < arr[i + 1]) {
			return false;
		}
	}
	return true;
}

//Перегруженный оператор сортировки - тестирующий массив по возрастанию
//n - размер массива; arr - массив;
//size_t - это беззнаковый целый тип для представления размера объекта в памяти
template <typename A>
bool is_sorted_more_to_less(size_t n, A arr[]) {
	for (size_t i = 0; i > n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

//Бинарный поиск числа в ОТСОРТИРОВАННОМ массиве
//arr - массив, x - число, n - размер массива
//WARNING: работает поиск ТОЛЬКО ПРИ ОТСОРТИРОВАННОМ МАССИВЕ
//Если число не найдено то -1 вернется
//todo: long/long вместо size_t
template <typename A>
long long binary_search(A arr[], size_t n, A x) {
	size_t left = 0;
	size_t right = n - 1;

	while (left <= right) {
		size_t mid = left + (right - left) / 2;
		if (arr[mid] == x) {
			cout << "\nЧисло " << x << " располагается на " << mid << " позиции в массиве" << endl;
			return mid; // Если найдено совпадение
		}
		if (arr[mid] < x) {
			left = mid + 1;  // Если искомое число находится в правой половине
		}
		else {
			right = mid - 1;  // Если искомое число находится в левой половине
		}
	}
	return -1; // Если искомое число не найдено
}

//Интерполяционный поиск числа в ОТСОРТИРОВАННОМ массиве
//arr - массив, n - размер массива, x - число
// Если число не найдено вернется -1
//WARNING: работает поиск ТОЛЬКО ПРИ ОТСОРТИРОВАННОМ МАССИВЕ
template <typename A>
long long interpolation_search(A arr[], size_t n, A x) {
	size_t low = 0;
	size_t high = n - 1;
	while (low <= high && x >= arr[low] && x <= arr[high]) {
		// Используем формулу интерполяции, чтобы предположить близкое местоположение элемента
		size_t pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);

		if (arr[pos] == x) {
			cout << "\nЧисло " << x << " располагается на " << pos << " позиции в массиве" << endl;
			return pos;
		}

		if (arr[pos] < x) {
			low = pos + 1;  //Если искомое число находится в правой половине
		}
		else {
			high = pos - 1; //Если искомое число находится в левой половине
		}
	}
	return -1;
}

// Последовательный поиск элемента по предикату func в массиве arr размера size (возвращает -1 если элемента нет в массиве)
// Принимает в func функции, принимающие элементы того же типа, что и массив, которые возвращают логическое значение
template<typename T>
long long int sequence_predicat_search(T* arr, size_t size, const function<bool(T&, T&)>& func, T arg)
{
	for (size_t i = 0; i < size; i++)
		if (func(arr[i], arg))
			return i;                // Если элемент найден, то возвращаем индекс
	return -1;                    // Если элемент не найден, возвращаем -1
}

//merge - Функция слияния двух отсортированных массивов
//arr - массив слияния, left - левая половина массива, leftsize - размер левой части массива
//right - правая половина массива, rightsize - размер правой части массива
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {

	//Копирование отсортированных массивов во временные массивы
	int* tempLeft = new int[leftSize];
	int* tempRight = new int[rightSize];
	memcpy(tempLeft, left, leftSize * sizeof(int));
	memcpy(tempRight, right, rightSize * sizeof(int));

	int i = 0, j = 0, k = 0;

	//Слияние двух временных массивов в один
	while (i < leftSize && j < rightSize) {
		if (tempLeft[i] <= tempRight[j]) {
			arr[k++] = tempLeft[i++];
		}
		else {
			arr[k++] = tempRight[j++];
		}
	}

	//Добавление оставшихся элементов из временного левого массива
	while (i < leftSize) {
		arr[k++] = tempLeft[i++];
	}

	//Добавление оставшихся элементов из временного правого массива
	while (j < rightSize) {
		arr[k++] = tempRight[j++];
	}
	delete[] left;
	delete[] right;
}

//mergeSort - Функция сортировки слиянием
//arr - массив, size - размер массива
void mergeSort(int arr[], int size) {
	if (size < 2) {
		return;
	}

	int mid = size / 2;
	int* left = new int[mid];
	int* right = new int[size - mid];

	//Заполнение левого и правого подмассивов
	memcpy(left, arr, mid * sizeof(int));
	memcpy(right, arr + mid, (size - mid) * sizeof(int));

	//Рекурсивная сортировка обеих половин
	mergeSort(left, mid);
	mergeSort(right, size - mid);

	//Слияние отсортированных половин
	merge(arr, left, mid, right, size - mid);
}

//partition - функция переборки
// //todo случайный элемент
//arr - массив; low - индекс низжего элемента; high - индекс высшего элемента
template <typename A>
int partition(A arr[], A low, A high) {
	int pivot = arr[high];  // Выбираем последний элемент в качестве опорного
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

//quickSort - функция быстрой сортировки
//arr - массив; low - индекс низжего элемента; high - индекс высшего элемента
template <typename A>
void quickSort(A arr[], A low, A high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//Функция сортировки по взростанию - shellSort - функция сортировки массива методом Шелла
//arr - сортируемый массив; n - размер шага //todo размер шага
template <typename A>
void shellSort(A arr[], size_t n) {
	for (int gap = n / 2; gap > 0; gap /= 2) { //gap - размер шага он уменьшается, BigO = O(n^3/2)
		for (int i = gap; i < n; i++) {
			A temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

//heapify - функция для преобразования массива в кучу
//arr - массив; n - размер массива; i - индекс корня поддерева
template <typename A>
void heapify(A arr[], int n, int i) {
	int largest = i;   
	int l = 2 * i + 1;  
	int r = 2 * i + 2; 

	if (l < n && arr[l] > arr[largest]) {
		largest = l;
	}

	if (r < n && arr[r] > arr[largest]) {
		largest = r;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
//https://habr.com/ru/companies/otus/articles/460087/
//heapSort - функция сортировки массива методом пирамиды
//arr - сортируемый массив; n - размер массива
template <typename A>
void heapSort(A arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

//Assert Функция - проверки функций
void assert_run() {
	//Проверки для четырех случаев todo и повторяющихся элементов
	int arr1[] = { 5, 2, 3, 4, 1 };
	int arr2[] = { 5, 2, 3, 1, 4 };
	int arr3[] = { 1, 2, 5, 4, 3 };
	int arr4[] = { 2, 3, 4, 1, 5 };
	int arr10[] = { 1, 5, 2, 3, 4 };

	int arr11[] = { 5, 4, 3, 2, 1 };
	int arr12[] = { 5, 4, 3, 2, 1 };
	int arr13[] = { 5, 4, 3, 2, 1 };
	int arr14[] = { 5, 4, 3, 2, 1 };
	int arr15[] = { 5, 4, 3, 2, 1 };

	int arr16[] = { 5, 4, 3, 2, 1 };
	int arr17[] = { 5, 4, 3, 2, 1 };
	int arr18[] = { 5, 4, 3, 2, 1 };
	int arr19[] = { 5, 4, 3, 2, 1 };
	int arr20[] = { 5, 4, 3, 2, 1 };

	int arr21[] = { 2, 2, 2, 2, 2 };
	int arr22[] = { 3, 3, 3, 3, 3 };
	int arr23[] = { 1, 1, 1, 1, 1 };
	int arr24[] = { 5, 5, 5, 5, 5 };
	int arr25[] = { 4, 4, 4, 4, 4 };

	int arr26[] = { 2, 2, 2, 2, 2 };
	int arr27[] = { 3, 3, 3, 3, 3 };
	int arr28[] = { 1, 1, 1, 1, 1 };
	int arr29[] = { 5, 5, 5, 5, 5 };
	int arr30[] = { 4, 4, 4, 4, 4 };

	int arr31[] = {1, 2, 5, 4, 3};
	int arr32[] = {5, 3, 1, 2, 4};
	int arr34[10] = {};
	int arr33[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
	mergeSort(arr34, 10);
	assert(is_sorted_more_to_less<int>(10, arr34));
	//Через is_sorted
	int arr35[] = { 5, 2, 3, 1, 4 };
	int arr36[] = { 5, 4, 3, 2, 1 };
	int arr37[] = { 5, 4, 3, 2, 1 };
	int arr38[] = { 3, 3, 3, 3, 3 };
	int arr43[] = { 3, 3, 3, 3, 3 };

	int arr39[] = { 5, 2, 3, 1, 4 };
	int arr40[] = { 5, 4, 3, 2, 1 };
	int arr41[] = { 5, 4, 3, 2, 1 };
	int arr42[] = { 3, 3, 3, 3, 3 };
	int arr44[] = { 3, 3, 3, 3, 3 };

	int arr7[] = { 5, 3, 4, 1, 5, 3, 9, 2, 5, 27, 4, 42, -5, 0, 1 };
	int arr8[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int expected_arr[] = { 1, 2, 3, 4, 5 };
	int n = 5;

	int answ = seek_run<int>(15, arr7, 42);
	assert(-1 != answ);
	answ = seek_run<int>(15, arr7, 128);
	assert(-1 == answ);



	//СР СЛУЧАЙ
	bubble_sort<int>(n, arr1);
	for (int i = 0; i < n; i++) {
		assert(arr1[i] == expected_arr[i]);
	}

	cocktail_sort<int>(n, arr2);
	for (int i = 0; i < n; i++) {
		assert(arr2[i] == expected_arr[i]);
	}

	insertion_sort<int>(n, arr3);
	for (int i = 0; i < n; i++) {
		assert(arr3[i] == expected_arr[i]);
	}

	algoritm_sort_array<int>(n, arr4);
	for (int i = 0; i < n; i++) {
		assert(arr4[i] == expected_arr[i]);
	}

	quickSort(arr10, 0, n-1);
	for (int i = 0; i < n; i++) {
		assert(arr10[i] == expected_arr[i]);
	}

	shellSort(arr35, 5);
	for (int i = 0; i < n; i++) {
		assert(arr35[i] == expected_arr[i]);
	}
	heapSort(arr39, 5);
	for (int i = 0; i < n; i++) {
		assert(arr39[i] == expected_arr[i]);
	}



	//ХУДШИЙ СЛУЧАЙ
	bubble_sort<int>(n, arr11);
	for (int i = 0; i < n; i++) {
		assert(arr11[i] == expected_arr[i]);
	}

	cocktail_sort<int>(n, arr12);
	for (int i = 0; i < n; i++) {
		assert(arr12[i] == expected_arr[i]);
	}

	insertion_sort<int>(n, arr13);
	for (int i = 0; i < n; i++) {
		assert(arr13[i] == expected_arr[i]);
	}

	algoritm_sort_array<int>(n, arr14);
	for (int i = 0; i < n; i++) {
		assert(arr14[i] == expected_arr[i]);
	}

	quickSort(arr15, 0, n - 1);
	for (int i = 0; i < n; i++) {
		assert(arr15[i] == expected_arr[i]);
	}

	shellSort(arr36, 5);
	for (int i = 0; i < n; i++) {
		assert(arr36[i] == expected_arr[i]);
	}
	heapSort(arr40, 5);
	for (int i = 0; i < n; i++) {
		assert(arr40[i] == expected_arr[i]);
	}

	//ЛУЧШИЙ СЛУЧАЙ
	bubble_sort<int>(n, arr16);
	for (int i = 0; i < n; i++) {
		assert(arr16[i] == expected_arr[i]);
	}

	cocktail_sort<int>(n, arr17);
	for (int i = 0; i < n; i++) {
		assert(arr17[i] == expected_arr[i]);
	}

	insertion_sort<int>(n, arr18);
	for (int i = 0; i < n; i++) {
		assert(arr18[i] == expected_arr[i]);
	}

	algoritm_sort_array<int>(n, arr19);
	for (int i = 0; i < n; i++) {
		assert(arr19[i] == expected_arr[i]);
	}

	quickSort(arr20, 0, n - 1);
	for (int i = 0; i < n; i++) {
		assert(arr20[i] == expected_arr[i]);
	}

	shellSort(arr37, 5);
	for (int i = 0; i < n; i++) {
		assert(arr37[i] == expected_arr[i]);
	}
	heapSort(arr41, 5);
	for (int i = 0; i < n; i++) {
		assert(arr41[i] == expected_arr[i]);
	}


	//ОДИНАКОВЫЙ СЛУЧАЙ
	bubble_sort<int>(n, arr16);
	for (int i = 0; i < n; i++) {
		assert(arr21[i] == arr26[i]);
	}

	cocktail_sort<int>(n, arr17);
	for (int i = 0; i < n; i++) {
		assert(arr22[i] == arr27[i]);
	}

	insertion_sort<int>(n, arr18);
	for (int i = 0; i < n; i++) {
		assert(arr23[i] == arr28[i]);
	}

	algoritm_sort_array<int>(n, arr19);
	for (int i = 0; i < n; i++) {
		assert(arr24[i] == arr29[i]);
	}

	quickSort(arr20, 0, n - 1);
	for (int i = 0; i < n; i++) {
		assert(arr25[i] == arr30[i]);
	}

	shellSort(arr38, 5);
	for (int i = 0; i < n; i++) {
		assert(arr38[i] == arr43[i]);
	}
	heapSort(arr42, 5);
	for (int i = 0; i < n; i++) {
		assert(arr42[i] == arr44[i]);
	}

	int arr5[] = { 1, 2, 3, 4, 5 };
	int arr6[] = { 5, 4, 3, 2, 1 };
	assert(is_sorted_less_to_more(5, arr5) == true);
	assert(is_sorted_more_to_less(5, arr6) == true);


	answ = binary_search<int>(arr8, 20, 18);
	assert(-1 != answ);

	answ = binary_search<int>(arr8, 20, 40);
	assert(-1 == answ);

	answ = interpolation_search<int>(arr8, 20, 43);
	assert(-1 == answ);

	answ = interpolation_search<int>(arr8, 20, 12);
	assert(-1 != answ);


	answ = binary_search<int>(arr8, 20, 1);

	assert(0 == answ);

	answ = interpolation_search<int>(arr8, 20, 1);
	assert(0 == answ);

	answ = binary_search<int>(arr8, 20, 20);
	assert(19 == answ);

	answ = interpolation_search<int>(arr8, 20, 20);
	assert(19 == answ);
	//todo: Проверка на первый и последний элемент - крайние элементы
	//todo крайние - несколько предикатов проверить разных
 
	
	//todo: Комментарии к каждой строчке
	//Крайние случаи
	function<bool(int&, int&)> isEqual = [](int x, int y) {return (x == y); }; //Лямбда функция 

	int* arr9 = new int[10] {1, 8, 3, 5, 8, 42, 6, 84, 265, 7}; //Массив для проверок
	assert(sequence_predicat_search(arr9, 10, isEqual, 1000) == -1); //Лямбда функция с выравниванием

	function<bool(int&, int&)> isDivisor = [](int x, int y) {if (x / y == 1) { return true; }; }; //Лямбда функция с делением
	assert(sequence_predicat_search(arr9, 10, isDivisor, 5) == 1);

}
