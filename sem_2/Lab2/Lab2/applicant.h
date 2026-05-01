#pragma once

#include <string>
using namespace std;

class Applicant {
    string fullName;
    string speciality;
    int examScore;

public:
    Applicant();
    Applicant(string, string, int);
    Applicant(const Applicant&);
    ~Applicant();

    string getFullName();
    void setFullName(string);

    string getSpeciality();
    void setSpeciality(string);

    int getExamScore();
    void setExamScore(int);

    void show();
};