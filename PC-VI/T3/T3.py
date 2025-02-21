import sys
import T3Module

__author__ = "Стич Назар Иванович ИВТ-22"

print("Задание 3 - 64: Дано натуральное число n (n > 99). Определить число сотен в нем\n")

T3Module.assert_check()

# Проверяем, передан ли аргумент
if len(sys.argv) == 2:
    try:
        n = int(sys.argv[1])
        if n <= 99:
            raise ValueError
    except ValueError:
        print("Ошибка: необходимо ввести натуральное число больше 99.")
        sys.exit(1)
else:
    while True:
        try:
            n = int(input("Введите число n (n > 99): "))
            if n > 99:
                break
            else:
                print("Ошибка: число должно быть больше 99.")
        except ValueError:
            print("Ошибка: введите корректное натуральное число.")

# Получаем цифру сотен
hundreds_digit = T3Module.get_hundreds_digit(n)

# Выводим результат
print(f"Цифра сотен в числе {n}: {hundreds_digit}")
