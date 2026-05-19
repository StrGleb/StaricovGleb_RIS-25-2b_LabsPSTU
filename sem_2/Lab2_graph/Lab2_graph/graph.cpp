#include "graph.h"

Graph::Graph(int size) {
    this->size = size; // сохраняем размер графа

    adjMatrix.resize(size, vector<int>(size, 0)); // создаем матрицу size x size и заполняем нулями
}

void Graph::addVertex(QString name, QPoint position) {
    vertices.push_back(name); // добавляем название вершины
    positions.push_back(position); // добавляем координаты
}

void Graph::increaseMatrixSize() {

    size++; // увеличиваем количество вершин

    // добавляем новый столбец
    for (int i = 0; i < adjMatrix.size(); i++) {
        adjMatrix[i].push_back(0);
    }

    // добавляем новую строку
    adjMatrix.push_back(vector<int>(size, 0));
}

void Graph::addEdge(int from, int to, int weight) {
    adjMatrix[from][to] = weight; // ребро from -> to
    adjMatrix[to][from] = weight; // ребро to -> from
}

void Graph::removeEdge(int from, int to) {
    adjMatrix[from][to] = 0; // удаляем ребро
    adjMatrix[to][from] = 0;
}

void Graph::setWeight(int from, int to, int weight) {
    adjMatrix[from][to] = weight; // меняем вес
    adjMatrix[to][from] = weight;
}

void Graph::removeVertex(int index) {

    // проверка индекса вершины
    if (index < 0 || index >= size) {
        cout << "Неверный индекс вершины" << endl;
        return;
    }

    vertices.erase(vertices.begin() + index); // удаляем вершину
    positions.erase(positions.begin() + index); // удаляем координаты

    adjMatrix.erase(adjMatrix.begin() + index); // удаляем строку

    // удаляем столбец
    for (int i = 0; i < adjMatrix.size(); i++) {
        adjMatrix[i].erase(adjMatrix[i].begin() + index);
    }

    size--; // уменьшаем размер графа
}

void Graph::printMatrix() {
    cout << "Матрица смежности:" << endl;

    // вывод матрицы
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {
            cout << adjMatrix[i][j] << "\t";
        }

        cout << endl;
    }
}

QString Graph::bfs(int start) {

    vector<bool> visited(size, false); // посещенные вершины
    queue<int> q; // очередь BFS

    QString result;
    QString order = "Результат: ";

    result += "BFS\n\n";

    result += "Стартовая вершина: ";
    result += QString::number(start + 1);
    result += "\n\n";

    visited[start] = true;
    q.push(start);

    // пока очередь не пустая
    while (!q.empty()) {

        int current = q.front();
        q.pop();

        result += "Посетили вершину: ";
        result += QString::number(current + 1);
        result += "\n";

        order += QString::number(current + 1) + " ";

        // проверяем соседей
        for (int i = 0; i < size; i++) {

            // если есть ребро и вершина не посещена
            if (adjMatrix[current][i] != 0 && !visited[i]) {

                visited[i] = true;

                q.push(i);

                result += "Добавили в очередь: ";
                result += QString::number(i + 1);
                result += "\n";
            }
        }

        result += "\n";
    }

    result += order;

    return result;
}

void Graph::dfsRecursive(int vertex, vector<bool>& visited, QString& result) {
    visited[vertex] = true; // отмечаем вершину

    result += "Посетили вершину: ";
    result += QString::number(vertex + 1);
    result += "\n";

    // проверяем соседей
    for (int i = 0; i < size; i++) {

        // если есть ребро и вершина не посещена
        if (adjMatrix[vertex][i] != 0 && !visited[i]) {

            result += "Переходим к вершине: ";
            result += QString::number(i + 1);
            result += "\n";

            dfsRecursive(i, visited, result);
        }
    }
}

QString Graph::dfs(int start) {

    vector<bool> visited(size, false);

    QString result;

    result += "DFS\n\n";

    result += "Стартовая вершина: ";
    result += QString::number(start + 1);
    result += "\n\n";

    dfsRecursive(start, visited, result);

    return result;
}

