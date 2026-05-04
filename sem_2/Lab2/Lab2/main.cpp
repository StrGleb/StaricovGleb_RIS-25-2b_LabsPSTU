#include "applicant.h"
#include <iostream>
#include <string>

using namespace std;

// Функция создания объекта (возврат объекта как результат)
// Демонстрирует вызов конструктора с параметрами и копирования
Applicant makeApplicant() {
    string fN;
    string s;
    int eS;

    cout << "\nVvedite fullName: ";
    getline(cin, fN);

    cout << "Vvedite speciality: ";
    getline(cin, s);

    cout << "Vvedite examScore: ";
    cin >> eS;

    cout << endl;

    // Создание объекта с параметрами
    Applicant ap(fN, s, eS);

    // Возврат объекта (вызывается конструктор копирования)
    return ap;
}

// Функция для передачи объекта по значению
// При передаче вызывается конструктор копирования
void printApplicant(Applicant ap) {
    ap.show();
}

int main() {
    // Конструктор без параметров
    Applicant ap1;
    ap1.show();

    // Конструктор с параметрами
    Applicant ap2("Ivanov Ivan Ivanovich", "IT-specialist", 310);
    ap2.show();

    // Конструктор копирования
    Applicant ap3 = ap2;

    // Изменение полей через модификаторы
    ap3.setFullName("Gogin Goga Gogevich");
    ap3.setSpeciality("dentist");
    ap3.setExamScore(233);

    // Передача объекта в функцию (конструктор копирования)
    printApplicant(ap3);

    // Возврат объекта из функции (конструктор копирования)
    ap1 = makeApplicant();
    ap1.show();

    return 0;
}