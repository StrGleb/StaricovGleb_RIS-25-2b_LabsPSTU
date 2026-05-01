#include <iostream>
#include <list>
#include <algorithm>
#include "Pair.h"
#include "AllTasks.h"

using namespace std;

void run_task3() {
    cout << "\n--- Task 3 (list<Pair>) ---\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    list<Pair> l;
    for (int i = 0; i < n; i++) {
        Pair p;
        cout << "Pair " << i + 1 << ": ";
        cin >> p;
        l.push_back(p);
    }

    // 🔹 Задание 3: поиск и вставка
    Pair key;
    cout << "Enter key (first second): ";
    cin >> key;

    int pos;
    cout << "Enter position: ";
    cin >> pos;

    auto it = find(l.begin(), l.end(), key);
    if (it != l.end()) {
        auto insert_it = l.begin();
        advance(insert_it, min(pos, (int)l.size()));
        l.insert(insert_it, key);
    }

    // 🔹 Задание 4: удаление по ключу
    l.remove(key);

    // 🔹 Задание 5: (max - min)
    if (!l.empty()) {
        Pair max_p = *max_element(l.begin(), l.end());
        Pair min_p = *min_element(l.begin(), l.end());
        Pair diff = max_p - min_p;

        for (auto& p : l)
            p = p - diff;
    }

    cout << "Result: ";
    for (auto& p : l) cout << p << " ";
    cout << endl;
}