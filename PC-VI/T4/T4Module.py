from typing import List

__author__ = "Стич Назар Иванович ИВТ-22"

def factorial(n: int) -> int:
    """
    Вычисляет факториал числа n.

    :param n: Число для вычисления факториала
    :return: Факториал числа n
    """
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result


def compute_sum() -> float:
    """
    Вычисляет сумму: \sum_{i=1}^{10} \frac{1}{i!}

    :return: Результат вычисления суммы
    """
    total = 0
    for i in range(1, 11):
        total += 1 / factorial(i)
    return total






