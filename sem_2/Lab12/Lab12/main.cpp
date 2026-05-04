#include <iostream>
#include "Task.h"
#include "Container.h"

using namespace std;

int main() {

    // ===== ЗАДАЧА 1 =====

    cout << "\n===== TASK 1 =====\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // создание и заполнение контейнера
    TSet s = make_set(n);

    // вывод контейнера
    cout << "Original set:\n";
    print_set(s);

    double a, b;
    cout << "Enter range [a b]: ";
    cin >> a >> b;

    // обработка контейнера
    modify_set(s, a, b);

    // вывод результата
    cout << "Result:\n";
    print_set(s);


    // ===== ЗАДАЧА 2 =====

    cout << "\n===== TASK 2 =====\n";

    cout << "Enter number of elements: ";
    cin >> n;

    // создание и заполнение контейнера
    TMap m = make_map(n);

    // вывод контейнера
    cout << "Original map:\n";
    print_map(m);

    int k1, k2;
    cout << "Enter key range [k1 k2]: ";
    cin >> k1 >> k2;

    // обработка контейнера
    process_map(m, k1, k2);

    // вывод результата
    cout << "Result:\n";
    print_map(m);


    // ===== ЗАДАЧА 3 =====

    cout << "\n===== TASK 3 =====\n";

    cout << "Enter number of elements: ";
    cin >> n;

    // создание контейнера
    Container<Pair> c(n);

    // вывод контейнера
    cout << "Original container:\n";
    c.Print();

    cout << "Enter key range [k1 k2]: ";
    cin >> k1 >> k2;

    // обработка контейнера
    c.RemoveRange(k1, k2);
    c.AddMax();
    c.AddAverage();

    // вывод результата
    cout << "Result:\n";
    c.Print();

    return 0;
}