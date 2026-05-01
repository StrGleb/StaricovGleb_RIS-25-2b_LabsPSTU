#pragma once
#include "Person.h"

class Abiturient : public Person {
public:
    Abiturient(void);
    ~Abiturient(void);
    void Show();
    void Input();
    Abiturient(string, int, int, string);
    Abiturient(const Abiturient&);
    Abiturient& operator=(const Abiturient&);
protected:
    int score;
    string spec;
};