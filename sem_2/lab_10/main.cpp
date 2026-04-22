#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введите количество строк: ";
    cin >> n;
    cin.ignore();

    if (n <= 0) {
        cout << "Ошибка.\n";
        return 0;
    }

    string* arr = new string[n];

    cout << "Введите строки:\n";
    for (int i = 0; i < n; i++) {
        cout << "Строка [" << i + 1 << "]: ";
        getline(cin, arr[i]);
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].length() > arr[maxIndex].length()) {
            maxIndex = i;
        }
    }

    if (n == 1) {
        delete[] arr;
        cout << "Массив пуст.\n";
        return 0;
    }

    string* newArr = new string[n - 1];

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i != maxIndex) {
            newArr[j] = arr[i];
            j++;
        }
    }

    delete[] arr;
    arr = newArr;
    n--;

    cout << "\nНомер\tСтрока\n";
    cout << "------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << arr[i] << endl;
    }

    delete[] arr;
}