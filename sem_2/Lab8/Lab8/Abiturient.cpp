#include "Abiturient.h"

Abiturient::Abiturient(void) : Person() { score = 0; spec = ""; }
Abiturient::~Abiturient(void) {}

Abiturient::Abiturient(string N, int A, int S, string Sp) : Person(N, A) {
    score = S;
    spec = Sp;
}

Abiturient::Abiturient(const Abiturient& a) {
    name = a.name; age = a.age;
    score = a.score; spec = a.spec;
}

Abiturient& Abiturient::operator=(const Abiturient& a) {
    if (&a == this) return *this;
    Person::operator=(a);
    score = a.score;
    spec = a.spec;
    return *this;
}

void Abiturient::Show() {
    cout << "\nNAME: " << name << "\nAGE: " << age;
    cout << "\nSCORE: " << score << "\nSPEC: " << spec << endl;
}

void Abiturient::Input() {
    cout << "\nName: "; cin >> name;
    cout << "\nAge: "; cin >> age;
    cout << "\nScore: "; cin >> score;
    cout << "\nSpec: "; cin >> spec;
}