#include <iostream>
#include <string>
#include <clocale>
using namespace std;

void buildShiftTable(const string& pattern, int shiftTable[]) {
    for (int i = 0; i < 256; i++)
        shiftTable[i] = pattern.length();

    for (int i = 0; i < pattern.length() - 1; i++)
        shiftTable[(unsigned char)pattern[i]] = pattern.length() - 1 - i;
}

int poisk(const string& text, const string& pattern) {
    if (pattern == "") return 0;
    if (pattern.length() > text.length()) return -1;

    int shiftTable[256];
    buildShiftTable(pattern, shiftTable);

    int i = 0;
    while (i <= text.length() - pattern.length()) {
        int j = pattern.length() - 1;

        while (j >= 0 && text[i + j] == pattern[j])
            j--;

        if (j < 0) return i;

        int shift = shiftTable[(unsigned char)text[i + j]] - (pattern.length() - 1 - j);

        if (shift <= 0)
            shift = 1;

        i += shift;
    }

    return -1;
}

int main() {
    setlocale(LC_ALL, "ru");

    string text, pattern;

    cout << "Введите строку: ";
    getline(cin, text);

    cout << "Введите шаблон: ";
    getline(cin, pattern);

    int pos = poisk(text, pattern);

    pos != -1 ?
        cout << "Подстрока найдена. Индекс первого символа: " << pos
        : cout << "Подстрока не найдена.";
}