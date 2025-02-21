from typing import Tuple

__author__ = "Стич Назар Иванович ИВТ-22"


def get_hundreds_digit(n: int) -> int:
    """
    Определяет цифру сотен в числе n.

    :param n: Натуральное число, n > 99
    :return: Цифра сотен
    """

    n = n // 100

    return n % 10


def assert_check():
    """
    Тесты для проверки корректности работы функции.
    """
    assert get_hundreds_digit(123) == 1
    assert get_hundreds_digit(4567) == 5
    assert get_hundreds_digit(98765) == 7




