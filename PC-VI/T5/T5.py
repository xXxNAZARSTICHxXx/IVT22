import sys
import T5Module

__author__ = "Стич Назар Иванович ИВТ-22"

print("Задание 5 - 136д: Дано натуральное число n, действительные числа a1,..., an. Вычислить: a1^2 + ... + an^2\n")

T5Module.assert_check()

# Проверяем, переданы ли аргументы
if len(sys.argv) >= 3:
    try:
        n = int(sys.argv[1])
        if n <= 0:
            raise ValueError("Число n должно быть натуральным (n > 0).")

        numbers = [float(arg) for arg in sys.argv[2:]]
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
                num = float(input(f"Введите число a{i+1}: "))
                numbers.append(num)
                break
            except ValueError:
                print("Ошибка: введите корректное число.")

# Вычисляем сумму квадратов
result = T5Module.compute_sum_of_squares(n, numbers)

# Выводим результат
print(f"Сумма квадратов чисел: {result:.6f}")
