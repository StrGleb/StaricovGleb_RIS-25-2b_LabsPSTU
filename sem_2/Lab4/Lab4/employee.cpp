#include "Employee.h"

Employee::Employee() : Person() { post = ""; salary = 0.0; } // вызов конструктора базового класса

Employee::Employee(string n, int a, string p, double s) : Person(n, a) {
    post = p;       // установка должности
    salary = s;     // установка оклада
}

Employee::Employee(const Employee& e) : Person(e) {
    post = e.post;     // копирование должности
    salary = e.salary; // копирование оклада
}

Employee::~Employee() {} // деструктор

void Employee::setPost(string p) { post = p; } // установка должности

void Employee::setSalary(double s) { salary = s; } // установка оклада

double Employee::getFullSalary(double percent) {
    return salary + salary * percent / 100; // расчет: оклад + %
}

Employee& Employee::operator=(const Employee& e) {
    if (this == &e) return *this; // самоприсваивание

    Person::operator=(e); // вызов оператора базового класса
    post = e.post;        // копирование должности
    salary = e.salary;    // копирование оклада
    return *this;
}

istream& operator>>(istream& in, Employee& e) {
    cout << "Enter name age post salary: ";
    in >> e.name >> e.age >> e.post >> e.salary; // ввод всех полей
    return in;
}

ostream& operator<<(ostream& out, const Employee& e) {
    out << "\nName: " << e.name
        << "\nAge: " << e.age
        << "\nPost: " << e.post
        << "\nSalary: " << e.salary << "\n"; // вывод всех полей
    return out;
}