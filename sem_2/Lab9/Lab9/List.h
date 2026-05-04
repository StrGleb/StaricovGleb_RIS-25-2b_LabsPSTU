#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 30; // максимальный размер списка

class List {
    int size; // количество элементов
    int* beg; // указатель на массив

public:
    List(); // конструктор без параметров
    List(int s); // конструктор с размером
    List(int s, int* mas); // конструктор с массивом
    List(const List& l); // конструктор копирования
    ~List(); // деструктор

    int operator()(); // получить размер

    int& operator[](int i); // доступ по индексу

    List operator+(int val); // добавление элемента
    List operator+(const List& l); // сложение списков

    List operator--(); // удаление элемента

    const List& operator=(const List& l); // присваивание

    friend ostream& operator<<(ostream& out, const List& l); // вывод
};