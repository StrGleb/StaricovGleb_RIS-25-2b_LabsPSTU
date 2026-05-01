#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "AllTasks.h"

using namespace std;

void run_task4() {
    cout << "\n--- Task 4 (stack<double>) ---\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    stack<double> s;
    for (int i = 0; i < n; i++) {
        double x;
        cout << "Element " << i + 1 << ": ";
        cin >> x;
        s.push(x);
    }

    // стек → вектор
    vector<double> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(), v.end());

    // 🔹 поиск + вставка
    double key;
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
        double max_val = *max_element(v.begin(), v.end());
        double min_val = *min_element(v.begin(), v.end());
        double diff = max_val - min_val;

        for (double& x : v)
            x -= diff;
    }

    // обратно в стек
    for (double x : v)
        s.push(x);

    cout << "Result (top to bottom):\n";
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}