#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "Pair.h"
#include "AllTasks.h"

using namespace std;

extern Pair s, avg;

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

void task2() {
    stack<Pair> st;
    int n;

    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Pair p;
        cin >> p;
        st.push(p);
    }

    vector<Pair> v;

    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    reverse(v.begin(), v.end());

    // 🔹 сортировка
    sort(v.begin(), v.end());

    // 🔹 поиск
    cout << "Enter element to find: ";
    cin >> s;
    find_if(v.begin(), v.end(), Equal_s());

    // 🔹 max
    Pair max_val = *max_element(v.begin(), v.end());
    v.push_back(max_val);

    // 🔹 диапазон
    Pair a, b;
    cout << "Enter range: ";
    cin >> a >> b;

    v.erase(remove_if(v.begin(), v.end(), InRange(a, b)), v.end());

    // 🔹 среднее
    if (!v.empty()) {
        Pair sum(0, 0);
        for (auto& p : v)
            sum = sum + p;

        avg = Pair(sum.first / (int)v.size(),
            sum.second / (double)v.size());

        for_each(v.begin(), v.end(), add_avg);
    }

    for (auto& p : v)
        st.push(p);

    cout << "Result (top to bottom):\n";
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}