#pragma once
#include <iostream>

class Pair {
public:
    int first;
    double second;

    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}

    bool operator>(const Pair& t) const {
        if (first != t.first) return first > t.first;
        return second > t.second;
    }

    bool operator<(const Pair& t) const { return t > *this; }
    bool operator>=(const Pair& t) const { return !(*this < t); }
    bool operator<=(const Pair& t) const { return !(*this > t); }

    bool operator==(const Pair& t) const {
        return first == t.first && second == t.second;
    }

    Pair operator+(const Pair& t) const {
        return Pair(first + t.first, second + t.second);
    }

    Pair operator-(const Pair& t) const {
        return Pair(first - t.first, second - t.second);
    }

    Pair operator/(int n) const {
        return Pair(first / n, second / n);
    }

    friend std::istream& operator>>(std::istream& in, Pair& t) {
        return in >> t.first >> t.second;
    }

    friend std::ostream& operator<<(std::ostream& out, const Pair& t) {
        return out << "(" << t.first << ":" << t.second << ")";
    }
};