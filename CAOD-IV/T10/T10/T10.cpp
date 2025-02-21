#include <iostream>
#include <stdexcept>
#include "T10Module.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    //assertCheckA();
    Stack<int> stack;
    int controller = 0;
    double x;

    do
    {
        switch (controller) {
        case 0:
            cout << "0: Список команд \n";

            cout << "1: Добавить в стек число \n";
            cout << "2: Удаление элемента из стека \n";
            cout << "3: Удаление ВСЕХ элементов из стека \n";
            cout << "4: Проверить - заполнен ли стек? \n";
            cout << "5: Завершение программы \n";

            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        break;

        case 1:
            cout << "\nВведите значение элемента: ";
            cin >> x;
            stack.push(x);
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;

        case 2:
            if (!stack.isEmpty()) {
                cout << "Удаленный элемент : " << stack.pop() << endl;
            }
            else {
                cout << "Стек пуст" << endl;
            }
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        
        case 3:
            while (!stack.isEmpty()) {
                stack.pop();
            }
            cout << "Стек очищен" << endl;
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;
        
        case 4:
            cout << "Стек пуст: " << (stack.isEmpty() ? "true" : "false") << endl;
            cout << "\nВведите команду: ";
            cin >> controller;
            cout << "\n";
            break;

        default:
        cout << "Введите другую команду или введите 0 для просмотра списка команд: ";
        cin >> controller;
        cout << "\n";
        }

    } while (controller != 5);

    cout << "Программа завершена!" << endl;

    return 0;
}
