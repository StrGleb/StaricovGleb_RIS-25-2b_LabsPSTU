#pragma once

#include <iostream>
using namespace std;

class Iterator {
    friend class List;

private:
    int* elem;

public:
    Iterator() { elem = 0; }
    Iterator(const Iterator& it) { elem = it.elem; }

    bool operator==(const Iterator& it) { return elem == it.elem; }
    bool operator!=(const Iterator& it) { return elem != it.elem; }

    void operator++() { ++elem; }
    Iterator operator++(int) {
        Iterator temp(*this);
        ++elem;
        return temp;
    }

    void operator--() { --elem; }

    int& operator*() const { return *elem; }
};

class List {
private:
    int size;
    int* data;
    Iterator beg;
    Iterator end;

public:
    List(int s, int k = 0);
    List(const List& l);
    ~List();

    List& operator=(const List& l);

    int& operator[](int index);

    List operator+(const List& l);
    List operator+(const int k);

    Iterator first() { return beg; }
    Iterator last() { return end; }

    friend ostream& operator<<(ostream& out, const List& l);
    friend istream& operator>>(istream& in, List& l);
};