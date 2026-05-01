#include <iostream>
#include <deque>
#include <algorithm>
#include "AllTasks.h"

using namespace std;

void run_task1() {
    cout << "\n--- Task 1 (deque<double>) ---\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    deque<double> d(n);
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> d[i];
    }

    // 🔹 Задание 3: поиск по ключу и вставка
    double key;
    cout << "Enter key to find: ";
    cin >> key;

    int pos;
    cout << "Enter position to insert: ";
    cin >> pos;

    auto it = find(d.begin(), d.end(), key);
    if (it != d.end() && pos >= 0 && pos <= d.size()) {
        d.insert(d.begin() + pos, key);
    }

    // 🔹 Задание 4: удалить по ключу
    d.erase(remove(d.begin(), d.end(), key), d.end());

    // 🔹 Задание 5: вычесть (max - min)
    if (!d.empty()) {
        double max_val = *max_element(d.begin(), d.end());
        double min_val = *min_element(d.begin(), d.end());
        double diff = max_val - min_val;

        for (double& x : d)
            x -= diff;
    }

    cout << "Result: ";
    for (double x : d) cout << x << " ";
    cout << endl;
}