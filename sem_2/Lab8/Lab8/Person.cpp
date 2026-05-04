#include "Person.h"

// конструктор без параметров
Person::Person(void) { 
    name = ""; // инициализация имени
    age = 0;   // инициализация возраста
}

// деструктор
Person::~Person(void) {}

// конструктор с параметрами
Person::Person(string N, int A) { 
    name = N; // установка имени
    age = A;  // установка возраста
}

// конструктор копирования
Person::Person(const Person& p) { 
    name = p.name; // копирование имени
    age = p.age;   // копирование возраста
}

// операция присваивания
Person& Person::operator=(const Person& p) {
    if (&p == this) return *this; // проверка самоприсваивания

    name = p.name; // копирование имени
    age = p.age;   // копирование возраста

    return *this; // возврат текущего объекта
}

// ввод данных
void Person::Input() {
    cout << "\nName: "; cin >> name; // ввод имени
    cout << "\nAge: "; cin >> age;   // ввод возраста
}

// обработка события (переопределяется в наследниках при необходимости)
void Person::HandleEvent(const TEvent& e) {
}

// вывод информации
void Person::Show() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}