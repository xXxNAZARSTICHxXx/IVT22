import numpy as np

__author__ = "Стич Назар Иванович ИВТ-22"


def replace_elements_with_zeros(matrix: np.ndarray, a: np.ndarray):
    """
    Заменяет нулями в матрице элементы с чётной суммой индексов,
    если они равны хотя бы одному из элементов последовательности a1, ..., a10.

    :param matrix: квадратная матрица размерности n x n (numpy.ndarray)
    :param a: массив из 10 целых чисел (numpy.ndarray)
    """
    n = matrix.shape[0]
    for i in range(n):
        for j in range(n):
            if (i + j) % 2 == 0 and matrix[i, j] in a:
                matrix[i, j] = 0


def print_matrix(matrix: np.ndarray):
    """
    Выводит матрицу в удобном формате.

    :param matrix: матрица для вывода (numpy.ndarray)
    """
    print("\n".join(" ".join(map(str, row)) for row in matrix))


# Тестирование с assert
def test_replace_elements_with_zeros():
    test_matrix = np.array([
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ])
    test_a = np.array([1, 3, 7])

    expected_output = np.array([
        [0, 2, 0],
        [4, 5, 6],
        [0, 8, 9]
    ])

    replace_elements_with_zeros(test_matrix, test_a)

    assert np.array_equal(test_matrix, expected_output), f"Ожидалось {expected_output}, но получено {test_matrix}"
    print("Тест пройден.")


if __name__ == "__main__":
    test_replace_elements_with_zeros()
