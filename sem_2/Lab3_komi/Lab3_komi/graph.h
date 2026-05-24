#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include <QPoint>
#include <vector>

using namespace std;

struct TspResult {
    int cost; // итоговая длина маршрута
    vector<int> path; // найденный маршрут
    QString log; // текстовый вывод решения
};

class Graph {
private:
    int size; // количество вершин
    vector<QString> vertices; // названия вершин
    vector<QPoint> positions; // координаты вершин
    vector<vector<int>> adjMatrix; // матрица смежности

    int bestCost; // лучший найденный ответ
    vector<int> bestPath; // лучший найденный маршрут

    int getMinOutgoing(int vertex); // минимальное ребро из вершины
    int calculateBound(int currentCost, vector<bool> visited); // оценка снизу

    void branchAndBound(
        int currentVertex,
        int startVertex,
        int currentCost,
        vector<int> currentPath,
        vector<bool> visited,
        QString& log
        ); // рекурсивный метод ветвей и границ

public:
    Graph(int size = 0); // конструктор графа

    void addVertex(QString name, QPoint position); // добавление вершины
    void addEdge(int from, int to, int weight); // добавление ребра
    void removeEdge(int from, int to); // удаление ребра
    void setWeight(int from, int to, int weight); // изменение веса
    void removeVertex(int index); // удаление вершины
    void clear(); // очистка графа

    TspResult solveTsp(int startVertex); // решение задачи коммивояжера

    int getSize(); // получение количества вершин
    vector<QString> getVertices(); // получение названий вершин
    vector<QPoint> getPositions(); // получение координат вершин
    vector<vector<int>> getMatrix(); // получение матрицы смежности
    void setPosition(int index, QPoint position); // изменение позиции вершины
};

#endif // GRAPH_H
