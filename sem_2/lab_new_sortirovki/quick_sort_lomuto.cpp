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

int partitionLomuto(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSortLomuto(int arr[], int left, int right) {
    if (left < right) {
        int p = partitionLomuto(arr, left, right);

        quickSortLomuto(arr, left, p - 1);
        quickSortLomuto(arr, p + 1, right);
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

    quickSortLomuto(arr, 0, n - 1);

    cout << "Отсортированный массив:\n";
    print(arr, n);

    delete[] arr;

    return 0;
}