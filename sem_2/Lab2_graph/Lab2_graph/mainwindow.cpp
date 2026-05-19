#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    graph(6) {

    ui->setupUi(this);

    // белый фон окна
    this->setAutoFillBackground(true);

    QPalette palette = this->palette();

    palette.setColor(QPalette::Window, Qt::white);

    this->setPalette(palette);

    // размер окна
    resize(1100, 650);

    // стиль поля вывода
    ui->resultTextEdit->setStyleSheet(
        "QTextEdit {"
        "background-color: black;"
        "color: white;"
        "border: 1px solid gray;"
        "font-size: 12pt;"
        "}"
        );

    // стиль таблицы
    ui->algorithmTableWidget->setStyleSheet(

        "QTableWidget {"
        "background-color: black;"
        "color: white;"
        "gridline-color: gray;"
        "border: 1px solid gray;"
        "selection-background-color: rgb(60, 60, 60);"
        "selection-color: white;"
        "}"

        "QTableWidget::item {"
        "padding: 5px;"
        "}"

        "QHeaderView::section {"
        "background-color: rgb(30, 30, 30);"
        "color: white;"
        "border: 1px solid gray;"
        "padding: 4px;"
        "}"
        );

    // отключаем выделение строк
    ui->algorithmTableWidget->setSelectionMode(
        QAbstractItemView::NoSelection
        );

    // скрываем рамку фокуса
    ui->algorithmTableWidget->setFocusPolicy(Qt::NoFocus);

    // стиль кнопок
    QString buttonStyle =

        "QPushButton {"
        "background-color: black;"
        "color: white;"
        "border: 1px solid gray;"
        "padding: 5px;"
        "border-radius: 5px;"
        "}"

        "QPushButton:hover {"
        "background-color: rgb(40, 40, 40);"
        "}"

        "QPushButton:pressed {"
        "background-color: rgb(70, 70, 70);"
        "}";

    ui->bfsButton->setStyleSheet(buttonStyle);
    ui->dfsButton->setStyleSheet(buttonStyle);
    ui->dijkstraButton->setStyleSheet(buttonStyle);
    ui->floydButton->setStyleSheet(buttonStyle);

    ui->addVertexButton->setStyleSheet(buttonStyle);
    ui->removeVertexButton->setStyleSheet(buttonStyle);

    ui->addEdgeButton->setStyleSheet(buttonStyle);
    ui->removeEdgeButton->setStyleSheet(buttonStyle);

    ui->changeWeightButton->setStyleSheet(buttonStyle);

    // добавление вершин
    graph.addVertex("1", QPoint(300, 50));
    graph.addVertex("2", QPoint(120, 150));
    graph.addVertex("3", QPoint(120, 320));
    graph.addVertex("4", QPoint(300, 420));
    graph.addVertex("5", QPoint(500, 320));
    graph.addVertex("6", QPoint(500, 150));

    // добавление ребер
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 5, 57);

    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 5, 13);

    graph.addEdge(2, 3, 5);

    graph.addEdge(3, 4, 34);
    graph.addEdge(3, 5, 21);

    graph.addEdge(4, 5, 45);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);

    // сглаживание
    painter.setRenderHint(QPainter::Antialiasing);

    vector<QPoint> positions = graph.getPositions();
    vector<QString> vertices = graph.getVertices();
    vector<vector<int>> matrix = graph.getMatrix();

    // рисование ребер
    for (int i = 0; i < graph.getSize(); i++) {

        for (int j = i + 1; j < graph.getSize(); j++) {

            // если есть ребро
            if (matrix[i][j] != 0) {

                QPoint p1 = positions[i];
                QPoint p2 = positions[j];

                // черные линии
                painter.setPen(Qt::black);

                // линия ребра
                painter.drawLine(p1, p2);

                // координаты веса
                int x = (p1.x() + p2.x()) / 2 + 10;
                int y = (p1.y() + p2.y()) / 2 - 10;

                QString weight =
                    QString::number(matrix[i][j]);

                QRect textRect(
                    x - 15,
                    y - 10,
                    30,
                    20
                    );

                // черный фон веса
                painter.fillRect(textRect, Qt::black);

                // белый текст веса
                painter.setPen(Qt::white);

                painter.drawText(
                    textRect,
                    Qt::AlignCenter,
                    weight
                    );
            }
        }
    }

    // рисование вершин
    for (int i = 0; i < graph.getSize(); i++) {

        QPoint point = positions[i];

        // черная заливка
        painter.setBrush(Qt::black);

        // черный контур
        painter.setPen(Qt::black);

        // круг вершины
        painter.drawEllipse(
            point.x() - 20,
            point.y() - 20,
            40,
            40
            );

        QRect rect(
            point.x() - 20,
            point.y() - 20,
            40,
            40
            );

        // белый текст
        painter.setPen(Qt::white);

        // номер вершины
        painter.drawText(
            rect,
            Qt::AlignCenter,
            vertices[i]
            );
    }
}

