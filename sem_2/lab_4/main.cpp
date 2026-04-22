#include <iostream>
#include <cstdlib>
#include <clocale>
using namespace std;

const int MAXN = 256;

bool vvod(int a[], int& n) {
    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0 || n > MAXN - 2) {
        cout << "Ошибка\n";
        return false;
    }

    int mode;
    cout << "Заполнение (0 - вручную, 1 - случайно): ";
    cin >> mode;

    if (mode == 1) {
        for (int i = 0; i < n; i++)
            a[i] = rand() % 101 - 50;
    }
    else if (mode == 0) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }
    else {
        cout << "Ошибка\n";
        return false;
    }

    return true;
}

bool vvod_k(int& k, int n) {
    cout << "Введите номер K (1.." << n << "): ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Ошибка\n";
        return false;
    }

    k--;
    return true;
}

void v_levo(const int a[], int n, int k) {
    int i = k;
    for (int cnt = 0; cnt < n; cnt++) {
        cout << a[i] << " ";
        i--;
        if (i < 0) i = n - 1;
    }
    cout << endl;
}

void v_pravo(const int a[], int n, int k) {
    int i = k;
    for (int cnt = 0; cnt < n; cnt++) {
        cout << a[i] << " ";
        i++;
        if (i == n) i = 0;
    }
    cout << endl;
}

void dobavit_1_i_posl(int a[], int& n) {
    a[n] = a[0];
    a[n + 1] = a[n - 1];
    n += 2;
}

int main() {
    setlocale(LC_ALL, "ru");

    int a[MAXN];
    int n, k;

    if (!vvod(a, n)) return 0;

    if (!vvod_k(k, n)) return 0;
    v_levo(a, n, k);

    dobavit_1_i_posl(a, n);

    if (!vvod_k(k, n)) return 0;
    v_pravo(a, n, k);

    return 0;
}