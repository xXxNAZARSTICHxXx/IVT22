#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <clocale> 
using namespace std;

// ������� ������ ������� �� �����
//n - ������ �������; arr - ������;
void show_array(size_t n, int arr[]){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
// ������� �������� ������� � ���������� ��� ���������� �������
//n - ������ �������; arr - ������, min - ����������� max - ������������ ��������;
void filling_array(size_t n, int min, int max, int arr[]) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

// ������� ����� ����������� �������
int array_size() {
	int n;
	cout << "������� ����������� �������: ";
	cin >> n;
	return n;
}

//������� ����� ��������� ��������� �����
//min - ����������� �������� ��������� �����; max - ������������ �������� ��������� ����� ;
void random_diaposon(int& min, int& max){
	cout << "������� �������� ��������� ����� ��� ���������� ������� MIN, MAX: ";
	cin >> min;
	cin >> max;
}
// ������� ���������� ������� � ����
//n - ������ �������; arr - ������; �������� ����� - constant ���������� fname
void save_in_file(int n, int arr[], const string& filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		throw runtime_error("������ �������� ����� ��� ������");
	}

	for (int i = 0; i < n; i++) {
		if (i % 21 == 20) {
			outfile << "\n";
		}
		outfile << arr[i] << " ";
	}
	outfile.close();
	cout << "\n������ ������� ������� � ����" << endl;
}

// ������� ��� ����������� ����, ��������� �� ���������� ���������, ������� ��������; ���������� ���������, ������� ��������, ��� ��������
//arr - ������, n - ������ �������, average - ���������� �����
int compareCounts(int* arr, size_t n, double average) {
    int aboveCount = 0;                                                         //���������� ��� �������� ���-�� ����� ����������� ������� �����
    int belowCount = 0;                                                         //���������� ��� �������� ���-�� ����� �� ����������� ������� �����
    int simmilarCount = 0;
    int m = n / 2;
    for (size_t i = 0; i < n; i++) {                                               //������� ���������
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

    if (simmilarCount == n){                                                                         //�������� ������
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

//�������, ������� ��������� ��� ��������� ��� �������� ������
//arr - ������, n - ������ �������, average - ������� �����, filrname - ������ �����, answ - ��������� ������ ������� �������� �� ������� ������
void answerReport(int* arr, size_t n, double average, const string& filename, int answ) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw runtime_error("Unable to open output file!");                     // ������� ���������� � ������ ������ �������� �����
    }
    if (answ == 1) {
        outFile << ">>> ����� ���������, ����������� �������, ������ ����� ���������, ������� ��������" << endl;
        outFile << ">>> ���������� �����: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("������ �������� ����� ��� ������");
        }
        show_array(n, arr);
    }
    else if (answ == 2) {
        outFile << ">>> ����� ���������, ����������� �������, ������ ����� ���������, ������� ��������" << endl;
        outFile << ">>> ���������� �����: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("������ �������� ����� ��� ������");
        }
        show_array(n, arr);
    }
    else if (answ == 3) {
        outFile << ">>> ����� ���������, ����������� �������, ����� ����� ���������, ������� ��������" << endl;
        outFile << ">>> ���������� �����: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("������ �������� ����� ��� ������");
        }
        show_array(n, arr);
    }
    else if (answ == 4) {
        outFile << ">>> ��� �������� � ������� �����" << endl;
        outFile << ">>> ���������� �����: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("������ �������� ����� ��� ������");
        }
        show_array(n, arr);
    }
    outFile.close();
}

//�������� �������, ���� ��� ����� ������ {2 2 2 2 2 2 2 2 2 2}%%%
//�������, ������� ��������� ������� ����� assert
void assertcheck(){
    int answ = 0;
    int n = 10;
    int arr2[] = {1,2,3,4,5,6,7,8,9,9}; //average = 5.4
    float sum = 0;                                                              //���������� ��� �������� ����� ��� ���������� �������� �����
    for (size_t i = 0; i < n; i++) {                                               //���������� �������� ��������
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

