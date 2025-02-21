#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

//findchange - ��������� ��������� �����
//amount - ��������� �����; nominal - ������� � ����������; size - ������ ������� � ����������; change - ������ �� ������ 
findChange(int amount, int nominal[], size_t size, int change[]) {
    sort(nominal, nominal + size, greater<int>()); // ���������� ��������� �� ��������
    int comparisons = 0;            // ������� ���������
    int num = 0;
    int index = 0; // ������ ��� ���������� ������� change
    for (int i = 0; i < size; i++) { // ����������� �������� �� ��� ��������
        while (amount >= nominal[i]) {     // ������ �������� �� ���-�� ��������/���� �������� ����� >= 0
            amount -= nominal[i];          // ��������� ������������� ��������
            num++;                         // ����������� ��������
            comparisons++;                 // ����������� ���������
        }
        if (num > 0) {
            change[index++] = num; // ���������� ���������� �������������� �����/����� � ������
            num = 0; // �������� �������
        }
        else {
            index++; //���� �������� ���������� �������������
        }
    }
    return comparisons; // ���������� ���������� ���������
}

//assert-�������� ��� �������������
void assertCheck() {
    int nominal[] = { 1, 2, 5, 10 ,50, 100, 200, 500, 1000, 2000, 5000 }; // �������� �����/�����
    const size_t size = sizeof(nominal) / sizeof(nominal[0]);                   //size_t size - ��� ����������� ������� �������
    int change[size] = { 0 };                                                   // ������ ��� �������� ���������� �������������� �����/�����
    assert((findChange(7500, nominal, size, change)) == 3);                      // �������� ��� ��������, ��� ������ �������� ������� �������� 3 ����
    assert((findChange(900, nominal, size, change)) == 3);                       // �������� ��� ��������, ��� ������ �������� ������� �������� 3 ����
    assert((findChange(45, nominal, size, change)) == 5);                        // �������� ��� ��������, ��� ������ �������� ������� �������� 5 ����
}
