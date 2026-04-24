#include <iostream>
#include <cmath>
#include <clocale>
#include <chrono>
#include <iomanip>

using namespace std;

double f(double x) {
    return acos(x) - sqrt(1 - 0.3 * x * x * x);
}

double df(double x) {
    return -1.0 / sqrt(1 - x * x) + (0.9 * x * x) / (2 * sqrt(1 - 0.3 * x * x * x));
}

int main() {
    setlocale(LC_ALL, "ru-RU");

    double x0 = 0.5;
    double eps = 1e-6;
    double x1;

    auto start = chrono::high_resolution_clock::now();

    while (true) {

        double fx = f(x0);
        double dfx = df(x0);

        if (fabs(dfx) < eps) {
            cout << "Производная слишком мала — возможное расхождение." << endl;
            break;
        }

        x1 = x0 - fx / dfx;

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