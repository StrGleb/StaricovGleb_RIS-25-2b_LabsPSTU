#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    graph(0) {

    ui->setupUi(this);

    setWindowTitle("Задача коммивояжёра");
    resize(1088, 726);

    // весь интерфейс делаем светлым, без черной области за меню
    setStyleSheet(
        "QMainWindow { background-color: white; }"
        "QWidget { background-color: white; color: black; font-size: 10pt; }"
        "#centralwidget { background-color: transparent; }"
        "QMenuBar { background-color: white; color: black; }"
        "QStatusBar { background-color: white; color: black; }"
        "QTextEdit { background-color: white; color: black; border: 1px solid #bdbdbd; }"
        "QTableWidget { background-color: white; color: black; gridline-color: #d0d0d0; border: 1px solid #bdbdbd; }"
        "QHeaderView::section { background-color: #f2f2f2; color: black; border: 1px solid #c8c8c8; padding: 4px; }"
        "QPushButton { background-color: #f7f7f7; color: black; border: 1px solid #999999; padding: 5px; border-radius: 5px; }"
        "QPushButton:hover { background-color: #e8e8e8; }"
        "QPushButton:pressed { background-color: #d8d8d8; }"
        );

    ui->centralwidget->setAttribute(Qt::WA_TranslucentBackground);
    ui->centralwidget->setAutoFillBackground(false);

    ui->matrixTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->matrixTableWidget->setFocusPolicy(Qt::NoFocus);

    draggedVertex = -1;
    activeStep = -1;

    animationTimer = new QTimer(this);

    connect(
        animationTimer,
        &QTimer::timeout,
        this,
        &MainWindow::animateSolution
        );

    createDemoGraph();
    fillMatrixTable();

    ui->resultTextEdit->setText(
        "Лабораторная работа\n"
        "Решение задачи коммивояжера методом ветвей и границ\n\n"
        "Можно добавлять вершины и ребра, менять веса, двигать вершины мышью.\n"
        "После запуска решения найденный маршрут подсвечивается на графе."
        );
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::createDemoGraph() {
    graph.clear();
    clearSolution();

    // демонстрационный двунаправленный граф из 6 вершин
    graph.addVertex("1", QPoint(300, 80));
    graph.addVertex("2", QPoint(120, 180));
    graph.addVertex("3", QPoint(140, 380));
    graph.addVertex("4", QPoint(320, 500));
    graph.addVertex("5", QPoint(530, 380));
    graph.addVertex("6", QPoint(520, 170));

    graph.addEdge(0, 1, 12);
    graph.addEdge(0, 2, 18);
    graph.addEdge(0, 5, 20);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 22);
    graph.addEdge(1, 5, 15);
    graph.addEdge(2, 3, 14);
    graph.addEdge(2, 4, 24);
    graph.addEdge(3, 4, 11);
    graph.addEdge(3, 5, 26);
    graph.addEdge(4, 5, 13);
}

void MainWindow::clearSolution() {
    solutionPath.clear();
    activeStep = -1;

    if (animationTimer != nullptr) {
        animationTimer->stop();
    }
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    vector<QPoint> positions = graph.getPositions();
    vector<QString> vertices = graph.getVertices();
    vector<vector<int>> matrix = graph.getMatrix();

    // рабочая зона графа
    painter.setPen(QPen(QColor(230, 230, 230), 1));
    painter.setBrush(QColor(252, 252, 252));
    painter.drawRoundedRect(20, 20, 590, 610, 12, 12);

    // обычные ребра
    for (int i = 0; i < graph.getSize(); i++) {
        for (int j = i + 1; j < graph.getSize(); j++) {
            if (matrix[i][j] > 0) {
                painter.setPen(QPen(QColor(120, 120, 120), 2));
                painter.drawLine(positions[i], positions[j]);

                QPoint center(
                    (positions[i].x() + positions[j].x()) / 2,
                    (positions[i].y() + positions[j].y()) / 2
                    );

                QRect weightRect(center.x() - 16, center.y() - 12, 32, 24);

                painter.setBrush(Qt::white);
                painter.setPen(QPen(QColor(120, 120, 120), 1));
                painter.drawRoundedRect(weightRect, 5, 5);

                painter.setPen(Qt::black);
                painter.drawText(
                    weightRect,
                    Qt::AlignCenter,
                    QString::number(matrix[i][j])
                    );
            }
        }
    }

    // подсветка найденного маршрута
    for (int i = 0; i + 1 < solutionPath.size(); i++) {
        int from = solutionPath[i];
        int to = solutionPath[i + 1];

        QColor color = QColor(30, 150, 70);
        int width = 5;

        if (i == activeStep) {
            color = QColor(220, 60, 40);
            width = 7;
        }

        painter.setPen(QPen(color, width, Qt::SolidLine, Qt::RoundCap));
        painter.drawLine(positions[from], positions[to]);

        QPoint center(
            (positions[from].x() + positions[to].x()) / 2,
            (positions[from].y() + positions[to].y()) / 2
            );

        QRect stepRect(center.x() - 12, center.y() - 28, 24, 22);
        painter.setBrush(color);
        painter.setPen(color);
        painter.drawEllipse(stepRect);

        painter.setPen(Qt::white);
        painter.drawText(stepRect, Qt::AlignCenter, QString::number(i + 1));
    }

    // вершины
    for (int i = 0; i < graph.getSize(); i++) {
        QColor fillColor = QColor(30, 30, 30);

        if (!solutionPath.empty()) {
            fillColor = QColor(40, 120, 210);
        }

        painter.setBrush(fillColor);
        painter.setPen(QPen(Qt::black, 2));
        painter.drawEllipse(positions[i].x() - 22, positions[i].y() - 22, 44, 44);

        QRect rect(positions[i].x() - 22, positions[i].y() - 22, 44, 44);

        painter.setPen(Qt::white);
        painter.drawText(rect, Qt::AlignCenter, vertices[i]);
    }
}

