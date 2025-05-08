import random
from typing import Generator

__author__ = "Стич Назар Иванович ИВТ-22"


def get_hundreds_digit(n: int) -> int:
    """
    Определяет цифру сотен в числе n.

    :param n: Натуральное число, n > 99
    :return: Цифра сотен
    """
    return (n // 100) % 10


def generate_random_numbers(count: int = 1) -> Generator[int, None, None]:
    """
    Генерирует заданное количество случайных натуральных чисел от 100 до 10 000 000,
    используя генератор.

    :param count: Количество чисел (по умолчанию 1)
    :yield: Случайное число в диапазоне [100, 10_000_000]
    """
    for _ in range(count):
        yield random.randint(100, 10_000_000)


def assert_check():
    """
    Тесты для проверки корректности работы функций.
    """
    # Тесты для get_hundreds_digit
    assert get_hundreds_digit(123) == 1
    assert get_hundreds_digit(4567) == 5
    assert get_hundreds_digit(98765) == 7

    # Тесты для generate_random_numbers
    generator = generate_random_numbers(5)  # Генерируем 5 чисел
    numbers = list(generator)

    # Проверка количества чисел
    assert len(numbers) == 5, "Генератор не вернул правильное количество чисел."

    # Проверка диапазона чисел
    for num in numbers:
        assert 100 <= num <= 10_000_000, f"Число {num} выходит за пределы диапазона [100, 10_000_000]."