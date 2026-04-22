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

void merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* leftP = new int[size1];
    int* rightP = new int[size2];

    for (int i = 0; i < size1; i++) {
        leftP[i] = arr[left + i];
    }

    for (int i = 0; i < size2; i++) {
        rightP[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2) {
        if (leftP[i] <= rightP[j]) {
            arr[k] = leftP[i];
            i++;
        }
        else {
            arr[k] = rightP[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = leftP[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = rightP[j];
        j++;
        k++;
    }

    delete[] leftP;
    delete[] rightP;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    cout << "Отсортированный массив:\n";
    print(arr, n);

    delete[] arr;
}