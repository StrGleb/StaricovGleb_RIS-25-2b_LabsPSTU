#include "pair.h"

Pair& Pair::operator=(const Pair& p) {
    if (this == &p) return *this;

    first = p.first;
    second = p.second;
    return *this;
}

bool Pair::operator<(const Pair& p) {
    if (first < p.first) return true;
    if (first == p.first && second < p.second) return true;
    return false;
}

bool Pair::operator>(const Pair& p) {
    if (first > p.first) return true;
    if (first == p.first && second > p.second) return true;
    return false;
}

Pair& Pair::operator--() {
    first--;
    return *this;
}

Pair Pair::operator--(int) {
    Pair temp(*this);
    second--;
    return temp;
}

istream& operator>>(istream& in, Pair& p) {
    cout << "Vvedite first: ";
    in >> p.first;
    cout << "Vvedite second: ";
    in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << p.first << ":" << p.second;
    return out;
}