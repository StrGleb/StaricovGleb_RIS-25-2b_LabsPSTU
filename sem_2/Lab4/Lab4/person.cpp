#include "Person.h"

void Person::setName(string n) { name = n; } // установка имени

void Person::setAge(int a) { age = a; } // установка возраста

Person& Person::operator=(const Person& p) {
    if (this == &p) return *this; // проверка самоприсваивания

    name = p.name; // копирование имени
    age = p.age;   // копирование возраста
    return *this;
}

istream& operator>>(istream& in, Person& p) {
    cout << "Enter name and age: ";
    in >> p.name >> p.age; // ввод полей
    return in;
}

ostream& operator<<(ostream& out, const Person& p) {
    out << "\nName: " << p.name
        << "\nAge: " << p.age << "\n"; // вывод полей
    return out;
}