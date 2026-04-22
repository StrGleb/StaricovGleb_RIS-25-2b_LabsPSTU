#include <iostream>
#include <clocale>
#include <cstdarg>
using namespace std;

int circuit(double R, int count, ...) {
    va_list args;
    va_start(args, count);

    int k = 0;

    for (int i = 0; i < count; i++) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);

        if (x * x + y * y == R * R)
            k++;
    }

    va_end(args);
    return k;
}

int main() {
    setlocale(LC_ALL, "ru");
    double R = 5;

    cout << "Количество точек: "
        << circuit(R, 3,
            3, 4,
            5, 0,
            1, 1)
        << endl;

    cout << "Количество точек: "
        << circuit(R, 5,
            3, 4,
            0, 5,
            -3, -4,
            2, 2,
            4, 3)
        << endl;

    cout << "Количество точек: "
        << circuit(R, 2,
            1, 2,
            2, 1)
        << endl;
}