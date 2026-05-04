#pragma once

#include <string>
using namespace std;

// Класс Applicant (Абитуриент)
// Описывает абитуриента с ФИО, специальностью и баллом ЕГЭ
class Applicant {
    string fullName;    // ФИО абитуриента
    string speciality;  // выбранная специальность
    int examScore;      // балл ЕГЭ

public:
    // Конструктор без параметров (создание "пустого" объекта)
    Applicant();

    // Конструктор с параметрами (инициализация полей)
    Applicant(string, string, int);

    // Конструктор копирования (создание объекта на основе другого)
    Applicant(const Applicant&);

    // Деструктор (освобождение ресурсов)
    ~Applicant();

    // Селектор для получения ФИО
    string getFullName();

    // Модификатор для изменения ФИО
    void setFullName(string);

    // Селектор для получения специальности
    string getSpeciality();

    // Модификатор для изменения специальности
    void setSpeciality(string);

    // Селектор для получения балла
    int getExamScore();

    // Модификатор для изменения балла
    void setExamScore(int);

    // Метод вывода данных объекта
    void show();
};