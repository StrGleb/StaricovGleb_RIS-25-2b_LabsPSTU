#include "Person.h"

void Person::setName(string n) {
    name = n;
}

void Person::setAge(int a) {
    age = a;
}

Person& Person::operator=(const Person& p) {
    if (this == &p) return *this;

    name = p.name;
    age = p.age;
    return *this;
}

istream& operator>>(istream& in, Person& p) {
    cout << "Enter name and age: ";
    in >> p.name >> p.age;
    return in;
}

ostream& operator<<(ostream& out, const Person& p) {
    out << "\nName: " << p.name
        << "\nAge: " << p.age << "\n";
    return out;
}