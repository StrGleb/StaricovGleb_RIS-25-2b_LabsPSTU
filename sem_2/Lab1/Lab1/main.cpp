#include "fraction.h"
#include <iostream>

using namespace std;

// Внешняя функция создания объекта fraction
fraction make_fraction(int f, double s) {
    fraction t;      // временный объект
    t.Init(f, s);    // инициализация
    return t;        // возврат объекта
}

int main() {
    // Создание объектов
    fraction A, B;

    // Инициализация объекта A
    A.Init(42, 0.232);

    // Ввод значений для объекта B
    B.Read();

    // Вывод значений объектов
    A.Show();
    B.Show();

    double k;
    cout << "Vvedite k: ";
    cin >> k;

    // Демонстрация работы метода multiply
    cout << "A = " << A.multiply(k) << endl;
    cout << "B = " << B.multiply(k) << endl;

    // Работа с динамическим объектом (указатель)
    fraction* X = new fraction;
    X->Init(2, 0.3);
    cout << "X = " << X->multiply(k) << endl;
    delete X; // освобождение памяти

    // Работа с массивом объектов
    fraction arr[2];
    arr[0].Init(1, 0.2);
    arr[1].Init(2, 0.3);

    cout << "arr[0] = " << arr[0].multiply(k) << endl;
    cout << "arr[1] = " << arr[1].multiply(k) << endl;

    // Использование функции make_fraction
    fraction F = make_fraction(5, 0.7);
    F.Show();

    return 0;
}