#include "Pair.h"
#include "File_work.h"
#include <iostream>

using namespace std;

int main() {
    char f_name[30];
    int choice;
    cout << "Enter filename: "; cin >> f_name;

    do {
        cout << "\n1. Make file";
        cout << "\n2. Print file";
        cout << "\n3. Delete records equal to value";
        cout << "\n4. Decrease records (val) by L";
        cout << "\n5. Add K records after value";
        cout << "\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1: make_file(f_name); break;
        case 2: print_file(f_name); break;
        case 3: {
            Pair val;
            cout << "Enter value to delete:\n"; cin >> val;
            del_equal(f_name, val);
            break;
        }
        case 4: {
            Pair val; double L;
            cout << "Enter value to find:\n"; cin >> val;
            cout << "Enter L: "; cin >> L;
            change_file(f_name, val, L);
            break;
        }
        case 5: {
            Pair target; int k;
            cout << "After which value? "; cin >> target;
            cout << "How many to add? "; cin >> k;
            add_after(f_name, target, k);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}