#include <iostream>
#include <vector>
#include <algorithm>
#include "Pair.h"
#include "AllTasks.h"

using namespace std;

void run_task2() {
    cout << "\n--- Task 2 (vector<Pair>) ---\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<Pair> v;
    for (int i = 0; i < n; i++) {
        Pair p;
        cout << "Pair " << i + 1 << ": ";
        cin >> p;
        v.push_back(p);
    }

    // 🔹 поиск + вставка
    Pair key;
    cout << "Enter key: ";
    cin >> key;

    int pos;
    cout << "Enter position: ";
    cin >> pos;

    if (find(v.begin(), v.end(), key) != v.end() &&
        pos >= 0 && pos <= v.size()) {
        v.insert(v.begin() + pos, key);
    }

    // 🔹 удаление по ключу
    v.erase(remove(v.begin(), v.end(), key), v.end());

    // 🔹 (max - min)
    if (!v.empty()) {
        Pair max_p = *max_element(v.begin(), v.end());
        Pair min_p = *min_element(v.begin(), v.end());
        Pair diff = max_p - min_p;

        for (auto& p : v)
            p = p - diff;
    }

    cout << "Result: ";
    for (auto& p : v)
        cout << p << " ";
    cout << endl;
}