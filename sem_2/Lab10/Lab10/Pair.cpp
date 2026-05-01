#include "Pair.h"

Pair::Pair() { first = 0; second = 0; }
Pair::Pair(int f, double s) { first = f; second = s; }
Pair::Pair(const Pair& p) { first = p.first; second = p.second; }
Pair::~Pair() {}

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

Pair& Pair::operator--() {
    --first; // Уменьшение первого числа (int)
    return *this;
}

Pair Pair::operator--(int) {
    Pair temp(*this);
    second--; // Уменьшение второго числа (double)
    return temp;
}

Pair Pair::operator-(double L) {
    return Pair(first, second - L);
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << p.first << ":" << p.second;
    return out;
}

istream& operator>>(istream& in, Pair& p) {
    cout << "first (int)? "; in >> p.first;
    cout << "second (double)? "; in >> p.second;
    return in;
}

fstream& operator>>(fstream& fin, Pair& p) {
    fin >> p.first;
    fin >> p.second;
    return fin;
}

fstream& operator<<(fstream& fout, const Pair& p) {
    fout << p.first << "\n" << p.second << "\n";
    return fout;
}