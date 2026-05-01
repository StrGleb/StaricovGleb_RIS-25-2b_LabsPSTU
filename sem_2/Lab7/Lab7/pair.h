#pragma once

#include <iostream>
using namespace std;

class Pair {
private:
	int first;
	double second;

public:
	Pair() { first = 0; second = 0.0; }
	Pair(int f, double s) { first = f; second = s; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() {}

	int getFirst() { return first; }
	double getSecond() { return second; }

	void setFirst(int f);
	void setSecond(double s);

	Pair& operator = (const Pair& p);

	Pair operator + (const Pair& p);

	friend istream& operator >> (istream& in, Pair& p);
	friend ostream& operator << (ostream& out, const Pair& p);
};