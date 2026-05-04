#include <iostream>
#include "Tasks.h"

using namespace std;

int main() {

    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Task 1 (deque)\n";
        cout << "2 - Task 2 (stack)\n";
        cout << "3 - Task 3 (set)\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        }

    } while (choice != 0);

    return 0;
}