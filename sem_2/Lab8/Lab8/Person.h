#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Person : public Object {
public:
    Person(void);
    virtual ~Person(void);
    void Show();
    void Input();
    Person(string, int);
    Person(const Person&);

    int Get_age() { return age; }
    Person& operator=(const Person&);
    void HandleEvent(const TEvent& e);
protected:
    string name;
    int age;
};