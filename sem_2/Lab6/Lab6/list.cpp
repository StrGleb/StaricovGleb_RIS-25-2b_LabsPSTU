#include "list.h"
#include <cstdlib>

List::List(int s, int k) {
    size = s; // установка размера списка
    data = new int[size]; // выделение памяти под массив

    for (int i = 0; i < size; i++)
        data[i] = k; // инициализация элементов

    beg.elem = &data[0]; // итератор на начало
    end.elem = &data[size]; // итератор на конец
}

List::List(const List& l) {
    size = l.size; // копирование размера
    data = new int[size]; // выделение памяти

    for (int i = 0; i < size; i++)
        data[i] = l.data[i]; // копирование элементов

    beg.elem = &data[0]; // итератор на начало
    end.elem = &data[size]; // итератор на конец
}

List::~List() {
    delete[] data; // освобождение памяти
}

List& List::operator=(const List& l) {
    if (this == &l) return *this; // проверка самоприсваивания

    if (data != 0) delete[] data; // освобождение старой памяти

    size = l.size; // копирование размера
    data = new int[size]; // выделение памяти

    for (int i = 0; i < size; i++)
        data[i] = l.data[i]; // копирование элементов

    beg.elem = &data[0]; // итератор на начало
    end.elem = &data[size]; // итератор на конец

    return *this; // возврат текущего объекта
}

int& List::operator[](int index) {
    if (index >= 0 && index < size)
        return data[index]; // доступ к элементу

    cout << "Error index" << endl;
    exit(1);
}

List List::operator+(const List& l) {
    int minSize = (size < l.size) ? size : l.size; // минимальный размер

    List temp(minSize, 0); // временный список

    for (int i = 0; i < minSize; i++)
        temp.data[i] = data[i] + l.data[i]; // сложение элементов

    return temp; // возврат результата
}

List List::operator+(const int k) {
    List temp(size, 0); // временный список

    for (int i = 0; i < size; i++)
        temp.data[i] = data[i] + k; // прибавление числа

    return temp; // возврат результата
}

Iterator List::first() {
    return beg; // итератор на начало
}

Iterator List::last() {
    return end; // итератор на конец
}

ostream& operator<<(ostream& out, const List& l) {
    for (int i = 0; i < l.size; i++)
        out << l.data[i] << " "; // вывод элементов

    return out;
}

istream& operator>>(istream& in, List& l) {
    for (int i = 0; i < l.size; i++)
        in >> l.data[i]; // ввод элементов

    return in;
}