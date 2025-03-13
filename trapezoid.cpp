#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Trapezoid {
    double a, b, c, d, h;

    double middleLine() {
        return (a + b) / 2;
    }

    double area() {
        return middleLine() * h;
    }

    double perimeter() {
        return a + b + c + d;
    }

    // Проверка существования трапеции
    bool isValid() {
        // 1. Высота должна быть меньше боковых сторон
        if (h >= c || h >= d) {
            cerr << "Ошибка: высота должна быть меньше боковых сторон!\n";
            return false;
        }

        // 2. Сумма боковых сторон должна быть больше разности оснований
        double minBase = min(a, b);
        double maxBase = max(a, b);
        double sideSum = c + d;
        double baseDiff = maxBase - minBase;

        if (sideSum <= baseDiff) {
            cerr << "Ошибка: сумма боковых сторон должна быть больше разности оснований!\n";
            return false;
        }

        // 3. Проверка, что высота не слишком маленькая при больших боковых сторонах
        // Используем теорему Герона для проверки, существует ли трапеция
        double semiPerimeter1 = (c + d + baseDiff) / 2;
        double semiPerimeter2 = (c + d + maxBase - minBase) / 2;
        
        double triangleArea1 = sqrt(semiPerimeter1 * (semiPerimeter1 - c) * (semiPerimeter1 - d) * (semiPerimeter1 - baseDiff));
        double triangleArea2 = sqrt(semiPerimeter2 * (semiPerimeter2 - c) * (semiPerimeter2 - d) * (semiPerimeter2 - (maxBase - minBase)));

        double minHeight = 2 * triangleArea1 / baseDiff;
        double altMinHeight = 2 * triangleArea2 / (maxBase - minBase);

        if (h < minHeight || h < altMinHeight) {
            cerr << "Ошибка: высота слишком мала для данных боковых сторон!\n";
            return false;
        }

        return true;
    }
};

int main() {
    Trapezoid trap;

    cout << "Введите длины оснований a и b: ";
    cin >> trap.a >> trap.b;
    if (trap.a <= 0 || trap.b <= 0) {
        cerr << "Ошибка: длины оснований должны быть положительными!\n";
        return 1;
    }

    cout << "Введите длины боковых сторон c и d: ";
    cin >> trap.c >> trap.d;
    if (trap.c <= 0 || trap.d <= 0) {
        cerr << "Ошибка: длины боковых сторон должны быть положительными!\n";
        return 1;
    }

    cout << "Введите высоту h: ";
    cin >> trap.h;
    if (trap.h <= 0) {
        cerr << "Ошибка: высота должна быть положительной!\n";
        return 1;
    }

    // Проверяем, существует ли такая трапеция
    if (!trap.isValid()) {
        return 1;
    }

    cout << fixed << setprecision(2);
    cout << "Средняя линия: " << trap.middleLine() << endl;
    cout << "Площадь: " << trap.area() << endl;
    cout << "Периметр: " << trap.perimeter() << endl;

    return 0;
}
