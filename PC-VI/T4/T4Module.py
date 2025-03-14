import random
from typing import List

__author__ = "Стич Назар Иванович ИВТ-22"




def compute_sum(n: int) -> float:
    """
    Вычисляет сумму: ∑ (от i=1 до n) 1/i!, используя предвычисленные факториалы.

    :param n: Количество итераций суммы выражения - включительно
    :return: Результат вычисления суммы
    """
    factorials = precompute_factorials(n)
    total = sum(1 / factorials[i] for i in range(1, n + 1))
    return total

# факториал не вычислять постоянно, а где-то хранить TODO

def precompute_factorials(n: int) -> List[int]:
    """
    Вычисляет и сохраняет факториалы от 0 до n.

    :param n: Верхняя граница вычисления факториалов
    :return: Список факториалов от 0! до n!
    """
    factorials = [1] * (n + 1)
    for i in range(2, n + 1):
        factorials[i] = factorials[i - 1] * i
    return factorials

def generate_random_iterations() -> int:
    """
    Генерирует случайное количество итераций от 1 до 100.

    :return: Случайное число итераций
    """
    return random.randint(1, 100)


def assert_check():
    """
    Проверка всех функций
    """
    assert abs(compute_sum(1) - 1.0) < 1e-6
    assert abs(compute_sum(2) - 1.5) < 1e-6
    assert abs(compute_sum(3) - 1.666667) < 1e-6
    assert 1 <= generate_random_iterations() <= 100
