#include "tree.h"

#include <algorithm>

BinaryTree::BinaryTree() {
    root = nullptr;
    originalRoot = nullptr;
}

BinaryTree::~BinaryTree() {
    clear(root);
    clear(originalRoot);
}

QString BinaryTree::keyToString(double key) {
    return QString::number(key, 'g', 6);
}

BinaryTree::Node* BinaryTree::insertRecursive(Node *node, double key, bool& added) {

    // если место найдено
    if (node == nullptr) {
        added = true;
        return new Node(key);
    }

    // если ключ меньше текущего
    if (key < node->key) {
        node->left = insertRecursive(node->left, key, added);
    }
    // если ключ больше текущего
    else if (key > node->key) {
        node->right = insertRecursive(node->right, key, added);
    }
    // одинаковые ключи не добавляем
    else {
        added = false;
    }

    return node;
}

bool BinaryTree::insert(double key) {
    bool added = false;

    root = insertRecursive(root, key, added);

    return added;
}

BinaryTree::Node* BinaryTree::findMin(Node *node) {

    // ищем самый левый узел
    while (node != nullptr && node->left != nullptr) {
        node = node->left;
    }

    return node;
}

BinaryTree::Node* BinaryTree::removeRecursive(Node *node, double key, bool& removed) {

    // узел не найден
    if (node == nullptr) {
        return nullptr;
    }

    // ищем в левом поддереве
    if (key < node->key) {
        node->left = removeRecursive(node->left, key, removed);
    }
    // ищем в правом поддереве
    else if (key > node->key) {
        node->right = removeRecursive(node->right, key, removed);
    }
    // узел найден
    else {
        removed = true;

        // нет левого потомка
        if (node->left == nullptr) {
            Node *temp = node->right;
            delete node;
            return temp;
        }

        // нет правого потомка
        if (node->right == nullptr) {
            Node *temp = node->left;
            delete node;
            return temp;
        }

        // есть два потомка
        Node *temp = findMin(node->right);

        node->key = temp->key;

        bool flag = false;
        node->right = removeRecursive(node->right, temp->key, flag);
    }

    return node;
}

bool BinaryTree::remove(double key) {
    bool removed = false;

    root = removeRecursive(root, key, removed);

    return removed;
}

BinaryTree::Node* BinaryTree::searchRecursive(Node *node, double key) {

    // если узла нет или ключ найден
    if (node == nullptr || node->key == key) {
        return node;
    }

    // если ключ меньше текущего
    if (key < node->key) {
        return searchRecursive(node->left, key);
    }

    // если ключ больше текущего
    return searchRecursive(node->right, key);
}

bool BinaryTree::search(double key) {
    return searchRecursive(root, key) != nullptr;
}

void BinaryTree::preorderRecursive(Node *node, QString& result) {

    if (node == nullptr) {
        return;
    }

    result += keyToString(node->key) + " ";

    preorderRecursive(node->left, result);
    preorderRecursive(node->right, result);
}

QString BinaryTree::preorder() {
    QString result;

    result += "Прямой обход\n\n";
    result += "Порядок: ";

    preorderRecursive(root, result);

    return result;
}

void BinaryTree::inorderRecursive(Node *node, QString& result) {

    if (node == nullptr) {
        return;
    }

    inorderRecursive(node->left, result);

    result += keyToString(node->key) + " ";

    inorderRecursive(node->right, result);
}

QString BinaryTree::inorder() {
    QString result;

    result += "Симметричный обход\n\n";
    result += "Порядок: ";

    inorderRecursive(root, result);

    return result;
}

void BinaryTree::postorderRecursive(Node *node, QString& result) {

    if (node == nullptr) {
        return;
    }

    postorderRecursive(node->left, result);
    postorderRecursive(node->right, result);

    result += keyToString(node->key) + " ";
}

QString BinaryTree::postorder() {
    QString result;

    result += "Обратный обход\n\n";
    result += "Порядок: ";

    postorderRecursive(root, result);

    return result;
}

void BinaryTree::levelsRecursive(Node *node, int level, vector<vector<double>>& levels) {

    if (node == nullptr) {
        return;
    }

    if (level == levels.size()) {
        levels.push_back(vector<double>());
    }

    levels[level].push_back(node->key);

    levelsRecursive(node->left, level + 1, levels);
    levelsRecursive(node->right, level + 1, levels);
}

