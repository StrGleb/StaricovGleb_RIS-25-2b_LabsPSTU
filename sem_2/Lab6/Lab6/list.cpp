#include "list.h"
#include <cstdlib>

List::List(int s, int k) {
    size = s;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = k;

    beg.elem = &data[0];
    end.elem = &data[size];
}

List::List(const List& l) {
    size = l.size;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = l.data[i];

    beg.elem = &data[0];
    end.elem = &data[size];
}

List::~List() {
    delete[] data;
}

List& List::operator=(const List& l) {
    if (this == &l) return *this;

    if (data != 0) delete[] data;

    size = l.size;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = l.data[i];

    beg.elem = &data[0];
    end.elem = &data[size];

    return *this;
}

int& List::operator[](int index) {
    if (index >= 0 && index < size)
        return data[index];

    cout << "Error index" << endl;
    exit(1);
}

List List::operator+(const List& l) {
    int minSize = (size < l.size) ? size : l.size;

    List temp(minSize, 0);

    for (int i = 0; i < minSize; i++)
        temp.data[i] = data[i] + l.data[i];

    return temp;
}

List List::operator+(const int k) {
    List temp(size, 0);

    for (int i = 0; i < size; i++)
        temp.data[i] = data[i] + k;

    return temp;
}

ostream& operator<<(ostream& out, const List& l) {
    for (int i = 0; i < l.size; i++)
        out << l.data[i] << " ";
    return out;
}

istream& operator>>(istream& in, List& l) {
    for (int i = 0; i < l.size; i++)
        in >> l.data[i];
    return in;
}