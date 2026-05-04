#pragma once

#include <iostream>
#include <string>
using namespace std;

// базовый класс 
class Person {
protected:
    string name; // имя
    int age;     // возраст

public:
    Person() { name = ""; age = 0; }                    // конструктор без параметров
    Person(string n, int a) { name = n; age = a; }      // конструктор с параметрами
    Person(const Person& p) { name = p.name; age = p.age; } // конструктор копирования
    virtual ~Person() {}                                // виртуальный деструктор

    string getName() { return name; } // селектор имени
    int getAge() { return age; }      // селектор возраста

    void setName(string n); // модификатор имени
    void setAge(int a);     // модификатор возраста

    Person& operator=(const Person&); // операция присваивания

    friend istream& operator>>(istream&, Person&);       // ввод объекта
    friend ostream& operator<<(ostream&, const Person&); // вывод объекта
};