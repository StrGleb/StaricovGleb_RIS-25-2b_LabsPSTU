#include "Person.h"

Person::Person(void) { name = ""; age = 0; }
Person::~Person(void) {}
Person::Person(string N, int A) { name = N; age = A; }
Person::Person(const Person& p) { name = p.name; age = p.age; }

Person& Person::operator=(const Person& p) {
    if (&p == this) return *this;
    name = p.name;
    age = p.age;
    return *this;
}

void Person::Show() {
    cout << "\nNAME: " << name << "\nAGE: " << age << endl;
}

void Person::Input() {
    cout << "\nName: "; cin >> name;
    cout << "\nAge: "; cin >> age;
}

void Person::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        switch (e.command) {
        case cmGet:
            // Здесь можно вывести имя объекта при запросе 'z'
            cout << "Checking person: " << name << endl;
            break;
        }
    }
}