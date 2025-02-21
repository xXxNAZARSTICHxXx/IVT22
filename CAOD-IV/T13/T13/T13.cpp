#include <iostream>
#include <stack>
#include <stdexcept>
#include "T13Module.cpp"

int main() {
	setlocale(LC_ALL, "russian");
	//assertcheckD();

	long long arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Исходный массив:" << endl;
	show_array(n, arr);

	radixSort(arr, n);

	cout << "Отсортированный массив:" << endl;
	show_array(n, arr);

	return 0;
}