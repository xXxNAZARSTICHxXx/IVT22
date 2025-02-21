#include <iostream>
#include <stack>
#include <stdexcept>
#include "T12Module.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    assertCheckC();
    int X;
    char Y = 'y';
    QueueFromStack<int> queue;
    while (Y == 'y' || Y == 'Y')
    {
        cout << "Введите целочисленный элемент для того, чтобы его положить в очередь: ";
        cin >> X;
        queue.enqueue(X);
        cout << "\nВвести еще один элемент?: ";
        cin >> Y;
    };
    Y = 'y';
    while (Y == 'y' || Y == 'Y')
    {
        try {
            cout << "Элемент из очереди: ";
            cout << queue.dequeue() << endl;  
        }
        catch (const out_of_range& e) {
            cerr << "отсутствует - " << e.what() << endl;
            break;
        }
        cout << "\nВывести еще один элемент с очереди?: ";
        cin >> Y;
    };

}