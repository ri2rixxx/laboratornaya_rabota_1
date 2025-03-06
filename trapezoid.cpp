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

    cout << fixed << setprecision(2);
    cout << "Средняя линия: " << trap.middleLine() << endl;
    cout << "Площадь: " << trap.area() << endl;
    cout << "Периметр: " << trap.perimeter() << endl;

    return 0;
}
