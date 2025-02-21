import sys
import T6Module

__author__ = "Стич Назар Иванович ИВТ-22"

print("Задание 6 - 178б: Даны натуральные числа n, a1...an. Определить количество членов")
print("ak последовательности a1,...,an: кратных 3 и не кратных 5\n")

T6Module.assert_check()

# Проверяем, переданы ли аргументы
if len(sys.argv) >= 3:
    try:
        n = int(sys.argv[1])
        if n <= 0:
            raise ValueError("Число n должно быть натуральным (n > 0).")

        numbers = [int(arg) for arg in sys.argv[2:]]
        if len(numbers) != n:
            raise ValueError(f"Ошибка: ожидалось {n} чисел, но передано {len(numbers)}.")
    except ValueError as e:
        print(f"Ошибка: {e}")
        sys.exit(1)

else:
    while True:
        try:
            n = int(input("Введите количество чисел n: "))
            if n > 0:
                break
            else:
                print("Ошибка: число n должно быть натуральным (n > 0).")
        except ValueError:
            print("Ошибка: введите корректное натуральное число.")

    numbers = []
    for i in range(n):
        while True:
            try:
                num = int(input(f"Введите число a{i+1}: "))
                numbers.append(num)
                break
            except ValueError:
                print("Ошибка: введите корректное целое число.")

# Вычисляем количество подходящих чисел
result = T6Module.count_multiples_of_3_not_5(n, numbers)

# Выводим результат
print(f"Количество чисел, кратных 3, но не кратных 5: {result}")
