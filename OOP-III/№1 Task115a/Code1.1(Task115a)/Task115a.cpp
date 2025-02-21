#include <iostream>                         //Подключение библиотеки C++
#include <cassert>							//Подколючение проверки assert
#include "calccycleName.h"					//Подключение своей "библиотеки" модуля

using namespace std;                        //Использование основных инструментов std

//115а Дано натуральное число n. Вычислить: Сумма всех дробей циклом [1..n] 1/n

int main(int argc, char* argv[])									//Главная функция
{ 
assert (FractionCounter(2)==1.5);                 //Делаем проверку через assert на ввод числа 2
assert (1.833332<FractionCounter(3)<1.833334);  //Делаем проверку через assert на ввод числа 3
assert (2.283332<FractionCounter(5)<2.283334);  //Делаем проверку через assert на ввод числа 5                                                                                      
cout << "The sum of all fractions by a cycle: [1..n] 1/n = " << FractionCounter(atoi(argv[1])) << endl; 	//Вывод результата на экран и вычисление его через другой модуль
return 0; 									//Возврат нуля - int main функция
}


