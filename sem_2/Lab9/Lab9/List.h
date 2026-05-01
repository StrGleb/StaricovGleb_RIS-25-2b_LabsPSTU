#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 30; // Лимит по заданию

class List {
    int size;
    int* beg;
public:
    List() { size = 0; beg = nullptr; }
    List(int s);
    List(const List& l);
    ~List();

    int& operator[](int i);
    List operator+(int val); // Добавление числа в начало
    // По заданию 13: + list (добавление списка к списку)
    List operator+(const List& l);

    const List& operator=(const List& l);
    friend ostream& operator<<(ostream& out, const List& l);
};