#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

string removeSpacesAtStart(const string& line) {
    int i = 0;
    while (i < (int)line.size() && (line[i] == ' ' || line[i] == '\t')) {
        i++;
    }
    return line.substr(i);
}

bool startsWithA(const string& line) {
    string s = removeSpacesAtStart(line);
    if (s.size() == 0) {
        return false;
    }
    return (s[0] == 'А' || s[0] == 'а' || s[0] == 'A' || s[0] == 'a');
}

int countWordsInLine(const string& line) {
    int words = 0;
    bool insideWord = false;

    for (int i = 0; i < (int)line.size(); i++) {
        char c = line[i];
        bool separator = (c == ' ' || c == '\t');

        if (!separator && !insideWord) {
            words++;
            insideWord = true;
        }
        else if (separator) {
            insideWord = false;
        }
    }
    return words;
}

void printFile(const string& fileName) {
    ifstream f(fileName);
    if (!f.is_open()) {
        cout << "Не удалось открыть файл " << fileName << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    cout << "\n===== Содержимое файла " << fileName << " =====\n";

    while (getline(f, line)) {
        lineNumber++;
        cout << lineNumber << ") " << line << "\n";
    }

    cout << "====================================\n";

    f.close();
}

void makeF2(const string& f1Name, const string& f2Name,
    int N1, int N2, string& lastLineF2) {

    ifstream f1(f1Name);
    ofstream f2(f2Name);

    if (!f1.is_open()) {
        cout << "Не удалось открыть файл " << f1Name << endl;
        lastLineF2 = "";
        return;
    }

    if (!f2.is_open()) {
        cout << "Не удалось создать файл " << f2Name << endl;
        lastLineF2 = "";
        return;
    }

    lastLineF2 = "";
    string line;
    int lineNumber = 0;

    while (getline(f1, line)) {
        lineNumber++;

        bool needWrite = false;

        if (lineNumber >= N1 && lineNumber <= N2) {
            if (startsWithA(line)) {
                needWrite = true;
            }
        }
        else if (lineNumber >= N2 + 3) {
            needWrite = true;
        }

        if (needWrite) {
            f2 << line << "\n";
            lastLineF2 = line;
        }
    }

    f1.close();
    f2.close();
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string F1 = "C:\\Users\\sgleb\\OneDrive\\Desktop\\Education\\kurs_1\\Informatics\\sem_2\\lab_9\\F1.txt";
    string F2 = "F2.txt";

    cout << "Исходный файл F1:\n";
    printFile(F1);
    int N1, N2;

    cout << "\nВведите номер строки N1: ";
    cin >> N1;

    cout << "Введите номер строки N2: ";
    cin >> N2;

    if (N1 <= 0 || N2 <= 0 || N1 > N2) {
        cout << "Ошибка ввода N1 и N2.\n";
        return 0;
    }

    string lastLineF2;

    makeF2(F1, F2, N1, N2, lastLineF2);

    cout << "\nИтоговый файл F2:\n";
    printFile(F2);

    cout << "\nРезультат задания 2:\n";

    if (lastLineF2 != "") {
        cout << "Последняя строка F2: " << lastLineF2 << "\n";
        cout << "Количество слов: " << countWordsInLine(lastLineF2) << "\n";
    }
    else {
        cout << "Файл F2 пуст.\n";
    }
}