void MainWindow::on_bfsButton_clicked() {

    // очищаем таблицу
    ui->algorithmTableWidget->clear();

    ui->algorithmTableWidget->setRowCount(0);
    ui->algorithmTableWidget->setColumnCount(0);

    QString result = graph.bfs(2);

    ui->resultTextEdit->setText(result);
}

void MainWindow::on_dfsButton_clicked() {

    // очищаем таблицу
    ui->algorithmTableWidget->clear();

    ui->algorithmTableWidget->setRowCount(0);
    ui->algorithmTableWidget->setColumnCount(0);

    QString result = graph.dfs(2);

    ui->resultTextEdit->setText(result);
}

void MainWindow::on_dijkstraButton_clicked() {

    QString result = graph.dijkstra(2);

    ui->resultTextEdit->setText(result);

    vector<int> distance =
        graph.getDijkstraDistances(2);

    int size = graph.getSize();

    // очищаем таблицу
    ui->algorithmTableWidget->clear();

    // размер таблицы
    ui->algorithmTableWidget->setRowCount(size);
    ui->algorithmTableWidget->setColumnCount(2);

    // заголовки
    QStringList headers;

    headers << "Вершина"
            << "Расстояние";

    ui->algorithmTableWidget
        ->setHorizontalHeaderLabels(headers);

    // скрываем вертикальные номера
    ui->algorithmTableWidget
        ->verticalHeader()
        ->setVisible(false);

    // заполнение таблицы
    for (int i = 0; i < size; i++) {

        QString distanceValue;

        if (distance[i] == 999999) {
            distanceValue = "INF";
        }
        else {
            distanceValue =
                QString::number(distance[i]);
        }

        QTableWidgetItem *vertexItem =
            new QTableWidgetItem(
                QString::number(i + 1)
                );

        QTableWidgetItem *distanceItem =
            new QTableWidgetItem(distanceValue);

        // выравнивание текста
        vertexItem->setTextAlignment(Qt::AlignCenter);
        distanceItem->setTextAlignment(Qt::AlignCenter);

        ui->algorithmTableWidget->setItem(
            i,
            0,
            vertexItem
            );

        ui->algorithmTableWidget->setItem(
            i,
            1,
            distanceItem
            );
    }

    // растягиваем таблицу
    ui->algorithmTableWidget
        ->horizontalHeader()
        ->setSectionResizeMode(
            QHeaderView::Stretch
            );
}

