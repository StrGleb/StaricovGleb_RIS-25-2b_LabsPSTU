#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct SNode {
    string key;
    SNode* next;
    SNode(const string& value) : key(value), next(nullptr) {}
};

struct DNode {
    string key;
    DNode* prev;
    DNode* next;
    DNode(const string& value) : key(value), prev(nullptr), next(nullptr) {}
};

class SinglyListHeadOnly {
    SNode* head;

public:
    SinglyListHeadOnly() : head(nullptr) {}
    ~SinglyListHeadOnly() { destroy(); }

    bool empty() const { return head == nullptr; }

    void print() const {
        if (empty()) {
            cout << "Список пустой.\n";
            return;
        }
        cout << "Список: ";
        SNode* p = head;
        int i = 1;
        while (p) {
            cout << "[" << i++ << ": " << p->key << "] ";
            p = p->next;
        }
        cout << "\n";
    }

    void addFront(const string& value) {
        SNode* node = new SNode(value);
        node->next = head;
        head = node;
    }

    void addBack(const string& value) {
        SNode* node = new SNode(value);
        if (!head) {
            head = node;
            return;
        }
        SNode* p = head;
        while (p->next) p = p->next;
        p->next = node;
    }

    bool removeFront() {
        if (!head) return false;
        SNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    bool removeBack() {
        if (!head) return false;
        if (!head->next) {
            delete head;
            head = nullptr;
            return true;
        }
        SNode* p = head;
        while (p->next->next) p = p->next;
        delete p->next;
        p->next = nullptr;
        return true;
    }

    bool removeByKey(const string& key) {
        if (!head) return false;
        if (head->key == key) return removeFront();
        SNode* p = head;
        while (p->next && p->next->key != key) p = p->next;
        if (!p->next) return false;
        SNode* temp = p->next;
        p->next = temp->next;
        delete temp;
        return true;
    }

    bool removeByNumber(int number) {
        if (number <= 0 || !head) return false;
        if (number == 1) return removeFront();
        SNode* p = head;
        int pos = 1;
        while (p->next && pos < number - 1) {
            p = p->next;
            pos++;
        }
        if (!p->next) return false;
        SNode* temp = p->next;
        p->next = temp->next;
        delete temp;
        return true;
    }

    bool addAfterKey(const string& targetKey, const string& value) {
        SNode* p = head;
        while (p && p->key != targetKey) p = p->next;
        if (!p) return false;
        SNode* node = new SNode(value);
        node->next = p->next;
        p->next = node;
        return true;
    }

    bool addByNumber(int number, const string& value) {
        if (number <= 0) return false;
        if (number == 1) {
            addFront(value);
            return true;
        }
        SNode* p = head;
        int pos = 1;
        while (p && pos < number - 1) {
            p = p->next;
            pos++;
        }
        if (!p) return false;
        SNode* node = new SNode(value);
        node->next = p->next;
        p->next = node;
        return true;
    }

    void saveToFile(const string& filename) const {
        ofstream fout(filename);
        if (!fout) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        for (SNode* p = head; p; p = p->next) fout << p->key << "\n";
        cout << "Список сохранен в файл " << filename << ".\n";
    }

    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        destroy();
        string s;
        while (getline(fin, s))
            if (!s.empty()) addBack(s);
        cout << "Список восстановлен из файла " << filename << ".\n";
    }

