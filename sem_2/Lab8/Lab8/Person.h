#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

// абстрактный класс Person (наследник Object)
class Person : public Object {
public:
    Person(void); // конструктор без параметров
    virtual ~Person(void); // деструктор

    virtual void Show(); // чисто виртуальная функция (вывод информации)

    void Input(); // ввод данных

    Person(string, int); // конструктор с параметрами
    Person(const Person&); // конструктор копирования

    int Get_age() { return age; } // получить возраст

    Person& operator=(const Person&); // операция присваивания

    void HandleEvent(const TEvent& e); // обработка события

protected:
    string name; // имя
    int age;     // возраст
};