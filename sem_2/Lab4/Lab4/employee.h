#pragma once

#include "Person.h"

// Производный класс
class Employee : public Person {
protected:
    string post;   // должность
    double salary; // оклад

public:
    Employee(); // конструктор без параметров
    Employee(string n, int a, string p, double s); // конструктор с параметрами
    Employee(const Employee&); // конструктор копирования
    ~Employee(); // деструктор

    string getPost() { return post; }   // селектор должности
    double getSalary() { return salary; } // селектор зарплаты

    void setPost(string p);   // модификатор должности
    void setSalary(double s); // модификатор зарплаты

    double getFullSalary(double percent); // расчет зарплаты с премией

    Employee& operator=(const Employee&); // операция присваивания

    friend istream& operator>>(istream&, Employee&);       // ввод
    friend ostream& operator<<(ostream&, const Employee&); // вывод
};