#include <iostream>
#include "T14Module.cpp" // Подключаем заголовочный файл с определением класса QueueFromDeque
using namespace std;
int main() {
    setlocale(LC_ALL, "russian");
    assertCheckE();
    // Создаем объект очереди типа int
    QueueFromDeque<int> queue;

    // Добавляем элементы в очередь
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Проверяем элемент в начале очереди без его извлечения
    cout << "Первый элемент в очереди: " << queue.peek_fr() << endl;

    // Извлекаем и выводим элементы из очереди
    cout << "Извлеченные элементы из очереди: ";
    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " ";
    }
    cout << endl;

    return 0;
}