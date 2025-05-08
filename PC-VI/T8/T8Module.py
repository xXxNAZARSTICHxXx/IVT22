import numpy as np
from typing import Generator, Tuple

__author__ = "Стич Назар Иванович ИВТ-22"

#todo 139 / todo
def generate_matrix_and_array(count: int = 1) -> Generator[Tuple[np.ndarray, np.ndarray], None, None]:
    """
    Генерирует случайные квадратные матрицы n x n и массивы из 10 случайных чисел с использованием генератора.

    :param count: Количество пар (матрица, массив) для генерации (по умолчанию 1)
    :yield: Кортеж (матрица, массив)
    """
    for _ in range(count):  # Итерируем по количеству генераций
        # Генерируем случайную квадратную матрицу размером n x n, где n от 2 до 5
        # Также генерируем массив из 10 случайных чисел от -10 до 10
        yield np.random.randint(-10, 10, (np.random.randint(2, 6), np.random.randint(2, 6))), np.random.randint(-10, 10, 10)


def replace_elements_with_zeros(matrix: np.ndarray, a: np.ndarray):
    """
    Заменяет нулями в матрице элементы с чётной суммой индексов,
    если они равны хотя бы одному из элементов последовательности a1, ..., a10.

    :param matrix: квадратная матрица размерности n x n (numpy.ndarray)
    :param a: массив из 10 целых чисел (numpy.ndarray)
    """
    n = matrix.shape[0]

    # Создаём булеву маску для элементов, у которых сумма индексов чётная

    # np.arange - функция из библиотеки numpy, которая создаёт массив (если взять диапазон от 0, до 10, шаг по умолчанию единица, создастя массив от 0 до 9)
    # чисел в заданном диапазоне с определённым шагом - четным - [:, None], нужен для того,
    # чтобы складывать двумерный массив с одномерным

    #todo смысл

    # np.arange(n)[:, None] - Матрица из одного столбца (как массив, но матрица)
    # np.arange(n) - Просто массив
    # % 2 == 0 - условие ЧЕТНЫХ элементов
    # Получится матрица из false и true - маска
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


def assert_check():
    """
    Проверка работы функций модуля.
    """
    # Тест 1: Генерация матрицы и массива
    generator = generate_matrix_and_array(count=1)
    matrix, a = next(generator)

    assert matrix.shape[0] == matrix.shape[1], "Матрица должна быть квадратной."
    assert len(a) == 10, "Массив должен содержать ровно 10 элементов."

    # Тест 2: Замена элементов в матрице
    test_matrix = np.array([[3, 7, -2], [1, 0, 4], [5, -6, 8]])
    test_a = np.array([-2, 4, 0, 7, 1, -6, 3, 5, 8, 9])

    replace_elements_with_zeros(test_matrix, test_a)

    expected_matrix = np.array([[0, 7, 0], [1, 0, 0], [5, -6, 0]])
    assert np.array_equal(test_matrix, expected_matrix), "Замена элементов в матрице работает некорректно."

    print("Все тесты пройдены успешно!")