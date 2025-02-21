def compute_sum_of_squares(n: int, numbers: list) -> float:
    """
    Вычисляет сумму квадратов чисел a1^2 + a2^2 + ... + an^2.

    :param n: Число элементов в списке
    :param numbers: Список из n действительных чисел
    :return: Сумма квадратов чисел
    """
    total = 0
    for num in numbers:
        total += num ** 2  # Добавляем квадрат текущего числа
    return total


def assert_check():
    """
    Тесты для проверки корректности работы функции compute_sum_of_squares.
    """
    # Тест 1: 1^2 + 2^2 + 3^2 = 1 + 4 + 9 = 14
    assert compute_sum_of_squares(3, [1, 2, 3]) == 14
    # Тест 2: 2.5^2 + 3.5^2 = 6.25 + 12.25 = 18.5
    assert compute_sum_of_squares(2, [2.5, 3.5]) == 18.5
    # Тест 3: 0^2 + 1^2 + 2^2 + 3^2 = 0 + 1 + 4 + 9 = 14
    assert compute_sum_of_squares(4, [0, 1, 2, 3]) == 14
    # Тест 4: 4^2 = 16
    assert compute_sum_of_squares(1, [4]) == 16
    # Тест 5: 5^2 + 6^2 = 25 + 36 = 61
    assert compute_sum_of_squares(2, [5, 6]) == 61