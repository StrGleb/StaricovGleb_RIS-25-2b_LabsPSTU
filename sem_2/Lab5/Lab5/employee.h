#pragma once

#include "person.h"

class Employee : public Person {
protected:
	string post;
	double salary;

public:
	Employee();
	~Employee();
	void Show();

	Employee(string n, int a, string p, double s);
	Employee(const Employee& e);

	string getPost() { return post; }
	double getSalary() { return salary; }

	void setPost(string p);
	void setSalary(double s);

	double getFullSalary(double percent);

	Employee& operator = (const Employee&);

	friend istream& operator >> (istream& in, Employee&);
	friend ostream& operator << (ostream& out, const Employee&);
};