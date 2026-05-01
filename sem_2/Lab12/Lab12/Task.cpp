#include <iostream>
#include <numeric>
#include "Task.h"

using namespace std;

// ЗАДАЧА 1 (double)
TSet make_set(int n) {
    TSet s;
    for (int i = 0; i < n; i++) {
        double val;
        cout << "  val: "; cin >> val;
        s.insert(val);
    }
    return s;
}

void print_set(const TSet& s) {
    for (auto x : s) cout << x << " ";
    cout << endl;
}

void modify_set(TSet& s, double min_v, double max_v) {
    if (s.empty()) return;

    // 1. Добавление максимального
    double max_val = *max_element(s.begin(), s.end());
    s.insert(max_val);

    // 2. Удаление диапазона
    for (auto it = s.begin(); it != s.end(); ) {
        if (*it >= min_v && *it <= max_v)
            it = s.erase(it);
        else
            ++it;
    }

    if (s.empty()) return;

    // 3. Добавление среднего
    double sum = accumulate(s.begin(), s.end(), 0.0);
    double avg = sum / s.size();

    TSet temp;
    for (double x : s)
        temp.insert(x + avg);

    s = temp;
}

// ЗАДАЧА 2 (map + Pair)
TMap make_map(int n) {
    TMap m;
    for (int i = 0; i < n; i++) {
        Pair p;
        cout << "  Pair " << i << ":" << endl;
        cin >> p;
        m[i] = p;
    }
    return m;
}

void print_map(const TMap& m) {
    for (auto const& [key, val] : m) cout << "[" << key << "]" << val << " ";
    cout << endl;
}

void process_map(TMap& m, int k1, int k2) {
    if (m.empty()) return;

    // 1. Удаление по ключам
    for (int i = k1; i <= k2; i++) m.erase(i);

    // 2. Добавление максимума
    if (!m.empty()) {
        auto max_it = m.begin();
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > max_it->second) max_it = it;
        }
        int new_key = m.rbegin()->first + 1;
        m[new_key] = max_it->second;
    }

    // 3. Добавление среднего
    if (!m.empty()) {
        Pair sum = m.begin()->second;
        auto it = m.begin();
        for (++it; it != m.end(); ++it) sum = sum + it->second;
        Pair avg = sum / (int)m.size();
        for (auto& [key, val] : m) val += avg;
    }
}