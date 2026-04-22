#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int n;
    cout << "Введите кол-во элементов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка";
        return 0;
    }

    int mas[100];

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (mas[j] > mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
}