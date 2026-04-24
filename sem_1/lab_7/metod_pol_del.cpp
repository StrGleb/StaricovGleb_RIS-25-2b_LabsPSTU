#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>
#include <chrono>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU");

    double a = 0.0, b = 1.0;
    double eps = 1e-6;
    double x;

    auto start = chrono::high_resolution_clock::now();

    while (abs(b - a) > eps) {
        x = (a + b) / 2.0;

        double f = acos(x) - sqrt(1 - 0.3 * x * x * x);

        if (f == 0.0) break;

        if ((acos(a) - sqrt(1 - 0.3 * a * a * a)) * f < 0)
            b = x;
        else
            a = x;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << fixed << setprecision(4);
    cout << "Корень x = " << (a + b) / 2.0 << endl;

    cout << fixed << setprecision(8);
    cout << "Время выполнения: " << elapsed.count() << " секунд" << endl;

    return 0;
}