import sys
import T1Module

__author__ = "Стич Назар Иванович ИВТ-22"

print("Задание 1 - 44: Даны действительные числа x и y. Получить (|x| - |y|) / (1 - |x * y|)\n")

T1Module.assert_check()

# Проверяем, были ли переданы аргументы
if len(sys.argv) == 3:
    try:
        x = float(sys.argv[1])
        y = float(sys.argv[2])
    except ValueError:
        print("Ошибка: аргументы должны быть числами.")
        sys.exit(1)  # Завершаем программу с кодом ошибки
else:
    print("Введите два числа x и y:")
    x = float(input("x: "))
    y = float(input("y: "))

result = T1Module.compute_expression(x, y)
T1Module.print_result(result)
