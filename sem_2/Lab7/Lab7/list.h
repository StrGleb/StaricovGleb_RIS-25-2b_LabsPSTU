#pragma once

#include <iostream>
using namespace std;

template <class T>
class List {
private:
	int size;
	T* data;

public:
	List(int s, T k);
	List(const List<T>& l);
	~List();

	List& operator = (const List<T>& l);

	T& operator [] (int index);

	List operator + (const List<T>& l);
	List operator + (const T k);

	friend ostream& operator << <> (ostream& out, const List<T>& l);
	friend istream& operator >> <> (istream& in, List<T>& l);
};

template <class T>
List<T>::List(int s, T k) {
	size = s;
	data = new T[size];

	for (int i = 0; i < size; i++)
		data[i] = k;
}

template <class T>
List<T>::List(const List<T>& l) {
	size = l.size;
	data = new T[size];

	for (int i = 0; i < size; i++)
		data[i] = l.data[i];
}

template <class T>
List<T>::~List() {
	delete[] data;
	data = 0;
}

template <class T>
List<T>& List<T>::operator = (const List<T>& l) {
	if (this == &l) return *this;

	size = l.size;

	if (data != 0) delete[] data;

	data = new T[size];

	for (int i = 0; i < size; i++)
		data[i] = l.data[i];

	return *this;
}

template <class T>
T& List<T>::operator [] (int index) {
	if (index >= 0 && index < size)
		return data[index];

	cout << "error index";
	return data[0];
}

template <class T>
List<T> List<T>::operator + (const List<T>& l) {
	int minSize;

	if (size < l.size)
		minSize = size;
	else
		minSize = l.size;

	List<T> temp(minSize, data[0]);

	for (int i = 0; i < minSize; i++)
		temp.data[i] = data[i] + l.data[i];

	return temp;
}

template <class T>
List<T> List<T>::operator + (const T k) {
	List<T> temp(size, data[0]);

	for (int i = 0; i < size; i++)
		temp.data[i] = data[i] + k;

	return temp;
}

template <class T>
ostream& operator << (ostream& out, const List<T>& l) {
	for (int i = 0; i < l.size; i++)
		out << l.data[i] << " ";

	return out;
}

template <class T>
istream& operator >> (istream& in, List<T>& l) {
	for (int i = 0; i < l.size; i++)
		in >> l.data[i];

	return in;
}