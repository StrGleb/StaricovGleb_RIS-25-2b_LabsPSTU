#pragma once
#include <iostream>
using namespace std;

// пользовательский тип Pair
class Pair {
public:
    int first;
    double second;

    Pair(int f = 0, double s = 0) {
        first = f;
        second = s;
    }

    // сравнение для max
    bool operator>(const Pair& p) const {
        return first > p.first;
    }

    // проверка диапазона
    bool inRange(int a, int b) const {
        return first >= a && first <= b;
    }

    // сложение
    Pair operator+(const Pair& p) const {
        return Pair(first + p.first, second + p.second);
    }

    // деление
    Pair operator/(int n) const {
        return Pair(first / n, second / n);
    }

    friend ostream& operator<<(ostream& out, const Pair& p) {
        out << "(" << p.first << "," << p.second << ")";
        return out;
    }
};