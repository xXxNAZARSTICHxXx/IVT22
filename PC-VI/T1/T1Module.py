from typing import Tuple

__author__ = "Стич Назар Иванович ИВТ-22"

def compute_expression(x: float, y: float) -> float:
    """
    Вычисляет значение выражения (|x| - |y|) / (1 - |x * y|).

    :param x: Первое число
    :param y: Второе число
    :return: Результат вычисления
    """
    a = abs(x) - abs(y)
    b = 1 - abs(x * y)

    return a / b if b != 0 else float('inf')


def print_result(result: float) -> None:
    """
    Выводит результат вычисления выражения.

    :param result: Результат вычисления
    """
    if result == float('inf'):
        print("Ошибка: деление на ноль.")
    else:
        print(f"Результат: {result:.2f}")


def assert_check() -> None:
    """
    Тесты для проверки корректности алгоритма.
    """
    assert compute_expression(2, 3) == 0.2
    assert compute_expression(1, -3) == 1
    assert compute_expression(-3, 1) == -1
    assert compute_expression(0, 0) == 0
    assert compute_expression(0, 5) == -5
