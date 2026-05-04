#pragma once

#include "object.h"
#include <iostream>
#include <string>
using namespace std;

// Класс Person, наследуется от абстрактного класса Object
class Person : public Object {
protected:
	string name; // имя
	int age;     // возраст

public:
	Person();                // конструктор без параметров
	virtual ~Person();       // виртуальный деструктор
	void Show();             // переопределение виртуальной функции

	Person(string n, int a); // конструктор с параметрами
	Person(const Person& p); // конструктор копирования

	string getName() { return name; } // селектор имени
	int getAge() { return age; }      // селектор возраста

	void setName(string n); // модификатор имени
	void setAge(int a);     // модификатор возраста

	Person& operator = (const Person&); // оператор присваивания

	friend istream& operator >> (istream& in, Person&);   // ввод
	friend ostream& operator << (ostream& out, const Person&); // вывод
};