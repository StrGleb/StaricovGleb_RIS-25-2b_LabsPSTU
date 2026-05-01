#pragma once
#include "Pair.h"
#include <iostream>
#include <fstream>

using namespace std;

inline int make_file(const char* f_name) {
    fstream stream(f_name, ios::out | ios::trunc);
    if (!stream) return -1;
    int n;
    Pair p;
    cout << "Count elements? "; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        stream << p;
    }
    stream.close();
    return n;
}

inline int print_file(const char* f_name) {
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Pair p; int i = 0;
    while (stream >> p) {
        cout << p << endl;
        i++;
    }
    stream.close();
    return i;
}

inline int del_equal(const char* f_name, Pair val) {
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Pair p;
    while (stream >> p) {
        if (!(p == val)) temp << p;
    }
    stream.close(); temp.close();
    remove(f_name);
    rename("temp", f_name);
    return 1;
}

inline int change_file(const char* f_name, Pair val, double L) {
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Pair p;
    while (stream >> p) {
        if (p == val) temp << (p - L);
        else temp << p;
    }
    stream.close(); temp.close();
    remove(f_name);
    rename("temp", f_name);
    return 1;
}

inline int add_after(const char* f_name, Pair target, int k) {
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Pair p;
    while (stream >> p) {
        temp << p;
        if (p == target) {
            for (int i = 0; i < k; i++) {
                Pair new_p;
                cout << "Enter new pair " << i + 1 << ":" << endl;
                cin >> new_p;
                temp << new_p;
            }
        }
    }
    stream.close(); temp.close();
    remove(f_name);
    rename("temp", f_name);
    return 1;
}