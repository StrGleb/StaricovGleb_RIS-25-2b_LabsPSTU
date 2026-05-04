#include "Pair.h"

// конструкторы
Pair::Pair() { first = 0; second = 0; }
Pair::Pair(int f, double s) { first = f; second = s; }
Pair::Pair(const Pair& p) { first = p.first; second = p.second; }
Pair::~Pair() {}

// сравнение
bool Pair::operator<(const Pair& p) const {
    if (first < p.first) return true;
    if (first == p.first && second < p.second) return true;
    return false;
}

bool Pair::operator>(const Pair& p) const {
    return !(*this < p || *this == p);
}

bool Pair::operator==(const Pair& p) const {
    return (first == p.first && second == p.second);
}

// префиксный --
Pair& Pair::operator--() {
    --first;
    return *this;
}

// постфиксный --
Pair Pair::operator--(int) {
    Pair temp(*this);
    second--;
    return temp;
}

// уменьшение на L
Pair Pair::operator-(double L) {
    return Pair(first, second - L);
}

// вывод 
ostream& operator<<(ostream& out, const Pair& p) {
    out << p.first << ":" << p.second;
    return out;
}

// ввод
istream& operator>>(istream& in, Pair& p) {

    if (&in == &cin) {
        cout << "Enter first (int): ";
        in >> p.first;

        cout << "Enter second (double): ";
        in >> p.second;
    }
    else {
        char ch;
        in >> p.first >> ch >> p.second; // читаем "1:1"
    }

    return in;
}