import random
from typing import Generator, List

__author__ = "Стич Назар Иванович ИВТ-22"

def count_multiples_of_3_not_5(n: int, numbers: List[int]) -> int:
    """
    Определяет количество членов последовательности, которые кратны 3, но не кратны 5.

    :param n: Число элементов в списке
    :param numbers: Список из n натуральных чисел
    :return: Количество чисел, кратных 3, но не кратных 5
    """
    count = 0
    for num in numbers:
        if num % 3 == 0 and num % 5 != 0:
            count += 1
    return count


def get_random_numbers(n: int, min_val: int, max_val: int) -> Generator[int, None, None]:
    """
    Генерирует n случайных натуральных чисел в диапазоне [min_val, max_val] с использованием генератора.

    :param n: Количество чисел
    :param min_val: Минимальное значение
    :param max_val: Максимальное значение
    :yield: Случайное число из диапазона [min_val, max_val]
    """
    if n <= 0:
        raise ValueError("Число элементов должно быть больше 0.")
    if min_val > max_val:
        raise ValueError("Минимальное значение не может быть больше максимального.")

    for _ in range(n):
        yield random.randint(min_val, max_val)


def assert_check() -> None:
    """
    Тесты для проверки корректности работы функций.
    """
    # Тесты для count_multiples_of_3_not_5
    assert count_multiples_of_3_not_5(5, [3, 6, 9, 10, 15]) == 3
    assert count_multiples_of_3_not_5(6, [3, 6, 9, 10, 12, 15]) == 4
    assert count_multiples_of_3_not_5(4, [5, 10, 20, 25]) == 0
    assert count_multiples_of_3_not_5(1, [3]) == 1
    assert count_multiples_of_3_not_5(1, [30]) == 0

    # Тесты для get_random_numbers (генератор)
    generator = get_random_numbers(10, 1, 100)
    numbers = list(generator)

    # Проверка количества чисел
    assert len(numbers) == 10, "Генератор не вернул правильное количество чисел."

    # Проверка диапазона чисел
    for num in numbers:
        assert 1 <= num <= 100, f"Число {num} выходит за пределы диапазона [1, 100]."