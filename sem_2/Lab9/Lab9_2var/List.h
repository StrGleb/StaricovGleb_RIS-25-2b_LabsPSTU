#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

class List {
    int size;
    int* beg;
public:
    List() { size = 0; beg = nullptr; }
    List(int s);
    List(const List& l);
    ~List();

    int& operator[](int i);
    List operator+(int val);       // Добавление в начало
    List operator+(const List& l); // Слияние списков

    const List& operator=(const List& l);
    friend ostream& operator<<(ostream& out, const List& l);
};