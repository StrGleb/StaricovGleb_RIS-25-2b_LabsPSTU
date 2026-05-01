#include "applicant.h"
#include <iostream>
#include <string>

using namespace std;

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

    Applicant ap(fN, s, eS);
    return ap;
}

void printApplicant(Applicant ap) {
    ap.show();
}

int main() {
    Applicant ap1;
    ap1.show();

    Applicant ap2("Ivanov Ivan Ivanovich", "IT-specialist", 310);
    ap2.show();

    Applicant ap3 = ap2;

    ap3.setFullName("Gogin Goga Gogevich");
    ap3.setSpeciality("dentist");
    ap3.setExamScore(233);

    printApplicant(ap3);

    ap1 = makeApplicant();
    ap1.show();

    return 0;
}