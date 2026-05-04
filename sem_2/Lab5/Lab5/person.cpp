#include "person.h"

Person::Person() { name = ""; age = 0; } // конструктор без параметров

Person::~Person() {} // деструктор

Person::Person(string n, int a) { name = n; age = a; } // конструктор с параметрами

Person::Person(const Person& p) { name = p.name; age = p.age; } // копирование

void Person::setName(string n) { name = n; } // установка имени

void Person::setAge(int a) { age = a; } // установка возраста

Person& Person::operator = (const Person& p) {
	if (this == &p) return *this; // проверка самоприсваивания

	name = p.name; // копирование имени
	age = p.age;   // копирование возраста
	return *this;
}

istream& operator >> (istream& in, Person& p) {
	cout << "enter name and age: ";
	in >> p.name >> p.age; // ввод полей
	return in;
}

ostream& operator << (ostream& out, const Person& p) {
	out << "\nName: " << p.name;
	out << "\nAge: " << p.age << "\n"; // вывод
	return out;
}

void Person::Show() {
	cout << "\nName: " << name;
	cout << "\nAge: " << age << "\n"; // реализация виртуальной функции
}