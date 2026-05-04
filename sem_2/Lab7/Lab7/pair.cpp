#include "Pair.h"

void Pair::setFirst(int f) {
	first = f; // установка первого значения
}

void Pair::setSecond(double s) {
	second = s; // установка второго значения
}

Pair& Pair::operator = (const Pair& p) {
	if (this == &p) return *this; // проверка самоприсваивания

	first = p.first;   // копирование первого значения
	second = p.second; // копирование второго значения
	return *this;      // возврат текущего объекта
}

Pair Pair::operator + (const Pair& p) {
	Pair temp; // временный объект

	temp.first = first + p.first;     // сложение первых значений
	temp.second = second + p.second;  // сложение вторых значений

	return temp; // возврат результата
}

Pair Pair::operator + (int k) {
	return Pair(first + k, second + k); // прибавление числа к обоим полям
}

istream& operator >> (istream& in, Pair& p) {
	cout << "enter first and second: ";
	in >> p.first >> p.second; // ввод значений
	return in;
}

ostream& operator << (ostream& out, const Pair& p) {
	out << p.first << " : " << p.second; // вывод пары
	return out;
}