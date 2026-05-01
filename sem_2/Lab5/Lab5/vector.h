#pragma once

#include "object.h"
#include <iostream>
using namespace std;

class Vector {
private:
	Object** beg;
	int size;
	int cur;

public:
	Vector();
	Vector(int n);
	~Vector();

	void Add(Object* p);

	friend ostream& operator << (ostream& out, const Vector& v);
};