#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void filling_the_array_1(int a, int b, int mas[100][100]) {
	cout << "Введите элементы массива:\n";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> mas[i][j];
		}
	}
}

void filling_the_array_2(int a, int b, int mas[100][100]) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			mas[i][j] = rand() % 100;
		}
	}
}

void array_output(int a, int b, int mas[100][100]) {
	cout << "Вывод массива:\n";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << setw(3) << mas[i][j];
		}
		cout << endl;
	}
}

void array_output_with_selection(int a, int b, int mas[100][100], int MaxX, int MaxY) {
	cout << "Вывод массива (с выделением подмассива):\n";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (i >= MaxX && i < MaxX + 3 && j >= MaxY && j < MaxY + 3) {
				cout << '[' << setw(3) << mas[i][j] << ']';
			}
			else {
				cout << " " << setw(3) << mas[i][j] << ' ';
			}
		}
		cout << endl;
	}
}

void compare(int a, int b, int mas[100][100], int& MaxX, int& MaxY, int& MaxSum) {
	MaxSum = -999;
	for (int i = 0; i <= a - 3; i++) {
		for (int j = 0; j <= b - 3; j++) {
			int sum = 0;

			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 3; l++) {
					sum += mas[k][l];
				}
			}
			if (sum > MaxSum) {
				MaxSum = sum;
				MaxX = i;
				MaxY = j;
			}
		}
	}
	cout << "Максимальный подмассив 3*3:\n";
	for (int i = MaxX; i < MaxX + 3; i++) {
		for (int j = MaxY; j < MaxY + 3; j++) {
			cout << setw(3) << mas[i][j];
		}
		cout << endl;
	}
	cout << "Сумма подмассива: " << MaxSum << "\nАдрес подмассива: (" << MaxX << ", " << MaxY << ")\n";
}

int main() {
	setlocale(LC_ALL, "ru");

	int m, n, arr[100][100], MaxX, MaxY, MaxSum, q;
	cout << "Введите размер двумерного массива (2 числа): ";
	cin >> n >> m;

	if (n < 3 || m < 3) {
		cout << "Размер массива должен быть не меньше 3х3, ошибка!" << endl;
		return 0;
	}

	cout << "Как заполнить массив? (1 - вручную, 2 - случайными числами): ";
	cin >> q;

	srand(time(0));
	if (q == 1) filling_the_array_1(n, m, arr);
	else if (q == 2) filling_the_array_2(n, m, arr);
	else {
		cout << "Неверно набрано число, ошибка!" << endl;
		return 0;
	}

	array_output(n, m, arr);
	compare(n, m, arr, MaxX, MaxY, MaxSum);
	array_output_with_selection(n, m, arr, MaxX, MaxY);
}