#pragma once
#include <iostream>

class Pair {
public:
    int first;
    double second;

    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}

    // Обязательно для map/set (сортировка по ключу/значению)
    bool operator<(const Pair& t) const {
        if (first != t.first) return first < t.first;
        return second < t.second;
    }

    bool operator>(const Pair& t) const { return t < *this; }

    // Операторы для вычисления среднего арифметического
    Pair operator+(const Pair& t) const { return Pair(first + t.first, second + t.second); }
    Pair operator/(int n) const { return Pair(first / n, second / n); }
    void operator+=(const Pair& t) { first += t.first; second += t.second; }

    friend std::istream& operator>>(std::istream& in, Pair& t) {
        std::cout << "    int: "; in >> t.first;
        std::cout << "    double: "; in >> t.second;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Pair& t) {
        return out << "(" << t.first << ":" << t.second << ")";
    }
};