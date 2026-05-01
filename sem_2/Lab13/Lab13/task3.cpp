#include <iostream>
#include <set>
#include "Pair.h"
#include "AllTasks.h"

using namespace std;

extern Pair avg;

void task3() {
    set<Pair> sset;
    int n;

    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Pair p;
        cin >> p;
        sset.insert(p);
    }

    // 🔹 max (set сам уберёт дубликат если есть)
    sset.insert(*prev(sset.end()));

    // 🔹 диапазон
    Pair a, b;
    cout << "Enter range: ";
    cin >> a >> b;

    for (auto it = sset.begin(); it != sset.end();) {
        if (*it >= a && *it <= b)
            it = sset.erase(it);
        else
            ++it;
    }

    // 🔹 среднее
    if (!sset.empty()) {
        Pair sum(0, 0);
        for (auto& p : sset)
            sum = sum + p;

        avg = Pair(sum.first / (int)sset.size(),
            sum.second / (double)sset.size());

        set<Pair> temp;
        for (auto& p : sset)
            temp.insert(p + avg);

        sset = temp;
    }

    cout << "Result:\n";
    for (auto& p : sset)
        cout << p << " ";
    cout << endl;
}