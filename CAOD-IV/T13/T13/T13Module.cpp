#include <iostream>
#include <stack>
#include <stdexcept>
#include "T10Module.cpp"
#include "T5Module.cpp"
#include <queue>


// ������� ��� ���������� ������������� ����� � �������
// arr[] - ������
// n - ���-�� ���������
long long findMax(long long arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ������� ��� ���������� ���������� Radix - ��������� �������� �� �����������
// arr[] - ������
// n - ���-�� ���������
void radixSort(long long arr[], int n) {
    long long max = findMax(arr, n); // ������� ������������ �����
    long long exp = 1;
    queue<long long> q[10]; // ������� 10 �������� ��� ������� ������� (0-9)

    while (max / exp > 0) { // ���� �� ��������� ������������� ������� �����
        // ������������ ����� � ������� �� �������� ������� (exp)
        for (long long i = 0; i < n; i++) {
            q[(arr[i] / exp) % 10].push(arr[i]);
        }

        // �������� ����� �� �������� ������� � ������
        long long j = 0;
        for (long long i = 0; i < 10; i++) {
            while (!q[i].empty()) {
                arr[j++] = q[i].front();
                q[i].pop();
            }
        }

        // ��������� � ���������� �������
        exp *= 10;
    }

}

void assertcheckD() {
    //�� bigO, ��� ���������� ����� O(n) - ���� ���� �� ����� �����, ��������, �� ��� O(n!), �� �� ��������� ��������� ������
    long long arr[] = { 103, 206, 309, 412, 515 }; 
    long long arr2[] = { 343, 552, 1088, 124, 423 };
    long long arr3[] = { 515, 412, 309, 206, 103 };
    long long arr4[] = { 111, 111, 111, 111, 111 };
    long long arr5[] = { 654568653, 534543278, 457467896, 734532345, 163643908 };
    //������ �������, �������, ����������... big O;
    long long n = 5;

    assert(findMax(arr, n) == 515);
    assert(findMax(arr2, n) == 1088);
    assert(findMax(arr3, n) == 515);
    assert(findMax(arr4, n) == 111);
    assert(findMax(arr5, n) == 734532345);
    radixSort(arr, n);
    radixSort(arr2, n);
    radixSort(arr3, n);
    radixSort(arr4, n);
    radixSort(arr5, n);
    assert(is_sorted_less_to_more(n, arr) == true);
    assert(is_sorted_less_to_more(n, arr2) == true);
    assert(is_sorted_less_to_more(n, arr3) == true);
    assert(is_sorted_less_to_more(n, arr4) == true);
    assert(is_sorted_less_to_more(n, arr5) == true);
}