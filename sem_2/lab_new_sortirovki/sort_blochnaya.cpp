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

void bucketSort(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        else if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketCount = 5;

    int** buckets = new int* [bucketCount];
    int* bucketSizes = new int[bucketCount];

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = new int[size];
        bucketSizes[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int index = (arr[i] - min) * bucketCount / (max - min + 1);
        buckets[index][bucketSizes[index]] = arr[i];
        bucketSizes[index]++;
    }

    for (int i = 0; i < bucketCount; i++) {
        for (int j = 1; j < bucketSizes[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }

            buckets[i][k + 1] = key;
        }
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }

    for (int i = 0; i < bucketCount; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
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

    bucketSort(arr, n);

    cout << "Отсортированный массив:\n";
    print(arr, n);

    delete[] arr;
}