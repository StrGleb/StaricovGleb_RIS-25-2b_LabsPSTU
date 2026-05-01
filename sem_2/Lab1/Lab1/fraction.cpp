#include "fraction.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void fraction::Init(int f, double s) {
    if (f <= 0) {
        cout << "Celaya chast dolzhna byt > 0\n";
        exit(1);
    }

    if (s <= 0 || s >= 1) {
        cout << "Drobnaya chast dolzhna byt v diapazone (0,1)\n";
        exit(1);
    }

    first = f;
    second = s;
}

void fraction::Read() {
    int f;
    double s;

    cout << "Vvedite celuyu chast chisla: ";
    cin >> f;

    cout << "Vvedite drobnuyu chast chisla: ";
    cin >> s;

    Init(f, s);
}

void fraction::Show() {
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
}

double fraction::multiply(double k) {
    return (first + second) * k;
}