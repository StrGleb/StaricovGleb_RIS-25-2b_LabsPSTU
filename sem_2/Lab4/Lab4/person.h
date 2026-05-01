#pragma once

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person() { name = ""; age = 0; }
    Person(string n, int a) { name = n; age = a; }
    Person(const Person& p) { name = p.name; age = p.age; }
    virtual ~Person() {}

    string getName() { return name; }
    int getAge() { return age; }

    void setName(string n);
    void setAge(int a);

    Person& operator=(const Person&);

    friend istream& operator>>(istream&, Person&);
    friend ostream& operator<<(ostream&, const Person&);
};