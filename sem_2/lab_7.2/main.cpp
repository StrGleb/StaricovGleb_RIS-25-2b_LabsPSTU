#include <iostream>
#include <cstdarg>
#include <clocale>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int d = 2; d <= sqrt(x); d++)
        if (x % d == 0) return false;
    return true;
}

void prost(int k, ...) {
    va_list args;
    va_start(args, k);

    int numx = 1;

    for (int i = 0; i < k; i += 2) {
        int a = va_arg(args, int);
        int b;

        if (i + 1 < k) b = va_arg(args, int);
        else b = a;

        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }

        cout << "Интервал #" << numx << " [" << a << "; " << b << "]: ";

        bool found = false;
        for (int x = a; x <= b; x++) {
            if (isPrime(x)) {
                cout << x << " ";
                found = true;
            }
        }

        if (!found) cout << "простых нет";
        cout << endl;

        numx++;
    }

    va_end(args);
}

int main() {
    setlocale(LC_ALL, "ru");

    int a1, b1, a2, b2, a3, b3, x;

    cout << "Вызов с 3 параметрами: prost(2, A, B)\n";
    cout << "Введите A B: ";
    cin >> a1 >> b1;
    prost(2, a1, b1);

    cout << "\nВызов с 5 параметрами: prost(4, A1, B1, A2, B2)\n";
    cout << "Введите A1 B1 A2 B2: ";
    cin >> a1 >> b1 >> a2 >> b2;
    prost(4, a1, b1, a2, b2);

    cout << "\nВызов с 6 параметрами: prost(5, A1, B1, A2, B2, X)\n";
    cout << "Последний X даст интервал [X; X]\n";
    cout << "Введите A1 B1 A2 B2 X: ";
    cin >> a1 >> b1 >> a2 >> b2 >> x;
    prost(5, a1, b1, a2, b2, x);
}