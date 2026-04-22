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

void countingSort(int arr[], int size) {
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

    int range = max - min + 1;

    int* count = new int[range];

    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[arr[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index] = i + min;
            index++;
            count[i]--;
        }
    }

    delete[] count;
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

    countingSort(arr, n);

    cout << "Отсортированный массив:\n";
    print(arr, n);

    delete[] arr;
}