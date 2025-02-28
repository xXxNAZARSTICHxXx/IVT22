from typing import Tuple

__author__ = "Стич Назар Иванович ИВТ-22"

def compute_double_sum(n, m) -> float:
    """
    Вычисляет сумму: \sum_{i=1}^{n} \sum_{j=1}^{m} \frac{1}{i + j^2}

    :return: Результат вычисления суммы
    """
    total = 0
    for i in range(1, n+1):
        for j in range(1, m+1):
            total += 1 / (i + j**2)
    return total

def assert_check():
    """
    Проверка всех функций
    """
    assert abs(compute_sum(10, 10) - 5.492241) < 1e-6
    assert abs(compute_sum(20, 10) - 8.290772) < 1e-6
    assert abs(compute_sum(20, 20) - 9.170500) < 1e-6






