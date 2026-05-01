#include <iostream>
#include <limits>
#include "AllTasks.h"

using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "1 - Task1\n";
        cout << "2 - Task2\n";
        cout << "3 - Task3\n";
        cout << "4 - Task4\n";
        cout << "5 - Task5\n";
        cout << "0. Exit" << endl;
        cout << "---------------------------------" << endl;
        cout << "Select option: ";

        if (!(cin >> choice)) {
            cout << "Input error! Please enter a number (0-5)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 0) {
            cout << "Exiting program..." << endl;
            break;
        }

        switch (choice) {
        case 1: run_task1(); break;
        case 2: run_task2(); break;
        case 3: run_task3(); break;
        case 4: run_task4(); break;
        case 5: run_task5(); break;
        default:
            cout << "Invalid selection. Try again." << endl;
            break;
        }

        cout << "\nDone. Press Enter to return to menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}