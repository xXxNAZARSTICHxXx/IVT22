#include <iostream>
#include <iostream>
#include <vector>
#include "T9Module.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    assertCheck();
    DoubleList<int> list1;  // Создание списка
    DoubleList<int> list2;  // Создание второго списка
    int controller = 0;
    int x, y;
    int arring;
    vector<int> pos_arr; // Создаем вектор для хранения позиций
    do
    {
        switch (controller) {
        case 0:
            std::cout << "0: Список команд \n";
            cout << "1: Добавить в ПЕРВЫЙ список элемент \n";
            cout << "2: Добавить во ВТОРОЙ список элемент \n";
            cout << "3: Показать ПЕРВЫЙ список \n";
            cout << "4: Показать ВТОРОЙ список \n";
            cout << "5: Соединить ПЕРВЫЙ список СО ВТОРЫМ \n";
            cout << "6: Соединить ВТОРОЙ список С ПЕРВЫМ \n";
            cout << "7: Размер ПЕРВОГО списка \n";
            cout << "8: Размер ВТОРОГО списка \n";
            cout << "9: Удалить элемент с конца ПЕРВОГО списка \n";
            cout << "10: Удалить элемент с конца ВТОРОГО списка \n";
            cout << "11: Удалить элемент с начала ПЕРВОГО списка \n";
            cout << "12: Удалить элемент с начала ВТОРОГО списка \n";
            cout << "13: Вставить элемент по позиции в ПЕРВЫЙ список \n";
            cout << "14: Вставить элемент по позиции во ВТОРОЙ список \n";
            cout << "15: Найти элемент в ПЕРВОМ списке \n";
            cout << "16: Найти элемент во ВТОРОМ списке \n";
            cout << "17: Отсортировать ПЕРВЫЙ список по возрастаню \n";
            cout << "18: Отсортировать ВТОРОЙ список по возрастаню \n";
            cout << "19: Сложить набор элементов в ПЕРВОМ списке \n";
            cout << "20: Сложить набор элементов во ВТОРОМ списке \n";
            cout << "21: Сложить все элементы в ПЕРВОМ списке \n";
            cout << "22: Сложить все элементы во ВТОРОМ списке \n";
            cout << "23: Сложить определенне элементы ПЕРВОГО списка \n";
            cout << "24: Сложить определенне элементы ВТОРОГО списка \n";
            cout << "25: Вычесть набор элементов в ПЕРВОМ списке \n";
            cout << "26: Вычесть набор элементов во ВТОРОМ списке \n";
            cout << "27: Вычесть все элементы в ПЕРВОМ списке \n";
            cout << "28: Вычесть все элементы во ВТОРОМ списке \n";
            cout << "29: Вычесть определенне элементы ПЕРВОГО списка \n";
            cout << "30: Вычесть определенне элементы ВТОРОГО списка \n";
            cout << "31: Перемножить набор элементов в ПЕРВОМ списке \n";
            cout << "32: Перемножить набор элементов во ВТОРОМ списке \n";
            cout << "33: Перемножить все элементы в ПЕРВОМ списке \n";
            cout << "34: Перемножить все элементы во ВТОРОМ списке \n";
            cout << "35: Перемножить определенне элементы ПЕРВОГО списка \n";
            cout << "36: Перемножить определенне элементы ВТОРОГО списка \n";
            cout << "37: Завершить программу \n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 1:
            cout << "\nВведите элемент для ввода: ";
            cin >> x;
            cout << "\n";
            list1.push_back(x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 2:
            cout << "\nВведите элемент для ввода: ";
            cin >> x;
            cout << "\n";
            list2.push_back(x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 3:
            cout << "\nПервый список: \n";
            list1.template print <int>(cout);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 4:
            cout << "\nПервый список: \n";
            list2.template print <int>(cout);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 5:
            list2.template concatenate<int>(list1);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 6:
            list1.template concatenate<int>(list2);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 7:
            cout << "\nРазмер первого списка: ";
            list1.getSize();
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 8:
            cout << "\nРазмер второго списка: ";
            list2.getSize();
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 9:
            list1.pop_back();
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 10:
            list2.pop_back();
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 11:
            list1.pop_front();
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 12:
            list2.pop_front();
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 13:
            cout << "\nВведите позицию элемента для ввода и элемент для ввода: ";
            cin >> x;
            cin >> y;
            list1.insert(x, y);
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 14:
            cout << "\nВведите позицию элемента для ввода и элемент для ввода: ";
            cin >> x;
            cin >> y;
            list2.insert(x, y);
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 15:
            cout << "\nВведите запрашиваемый элемент: ";
            cin >> x;
            cout << list1.find(x) << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 16:
            cout << "\nВведите запрашиваемый элемент: ";
            cin >> x;
            cout << list2.find(x) << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 17:
            list1.insertionSort();
            cout << "\nОтсортированно по возростанию ";
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 18:
            list2.insertionSort();
            cout << "\nОтсортированно по возростанию ";
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 19:
            cout << "\n Сумма всех чисел в списке равна: " << list1.sum_all() << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 20:
        {
            cout << "\n Сумма всех чисел в списке равна: " << list2.sum_all() << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        }
        case 21:
            cout << "Введите количество позиций: ";
            cin >> arring;
            pos_arr.resize(arring);
            cout << "\nВведите позиции элементов: ";
            for (int i = 0; i < arring; i++) {
                cin >> pos_arr[i];
            }

            cout << "\nСумма выбранных элементов: " << list1.sum_specific (pos_arr.data(), arring) << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 22:
            cout << "Введите количество позиций: ";
            cin >> arring;
            pos_arr.resize(arring);
            cout << "\nВведите позиции элементов: ";
            for (int i = 0; i < arring; i++) {
                cin >> pos_arr[i];
            }

            cout << "\nСумма выбранных элементов: " << list1.sum_specific (pos_arr.data(), arring) << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 23:
            cout << "\nВведите диапазон суммы элементов X и Y: ";
            cin >> x;
            cin >> y;
            cout << "\nСумма выбранного диапазона элементов: " << list1.sum_subset(x, y) << endl;
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 24:
            cout << "\nВведите диапазон суммы элементов X и Y: ";
            cin >> x;
            cin >> y;
            cout << "\nСумма выбранного диапазона элементов: " << list2.sum_subset(x, y) << endl;
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 25:
            cout << "\n Разность всех чисел в списке равна: " << list1.sub_all () << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 26:
        {
            cout << "\n Разность всех чисел в списке равна: " << list2.sub_all () << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        }
        case 27:
            cout << "Введите количество позиций: ";
            cin >> arring;
            pos_arr.resize(arring);
            cout << "\nВведите позиции элементов: ";
            for (int i = 0; i < arring; i++) {
                cin >> pos_arr[i];
            }

            cout << "\nРазность выбранных элементов: " << list1.sub_specific (pos_arr.data(), arring) << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 28:
            cout << "Введите количество позиций: ";
            cin >> arring;
            pos_arr.resize(arring);
            cout << "\nВведите позиции элементов: ";
            for (int i = 0; i < arring; i++) {
                cin >> pos_arr[i];
            }

            cout << "\nРазность выбранных элементов: " << list2.sub_specific(pos_arr.data(), arring) << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 29:
            cout << "\nВведите диапазон разностей элементов X и Y: ";
            cin >> x;
            cin >> y;
            cout << "\nРазности выбранного диапазона элементов: " << list1.sub_subset (x, y) << endl;
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 30:
            cout << "\nВведите диапазон разностей элементов X и Y: ";
            cin >> x;
            cin >> y;
            cout << "\nРазности выбранного диапазона элементов: " << list2.sub_subset (x, y) << endl;
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 31:
            cout << "\n Перемножение всех чисел в списке равно: " << list1.num_all() << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 32:
        {
            cout << "\n Перемножение всех чисел в списке равно: " << list2.num_all() << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        }
        case 33:
            cout << "Введите количество позиций: ";
            cin >> arring;
            pos_arr.resize(arring);
            cout << "\nВведите позиции элементов: ";
            for (int i = 0; i < arring; i++) {
                cin >> pos_arr[i];
            }

            cout << "\nПеремножение выбранных элементов: " << list1.mul_specific(pos_arr.data(), arring) << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 34:
            cout << "Введите количество позиций: ";
            cin >> arring;
            pos_arr.resize(arring);
            cout << "\nВведите позиции элементов: ";
            for (int i = 0; i < arring; i++) {
                cin >> pos_arr[i];
            }

            cout << "\nПеремножение выбранных элементов: " << list2.mul_specific(pos_arr.data(), arring) << endl;
            cout << "\n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 35:
            cout << "\nВведите диапазон разностей элементов X и Y: ";
            cin >> x;
            cin >> y;
            cout << "\nПеремножение выбранного диапазона элементов: " << list1.mul_subset(x, y) << endl;
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 36:
            cout << "\nВведите диапазон разностей элементов X и Y: ";
            cin >> x;
            cin >> y;
            cout << "\nПеремножение выбранного диапазона элементов: " << list2.mul_subset(x, y) << endl;
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;

        default:
            cout << "Введите другую команду или введите 0 для просмотра списка команд: ";
            cin >> controller;
            cout << "\n";
        }
    } while (controller != 26);
    list1.template clear <int>();
    list2.template clear <int>();
    cout << "\nПрограмма завершилась!";
    return 0;
}
