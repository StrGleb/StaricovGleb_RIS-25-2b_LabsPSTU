#include "List.h"

// Конструктор с проверкой размера
List::List(int s) {
    if (s > MAX_SIZE) throw 1; // Ошибка 1
    size = s;
    beg = new int[s];
    for (int i = 0; i < size; i++) beg[i] = 0;
}

// Конструктор копирования
List::List(const List& l) {
    size = l.size;
    beg = new int[size];
    for (int i = 0; i < size; i++) beg[i] = l.beg[i];
}

List::~List() {
    if (beg != nullptr) delete[] beg;
}

// Доступ по индексу с двумя проверками[cite: 6]
int& List::operator[](int i) {
    if (i < 0) throw 2;       // Ошибка 2[cite: 6]
    if (i >= size) throw 3;    // Ошибка 3[cite: 6]
    return beg[i];
}

// ОПЕРАЦИЯ: Добавление числа в НАЧАЛО списка
List List::operator+(int val) {
    if (size + 1 > MAX_SIZE) throw 4; // Ошибка 4[cite: 6]
    List temp(size + 1);
    temp.beg[0] = val; // Новое число в начало[cite: 6]
    for (int i = 0; i < size; i++) {
        temp.beg[i + 1] = beg[i]; // Остальные сдвигаем
    }
    return temp;
}

// ОПЕРАЦИЯ: Добавление списка к списку (a + b)
List List::operator+(const List& l) {
    if (size + l.size > MAX_SIZE) throw 1; // Проверка общего размера[cite: 6]
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