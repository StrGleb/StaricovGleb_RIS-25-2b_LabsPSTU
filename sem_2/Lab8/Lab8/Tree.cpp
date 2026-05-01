#include "Tree.h"

Tree::Tree() { root = nullptr; cur = 0; }
void Tree::Clear(Node* t) {
    if (t) {
        Clear(t->left);
        Clear(t->right);
        delete t->data;
        delete t;
    }
}
Tree::~Tree() { Clear(root); }

void Tree::Add() {
    Object* p;
    cout << "1.Person 2.Abiturient: ";
    int y; cin >> y;
    if (y == 1) p = new Person;
    else p = new Abiturient;
    p->Input();

    Node* newNode = new Node{ p, nullptr, nullptr };
    if (!root) root = newNode;
    else {
        Node* temp = root;
        while (temp->left) temp = temp->left; // Упрощенная вставка в ветку
        temp->left = newNode;
    }
    cur++;
}

void Tree::Del() {
    if (!root) return;
    Node* temp = root;
    root = root->left;
    delete temp->data;
    delete temp;
    cur--;
}

void Tree::Show(Node* t) {
    if (t) {
        t->data->Show();
        Show(t->left);
        Show(t->right);
    }
}

void Tree::Show() {
    if (!root) cout << "Tree is empty" << endl;
    else Show(root);
}

int Tree::operator()() { return cur; }

void Tree::AvgAge(Node* t, int& sum, int& count) {
    if (t) {
        Person* p = dynamic_cast<Person*>(t->data);
        if (p) { sum += p->Get_age(); count++; }
        AvgAge(t->left, sum, count);
        AvgAge(t->right, sum, count);
    }
}

void Tree::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        if (e.command == cmGet) {
            int sum = 0, count = 0;
            AvgAge(root, sum, count);
            if (count > 0) cout << "Average Age: " << (float)sum / count << endl;
            else cout << "No persons in tree" << endl;
        }
    }
}