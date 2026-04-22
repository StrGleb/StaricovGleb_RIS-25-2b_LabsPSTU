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

string* input_string(int n) {
	string* mas = new string[n];
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, mas[i]);
	}
	return mas;
}

void result(int* mas, int n, int key) {
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (key == mas[mid]) {
			cout << "Элемент найден. Индекс: " << mid;
			return;
		}
		else if (key > mas[mid]) left = mid + 1;
		else right = mid - 1;
	}
	cout << "Элемент не найден.";
}

void result(double* mas, int n, double key) {
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (fabs(key - mas[mid]) < 1e-9) {
			cout << "Элемент найден. Индекс: " << mid;
			return;
		}
		else if (key - mas[mid] > 1e-9) left = mid + 1;
		else right = mid - 1;
	}
	cout << "Элемент не найден.";
}

void result(string* mas, int n, const string& key) {
	int left = 0, right = n - 1, mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (key == mas[mid]) {
			cout << "Элемент найден. Индекс: " << mid;
			return;
		}
		else if (key > mas[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
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

		cout << "Введите элементы (в порядке возрастания): ";
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

		cout << "Введите элементы (в порядке возрастания): ";
		double* mas = input_double(n);

		double key;
		cout << "Введите ключ: ";
		cin >> key;

		result(mas, n, key);
		delete[] mas;
		break;
	}

	case 3: {
		cout << "Введите кол-во строк: ";
		cin >> n;

		cout << "Введите строки (в алфавитном порядке): ";
		string* mas = input_string(n);

		string key;
		cout << "Введите ключ: ";
		getline(cin, key);

		result(mas, n, key);

		delete[] mas;
		break;
	}

	default: {
		cout << "Неправильно набран номер.";
		break;
	}

	}
}