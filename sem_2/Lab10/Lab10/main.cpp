#include "File_work.h"
#include <iostream>
using namespace std;

int main() {
    Pair p;
    int k, c;
    char file_name[30];

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Create file\n";
        cout << "2. Show file\n";
        cout << "3. Delete records\n";
        cout << "4. Add records\n";
        cout << "5. Change records\n";
        cout << "0. Exit\n";
        cout << "Choose: ";

        cin >> c;

        switch (c) {

        case 1:
            cout << "\n[CREATE FILE]\n";
            cout << "Enter file name: ";
            cin >> file_name;

            k = make_file(file_name);
            if (k < 0)
                cout << "Error: cannot create file\n";
            else
                cout << "File created. Records: " << k << "\n";
            break;

        case 2:
            cout << "\n[SHOW FILE]\n";
            cout << "Enter file name: ";
            cin >> file_name;

            k = print_file(file_name);
            if (k < 0)
                cout << "Error: cannot open file\n";
            else if (k == 0)
                cout << "File is empty\n";
            else
                cout << "Total records: " << k << "\n";
            break;

        case 3:
            cout << "\n[DELETE RECORDS]\n";
            cout << "Enter file name: ";
            cin >> file_name;

            cout << "Enter value to delete:\n";
            cin >> p;

            k = del_equal(file_name, p);
            if (k < 0)
                cout << "Error: cannot read file\n";
            else
                cout << "Deleted records: " << k << "\n";
            break;

        case 4:
            cout << "\n[ADD RECORDS]\n";
            cout << "Enter file name: ";
            cin >> file_name;

            cout << "Enter target value:\n";
            cin >> p;

            cout << "How many records to add (K): ";
            cin >> k;

            int res;
            res = add_after(file_name, p, k);

            if (res < 0)
                cout << "Error: cannot read file\n";
            else if (res == 0) {
                cout << "Value not found. Adding to end.\n";
                add_end(file_name, p);
            }
            else
                cout << "Records added successfully\n";
            break;

        case 5:
            cout << "\n[CHANGE RECORDS]\n";
            cout << "Enter file name: ";
            cin >> file_name;

            cout << "Enter value to change:\n";
            cin >> p;

            double L;
            cout << "Enter L (decrease value): ";
            cin >> L;

            k = change_file(file_name, p, L);

            if (k < 0)
                cout << "Error: cannot read file\n";
            else if (k == 0)
                cout << "No matching records found\n";
            else
                cout << "Changed records: " << k << "\n";
            break;
        }

    } while (c != 0);

    cout << "\nProgram finished.\n";
    return 0;
}