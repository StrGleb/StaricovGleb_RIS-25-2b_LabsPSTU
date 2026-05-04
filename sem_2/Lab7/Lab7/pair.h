#pragma once

#include <iostream>
using namespace std;

class Pair {
private:
	int first;      // первое число пары
	double second;  // второе число пары

public:
	Pair() { first = 0; second = 0.0; } // конструктор без параметров
	Pair(int f, double s) { first = f; second = s; } // конструктор с параметрами
	Pair(const Pair& p) { first = p.first; second = p.second; } // конструктор копирования
	~Pair() {} // деструктор

	int getFirst() { return first; } // получить первое значение
	double getSecond() { return second; } // получить второе значение

	void setFirst(int f); // установить первое значение
	void setSecond(double s); // установить второе значение

	Pair& operator = (const Pair& p); // операция присваивания
	Pair operator + (const Pair& p);  // сложение двух пар
	Pair operator + (int k);          // прибавление числа к паре

	friend istream& operator >> (istream& in, Pair& p); // ввод пары
	friend ostream& operator << (ostream& out, const Pair& p); // вывод пары
};