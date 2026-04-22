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

bool splitToRuns(int arr[], int n, int left[], int& leftS, int right[], int& rightS) {
    leftS = 0;
    rightS = 0;

    bool toLeft = true;
    bool needSort = false;

    for (int i = 0; i < n; i++) {
        if (toLeft) {
            left[leftS++] = arr[i];
        }
        else {
            right[rightS++] = arr[i];
        }

        if (i < n - 1 && arr[i] > arr[i + 1]) {
            needSort = true;

            if (toLeft) {
                left[leftS++] = -1;
            }
            else {
                right[rightS++] = -1;
            }

            toLeft = !toLeft;
        }
    }

    if (toLeft) {
        left[leftS++] = -1;
    }
    else {
        right[rightS++] = -1;
    }

    return needSort;
}

void mergeRuns(int left[], int leftS, int right[], int rightS, int arr[], int& n) {
    int i = 0, j = 0, k = 0;

    while (i < leftS || j < rightS) {
        while (i < leftS && j < rightS && left[i] != -1 && right[j] != -1) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }

        while (i < leftS && left[i] != -1) {
            arr[k++] = left[i++];
        }

        while (j < rightS && right[j] != -1) {
            arr[k++] = right[j++];
        }

        if (i < leftS && left[i] == -1) {
            i++;
        }
        if (j < rightS && right[j] == -1) {
            j++;
        }
    }

    n = k;
}

void mergeSort(int arr[], int& n) {
    int left[200], right[200];
    int leftS, rightS;

    while (true) {
        bool needSort = splitToRuns(arr, n, left, leftS, right, rightS);

        if (!needSort) {
            break;
        }

        mergeRuns(left, leftS, right, rightS, arr, n);
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

    mergeSort(arr, n);

    cout << "Отсортированный массив:\n";
    print(arr, n);

    return 0;
}