#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "Pair.h"
#include "AllTasks.h"

using namespace std;

void run_task5() {
    cout << "\n--- Task 5 (stack<Pair>) ---\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    stack<Pair> s;
    for (int i = 0; i < n; i++) {
        Pair p;
        cout << "Pair " << i + 1 << ": ";
        cin >> p;
        s.push(p);
    }

    // Копируем в вектор
    vector<Pair> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(), v.end());

    // 🔹 Задание 3: поиск и вставка
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

    // 🔹 Задание 4: удаление по ключу
    v.erase(remove(v.begin(), v.end(), key), v.end());

    // 🔹 Задание 5: (max - min)
    if (!v.empty()) {
        Pair max_p = *max_element(v.begin(), v.end());
        Pair min_p = *min_element(v.begin(), v.end());
        Pair diff = max_p - min_p;

        for (auto& p : v)
            p = p - diff;
    }

    // обратно в стек
    for (auto& p : v)
        s.push(p);

    cout << "Result (top to bottom):\n";
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}