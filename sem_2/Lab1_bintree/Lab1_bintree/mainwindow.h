#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>
#include <QLineEdit>
#include <QTableWidgetItem>

#include "tree.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    BinaryTree tree; // объект дерева

    void fillTreeTable(); // заполнение таблицы узлов
    QString keyToString(double key); // ключ в строку

protected:
    void paintEvent(QPaintEvent *event); // отрисовка дерева

private slots:
    void on_insertButton_clicked(); // вставка узла
    void on_removeButton_clicked(); // удаление узла
    void on_searchButton_clicked(); // поиск узла

    void on_preorderButton_clicked(); // прямой обход
    void on_inorderButton_clicked(); // симметричный обход
    void on_postorderButton_clicked(); // обратный обход

    void on_balanceButton_clicked(); // балансировка дерева

    void on_verticalPrintButton_clicked(); // вертикальная печать
    void on_horizontalPrintButton_clicked(); // горизонтальная печать

    void on_leavesButton_clicked(); // количество листьев
    void on_resetButton_clicked(); // возврат к исходному дереву

public:
    MainWindow(QWidget *parent = nullptr); // конструктор окна
    ~MainWindow(); // деструктор
};

#endif // MAINWINDOW_H
