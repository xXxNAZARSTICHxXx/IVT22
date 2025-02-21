#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
#include "T10Module.cpp"

using namespace std;

// factorial - функция поиска факториала числа
//
unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;
    for (unsigned int i = 2; i <= n; i++) {
        result *= i; // Постепенное умножение на числа от 2 до n
    }
    return result;
}

// isOperator - проверка на оператор
//
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == 'v' || ch == '!';
}

// isOperand - проверка на операнд
//
bool isOperand(char ch) {
    return isdigit(ch);
}

// applyOperation - функция для выполнения операции
//
//
//
double applyOperation(double operand1, double operand2, char op) {
    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 == 0)
            throw invalid_argument("Деление на ноль");
        return operand1 / operand2;
    case '^':
        return pow(operand1, operand2);
    case 'v':
        return sqrt(operand1);
    case '!':
        return factorial(operand1);
    default:
        throw invalid_argument("Неверная операция");
    }
}

// evaluatePostfix - выполнение операций в постфиксном выражении
// expression - выражение
// operandStack - стек выражения
double evaluatePostfix(const string& expression, Stack<double>& operandStack) {
    stringstream ss(expression); //stringstream ss(expression) - создается объект stringstream(поток символов строки) с именем ss, который используется для чтения из строки expression
    string token; //это строка, которая счиывается потоком ss, которая хранит число(многозначное) или символ - оператор ~ считается благодаря пробелами между операндами и операторами "2 4 +"
    double result = 0.0; // Инициализация переменной для результата
    double operand1, operand2;
    while (ss >> token) {  //Начинается цикл, который продолжается до тех пор, пока объект stringstream ss может извлечь символы из строки expression и помещать их в переменную token
        //todo что записывается в token
        if (isdigit(token[0])) { 
            operandStack.push(stod(token)); // Помещаем операнды в стек
        }
        else {
            char op = token[0];
            if (isOperator(op)) {
                if (op == 'v') {
                    operand2 = operandStack.pop(); // Извлекаем операнды из стека
                    result = applyOperation(operand2, 0, op); // Выполняем операцию и помещаем результат в стек
                }
                else if (op == '!') {
                    operand1 = operandStack.pop(); // Извлекаем операнд из стека
                    result = applyOperation(operand1, 0, op); // Выполняем операцию и помещаем результат в стек
                }
                else {
                    operand2 = operandStack.pop(); // Извлекаем операнды из стека
                    operand1 = operandStack.pop();
                    result = applyOperation(operand1, operand2, op); // Выполняем операцию и помещаем результат в стек
                }
            }
            operandStack.push(result);
        }
    }
    return result; // Возвращаем результат
}

void assertCheckB() {
    Stack<double> operandStack;
    assert(evaluatePostfix("4 v", operandStack) == 2);
    operandStack.clear();
    assert(evaluatePostfix("4 !", operandStack) == 24);
    operandStack.clear();
    assert(evaluatePostfix("5 5 +", operandStack) == 10);
    operandStack.clear();
    assert(evaluatePostfix("5 5 -", operandStack) == 0);
    operandStack.clear();
    assert(evaluatePostfix("5 5 *", operandStack) == 25);
    operandStack.clear();
    assert(evaluatePostfix("5 5 /", operandStack) == 1);
    operandStack.clear();
    assert(evaluatePostfix("5 5 ^", operandStack) == 3125);
    operandStack.clear();

    assert(evaluatePostfix("5 5 - 5 -", operandStack) == -5);
    operandStack.clear();
    assert(evaluatePostfix("5 5 + 5 +", operandStack) == 15);
    operandStack.clear();
    assert(evaluatePostfix("5 5 * 5 *", operandStack) == 125);
    operandStack.clear();
    assert(evaluatePostfix("5 5 / 5 /", operandStack) == 0.2);
    operandStack.clear();
    assert(evaluatePostfix("5 5 ^ 5 ^", operandStack) == 298023223876953125);
    operandStack.clear();
    assert(evaluatePostfix("1296 v v", operandStack) == 6);
    operandStack.clear();
    assert(evaluatePostfix("3 ! !", operandStack) == 720);
    operandStack.clear();

    assert(evaluatePostfix("42 42 + 34 - 5 / 2 * 3 ^ 3904 - v v !", operandStack) == 40320);
    operandStack.clear();
}