#pragma once
#include <iostream>
#include <fstream>
using namespace std;

// Класс Pair (пара чисел)
class Pair {
    int first;      // первое число
    double second;  // второе число

public:
    Pair();                    // конструктор без параметров
    Pair(int, double);         // конструктор с параметрами
    Pair(const Pair&);         // конструктор копирования
    ~Pair();                   // деструктор

    // операции сравнения (по методичке)
    bool operator<(const Pair&) const;
    bool operator>(const Pair&) const;
    bool operator==(const Pair&) const;

    // операция -- (по заданию)
    Pair& operator--();     // префиксная (уменьшает первое число)
    Pair operator--(int);   // постфиксная (уменьшает второе число)

    // операция уменьшения на число L
    Pair operator-(double L);

    // ввод/вывод
    friend ostream& operator<<(ostream& out, const Pair& p);
    friend istream& operator>>(istream& in, Pair& p);
};