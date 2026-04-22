#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

struct Film {
    char title[60];
    char director[60];
    int year;
    double price;
};

Film inputFilm() {
    Film f{};

    cout << "Название: ";
    cin.getline(f.title, 60);

    cout << "Режиссер: ";
    cin.getline(f.director, 60);

    cout << "Год: ";
    cin >> f.year;

    cout << "Стоимость: ";
    cin >> f.price;

    cin.ignore(100000, '\n');
    return f;
}

void printFilm(const Film& f) {
    cout << left << setw(20) << f.title
        << setw(20) << f.director
        << setw(8) << f.year
        << fixed << setprecision(2) << f.price
        << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    const char* fname = "films.dat";
    Film a[200];
    int n = 0;

    int m;
    cout << "Сколько фильмов ввести? ";
    cin >> m;
    cin.ignore(100000, '\n');

    FILE* fp = nullptr;

    fopen_s(&fp, fname, "wb");
    if (fp == NULL) {
        cout << "Ошибка открытия файла\n";
        return 0;
    }

    for (int i = 0; i < m; i++) {
        cout << "\nФильм #" << i + 1 << endl;
        Film f = inputFilm();
        fwrite(&f, sizeof(Film), 1, fp);
    }

    fclose(fp);

    fopen_s(&fp, fname, "rb");
    if (fp == NULL) {
        cout << "Ошибка открытия файла\n";
        return 0;
    }

    while (fread(&a[n], sizeof(Film), 1, fp) == 1)
        n++;

    fclose(fp);

    cout << "\nИсходный файл\n";
    for (int i = 0; i < n; i++)
        printFilm(a[i]);

    cout << "\nДобавить фильм в начало\n";
    Film add = inputFilm();

    for (int i = n; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = add;
    n++;

    double limit;
    cout << "\nУдалить фильмы дороже: ";
    cin >> limit;

    int k = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].price <= limit) {
            a[k] = a[i];
            k++;
        }
    }

    n = k;

    fopen_s(&fp, fname, "wb");
    if (fp == NULL) {
        cout << "Ошибка открытия файла\n";
        return 0;
    }

    fwrite(a, sizeof(Film), n, fp);

    fclose(fp);

    cout << "\nИтоговый файл\n";
    for (int i = 0; i < n; i++)
        printFilm(a[i]);

    return 0;
}