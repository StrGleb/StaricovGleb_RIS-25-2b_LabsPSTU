#include <iostream>
#include <string>
#include <clocale>
#include <Windows.h>

using namespace std;

struct Person {
    string fio;
    string date;
    string phone;
};

//ОБЩИЕ ФУНКЦИИ 

int strToNum(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (unsigned char)s[i];
    }
    return sum;
}

int hashFunc(string key, int size) {
    return strToNum(key) % size;
}

Person inputPerson() {
    Person p;

    cout << "\nВведите ФИО: ";
    getline(cin, p.fio);

    cout << "Введите дату рождения: ";
    getline(cin, p.date);

    cout << "Введите телефон: ";
    getline(cin, p.phone);

    return p;
}

void printPerson(Person p) {
    cout << "ФИО: " << p.fio
        << " | Дата рождения: " << p.date
        << " | Телефон: " << p.phone << endl;
}

//МЕТОД ЦЕПОЧЕК

struct Node {
    Person data;
    Node* next;
};

void initChain(Node** table, int size) {
    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
}

void addChain(Node** table, int size, Person p) {
    int h = hashFunc(p.fio, size);

    Node* temp = new Node;
    temp->data = p;
    temp->next = table[h];
    table[h] = temp;
}

Node* findChain(Node** table, int size, string key) {
    int h = hashFunc(key, size);
    Node* cur = table[h];

    while (cur != NULL) {
        if (cur->data.fio == key) {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

bool delChain(Node** table, int size, string key) {
    int h = hashFunc(key, size);
    Node* cur = table[h];
    Node* prev = NULL;

    while (cur != NULL) {
        if (cur->data.fio == key) {
            if (prev == NULL) {
                table[h] = cur->next;
            }
            else {
                prev->next = cur->next;
            }

            delete cur;
            return true;
        }

        prev = cur;
        cur = cur->next;
    }

    return false;
}

bool editChain(Node** table, int size, string key) {
    Node* cur = findChain(table, size, key);

    if (cur == NULL) {
        return false;
    }

    cout << "\nВведите новые данные:\n";
    cur->data = inputPerson();

    return true;
}

void printChain(Node** table, int size) {
    cout << "\nТаблица (цепочки):\n";

    for (int i = 0; i < size; i++) {
        cout << i << ": ";
        Node* cur = table[i];

        if (cur == NULL) {
            cout << "пусто";
        }
        else {
            while (cur != NULL) {
                cout << "[" << cur->data.fio << ", "
                    << cur->data.date << ", "
                    << cur->data.phone << "]";

                if (cur->next != NULL) {
                    cout << " -> ";
                }

                cur = cur->next;
            }
        }

        cout << endl;
    }
}

void clearChain(Node** table, int size) {
    for (int i = 0; i < size; i++) {
        Node* cur = table[i];

        while (cur != NULL) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
}

//ЛИНЕЙНОЕ ПРОБИРОВАНИЕ

struct Cell {
    Person data;
    bool busy;
    bool del;
};

void initProbe(Cell* table, int size) {
    for (int i = 0; i < size; i++) {
        table[i].busy = false;
        table[i].del = false;
    }
}

bool addProbe(Cell* table, int size, Person p) {
    int h = hashFunc(p.fio, size);

    for (int i = 0; i < size; i++) {
        int pos = (h + i) % size;

        if (!table[pos].busy || table[pos].del) {
            table[pos].data = p;
            table[pos].busy = true;
            table[pos].del = false;
            return true;
        }
    }

    return false;
}

int findProbe(Cell* table, int size, string key) {
    int h = hashFunc(key, size);

    for (int i = 0; i < size; i++) {
        int pos = (h + i) % size;

        if (!table[pos].busy && !table[pos].del) {
            return -1;
        }

        if (table[pos].busy && !table[pos].del && table[pos].data.fio == key) {
            return pos;
        }
    }

    return -1;
}

bool delProbe(Cell* table, int size, string key) {
    int pos = findProbe(table, size, key);

    if (pos == -1) {
        return false;
    }

    table[pos].busy = false;
    table[pos].del = true;
    return true;
}

bool editProbe(Cell* table, int size, string key) {
    int pos = findProbe(table, size, key);

    if (pos == -1) {
        return false;
    }

    cout << "\nВведите новые данные:\n";
    table[pos].data = inputPerson();

    return true;
}

void printProbe(Cell* table, int size) {
    cout << "\nТаблица (линейное пробирование):\n";

    for (int i = 0; i < size; i++) {
        cout << i << ": ";

        if (table[i].busy && !table[i].del) {
            cout << "[" << table[i].data.fio << ", "
                << table[i].data.date << ", "
                << table[i].data.phone << "]";
        }
        else if (table[i].del) {
            cout << "DEL";
        }
        else {
            cout << "пусто";
        }

        cout << endl;
    }
}

void menu() {
    cout << "\n===== МЕНЮ =====\n";
    cout << "1. Добавить запись\n";
    cout << "2. Найти запись\n";
    cout << "3. Удалить запись\n";
    cout << "4. Изменить запись\n";
    cout << "5. Показать таблицу цепочек\n";
    cout << "6. Показать таблицу пробирования\n";
    cout << "7. Показать обе таблицы\n";
    cout << "0. Выход\n";
    cout << "Выбор: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int size;
    cout << "Введите размер хеш-таблицы: ";
    cin >> size;
    cin.ignore();

    Node** chain = new Node * [size];
    Cell* probe = new Cell[size];

    initChain(chain, size);
    initProbe(probe, size);

    int k;

    do {
        menu();
        cin >> k;
        cin.ignore();

        if (k == 1) {
            Person p = inputPerson();

            addChain(chain, size, p);

            if (!addProbe(probe, size, p)) {
                cout << "\nТаблица пробирования переполнена.\n";
            }
            else {
                cout << "\nЗапись добавлена.\n";
            }
        }
        else if (k == 2) {
            string key;
            cout << "\nВведите ФИО для поиска: ";
            getline(cin, key);

            cout << "\nПоиск в цепочках:\n";
            Node* f1 = findChain(chain, size, key);
            if (f1 != NULL) {
                printPerson(f1->data);
            }
            else {
                cout << "Не найдено.\n";
            }

            cout << "\nПоиск в пробировании:\n";
            int f2 = findProbe(probe, size, key);
            if (f2 != -1) {
                printPerson(probe[f2].data);
            }
            else {
                cout << "Не найдено.\n";
            }
        }
        else if (k == 3) {
            string key;
            cout << "\nВведите ФИО для удаления: ";
            getline(cin, key);

            bool a = delChain(chain, size, key);
            bool b = delProbe(probe, size, key);

            if (a || b) {
                cout << "Запись удалена.\n";
            }
            else {
                cout << "Не найдено.\n";
            }
        }
        else if (k == 4) {
            string key;
            cout << "\nВведите ФИО для изменения: ";
            getline(cin, key);

            cout << "\nИзменение в цепочках:\n";
            if (!editChain(chain, size, key)) {
                cout << "Не найдено.\n";
            }

            cout << "\nИзменение в пробировании:\n";
            if (!editProbe(probe, size, key)) {
                cout << "Не найдено.\n";
            }
        }
        else if (k == 5) {
            printChain(chain, size);
        }
        else if (k == 6) {
            printProbe(probe, size);
        }
        else if (k == 7) {
            printChain(chain, size);
            printProbe(probe, size);
        }

    } while (k != 0);

    clearChain(chain, size);
    delete[] chain;
    delete[] probe;
}