#pragma once
#include <iostream>
using namespace std;

class Pair {
public:
    int first;
    double second;

    Pair() : first(0), second(0) {}
    Pair(int f, double s) : first(f), second(s) {}

    // сравнение
    bool operator<(const Pair& t) const {
        if (first != t.first) return first < t.first;
        return second < t.second;
    }

    bool operator>(const Pair& t) const {
        return t < *this;
    }

    bool operator==(const Pair& t) const {
        return first == t.first && second == t.second;
    }

    // арифметика
    Pair operator+(const Pair& t) const {
        return Pair(first + t.first, second + t.second);
    }

    Pair operator/(int n) const {
        return Pair(first / n, second / n);
    }

    void operator+=(const Pair& t) {
        first += t.first;
        second += t.second;
    }

    // ввод
    friend istream& operator>>(istream& in, Pair& t) {
        cout << "  first: ";
        in >> t.first;
        cout << "  second: ";
        in >> t.second;
        return in;
    }

    // вывод
    friend ostream& operator<<(ostream& out, const Pair& t) {
        return out << "(" << t.first << ":" << t.second << ")";
    }
};