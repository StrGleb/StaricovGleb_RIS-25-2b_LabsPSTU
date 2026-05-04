#include <iostream>
#include <deque>
#include <stack>
#include "Pair.h"
#include "List.h"
using namespace std;

// ЗАДАНИЕ 1
void task1() {
    cout << "\n===== Task 1: deque<double> =====\n";

    deque<double> d;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        d.push_back(x);
    }

    cout << "\nOriginal container:\n";
    for (auto x : d) cout << x << " ";
    cout << endl;

    // add max
    double m = d[0];
    for (auto x : d)
        if (x > m) m = x;

    cout << "Max element = " << m << " -> adding to container\n";
    d.push_back(m);

    // удаление
    double a, b;
    cout << "Enter range to delete [a b]: ";
    cin >> a >> b;

    for (auto it = d.begin(); it != d.end();) {
        if (*it >= a && *it <= b)
            it = d.erase(it);
        else
            ++it;
    }

    cout << "After deletion:\n";
    for (auto x : d) cout << x << " ";
    cout << endl;

    // среднее
    double sum = 0;
    for (auto x : d) sum += x;

    double avg = sum / d.size();

    cout << "Average = " << avg << " -> adding to each element\n";

    for (auto& x : d)
        x += avg;

    cout << "Final result:\n";
    for (auto x : d) cout << x << " ";
    cout << endl;
}

// ЗАДАНИЕ 2
void task2() {
    cout << "\n===== Task 2: deque<Pair> =====\n";

    deque<Pair> d;
    int n;

    cout << "Enter number of pairs: ";
    cin >> n;

    cout << "Enter pairs (first int, second double):\n";
    for (int i = 0; i < n; i++) {
        int f; double s;
        cin >> f >> s;
        d.push_back(Pair(f, s));
    }

    cout << "\nOriginal container:\n";
    for (auto x : d) cout << x << " ";
    cout << endl;

    // add max
    Pair m = d[0];
    for (auto x : d)
        if (x > m) m = x;

    cout << "Max element = " << m << " -> adding to container\n";
    d.push_back(m);

    // удаление
    int a, b;
    cout << "Enter range for first field [a b]: ";
    cin >> a >> b;

    for (auto it = d.begin(); it != d.end();) {
        if (it->inRange(a, b))
            it = d.erase(it);
        else
            ++it;
    }

    cout << "After deletion:\n";
    for (auto x : d) cout << x << " ";
    cout << endl;

    // среднее
    Pair sum;
    for (auto x : d)
        sum = sum + x;

    Pair avg = sum / d.size();

    cout << "Average = " << avg << " -> adding to each element\n";

    for (auto& x : d)
        x = x + avg;

    cout << "Final result:\n";
    for (auto x : d) cout << x << " ";
    cout << endl;
}

// ЗАДАНИЕ 3
void task3() {
    cout << "\n===== Task 3: List =====\n";

    List<Pair> lst;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter pairs (first int, second double):\n";
    for (int i = 0; i < n; i++) {
        int f; double s;
        cin >> f >> s;
        lst.push_back(Pair(f, s));
    }

    cout << "\nOriginal list:\n";
    lst.print();

    cout << "Adding max element...\n";
    lst.add_max();

    int a, b;
    cout << "Enter range for deletion [a b]: ";
    cin >> a >> b;

    lst.remove_range(a, b);

    cout << "After deletion:\n";
    lst.print();

    cout << "Adding average to each element...\n";
    lst.add_average();

    cout << "Final result:\n";
    lst.print();
}

// ЗАДАНИЕ 4
void task4() {
    cout << "\n===== Task 4: stack =====\n";

    stack<Pair> st;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter pairs (first int, second double):\n";
    for (int i = 0; i < n; i++) {
        int f; double s;
        cin >> f >> s;
        st.push(Pair(f, s));
    }

    cout << "Stack created\n";

    // add max
    stack<Pair> temp = st;
    Pair m = temp.top();

    while (!temp.empty()) {
        if (temp.top() > m)
            m = temp.top();
        temp.pop();
    }

    cout << "Max element = " << m << " -> adding to stack\n";
    st.push(m);

    // удаление
    int a, b;
    cout << "Enter range for deletion [a b]: ";
    cin >> a >> b;

    stack<Pair> st2;
    while (!st.empty()) {
        Pair p = st.top();
        st.pop();

        if (!p.inRange(a, b))
            st2.push(p);
    }

    cout << "After deletion\n";

    // среднее
    stack<Pair> temp2 = st2;
    Pair sum;
    int count = 0;

    while (!temp2.empty()) {
        sum = sum + temp2.top();
        temp2.pop();
        count++;
    }

    Pair avg = sum / count;

    cout << "Average = " << avg << " -> adding to each element\n";

    stack<Pair> result;
    while (!st2.empty()) {
        result.push(st2.top() + avg);
        st2.pop();
    }

    cout << "Final result:\n";
    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;
}

// ЗАДАНИЕ 5
void task5() {
    cout << "\n===== Task 5: List + stack =====\n";

    List<Pair> lst;
    stack<Pair> st;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter pairs (first int, second double):\n";
    for (int i = 0; i < n; i++) {
        int f; double s;
        cin >> f >> s;
        st.push(Pair(f, s));
    }

    cout << "Transferring stack to list...\n";

    while (!st.empty()) {
        lst.push_back(st.top());
        st.pop();
    }

    cout << "Original list:\n";
    lst.print();

    cout << "Adding max...\n";
    lst.add_max();

    int a, b;
    cout << "Enter range for deletion [a b]: ";
    cin >> a >> b;

    lst.remove_range(a, b);

    cout << "After deletion:\n";
    lst.print();

    cout << "Adding average...\n";
    lst.add_average();

    cout << "Final result:\n";
    lst.print();
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();

    return 0;
}