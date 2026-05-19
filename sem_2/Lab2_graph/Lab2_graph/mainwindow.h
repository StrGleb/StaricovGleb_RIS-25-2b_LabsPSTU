#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>

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

protected:
    void paintEvent(QPaintEvent *event); // отрисовка графа

private slots:
    void on_bfsButton_clicked(); // запуск BFS
    void on_dfsButton_clicked(); // запуск DFS

    void on_dijkstraButton_clicked(); // запуск Дейкстры
    void on_floydButton_clicked(); // запуск Флойда

    void on_addEdgeButton_clicked(); // добавление ребра
    void on_removeEdgeButton_clicked(); // удаление ребра

    void on_changeWeightButton_clicked(); // изменение веса

    void on_addVertexButton_clicked(); // добавление вершины
    void on_removeVertexButton_clicked(); // удаление вершины

public:
    MainWindow(QWidget *parent = nullptr); // конструктор окна
    ~MainWindow(); // деструктор
};

#endif // MAINWINDOW_H