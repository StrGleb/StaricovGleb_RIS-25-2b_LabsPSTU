#include "object.h"
#include "person.h"
#include "employee.h"
#include "vector.h"

#include <iostream>
using namespace std;

int main() {
    Vector v(5); // создание вектора

    Person a;
    cin >> a; // ввод объекта Person
    cout << endl;

    Employee b;
    cin >> b; // ввод объекта Employee

    Object* p = &a; // указатель на базовый класс
    v.Add(p);       // добавление Person

    p = &b;         // указатель на Employee
    v.Add(p);       // добавление Employee

    cout << v;      // полиморфный вывод

    cout << "\nSalary with bonus: " << b.getFullSalary(20) << endl; // расчет зарплаты

    return 0;
}