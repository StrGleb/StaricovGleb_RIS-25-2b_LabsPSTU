#include "pair.h"
#include <iostream>

using namespace std;

int main() {
    Pair a;
    Pair b;
    Pair c;

    cin >> a;
    cin >> b;

    --a;
    cout << "a after --a: " << a << endl;

    c = a--;
    cout << "a after a--: " << a << endl;
    cout << "c (old a): " << c << endl;

    if (a > b)
        cout << "a > b" << endl;
    else if (a < b)
        cout << "a < b" << endl;
    else
        cout << "a == b" << endl;

    return 0;
}