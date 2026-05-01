#pragma once
#include "Abiturient.h"

struct Node {
    Object* data;
    Node* left, * right;
};

class Tree {
public:
    Tree();
    virtual ~Tree();
    void Add();
    void Del();
    void Show();
    void Show(Node* t);
    int operator()();
    void HandleEvent(const TEvent& e);
protected:
    Node* root;
    int cur; // Текущее количество
    void Clear(Node* t);
    void AvgAge(Node* t, int& sum, int& count);
};