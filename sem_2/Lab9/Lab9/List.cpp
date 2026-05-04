#include "List.h"
#include "Error.h"

// конструктор без параметров
List::List() {
    size = 0;
    beg = nullptr;
}

// конструктор с размером
List::List(int s) {
    if (s > MAX_SIZE)
        throw error("size > MAX_SIZE"); // ошибка размера

    size = s;
    beg = new int[size];

    for (int i = 0; i < size; i++)
        beg[i] = 0;
}

// конструктор с массивом
List::List(int s, int* mas) {
    if (s > MAX_SIZE)
        throw error("size > MAX_SIZE");

    size = s;
    beg = new int[size];

    for (int i = 0; i < size; i++)
        beg[i] = mas[i];
}

// конструктор копирования
List::List(const List& l) {
    size = l.size;
    beg = new int[size];

    for (int i = 0; i < size; i++)
        beg[i] = l.beg[i];
}

// деструктор
List::~List() {
    delete[] beg;
}

// оператор присваивания
const List& List::operator=(const List& l) {
    if (this == &l) return *this;

    delete[] beg;

    size = l.size;
    beg = new int[size];

    for (int i = 0; i < size; i++)
        beg[i] = l.beg[i];

    return *this;
}

// получение размера
int List::operator()() {
    return size;
}

// доступ по индексу
int& List::operator[](int i) {
    if (i < 0)
        throw error("index < 0"); // отрицательный индекс

    if (i >= size)
        throw error("index > size"); // выход за границы

    return beg[i];
}

// добавление элемента
List List::operator+(int val) {
    if (size + 1 > MAX_SIZE)
        throw error("overflow"); // переполнение

    List temp(size + 1);

    temp.beg[0] = val;

    for (int i = 0; i < size; i++)
        temp.beg[i + 1] = beg[i];

    return temp;
}

// сложение списков
List List::operator+(const List& l) {
    if (size + l.size > MAX_SIZE)
        throw error("overflow");

    List temp(size + l.size);

    for (int i = 0; i < size; i++)
        temp.beg[i] = beg[i];

    for (int i = 0; i < l.size; i++)
        temp.beg[size + i] = l.beg[i];

    return temp;
}

// удаление элемента
List List::operator--() {
    if (size == 0)
        throw error("empty list"); // пустой список

    if (size == 1) {
        delete[] beg;
        beg = nullptr;
        size = 0;
        return *this;
    }

    List temp(size, beg);

    delete[] beg;
    size--;

    beg = new int[size];

    for (int i = 0; i < size; i++)
        beg[i] = temp.beg[i];

    return *this;
}

// вывод
ostream& operator<<(ostream& out, const List& l) {
    if (l.size == 0) {
        out << "Empty\n";
        return out;
    }

    for (int i = 0; i < l.size; i++)
        out << l.beg[i] << " ";

    out << endl;
    return out;
}