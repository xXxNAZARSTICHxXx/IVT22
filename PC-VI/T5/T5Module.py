import random
from typing import Generator, List

__author__ = "Стич Назар Иванович ИВТ-22"


def compute_sum_of_squares(numbers: List[float]) -> float:
    """
    Вычисляет сумму квадратов чисел a1^2 + a2^2 + ... + an^2.

    :param numbers: Список действительных чисел
    :return: Сумма квадратов чисел
    """
    return sum(num ** 2 for num in numbers)


def get_random_numbers(n: int, min_val: float, max_val: float) -> Generator[float, None, None]:
    """
    Генерирует n случайных чисел в диапазоне [min_val, max_val] с использованием генератора.

    :param n: Количество чисел
    :param min_val: Минимальное значение
    :param max_val: Максимальное значение
    :yield: Случайное число из диапазона [min_val, max_val]
    """
    if n <= 0:
        raise ValueError("Число элементов должно быть больше 0.")
    if min_val > max_val:
        raise ValueError("Минимальное значение не может быть больше максимального.")

    for _ in range(n):
        yield random.uniform(min_val, max_val)


def assert_check():
    """
    Тесты для проверки корректности работы функций.
    """
    # Тесты для compute_sum_of_squares
    assert compute_sum_of_squares([1, 2, 3]) == 14
    assert compute_sum_of_squares([2.5, 3.5]) == 18.5
    assert compute_sum_of_squares([0, 1, 2, 3]) == 14
    assert compute_sum_of_squares([4]) == 16
    assert compute_sum_of_squares([5, 6]) == 61

    # Тесты для get_random_numbers (генератор)
    generator = get_random_numbers(10, 1, 100)
    numbers = list(generator)

    # Проверка количества чисел
    assert len(numbers) == 10, "Генератор не вернул правильное количество чисел."

    # Проверка диапазона чисел
    for num in numbers:
        assert 1 <= num <= 100, f"Число {num} выходит за пределы диапазона [1, 100]."