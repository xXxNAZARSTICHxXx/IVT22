import sys
import T4Module

__author__ = "Стич Назар Иванович ИВТ-22"

TASK_DESCRIPTION = """Задание 4 - 114в:
Вычислить сумму: ∑ (от i=1 до n) 1/i!\n
Введите количество итераций - n (количество сумм)\n"""

n = 0 # Количество итераций в сумматоре

# Проверка всех функций
T4Module.assert_check()

# Проверка на аргумент "-help"
if len(sys.argv) == 2 and sys.argv[1] == "-help":
    print(TASK_DESCRIPTION)
    sys.exit(0)  # Завершаем программу после вывода справки

# print(TASK_DESCRIPTION)

# Проверяем, передан ли аргумент
if len(sys.argv) == 2:
    try:
        n = int(sys.argv[1])
        if n < 1:
            raise ValueError
    except ValueError:
        print("Ошибка: необходимо ввести натуральное число .")
        sys.exit(1)

# Вычисляем сумму от количества итераций n
result = T4Module.compute_sum(n)

# Выводим результат
print(f"Результат вычисления суммы: {result:.6f}")
