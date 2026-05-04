#pragma once
#include <string>
#include <iostream>
using namespace std;

// класс для представления ошибки
class error {
    string str; // текст ошибки

public:
    // конструктор с параметром
    error(string s) {
        str = s;
    }

    // вывод сообщения об ошибке
    void what() {
        cout << str << endl;
    }
};