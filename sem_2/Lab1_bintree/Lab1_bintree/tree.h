#ifndef TREE_H
#define TREE_H

#include <QString>
#include <QPoint>
#include <vector>

using namespace std;

struct VisualNode {
    double key; // ключ узла
    double parentKey; // ключ родителя
    bool hasParent; // есть ли родитель
    QPoint position; // координаты для рисования
    int level; // уровень узла
};

class BinaryTree {
private:
    struct Node {
        double key; // информационное поле double
        Node *left; // левый потомок
        Node *right; // правый потомок

        Node(double key) {
            this->key = key;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root; // корень дерева
    Node *originalRoot; // исходное состояние дерева

    Node* insertRecursive(Node *node, double key, bool& added); // вставка
    Node* removeRecursive(Node *node, double key, bool& removed); // удаление
    Node* searchRecursive(Node *node, double key); // поиск
    Node* findMin(Node *node); // минимальный узел

    void preorderRecursive(Node *node, QString& result); // прямой обход
    void inorderRecursive(Node *node, QString& result); // симметричный обход
    void postorderRecursive(Node *node, QString& result); // обратный обход

    void horizontalPrintRecursive(Node *node, int space, QString& result); // горизонтальная печать
    void levelsRecursive(Node *node, int level, vector<vector<double>>& levels); // уровни дерева

    void saveInorder(Node *node, vector<double>& values); // сохранение в отсортированный массив
    Node* buildBalanced(vector<double>& values, int left, int right); // построение сбалансированного дерева

    int countLeavesRecursive(Node *node); // количество листьев
    int countNodesRecursive(Node *node); // количество узлов
    int heightRecursive(Node *node); // высота дерева

    void fillVisualNodes(Node *node,
                         vector<VisualNode>& nodes,
                         double parentKey,
                         bool hasParent,
                         int level,
                         int& index,
                         int horizontalStep); // узлы для рисования

    Node* clone(Node *node); // копирование дерева
    void clear(Node *node); // очистка памяти
    QString keyToString(double key); // преобразование ключа в строку

public:
    BinaryTree(); // конструктор
    ~BinaryTree(); // деструктор

    bool insert(double key); // вставка узла
    bool remove(double key); // удаление узла
    bool search(double key); // поиск узла

    QString preorder(); // прямой обход
    QString inorder(); // симметричный обход
    QString postorder(); // обратный обход

    QString verticalPrint(); // вертикальная печать
    QString horizontalPrint(); // горизонтальная печать

    void balance(); // балансировка дерева

    void saveOriginal(); // сохранение исходного состояния
    void restoreOriginal(); // восстановление исходного состояния

    int countLeaves(); // количество листьев
    int getSize(); // количество узлов
    int getHeight(); // высота дерева

    vector<VisualNode> getVisualNodes(); // получение узлов для отрисовки
};

#endif // TREE_H
