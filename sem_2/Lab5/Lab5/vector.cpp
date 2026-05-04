#include "vector.h"

Vector::Vector() { beg = 0; size = 0; cur = 0; } // пустой вектор

Vector::Vector(int n) {
	beg = new Object * [n]; // выделение памяти
	size = n;
	cur = 0;
}

Vector::~Vector() {
	if (beg != 0) delete[] beg; // освобождение памяти
	beg = 0;
}

void Vector::Add(Object* p) {
	if (cur < size) {
		beg[cur] = p; // добавление указателя
		cur++;        // увеличение позиции
	}
}

ostream& operator << (ostream& out, const Vector& v) {
	if (v.size == 0) out << "empty" << endl;

	Object** p = v.beg; // указатель на массив

	for (int i = 0; i < v.cur; i++) {
		(*p)->Show(); // вызов виртуальной функции (полиморфизм)
		p++;           // переход к следующему объекту
	}

	return out;
}