#pragma once
#include "Pair.h"
#include <fstream>
#include <cstdio>
using namespace std;

// создание файла
int make_file(const char* f_name) {
    fstream stream(f_name, ios::out | ios::trunc);
    if (!stream) return -1;

    int n;
    Pair p;

    cout << "Count of pairs: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p;
        stream << p << endl;
    }

    stream.close();
    return n;
}

// вывод файла
int print_file(const char* f_name) {
    fstream stream(f_name, ios::in);
    if (!stream) return -1;

    Pair p;
    int count = 0;

    while (stream >> p) {
        cout << p << endl;
        count++;
    }

    stream.close();
    return count;
}

// удаление записей, равных значению
int del_equal(const char* f_name, Pair val) {
    fstream stream(f_name, ios::in);
    fstream temp("temp", ios::out);

    if (!stream) return -1;

    Pair p;
    int count = 0;

    while (stream >> p) {
        if (!(p == val))
            temp << p << endl;
        else
            count++; // считаем удалённые элементы
    }

    stream.close();
    temp.close();

    remove(f_name);
    rename("temp", f_name);

    return count;
}

// изменение записей (уменьшение на L) С ПОДТВЕРЖДЕНИЕМ
int change_file(const char* f_name, Pair val, double L) {
    fstream stream(f_name, ios::in);
    fstream temp("temp", ios::out);

    if (!stream) return -1;

    Pair p;
    int count = 0;
    char x;

    while (stream >> p) {
        if (p == val) {
            cout << p << " - is changing... Continue[y/n]?\n";
            cin >> x;

            if (x == 'y' || x == 'Y') {
                temp << (p - L) << endl;
                count++;
            }
            else {
                temp << p << endl;
            }
        }
        else {
            temp << p << endl;
        }
    }

    stream.close();
    temp.close();

    remove(f_name);
    rename("temp", f_name);

    return count;
}

// добавление в конец (как в методичке)
int add_end(const char* f_name, Pair p) {
    fstream stream(f_name, ios::app);
    if (!stream) return -1;

    stream << p << endl;
    stream.close();
    return 1;
}

// добавление K записей после заданного значения
int add_after(const char* f_name, Pair target, int k) {
    fstream stream(f_name, ios::in);
    fstream temp("temp", ios::out);

    if (!stream) return -1;

    Pair p;
    int found = 0;

    while (stream >> p) {
        temp << p << endl;

        if (p == target) {
            found = 1;

            for (int i = 0; i < k; i++) {
                Pair new_p;
                cout << "New pair:\n";
                cin >> new_p;
                temp << new_p << endl;
            }
        }
    }

    stream.close();
    temp.close();

    remove(f_name);
    rename("temp", f_name);

    return found; // если 0 -> не нашли элемент
}