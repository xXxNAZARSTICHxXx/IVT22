import sys
import random
import T5Module

__author__ = "Стич Назар Иванович ИВТ-22"

TASK_DESCRIPTION = """Задание 5 - 136д:
Дано натуральное число n, действительные числа a1,..., an.
Вычислить: a1^2 + ... + an^2
"""

# Проверка на аргумент "-help"
if len(sys.argv) == 2 and sys.argv[1] == "-help":
    print(TASK_DESCRIPTION)
    sys.exit(0)  # Завершаем программу после вывода справки

print(TASK_DESCRIPTION)

T5Module.assert_check()

numbers = []  # Список чисел

# Проверяем, переданы ли аргументы
if len(sys.argv) >= 3:
    if sys.argv[1] == "-random" and len(sys.argv) == 5:
        try:
            n = int(sys.argv[2])
            min_val = float(sys.argv[3])
            max_val = float(sys.argv[4])

            if n <= 0 or min_val > max_val:
                raise ValueError("Ошибка: длина массива должна быть > 0, а min <= max.")

            generator = T5Module.get_random_numbers(n, min_val, max_val)
            numbers = list(generator)  # Преобразуем генератор в список
            print(f"Сгенерированный массив: {numbers}")

        except ValueError as e:
            print(f"Ошибка: {e}")
            sys.exit(1)
    else:
        try:
            n = int(sys.argv[1])
            if n <= 0:
                raise ValueError("Число n должно быть натуральным (n > 0).")

            numbers = [float(arg) for arg in sys.argv[2:]]
            if len(numbers) != n:
                raise ValueError(f"Ошибка: ожидалось {n} чисел, но передано {len(numbers)}.")
        except ValueError as e:
            print(f"Ошибка: {e}")
            sys.exit(1)
else:
    while True:
        try:
            n = int(input("Введите количество чисел n: "))
            if n > 0:
                break
            else:
                print("Ошибка: число n должно быть натуральным (n > 0).")
        except ValueError:
            print("Ошибка: введите корректное натуральное число.")

    for i in range(n):
        while True:
            try:
                num = float(input(f"Введите число a{i+1}: "))
                numbers.append(num)
                break
            except ValueError:
                print("Ошибка: введите корректное число.")
