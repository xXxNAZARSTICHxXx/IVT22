#include <iostream>
#include <stack>
#include <utility>
#include <cassert>

using namespace std;

//ackermannBAD - рекурсивная функция, которая вызовет переполнение памяти при средних значениях (хуже)
//m и n - это аргументы
int ackermannBAD(int m, int n) {
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return ackermannBAD(m - 1, 1);
    else
        return ackermannBAD(m - 1, ackermannBAD(m, n - 1));
}

//infinityRecursion - функция, которая вызывает функцию, которая вызывает функцию, которая вызывает функцию, которая вызывает функцию...
//которая вызвает функцию... которая измеряет глубину стека
//Последнее значение после ошибки, это размер глубины стека%%%
//В debug глубина равна 4011 вызовов; В release глубина равна 21437 вызовов%%%
int infinityRecursion(int& arg)
{
    cout << arg << endl;
    arg++;
    infinityRecursion(arg);
    return 0;
}



//ackermannGOOD - цикличная функция, которая вызовет переполнение памяти при очень высоких значениях (лучше)
//m и n - это аргументы
int ackermannGOOD(int m, int n) {
    stack<pair<int, int>> stack;
    stack.push(make_pair(m, n));

    while (!stack.empty()) {
        pair<int, int> current = stack.top();
        stack.pop();
        m = current.first;
        n = current.second;

        if (m == 0)
            n = n + 1;
        else if (n == 0) {
            stack.push(make_pair(m - 1, 1));
            continue;
        }
        else {
            stack.push(make_pair(m - 1, n));
            stack.push(make_pair(m, n - 1));
            continue;
        }
    }
    return n;
}

//Функция assert проверка %%%
void assertCheck() {
    assert(ackermannBAD(2, 0) == 3);
    assert(ackermannBAD(3, 0) == 5);
    assert(ackermannBAD(4, 0) == 13);
    assert(ackermannGOOD(2, 0) == 3);
    assert(ackermannGOOD(3, 0) == 5);
    assert(ackermannGOOD(4, 0) == 13);
}
//todo test