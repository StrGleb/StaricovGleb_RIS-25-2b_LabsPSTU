#include <iostream>
#include <algorithm>
#include <numeric>
#include "Task.h"

using namespace std;


// ЗАДАЧА 1 — set<double>

// создание контейнера
TSet make_set(int n) {
    TSet s;

    // ввод элементов
    for (int i = 0; i < n; i++) {
        double x;
        cout << "Enter value: ";
        cin >> x;
        s.insert(x);
    }

    return s;
}

// вывод контейнера
void print_set(const TSet& s) {
    for (double x : s)
        cout << x << " ";
    cout << endl;
}

// обработка контейнера
void modify_set(TSet& s, double a, double b) {

    if (s.empty()) return;

    // добавление максимального элемента
    double max_val = *max_element(s.begin(), s.end());
    s.insert(max_val);

    // удаление элементов из диапазона
    for (auto it = s.begin(); it != s.end();) {
        if (*it >= a && *it <= b)
            it = s.erase(it);
        else
            ++it;
    }

    if (s.empty()) return;

    // вычисление среднего значения
    double sum = accumulate(s.begin(), s.end(), 0.0);
    double avg = sum / s.size();

    // добавление среднего значения к элементам
    TSet temp;
    for (double x : s)
        temp.insert(x + avg);

    s = temp;
}


// ЗАДАЧА 2 — map<int, Pair>

// создание контейнера
TMap make_map(int n) {
    TMap m;

    // ввод элементов
    for (int i = 0; i < n; i++) {
        Pair p;
        cout << "Pair " << i << ":\n";
        cin >> p;
        m[i] = p;
    }

    return m;
}

// вывод контейнера
void print_map(const TMap& m) {
    for (auto [key, val] : m)
        cout << key << ": " << val << endl;
}

// обработка контейнера
void process_map(TMap& m, int k1, int k2) {

    if (m.empty()) return;

    // удаление элементов по ключам
    for (int i = k1; i <= k2; i++)
        m.erase(i);

    // добавление максимального элемента
    if (!m.empty()) {
        auto max_it = m.begin();
        for (auto it = m.begin(); it != m.end(); ++it)
            if (it->second > max_it->second)
                max_it = it;

        int new_key = m.rbegin()->first + 1;
        m[new_key] = max_it->second;
    }

    // вычисление среднего значения
    if (!m.empty()) {
        Pair sum = m.begin()->second;
        auto it = m.begin();
        for (++it; it != m.end(); ++it)
            sum = sum + it->second;

        Pair avg = sum / (int)m.size();

        // добавление среднего значения к элементам
        for (auto& [key, val] : m)
            val += avg;
    }
}