from typing import Tuple

__author__ = "Стич Назар Иванович ИВТ-22"

def compute_double_sum() -> float:
    """
    Вычисляет сумму: \sum_{i=1}^{100} \sum_{j=1}^{50} \frac{1}{i + j^2}

    :return: Результат вычисления суммы
    """
    total = 0
    for i in range(1, 101):
        for j in range(1, 51):
            total += 1 / (i + j**2)
    return total






