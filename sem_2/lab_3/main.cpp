#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

double step(int k, int n, double x, double t) {

    if (k > n) return 0;

    double next = t;

    if (k < n) {
        int kk = k + 1;
        next = t * x * x / ((2.0 * kk) * (2.0 * kk - 1.0));
    }
    return t + step(k + 1, n, x, next);
}

int main() {
    setlocale(LC_ALL, "ru");

    double x;
    const int n = 10;
    cout << "Введите x: ";
    cin >> x;

    double sum = step(0, n, x, 1.0);
    double y = (exp(x) + exp(-x)) / 2.0;

    cout << "X = " << x << endl;
    cout << "S = " << sum << endl;
    cout << "Y = " << y << endl;

    return 0;
}