from typing import Tuple

__author__ = "Стич Назар Иванович ИВТ-22"

def replace_elements_with_zeros(matrix: list, a: list, n: int):
    """
    Заменяет нулями в матрице элементы с чётной суммой индексов,
    если они равны хотя бы одному из элементов последовательности a1, ..., a10.

    :param matrix: квадратная матрица размерности n x n
    :param a: последовательность из 10 целых чисел
    :param n: порядок матрицы (n x n)
    """
    for i in range(n):
        for j in range(n):
            # Если сумма индексов чётная и элемент в матрице равен хотя бы одному из элементов a
            if (i + j) % 2 == 0 and matrix[i][j] in a:
                matrix[i][j] = 0


def print_matrix(matrix: list):
    """
    Выводит матрицу в удобном формате.

    :param matrix: матрица для вывода
    """
    for row in matrix:
        print(" ".join(map(str, row)))

