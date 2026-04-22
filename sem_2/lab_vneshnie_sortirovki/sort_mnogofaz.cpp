#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void filling(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void mergeTwo(int a[], int n1, int b[], int n2, int result[], int& n3) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            result[k++] = a[i++];
        }
        else {
            result[k++] = b[j++];
        }
    }

    while (i < n1) {
        result[k++] = a[i++];
    }

    while (j < n2) {
        result[k++] = b[j++];
    }

    n3 = k;
}

void multiphaseSort(int arr[], int n) {
    int file1[200], file2[200], file3[200];
    int n1 = 0, n2 = 0, n3 = 0;

    int mid = n / 2;

    for (int i = 0; i < mid; i++) {
        file1[n1++] = arr[i];
    }

    for (int i = mid; i < n; i++) {
        file2[n2++] = arr[i];
    }

    for (int i = 0; i < n1 - 1; i++) {
        for (int j = 0; j < n1 - i - 1; j++) {
            if (file1[j] > file1[j + 1]) {
                int temp = file1[j];
                file1[j] = file1[j + 1];
                file1[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n2 - 1; i++) {
        for (int j = 0; j < n2 - i - 1; j++) {
            if (file2[j] > file2[j + 1]) {
                int temp = file2[j];
                file2[j] = file2[j + 1];
                file2[j + 1] = temp;
            }
        }
    }

    mergeTwo(file1, n1, file2, n2, file3, n3);

    for (int i = 0; i < n3; i++) {
        arr[i] = file3[i];
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int arr[200];

    filling(arr, n);

    cout << "Исходный массив:\n";
    print(arr, n);

    multiphaseSort(arr, n);

    cout << "Отсортированный массив:\n";
    print(arr, n);

    return 0;
}