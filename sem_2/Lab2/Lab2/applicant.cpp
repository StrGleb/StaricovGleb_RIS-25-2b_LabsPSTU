#include "applicant.h"
#include <iostream>

using namespace std;

// Конструктор без параметров
// Инициализирует поля значениями по умолчанию
Applicant::Applicant() {
    fullName = "";
    speciality = "";
    examScore = 0;
    cout << "Constructor bez parametrov dlia objecta " << this << endl;
}

// Конструктор с параметрами
// Позволяет задать значения полей при создании объекта
Applicant::Applicant(string fN, string s, int eS) {
    fullName = fN;
    speciality = s;
    examScore = eS;
    cout << "Constructor s parametrami dlia objecta " << this << endl;
}

// Конструктор копирования
// Создает новый объект как копию существующего
Applicant::Applicant(const Applicant& ap) {
    fullName = ap.fullName;
    speciality = ap.speciality;
    examScore = ap.examScore;
    cout << "Constructor copirovania dlia objecta " << this << endl;
}

// Деструктор
// Вызывается при удалении объекта
Applicant::~Applicant() {
    cout << "Destructor dlia objecta " << this << endl;
}

// Селектор (getter) для поля fullName
string Applicant::getFullName() {
    return fullName;
}

// Модификатор (setter) для поля fullName
void Applicant::setFullName(string str) {
    fullName = str;
}

// Селектор для поля speciality
string Applicant::getSpeciality() {
    return speciality;
}

// Модификатор для поля speciality
void Applicant::setSpeciality(string str) {
    speciality = str;
}

// Селектор для поля examScore
int Applicant::getExamScore() {
    return examScore;
}

// Модификатор для поля examScore
void Applicant::setExamScore(int n) {
    examScore = n;
}

// Метод вывода значений полей объекта
void Applicant::show() {
    cout << "fullName: " << fullName << endl;
    cout << "speciality: " << speciality << endl;
    cout << "examScore: " << examScore << endl;
    cout << endl;
}