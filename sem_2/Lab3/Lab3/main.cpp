#include "pair.h"
#include <iostream>

using namespace std;

int main() {
    Pair a;                 // Конструктор без параметров
    Pair b(4, 0.232);       // Конструктор с параметрами
    Pair c;

    cin >> a;               // Ввод объекта с клавиатуры (перегруженный оператор >>)
    cout << a << endl << b << endl;     // Вывод объектов (перегруженный оператор <<)

    --a;            // Префиксный декремент (--a)
    cout << "a after --a: " << a << endl;

    c = a--;            // Постфиксный декремент (a--)
    cout << "a after a--: " << a << endl;
    cout << "c (old a): " << c << endl;

    // Проверка перегруженных операций сравнения
    if (a > b)
        cout << "a > b" << endl;
    else if (a < b)
        cout << "a < b" << endl;
    else
        cout << "a == b" << endl;

    return 0;
}