import sys
import T2Module

__author__ = "Стич Назар Иванович ИВТ-22"

TASK_DESCRIPTION = """Задание 2 - 43: 
Даны три действительных числа. Возвести в квадрат те из них, значения которых неотрицательны.\n"""

# Проверка на аргумент "-help"
if len(sys.argv) == 2 and sys.argv[1] == "-help":
    print(TASK_DESCRIPTION)
    sys.exit(0)

print(TASK_DESCRIPTION)
T2Module.assert_check()

# Проверяем аргументы командной строки
if len(sys.argv) == 4:
    try:
        x = float(sys.argv[1])
        y = float(sys.argv[2])
        z = float(sys.argv[3])
    except ValueError:
        print("Ошибка: аргументы должны быть числами.")
        sys.exit(1)

elif len(sys.argv) == 2 and sys.argv[1] == "-random":
    print("Введите 6 чисел (минимум и максимум для 3 случайных чисел):")

    try:
        # Ввод 6 чисел через пробел
        nums = input("Введите 6 чисел через пробел: ").strip()
        values = list(map(float, nums.split()))

        if len(values) != 6:
            raise ValueError("Нужно ввести ровно 6 чисел.")

        # Разделение на минимумы и максимумы
        min_vals = values[0::2]  # Четные индексы (0, 2, 4) — минимумы
        max_vals = values[1::2]  # Нечетные индексы (1, 3, 5) — максимумы

        # Генерация 3 случайных чисел в указанных диапазонах
        x, y, z = T2Module.generate_random_numbers(min_vals, max_vals)

        print(f"Сгенерированные числа: {x:.4f}, {y:.4f}, {z:.4f}")

    except ValueError as e:
        print(f"Ошибка: {e}")
        sys.exit(1)

else:
    print("Введите 3 числа x, y, z:")
    x = float(input("x: "))
    y = float(input("y: "))
    z = float(input("z: "))

# Обрабатываем числа
x, y, z = T2Module.square_non_negative(x, y, z)

# Выводим результат
T2Module.print_numbers(x, y, z)
