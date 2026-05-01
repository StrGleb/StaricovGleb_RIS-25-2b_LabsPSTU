#pragma once

#include "Person.h"

class Employee : public Person {
protected:
    string post;
    double salary;

public:
    Employee();
    Employee(string n, int a, string p, double s);
    Employee(const Employee&);
    ~Employee();

    string getPost() { return post; }
    double getSalary() { return salary; }

    void setPost(string p);
    void setSalary(double s);

    double getFullSalary(double percent);

    Employee& operator=(const Employee&);

    friend istream& operator>>(istream&, Employee&);
    friend ostream& operator<<(ostream&, const Employee&);
};