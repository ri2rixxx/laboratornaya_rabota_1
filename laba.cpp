#include <iostream>
#include <cmath>

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

int main() 
{
    Trapezoid trap;

    cout << "Введите длины оснований a и b: ";
    cin >> trap.a >> trap.b;
    
    cout << "Введите длины боковых сторон c и d: ";
    cin >> trap.c >> trap.d;

    cout << "Введите высоту h: ";
    cin >> trap.h;

    cout << "Средняя линия: " << trap.middleLine() << endl;
    cout << "Площадь: " << trap.area() << endl;
    cout << "Периметр: " << trap.perimeter() << endl;

    return 0;
}
