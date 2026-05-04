#pragma once
#include <iostream>
using namespace std;

class Pair {
public:
    int first;
    double second;

    // конструкторы
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}

    // операции сравнения
    bool operator<(const Pair& t) const {
        if (first != t.first) return first < t.first;
        return second < t.second;
    }

    bool operator>(const Pair& t) const {
        return t < *this;
    }

    // арифметические операции
    Pair operator+(const Pair& t) const {
        return Pair(first + t.first, second + t.second);
    }

    Pair operator/(int n) const {
        return Pair(first / n, second / n);
    }

    Pair operator-(const Pair& t) const {
        return Pair(first - t.first, second - t.second);
    }

    void operator+=(const Pair& t) {
        first += t.first;
        second += t.second;
    }

    // ввод объекта
    friend istream& operator>>(istream& in, Pair& t) {
        cout << "  first: ";
        in >> t.first;
        cout << "  second: ";
        in >> t.second;
        return in;
    }

    // вывод объекта
    friend ostream& operator<<(ostream& out, const Pair& t) {
        return out << "(" << t.first << ":" << t.second << ")";
    }
};