#include "List.h"
#include "Error.h"

List::List(int s) {
    if (s > MAX_SIZE) throw error("Vector length more than MAXSIZE");
    size = s;
    beg = new int[s];
    for (int i = 0; i < size; i++) beg[i] = 0;
}

List::List(const List& l) {
    size = l.size;
    beg = new int[size];
    for (int i = 0; i < size; i++) beg[i] = l.beg[i];
}

List::~List() {
    if (beg != nullptr) delete[] beg;
}

int& List::operator[](int i) {
    if (i < 0) throw error("index < 0");
    if (i >= size) throw error("index > size");
    return beg[i];
}

List List::operator+(int val) {
    if (size + 1 > MAX_SIZE) throw error("List overflow");
    List temp(size + 1);
    temp.beg[0] = val;
    for (int i = 0; i < size; i++) {
        temp.beg[i + 1] = beg[i];
    }
    return temp;
}

List List::operator+(const List& l) {
    if (size + l.size > MAX_SIZE) throw error("Merged list too large");
    List temp(size + l.size);
    for (int i = 0; i < size; i++) temp.beg[i] = beg[i];
    for (int i = 0; i < l.size; i++) temp.beg[size + i] = l.beg[i];
    return temp;
}

const List& List::operator=(const List& l) {
    if (this == &l) return *this;
    if (beg != nullptr) delete[] beg;
    size = l.size;
    beg = new int[size];
    for (int i = 0; i < size; i++) beg[i] = l.beg[i];
    return *this;
}

ostream& operator<<(ostream& out, const List& l) {
    if (l.size == 0) out << "Empty" << endl;
    else {
        for (int i = 0; i < l.size; i++) out << l.beg[i] << " ";
        out << endl;
    }
    return out;
}