import sys

import T7Module

__author__ = "Стич Назар Иванович ИВТ-22"

TASK_DESCRIPTION = """Задание 7 - 334a:
Вычислить: 
∑(i=1 до n) ∑(j=1 до m) (1 / (i + j^2))
Введите количество итераций по i и j
"""



# Проверка на аргумент "-help"
if len(sys.argv) == 2 and sys.argv[1] == "-help":
    print(TASK_DESCRIPTION)
    sys.exit(0)  # Завершаем программу после вывода справки

n = m = 0  # Инициализация чисел

if len(sys.argv) == 3:
    try:
        n = int(sys.argv[1])
        m = int(sys.argv[2])
        if n < 1 or m < 1:
            raise ValueError("Числа должны быть натуральными (n, m > 0).")
    except ValueError as e:
        print(f"Ошибка: {e}")
        sys.exit(1)

elif len(sys.argv) == 6 and sys.argv[1] == "-random":
    try:
        min_n, max_n = int(sys.argv[2]), int(sys.argv[3])
        min_m, max_m = int(sys.argv[4]), int(sys.argv[5])

        generator = T7Module.generate_random_values(min_n, max_n, min_m, max_m)
        n, m = next(generator)  # Получаем первую пару значений
        print(f"Случайно сгенерированные n = {n}, m = {m}")
    except ValueError as e:
        print(f"Ошибка: {e}")
        sys.exit(1)

else:
    while True:
        try:
            n = int(input("Введите количество итераций по i (натуральное число): "))
            m = int(input("Введите количество итераций по j (натуральное число): "))
            if n > 0 and m > 0:
                break
            print("Ошибка: числа должны быть натуральными (n, m > 0).")
        except ValueError:
            print("Ошибка: введите корректные натуральные числа.")

print(TASK_DESCRIPTION)

# Вычисляем двойную сумму
result = T7Module.compute_double_sum(n, m)

# Выводим результат
print(f"Результат вычисления суммы: {result:.6f}")