void MainWindow::on_floydButton_clicked() {

    QString result = graph.floyd();

    ui->resultTextEdit->setText(result);

    vector<vector<int>> matrix =
        graph.getFloydMatrix();

    int size = graph.getSize();

    // очищаем таблицу
    ui->algorithmTableWidget->clear();

    // размер таблицы
    ui->algorithmTableWidget->setRowCount(size);
    ui->algorithmTableWidget->setColumnCount(size);

    // заголовки
    QStringList headers;

    for (int i = 0; i < size; i++) {
        headers << QString::number(i + 1);
    }

    ui->algorithmTableWidget
        ->setHorizontalHeaderLabels(headers);

    ui->algorithmTableWidget
        ->setVerticalHeaderLabels(headers);

    // показываем вертикальные номера
    ui->algorithmTableWidget
        ->verticalHeader()
        ->setVisible(true);

    // заполнение таблицы
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            QString value;

            if (matrix[i][j] == 999999) {
                value = "INF";
            }
            else {
                value = QString::number(matrix[i][j]);
            }

            QTableWidgetItem *item =
                new QTableWidgetItem(value);

            // выравнивание текста
            item->setTextAlignment(Qt::AlignCenter);

            ui->algorithmTableWidget->setItem(
                i,
                j,
                item
                );
        }
    }

    // растягиваем таблицу
    ui->algorithmTableWidget
        ->horizontalHeader()
        ->setSectionResizeMode(
            QHeaderView::Stretch
            );

    ui->algorithmTableWidget
        ->verticalHeader()
        ->setSectionResizeMode(
            QHeaderView::Stretch
            );
}

void MainWindow::on_addEdgeButton_clicked() {

    bool ok;

    int from = QInputDialog::getInt(
        this,
        "Добавление ребра",
        "Первая вершина:",
        1,
        1,
        graph.getSize(),
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    int to = QInputDialog::getInt(
        this,
        "Добавление ребра",
        "Вторая вершина:",
        1,
        1,
        graph.getSize(),
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    int weight = QInputDialog::getInt(
        this,
        "Добавление ребра",
        "Вес:",
        1,
        1,
        999,
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    // добавляем ребро
    graph.addEdge(from - 1, to - 1, weight);

    update();
}

void MainWindow::on_removeEdgeButton_clicked() {

    bool ok;

    int from = QInputDialog::getInt(
        this,
        "Удаление ребра",
        "Первая вершина:",
        1,
        1,
        graph.getSize(),
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    int to = QInputDialog::getInt(
        this,
        "Удаление ребра",
        "Вторая вершина:",
        1,
        1,
        graph.getSize(),
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    // удаляем ребро
    graph.removeEdge(from - 1, to - 1);

    update();
}

void MainWindow::on_changeWeightButton_clicked() {

    bool ok;

    int from = QInputDialog::getInt(
        this,
        "Изменение веса",
        "Первая вершина:",
        1,
        1,
        graph.getSize(),
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    int to = QInputDialog::getInt(
        this,
        "Изменение веса",
        "Вторая вершина:",
        1,
        1,
        graph.getSize(),
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    int weight = QInputDialog::getInt(
        this,
        "Изменение веса",
        "Новый вес:",
        1,
        1,
        999,
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    // меняем вес
    graph.setWeight(from - 1, to - 1, weight);

    update();
}

void MainWindow::on_addVertexButton_clicked() {

    bool ok;

    QString name = QInputDialog::getText(
        this,
        "Добавление вершины",
        "Название вершины:",
        QLineEdit::Normal,
        "",
        &ok
        );

    if (!ok || name.isEmpty()) {
        return;
    }

    int x = QInputDialog::getInt(
        this,
        "Добавление вершины",
        "X координата:",
        100,
        50,
        650,
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    int y = QInputDialog::getInt(
        this,
        "Добавление вершины",
        "Y координата:",
        100,
        50,
        550,
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    // увеличиваем матрицу
    graph.increaseMatrixSize();

    // добавляем вершину
    graph.addVertex(name, QPoint(x, y));

    update();
}

void MainWindow::on_removeVertexButton_clicked() {

    bool ok;

    int vertex = QInputDialog::getInt(
        this,
        "Удаление вершины",
        "Номер вершины:",
        1,
        1,
        graph.getSize(),
        1,
        &ok
        );

    if (!ok) {
        return;
    }

    // удаляем вершину
    graph.removeVertex(vertex - 1);

    update();
}