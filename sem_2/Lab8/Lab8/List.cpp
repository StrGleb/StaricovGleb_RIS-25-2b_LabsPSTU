#include "List.h"

List::List() {
    beg = nullptr; // список пуст
    cur = 0;       // элементов нет
}

// очистка списка
void List::Clear() {
    while (beg) {
        Node* temp = beg;
        beg = beg->next;
        delete temp->data;
        delete temp;
    }
}

// деструктор
List::~List() {
    Clear(); // освобождение памяти
}

// добавление элемента
void List::Add() {
    Object* p;

    cout << "1.Person 2.Abiturient: ";
    int y;
    cin >> y;

    if (y == 1)
        p = new Person;
    else
        p = new Abiturient;

    p->Input();

    Node* newNode = new Node{ p, nullptr };

    if (!beg)
        beg = newNode;
    else {
        Node* temp = beg;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    cur++;
}

// удаление первого элемента
void List::Del() {
    if (!beg) return;

    Node* temp = beg;
    beg = beg->next;

    delete temp->data;
    delete temp;

    cur--; // уменьшаем количество
}

// вывод элементов
void List::Show() {
    if (!beg) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = beg;

    while (temp) {
        temp->data->Show(); // вызов виртуальной функции
        temp = temp->next;
    }
}

// количество элементов
int List::operator()() {
    return cur;
}

// вычисление среднего возраста
void List::AvgAge(int& sum, int& count) {
    Node* temp = beg;

    while (temp) {
        Person* p = dynamic_cast<Person*>(temp->data);

        if (p) {
            sum += p->Get_age();
            count++;
        }

        temp = temp->next;
    }
}

// обработка событий
void List::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        if (e.command == cmGet) {
            int sum = 0, count = 0;

            AvgAge(sum, count);

            if (count > 0)
                cout << "Average Age: " << (float)sum / count << endl;
            else
                cout << "No persons in list" << endl;
        }
    }
}