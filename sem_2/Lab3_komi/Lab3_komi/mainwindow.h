#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>
#include <QTimer>

#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Graph graph; // объект графа

    vector<int> solutionPath; // маршрут коммивояжера для подсветки
    int activeStep; // текущий подсвечиваемый ход
    int draggedVertex; // перетаскиваемая вершина
    QTimer *animationTimer; // таймер анимации маршрута

    int findVertexAt(QPoint point); // поиск вершины по координатам
    void fillMatrixTable(); // вывод матрицы смежности
    void createDemoGraph(); // исходный граф
    void clearSolution(); // очистка подсветки

protected:
    void paintEvent(QPaintEvent *event); // отрисовка графа
    void mousePressEvent(QMouseEvent *event); // нажатие мыши
    void mouseMoveEvent(QMouseEvent *event); // перемещение мыши
    void mouseReleaseEvent(QMouseEvent *event); // отпускание мыши

private slots:
    void on_solveTspButton_clicked(); // запуск решения
    void on_addVertexButton_clicked(); // добавление вершины
    void on_removeVertexButton_clicked(); // удаление вершины
    void on_addEdgeButton_clicked(); // добавление ребра
    void on_removeEdgeButton_clicked(); // удаление ребра
    void on_changeWeightButton_clicked(); // изменение веса
    void on_resetButton_clicked(); // возврат примера
    void animateSolution(); // шаг анимации

public:
    MainWindow(QWidget *parent = nullptr); // конструктор окна
    ~MainWindow(); // деструктор
};

#endif // MAINWINDOW_H
