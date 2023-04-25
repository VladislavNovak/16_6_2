#include <iostream>
#include <cmath> // pow

using std::cout;
using std::endl;

// Возвращает введенную пользователем цифру
int getUserDigit() {
    int input = 0;

    // Пока не будет введено нормальное число, выполняем цикл
    while (!(std::cin >> input)) {
        cout << "Error. Enter a number: ";
        // Сбрасываем коматозное состояние cin
        std::cin.clear();
        // Очищаем поток ввода
        fflush(stdin);
    }

    return input;
}

// Возвращаем количество разрядов в int
int digitCount(int digit) {
    int count = 0;
    while (digit != 0) {
        digit /= 10;
        ++count;
    }
    return count;
}

// Преобразуем int в дробную часть double
double getFractionalFromInt(int digit) {
    return digit / std::pow(10, digitCount(digit));
}

int main() {
    cout << "Enter left part: ";
    double leftPart = getUserDigit();
    cout << "Enter right part (will be converted to fractional part): ";
    double rightPart = getFractionalFromInt(getUserDigit());
    double result = leftPart + rightPart;

    printf("Result %.3f \n", result);
}
