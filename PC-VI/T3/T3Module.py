import random
from typing import Tuple

__author__ = "Стич Назар Иванович ИВТ-22"


def get_hundreds_digit(n: int) -> int:
    """
    Определяет цифру сотен в числе n.

    :param n: Натуральное число, n > 99
    :return: Цифра сотен
    """
    return (n // 100) % 10


def generate_random_number() -> int:
    """
    Генерирует случайное натуральное число от 100 до 10 000 000.

    :return: Случайное число в указанном диапазоне
    """
    return random.randint(100, 10_000_000)


def assert_check():
    """
    Тесты для проверки корректности работы функций.
    """
    assert get_hundreds_digit(123) == 1
    assert get_hundreds_digit(4567) == 5
    assert get_hundreds_digit(98765) == 7
    assert 100 <= generate_random_number() <= 10_000_000
