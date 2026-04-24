#include <iostream>
#include <cmath>
#include <clocale>
#include <chrono>
#include <iomanip>

using namespace std;

double f(double x) {
    return acos(x) - sqrt(1 - 0.3 * x * x * x);
}

double g(double x) {
    double L = 0.5; // коэффициент
    return x + L * f(x);
}

int main() {
    setlocale(LC_ALL, "ru-RU");

    double x0 = 0.5;
    double eps = 1e-6;
    double x1;

    auto start = chrono::high_resolution_clock::now();

    while (true) {
        x1 = g(x0);

        if (fabs(x1 - x0) < eps)
            break;

        x0 = x1;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << fixed << setprecision(4);
    cout << "Корень x = " << x1 << endl;

    cout << fixed << setprecision(8);
    cout << "Время выполнения: " << elapsed.count() << " секунд" << endl;

    return 0;
}