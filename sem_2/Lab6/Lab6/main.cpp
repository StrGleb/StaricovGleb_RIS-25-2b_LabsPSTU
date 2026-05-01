#include "list.h"
#include <iostream>

using namespace std;

int main() {
    List a(5);
    List b(5);

    cout << "enter first list: ";
    cin >> a;

    cout << "enter second list: ";
    cin >> b;

    cout << "\na: " << a;
    cout << "\nb: " << b;

    a[2] = 100;
    cout << "\na after change: " << a;

    List c = a + b;
    cout << "\nc = a + b: " << c;

    List d = a + 10;
    cout << "\nd = a + 10: " << d;

    Iterator i = a.first();

    i++;
    cout << "\nafter i++: " << *i;

    cout << "\nreverse: ";
    for (i = a.last(); i != a.first();) {
        --i;
        cout << *i << " ";
    }

    cout << endl;

    return 0;
}