#include <iostream>
#include <clocale>
#include <string>
#include <cmath>
using namespace std;

int* input_int(int n) {
	int* m = new int[n];
	for (int i = 0; i < n; i++)
		cin >> m[i];
	return m;
}

double* input_double(int n) {
	double* m = new double[n];
	for (int i = 0; i < n; i++)
		cin >> m[i];
	return m;
}

string input_string() {
	string str;
	cin.ignore();
	getline(cin, str);

	return str;
}

void result(int* mas, int n, int key) {
	for (int i = 0; i < n; i++)
		if (key == mas[i]) {
			cout << "Элемент найден. Индекс: " << i;
			return;
		}
	cout << "Элемент не найден.";
}

void result(double* mas, int n, double key) {
	for (int i = 0; i < n; i++)
		if (fabs(mas[i] - key) < 1e-9) {
			cout << "Элемент найден. Индекс: " << i;
			return;
		}
	cout << "Элемент не найден.";
}

void result(const string& str, const string& key) {
	size_t pos = str.find(key);
	if (pos != string::npos) {
		cout << "Отрывок найден. Индекс первого символа: " << pos;
		return;
	}
	cout << "Элемент не найден.";
}

int main() {
	setlocale(LC_ALL, "ru");

	int choice, n;
	cout << "Выберите тип данных для поиска\n1. int\n2. double\n3. string\nВведите пункт: ";
	cin >> choice;

	switch (choice) {
	case 1: {
		cout << "Введите кол-во элементов: ";
		cin >> n;

		cout << "Введите элементы: ";
		int* mas = input_int(n);

		int key;
		cout << "Введите ключ: ";
		cin >> key;

		result(mas, n, key);
		delete[] mas;
		break;
	}

	case 2: {
		cout << "Введите кол-во элементов: ";
		cin >> n;

		cout << "Введите элементы: ";
		double* mas = input_double(n);

		double key;
		cout << "Введите ключ: ";
		cin >> key;

		result(mas, n, key);
		delete[] mas;
		break;
	}

	case 3: {
		cout << "Введите строку: ";
		string str = input_string();

		string key;
		cout << "Введите ключ: ";
		cin.ignore();
		getline(cin, key);

		result(str, key);
		break;
	}

	default: {
		cout << "Неправильно набран номер.";
		break;
	}

	}
}