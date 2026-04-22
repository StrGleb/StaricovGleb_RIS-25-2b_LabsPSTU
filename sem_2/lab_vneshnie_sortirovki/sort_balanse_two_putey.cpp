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

void mergeParts(int arr[], int left, int mid, int right) {
    int temp[200];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    mergeParts(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    cout << "Отсортированный массив:\n";
    print(arr, n);

    return 0;
}