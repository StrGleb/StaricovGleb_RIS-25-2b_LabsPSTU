#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <QString>
#include <QPoint>

using namespace std;

class Graph {
private:
    int size; // количество вершин

    vector<QString> vertices; // названия вершин
    vector<QPoint> positions; // координаты вершин

    vector<vector<int>> adjMatrix; // матрица смежности

    void dfsRecursive(int vertex, vector<bool>& visited, QString& result); // рекурсивный DFS

public:
public:
    Graph(int size); // конструктор графа

    void addVertex(QString name, QPoint position); // добавление вершины
    void increaseMatrixSize(); // увеличение размера матрицы

    void addEdge(int from, int to, int weight); // добавление ребра
    void removeEdge(int from, int to); // удаление ребра

    void setWeight(int from, int to, int weight); // изменение веса ребра

    void removeVertex(int index); // удаление вершины

    void printMatrix(); // вывод матрицы смежности

    QString bfs(int start); // обход графа в ширину
    QString dfs(int start); // обход графа в глубину
    QString dijkstra(int start); // алгоритм Дейкстры
    QString floyd(); // алгоритм Флойда

    int getSize(); // получение количества вершин

    vector<QString> getVertices(); // получение вершин
    vector<QPoint> getPositions(); // получение координат
    vector<vector<int>> getMatrix(); // получение матрицы
    vector<vector<int>> getFloydMatrix(); // матрица Флойда
    vector<int> getDijkstraDistances(int start); // расстояния Дейкстры
};

#endif // GRAPH_H