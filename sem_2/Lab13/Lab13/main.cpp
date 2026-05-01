#include <iostream>
#include "AllTasks.h"

using namespace std;

int main() {
    int c;

    do {
        cout << "\n1 - deque\n2 - stack\n3 - set\n0 - exit\n";
        cin >> c;

        switch (c) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        }

    } while (c != 0);

    return 0;
}