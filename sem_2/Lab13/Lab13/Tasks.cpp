#include <iostream>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Pair.h"

using namespace std;

// ===== ЗАДАЧА 1 =====
void task1() {

    cout << "\n===== TASK 1: deque<Pair> =====\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // создание контейнера
    deque<Pair> d;

    // ввод элементов
    for (int i = 0; i < n; i++) {
        Pair p;
        cout << "Element " << i << ":\n";
        cin >> p;
        d.push_back(p);
    }

    // вывод контейнера
    cout << "Original deque:\n";
    for (auto p : d) cout << p << " ";
    cout << endl;

    // сортировка контейнера
    sort(d.begin(), d.end());

    // поиск максимального элемента
    Pair max_val = *max_element(d.begin(), d.end());

    // добавление максимального элемента
    d.push_back(max_val);

    int k1, k2;
    cout << "Enter key range [k1 k2]: ";
    cin >> k1 >> k2;

    // удаление элементов из диапазона
    d.erase(remove_if(d.begin(), d.end(),
        [k1, k2](Pair p) {
            return p.first >= k1 && p.first <= k2;
        }), d.end());

    // поиск элемента (использование find_if)
    auto found = find_if(d.begin(), d.end(),
        [](Pair p) { return p.first == 0; });

    if (found != d.end())
        cout << "Element with first = 0 found\n";

    // подсчёт элементов (count_if)
    int count = count_if(d.begin(), d.end(),
        [](Pair p) { return p.first > 0; });

    cout << "Elements with first > 0: " << count << endl;

    // вычисление среднего
    Pair sum = accumulate(d.begin(), d.end(), Pair());
    Pair avg = sum / (int)d.size();

    // добавление среднего значения
    for_each(d.begin(), d.end(), [avg](Pair& p) {
        p += avg;
        });

    // вывод результата
    cout << "Result:\n";
    for (auto p : d) cout << p << " ";
    cout << endl;
}


// ===== ЗАДАЧА 2 =====
void task2() {

    cout << "\n===== TASK 2: stack<Pair> =====\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // создание контейнера
    stack<Pair> st;

    // ввод элементов
    for (int i = 0; i < n; i++) {
        Pair p;
        cout << "Element " << i << ":\n";
        cin >> p;
        st.push(p);
    }

    // перенос в вектор
    vector<Pair> v;
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }

    // сортировка
    sort(v.begin(), v.end());

    // поиск максимального элемента
    Pair max_val = *max_element(v.begin(), v.end());

    // добавление максимального элемента
    v.push_back(max_val);

    int k1, k2;
    cout << "Enter key range [k1 k2]: ";
    cin >> k1 >> k2;

    // удаление элементов
    v.erase(remove_if(v.begin(), v.end(),
        [k1, k2](Pair p) {
            return p.first >= k1 && p.first <= k2;
        }), v.end());

    // вычисление среднего
    Pair sum = accumulate(v.begin(), v.end(), Pair());
    Pair avg = sum / (int)v.size();

    // добавление среднего
    for_each(v.begin(), v.end(), [avg](Pair& p) {
        p += avg;
        });

    // обратно в стек
    for (auto p : v)
        st.push(p);

    // вывод результата
    cout << "Result stack:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}


// ===== ЗАДАЧА 3 =====
void task3() {

    cout << "\n===== TASK 3: set<Pair> =====\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // создание контейнера
    set<Pair> s;

    // ввод элементов
    for (int i = 0; i < n; i++) {
        Pair p;
        cout << "Element " << i << ":\n";
        cin >> p;
        s.insert(p);
    }

    // вывод контейнера
    cout << "Original set:\n";
    for (auto p : s) cout << p << " ";
    cout << endl;

    // поиск максимального элемента
    Pair max_val = *max_element(s.begin(), s.end());

    // добавление максимального элемента
    s.insert(max_val);

    int k1, k2;
    cout << "Enter key range [k1 k2]: ";
    cin >> k1 >> k2;

    // удаление элементов
    for (auto it = s.begin(); it != s.end();) {
        if (it->first >= k1 && it->first <= k2)
            it = s.erase(it);
        else
            ++it;
    }

    // вычисление среднего
    Pair sum = accumulate(s.begin(), s.end(), Pair());
    Pair avg = sum / (int)s.size();

    // добавление среднего
    set<Pair> temp;
    for_each(s.begin(), s.end(), [&](Pair p) {
        temp.insert(p + avg);
        });

    s = temp;

    // вывод результата
    cout << "Result:\n";
    for (auto p : s) cout << p << " ";
    cout << endl;
}