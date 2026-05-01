#include "Employee.h"

Employee::Employee() : Person() {
    post = "";
    salary = 0.0;
}

Employee::~Employee() {}

Employee::Employee(string n, int a, string p, double s) : Person(n, a) {
    post = p;
    salary = s;
}

Employee::Employee(const Employee& e) : Person(e) {
    post = e.post;
    salary = e.salary;
}

void Employee::setPost(string p) {
    post = p;
}

void Employee::setSalary(double s) {
    salary = s;
}

double Employee::getFullSalary(double percent) {
    return salary + salary * percent / 100;
}

Employee& Employee::operator=(const Employee& e) {
    if (this == &e) return *this;

    Person::operator=(e);
    post = e.post;
    salary = e.salary;
    return *this;
}

istream& operator>>(istream& in, Employee& e) {
    cout << "enter name age post salary: ";
    in >> e.name >> e.age >> e.post >> e.salary;
    return in;
}

ostream& operator<<(ostream& out, const Employee& e) {
    out << "\nName: " << e.name;
    out << "\nAge: " << e.age;
    out << "\nPost: " << e.post;
    out << "\nSalary: " << e.salary << "\n";
    return out;
}

void Employee::Show() {
    cout << "\nName: " << name;
    cout << "\nAge: " << age;
    cout << "\nPost: " << post;
    cout << "\nSalary: " << salary << "\n";
}