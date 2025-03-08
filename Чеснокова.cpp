#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int a, b;

    cout << "������� ����� ������ ��������������: ";
    cin >> a >> b;

    int P = (a + b) * 2; // ��������
    int S = a * b; // �������
    double d = sqrt(pow(a, 2.0) + pow(b, 2.0)); // ���������

    int choice;
    do {
        cout << "\n��������, ��� �������:" << endl;
        cout << "1. ��������" << endl;
        cout << "2. �������" << endl;
        cout << "3. ���������" << endl;
        cout << "0. �����" << endl;
        cout << "��� �����: ";
        cin >> choice;

        if (choice == 1) {
            cout << "��������: " << P << endl;
        }
        else if (choice == 2) {
            cout << "�������: " << S << endl;
        }
        else if (choice == 3) {
            cout << "���������: " << d << endl;
        }
        else if (choice == 0) {
            cout << "����� �� ���������" << endl;
        }
        else {
            cout << "�������� �����" << endl;
        }
    } while (choice != 0);

    return 0;
}