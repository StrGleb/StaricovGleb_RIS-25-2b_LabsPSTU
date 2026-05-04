#pragma once

#include "person.h"

// Производный класс Employee
class Employee : public Person {
protected:
	string post;   // должность
	double salary; // оклад

public:
	Employee();  // конструктор
	~Employee(); // деструктор
	void Show(); // переопределение виртуальной функции

	Employee(string n, int a, string p, double s); // конструктор с параметрами
	Employee(const Employee& e); // конструктор копирования

	string getPost() { return post; }   // селектор должности
	double getSalary() { return salary; } // селектор оклада

	void setPost(string p);   // модификатор должности
	void setSalary(double s); // модификатор оклада

	double getFullSalary(double percent); // расчет зарплаты с премией

	Employee& operator = (const Employee&); // присваивание

	friend istream& operator >> (istream& in, Employee&);   // ввод
	friend ostream& operator << (ostream& out, const Employee&); // вывод
};