QString Graph::dijkstra(int start) {

    const int INF = 999999;

    vector<int> distance(size, INF); // расстояния
    vector<bool> visited(size, false); // посещенные вершины

    QString result;

    result += "Алгоритм Дейкстры\n\n";

    result += "Стартовая вершина: ";
    result += QString::number(start + 1);
    result += "\n\n";

    distance[start] = 0;

    // основной цикл
    for (int i = 0; i < size - 1; i++) {

        int minDistance = INF;
        int currentVertex = -1;

        // ищем минимальную вершину
        for (int j = 0; j < size; j++) {

            if (!visited[j] && distance[j] < minDistance) {

                minDistance = distance[j];
                currentVertex = j;
            }
        }

        // если вершина не найдена
        if (currentVertex == -1) {
            break;
        }

        visited[currentVertex] = true;

        result += "Текущая вершина: ";
        result += QString::number(currentVertex + 1);
        result += "\n";

        // обновляем расстояния
        for (int j = 0; j < size; j++) {

            // если есть ребро
            if (adjMatrix[currentVertex][j] != 0
                && !visited[j]) {

                int newDistance =
                    distance[currentVertex]
                    + adjMatrix[currentVertex][j];

                // если путь стал короче
                if (newDistance < distance[j]) {

                    distance[j] = newDistance;

                    result += "Обновили путь до вершины ";
                    result += QString::number(j + 1);
                    result += " = ";
                    result += QString::number(distance[j]);
                    result += "\n";
                }
            }
        }

        result += "\n";
    }

    result += "Итоговые расстояния:\n";

    // итоговые расстояния
    for (int i = 0; i < size; i++) {

        result += "До вершины ";
        result += QString::number(i + 1);
        result += " = ";
        result += QString::number(distance[i]);
        result += "\n";
    }

    return result;
}

QString Graph::floyd() {

    const int INF = 999999;

    vector<vector<int>> distance = adjMatrix;

    QString result;

    result += "Алгоритм Флойда\n\n";

    // заменяем нули на INF
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if (i != j && distance[i][j] == 0) {
                distance[i][j] = INF;
            }
        }
    }

    // алгоритм Флойда
    for (int k = 0; k < size; k++) {

        result += "Промежуточная вершина: ";
        result += QString::number(k + 1);
        result += "\n";

        for (int i = 0; i < size; i++) {

            for (int j = 0; j < size; j++) {

                // если путь через k короче
                if (distance[i][k] + distance[k][j]
                    < distance[i][j]) {

                    distance[i][j] =
                        distance[i][k]
                        + distance[k][j];

                    result += "Обновили путь ";
                    result += QString::number(i + 1);
                    result += " -> ";
                    result += QString::number(j + 1);
                    result += " = ";
                    result += QString::number(distance[i][j]);
                    result += "\n";
                }
            }
        }

        result += "\n";
    }

    result += "Итоговая матрица выведена в таблицу.\n";

    return result;
}

int Graph::getSize() {
    return size; // возвращаем количество вершин
}

vector<QString> Graph::getVertices() {
    return vertices; // возвращаем вершины
}

vector<QPoint> Graph::getPositions() {
    return positions; // возвращаем координаты
}

vector<vector<int>> Graph::getMatrix() {
    return adjMatrix; // возвращаем матрицу смежности
}

vector<vector<int>> Graph::getFloydMatrix() {

    const int INF = 999999;

    vector<vector<int>> distance = adjMatrix;

    // заменяем нули
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if (i != j && distance[i][j] == 0) {
                distance[i][j] = INF;
            }
        }
    }

    // алгоритм Флойда
    for (int k = 0; k < size; k++) {

        for (int i = 0; i < size; i++) {

            for (int j = 0; j < size; j++) {

                if (distance[i][k] + distance[k][j]
                    < distance[i][j]) {

                    distance[i][j] =
                        distance[i][k]
                        + distance[k][j];
                }
            }
        }
    }

    return distance;
}

vector<int> Graph::getDijkstraDistances(int start) {

    const int INF = 999999;

    vector<int> distance(size, INF);
    vector<bool> visited(size, false);

    distance[start] = 0;

    // основной цикл
    for (int i = 0; i < size - 1; i++) {

        int minDistance = INF;
        int currentVertex = -1;

        // поиск минимальной вершины
        for (int j = 0; j < size; j++) {

            if (!visited[j] && distance[j] < minDistance) {

                minDistance = distance[j];
                currentVertex = j;
            }
        }

        if (currentVertex == -1) {
            break;
        }

        visited[currentVertex] = true;

        // обновление расстояний
        for (int j = 0; j < size; j++) {

            if (adjMatrix[currentVertex][j] != 0
                && !visited[j]) {

                int newDistance =
                    distance[currentVertex]
                    + adjMatrix[currentVertex][j];

                if (newDistance < distance[j]) {
                    distance[j] = newDistance;
                }
            }
        }
    }

    return distance;
}
