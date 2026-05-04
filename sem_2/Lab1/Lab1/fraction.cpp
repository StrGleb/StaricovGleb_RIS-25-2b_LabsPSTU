#include "fraction.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Метод инициализации с проверкой корректности данных
void fraction::Init(int f, double s) {
    // Проверка целой части
    if (f <= 0) {
        cout << "Celaya chast dolzhna byt > 0\n";
        exit(1);
    }

    // Проверка дробной части
    if (s <= 0 || s >= 1) {
        cout << "Drobnaya chast dolzhna byt v diapazone (0,1)\n";
        exit(1);
    }

    // Присваивание значений полям класса
    first = f;
    second = s;
}

// Метод ввода значений с клавиатуры
void fraction::Read() {
    int f;
    double s;

    cout << "Vvedite celuyu chast chisla: ";
    cin >> f;

    cout << "Vvedite drobnuyu chast chisla: ";
    cin >> s;

    // Инициализация через Init (с проверкой)
    Init(f, s);
}

// Метод вывода значений полей объекта
void fraction::Show() {
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
}

// Метод умножения на целое число k
double fraction::multiply(int k) {
    // Преобразуем число в вещественное и умножаем
    return (first + second) * k;
}

// Метод умножения на вещественное число k
double fraction::multiply(double k) {
    return (first + second) * k;
}