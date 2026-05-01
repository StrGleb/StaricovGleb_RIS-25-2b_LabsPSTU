#pragma once

#include <iostream>
using namespace std;

class Pair {
    int first;
    double second;

public:
    Pair() { first = 0; second = 0.0; }
    Pair(int f, double s) { first = f; second = s; }
    Pair(const Pair& p) { first = p.first; second = p.second; }
    ~Pair() {}

    int getFirst() { return first; }
    double getSecond() { return second; }

    void setFirst(int f) { first = f; }
    void setSecond(double s) { second = s; }

    Pair& operator=(const Pair&);

    bool operator<(const Pair&);
    bool operator>(const Pair&);

    Pair& operator--();
    Pair operator--(int);

    friend istream& operator>>(istream&, Pair&);
    friend ostream& operator<<(ostream&, const Pair&);
};