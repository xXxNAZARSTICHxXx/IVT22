import sys
import T1Module

__author__ = "Стич Назар Иванович ИВТ-22"

TASK_DESCRIPTION = """Задание 1 - 44: 
Даны действительные числа x и y. Получить (|x| - |y|) / (1 - |x * y|)\n"""

# Проверка аргументов командной строки
if len(sys.argv) == 2 and sys.argv[1] == "-help":
    print(TASK_DESCRIPTION)
    sys.exit(0)  # Завершаем программу после вывода справки

print(TASK_DESCRIPTION)
T1Module.assert_check()

# Проверяем, переданы ли два аргумента (x и y)
if len(sys.argv) == 3:
    try:
        x = float(sys.argv[1])
        y = float(sys.argv[2])
    except ValueError:
        print("Ошибка: аргументы должны быть числами.")
        sys.exit(1)
else:
    print("Введите два числа x и y:")
    x = float(input("x: "))
    y = float(input("y: "))

# Вычисление и вывод результата
result = T1Module.compute_expression(x, y)
T1Module.print_result(result)
