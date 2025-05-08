import random
from typing import Generator

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
        print(f"Результат: {result:.4f}")  # Вывод с 4 знаками после запятой


def generate_random_numbers(count: int = 2) -> Generator[float, None, None]:
    """
    Генерирует заданное количество случайных чисел с четырьмя знаками после запятой,
    используя генератор.

    :param count: Количество чисел (по умолчанию 2)
    :yield: Случайное число с четырьмя знаками после запятой
    """
    for _ in range(count):
        yield round(random.uniform(-10, 10), 4)


def assert_check() -> None:
    """
    Тесты для проверки корректности алгоритма и генератора.
    """
    # Тесты для compute_expression
    assert compute_expression(2, 3) == 0.2
    assert compute_expression(1, -3) == 1
    assert compute_expression(-3, 1) == -1
    assert compute_expression(0, 0) == 0
    assert compute_expression(0, 5) == -5

    # Тесты для generate_random_numbers
    generator = generate_random_numbers(5)  # Генерируем 5 чисел
    numbers = list(generator)

    # Проверка количества чисел
    assert len(numbers) == 5, "Генератор не вернул правильное количество чисел."

    # Проверка диапазона чисел
    for num in numbers:
        assert -10 <= num <= 10, f"Число {num} выходит за пределы диапазона [-10, 10]."

    # Проверка точности (4 знака после запятой)
    for num in numbers:
        assert round(num, 4) == num, f"Число {num} не округлено до 4 знаков после запятой."