import sys
import T8Module

__author__ = "Стич Назар Иванович ИВТ-22"

print("Задание 8 - 674: Даны целые числа a1, ..., a10, целочисленная квадратная матрица порядка n.")
print("Заменить нулями в матрице те элементы с чётной суммой индексов, для которых имеются равные")
print("среди a1, ..., a10.\n")

# Проверяем, переданы ли аргументы
if len(sys.argv) >= 12:  # n + 10 элементов массива + n * n элементов матрицы
    try:
        # Читаем порядок матрицы n
        n = int(sys.argv[1])
        if n <= 0:
            raise ValueError("Порядок матрицы n должен быть натуральным (n > 0).")

        # Читаем массив a из 10 элементов
        a = [int(arg) for arg in sys.argv[2:12]]

        # Читаем матрицу n x n
        matrix_elements = [int(arg) for arg in sys.argv[12:]]
        if len(matrix_elements) != n * n:
            raise ValueError(f"Ожидалось {n * n} элементов матрицы, но передано {len(matrix_elements)}.")

        # Формируем матрицу n x n
        matrix = [matrix_elements[i * n:(i + 1) * n] for i in range(n)]

    except ValueError as e:
        print(f"Ошибка: {e}")
        sys.exit(1)

else:
    while True:
        try:
            n = int(input("Введите порядок матрицы n: "))
            if n > 0:
                break
            else:
                print("Ошибка: число n должно быть натуральным (n > 0).")
        except ValueError:
            print("Ошибка: введите корректное натуральное число.")

    # Ввод массива a (10 элементов)
    a = []
    for i in range(10):
        while True:
            try:
                num = int(input(f"Введите элемент a{i + 1}: "))
                a.append(num)
                break
            except ValueError:
                print("Ошибка: введите корректное целое число.")

    # Ввод матрицы n x n
    matrix = []
    for i in range(n):
        row = []
        for j in range(n):
            while True:
                try:
                    num = int(input(f"Введите элемент матрицы [{i + 1}][{j + 1}]: "))
                    row.append(num)
                    break
                except ValueError:
                    print("Ошибка: введите корректное целое число.")
        matrix.append(row)

# Выполняем замену элементов
T8Module.replace_elements_with_zeros(matrix, a, n)

# Вывод результата
print("\nРезультат замены:")
T8Module.print_matrix(matrix)
