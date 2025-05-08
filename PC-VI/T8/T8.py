import sys
import numpy as np
import T8Module

__author__ = "Стич Назар Иванович ИВТ-22"

TASK_DESCRIPTION = """Задание 8 - 674:
Даны целые числа a1, ..., a10 и целочисленная квадратная матрица порядка n.
Заменить нулями в матрице те элементы с чётной суммой индексов, 
для которых имеются равные среди a1, ..., a10.
"""

# Проверка на аргумент "-help"
if len(sys.argv) == 2 and sys.argv[1] == "-help":
    print(TASK_DESCRIPTION)
    sys.exit(0)

print(TASK_DESCRIPTION)

# Проверка работы функций модуля
T8Module.assert_check()

# Проверяем, переданы ли аргументы через командную строку
if len(sys.argv) >= 12:
    try:
        n = int(sys.argv[1])
        if n <= 0:
            raise ValueError("Порядок матрицы n должен быть натуральным (n > 0).")

        a = np.array([int(arg) for arg in sys.argv[2:12]])
        matrix_elements = np.array([int(arg) for arg in sys.argv[12:]])

        if matrix_elements.size != n * n:
            raise ValueError(f"Ошибка: ожидалось {n * n} элементов матрицы, но передано {matrix_elements.size}.")

        matrix = matrix_elements.reshape(n, n)

    except ValueError as e:
        print(f"Ошибка: {e}")
        sys.exit(1)

else:
    while True:
        try:
            n = int(input("Введите порядок матрицы n: "))
            if n > 0:
                break
            print("Ошибка: число n должно быть натуральным (n > 0).")
        except ValueError:
            print("Ошибка: введите корректное натуральное число.")

    # Генерируем случайную матрицу и массив с использованием генератора
    generator = T8Module.generate_matrix_and_array(count=1)
    matrix, a = next(generator)

    print("\nСгенерированная матрица:")
    T8Module.print_matrix(matrix)

    print("\nСгенерированный массив a:")
    print(" ".join(map(str, a)))

# Выполняем замену элементов
T8Module.replace_elements_with_zeros(matrix, a)

# Вывод результата
print("\nРезультат замены:")
T8Module.print_matrix(matrix)
