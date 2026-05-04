#pragma once
#include "Abiturient.h"

// структура узла списка
struct Node {
    Object* data; // указатель на объект
    Node* next;   // указатель на следующий элемент
};

// класс списка (группа объектов)
class List {
public:
    List(); // конструктор
    virtual ~List(); // деструктор

    void Add(); // добавление элемента
    void Del(); // удаление элемента
    void Show(); // просмотр списка
    int operator()(); // количество элементов

    void HandleEvent(const TEvent& e); // обработка событий

protected:
    Node* beg; // начало списка
    int cur;   // текущее количество элементов

    void Clear(); // очистка списка
    void AvgAge(int& sum, int& count); // вычисление среднего возраста
};