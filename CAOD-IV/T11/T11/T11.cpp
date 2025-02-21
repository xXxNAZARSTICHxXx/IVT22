#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
#include "T11Module.cpp"
using namespace std;


int main() {
    setlocale(LC_ALL, "russian");
    assertCheckB();
    Stack<double> operandStack;
    string postfixExpression;
    cout << "Введите постфиксное выражение: ";
    getline(cin, postfixExpression);
    cout << "Результат: " << evaluatePostfix(postfixExpression, operandStack) << endl;
    return 0;
}