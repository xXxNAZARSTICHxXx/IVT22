import random

__author__ = "Стич Назар Иванович ИВТ-22"

def compute_double_sum(n: int, m: int) -> float:
    """
    Вычисляет сумму: ∑_{i=1}^{n} ∑_{j=1}^{m} (1 / (i + j^2))

    :param n: Число итераций по i
    :param m: Число итераций по j
    :return: Результат вычисления суммы
    """
    total = 0
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            total += 1 / (i + j**2)
    return total

def generate_random_values(min_n: int, max_n: int, min_m: int, max_m: int) -> tuple:
    """
    Генерирует случайные значения n и m в заданных диапазонах.

    :param min_n: Минимальное значение для n
    :param max_n: Максимальное значение для n
    :param min_m: Минимальное значение для m
    :param max_m: Максимальное значение для m
    :return: Кортеж (n, m) с случайными значениями
    """
    if min_n < 1 or max_n < min_n or min_m < 1 or max_m < min_m:
        raise ValueError("Диапазоны должны быть корректными и натуральными.")

    n = random.randint(min_n, max_n)
    m = random.randint(min_m, max_m)
    return n, m

def assert_check():
    """
    Проверка работы функции compute_double_sum.
    """
    assert abs(compute_double_sum(10, 10) - 5.492241) < 1e-6
    assert abs(compute_double_sum(20, 10) - 8.290772) < 1e-6
    assert abs(compute_double_sum(20, 20) - 9.170500) < 1e-6
