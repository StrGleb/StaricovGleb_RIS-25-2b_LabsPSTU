#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

bool isLet(unsigned char c) {
    return (c >= 192 && c <= 255) || c == 168 || c == 184;
}

unsigned char low(unsigned char c) {
    if (c >= 192 && c <= 223) { return (unsigned char)(c + 32); }
    if (c == 168) { return 184; }
    return c;
}

bool isVow(unsigned char c) {
    return c == 224 || c == 229 || c == 184 || c == 232 || c == 238 ||
        c == 243 || c == 251 || c == 253 || c == 254 || c == 255;
}

int cntCons(const string& w) {
    int k = 0;
    for (int i = 0; i < (int)w.size(); i++) {
        unsigned char c = (unsigned char)w[i];
        if (!isLet(c)) { continue; }
        c = low(c);
        if (!isVow(c)) { k++; }
    }
    return k;
}

int cntWords(const string& s) {
    int k = 0;
    bool in = false;
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        bool sep = (c == ' ' || c == '\t');
        if (!sep && !in) {
            k++;
            in = true;
        }
        else if (sep) {
            in = false;
        }
    }
    return k;
}

void printFile(const string& fn) {
    ifstream f(fn);
    if (!f.is_open()) {
        cout << "Не удалось открыть файл " << fn << "\n";
        return;
    }

    string s;
    int ln = 0;

    cout << "\n===== " << fn << " =====\n";
    while (getline(f, s)) {
        ln++;
        cout << ln << ") " << s << "\n";
    }
    cout << "====================\n";

    f.close();
}

void upd(int n, int k, int& mx, int a[], int& m) {
    if (k > mx) {
        mx = k;
        m = 0;
        a[m++] = n;
    }
    else if (k == mx) {
        a[m++] = n;
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string F1 = "C:\\Users\\sgleb\\OneDrive\\Desktop\\Education\\kurs_1\\Informatics\\sem_2\\lab_9_2\\F1.txt";
    string F2 = "F2.txt";

    cout << "ИСХОДНЫЙ ФАЙЛ:\n";
    printFile(F1);

    ifstream f1(F1);
    ofstream f2(F2);

    if (!f1.is_open() || !f2.is_open()) {
        cout << "Ошибка открытия файлов\n";
        return 0;
    }

    string s, w;
    int n = 0;
    int mx = -1;
    int a[10000];
    int m = 0;

    while (getline(f1, s)) {

        if (cntWords(s) == 2) {
            f2 << s << "\n";
        }

        w = "";
        for (int i = 0; i <= (int)s.size(); i++) {
            char c = (i < (int)s.size() ? s[i] : ' ');

            if (c == ' ' || c == '\t') {
                if (w != "") {
                    n++;
                    int k = cntCons(w);
                    upd(n, k, mx, a, m);
                    w = "";
                }
            }
            else {
                w += c;
            }
        }
    }

    f1.close();
    f2.close();

    cout << "\nИТОГОВЫЙ ФАЙЛ (F2):\n";
    printFile(F2);

    cout << "\nМаксимум согласных: " << mx / 2 << "\n";
    cout << "Номера слов (из исходного файла): ";
    for (int i = 0; i < m; i++) {
        cout << a[i];
        if (i + 1 < m) { cout << " "; }
    }
    cout << "\n";

    return 0;
}