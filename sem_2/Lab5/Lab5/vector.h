#pragma once

#include "object.h"
#include <iostream>
using namespace std;

// Класс Vector (хранит указатели на Object)
class Vector {
private:
	Object** beg; // массив указателей на объекты
	int size;     // размер
	int cur;      // текущая позиция

public:
	Vector();        // конструктор без параметров
	Vector(int n);   // конструктор с размером
	~Vector();       // деструктор

	void Add(Object* p); // добавление элемента

	friend ostream& operator << (ostream& out, const Vector& v); // вывод
};