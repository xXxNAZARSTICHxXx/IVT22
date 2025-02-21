import matplotlib.pyplot as plt

# Данные для графика
measurements = [1, 2, 3, 4, 5]
seconds = [494, 570, 545, 591, 522]

# Построение графика
plt.plot(measurements, seconds, marker='o', linestyle='-')

# Добавление заголовка и подписей к осям
plt.title('График зависимости времени от измерения')
plt.xlabel('№ Измерения')
plt.ylabel('Время (секунды)')

# Отображение графика
plt.show()
