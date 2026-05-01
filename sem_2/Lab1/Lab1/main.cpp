#include "fraction.h"
#include <iostream>

using namespace std;

fraction make_fraction(int f, double s) {
    fraction t;
    t.Init(f, s);
    return t;
}

int main() {
    fraction A, B;
    A.Init(3, 0.5);
    B.Read();

    A.Show();
    B.Show();

    double k;
    cout << "Vvedite k: ";
    cin >> k;

    cout << "A = " << A.multiply(k) << endl;
    cout << "B = " << B.multiply(k) << endl;

    fraction* X = new fraction;
    X->Init(2, 0.3);
    cout << "X = " << X->multiply(k) << endl;
    delete X;

    fraction arr[2];
    arr[0].Init(1, 0.2);
    arr[1].Init(2, 0.3);

    cout << "arr[0] = " << arr[0].multiply(k) << endl;
    cout << "arr[1] = " << arr[1].multiply(k) << endl;

    fraction F = make_fraction(5, 0.7);
    F.Show();

    return 0;
}