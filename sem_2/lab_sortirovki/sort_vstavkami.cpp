
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

    for (int i = 1; i < n; i++) {
        int temp = mas[i];
        int j = i - 1;

        while (j >= 0 && mas[j] > temp) {
            mas[j + 1] = mas[j];
            j--;
        }

        mas[j + 1] = temp;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }

    return 0;
}