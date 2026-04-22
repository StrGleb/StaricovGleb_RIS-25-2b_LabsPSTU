#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

double f(int mas[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += mas[i];

    return (double)sum / n;
}

int f(string s) {
    int k = 0;

    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'А' && s[i] <= 'я'))
            k++;
    }
    return k;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    int arr[100];

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    double avg = f(arr, n);
    cout << "Среднее арифметическое: " << avg << endl;

    cin.ignore();

    string s;
    cout << "\nВведите строку: ";
    getline(cin, s);

    int letters = f(s);
    cout << "Количество букв в строке: " << letters << endl;
}