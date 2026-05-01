#include "Pair.h"

void Pair::setFirst(int f) {
	first = f;
}

void Pair::setSecond(double s) {
	second = s;
}

Pair& Pair::operator = (const Pair& p) {
	if (this == &p) return *this;

	first = p.first;
	second = p.second;
	return *this;
}

Pair Pair::operator + (const Pair& p) {
	Pair temp;

	temp.first = first + p.first;
	temp.second = second + p.second;

	return temp;
}

istream& operator >> (istream& in, Pair& p) {
	cout << "enter first and second: ";
	in >> p.first >> p.second;
	return in;
}

ostream& operator << (ostream& out, const Pair& p) {
	out << p.first << " : " << p.second;
	return out;
}