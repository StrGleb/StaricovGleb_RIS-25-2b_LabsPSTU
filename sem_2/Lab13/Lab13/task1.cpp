#include <iostream>
#include <deque>
#include <algorithm>
#include "Pair.h"
#include "AllTasks.h"

using namespace std;

Pair s, avg;

struct Equal_s {
    bool operator()(Pair t) {
        return t == s;
    }
};

struct InRange {
    Pair a, b;
    InRange(Pair a, Pair b) : a(a), b(b) {}

    bool operator()(Pair t) {
        return t >= a && t <= b;
    }
};

static void add_avg(Pair& t) {
    t = t + avg;
}

void task1() {
    deque<Pair> d;
    int n;

    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Pair p;
        cin >> p;
        d.push_back(p);
    }

    // 🔹 сортировка
    sort(d.begin(), d.end());

    // 🔹 поиск
    cout << "Enter element to find: ";
    cin >> s;
    find_if(d.begin(), d.end(), Equal_s());

    // 🔹 max (без дублей)
    Pair max_val = *max_element(d.begin(), d.end());
    d.push_back(max_val);

    // 🔹 диапазон
    Pair a, b;
    cout << "Enter range: ";
    cin >> a >> b;

    d.erase(remove_if(d.begin(), d.end(), InRange(a, b)), d.end());

    // 🔹 среднее (ПРАВИЛЬНОЕ)
    if (!d.empty()) {
        Pair sum(0, 0);
        for (auto& p : d)
            sum = sum + p;

        avg = Pair(sum.first / (int)d.size(),
            sum.second / (double)d.size());

        for_each(d.begin(), d.end(), add_avg);
    }

    cout << "Result:\n";
    for (auto& p : d)
        cout << p << " ";
    cout << endl;
}