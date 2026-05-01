#include "applicant.h"
#include <iostream>

using namespace std;

Applicant::Applicant() {
    fullName = "";
    speciality = "";
    examScore = 0;
    cout << "Constructor bez parametrov dlia objecta " << this << endl;
}

Applicant::Applicant(string fN, string s, int eS) {
    fullName = fN;
    speciality = s;
    examScore = eS;
    cout << "Constructor s parametrami dlia objecta " << this << endl;
}

Applicant::Applicant(const Applicant& ap) {
    fullName = ap.fullName;
    speciality = ap.speciality;
    examScore = ap.examScore;
    cout << "Constructor copirovania dlia objecta " << this << endl;
}

Applicant::~Applicant() {
    cout << "Destructor dlia objecta " << this << endl;
}

string Applicant::getFullName() {
    return fullName;
}

void Applicant::setFullName(string str) {
    fullName = str;
}

string Applicant::getSpeciality() {
    return speciality;
}

void Applicant::setSpeciality(string str) {
    speciality = str;
}

int Applicant::getExamScore() {
    return examScore;
}

void Applicant::setExamScore(int n) {
    examScore = n;
}

void Applicant::show() {
    cout << "fullName: " << fullName << endl;
    cout << "speciality: " << speciality << endl;
    cout << "examScore: " << examScore << endl;
    cout << endl;
}