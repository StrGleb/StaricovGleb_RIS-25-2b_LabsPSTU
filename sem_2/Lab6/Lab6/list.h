#pragma once
#include <iostream>
#include "iterator.h"

using namespace std;

class List {
private:
    int* data;      // динамический массив элементов
    int size;       // размер списка
    Iterator beg;   // итератор на начало
    Iterator end;   // итератор на конец

public:
    List(int s = 0, int k = 0); // конструктор с параметрами
    List(const List&); // конструктор копирования
    ~List(); // деструктор

    List& operator=(const List&); // операция присваивания

    int& operator[](int); // доступ по индексу

    List operator+(const List&); // сложение двух списков
    List operator+(int); // прибавление числа ко всем элементам

    Iterator first(); // вернуть итератор на начало
    Iterator last();  // вернуть итератор на конец

    friend ostream& operator<<(ostream&, const List&); // вывод списка
    friend istream& operator>>(istream&, List&); // ввод списка
};