QString BinaryTree::verticalPrint() {
    QString result;

    result += "Вертикальная печать\n\n";

    vector<VisualNode> nodes = getVisualNodes();

    if (nodes.empty()) {
        result += "Дерево пустое.";
        return result;
    }

    sort(nodes.begin(), nodes.end(), [](const VisualNode& first,
                                        const VisualNode& second) {
        if (first.level == second.level) {
            return first.position.x() < second.position.x();
        }

        return first.level < second.level;
    });

    int maxLevel = 0;

    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].level > maxLevel) {
            maxLevel = nodes[i].level;
        }
    }

    for (int level = 0; level <= maxLevel; level++) {

        int currentPosition = 0;

        for (int i = 0; i < nodes.size(); i++) {

            if (nodes[i].level != level) {
                continue;
            }

            int textPosition = nodes[i].position.x() / 10;

            while (currentPosition < textPosition) {
                result += " ";
                currentPosition++;
            }

            QString key = keyToString(nodes[i].key);

            result += key;
            currentPosition += key.length();
        }

        result += "\n";
    }

    return result;
}

void BinaryTree::horizontalPrintRecursive(Node *node, int space, QString& result) {

    if (node == nullptr) {
        return;
    }

    space += 5;

    horizontalPrintRecursive(node->right, space, result);

    result += "\n";

    for (int i = 5; i < space; i++) {
        result += " ";
    }

    result += keyToString(node->key);

    horizontalPrintRecursive(node->left, space, result);
}

QString BinaryTree::horizontalPrint() {
    QString result;

    result += "Горизонтальная печать\n";

    horizontalPrintRecursive(root, 0, result);

    return result;
}

void BinaryTree::saveInorder(Node *node, vector<double>& values) {

    if (node == nullptr) {
        return;
    }

    saveInorder(node->left, values);

    values.push_back(node->key);

    saveInorder(node->right, values);
}

BinaryTree::Node* BinaryTree::buildBalanced(vector<double>& values, int left, int right) {

    if (left > right) {
        return nullptr;
    }

    int middle = (left + right) / 2;

    Node *node = new Node(values[middle]);

    node->left = buildBalanced(values, left, middle - 1);
    node->right = buildBalanced(values, middle + 1, right);

    return node;
}

void BinaryTree::balance() {
    vector<double> values;

    saveInorder(root, values);

    clear(root);

    root = nullptr;

    if (values.empty()) {
        return;
    }

    root = buildBalanced(values, 0, values.size() - 1);
}

BinaryTree::Node* BinaryTree::clone(Node *node) {

    if (node == nullptr) {
        return nullptr;
    }

    Node *newNode = new Node(node->key);

    newNode->left = clone(node->left);
    newNode->right = clone(node->right);

    return newNode;
}

void BinaryTree::saveOriginal() {

    clear(originalRoot);

    originalRoot = clone(root);
}

void BinaryTree::restoreOriginal() {

    clear(root);

    root = clone(originalRoot);
}

int BinaryTree::countLeavesRecursive(Node *node) {

    if (node == nullptr) {
        return 0;
    }

    // лист — узел без потомков
    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }

    return countLeavesRecursive(node->left)
           + countLeavesRecursive(node->right);
}

int BinaryTree::countLeaves() {
    return countLeavesRecursive(root);
}

int BinaryTree::countNodesRecursive(Node *node) {

    if (node == nullptr) {
        return 0;
    }

    return 1
           + countNodesRecursive(node->left)
           + countNodesRecursive(node->right);
}

int BinaryTree::getSize() {
    return countNodesRecursive(root);
}

int BinaryTree::heightRecursive(Node *node) {

    if (node == nullptr) {
        return 0;
    }

    int leftHeight = heightRecursive(node->left);
    int rightHeight = heightRecursive(node->right);

    return 1 + max(leftHeight, rightHeight);
}

int BinaryTree::getHeight() {
    return heightRecursive(root);
}

void BinaryTree::fillVisualNodes(Node *node,
                                 vector<VisualNode>& nodes,
                                 double parentKey,
                                 bool hasParent,
                                 int level,
                                 int& index,
                                 int horizontalStep) {

    if (node == nullptr) {
        return;
    }

    fillVisualNodes(node->left,
                    nodes,
                    node->key,
                    true,
                    level + 1,
                    index,
                    horizontalStep);

    int x = 40 + (index + 1) * horizontalStep;
    int y = 50 + level * 75;

    VisualNode visualNode;

    visualNode.key = node->key;
    visualNode.parentKey = parentKey;
    visualNode.hasParent = hasParent;
    visualNode.position = QPoint(x, y);
    visualNode.level = level;

    nodes.push_back(visualNode);

    index++;

    fillVisualNodes(node->right,
                    nodes,
                    node->key,
                    true,
                    level + 1,
                    index,
                    horizontalStep);
}

vector<VisualNode> BinaryTree::getVisualNodes() {
    vector<VisualNode> nodes;

    int count = getSize();

    if (count == 0) {
        return nodes;
    }

    int horizontalStep = 560 / (count + 1);

    int index = 0;

    fillVisualNodes(root,
                    nodes,
                    0,
                    false,
                    0,
                    index,
                    horizontalStep);

    return nodes;
}

void BinaryTree::clear(Node *node) {

    if (node == nullptr) {
        return;
    }

    clear(node->left);
    clear(node->right);

    delete node;
}
