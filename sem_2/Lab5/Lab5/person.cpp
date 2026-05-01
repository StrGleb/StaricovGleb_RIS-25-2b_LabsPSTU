#include "person.h"

Person::Person() {
	name = "";
	age = 0;
}

Person::~Person() {}

Person::Person(string n, int a) {
	name = n;
	age = a;
}

Person::Person(const Person& p) {
	name = p.name;
	age = p.age;
}

void Person::setName(string n) {
	name = n;
}

void Person::setAge(int a) {
	age = a;
}

Person& Person::operator = (const Person& p) {
	if (this == &p) return *this;

	name = p.name;
	age = p.age;
	return *this;
}

istream& operator >> (istream& in, Person& p) {
	cout << "enter name and age: ";
	in >> p.name >> p.age;
	return in;
}

ostream& operator << (ostream& out, const Person& p) {
	out << "\nName: " << p.name;
	out << "\nAge: " << p.age << "\n";
	return out;
}

void Person::Show() {
	cout << "\nName: " << name;
	cout << "\nAge: " << age << "\n";
}