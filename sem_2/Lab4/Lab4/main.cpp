#include "Person.h"
#include "Employee.h"
#include <iostream>

using namespace std;

// функция с базовым классом (принцип подстановки)
void f1(Person& p) {
    p.setName("Ivan"); // изменение имени
    cout << p;         // вывод
}

// возврат базового класса (фактически возвращается Employee)
Person f2() {
    Employee e("Petr", 25, "manager", 50000); // создание объекта
    return e; // возврат как Person
}

int main() {
    Person a;                   // базовый объект
    Person b("Alex", 20);       // инициализация

    cin >> a;                   // ввод
    cout << a;                  // вывод

    cout << b;

    a = b;                      // присваивание
    cout << a << endl;

    Employee c;                 // объект производного класса
    cin >> c;                   // ввод
    cout << c;                  // вывод

    cout << "\nSalary with bonus: " << c.getFullSalary(20) << endl; // расчет зарплаты

    f1(c);                      // передача производного класса как базового

    a = f2();                   // получение объекта производного как базового
    cout << a;

    return 0;
}