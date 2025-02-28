import sys
import T2Module

__author__ = "Стич Назар Иванович ИВТ-22"

TASK_DESCRIPTION = """Задание 2 - 43: 
Даны три действительных числа. Возвести в квадрат те из них, значения которых неотрицательны.\n"""

# Проверка на аргумент "-help"
if len(sys.argv) == 2 and sys.argv[1] == "-help":
    print(TASK_DESCRIPTION)
    sys.exit(0)  # Завершаем программу после вывода справки

print(TASK_DESCRIPTION)
T2Module.assert_check()

# Проверяем, переданы ли три аргумента (x, y, z)
if len(sys.argv) == 4:
    try:
        x = float(sys.argv[1])
        y = float(sys.argv[2])
        z = float(sys.argv[3])
    except ValueError:
        print("Ошибка: аргументы должны быть числами.")
        sys.exit(1)  # Завершаем программу с кодом ошибки
else:
    print("Введите 3 числа x, y, z:")
    x = float(input("x: "))
    y = float(input("y: "))
    z = float(input("z: "))

# Обрабатываем числа
x, y, z = T2Module.square_non_negative(x, y, z)

# Выводим результат
T2Module.print_numbers(x, y, z)