    void destroy() {
        while (head) {
            SNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class SinglyListHeadTail {
    SNode* head;
    SNode* tail;

public:
    SinglyListHeadTail() : head(nullptr), tail(nullptr) {}
    ~SinglyListHeadTail() { destroy(); }

    bool empty() const { return head == nullptr; }

    void print() const {
        if (empty()) {
            cout << "Список пустой.\n";
            return;
        }
        cout << "Список: ";
        SNode* p = head;
        int i = 1;
        while (p) {
            cout << "[" << i++ << ": " << p->key << "] ";
            p = p->next;
        }
        cout << "\n";
    }

    void addFront(const string& value) {
        SNode* node = new SNode(value);
        node->next = head;
        head = node;
        if (!tail) tail = node;
    }

    void addBack(const string& value) {
        SNode* node = new SNode(value);
        if (!head) {
            head = tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }

    bool removeFront() {
        if (!head) return false;
        SNode* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
        return true;
    }

    bool removeBack() {
        if (!head) return false;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return true;
        }
        SNode* p = head;
        while (p->next != tail) p = p->next;
        delete tail;
        tail = p;
        tail->next = nullptr;
        return true;
    }

    bool removeByKey(const string& key) {
        if (!head) return false;
        if (head->key == key) return removeFront();
        SNode* p = head;
        while (p->next && p->next->key != key) p = p->next;
        if (!p->next) return false;
        SNode* temp = p->next;
        p->next = temp->next;
        if (temp == tail) tail = p;
        delete temp;
        return true;
    }

    bool removeByNumber(int number) {
        if (number <= 0 || !head) return false;
        if (number == 1) return removeFront();
        SNode* p = head;
        int pos = 1;
        while (p->next && pos < number - 1) {
            p = p->next;
            pos++;
        }
        if (!p->next) return false;
        SNode* temp = p->next;
        p->next = temp->next;
        if (temp == tail) tail = p;
        delete temp;
        return true;
    }

    bool addAfterKey(const string& targetKey, const string& value) {
        SNode* p = head;
        while (p && p->key != targetKey) p = p->next;
        if (!p) return false;
        SNode* node = new SNode(value);
        node->next = p->next;
        p->next = node;
        if (tail == p) tail = node;
        return true;
    }

    bool addByNumber(int number, const string& value) {
        if (number <= 0) return false;
        if (number == 1) {
            addFront(value);
            return true;
        }
        SNode* p = head;
        int pos = 1;
        while (p && pos < number - 1) {
            p = p->next;
            pos++;
        }
        if (!p) return false;
        SNode* node = new SNode(value);
        node->next = p->next;
        p->next = node;
        if (tail == p) tail = node;
        return true;
    }

    void saveToFile(const string& filename) const {
        ofstream fout(filename);
        if (!fout) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        for (SNode* p = head; p; p = p->next) fout << p->key << "\n";
        cout << "Список сохранен в файл " << filename << ".\n";
    }

    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        destroy();
        string s;
        while (getline(fin, s))
            if (!s.empty()) addBack(s);
        cout << "Список восстановлен из файла " << filename << ".\n";
    }

    void destroy() {
        while (head) {
            SNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

class DoublyList {
    DNode* head;
    DNode* tail;

public:
    DoublyList() : head(nullptr), tail(nullptr) {}
    ~DoublyList() { destroy(); }

    bool empty() const { return head == nullptr; }

    void print() const {
        if (empty()) {
            cout << "Список пустой.\n";
            return;
        }
        cout << "Список: ";
        DNode* p = head;
        int i = 1;
        while (p) {
            cout << "[" << i++ << ": " << p->key << "] ";
            p = p->next;
        }
        cout << "\n";
    }

    void printReverse() const {
        if (empty()) {
            cout << "Список пустой.\n";
            return;
        }
        cout << "Список в обратном порядке: ";
        for (DNode* p = tail; p; p = p->prev) cout << "[" << p->key << "] ";
        cout << "\n";
    }

    void addFront(const string& value) {
        DNode* node = new DNode(value);
        if (!head) {
            head = tail = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
    }

    void addBack(const string& value) {
        DNode* node = new DNode(value);
        if (!tail) {
            head = tail = node;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    bool removeFront() {
        if (!head) return false;
        DNode* temp = head;
        if (head == tail) head = tail = nullptr;
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        return true;
    }

    bool removeBack() {
        if (!tail) return false;
        DNode* temp = tail;
        if (head == tail) head = tail = nullptr;
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        return true;
    }

    bool removeByKey(const string& key) {
        DNode* p = head;
        while (p && p->key != key) p = p->next;
        if (!p) return false;
        if (p == head) return removeFront();
        if (p == tail) return removeBack();
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        return true;
    }

    bool removeByNumber(int number) {
        if (number <= 0) return false;
        DNode* p = head;
        int pos = 1;
        while (p && pos < number) {
            p = p->next;
            pos++;
        }
        if (!p) return false;
        if (p == head) return removeFront();
        if (p == tail) return removeBack();
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        return true;
    }

    bool addAfterKey(const string& targetKey, const string& value) {
        DNode* p = head;
        while (p && p->key != targetKey) p = p->next;
        if (!p) return false;
        DNode* node = new DNode(value);
        node->prev = p;
        node->next = p->next;
        if (p->next) p->next->prev = node;
        else tail = node;
        p->next = node;
        return true;
    }

    bool addByNumber(int number, const string& value) {
        if (number <= 0) return false;
        if (number == 1) {
            addFront(value);
            return true;
        }
        DNode* p = head;
        int pos = 1;
        while (p && pos < number - 1) {
            p = p->next;
            pos++;
        }
        if (!p) return false;
        DNode* node = new DNode(value);
        node->prev = p;
        node->next = p->next;
        if (p->next) p->next->prev = node;
        else tail = node;
        p->next = node;
        return true;
    }

    void saveToFile(const string& filename) const {
        ofstream fout(filename);
        if (!fout) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        for (DNode* p = head; p; p = p->next) fout << p->key << "\n";
        cout << "Список сохранен в файл " << filename << ".\n";
    }

    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        destroy();
        string s;
        while (getline(fin, s))
            if (!s.empty()) addBack(s);
        cout << "Список восстановлен из файла " << filename << ".\n";
    }

    void destroy() {
        while (head) {
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

class QueueList {
    DNode* head;
    DNode* tail;

public:
    QueueList() : head(nullptr), tail(nullptr) {}
    ~QueueList() { destroy(); }

    bool empty() const { return head == nullptr; }

    void print() const {
        if (empty()) {
            cout << "Очередь пустая.\n";
            return;
        }
        cout << "Очередь: ";
        DNode* p = head;
        int i = 1;
        while (p) {
            cout << "[" << i++ << ": " << p->key << "] ";
            p = p->next;
        }
        cout << "\n";
    }

    void enqueue(const string& value) {
        DNode* node = new DNode(value);
        if (!tail) {
            head = tail = node;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    bool dequeue() {
        if (!head) return false;
        DNode* temp = head;
        if (head == tail) head = tail = nullptr;
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        return true;
    }

    bool insertBeforeNumber(int number, const string& value) {
        if (number <= 0) return false;
        if (number == 1) {
            DNode* node = new DNode(value);
            if (!head) head = tail = node;
            else {
                node->next = head;
                head->prev = node;
                head = node;
            }
            return true;
        }
        DNode* p = head;
        int pos = 1;
        while (p && pos < number) {
            p = p->next;
            pos++;
        }
        if (!p) return false;
        DNode* node = new DNode(value);
        node->prev = p->prev;
        node->next = p;
        p->prev->next = node;
        p->prev = node;
        return true;
    }

    void saveToFile(const string& filename) const {
        ofstream fout(filename);
        if (!fout) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        for (DNode* p = head; p; p = p->next) fout << p->key << "\n";
        cout << "Очередь сохранена в файл " << filename << ".\n";
    }

    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        destroy();
        string s;
        while (getline(fin, s))
            if (!s.empty()) enqueue(s);
        cout << "Очередь восстановлена из файла " << filename << ".\n";
    }

    void destroy() {
        while (head) {
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

class StackList {
    SNode* topNode;

public:
    StackList() : topNode(nullptr) {}
    ~StackList() { destroy(); }

    bool empty() const { return topNode == nullptr; }

    void print() const {
        if (empty()) {
            cout << "Стек пустой.\n";
            return;
        }
        cout << "Стек сверху вниз: ";
        SNode* p = topNode;
        int i = 1;
        while (p) {
            cout << "[" << i++ << ": " << p->key << "] ";
            p = p->next;
        }
        cout << "\n";
    }

    void push(const string& value) {
        SNode* node = new SNode(value);
        node->next = topNode;
        topNode = node;
    }

    bool pop() {
        if (!topNode) return false;
        SNode* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return true;
    }

    void saveToFile(const string& filename) const {
        ofstream fout(filename);
        if (!fout) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        for (SNode* p = topNode; p; p = p->next) fout << p->key << "\n";
        cout << "Стек сохранен в файл " << filename << ".\n";
    }

    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        destroy();

        SNode* first = nullptr;
        SNode* last = nullptr;
        string s;

        while (getline(fin, s)) {
            if (s.empty()) continue;
            SNode* node = new SNode(s);
            if (!first) first = last = node;
            else {
                last->next = node;
                last = node;
            }
        }

        while (first) {
            SNode* prev = nullptr;
            SNode* cur = first;
            while (cur->next) {
                prev = cur;
                cur = cur->next;
            }
            push(cur->key);
            if (!prev) {
                delete first;
                first = nullptr;
            }
            else {
                delete cur;
                prev->next = nullptr;
            }
        }

        cout << "Стек восстановлен из файла " << filename << ".\n";
    }

    void destroy() {
        while (topNode) {
            SNode* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};

void demoSinglyHeadOnly() {
    cout << "\n===== Односвязный список, только head =====\n";
    SinglyListHeadOnly list;
    list.addBack("A");
    list.addBack("B");
    list.addBack("C");
    cout << "После addBack A, B, C\n";
    list.print();

    list.addFront("X");
    cout << "После addFront X\n";
    list.print();

    cout << "После addAfterKey B -> BB\n";
    cout << (list.addAfterKey("B", "BB") ? "Добавление выполнено.\n" : "Ключ не найден.\n");
    list.print();

    cout << "После addByNumber 2 -> P\n";
    cout << (list.addByNumber(2, "P") ? "Добавление выполнено.\n" : "Неверный номер.\n");
    list.print();

    cout << "После removeFront\n";
    cout << (list.removeFront() ? "Удаление выполнено.\n" : "Список пустой.\n");
    list.print();

    cout << "После removeBack\n";
    cout << (list.removeBack() ? "Удаление выполнено.\n" : "Список пустой.\n");
    list.print();

    cout << "После removeByKey B\n";
    cout << (list.removeByKey("B") ? "Удаление выполнено.\n" : "Ключ не найден.\n");
    list.print();

    cout << "После removeByNumber 2\n";
    cout << (list.removeByNumber(2) ? "Удаление выполнено.\n" : "Неверный номер.\n");
    list.print();

    list.saveToFile("singly_head_only.txt");
    list.destroy();
    cout << "После destroy\n";
    list.print();
    list.loadFromFile("singly_head_only.txt");
    list.print();
}

void demoSinglyHeadTail() {
    cout << "\n===== Односвязный список, head и tail =====\n";
    SinglyListHeadTail list;
    list.addBack("red");
    list.addBack("green");
    list.addBack("blue");
    cout << "После addBack red, green, blue\n";
    list.print();

    list.addFront("black");
    cout << "После addFront black\n";
    list.print();

    cout << "После addAfterKey green -> lime\n";
    cout << (list.addAfterKey("green", "lime") ? "Добавление выполнено.\n" : "Ключ не найден.\n");
    list.print();

    cout << "После addByNumber 3 -> white\n";
    cout << (list.addByNumber(3, "white") ? "Добавление выполнено.\n" : "Неверный номер.\n");
    list.print();

    cout << "После removeFront\n";
    cout << (list.removeFront() ? "Удаление выполнено.\n" : "Список пустой.\n");
    list.print();

    cout << "После removeBack\n";
    cout << (list.removeBack() ? "Удаление выполнено.\n" : "Список пустой.\n");
    list.print();

    cout << "После removeByKey green\n";
    cout << (list.removeByKey("green") ? "Удаление выполнено.\n" : "Ключ не найден.\n");
    list.print();

    cout << "После removeByNumber 2\n";
    cout << (list.removeByNumber(2) ? "Удаление выполнено.\n" : "Неверный номер.\n");
    list.print();

    list.saveToFile("singly_head_tail.txt");
    list.destroy();
    cout << "После destroy\n";
    list.print();
    list.loadFromFile("singly_head_tail.txt");
    list.print();
}

void demoDoublyList() {
    cout << "\n===== Двусвязный список =====\n";
    DoublyList list;
    list.addBack("one");
    list.addBack("two");
    list.addBack("three");
    list.addBack("four");
    cout << "После addBack one, two, three, four\n";
    list.print();

    cout << "Обратный вывод\n";
    list.printReverse();

    list.addFront("zero");
    cout << "После addFront zero\n";
    list.print();

    cout << "После addAfterKey two -> TWO_PLUS\n";
    cout << (list.addAfterKey("two", "TWO_PLUS") ? "Добавление выполнено.\n" : "Ключ не найден.\n");
    list.print();

    cout << "После addByNumber 3 -> MID\n";
    cout << (list.addByNumber(3, "MID") ? "Добавление выполнено.\n" : "Неверный номер.\n");
    list.print();

    cout << "После removeFront\n";
    cout << (list.removeFront() ? "Удаление выполнено.\n" : "Список пустой.\n");
    list.print();

    cout << "После removeBack\n";
    cout << (list.removeBack() ? "Удаление выполнено.\n" : "Список пустой.\n");
    list.print();

    cout << "После removeByKey two\n";
    cout << (list.removeByKey("two") ? "Удаление выполнено.\n" : "Ключ не найден.\n");
    list.print();

    cout << "После removeByNumber 2\n";
    cout << (list.removeByNumber(2) ? "Удаление выполнено.\n" : "Неверный номер.\n");
    list.print();

    cout << "Вариант 17. Удаление по номеру 2\n";
    cout << (list.removeByNumber(2) ? "Удаление выполнено.\n" : "Неверный номер.\n");
    list.print();

    cout << "Вариант 17. Добавление K элементов в начало: A1, A2, A3\n";
    list.addFront("A1");
    list.addFront("A2");
    list.addFront("A3");
    list.print();

    cout << "Обратный вывод\n";
    list.printReverse();

    list.saveToFile("doubly_list.txt");
    list.destroy();
    cout << "После destroy\n";
    list.print();
    list.loadFromFile("doubly_list.txt");
    list.print();
}

void demoQueue() {
    cout << "\n===== Очередь FIFO =====\n";
    QueueList queue;
    queue.enqueue("q1");
    queue.enqueue("q2");
    queue.enqueue("q3");
    queue.enqueue("q4");
    cout << "После enqueue q1, q2, q3, q4\n";
    queue.print();

    cout << "После dequeue\n";
    cout << (queue.dequeue() ? "Удаление выполнено.\n" : "Очередь пустая.\n");
    queue.print();

    cout << "После insertBeforeNumber 2 -> priority\n";
    cout << (queue.insertBeforeNumber(2, "priority") ? "Вставка выполнена.\n" : "Неверный номер.\n");
    queue.print();

    queue.saveToFile("queue.txt");
    queue.destroy();
    cout << "После destroy\n";
    queue.print();
    queue.loadFromFile("queue.txt");
    queue.print();
}

void demoStack() {
    cout << "\n===== Стек LIFO =====\n";
    StackList stack;
    stack.push("s1");
    stack.push("s2");
    stack.push("s3");
    cout << "После push s1, s2, s3\n";
    stack.print();

    cout << "После pop\n";
    cout << (stack.pop() ? "Удаление выполнено.\n" : "Стек пустой.\n");
    stack.print();

    stack.push("s4");
    cout << "После push s4\n";
    stack.print();

    stack.saveToFile("stack.txt");
    stack.destroy();
    cout << "После destroy\n";
    stack.print();
    stack.loadFromFile("stack.txt");
    stack.print();
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "");

    cout << "Лабораторная работа 11\n";
    cout << "Автоматическая демонстрация структур\n";

    demoSinglyHeadOnly();
    demoSinglyHeadTail();
    demoDoublyList();
    demoQueue();
    demoStack();

    cout << "\nДемонстрация завершена.\n";
    return 0;
}