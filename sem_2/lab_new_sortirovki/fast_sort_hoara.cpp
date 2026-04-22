#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void filling(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int partitionHoare(int arr[], int left, int right) {
    int pivot = arr[left + (right - left) / 2];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

void quickSortHoare(int arr[], int left, int right) {
    if (left < right) {
        int p = partitionHoare(arr, left, right);

        quickSortHoare(arr, left, p);
        quickSortHoare(arr, p + 1, right);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n];

    filling(arr, n);

    cout << "Исходный массив:\n";
    print(arr, n);

    quickSortHoare(arr, 0, n - 1);

    cout << "Отсортированный массив:\n";
    print(arr, n);

    delete[] arr;

    return 0;
}