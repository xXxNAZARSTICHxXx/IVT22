#include <iostream>
#include <string>
#include <vector>

int main() {
    setlocale(LC_ALL, "russian");
    std::string binaryString;
    int PowerUp = 2;
    int CountPowerUp = 1;
    int i;

    // Вводимая строка из 0 и 1
    std::cout << "Введите строку из 0 и 1: ";
    std::cin >> binaryString;

    // Проверка длины строки
    if (binaryString.size() == 0 || (binaryString.size() & (binaryString.size() - 1)) != 0) {
        std::cerr << "Длина строки должна быть степенью 2 и не равной нулю." << std::endl;
        return 1; // Возврат кода ошибки
    }

    // Преобразование строки в числовой ряд
    for (char& c : binaryString) {
        if (c == '0') {
            std::cout << 0 << " ";
        } else if (c == '1') {
            std::cout << 1 << " ";
        } else {
            std::cerr << "Введен некорректный символ: " << c << std::endl;
            return 1; // Возврат кода ошибки
        }
    }

    int BinaryStringSizeConst = binaryString.size();

    // Создание вектора переменных x1, x2, ..., xn
    std::vector<int> x;
    x.resize(CountPowerUp, 0); // Исправление: инициализация значений вектора нулями

    do {
        PowerUp = 2;
        CountPowerUp++;
        for (i = 1; i != CountPowerUp; i++) {
            PowerUp = PowerUp * 2;
        }
    } while (PowerUp != BinaryStringSizeConst);

    std::cout << std::endl;



    // Вывод значений переменных x1, x2, ..., xn
    std::cout << std::endl;
    if (CountPowerUp < 10){





    for (i = 0; i < CountPowerUp; i++) {
        std::cout << "x" << i + 1 << " ";
    }
    std::cout << "F";
    std::cout << std::endl;
    for (i = -1; i < CountPowerUp; i++) {
        std::cout << "---";
    }
    std::cout << std::endl;





    }
    else
    {

    for (i = 0; i < 10; i++) {
        std::cout << "x" << i + 1 << "  ";   
    }
    for (i = 10; i < CountPowerUp; i++) {
        std::cout << "x" << i + 1 << " ";   
    }
    std::cout << " " << "F";
    std::cout << std::endl;
    for (i = -1; i < CountPowerUp; i++) {
        std::cout << "----";
    }
    std::cout << std::endl;

    }
    return 0;
}
