#include <iostream>  // Библиотека для ввода и вывода
#include <vector>    // Библиотека для работы с динамическими массивами (векторами)
#include <stdexcept> // Библиотека для обработки исключений
#include "Heap.h"   
#include "T8Module.cpp"   

int main() {
    setlocale(LC_ALL, "russian");
    testMinHeap();
    testMaxHeap();
    MinHeap<int> heap; // Создаем объект класса MinHeap для типа int
    heap.insert(10); // Вставляем элементы в кучу
    heap.insert(5);
    heap.insert(20);
    heap.insert(2);

    std::cout << "Куча: "; // Выводим текущее состояние кучи
    heap.printHeap();

    std::cout << "Минимальное значение: " << heap.getMin() << std::endl; // Выводим минимальный элемент

    std::cout << "Минимальный элемент: " << heap.extractMin() << std::endl; // Извлекаем минимальный элемент

    std::cout << "Куча после обработки: "; // Выводим состояние кучи после извлечения
    heap.printHeap();

    return 0;
}
