#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
#include "T10Module.cpp"

using namespace std;

// factorial - ������� ������ ���������� �����
//
unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;
    for (unsigned int i = 2; i <= n; i++) {
        result *= i; // ����������� ��������� �� ����� �� 2 �� n
    }
    return result;
}

// isOperator - �������� �� ��������
//
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == 'v' || ch == '!';
}

// isOperand - �������� �� �������
//
bool isOperand(char ch) {
    return isdigit(ch);
}

// applyOperation - ������� ��� ���������� ��������
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
            throw invalid_argument("������� �� ����");
        return operand1 / operand2;
    case '^':
        return pow(operand1, operand2);
    case 'v':
        return sqrt(operand1);
    case '!':
        return factorial(operand1);
    default:
        throw invalid_argument("�������� ��������");
    }
}

// evaluatePostfix - ���������� �������� � ����������� ���������
// expression - ���������
// operandStack - ���� ���������
double evaluatePostfix(const string& expression, Stack<double>& operandStack) {
    stringstream ss(expression); //stringstream ss(expression) - ��������� ������ stringstream(����� �������� ������) � ������ ss, ������� ������������ ��� ������ �� ������ expression
    string token; //��� ������, ������� ���������� ������� ss, ������� ������ �����(������������) ��� ������ - �������� ~ ��������� ��������� ��������� ����� ���������� � ����������� "2 4 +"
    double result = 0.0; // ������������� ���������� ��� ����������
    double operand1, operand2;
    while (ss >> token) {  //���������� ����, ������� ������������ �� ��� ���, ���� ������ stringstream ss ����� ������� ������� �� ������ expression � �������� �� � ���������� token
        //todo ��� ������������ � token
        if (isdigit(token[0])) { 
            operandStack.push(stod(token)); // �������� �������� � ����
        }
        else {
            char op = token[0];
            if (isOperator(op)) {
                if (op == 'v') {
                    operand2 = operandStack.pop(); // ��������� �������� �� �����
                    result = applyOperation(operand2, 0, op); // ��������� �������� � �������� ��������� � ����
                }
                else if (op == '!') {
                    operand1 = operandStack.pop(); // ��������� ������� �� �����
                    result = applyOperation(operand1, 0, op); // ��������� �������� � �������� ��������� � ����
                }
                else {
                    operand2 = operandStack.pop(); // ��������� �������� �� �����
                    operand1 = operandStack.pop();
                    result = applyOperation(operand1, operand2, op); // ��������� �������� � �������� ��������� � ����
                }
            }
            operandStack.push(result);
        }
    }
    return result; // ���������� ���������
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