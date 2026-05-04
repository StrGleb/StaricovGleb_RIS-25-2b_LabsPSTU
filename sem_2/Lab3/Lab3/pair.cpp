#include "pair.h"

// перегрузка операции присваивания
Pair& Pair::operator=(const Pair& p) {
    if (this == &p) return *this;

    first = p.first;
    second = p.second;
    return *this;
}

// перегрузка операторов сравнения
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

// перегрузка префиксной операции
Pair& Pair::operator--() {
    first--;
    return *this;
}

// перегрузка постфиксной операции
Pair Pair::operator--(int) {
    Pair temp(*this);
    second--;
    return temp;
}

// перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Pair& p) {
    cout << "Vvedite first: ";
    in >> p.first;
    cout << "Vvedite second: ";
    in >> p.second;
    return in;
}

// перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Pair& p) {
    out << p.first << ":" << p.second;
    return out;
}