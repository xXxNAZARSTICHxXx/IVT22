import sys
import T7Module
#Массовость
__author__ = "Стич Назар Иванович ИВТ-22"

TASK_DESCRIPTION = """Задание 7 - 334a:
Вычислить: 
∑(i=1 до n) ∑(j=1 до m) (1 / (i + j^2))
Введите количество итераций по i и j
"""

# Проверка на аргумент "-help"
if len(sys.argv) == 2 and sys.argv[1] == "-help":
    print(TASK_DESCRIPTION)
    sys.exit(0)  # Завершаем программу после вывода справки


n = m = 0 # Инициализация чисел

if len(sys.argv) == 3:
    try:
        n = int(sys.argv[1])
        if n < 1:
            raise ValueError
        m = int(sys.argv[2])
        if m < 1:
            raise ValueError
    except ValueError:
        print("Ошибка: необходимо ввести натуральные числа .")
        sys.exit(1)

print(TASK_DESCRIPTION)

# Вычисляем двойную сумму
result = T7Module.compute_double_sum(n, m)

# Выводим результат
print(f"Результат вычисления суммы: {result:.6f}")
