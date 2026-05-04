#pragma once
#include <iostream>
using namespace std;

// параметризованный класс List (собственная реализация)
template <class T>
class List {
private:
    // узел списка
    struct Node {
        T data;
        Node* next;

        Node(T value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head; // начало списка

public:
    // конструктор
    List() {
        head = nullptr;
    }

    // деструктор
    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // добавление в конец
    void push_back(T value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    // вывод списка
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // поиск максимума
    T max() {
        Node* temp = head;
        T m = temp->data;

        while (temp != nullptr) {
            if (temp->data > m)
                m = temp->data;
            temp = temp->next;
        }

        return m;
    }

    // добавить max
    void add_max() {
        push_back(max());
    }

    // удаление по диапазону
    void remove_range(int a, int b) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data.inRange(a, b)) {
                if (temp == head) {
                    head = temp->next;
                    delete temp;
                    temp = head;
                }
                else {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
    }

    // вычисление среднего
    T average() {
        Node* temp = head;
        T sum = T();
        int count = 0;

        while (temp != nullptr) {
            sum = sum + temp->data;
            temp = temp->next;
            count++;
        }

        return sum / count;
    }

    // добавить среднее
    void add_average() {
        T avg = average();

        Node* temp = head;
        while (temp != nullptr) {
            temp->data = temp->data + avg;
            temp = temp->next;
        }
    }
};