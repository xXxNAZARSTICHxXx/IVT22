import numpy as np

__author__ = "Стич Назар Иванович ИВТ-22"


def generate_matrix_and_array(n: int):
    """
    Генерирует случайную квадратную матрицу n x n и массив из 10 случайных чисел.

    :param n: Порядок матрицы (натуральное число)
    :return: Кортеж (матрица, массив)
    """
    matrix = np.random.randint(-10, 10, (n, n))  # Матрица со случайными числами от -10 до 10
    a = np.random.randint(-10, 10, 10)  # Массив из 10 случайных чисел
    return matrix, a


def replace_elements_with_zeros(matrix: np.ndarray, a: np.ndarray):
    """
    Заменяет нулями в матрице элементы с чётной суммой индексов,
    если они равны хотя бы одному из элементов последовательности a1, ..., a10.

    :param matrix: квадратная матрица размерности n x n (numpy.ndarray)
    :param a: массив из 10 целых чисел (numpy.ndarray)
    """
    n = matrix.shape[0]

    # Создаём булеву маску для элементов, у которых сумма индексов чётная
    even_index_mask = (np.arange(n)[:, None] + np.arange(n)) % 2 == 0

    # Создаём маску, проверяющую, содержится ли элемент в массиве a
    value_mask = np.isin(matrix, a)

    # Итоговая маска: где обе маски True, заменяем на 0
    matrix[even_index_mask & value_mask] = 0



def print_matrix(matrix: np.ndarray):
    """
    Выводит матрицу в удобном формате.

    :param matrix: матрица для вывода (numpy.ndarray)
    """
    print("\n".join(" ".join(map(str, row)) for row in matrix))
