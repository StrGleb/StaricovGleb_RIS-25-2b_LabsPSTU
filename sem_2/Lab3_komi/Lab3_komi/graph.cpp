#include "graph.h"

Graph::Graph(int size) {
    this->size = 0;
    bestCost = 999999;
}

void Graph::addVertex(QString name, QPoint position) {
    vertices.push_back(name); // добавляем название вершины
    positions.push_back(position); // добавляем координаты вершины

    size = vertices.size();

    // добавляем новый столбец в существующие строки
    for (int i = 0; i < adjMatrix.size(); i++) {
        adjMatrix[i].push_back(0);
    }

    // добавляем новую строку
    adjMatrix.push_back(vector<int>(size, 0));
}

void Graph::addEdge(int from, int to, int weight) {
    if (from < 0 || to < 0 || from >= size || to >= size || from == to) {
        return;
    }

    adjMatrix[from][to] = weight; // граф двунаправленный
    adjMatrix[to][from] = weight;
}

void Graph::removeEdge(int from, int to) {
    if (from < 0 || to < 0 || from >= size || to >= size) {
        return;
    }

    adjMatrix[from][to] = 0;
    adjMatrix[to][from] = 0;
}

void Graph::setWeight(int from, int to, int weight) {
    addEdge(from, to, weight);
}

void Graph::removeVertex(int index) {
    if (index < 0 || index >= size) {
        return;
    }

    vertices.erase(vertices.begin() + index);
    positions.erase(positions.begin() + index);
    adjMatrix.erase(adjMatrix.begin() + index);

    for (int i = 0; i < adjMatrix.size(); i++) {
        adjMatrix[i].erase(adjMatrix[i].begin() + index);
    }

    size = vertices.size();
}

void Graph::clear() {
    size = 0;
    vertices.clear();
    positions.clear();
    adjMatrix.clear();
}

int Graph::getMinOutgoing(int vertex) {
    int minValue = 999999;

    for (int i = 0; i < size; i++) {
        if (adjMatrix[vertex][i] > 0 && adjMatrix[vertex][i] < minValue) {
            minValue = adjMatrix[vertex][i];
        }
    }

    return minValue;
}

int Graph::calculateBound(int currentCost, vector<bool> visited) {
    int bound = currentCost;

    // к текущей стоимости добавляем минимальные возможные выходы
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            int minValue = getMinOutgoing(i);

            if (minValue == 999999) {
                return 999999;
            }

            bound += minValue;
        }
    }

    return bound;
}

void Graph::branchAndBound(
    int currentVertex,
    int startVertex,
    int currentCost,
    vector<int> currentPath,
    vector<bool> visited,
    QString& log
    ) {

    // если все вершины уже включены в маршрут
    if (currentPath.size() == size) {
        if (adjMatrix[currentVertex][startVertex] == 0) {
            log += "Маршрут не замыкается в начальную вершину. Ветвь отброшена.\n";
            return;
        }

        int fullCost = currentCost + adjMatrix[currentVertex][startVertex];

        log += "Проверка полного маршрута: ";

        for (int i = 0; i < currentPath.size(); i++) {
            log += vertices[currentPath[i]] + " -> ";
        }

        log += vertices[startVertex];
        log += " = " + QString::number(fullCost) + "\n";

        if (fullCost < bestCost) {
            bestCost = fullCost;
            bestPath = currentPath;
            bestPath.push_back(startVertex);

            log += "Найден новый лучший маршрут.\n";
        }

        log += "\n";
        return;
    }

    // перебираем возможные переходы
    for (int next = 0; next < size; next++) {
        if (!visited[next] && adjMatrix[currentVertex][next] > 0) {
            int newCost = currentCost + adjMatrix[currentVertex][next];

            vector<bool> newVisited = visited;
            vector<int> newPath = currentPath;

            newVisited[next] = true;
            newPath.push_back(next);

            int bound = calculateBound(newCost, newVisited);

            log += "Ветвь: " + vertices[currentVertex] + " -> " + vertices[next];
            log += ", стоимость = " + QString::number(newCost);
            log += ", оценка = " + QString::number(bound) + "\n";

            if (bound >= bestCost) {
                log += "Ветвь отброшена, так как оценка не лучше текущего ответа.\n\n";
                continue;
            }

            branchAndBound(
                next,
                startVertex,
                newCost,
                newPath,
                newVisited,
                log
                );
        }
    }
}

TspResult Graph::solveTsp(int startVertex) {
    TspResult result;
    result.cost = -1;

    if (size < 3) {
        result.log = "Для задачи коммивояжера нужно минимум 3 вершины.";
        return result;
    }

    bestCost = 999999;
    bestPath.clear();

    vector<bool> visited(size, false);
    vector<int> path;

    visited[startVertex] = true;
    path.push_back(startVertex);

    QString log;
    log += "Задача коммивояжера\n";
    log += "Метод ветвей и границ\n\n";
    log += "Стартовая вершина: " + vertices[startVertex] + "\n\n";

    branchAndBound(
        startVertex,
        startVertex,
        0,
        path,
        visited,
        log
        );

    if (bestPath.empty()) {
        result.log = log + "Гамильтонов цикл не найден.";
        return result;
    }

    result.cost = bestCost;
    result.path = bestPath;

    log += "Лучший маршрут: ";

    for (int i = 0; i < bestPath.size(); i++) {
        log += vertices[bestPath[i]];

        if (i + 1 < bestPath.size()) {
            log += " -> ";
        }
    }

    log += "\nИтоговая длина маршрута: " + QString::number(bestCost);

    result.log = log;
    return result;
}

int Graph::getSize() {
    return size;
}

vector<QString> Graph::getVertices() {
    return vertices;
}

vector<QPoint> Graph::getPositions() {
    return positions;
}

vector<vector<int>> Graph::getMatrix() {
    return adjMatrix;
}

void Graph::setPosition(int index, QPoint position) {
    if (index < 0 || index >= size) {
        return;
    }

    positions[index] = position;
}
