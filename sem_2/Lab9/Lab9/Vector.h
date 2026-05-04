#pragma once
#include <iostream>
using namespace std;

const int MAX_VECTOR_SIZE = 30; // максимальный размер вектора

class Vector {
    int size; // текущий размер
    int* data; // указатель на массив

public:
    Vector(); // конструктор без параметров
    Vector(int s); // конструктор с размером
    Vector(int s, int* mas); // конструктор с массивом
    Vector(const Vector& v); // конструктор копирования
    ~Vector(); // деструктор

    const Vector& operator=(const Vector& v); // присваивание

    int operator()(); // получение размера

    int& operator[](int i); // доступ по индексу

    Vector operator+(const Vector& v); // сложение векторов
    Vector operator+(int val); // добавление элемента

    Vector operator--(); // удаление элемента

    friend ostream& operator<<(ostream& out, const Vector& v); // вывод
    friend istream& operator>>(istream& in, Vector& v); // ввод
};