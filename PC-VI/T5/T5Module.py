import random
from typing import List

__author__ = "Стич Назар Иванович ИВТ-22"


def compute_sum_of_squares(numbers: List[float]) -> float:
    """
    Вычисляет сумму квадратов чисел a1^2 + a2^2 + ... + an^2.

    :param numbers: Список действительных чисел
    :return: Сумма квадратов чисел
    """
    return sum(num ** 2 for num in numbers)


def get_random_numbers(n: int, min_val: float, max_val: float) -> List[float]:
    """
    Генерирует список из n случайных чисел в диапазоне [min_val, max_val].

    :param n: Количество чисел
    :param min_val: Минимальное значение
    :param max_val: Максимальное значение
    :return: Список случайных чисел
    """
    if n <= 0:
        raise ValueError("Число элементов должно быть больше 0.")
    if min_val > max_val:
        raise ValueError("Минимальное значение не может быть больше максимального.")

    return [random.uniform(min_val, max_val) for _ in range(n)]


def assert_check():
    """
    Тесты для проверки корректности работы функций.
    """
    assert compute_sum_of_squares([1, 2, 3]) == 14
    assert compute_sum_of_squares([2.5, 3.5]) == 18.5
    assert compute_sum_of_squares([0, 1, 2, 3]) == 14
    assert compute_sum_of_squares([4]) == 16
    assert compute_sum_of_squares([5, 6]) == 61

    random_numbers = get_random_numbers(10, 1, 100)
    assert len(random_numbers) == 10
    assert all(1 <= x <= 100 for x in random_numbers)
