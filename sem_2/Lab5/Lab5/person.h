#pragma once

#include "object.h"
#include <iostream>
#include <string>
using namespace std;

class Person : public Object {
protected:
	string name;
	int age;

public:
	Person();
	virtual ~Person();
	void Show();

	Person(string n, int a);
	Person(const Person& p);

	string getName() { return name; }
	int getAge() { return age; }

	void setName(string n);
	void setAge(int a);

	Person& operator = (const Person&);

	friend istream& operator >> (istream& in, Person&);
	friend ostream& operator << (ostream& out, const Person&);
};