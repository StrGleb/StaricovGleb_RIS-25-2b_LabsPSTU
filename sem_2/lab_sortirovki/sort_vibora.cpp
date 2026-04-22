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
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (mas[j] < mas[minIndex]) {
                minIndex = j;
            }
        }

        int temp = mas[i];
        mas[i] = mas[minIndex];
        mas[minIndex] = temp;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
}