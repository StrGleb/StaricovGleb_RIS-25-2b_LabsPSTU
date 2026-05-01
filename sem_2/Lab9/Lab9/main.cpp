#include "List.h"
#include <iostream>
using namespace std;

int main() {
    try {
        List a(3); // [0, 0, 0]
        cout << "A: " << a;

        cout << "Adding 5 to start..." << endl;
        a = a + 5; // [5, 0, 0, 0]
        cout << "A: " << a;

        List b(2);
        b[0] = 10; b[1] = 20;
        cout << "B: " << b;

        cout << "Merging A + B..." << endl;
        List c = a + b;
        cout << "C: " << c;

        cout << "Testing error (index 100)..." << endl;
        cout << c[100] << endl; // Должно бросить ошибку 3[cite: 6]
    }
    catch (int e) {
        cout << "!!! EXCEPTION CAUGHT. CODE: " << e << endl;
        if (e == 1) cout << "Reason: Too large size" << endl;
        if (e == 2) cout << "Reason: Negative index" << endl;
        if (e == 3) cout << "Reason: Index out of range" << endl;
        if (e == 4) cout << "Reason: Overflow" << endl;
    }
}