#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int a, b;

    cout << "Введите длины сторон прямоугольника: ";
    cin >> a >> b;

    int P = (a + b) * 2; // периметр
    int S = a * b; // площадь
    double d = sqrt(pow(a, 2.0) + pow(b, 2.0)); // диагональ

    int choice;
    do {
        cout << "\Выберите, что вывести:" << endl;
        cout << "1. Периметр" << endl;
        cout << "2. Площадь" << endl;
        cout << "3. Диагональ" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Периметр: " << P << endl;
        }
        else if (choice == 2) {
            cout << "Площадь: " << S << endl;
        }
        else if (choice == 3) {
            cout << "Диагональ: " << d << endl;
        }
        else if (choice == 0) {
            cout << "Выход из программы" << endl;
        }
        else {
            cout << "Неверный выбор" << endl;
        }
    } while (choice != 0);

    return 0;
}
