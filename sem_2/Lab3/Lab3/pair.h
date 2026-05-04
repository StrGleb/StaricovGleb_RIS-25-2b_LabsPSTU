#pragma once

#include <iostream>
using namespace std;

class Pair {
    int first; // целое число
    double second; //дробное число

public:
    Pair() { first = 0; second = 0.0; }                       // конструктор без параметров
    Pair(int f, double s) { first = f; second = s; }          // конструктор с параметрами
    Pair(const Pair& p) { first = p.first; second = p.second; } // конструктор копирования
    ~Pair() {}      // деструктор

    int getFirst() { return first; } // вывод целого числа
    double getSecond() { return second; } // вывод дробного числа

    void setFirst(int f) { first = f; }         // присваивание значения целому числу
    void setSecond(double s) { second = s; }    // присваивание значения дробному числу

    // перегруженные операции
    Pair& operator=(const Pair&);  
    bool operator<(const Pair&);  
    bool operator>(const Pair&);        

    Pair& operator--();            // перегрузка постфиксной операции
    Pair operator--(int);       

    // глобальные функции ввода-вывода
    friend istream& operator>>(istream&, Pair&);
    friend ostream& operator<<(ostream&, const Pair&);
};