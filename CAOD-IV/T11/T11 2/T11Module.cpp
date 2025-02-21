#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
//#include <ntdill.h>
#include "T10Module.cpp"

using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isOperand(char ch) {
    return isdigit(ch);
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

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
    default:
        throw invalid_argument("Неверная операция");
    }
}

double evaluateExpression(const string& token, Stack<double>& operandStack) {
    string op;
    if (token == "+" || token == "-" || token == "*" || token == "/") {
        op = token;
    }
    else {
        throw invalid_argument("Неверная операция");
    }

    double operand2 = operandStack.pop();
    double operand1 = operandStack.pop();

    if (op == "+") {
        return operand1 + operand2;
    }
    else if (op == "-") {
        return operand1 - operand2;
    }
    else if (op == "*") {
        return operand1 * operand2;
    }
    else if (op == "/") {
        if (operand2 == 0)
            throw invalid_argument("Деление на ноль");
        return operand1 / operand2;
    }

    throw invalid_argument("Неверная операция");
}

size_t countSymbols(const string& expression) {
    size_t count = 0;
    for (char ch : expression) {
        if (!isspace(ch)) {
            ++count;
        }
    }
    return count;
}

double evaluatePostfix(const string& expression, Stack<double>& operandStack) {
    stringstream ss(expression);
    string token;
    double result = 0.0; // Инициализируем переменную для хранения результата
    double operand2;
    double operand1;
    while (ss >> token) {
        if (isdigit(token[0])) {
            operandStack.push(stod(token)); // Преобразуем строку с числом в double и помещаем его в стек
        }
        else if (isOperator(token[0])) {
            if (result != 0) {
                operand2 = result;
            }
            else {
                operand1 = operandStack.pop();
            }
            operand2 = operandStack.pop();
            char op = token[0];
            result = applyOperation(operand1, operand2, op);
            operandStack.push(result); // Помещаем результат вычисления обратно в стек
        }
    }
    return result; // Возвращаем сохраненный результат
}

void assertCheckB() {
    Stack<int> stack;
    assert(stack.isEmpty());
    stack.push(5);
    stack.push(10);
    stack.push(15);
    assert(!stack.isEmpty());
    assert(stack.peek() == 15);
    assert(stack.pop() == 15);
    assert(stack.pop() == 10);
    assert(stack.pop() == 5);
    assert(stack.isEmpty());
    stack.push(20);
    stack.push(25);
    stack.clear();
    assert(stack.isEmpty());

    Stack<double> operandStack;
    assert(evaluatePostfix("5 5 +", operandStack) == 10);
    operandStack.clear();
    assert(evaluatePostfix("5 5 5 + *", operandStack) == 50);
    operandStack.clear();

}