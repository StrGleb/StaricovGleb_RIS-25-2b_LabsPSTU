#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Pair {
    int first;
    double second;
public:
    Pair();
    Pair(int, double);
    Pair(const Pair&);
    ~Pair();

    // Операции сравнения по заданию
    bool operator<(const Pair&) const;
    bool operator>(const Pair&) const;
    bool operator==(const Pair&) const;

    // Операция -- по заданию
    Pair& operator--();    // Префиксная (уменьшает первое число)
    Pair operator--(int); // Постфиксная (уменьшает второе число)

    // Вспомогательная операция для уменьшения на L
    Pair operator-(double L);

    // Ввод/вывод для стандартных потоков
    friend ostream& operator<<(ostream& out, const Pair& p);
    friend istream& operator>>(istream& in, Pair& p);

    // Ввод/вывод для файловых потоков
    friend fstream& operator>>(fstream& fin, Pair& p);
    friend fstream& operator<<(fstream& fout, const Pair& p);
};