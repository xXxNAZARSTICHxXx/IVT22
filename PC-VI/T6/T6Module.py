from typing import Tuple

__author__ = "Стич Назар Иванович ИВТ-22"

def count_multiples_of_3_not_5(n: int, numbers: list) -> int:
    """
    Определяет количество членов последовательности, которые кратны 3, но не кратны 5.

    :param n: Число элементов в списке
    :param numbers: Список из n натуральных чисел
    :return: Количество чисел, кратных 3, но не кратных 5
    """
    count = 0
    for num in numbers:
        if num % 3 == 0 and num % 5 != 0:
            count += 1
    return count


def assert_check() -> None:
    """
    Тесты для проверки корректности работы функции.
    """
    assert count_multiples_of_3_not_5(5, [3, 6, 9, 10, 15]) == 3
    assert count_multiples_of_3_not_5(6, [3, 6, 9, 10, 12, 15]) == 4
    assert count_multiples_of_3_not_5(4, [5, 10, 20, 25]) == 0
    assert count_multiples_of_3_not_5(1, [3]) == 1
    assert count_multiples_of_3_not_5(1, [30]) == 0






