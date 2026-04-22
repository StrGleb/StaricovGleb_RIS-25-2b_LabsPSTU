#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str;
    cout << "Введите строку: ";
    getline(cin, str);

    const int MAX_WORDS = 100;
    string words[MAX_WORDS];
    int wordCount = 0;
    string temp = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ' && str[i] != '.') {
            temp += str[i];
        }
        else {
            if (temp.size() > 0) {
                if (wordCount < MAX_WORDS) {
                    words[wordCount++] = temp;
                }
                temp = "";
            }
        }
    }
    if (temp.size() > 0 && wordCount < MAX_WORDS) {
        words[wordCount++] = temp;
    }

    cout << "\nПосле разбиения строки:\n";
    for (int i = 0; i < wordCount; i++) {
        cout << "[" << i << "] " << words[i] << endl;
    }

    cout << "\nЧастота слов:\n";
    for (int i = 0; i < wordCount; i++) {
        bool pr = false;
        for (int p = 0; p < i; p++) {
            if (words[i] == words[p]) {
                pr = true;
                break;
            }
        }
        if (pr) continue;

        int k = 0;
        for (int j = 0; j < wordCount; j++) {
            if (words[i] == words[j])
                k++;
        }
        cout << words[i] << " — " << k << endl;
    }

    cout << "\nСлова, встречающиеся 1 раз:\n";
    bool search = false;
    for (int i = 0; i < wordCount; i++) {
        int k = 0;
        for (int j = 0; j < wordCount; j++) {
            if (words[i] == words[j])
                k++;
        }
        if (k == 1) {
            cout << words[i] << endl;
            search = true;
        }
    }

    if (!search)
        cout << "Таких слов нет.";
}