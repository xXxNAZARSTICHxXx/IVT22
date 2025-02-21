
#include <iostream>
#include <algorithm>
#include "T8Module.cpp"
#include "T5Module.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "russian"); // Устанавливаем русскую локаль
    DynamicArray<int> arr;
    DynamicArray<int> arrTwo;
    assertCheck();
    int controller;
    int x, y, z, min, max, ind;
    arr.push_back_n(0, 0);
    cout << "Введите команду: ";
    cin >> controller;
    cout << "\n";

    do
    {
        switch (controller) {
        case 0:
            cout << "0: Список команд \n";

            cout << "1: Добавить несколько элементов одинакового значения в ПЕРВЫЙ массив \n";
            cout << "2: Показать ПЕРВЫЙ массив \n";
            cout << "3: Отсечь после какой-нибуть позиции сколько то элементов в ПЕРВОМ массиве \n";
            cout << "4: Сделать ПЕРВЫМ массив случайным \n";
            cout << "5: Информация о ПЕРВОМ массиве \n";
            cout << "6: Добавление элемена по позиции и значению в ПЕРВОМ массиве \n";
            cout << "7: Удаление элемента по значению в ПЕРВОМ массиве  \n";
            cout << "8: Поиск значения в ПЕРВОМ массиве \n";
            cout << "9: Сортировка по возростанию в ПЕРВОМ массиве \n";
            cout << "10: Удалить несколько элементов с конца ПЕРВОГО массива \n";
            cout << "11: Добавить несколько элементов с определенной позиции массива в ПЕРВОМ массиве \n";

            cout << "12: Добавить несколько элементов одинакового значения во ВТОРОЙ массив \n";
            cout << "13: Показать ВТОРОЙ массив \n";
            cout << "14: Отсечь после какой-нибуть позиции сколько то элементов во ВТОРОМ массиве \n";
            cout << "15: Сделать ВТОРОЙ массив случайным \n";
            cout << "16: Информация во ВТОРОМ массиве \n";
            cout << "17: Добавление элемена по позиции и значению во ВТОРОМ массиве \n";
            cout << "18: Удаление элемента по значению во ВТОРОМ массиве  \n";
            cout << "19: Поиск значения во ВТОРОМ массиве \n";
            cout << "20: Сортировка по возростанию во ВТОРОМ массиве \n";
            cout << "21: Удалить несколько элементов с конца ВТОРОГО массива \n";
            cout << "22: Добавить несколько элементов с определенной позиции массива во ВТОРОМ массиве \n";

            cout << "23: Сложить ПЕРВЫЙ массив со ВТОРЫМ массивом \n";
            cout << "24: Сложить ВТОРОЙ массив с ПЕРВЫМ массивом \n";

            cout << "25: Завершить программу \n";
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 1:
            cout << "Введите размер, который хотите добавить к массиву,\nи укажите какой элемент туда поместить: ";
            cin >> x;
            cin >> y;
            arr.push_back_n(y, x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;

        case 2:
            cout << "Динамический массив выглядит следующим образом:\n ";
            arr.print();
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;

        case 3:
            cout << "Введите размер, который требуется отсечь и позицию, ПОСЛЕ КАКОГО элемента отсекать: ";
            cin >> x;
            cin >> y;
            arr.erase_n(y, x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 4:
            cout << "Укажите ДИАПАЗОН ЭЛЕМЕНТОВ MIN MAX, чтобы изменить знчения: ";
            cin >> min;
            cin >> max;
            arr.fill_random(min, max);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 5:
            cout << "Информация о массиве: ";

            cout << "Размер: " << arr.getSize() << endl;
            cout << "Емкость: " << arr.getCapacity() << endl;

            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 6:
            cout << "Введите позицию элемента и значение элемента,\nкоторого вы хотите добавить: ";
            cin >> x;
            cin >> y;
            arr.insert(y, x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 7:
            cout << "Введите позицию элемента, который треюуется убрать: ";
            cin >> x;
            arr.erase(x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;

        case 8:
            cout << "Введите значение элемента, который требуется найти: ";
            cin >> x;
            if (is_sorted_less_to_more(arr.getSize(), arr.getData()) == true) {
                cout << "1: Поиск последовательный \n";
                cout << "2: Поиск бинарный \n";
                cout << "3: Поиск интерполяционный \n";
                cout << "\nВведите способ поиска: ";
                cin >> controller;
                cout << "\n";
                switch (controller)
                {
                case 1:
                    //todo шаблонный seek_run
                    cout << "Позиция на которой расположен элемент: " << seek_run(arr.getSize(), arr.getData(), x)  << endl;
                case 2:
                    binary_search(arr.getData(), arr.getSize(), x);
                case 3:
                    interpolation_search(arr.getData(), arr.getSize(), x);
                default:
                    break;
                }

            }
            else
            {
                cout << seek_run(arr.getSize(), arr.getData(), x) << endl;
            }
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 9:
            cout << "1: Сортировка пузырьком \n";
            cout << "2: Коктельная сортировка \n";
            cout << "3: Сортировка вставками \n";
            cout << "4: Сортировка библиотечкая \n";
            cout << "5: Сортировка супербыстрая \n";
            cout << "6: Сортировка слияния \n";
            cout << "7: Сортировка Шелла \n";
            cout << "8: Сортировка пирамидальная \n";
            cout << "\nВведите сортировку: ";
            cin >> controller;
            cout << "\n";

            switch (controller)
            {
            case 1:
                bubble_sort(arr.getSize(), arr.getData());
                break;
            case 2:
                cocktail_sort(arr.getSize(), arr.getData());
                break;
            case 3:
                insertion_sort(arr.getSize(), arr);
                break;
            case 4:
                algoritm_sort_array(arr.getSize(), arr.getData());
                break;
            case 5:
                ind = arr.getSize();
                quickSort(arr.getData(), 0, ind);
                break;
            case 6:
                mergeSort(arr.getData(), arr.getSize());
                break;
            case 7:
                shellSort(arr.getData(), arr.getSize());
                break;
            case 8:
                bubble_sort(arr.getSize(), arr.getData());
                break;
            default:
                break;
            }
            cout << "Отсортировано по возростанию\n";
            cout << "Введите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 10:
            cout << "Введите количество элементов, которые вы хотите отсечь с конца: ";
            cin >> x;
            arr.pop_back_n(x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 11:
            cout << "Введите позицию элемента, значение элемента,\nи количество элементов которого вы хотите\nдобавить: ";
            cin >> x;
            cin >> y;
            cin >> z;
            arr.insert_n(x, y, z);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;

        case 12:
            cout << "Введите размер, который хотите добавить к массиву,\nи укажите какой элемент туда поместить: ";
            cin >> x;
            cin >> y;
            arrTwo.push_back_n(y, x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;

        case 13:
            cout << "Динамический массив выглядит следующим образом:\n ";
            arrTwo.print();
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;

        case 14:
            cout << "Введите размер, который требуется отсечь и позицию, ПОСЛЕ КАКОГО элемента отсекать: ";
            cin >> x;
            cin >> y;
            arrTwo.erase_n(y, x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 15:
            cout << "Укажите ДИАПАЗОН ЭЛЕМЕНТОВ MIN MAX, чтобы изменить знчения: ";
            cin >> min;
            cin >> max;
            arrTwo.fill_random(min, max);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 16:
            cout << "Информация о массиве: ";

            cout << "Размер: " << arrTwo.getSize() << endl;
            cout << "Емкость: " << arrTwo.getCapacity() << endl;

            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 17:
            cout << "Введите позицию элемента и значение элемента,\nкоторого вы хотите добавить: ";
            cin >> x;
            cin >> y;
            arrTwo.insert(y, x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 18:
            cout << "Введите позицию элемента, который треюуется убрать: ";
            cin >> x;
            arrTwo.erase(x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;

        case 19:
            cout << "Введите значение элемента, который требуется найти: ";
            cin >> x;
            if (is_sorted_less_to_more(arrTwo.getSize(), arrTwo.getData()) == true) {
                cout << "1: Поиск последовательный \n";
                cout << "2: Поиск бинарный \n";
                cout << "3: Поиск интерполяционный \n";
                cout << "\nВведите способ поиска: ";
                cin >> controller;
                cout << "\n";
                switch (controller)
                {
                case 1:
                    cout << "Позиция на которой расположен элемент: " << seek_run(arrTwo.getSize(), arrTwo.getData(), x) << endl;
                case 2:
                    binary_search(arrTwo.getData(), arrTwo.getSize(), x);
                case 3:
                    interpolation_search(arrTwo.getData(), arrTwo.getSize(), x);
                default:
                    break;
                }

            }
            else
            {
                cout << seek_run(arrTwo.getSize(), arrTwo.getData(), x) << endl;
            }
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 20:
            cout << "1: Сортировка пузырьком \n";
            cout << "2: Коктельная сортировка \n";
            cout << "3: Сортировка вставками \n";
            cout << "4: Сортировка библиотечкая \n";
            cout << "5: Сортировка супербыстрая \n";
            cout << "6: Сортировка слияния \n";
            cout << "7: Сортировка Шелла \n";
            cout << "8: Сортировка пирамидальная \n";
            cout << "\nВведите сортировку: ";
            cin >> controller;
            cout << "\n";

            switch (controller)
            {
            case 1:
                bubble_sort(arrTwo.getSize(), arrTwo.getData());
                break;
            case 2:
                cocktail_sort(arrTwo.getSize(), arrTwo.getData());
                break;
            case 3:
                insertion_sort(arrTwo.getSize(), arrTwo);
                break;
            case 4:
                algoritm_sort_array(arrTwo.getSize(), arrTwo.getData());
                break;
            case 5:
                ind = arr.getSize();
                quickSort(arr.getData(), 0, ind);
                break;
            case 6:
                mergeSort(arr.getData(), arr.getSize());
                break;
            case 7:
                shellSort(arr.getData(), arr.getSize());
                break;
            case 8:
                bubble_sort(arr.getSize(), arr.getData());
                break;
            default:
                break;
            }
            cout << "Отсортировано по возростанию\n";
            cout << "Введите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 21:
            cout << "Введите количество элементов, которые вы хотите отсечь с конца: ";
            cin >> x;
            arrTwo.pop_back_n(x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 22:
            cout << "Введите позицию элемента, значение элемента,\nи количество элементов которого вы хотите\nдобавить: ";
            cin >> x;
            cin >> y;
            cin >> z;
            arrTwo.insert_n(x, y, z);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 23:
            cout << "Соеденино";
            cin >> x;
            cin >> y;
            cin >> z;
            arr.concatenate(arrTwo);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        case 24:
            cout << "Соеденино";
            cin >> x;
            cin >> y;
            cin >> z;
            arrTwo.concatenate(arr);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        default:
            cout << "Введите другую команду или введите 0 для просмотра списка команд: ";
            cin >> controller;
            cout << "\n";
        }

    } while (controller != 25);
    arr.~DynamicArray();
    arrTwo.~DynamicArray();
    cout << "\nПрограмма завершилась!";
    return 0;
}

//TODO RUN!!! Метод конкатинации