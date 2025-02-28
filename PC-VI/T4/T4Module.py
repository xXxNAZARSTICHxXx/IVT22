from typing import List
# массовость
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


def compute_sum(n: int) -> float:
    """
    Вычисляет сумму: \sum_{i=1}^{10} \frac{1}{i!}

    :param n: Количество итераций суммы выражения - включительно
    :return: Результат вычисления суммы
    """
    total = 0
    for i in range(1, n+1):
        total += 1 / factorial(i)
    return total

def assert_check():
    """
    Проверка всех функций
    """
    assert abs(compute_sum(1) - 1.0) < 1e-6
    assert abs(compute_sum(2) - 1.5) < 1e-6
    assert abs(compute_sum(3) - 1.666667) < 1e-6
    assert factorial(3) == 6
    assert factorial(5) == 120
    assert factorial(7) == 5040






