#include <iostream>
#include <cassert>
#include <fstream>
#include <stdexcept>
#include <vector> 
#include <algorithm>
using namespace std;

//���������� ������ ��� �������� ����� ������������ �������
vector<vector<long long>> pascalTriangle;

//������� ��� ���������� �������� �������� ������������ �������
//row - �������� �����, col - �������� ��������
long long pascalValue(int row, int col) {
    if (col == 0 || col == row)
        return 1;
    else
        return pascalValue(row - 1, col - 1) + pascalValue(row - 1, col);
}

//������� ��� �������� ����� � ������ �������� �� ����
//filename - �������� ����������
int readValueFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw runtime_error("���������� ������� ���� " + filename + " ��� ������");
    }
    int value;
    inputFile >> value;
    inputFile.close();

    return value;
}

//������� ��� ���������� ������� ����� ������������ �������
//n - ������ �������
void fillPascalTriangle(int n) {
    pascalTriangle.clear(); 
    for (int i = 0; i < n; i++) {
        vector<long long> row;
        for (int j = 0; j <= i; j++) {
            row.push_back(pascalValue(i, j));
        }
        pascalTriangle.push_back(row);
    }
}

//������� ��� ������ ������������ ������� � ����
//n - ������ �������, filename - �������� ����������
void printPascalTriangleToFile(int n, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        throw runtime_error("���������� ������� ���� ��� ������.");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            outputFile << pascalValue(i, j) << " ";
        }
        outputFile << endl;
    }
    outputFile.close();
}

//Assert-������� ��� �������� �������
void assertCheck() {
    assert(pascalValue(3, 3) == 1);
    assert(pascalValue(5, 4) == 5);
    assert(pascalValue(7, 5) == 21);
}

