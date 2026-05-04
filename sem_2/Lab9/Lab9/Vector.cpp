#include "Vector.h"

// конструктор без параметров
Vector::Vector() {
    size = 0;
    data = nullptr;
}

// конструктор с размером
Vector::Vector(int s) {
    if (s > MAX_VECTOR_SIZE) throw 1; // превышен размер

    size = s;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = 0;
}

// конструктор с массивом
Vector::Vector(int s, int* mas) {
    if (s > MAX_VECTOR_SIZE) throw 1; // превышен размер

    size = s;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = mas[i];
}

// конструктор копирования
Vector::Vector(const Vector& v) {
    size = v.size;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = v.data[i];
}

// деструктор
Vector::~Vector() {
    delete[] data;
}

// оператор присваивания
const Vector& Vector::operator=(const Vector& v) {
    if (this == &v) return *this; // самоприсваивание

    delete[] data;

    size = v.size;
    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = v.data[i];

    return *this;
}

// получение размера
int Vector::operator()() {
    return size;
}

// доступ по индексу
int& Vector::operator[](int i) {
    if (i < 0) throw 2;        // индекс < 0
    if (i >= size) throw 3;    // индекс > size

    return data[i];
}

// сложение векторов
Vector Vector::operator+(const Vector& v) {
    if (size + v.size > MAX_VECTOR_SIZE) throw 4; // переполнение

    Vector temp(size + v.size);

    for (int i = 0; i < size; i++)
        temp.data[i] = data[i];

    for (int i = 0; i < v.size; i++)
        temp.data[size + i] = v.data[i];

    return temp;
}

// добавление элемента
Vector Vector::operator+(int val) {
    if (size + 1 > MAX_VECTOR_SIZE) throw 5; // переполнение

    Vector temp(size + 1);

    temp.data[0] = val;

    for (int i = 0; i < size; i++)
        temp.data[i + 1] = data[i];

    return temp;
}

// удаление элемента
Vector Vector::operator--() {
    if (size == 0) throw 6; // пустой вектор

    if (size == 1) {
        delete[] data;
        data = nullptr;
        size = 0;
        return *this;
    }

    Vector temp(size, data);

    delete[] data;
    size--;

    data = new int[size];

    for (int i = 0; i < size; i++)
        data[i] = temp.data[i];

    return *this;
}

// вывод
ostream& operator<<(ostream& out, const Vector& v) {
    if (v.size == 0) {
        out << "Empty\n";
        return out;
    }

    for (int i = 0; i < v.size; i++)
        out << v.data[i] << " ";

    out << endl;
    return out;
}

// ввод
istream& operator>>(istream& in, Vector& v) {
    for (int i = 0; i < v.size; i++) {
        cout << ">";
        in >> v.data[i];
    }
    return in;
}