int MainWindow::findVertexAt(QPoint point) {
    vector<QPoint> positions = graph.getPositions();

    for (int i = 0; i < positions.size(); i++) {
        int dx = point.x() - positions[i].x();
        int dy = point.y() - positions[i].y();

        if (dx * dx + dy * dy <= 22 * 22) {
            return i;
        }
    }

    return -1;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    draggedVertex = findVertexAt(event->pos());
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (draggedVertex != -1) {
        QPoint point = event->pos();

        // ограничиваем перемещение зоной графа
        point.setX(qBound(45, point.x(), 585));
        point.setY(qBound(45, point.y(), 610));

        graph.setPosition(draggedVertex, point);
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    draggedVertex = -1;
}

void MainWindow::fillMatrixTable() {
    vector<vector<int>> matrix = graph.getMatrix();
    vector<QString> vertices = graph.getVertices();

    ui->matrixTableWidget->clear();
    ui->matrixTableWidget->setRowCount(graph.getSize());
    ui->matrixTableWidget->setColumnCount(graph.getSize());
    ui->matrixTableWidget->setHorizontalHeaderLabels(QStringList(vertices.begin(), vertices.end()));
    ui->matrixTableWidget->setVerticalHeaderLabels(QStringList(vertices.begin(), vertices.end()));

    for (int i = 0; i < graph.getSize(); i++) {
        for (int j = 0; j < graph.getSize(); j++) {
            QString value = matrix[i][j] == 0 ? "-" : QString::number(matrix[i][j]);

            QTableWidgetItem *item = new QTableWidgetItem(value);
            item->setTextAlignment(Qt::AlignCenter);
            ui->matrixTableWidget->setItem(i, j, item);
        }
    }

    ui->matrixTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->matrixTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_solveTspButton_clicked() {
    clearSolution();

    TspResult result = graph.solveTsp(0);

    ui->resultTextEdit->setText(result.log);
    solutionPath = result.path;

    fillMatrixTable();

    if (!solutionPath.empty()) {
        activeStep = 0;
        animationTimer->start(700);
    }

    update();
}

void MainWindow::on_addVertexButton_clicked() {
    clearSolution();

    QString name = QString::number(graph.getSize() + 1);
    QPoint position(90 + graph.getSize() * 45, 90 + graph.getSize() * 35);

    graph.addVertex(name, position);

    ui->resultTextEdit->setText("Добавлена вершина: " + name);

    fillMatrixTable();
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

    clearSolution();
    graph.removeVertex(vertex - 1);

    ui->resultTextEdit->setText("Вершина удалена.");

    fillMatrixTable();
    update();
}

void MainWindow::on_addEdgeButton_clicked() {
    bool ok1;
    bool ok2;
    bool ok3;

    int from = QInputDialog::getInt(this, "Добавление ребра", "Первая вершина:", 1, 1, graph.getSize(), 1, &ok1);

    if (!ok1) {
        return;
    }

    int to = QInputDialog::getInt(this, "Добавление ребра", "Вторая вершина:", 1, 1, graph.getSize(), 1, &ok2);

    if (!ok2) {
        return;
    }

    int weight = QInputDialog::getInt(this, "Добавление ребра", "Вес ребра:", 10, 1, 9999, 1, &ok3);

    if (!ok3) {
        return;
    }

    clearSolution();
    graph.addEdge(from - 1, to - 1, weight);

    ui->resultTextEdit->setText("Ребро добавлено.");

    fillMatrixTable();
    update();
}

void MainWindow::on_removeEdgeButton_clicked() {
    bool ok1;
    bool ok2;

    int from = QInputDialog::getInt(this, "Удаление ребра", "Первая вершина:", 1, 1, graph.getSize(), 1, &ok1);

    if (!ok1) {
        return;
    }

    int to = QInputDialog::getInt(this, "Удаление ребра", "Вторая вершина:", 1, 1, graph.getSize(), 1, &ok2);

    if (!ok2) {
        return;
    }

    clearSolution();
    graph.removeEdge(from - 1, to - 1);

    ui->resultTextEdit->setText("Ребро удалено.");

    fillMatrixTable();
    update();
}

void MainWindow::on_changeWeightButton_clicked() {
    bool ok1;
    bool ok2;
    bool ok3;

    int from = QInputDialog::getInt(this, "Изменение веса", "Первая вершина:", 1, 1, graph.getSize(), 1, &ok1);

    if (!ok1) {
        return;
    }

    int to = QInputDialog::getInt(this, "Изменение веса", "Вторая вершина:", 1, 1, graph.getSize(), 1, &ok2);

    if (!ok2) {
        return;
    }

    int weight = QInputDialog::getInt(this, "Изменение веса", "Новый вес:", 10, 1, 9999, 1, &ok3);

    if (!ok3) {
        return;
    }

    clearSolution();
    graph.setWeight(from - 1, to - 1, weight);

    ui->resultTextEdit->setText("Вес ребра изменен.");

    fillMatrixTable();
    update();
}

void MainWindow::on_resetButton_clicked() {
    createDemoGraph();
    fillMatrixTable();

    ui->resultTextEdit->setText("Граф возвращен к исходному примеру.");

    update();
}

void MainWindow::animateSolution() {
    if (solutionPath.size() < 2) {
        animationTimer->stop();
        return;
    }

    activeStep++;

    if (activeStep >= solutionPath.size() - 1) {
        activeStep = 0;
    }

    update();
}
