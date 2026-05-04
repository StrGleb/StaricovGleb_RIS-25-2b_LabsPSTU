#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class List {
private:
    T* data;   // динамический массив элементов
    int size;  // размер списка

public:
    // конструктор
    List(int s = 0, T k = T()) {
        size = s; // установка размера
        data = new T[size]; // выделение памяти

        for (int i = 0; i < size; i++)
            data[i] = k; // инициализация элементов
    }

    // конструктор копирования
    List(const List<T>& l) {
        size = l.size; // копирование размера
        data = new T[size]; // выделение памяти

        for (int i = 0; i < size; i++)
            data[i] = l.data[i]; // копирование элементов
    }

    // деструктор
    ~List() {
        delete[] data; // освобождение памяти
    }

    // операция присваивания
    List<T>& operator=(const List<T>& l) {
        if (this == &l) return *this; // проверка самоприсваивания

        if (data != 0) delete[] data; // очистка памяти

        size = l.size; // копирование размера
        data = new T[size]; // выделение памяти

        for (int i = 0; i < size; i++)
            data[i] = l.data[i]; // копирование элементов

        return *this; // возврат текущего объекта
    }

    // доступ по индексу
    T& operator[](int index) {
        if (index >= 0 && index < size)
            return data[index]; // возврат элемента

        cout << "Error index" << endl;
        exit(1);
    }

    // сложение списков
    List<T> operator+(const List<T>& l) {
        int minSize = (size < l.size) ? size : l.size; // минимальный размер

        List<T> temp(minSize, T()); // временный список

        for (int i = 0; i < minSize; i++)
            temp.data[i] = data[i] + l.data[i]; // поэлементное сложение

        return temp; // возврат результата
    }

    // прибавление значения ко всем элементам
    List<T> operator+(T k) {
        List<T> temp(size, T()); // временный список

        for (int i = 0; i < size; i++)
            temp.data[i] = data[i] + k; // прибавление

        return temp; // возврат результата
    }

    // вывод списка
    friend ostream& operator<<(ostream& out, const List<T>& l) {
        for (int i = 0; i < l.size; i++)
            out << l.data[i] << " "; // вывод элементов

        return out;
    }

    // ввод списка
    friend istream& operator>>(istream& in, List<T>& l) {
        for (int i = 0; i < l.size; i++)
            in >> l.data[i]; // ввод элементов

        return in;
    }
};