#include "list.h"
#include "pair.h"
#include <iostream>

using namespace std;

int main() {
    List<int> a(5); // список целых чисел
    List<int> b(5); // список целых чисел

    cout << "enter a: ";
    cin >> a; // ввод списка a

    cout << "enter b: ";
    cin >> b; // ввод списка b

    cout << "\na: " << a; // вывод списка a
    cout << "\nb: " << b; // вывод списка b

    a[2] = 100; // изменение элемента по индексу
    cout << "\na after change: " << a;

    List<int> c = a + b; // сложение списков
    cout << "\nc = a + b: " << c;

    List<int> d = a + 10; // прибавление числа ко всем элементам
    cout << "\nd = a + 10: " << d;

    Pair p1, p2; // объекты класса Pair

    cout << "\nenter pair 1: ";
    cin >> p1; // ввод первой пары

    cout << "enter pair 2: ";
    cin >> p2; // ввод второй пары

    Pair p3 = p1 + p2; // сложение пар
    cout << "p1 + p2 = " << p3;

    Pair p4 = p1 + 10; // прибавление числа к паре
    cout << "\np1 + 10 = " << p4;

    return 0; // конец программы
}