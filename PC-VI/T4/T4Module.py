import random
from typing import Generator
import math

__author__ = "Стич Назар Иванович ИВТ-22"


def compute_sum_and_factorials(n: int) -> float:
    """
    Вычисляет сумму ∑ (от i=1 до n) 1/i! и сохраняет факториалы от 1 до n.

    :param n: Количество итераций суммы выражения (включая n)
    :return: Результат вычисления суммы

    Функция объединяет вычисления суммы и предварительное сохранение факториалов.
    """
    total = 0.0
    factorial = 1  # Начальный факториал для 0! (равен 1)

    for i in range(1, n + 1):
        factorial *= i  # Вычисляем факториал на лету
        total += 1.0 / factorial  # Прибавляем 1/i!

    return total


def generate_random_iterations(count: int = 1) -> Generator[int, None, None]:
    """
    Генерирует заданное количество случайных чисел итераций от 1 до 100,
    используя генератор.

    :param count: Количество чисел (по умолчанию 1)
    :yield: Случайное число итераций в диапазоне [1, 100]
    """
    for _ in range(count):
        yield random.randint(1, 100)


def assert_check():
    """
    Проверка всех функций.
    """
    # Тесты для compute_sum_and_factorials
    assert abs(compute_sum_and_factorials(1) - 1.0) < 1e-6
    assert abs(compute_sum_and_factorials(2) - 1.5) < 1e-6
    assert abs(compute_sum_and_factorials(3) - 1.666667) < 1e-6
