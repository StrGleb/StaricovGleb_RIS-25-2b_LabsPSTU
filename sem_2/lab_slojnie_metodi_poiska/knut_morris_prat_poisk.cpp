#include <iostream>
#include <clocale>
#include <string>
using namespace std;

void buildPrefix(const string& pattern, int prefix[], int size) {
    int j = 0;
    prefix[0] = 0;

    for (int i = 1; i < size; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = prefix[j - 1];

        if (pattern[i] == pattern[j])
            j++;

        prefix[i] = j;
    }
}

int search(const string& text, const string& pattern) {
    if (pattern == "") return 0;
    if (pattern.length() > text.length()) return -1;

    const int size = pattern.length();
    int* prefix = new int[size];
    buildPrefix(pattern, prefix, size);

    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        while (j > 0 && text[i] != pattern[j])
            j = prefix[j - 1];

        if (text[i] == pattern[j])
            j++;

        if (j == pattern.length()) {
            delete[] prefix;
            return i - pattern.length() + 1;
        }
    }

    delete[] prefix;
    return -1;
}

int main() {
    setlocale(LC_ALL, "ru");

    string text, pattern;
    cout << "Введите строку: ";
    getline(cin, text);

    cout << "Введите шаблон: ";
    getline(cin, pattern);

    int pos = search(text, pattern);

    pos != -1
        ? cout << "Подстрока найдена. Индекс первого символа: " << pos
        : cout << "Подстрока не найдена.";
}