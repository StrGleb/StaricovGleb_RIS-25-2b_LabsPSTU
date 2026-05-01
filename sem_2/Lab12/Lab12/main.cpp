#include <iostream>
#include "Task.h"
#include "Container.h"
#include "Pair.h"

using namespace std;

int main() {
    int task;
    cout << "Select task (1, 2, 3) or 0 to exit: ";
    cin >> task;

    if (task == 1) {
        int n; cout << "Enter count: "; cin >> n;
        TSet s = make_set(n);
        cout << "Range to remove (min max): ";
        double v1, v2; cin >> v1 >> v2;
        modify_set(s, v1, v2);
        print_set(s);
    }
    else if (task == 2) {
        int n; cout << "Enter count: "; cin >> n;
        TMap m = make_map(n);
        cout << "Key range to remove (k1 k2): ";
        int k1, k2; cin >> k1 >> k2;
        process_map(m, k1, k2);
        print_map(m);
    }
    else if (task == 3) {
        int n; cout << "Enter count: "; cin >> n;
        Container<Pair> con(n);
        con.AddMax();
        cout << "Key range to remove (k1 k2): ";
        int k1, k2; cin >> k1 >> k2;
        con.RemoveRange(k1, k2);
        con.AddAverage();
        con.Print();
    }
}