#include <iostream>
using namespace std;

double* input(int n) {
	double* mas = new double[n];
	cout << "Введите элементы: ";
	for (int i = 0; i < n; i++)
		cin >> mas[i];

	return mas;
}

void poisk(const double* A, int n, double key) {
	int left = 0, right = n - 1, mid;

	while (left <= right && key >= A[left] && key <= A[right]) {

		if (A[left] == A[right]) {
			if (fabs(key - A[left]) < 1e-9) {
				cout << "Элемент найден. Индекс: " << left;
				return;
			}
			else {
				cout << "Элемент не найден.";
			}
			return;
		}

		mid = left + (key - A[left]) * (right - left) / (A[right] - A[left]);
		if (fabs(A[mid] - key) < 1e-9) {
			cout << "Элемент найден. Индекс: " << mid;
			return;
		}
		else if (key > A[mid] + 1e-9) left = mid + 1;
		else right = mid - 1;
	}
	cout << "Элемент не найден.";
}

int main() {
	setlocale(LC_ALL, "ru");

	int n;
	cout << "Введите кол-во элементов: ";
	cin >> n;

	double* A = input(n);

	double key;
	cout << "Введите ключ: ";
	cin >> key;

	poisk(A, n, key);

	delete[] A;
}