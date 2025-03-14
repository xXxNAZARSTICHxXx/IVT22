import random
from typing import Tuple, List

__author__ = "Стич Назар Иванович ИВТ-22"

def square_non_negative(x: float, y: float, z: float) -> Tuple[float, float, float]:
    """
    Возводит в квадрат только неотрицательные числа из переданных x, y, z.

    :param x: Первое число
    :param y: Второе число
    :param z: Третье число
    :return: Кортеж из трех чисел, где неотрицательные возведены в квадрат
    """
    if x >= 0:
        x = x ** 2
    if y >= 0:
        y = y ** 2
    if z >= 0:
        z = z ** 2

    return x, y, z


def print_numbers(x: float, y: float, z: float):
    """
    Выводит три числа в удобном формате.

    :param x: Первое число
    :param y: Второе число
    :param z: Третье число
    """
    print(f"Число X: {x:.4f}")
    print(f"Число Y: {y:.4f}")
    print(f"Число Z: {z:.4f}")


def generate_random_numbers(min_vals: List[float], max_vals: List[float]) -> Tuple[float, float, float]:
    """
    Генерирует три случайных числа в заданных диапазонах с 4 знаками после запятой.

    :param min_vals: Список из 3 минимальных значений
    :param max_vals: Список из 3 максимальных значений
    :return: Кортеж из трех случайных чисел
    """
    return (
        round(random.uniform(min_vals[0], max_vals[0]), 4),
        round(random.uniform(min_vals[1], max_vals[1]), 4),
        round(random.uniform(min_vals[2], max_vals[2]), 4)
    )


def assert_check():
    """
    Тесты для проверки корректности алгоритма.
    """
    assert square_non_negative(3, -1, 2) == (9, -1, 4)
    assert square_non_negative(-5, 0, 4) == (-5, 0, 16)
    assert square_non_negative(0.5, -0.7, 1.2) == (0.25, -0.7, 1.44)
    assert square_non_negative(-3, -2, -1) == (-3, -2, -1)
    assert square_non_negative(0, 0, 0) == (0, 0, 0)
